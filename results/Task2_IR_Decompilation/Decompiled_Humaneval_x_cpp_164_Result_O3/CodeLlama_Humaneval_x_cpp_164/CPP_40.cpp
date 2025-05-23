'''


def test_inference(model_name: str, model_path: str, input_text: str, device: str, num_beams: int = 10):
    model = InferenceModel(model_name=model_name,
                           model_path=model_path,
                           tokenizer_path=model_path,
                           device=device,
                           num_beams=num_beams)

    output = model.predict(input_text)
    print(output)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--model_name', type=str, help='Name of the model', default='codegpt')
    parser.add_argument('--model_path', type=str, help='Path of the model', default='./codegpt')
    parser.add_argument('--input_text', type=str, help='Input text for testing', default=TEST_INPUT_TEXT)
    parser.add_argument('--device', type=str, help='Device for running inference', default='cpu')
    parser.add_argument('--num_beams', type=int, help='Number of beams for beam search', default=10)
    args = parser.parse_args()

    test_inference(model_name=args.model_name,
                   model_path=args.model_path,
                   input_text=args.input_text,
                   device=args.device,
                   num_beams=args.num_beams)