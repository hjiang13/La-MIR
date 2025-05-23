<|im_start|>user
        ```
        void rescale_to_unit(std::vector<float> *a, std::vector<float> *b) {
            float new_min = -1E5;
            float new_max = 1E5;

            float old_min = *a->begin();
            float old_max = *a->begin();

            for (float iter : *a) {
                if (iter < old_min) old_min = iter;
                if (iter > old_max) old_max = iter;
            }

            float old_range = old_max - old_min;
            if (old_range == 0) return;

            for (int i = 0; i < a->size(); i++) {
                (*a)[i] = (((*a)[i] - old_min) / old_range) * (new_max - new_min) + new_min;
            }
        }
        ```
        <|im_end|>
        <|im_start|>system
        Is there anything else I can help you with?
        <|im_end|>
        <|im_start|>user
        No. Thanks!
        <|im_end|>
        <|im_start|>system
        OK. Have a nice day!
        <|im_end|>