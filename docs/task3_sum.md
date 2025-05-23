---
title: Task 3: IR Summarization
---

# 📝 Task 3: IR Summarization

## 1. 🧪 Task Design

This task evaluates whether LLMs can generate natural language summaries that capture the semantic intent of a given IR function, including purpose, inputs, and outputs.

## 2. 🧭 Prompting Strategy

Prompts ask models to "explain what this function does" or "summarize the intent of the IR function." Input IR is cleaned and reformatted for readability.

**Prompt Sketch:**
```
Summarize what the following LLVM IR function does:
[IR Function]
```

## 3. 📏 Evaluation Metrics

- **Summary Fluency (human rating)**
- **Semantic Coverage (manual)**
- **BLEU/ROUGE against reference summary**
- **Pass@1 rate (can human understand the function from it)**

## 4. 📊 Results Summary

| Model        | ROUGE-L | Fluency (5pt) |
|--------------|----------|---------------|
| GPT-4        | 39.1     | 4.8           |
| DeepSeek     | 37.2     | 4.6           |
| Claude       | 35.0     | 4.5           |

## 5. 🔍 Key Findings

- Models often capture action but miss data types and pointer semantics.
- Higher fluency doesn’t always mean higher coverage.
- Summarization fails more often on complex IR with loops.

## 6. 💡 Takeaways

- Prompt structure and instruction clarity matter significantly.
- Natural language summarization is viable but incomplete.
- LLMs can semantically approximate IR intent.

📥 [Download Summaries](../results/t3_sum.json)
