---
title: LaMIR: Can LLMs Understand Intermediate Representations?
---

# 🧠 LaMIR: Can Large Language Models Understand Intermediate Representations?

📄 [Read the Paper](https://arxiv.org/abs/2502.06854)  
🎓 Presented at ICML 2025  
🔗 [Back to GitHub Repo](https://github.com/hjiang13/La-MIR)

---

## 📌 Project Overview

![logo](./figures/LaMIR_logo.drawio.png)

**LaMIR** is the first comprehensive benchmark to evaluate whether Large Language Models (LLMs) can understand compiler Intermediate Representations (IRs). We assess six state-of-the-art LLMs 
- GPT-4
- GPT-3.5
- DeepSeek 
- Gemma 2
- LLaMA 3.1 
- Code Llama

across four core IR tasks:

- Structural reasoning (CFGs),
- Syntactic transformation (decompilation),
- Semantic abstraction (summarization),
- Execution behavior analysis (assertion prediction).

We highlight persistent limitations in control flow modeling, semantic fidelity, and loop handling—offering key insights for building IR-aware language models.

---
## 🔍 Study Design Overview

![Study Overview](./figures/study_design_overview.png)

The figure above illustrates the overall design of our benchmark framework. We evaluate LLMs on four core tasks that capture different aspects of IR comprehension:

- **Task 1 – Structural Understanding:** Reconstruct the control flow graph (CFG) from IR, assessing models’ ability to infer branching logic and loop structures.
- **Task 2 – Syntactic Comprehension:** Decompile IRs into high-level C/C++ code, measuring syntactic translation fidelity and re-executability.
- **Task 3 – Semantic Comprehension:** Summarize IR functions using natural language, focusing on semantic abstraction of input/output behavior.
- **Task 4 – Execution Reasoning:** Predict whether assertion statements hold based on static IR execution, revealing a model’s reasoning depth.

Each task is formulated with carefully crafted prompts, grounded evaluation metrics, and multi-level compiler optimizations to challenge and quantify LLMs’ capacity to reason over IRs.

---

## 📋 Tasks Overview

Explore each benchmark task in detail:

- 🔗 [Task 1: CFG Construction](./task1_cfg.md)  
  Reconstruct the **control flow graph (CFG)** from IR by identifying basic blocks and control edges.

- 🔗 [Task 2: IR Decompilation](./task2_decomp.md)  
  Translate IR into high-level **C/C++ source code**, assessing syntactic understanding via re-execution.

- 🔗 [Task 3: IR Summarization](./task3_sum.md)  
  Generate **natural language summaries** of IR functions, focusing on their purpose, inputs, and outputs.

- 🔗 [Task 4: Execution Reasoning](./task4_exec.md)  
  Predict **which assertion statements will pass or fail** by statically simulating IR-based program behavior.


---

## 📥 Download

- 🔹 [Dataset (IRs + prompts)](https://github.com/hjiang13/La-MIR/tree/main/data)
- 🔹 [Prediction Results](https://github.com/hjiang13/La-MIR/tree/main/results)
- 🔹 [Figures](./figures)

---

## ✉️ Contact

Maintained by [Hailong Jiang](mailto:hjiang13@kent.edu)  
Feel free to open an [issue](https://github.com/hjiang13/La-MIR/issues) for questions or contributions.
