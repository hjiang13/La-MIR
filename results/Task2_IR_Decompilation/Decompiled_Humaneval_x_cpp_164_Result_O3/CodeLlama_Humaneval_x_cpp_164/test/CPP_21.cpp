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
#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(rescale_to_unit({2.0, 49.9}) , {0.0, 1.0}));
     assert (issame(rescale_to_unit({100.0, 49.9}) ,{1.0, 0.0})); 
     assert (issame(rescale_to_unit({1.0, 2.0, 3.0, 4.0, 5.0}) , {0.0, 0.25, 0.5, 0.75, 1.0}));
    assert (issame(rescale_to_unit({2.0, 1.0, 5.0, 3.0, 4.0}) , {0.25, 0.0, 1.0, 0.5, 0.75}));
     assert (issame(rescale_to_unit({12.0, 11.0, 15.0, 13.0, 14.0}) ,{0.25, 0.0, 1.0, 0.5, 0.75}));
}
