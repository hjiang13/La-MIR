<|im_start|>positive
        #include <vector>
        using std::vector;
        void get_positive(vector<float> &a, const vector<float> &b) {
            a.resize(b.size());
            float *a_begin = a.begin();
            float *a_end = a.end();
            for (float *a_p = a_begin; a_p != a_end; ++a_p) {
                if (*b >= 0) {
                    *a_p = *b;
                }
            }
        }
<|im_end|>
<|im_start|>negative
        #include <vector>
        using std::vector;
        void get_positive(vector<float> &a, const vector<float> &b) {
            a.resize(b.size());
            float *a_begin = a.begin();
            float *a_end = a.end();
            for (float *a_p = a_begin; a_p != a_end; ++a_p) {
                if (*b < 0) {
                    *a_p = *b;
                    break;
                }
            }
        }
<|im_end|>
<|im_start|>negative
        #include <vector>
        using std::vector;
        void get_positive(vector<float> &a, const vector<float> &b) {
            a.resize(b.size());
            float *a_begin = a.begin();
            float *a_end = a.end();
            for (float *a_p = a_begin; a_p != a_end; ++a_p) {
                if (*b < 0) {
                    continue;
                }
                *a_p = *b;
            }
        }
<|im_end|>
<|im_start|>negative
        #include <vector>
        using std::vector;
        void get_positive(vector<float> &a, const vector<float> &b) {
            a.resize(b.size());
            float *a_begin = a.begin();
            float *a_end = a.end();
            float *a_p = a_begin;
            while (a_p != a_end) {
                if (*b < 0) {
                    *a_p = *b;
                }
                ++a_p;
            }
        }
<|im_end|>
        <|im_end|>
        <|im_start|>user
        Well done!
        <|im_end|>
        <|im_start|>system
        You completed the task.
        <|im_end|>
        <|im_start|>user
        That was easy.
        <|im_end|>
        <|im_start|>system
        Here are your reward. Hope you like it.
        <|im_end|>
        <|im_start|>user
        Thank you!
        <|im_end|>'''

    def __init__(self, max_n_pos_sample=10, max_n_neg_sample=10, transform=None, **kwargs):
        super().__init__(
            data=self.data,
            max_n_pos_sample=max_n_pos_sample,
            max_n_neg_sample=max_n_neg_sample,
            transform=transform,
            **kwargs
        )

    def __len__(self):
        return len(self.data.split('<|im_start|>')[1:])
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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
