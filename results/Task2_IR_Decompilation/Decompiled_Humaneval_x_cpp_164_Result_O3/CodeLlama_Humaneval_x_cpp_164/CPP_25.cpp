<|im_start|>user
        ```
        #include <stdlib.h>
        #include <vector>
        using namespace std;
        void factorize(vector<int> &primes, int n) {
            int i = 2;
            while(n > 1) {
                while (n % i == 0) {
                    primes.push_back(i);
                    n /= i;
                }
                i += 1;
                if (i * i > n) break;
            }
            if (n != 1) primes.push_back(n);
        }
        ```
        <|im_end|>
        <|im_start|>system
        Your answer is correct!
        <|im_end|>
<|endoftext|>
```

### Data Fields

- `func_name` : Name of the function.
- `args` : Arguments of the function.
- `return_type` : Return type of the function.
- `docstring` : Comment describing the function.
- `code` : Code of the function.
- `annotations` : Annotations on the code.
- `return_line` : Line which has the return statement (usually last line).

### Data Splits

The dataset is split into train, validation and test set.

|                            | Tain   | Valid | Test |
| -----                      | ------ | ----- | ---- |
| Input/Output Examples      | 110708 | 18484 | 19484 |
| Examples with Function Spec | 110708 | 18484 | 19484 |
| Examples with Docstring    | 110708 | 18484 | 19484 |
| Examples with Comments     | 110708 | 18484 | 19484 |

## Dataset Creation

### Curation Rationale

[More Information Needed]

### Source Data

#### Initial Data Collection and Normalization

[More Information Needed]

#### Who are the source language producers?

[More Information Needed]

### Annotations

#### Annotation process

[More Information Needed]

#### Who are the annotators?

[More Information Needed]

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
@article{DBLP:journals/corr/abs-2108-13330,
  author    = {Yinhan Liu and
               Myle Ott and
               Naman Goyal and
               Jingfei Du and
               Mandar Joshi and
               Danqi Chen and
               Omer Levy and
               Mike Lewis and
               Luke Zettlemoyer and
               Veselin Stoyanov},
  title     = {CodeXGLUE: {A} Machine Learning Benchmark Dataset for Code Understanding
               and Generation},
  journal   = {CoRR},
  volume    = {abs/2108.13330},
  year      = {2021},
  url       = {https://arxiv.org/abs/2108.13330},
  archivePrefix = {arXiv},
  eprint    = {2108.13330},
  timestamp = {Tue, 07 Sep 2021 11:19:16 +0200},
  biburl    = {https://dblp.org/rec/journals/corr/abs-2108-13330.bib},
  bibsource = {dblp computer science bibliography, https://dblp.org}
}
```

### Contributions

Thanks to [@patil-suraj](https://github.com/patil-suraj) for adding this dataset.