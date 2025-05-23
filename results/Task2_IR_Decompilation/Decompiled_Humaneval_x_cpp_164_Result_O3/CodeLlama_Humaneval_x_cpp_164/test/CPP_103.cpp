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
#undef NDEBUG
#include<assert.h>
int main(){
    assert (rounded_avg(1, 5) == "11");
    assert (rounded_avg(7, 13) == "1010");
    assert (rounded_avg(964,977) == "1111001010");
    assert (rounded_avg(996,997) == "1111100100");
    assert (rounded_avg(560,851) == "1011000001");  
    assert (rounded_avg(185,546) == "101101101");
    assert (rounded_avg(362,496) == "110101101");
    assert (rounded_avg(350,902) == "1001110010");
    assert (rounded_avg(197,233) == "11010111");
    assert (rounded_avg(7, 5) == "-1");
    assert (rounded_avg(5, 1) == "-1");
    assert (rounded_avg(5, 5) == "101");
}
