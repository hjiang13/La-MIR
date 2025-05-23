<|im_start|>human
        I have no idea.
        <|im_end|>
        <|im_start|>system
        The C source code is:
        ```
        #include <bits/stdc++.h>
        using namespace std;
        void find_max(string &max_val, vector<string> &words)
        {
            string temp;
            string cur_max = "";
            vector<string>::iterator it = words.begin();
            while (it != words.end())
            {
                temp = *it;
                if (temp == "")
                {
                    it++;
                    continue;
                }
                if (temp.size() > cur_max.size())
                {
                    cur_max = temp;
                }
                else if (temp.size() < cur_max.size())
                {
                    ;
                }
                else
                {
                    if (strcmp(temp.c_str(), cur_max.c_str()) > 0)
                    {
                        cur_max = temp;
                    }
                }
                it++;
            }
            max_val = cur_max;
        }
        ```
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        The task is complete. You can try a new task by writing "new task".
        <|im_end|>        
        '''

        return text

    def get_task_prefix(self):
        return 'translate from llvm ir to c code\n'

    def test_io_boundaries(self, text):
        if text[0] != '<|im_start|>':
            return False
        if text[-1] != '<|im_end|>':
            return False
        if text.count('<|im_start|>') != text.count('<|im_end|>'):
            return False
        return True

    def process_completion(self, text, task_description=None):
        # text = "<|im_start|>human\n" + text.replace("\n", "\n<|im_end|>\n<|im_start|>human\n")
        text = "<|im_start|>system\n" + text.replace("\n", "\n<|im_end|>\n<|im_start|>system\n")
        text = 'translate from llvm ir to c code\n' + text
        return text

    def process_example(self, example, is_task_example=False):
        description = example['description']
        llvm_ir = example['input']
        c_code = example['output']
        # return "<|im_start|>human\n" + description + "\n<|im_end|>\n<|im_start|>system\n" + llvm_ir + "\n<|im_end|>\n<|im_start|>human\n<|im_end|>\n<|im_start|>system\n" + c_code + "\n<|im_end|>\n\n"
        return "translate from llvm ir to c code\n" + description + "\n<|im_end|>\n<|im_start|>system\n" + llvm_ir + "\n<|im_end|>\n<|im_start|>human\n<|im_end|>\n<|im_start|>system\n" + c_code + "\n<|im_end|>\n\n"

    def get_description(self, example):
        return example['description']

    def get_input(self, example):
        return example['input']

    def get_output(self, example):
        return example['output']