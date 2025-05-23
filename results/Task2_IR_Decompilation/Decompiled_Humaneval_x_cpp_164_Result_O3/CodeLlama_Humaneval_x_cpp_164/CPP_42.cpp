"""


def main():
  tokenizer = RobertaTokenizer.from_pretrained(MODEL_PATH)
  model = RobertaForMaskedLM.from_pretrained(MODEL_PATH)
  model = model.to(DEVICE)

  with open("data/test.txt", "w") as f:
    for i in range(10):
      f.write(EXAMPLE)

  train_dataset = LineByLineTextDataset(
    tokenizer=tokenizer,
    file_path="data/test.txt",
    block_size=512,
  )

  data_collator = DataCollatorForLanguageModeling(
    tokenizer=tokenizer, mlm=True, mlm_probability=0.15
  )

  training_args = TrainingArguments(
    output_dir="./results",
    per_device_train_batch_size=32,
    per_device_eval_batch_size=64,
    do_train=True,
    do_eval=True,
    evaluate_during_training=True,
  )

  trainer = Trainer(
    model=model,
    args=training_args,
    data_collator=data_collator,
    train_dataset=train_dataset,
    prediction_loss_only=True,
  )

  trainer.train()
  #trainer.save_model()


if __name__ == "__main__":
  main()