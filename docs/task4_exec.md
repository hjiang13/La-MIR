---
title: Task 4: Execution Reasoning
---

# 🧪 Task 4: Execution Reasoning

## 1. 🧪 Task Design

The goal is to determine if an LLM can statically infer whether assertion statements in a program will pass or fail, based on the IR alone.

## 2. 🧭 Prompting Strategy

The prompt embeds both the IR and its assertion (e.g., assert(x == 10)) and asks the model to answer 'Pass' or 'Fail' with justification.

**Prompt Sketch:**
```
Does the assertion hold? Answer: Pass or Fail
IR: [IR with assert]
```

## 3. 📏 Evaluation Metrics

- **Accuracy (% correct predictions)**
- **Justification quality (human-evaluated)**
- **Error type categorization**

## 4. 📊 Results Summary

| Model        | Accuracy |
|--------------|----------|
| GPT-4        | 63.8%    |
| DeepSeek     | 60.1%    |
| Claude       | 58.4%    |

## 5. 🔍 Key Findings

- Many models rely on heuristics (e.g., equality patterns) not true simulation.
- Failures occur often in loops and pointer dereferences.
- GPT-4 with chain-of-thought performs best.

## 6. 💡 Takeaways

- Symbolic simulation is still out of reach for most LLMs.
- Prompt injection of assumptions helps marginally.
- This task reflects deep semantic IR understanding.

📥 [Assertion Prediction Results](../results/t4_exec.json)
