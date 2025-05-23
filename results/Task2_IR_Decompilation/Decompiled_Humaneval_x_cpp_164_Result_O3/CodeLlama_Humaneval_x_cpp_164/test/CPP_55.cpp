<|im_start|>system
Your C source code format is as follows:
        <|im_end|>
<|im_start|>user
#include <stdio.h>
int fib(int n) {
    int F[1000];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}
```

### Baseline

The baseline of the human-language programming task is [CodeT5](https://github.com/salesforce/CodeT5).
In the current implementation, the baseline can only be trained in the single GPU.

```
python -u run_codet5.py --do_train --do_eval --data_path data/human_cs_programming.jsonl --model_name=Salesforce/codet5-base --output_dir=./save/codet5/human_cs_programming --max_source_length=256 --max_target_length=256 --val_max_target_length=256 --test_max_target_length=256 --train_batch_size=4 --eval_batch_size=4 --gradient_accumulation_steps=2 --learning_rate=1e-4 --beam_size=4 --train_step=10000 --eval_step=1000 --gpus 1
```

### Evaluation

For evaluation, we provide the following script.

```
python evaluate.py --data_path data/human_cs_programming.jsonl --model_path save/codet5/human_cs_programming --output_path save/codet5/human_cs_programming/predictions.jsonl
```

### Submission

You can submit the result file to the [CodaLab leaderboard](https://competitions.codalab.org/competitions/33385).

## Citation

If you use our dataset in your research, please cite the following paper.

```
@misc{matsuzawa2022humancs,
      title={Human-in-the-Loop Machine Learning for Human-Level Coding},
      author={Yoshitaka Matsuzawa and Tomoyuki Kataoka and Masaaki Nagata and Kento Watanabe},
      year={2022},
      eprint={2203.07410},
      archivePrefix={arXiv},
      primaryClass={cs.SE}
}
```

## Contact

If you have any questions, please contact the authors.

- [Yoshitaka Matsuzawa](https://researchmap.jp/matsuzawa/?lang=english)
- [Tomoyuki Kataoka](https://researchmap.jp/tomoyuki.kataoka/?lang=english)
- [Masaaki Nagata](https://researchmap.jp/Masaaki.Nagata/?lang=english)
- [Kento Watanabe](https://researchmap.jp/watanabe.kento/?lang=english)
#undef NDEBUG
#include<assert.h>
int main(){
    assert (fib(10) == 55);
    assert (fib(1) == 1);
    assert (fib(8) == 21);
    assert (fib(11) == 89);
    assert (fib(12) == 144);
}
