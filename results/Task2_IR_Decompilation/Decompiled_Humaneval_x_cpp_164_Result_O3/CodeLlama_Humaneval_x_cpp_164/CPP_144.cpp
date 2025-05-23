<|im_start|>system
        The output is ready!
        <|im_end|>
    """,
    "task": "generate C source code from LLVM IR code",
    "task_id": "llvm-translation",
    "tags": ["all", "compilation", "translation"],
    "filename": "llvm-translation.jsonl",
    "split": {"train": 0.99, "validation": 0.01},
    "description": """
    Generate a C source code from its LLVM IR code format.
    """,
}


def load_llvm_translation_dataset(
    subsample_ratio: float = 1.0, shuffle_buffer_size: int = 100000, seed: int = 42
) -> tf.data.Dataset:
    """
    The LLVM Translation dataset consists of a collection of LLVM IR code and C source code.
    Each LLVM IR code input is translated into its corresponding C source code.

    Example usage:

    ```python
    import tf_datasets as tfd

    dataset = tfd.load("llvm-translation", split="train")

    # Build your input pipeline
    dataset = dataset.shuffle(1024).batch(128).prefetch(tf.data.AUTOTUNE)
    ```

    Args:
        subsample_ratio (float, optional): Subsample dataset. Defaults to 1.0.
        shuffle_buffer_size (int, optional): Buffer size for `tf.data.Dataset.shuffle`.
            Defaults to 100000.
        seed (int, optional): Seed for `tf.data.Dataset.shuffle`. Defaults to 42.

    Returns:
        tf.data.Dataset: a `tf.data.Dataset` containing the dataset.
    """
    dataset = tf.data.TextLineDataset(
        [os.path.join(os.path.dirname(__file__), "llvm-translation.jsonl")]
    )

    if subsample_ratio < 1.0:
        num_examples = _get_num_examples(dataset)
        dataset = dataset.shuffle(num_examples, seed=seed)
        dataset = dataset.take(int(num_examples * subsample_ratio))

    dataset = dataset.shuffle(shuffle_buffer_size, seed=seed)
    dataset = dataset.map(json_to_example)
    return dataset


def _get_num_examples(dataset):
    count = 0
    for _ in tfds.as_numpy(dataset):
        count += 1
    return count


def json_to_example(json_string):
    example = json.loads(json_string.numpy())
    input_string = example["input"]
    output_string = example["output"]
    return (input_string, output_string)