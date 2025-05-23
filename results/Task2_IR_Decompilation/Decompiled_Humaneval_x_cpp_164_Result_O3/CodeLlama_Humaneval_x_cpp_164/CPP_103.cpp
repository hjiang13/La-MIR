<|resp_start|>
        ```
        #include &lt;bits/stdc++.h&gt;
        using namespace std;
        
        string rounded_avg(int x, int y)
        {
          stringstream ss;
          ss &lt;&lt; (x+y)/2;
          return ss.str();
        }
        ```
        <|resp_end|>
        <|im_start|>user
        Thanks! I will try to use it next time I have to compare two numbers.
        <|im_end|>
        <|im_start|>system
        Do you want to learn more about how to use this function? 
        <|im_end|>
        <|im_start|>user
        Yes, I would like to learn more.
        <|im_end|>
        <|im_start|>system
        Here is the docstring for this function:
        <|im_end|>
        <|im_start|>system
        Compute the average of x and y, rounded down to the nearest integer.
        <|im_end|>
        <|im_start|>user
        Thank you!
        <|im_end|>
        <|im_start|>system
        What else can I help you with?
        <|im_end|>
        <|im_start|>user
        Bye.
        <|im_end|>
        <|im_start|>system
        Bye.
        <|im_end|>
        """
        return


class ConvAI3WithMemoryContextTeacher(ConvAI2Teacher):
    def __init__(self, opt, shared=None):
        opt['add_memory'] = True
        super().__init__(opt, shared)


class ConvAI3WithoutMemoryTeacher(ConvAI2Teacher):
    def __init__(self, opt, shared=None):
        opt['add_memory'] = 'no_memory'
        super().__init__(opt, shared)