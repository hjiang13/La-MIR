---
title: Task 2: IR Decompilation
---

# 🧾 Task 2: IR Decompilation

## 1. 🧪 Task Design

This task assesses whether LLMs can translate LLVM IR back into high-level C/C++ source code. It evaluates syntactic understanding and translation fidelity, and tests whether the decompiled code can be re-executed to yield the same result.

## 2. 🧭 Prompting Strategy

We prompt models with a declarative role plus input IR and ask for equivalent C-style code. Few-shot prompts use easy arithmetic cases to build expectation of syntax.

**Prompt Sketch:**
```
You are a decompiler...
Input IR: [IR snippet]
Output: high-level source code in C/C++
```

## 3. 📏 Evaluation Metrics

- **Re-executability**: Can the output code be compiled and run?
- **Output Equivalence**: Does output match original IR execution?
- **Exact Match Rate**: String match to ground truth
- **Token-level BLEU / ROUGE**

## 4. 📊 Results Summary

| Model        | BLEU Score | Re-exec. Rate |
|--------------|------------|---------------|
| GPT-4        | 45.6       | High          |
| DeepSeek     | 43.2       | High          |
| Claude       | 41.8       | Medium        |
| Gemma 2      | 38.9       | Low           |

## 5. 🔍 Key Findings

- GPT and DeepSeek demonstrate strong lexical and semantic fidelity.
- Exact syntax is often incorrect (e.g., type casting, return values).
- Errors tend to accumulate in deeper optimization levels.

## 6. 💡 Takeaways

- Codegen-aware prompting improves output realism.
- Re-executability is a strong evaluation proxy.
- AST-based structure matching may help refine metrics.

📥 [Download Decompiled Outputs](../results/t2_decomp.json)
