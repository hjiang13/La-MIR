<|im_start|>system
Here is your C source code output:
```

#include <vector>

bool pairs_sum_to_zero(std::vector<int> const &data) {
    for (std::size_t i = 0; i + 1 < data.size(); ++i) {
        for (std::size_t j = i + 1; j < data.size(); ++j) {
            if (data[i] + data[j] == 0) {
                return true;
            }
        }
    }
    return false;
}
```
```
<|im_end|>
<|im_start|>user

        That is correct! You have solved the problem!
        <|im_end|>
<|im_start|>system
        To read more about converting IR code to C source code, please refer to:
        https://clang.llvm.org/docs/CommandGuide/clang.html#generating-c-code-with-clang
        https://llvm.org/docs/CommandGuide/llc.html
        <|im_end|>
<|im_start|>user

        I have read a little bit about these tools.
        Thank you for your help! I will talk to you again!
        <|im_end|>
<|im_start|>system
Thank you for the conversation!
<|im_end|>
'''


def test_system_api():
    cfg = ChatServiceConfig(
        agent_classes=[
            PanGuAlphaRewriter,
            GPT3Agent,
            RuGPT3XL,
            ImageCaptioningSaliency,
            ImageCaptioningXL,
            ImageCaptioningSRN,
            DummyAgent
        ],
        agent_types=[
            AgentType.REWRITER,
            AgentType.RESPONSE,
            AgentType.CLASSIFIER,
            AgentType.RANKER,
            AgentType.RERANKER,
            AgentType.ANY
        ],
        language_model_api='openai',
        image_caption_api='google',
        response_api='openai',
        ranker_api='sbert',
        reranker_api='sbert',
    )
    env = Environment(cfg)
    env.new_chat_session('test')
    res_text = ''
    for line in input_text.splitlines():
        if line.startswith('<|im_start|>user'):
            text = (line.split('<|im_start|>user')[-1]).strip()
            res = env.inference(text)
            res_text += res.text + '\n'
    print(res_text)
    assert res_text == expected_output
#undef NDEBUG
#include<assert.h>
int main(){
    assert (pairs_sum_to_zero({1, 3, 5, 0}) == false);
    assert (pairs_sum_to_zero({1, 3, -2, 1}) == false);
    assert (pairs_sum_to_zero({1, 2, 3, 7}) == false);
    assert (pairs_sum_to_zero({2, 4, -5, 3, 5, 7}) == true);
    assert (pairs_sum_to_zero({1}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 30}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 3, 2, 31}) == true);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 30}) == false);
    assert (pairs_sum_to_zero({-3, 9, -1, 4, 2, 31}) == false);
}
