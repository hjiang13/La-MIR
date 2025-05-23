<|im_start|>system
Here is your output:
        ```
        int add(int, int);
        int add(int a1, int a2) {
          return a1 + a2;
        }
        ```
<|im_end|>
<|im_start|>user

<|im_end|>
<|im_start|>system
Please rate the task difficulty.
<|im_end|>
<|im_start|>user

        easy
<|im_end|>
<|im_start|>system
Please rate the semantic similarity between the input and output.
<|im_end|>
<|im_start|>user

        almost exactly
<|im_end|>
<|im_start|>system
Please rate the grammar quality of the output.
<|im_end|>
<|im_start|>user

        perfect
<|im_end|>
<|im_start|>system
Would you like to provide an additional comment regarding the output?
<|im_end|>
<|im_start|>user

        no
<|im_end|>
<|im_start|>system
Thank you. We will follow up shortly with your payment information.
<|im_end|>
        """,
        """
<|im_start|>system

        Please write a Python function which will take an array of integers and the array will include values that are repeated at least once and return the first instance of the repeated value.

<|im_end|>
<|im_start|>user

        def find_repeat(arr):
          for i in range(len(arr)):
            x = arr[i]
            if x in arr[i+1:]:
              return x
          return None
<|im_end|>
<|im_start|>system
Please rate the task difficulty.
<|im_end|>
<|im_start|>user

        easy
<|im_end|>
<|im_start|>system
Please rate the semantic similarity between the input and output.
<|im_end|>
<|im_start|>user

        almost exactly
<|im_end|>
<|im_start|>system
Please rate the grammar quality of the output.
<|im_end|>
<|im_start|>user

        perfect
<|im_end|>
<|im_start|>system
Would you like to provide an additional comment regarding the output?
<|im_end|>
<|im_start|>user

        no
<|im_end|>
<|im_start|>system
Thank you. We will follow up shortly with your payment information.
<|im_end|>
        """
    ]
)

# Values and Notes:
# - 1, 1, 1 for all dialogues
# - 1, 10, 1 for first dialogue
# - 1, 10, 10 for second dialogue

# Average ratings
print('Average ratings:')
print(f'    Difficulty:\t\t{np.mean(difficulty_ratings):.4f}')
print(f'    Semantic similarity:\t{np.mean(semantic_similarity_ratings):.4f}')
print(f'    Grammar quality:\t\t{np.mean(grammar_quality_ratings):.4f}')

# Standard deviations
print('Standard deviations:')
print(f'    Difficulty:\t\t{np.std(difficulty_ratings):.4f}')
print(f'    Semantic similarity:\t{np.std(semantic_similarity_ratings, dtype=np.float64):.4f}')
print(f'    Grammar quality:\t\t{np.std(grammar_quality_ratings):.4f}')

# Median ratings
print('Median ratings:')
print(f'    Difficulty:\t\t{np.median(difficulty_ratings):.4f}')
print(f'    Semantic similarity:\t{np.median(semantic_similarity_ratings):.4f}')
print(f'    Grammar quality:\t\t{np.median(grammar_quality_ratings):.4f}')