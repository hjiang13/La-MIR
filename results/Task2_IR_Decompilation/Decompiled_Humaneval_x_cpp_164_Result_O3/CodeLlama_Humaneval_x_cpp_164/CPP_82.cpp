<|im_start|>system
Here is the C source code output:
```
bool prime_length(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const &);
```
<|im_end|>
<|im_start|>user

       This is the correct output for the IR code given as input. Thank you for your help!
       <|im_end|>
       """

    def __init__(self, task_name="IR to C source code", task_description="Convert IR to C source code format without any explanation or comments"):
        super().__init__(task_name=task_name, task_description=task_description)

    def get_task_details(self):
        return task.TaskMetadata(
            name="convert IR to C source code",
            description="Convert IR to C source code format without any explanation or comments",
            keywords=["optimization", "reinforcement learning", "compiler"],
            max_input_length_per_query=2000,
            max_queries=10000,
        )