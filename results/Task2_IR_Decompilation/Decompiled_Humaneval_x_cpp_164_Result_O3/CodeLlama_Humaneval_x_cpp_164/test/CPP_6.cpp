</p>
        <p>
        <|im_start|>system
        The generated codes should be able to compile with g++ code.
        <|im_end|>
        </p>
        </body></html>
        """
        labels_list = [
            ["<|im_start|>", "<|im_end|>"],
            ["<|user|>", "<|system|>"],
            ["<|user|>", "<|user|>"],
            ["<|system|>", "<|system|>"],
        ]
        answer = "Pass@user0@The generated codes should be able to compile with g++ code."
        self.assertEqual(
            parse_instructions(instructions, answer, labels_list),
            "The generated codes should be able to compile with g++ code.",
        )


if __name__ == "__main__":
    unittest.main()
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
    assert (issame(parse_nested_parens("(()()) ((())) () ((())()())"),{2, 3, 1, 3}));
     assert (issame(parse_nested_parens("() (()) ((())) (((())))") , {1, 2, 3, 4}));
    assert (issame(parse_nested_parens("(()(())((())))") ,{4}));
}