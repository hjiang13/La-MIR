# `La-MIR`: `La`rge `La`nguage `M`odels for `I`ntermediate `R`epresentation

This repository contains the official implementation and evaluation framework for the ICML 2025 paper:

**"Can Large Language Models Understand the Semantics of Intermediate Representation Code?"**

**[📄 Paper Link](https://arxiv.org/abs/2502.06854)** | **[🖼️ Poster](./figures/poster.pdf)**


---

## 🔍 Overview

La-MIR is a benchmarking framework to evaluate and analyze the ability of LLMs to understand compiler **Intermediate Representation (IR)**. It includes multiple tasks reflecting different levels of semantic understanding:

* **CFG Reconstruction**
* **Call Graph Prediction**
* **Data Dependence Graph (DDG) Analysis**
* **Execution Reasoning**

The project provides all necessary IR datasets, task prompts, expected outputs, baseline results, and analysis tools.

---

## 🗂️ Repository Structure

```
La-MIR/
├── src/                    # Core source code (prompt generation, task evaluation)
│   ├── model/              # LLM interfaces & wrappers
│   ├── data/               # IR processing and annotation
│   ├── utils/              # Shared utilities
│   └── main.py             # Entry point for evaluation
├── configs/                # Task configurations and LLM settings
├── scripts/                # Shell scripts for quick run
│   ├── run_all.sh
│   └── run_task.sh
├── results/                # Output predictions, scores, figures
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

| Task                | Description                                    |
| ------------------- | ---------------------------------------------- |
| CFG Reconstruction  | Predict basic blocks and control flow edges    |
| Call Graph          | Identify caller-callee relationships           |
| DDG Analysis        | Capture data dependencies between instructions |
| Execution Reasoning | Predict IR output given an input               |

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
