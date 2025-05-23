"""

        for i, example in enumerate(inputs):
            input_formatted = input_format.format(example["input"])
            output_formatted = output_format.format(example["output"])
            print("Example {}:".format(i + 1))
            print(input_formatted)
            print(output_formatted)

        print("")


def main():
    parser = argparse.ArgumentParser(description="Run the IR to C dataset.")
    parser.add_argument("--config_path", help="path to config file with data, model, and Cuda parameters.")
    args = parser.parse_args()

    config = toml.load(args.config_path)

    if torch.cuda.is_available() and config["cuda"]:
        device = "cuda:0"
        torch.cuda.set_device(device)
    else:
        device = "cpu"

    model_config = config.get("model")
    data_config = config.get("data")

    model = CodeT5(model_config).to(device)
    model.load_state_dict(torch.load(model_config["model_path"]))
    model.eval()

    dataset = CodeT5Dataset(data_config["data_path"])
    dataset.load()
    dataset.preprocess_data(data_config["max_len"])

    inputs, outputs = dataset.get_dataset()

    inputs_t = torch.tensor(inputs)
    outputs_t = torch.tensor(outputs)

    dataloader = DataLoader(
        TensorDataset(inputs_t, outputs_t),
        batch_size=data_config["batch_size"],
        shuffle=True,
        num_workers=0,
        pin_memory=True,
    )

    outputs_pred = []
    with torch.no_grad():
        for batch in tqdm(dataloader):
            batch = tuple(t.to(device) for t in batch)
            input_ids, output_ids = batch
            outputs_pred_batch = model.generate(
                input_ids=input_ids,
                num_beams=10,
                no_repeat_ngram_size=4,
                max_length=data_config["max_len"],
                early_stopping=True,
                length_penalty=1.0,
            )
            outputs_pred += [dataset.decode(ids) for ids in outputs_pred_batch]

    # print("Examples:")

    # for output_pred, output_true in zip(outputs_pred[:10], outputs_t[:10]):
    #     print("Pred:", output_pred)
    #     print("True:", dataset.decode(output_true), "\n")

    rouge = Rouge()
    scores_rouge = rouge.get_scores(outputs_pred, [[dataset.decode(ids)] for ids in outputs_t], avg=True)
    print(scores_rouge)

    bleu = BLEU()
    bleu_score = bleu.corpus_score(outputs_pred, [[dataset.decode(ids)] for ids in outputs_t])
    print(bleu_score)

    # evaluate_from_input_output(inputs, outputs_pred)


if __name__ == "__main__":
    main()