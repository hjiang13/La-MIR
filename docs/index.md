---
title: LaMIR: Understanding IR with LLMs
---

# 🧠 LaMIR: Understanding Intermediate Representation with LLMs

📄 [Read the Paper](https://arxiv.org/abs/2502.06854)  
🎓 Presented at ICML 2025  
🔗 [Back to GitHub Repo](https://github.com/hjiang13/La-MIR)

---

## 🔍 What is LaMIR?

**LaMIR** is a benchmark designed to evaluate whether large language models (LLMs) can understand the semantics of compiler intermediate representations (IR). It introduces four structured tasks targeting control flow, semantic generation, execution reasoning, and behavioral equivalence.

---

## 📊 Evaluation Results

| Model      | T1: CFG (%) | T2: Decomp (%) | T3: Exec (%) | T4: Consistency (%) |
|------------|-------------|----------------|--------------|---------------------|
| GPT-4      | 52.3        | 45.6           | 71.2         | 63.8                |
| DeepSeek   | 48.9        | 43.2           | 69.0         | 60.1                |
| Claude     | 44.7        | 41.8           | 66.3         | 58.4                |

📘 [View Task Details](./tasks.md)  
📈 [See Full Results](./results.md)

---

## 📥 Download

- 🔹 [Dataset (IRs + prompts)](https://github.com/hjiang13/La-MIR/tree/main/data)
- 🔹 [Prediction Results](https://github.com/hjiang13/La-MIR/tree/main/results)
- 🔹 [Figures](./figures)

---

## ✉️ Contact

Maintained by [Hailong Jiang](mailto:hjiang13@kent.edu)  
Feel free to open an [issue](https://github.com/hjiang13/La-MIR/issues) for questions or contributions.
