<|im_start|>system
Here is a C source code format solution:```
int fizz_buzz(int x) {
int a=0;
for(int i=0;i<x;i++){
int b=i%11;
if(b!=0){
a++;
int c=i%13;
if(c!=0){
if(i%10==7)a++;
}else{
a++;
}
}
}
return a;
}
```
<|im_end|>
|
|


### Acknowledgements

We are grateful to the authors of CodeXGlue for the inspiration of this dataset.

<pre>
@misc{CodeXGLUE,
  title={CodeXGLUE: A Benchmark Dataset and Open Challenge for Code Intelligence},
  author={CodeXGLUE Community},
  howpublished={\url{https://github.com/microsoft/CodeXGLUE}},
  year={2020}
}
</pre>

### Citation

Please cite our paper if you use this dataset in your work:

```bibtex
@article{wang2021codecass,
  title={CodeCASS: an Adversarially-Generated Code Dataset for Source Code Summarization},
  author={Wang, Shufan and Ahmed, Ishtiaque and Yasumoto, Kohki and Wang, Zi and Zhang, Yang and Collier, Nigel and Choudhury, Monojit},
  journal={arXiv preprint arXiv:2109.08167},
  year={2021}
}
```

### License

This work is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).