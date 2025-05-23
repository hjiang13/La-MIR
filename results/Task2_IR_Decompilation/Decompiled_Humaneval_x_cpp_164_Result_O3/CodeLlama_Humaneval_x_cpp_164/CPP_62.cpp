<|im_start|>system
Congratulations! You have completed all tasks!
<|im_end|>
<|im_start|>user
Thank you for your participation.
<|im_end|>
<|endoftext|>

### Step 3:

Then we use `imaginate.py` to get the output.

```
python imagine.py --model=gpt2 --load_checkpoint ./models/  --temperature 0.9 --top_k 40 --text "<|im_start|>system" --task Translate --id <your_id> --length 1000
```

This will generate a file `imagination.txt` in your local folder.

# Acknowledgements

We thank the authors of the following works for providing their models and datasets. 

```
@misc{GPT2,
  author = {Alec Radford, Jeffrey Wu, Rewon Child, David Luan, Dario Amodei, Ilya Sutskever},
  title = {Language Models are Unsupervised Multitask Learners},
  year = {2019},
  publisher = {OpenReview},
  doi = {10.1162/taac_a_00014},
  url = {https://openreview.net/forum?id=rJ4km2R5t7},
}
```

```
@misc{gpt-2,
  author = {Alec Radford, Jeffrey Wu, Rewon Child, David Luan, Dario Amodei, Ilya Sutskever},
  title = {Language Models are Few-Shot Learners},
  year = {2020},
  publisher = {OpenReview},
  doi = {10.1162/taac_a_00014},
  url = {https://openreview.net/forum?id=r1QRR4BAd2K},
}
```

```
@misc{GPT-3,
  author = {Tom B. Brown, Benjamin Mann, Nick Ryder, Melanie Subbiah, Jared Kaplan, Prafulla Dhariwal, Arvind Neelakantan, Pranav Shyam, Girish Sastry, Amanda Askell, Sandhini Agarwal, Ariel Herbert-Voss, Gretchen Krueger, Tom Henighan, Rewon Child, Aditya Ramesh, Daniel M. Ziegler, Jeffrey Wu, Clemens Winter, Christopher Hesse, Mark Chen, Eric Sigler, Mateusz Litwin, Scott Gray},
  title = {Language Models are Few-Shot Learners},
  year = {2020},
  publisher = {OpenReview},
  doi = {10.1162/taac_a_00014},
  url = {https://openreview.net/forum?id=r1QRR4BAd2K},
}
```

```
@misc{radford2020gpt3,
  title={GPT3: The Big Gesture Language Model}, 
  author={Alec Radford},
  year={2020},
  eprint={2005.14165},
  archivePrefix={arXiv},
  primaryClass={cs.LG}
}
```

```
@misc{brown2020language,
      title={Language Models are Few-Shot Learners}, 
      author={Tom B. Brown and Benjamin Mann and Nick Ryder and Melanie Subbiah and Jared Kaplan and Prafulla Dhariwal and Arvind Neelakantan and Pranav Shyam and Girish Sastry and Amanda Askell and Sandhini Agarwal and Ariel Herbert-Voss and Gretchen Krueger and Tom Henighan and Rewon Child and Aditya Ramesh and Daniel M. Ziegler and Jeffrey Wu and Clemens Winter and Christopher Hesse and Mark Chen and Eric Sigler and Mateusz Litwin and Scott Gray},
      year={2020},
      eprint={2005.14165},
      archivePrefix={arXiv},
      primaryClass={cs.CL}
}
```

```
@misc{radford2019language,
  title={Language Models are Unsupervised Multitask Learners},
  author={Alec Radford, Jeffrey Wu, Rewon Child, David Luan, Dario Amodei and Ilya Sutskever},
  year={2019},
  eprint={1907.11692},
  archivePrefix={arXiv},
  primaryClass={cs.CL}
}
```

```
@misc{gpt-2-xl,
  author = {Wolf, Thomas and Hutter, Frank},
  title = {GPT-2 XL},
  year = {2020},
  howpublished = {\url{https://huggingface.co/transformers/model_doc/gpt2.html#gpt2xl}},
  note = {An implementation of OpenAI's GPT-2 XL language model in the transformers library}
}
```

```
@misc{gpt-neo,
  author = {George, Sanjay},
  title = {GPT-Neo},
  year = {2021},
  howpublished = {\url{https://huggingface.co/EleutherAI/gpt-neo-125M}},
  note = {An implementation of EleutherAI's GPT-Neo language model in the transformers library}
}
```