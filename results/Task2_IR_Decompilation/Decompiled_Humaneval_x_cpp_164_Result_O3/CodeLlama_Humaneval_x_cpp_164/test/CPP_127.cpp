<|endoftext|>"""

# 🤗 Transformers library
import transformers
import torch

# Additional imports
import os
import random

# Import CUDA devices
os.environ["CUDA_VISIBLE_DEVICES"]="0,1"
device_ids = [int(i) for i in os.environ["CUDA_VISIBLE_DEVICES"].split(",")]
print(f"{len(device_ids)} GPUs are available")

# Initialize the model
model = transformers.GPT2LMHeadModel.from_pretrained("gpt2")
tokenizer = transformers.GPT2Tokenizer.from_pretrained("gpt2")

# Move to GPUs
model = model.to("cuda:0")
tokenizer = tokenizer.to("cuda:0")

# Make sure everything is on the same device
device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
n_gpu = torch.cuda.device_count()

# Parallelize the model
if n_gpu > 1:
    model = torch.nn.DataParallel(model, device_ids=device_ids)

# Set the model in evaluation mode to desactivate the DropOut modules
# This is IMPORTANT to have reproductible results during evaluation!
model.eval()

# If there is a GPU available, put it on the GPU:
if torch.cuda.is_available():
    input_ids = input_ids.to("cuda")
    attention_mask = attention_mask.to("cuda")

# Create the past variable
past = None

# For sampling renormalizing the softmax
softmax_temp = 0.5

# Initialize the tokens as a random token
token_input = tokenizer.encode(prompt, return_tensors="pt")

# Initialize the tokens as a random token
generated_tokens = torch.tensor(token_input.size()[0]*[token_input.size()[1]-1]).unsqueeze(0).to("cuda")

# Initialize the past variable
past = None

# For sampling renormalizing the softmax
softmax_temp = 0.7

for iter in range(iterations):
    # Get the input tokens
    input_ids = generated_tokens
    # Add a batch dimension
    input_ids = input_ids.unsqueeze(0).to("cuda")

    # Get the attention mask
    attention_mask = torch.ones(input_ids.shape).to("cuda")

    # Forward pass to get the output
    with torch.no_grad():
        outputs = model(input_ids, attention_mask=attention_mask, past=past)

    # Get the last hidden state
    next_token_logits = outputs[0][:, -1, :] / softmax_temp

    # Get the last past state
    past = outputs[1]

    # Get the next token
    next_token = torch.multinomial(torch.softmax(next_token_logits, dim=1), num_samples=1)

    # Add it to the generated tokens
    generated_tokens = torch.cat([generated_tokens, next_token.unsqueeze(0)], dim=1)

# Remove the batch dimension
generated_tokens = generated_tokens.squeeze(0)

# Convert the tokens to text
generated_text = tokenizer.decode(generated_tokens)

# Print the generated text
print(prompt + generated_text)
#undef NDEBUG
#include<assert.h>
int main(){
    assert (intersection({1, 2}, {2, 3}) == "NO");
    assert (intersection({-1, 1}, {0, 4}) == "NO");
    assert (intersection({-3, -1}, {-5, 5}) == "YES");
    assert (intersection({-2, 2}, {-4, 0}) == "YES");
    assert (intersection({-11, 2}, {-1, -1}) == "NO");
    assert (intersection({1, 2}, {3, 5}) == "NO");
    assert (intersection({1, 2}, {1, 2}) == "NO");
    assert (intersection({-2, -2}, {-3, -2}) == "NO");
}
