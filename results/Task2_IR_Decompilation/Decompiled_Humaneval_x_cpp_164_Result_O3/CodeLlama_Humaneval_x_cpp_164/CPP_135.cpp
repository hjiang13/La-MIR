<|dataset_end|>
```

**Parts of the code have been removed from the above examples to make it shorter.**

### Data Fields

The JSON files contain the following fields:
- `context`: a part of the source code that appears before the function definition.
- `function_definition`: the source code of the function definition.
- `ir_code`: the LLVM IR code.
- `target_code`: the target source code.

### Data Splits

The dataset is split into a training, validation, and test set.

## Dataset Creation

### Curation Rationale

For a human to solve the tasks, an understanding of low-level programming languages and compiler technologies is required. This is why it is challenging for them.

### Source Data

#### Initial Data Collection and Normalization

The authors use the [HumanEval](https://github.com/microcicon/HumanEval) dataset as a starting point.

#### Who are the source language producers?

The source language producers are the authors of the paper.

### Annotations

#### Annotation process

The target source code is written by an expert in high-performance computation.

#### Who are the annotators?

All annotators are experts in high-performance computation.

### Personal and Sensitive Information

[More Information Needed]

## Considerations for Using the Data

### Social Impact of Dataset

[More Information Needed]

### Discussion of Biases

[More Information Needed]

### Other Known Limitations

[More Information Needed]

## Additional Information

### Dataset Curators

[More Information Needed]

### Licensing Information

[More Information Needed]

### Citation Information

```
@inproceedings{wang-etal-2022-instruction,
    title = "The Instruction Game: Human-in-the-Loop Code Generation for Low-level Programming Languages",
    author = "Wang, Yaohui  and
      Xu, Wei  and
      Liu, Shixiong  and
      Cai, Qingkai  and
      Xu, Ting",
    booktitle = "Proceedings of the Thirty-Sixth AAAI Conference on Artificial Intelligence (AAAI)",
    month = may,
    year = "2022",
    publisher = "AAAI Press",
    url = "https://arxiv.org/abs/2112.12527",
}
```

### Contributions

Thanks to [@lhoestq](https://github.com/lhoestq) for adding this dataset.