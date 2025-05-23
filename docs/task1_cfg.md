---
title: Task 1: CFG Construction
---

# 🧩 Task 1: Control Flow Graph (CFG) Construction

## 1. 🧪 Task Design

This task evaluates whether LLMs can reconstruct a program's control flow graph (CFG) directly from its LLVM IR. A CFG is a directed graph where nodes represent basic blocks, and edges represent possible control transfers. Successful reconstruction reflects a model's ability to reason about branching, loops, and IR structural boundaries.

## 2. 🧭 Prompting Strategy

We use a meta-template prompt that includes:
- Role declaration: “You are a control flow graph analyzer...”
- IR input
- Expected output format: a DOT graph or structured list of edges
- One-shot or few-shot examples

**Example Prompt (Simplified):**
```
You are a control flow graph analyzer...
Input IR: [IR]
Output: DOT format CFG with labeled nodes and edges.
```

## 3. 📏 Evaluation Metrics

We evaluate from multiple structural dimensions:
- **Node Construction Accuracy** – correct identification of basic blocks
- **Edge Construction Accuracy** – correct control edges between blocks
- **Full CFG Accuracy** – both nodes and edges are correct
- **Loop Edge Accuracy** – correct modeling of loop back edges
- **Conditional Branch Accuracy** – correct identification of conditional branches

## 4. 📊 Results Summary

| Model        | Node Acc. | Full Acc. | Loop Acc. | Cond Branch Acc. |
|--------------|-----------|-----------|-----------|-------------------|
| GPT-4        | 50        | 39        | 9         | 2                 |
| DeepSeek R1  | 64        | 57        | 6         | 1                 |
| GPT-3        | 18        | 14        | 3         | 1                 |
| Gemma 2      | 18        | 16        | 2         | 0                 |
| LLaMA 3.1    | 17        | 15        | 2         | 0                 |
| Code Llama   | 0         | 0         | 0         | 0                 |

## 5. 🔍 Key Findings

- **Structural modeling is fragile**: Most models make mistakes in segmenting IR into valid basic blocks.
- **Control edges are challenging**: Even GPT-4 and DeepSeek struggle with loop and branch reconstructions.
- **Chain-of-Thought (CoT) helps**: DeepSeek R1’s CoT prompting improves per-sample accuracy.

## 6. 💡 Takeaways

- IR-aware prompting strategies (e.g., explicit control flow roles) are crucial.
- Future LLMs should be enhanced with structural reasoning capability.
- Loop handling remains the hardest sub-task in CFG construction.

📥 [Download Sample Outputs (JSON)](../results/t1_cfg_outputs.json)
