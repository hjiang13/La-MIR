<|im_end|>
```

Codex is able to generate C++ code with the following format:
```c++
void string_xor(std::string *s1, std::string *s2) {
  if (s1->length() == 0) {
    return;
  } else {
    if (s2->length() == 0) {
      return;
    } else {
      if (*((*s1)[0]) == *((*s2)[0])) {
        return;
      } else {
        long n;
        if (s1->length() > s2->length()) {
          n = s2->length();
        } else {
          n = s1->length();
        }
        for (int i = 0; i < n; i++) {
          if (*((*s1)[i]) == *((*s2)[i])) {
            return;
          }
        }
        return;
      }
    }
  }
}
```

The task of this competition is to generate C++ code as the output from the input IR code.

## Data

The data is based on the [Human_xBenchmarks](https://github.com/Human-Xbenchmarks/Human_XBenchmarks).
The task is to generate C/C++ code from the input LLVM IR code.

### Dataset size

The total size of the dataset is 1.5GB.

### Data format

The dataset is stored in JSON Lines format.
The JSON object has the following structure:

```json
{
  "input_id": "00000001",
  "input_string": "Codex input prompt",
  "output_id": "00000001",
  "output_string": "Codex output text"
}
```

### Data statistics

The data is split into train and validation sets.
The statistics of the train and validation sets are shown in the below table:

|                        | Train set | Validation set |
|:-----------------------|:---------:|:--------------:|
| Input prompts          | 150,241   | 15,024         |
| Unique inputs          | 1,215     | 150            |
| Outputs per input      | 123.42    | 10.01          |
| Avg. tokens per input  | 382.83    | 382.58         |
| Avg. tokens per output | 356.94    | 356.99         |
| Total tokens           | 57,514,602| 225,468        |

## Evaluation

The competition is evaluated using the token-level BLEU score.

## Submission

You can submit your results in JSON Lines format to the [competition page](https://aicrowd.com/challenges/ai-for-prosaic-human-evaluation/submissions/new).
The JSON object has the following structure:

```json
{
  "input_id": "00000001",
  "output_id": "00000001",
  "output_string": "Codex output text"
}
```

## Baselines

The baseline models are trained and evaluated on a single machine equipped with Nvidia Tesla V100 GPU.

### Codex

[Codex](https://arxiv.org/abs/2107.03374) is a large-scale general-purpose language model developed by OpenAI.
The model is trained with 404.8GB pre-training data.
The model is evaluated with the following hyperparameters:

- `temperature`: 0.0
- `repetition_penalty`: 1.5
- `num_beams`: 6
- `num_return_sequences`: 1
- `length_penalty`: 0.6

### GPT-2

[GPT-2](https://arxiv.org/abs/1907.11692) is a large-scale general-purpose language model trained with 40GB pre-training data.
The model is evaluated with the following hyperparameters:

- `temperature`: 0.7
- `repetition_penalty`: 1.5
- `num_beams`: 2
- `num_return_sequences`: 1

## References

```bibtex
@misc{brown2020language,
  title={Language Models are Few-Shot Learners},
  author={Tom B. Brown and Benjamin Mann and Nick Ryder and Melanie Subbiah and Jared Kaplan and Prafulla Dhariwal and Arvind Neelakantan and Pranav Shyam and Girish Sastry and Amanda Askell and Sandhini Agarwal and Ariel Herbert-Voss and Gretchen Krueger and Tom Henighan and Rewon Child and Aditya Ramesh and Daniel M. Ziegler and Jeffrey Wu and Clemens Winter and Christopher Hesse and Mark Chen and Eric Sigler and Mateusz Litwin and Scott Gray and Benjamin Chess and Jack Clark and Christopher Berner and Sam McCandlish and Alec Radford and Ilya Sutskever and Dario Amodei},
  year={2020},
  eprint={2005.14165},
  archivePrefix={arXiv},
  primaryClass={cs.CL}
}
```