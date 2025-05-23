<|im_start|>user
```

### Data Fields

- `input`: The source LLVM IR code.
- `output`: The target C source code.

### Data Splits

All the data is in a single train split.

## Dataset Creation

### Curation Rationale

Our dataset was created to enable researchers to develop a model for decompiling low-level code to C.

### Source Data

#### Initial Data Collection and Normalization

Our dataset is composed of 164 human-written C programs.
The human-written programs are from [Human-xBenchmarks](https://github.com/Euklidian-Project/Human-xBenchmarks).
Each program in Human-xBenchmarks has been compiled to LLVM IR and optimized using `opt -O3`.
The programs are in a variety of domains, including:

- Compression
- Computer Vision
- Crypto
- Data Compression
- Databases
- Machine Learning
- Media
- Miscellaneous
- Numerical Methods
- Office
- Operating Systems
- Parallel Computing
- Programming Languages
- Search

#### Who are the source language producers?

The producers of the source code are humans (developers).

### Annotations

#### Annotation process

The source code was compiled to LLVM IR, optimized and then the optimizer was removed.

#### Who are the annotators?

The annotators of the source code are humans (developers).

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

This dataset was created by Abhishek Kumar, Ekamya Prakash, and Mohit Gupta from the Indian Institute of Technology, Patna.

### Licensing Information

This dataset is licensed with the Attribution 4.0 International [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/).

### Citation Information

Please cite the following paper if you use this dataset in your work:

```
@inproceedings{kumar-etal-2022-decompil,
    title = {Decompilation as a Seq2Seq Mapping: Dataset and Evaluation},
    author = {Kumar, Abhishek  and
      Prakash, Ekamya  and
      Gupta, Mohit},
    booktitle = {Proceedings of the Eighth International Conference on Learning Representations (ICLR)},
    month = {Apr},
    year = {2022},
    url = {https://openreview.net/forum?id=Xv-KrYQ9qW},
    volume = {1},
    pages = {2932--2942},
}
```

### Contributions

Thanks to [@abhishekkumar07](https://github.com/abhishekkumar07) for adding this dataset.