<|im_start|>system
        Are you ready?
        <|im_end|>
        <|im_start|>user
        Ok.
        <|im_end|>
        <|im_start|>system
        Here is the output C source code:
        ```
        #include <vector>
        float mean_absolute_deviation(std::vector<float> const& v)
        {
            float sum = 0.0f;
            for (auto const& x : v)
                sum += x;
            float mean = sum / v.size();
            float deviation = 0.0f;
            for (auto const& x : v)
                deviation += std::fabs(x - mean);
            return deviation / v.size();
        }
        ```
        <|im_end|>
        <|im_start|>user
        Wow, it's amazing! Thank you very much!
        <|im_end|>
        <|im_start|>system
        You are welcome!
        <|im_end|>
        '''
        ckpt_path = self.ckpt_path
        if self.device == "cuda":
            ckpt_path = f"{ckpt_path[:-5]}-cuda.pt"
        print("Loading Model...")
        tokenizer = GPT2Tokenizer.from_pretrained(self.tokenizer_path)
        model = GPT2LMHeadModel.from_pretrained(self.model_path)
        device = "cpu"
        if torch.cuda.is_available():
            device = "cuda:0"
        model.to(device)
        model.load_state_dict(torch.load(ckpt_path))
        model.eval()
        print("Model loaded.")

        context_ids = tokenizer.encode(context)
        context_ids = torch.tensor([context_ids], device=device)
        input_index = 0
        while True:
            with torch.no_grad():
                outputs = model(context_ids)
                logits = outputs[0]
                logits = logits[0, -1, :]
                next_token_logits = logits / self.temperature
                filtered_logits = top_k_top_p_filtering(next_token_logits, top_k=self.top_k, top_p=self.top_p)
                if self.do_sample:
                    next_token = torch.multinomial(torch.softmax(filtered_logits, dim=-1), num_samples=1)
                else:
                    next_token = torch.argmax(filtered_logits, dim=-1).unsqueeze(0)
                context_ids = torch.cat([context_ids, next_token.unsqueeze(0)], dim=1)

            input_index += 1
            if input_index % 10 == 0:
                print(f"{input_index} words generated!")

            if "<|im_end|>" in tokenizer.decode(next_token.item()):
                break

        print(tokenizer.decode(context_ids[0]))


if __name__ == "__main__":
    fire.Fire(Interact)
#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0}) - 2.0/3.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0}) - 1.0) < 1e-4);
    assert (abs(mean_absolute_deviation({1.0, 2.0, 3.0, 4.0, 5.0}) - 6.0/5.0) < 1e-4);
}