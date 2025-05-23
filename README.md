![logo](./docs/figures/LaMIR_logo.drawio.png)
# LaMIR: Large Language Models for Intermediate Representation

This repository contains the official implementation and evaluation framework for the ICML 2025 paper:

**"Can Large Language Models Understand the Semantics of Intermediate Representation Code?"**

[Paper Link](https://arxiv.org/abs/2502.06854) | [Poster](./figures/poster.pdf) | [Webpage](https://hjiang13.github.io/La-MIR/)

---

## 🔍 Overview

LaMIR is a benchmarking framework to evaluate and analyze the ability of LLMs to understand compiler **Intermediate Representation (IR)**. It includes multiple tasks reflecting different levels of semantic understanding:

* **CFG Reconstruction**
* **Call Graph Prediction**
* **Data Dependence Graph (DDG) Analysis**
* **Execution Reasoning**
* **Behavior Consistency**

The project provides all necessary IR datasets, task prompts, expected outputs, baseline results, and analysis tools.

---

## 🗂️ Repository Structure

```
LaMIR/
├── src/                    # Core source code (prompt generation, task evaluation)
│   ├── model/              # LLM interfaces & wrappers
│   ├── tasks/              # Implementations of each evaluation task (T1~T4)
│   ├── data/               # IR preprocessing, slicing, labeling
│   ├── utils/              # Shared utilities (e.g., IO, parsing)
│   └── main.py             # Entry point for launching evaluation
├── configs/                # Task configurations and LLM settings
├── scripts/                # Shell scripts for running experiments
│   ├── run_all.sh
│   └── run_task.sh
├── results/                # Output predictions, performance reports
├── figures/                # Figures from the paper
├── docs/                   # Reproducibility, task definitions
│   └── reproducibility.md
├── requirements.txt        # Python dependencies
├── LICENSE                 # Open-source license (MIT)
├── .gitignore              # Git ignore file
└── README.md               # Project summary (this file)
```

---

## 🚀 Getting Started

1. **Install dependencies**:

```bash
pip install -r requirements.txt
```

2. **Run evaluation on all tasks**:

```bash
bash scripts/run_all.sh
```

3. **Check output scores**:

```bash
cat results/summary.csv
```

---

## 📊 Tasks

| Task                         | Description                                                                                 |
| ---------------------------- | ------------------------------------------------------------------------------------------- |
| **T1: CFG Construction**     | Given IR, reconstruct its Control Flow Graph by identifying basic blocks and control edges. |
| **T2: IR Decompilation**     | Translate IR back into natural-language-like statements that reflect its semantics.         |
| **T3: Execution Reasoning**  | Simulate IR execution given inputs and predict the output values.                           |
| **T4: Behavior Consistency** | Judge whether two IRs exhibit the same behavior (semantics-preserving transformations).     |

Each task is described in detail in [`docs/reproducibility.md`](docs/reproducibility.md).

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙋 Citation

```bibtex
@inproceedings{jiang2025lamir,
  title={Can Large Language Models Understand the Semantics of Intermediate Representation Code?},
  author={Jiang, Hailong and et al.},
  booktitle={International Conference on Machine Learning (ICML)},
  year={2025}
}
```

---

## 🔗 Contact

For questions or feedback, please open an issue or contact [hjiang13@kent.edu](mailto:hjiang13@kent.edu).
