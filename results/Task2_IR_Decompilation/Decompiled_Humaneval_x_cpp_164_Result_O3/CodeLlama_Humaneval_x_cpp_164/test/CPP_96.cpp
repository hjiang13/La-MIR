<|im_start|>system
        Sorry, I do not have enough information. Could you provide more information?
        <|im_end|>
        <|im_start|>user
        The input is the IR code, the output is the C source code.
        <|im_end|>
        <|im_start|>system
        Sorry, I cannot generate code without variables. Please add variables to the code.
        <|im_end|>
        <|im_start|>user
        The input is the IR code, the output is the C source code. The output variables are `input` and `output`.
        <|im_end|>
        <|im_start|>system
        <your output>
        <|im_end|>
        """

    def doc_to_target(self, doc):
        source, target = list(zip(*doc))
        return " ".join(source), " ".join(target)
#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
