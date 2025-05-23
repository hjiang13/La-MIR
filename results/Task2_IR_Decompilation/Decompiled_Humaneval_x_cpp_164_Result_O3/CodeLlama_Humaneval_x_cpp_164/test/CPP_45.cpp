<|im_start|>system
Please use the standard function name as the entry point, which is "func" in most cases.
<|im_end|>
<|im_start|>user

        Great. Give me your C source code.
        ```
        #include <stdint.h>
        #include <math.h>
        float triangle_area(float,float);
        
        float func(float a, float b) {
          return triangle_area(a,b);
        }
        
        float triangle_area(float a, float b) {
          return 0.5 * a * b;
        }
        ```
        <|im_end|>
<|im_start|>system
Thank you!
<|im_end|>

"""


class Custom(Task):
    def __init__(self, seed=42, max_output_length=1000):
        super().__init__(seed=seed, max_output_length=max_output_length)
        # self.max_output_length = max_output_length

    def get_task_details(self):
        return task.TaskMetadata(
            name="custom_task",
            description="Custom Task",
            keywords=[
                "zero-shot",
                "many-shot",
                "one-shot",
                "open-ended",
            ],
            max_input_length_per_query=1000,
            max_queries=1000,
        )

    def evaluate_model(self, model, max_examples=None, random_seed=None):
        if random_seed is None:
            random_seed = self.seed

        score_data = []

        # NEXT STEP: Iterate through the loop, calling model.generate_text() each time
        #            Add the total scores from each dialogue to score_data
        #            Also store the processed conversation as a string, results,
        #            so that you can print it out later
        # TODO: for each pair of prompts, generate a reply
        for context, completion, _ in [
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need help with my computer.",
                "I can help you with that. What seems to be the problem?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need to schedule an appointment.",
                "I can help you with that. When would you like to make the appointment?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need to make some travel plans.",
                "I can help you with that. Where would you like to go?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need a new phone.",
                "I can help you with that. What kind of phone would you like?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need to make some travel plans.",
                "I can help you with that. Where would you like to go?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need help with my computer.",
                "I can help you with that. What seems to be the problem?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need to schedule an appointment.",
                "I can help you with that. When would you like to make the appointment?",
            ),
            (
                "I am a highly intelligent virtual agent. I can do many things. What can I help you with today?",
                "I need a new phone.",
                "I can help you with that. What kind of phone would you like?",
            ),
        ]:
            context_enc = f"<|im_start|>user\n{context}\n<|im_end|><|im_start|>system\n{completion}\n<|im_end|>"
            completion_enc = "<|im_start|>user"
            score_data.append(
                generate_response(
                    model, context_enc, completion_enc, 3, 20, random_seed, stop_string="<|im_start|>"
                )
            )

        # NEXT STEP: Calculate the average accuracy of the model in the same way
        #            you did in the previous step
        score = sum(score_data) / len(score_data)

        return task.ScoreData(
            {"exact_str_match": score, "f1": score},
            preferred_score="exact_str_match",
            subtask_description="",
            low_score=0.0,
            high_score=1.0,
            number_of_shots=0,
        )
#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(triangle_area(5, 3) - 7.5)<1e-4);
    assert (abs(triangle_area(2, 2) - 2.0)<1e-4);
    assert (abs(triangle_area(10, 8) - 40.0)<1e-4);
}
