<|im_start|>user

        CPP_142.cpp
        ```
        #include <vector>
        using namespace std;
        
        int sum_squares(const vector <int> &v) {
            int sum = 0;
            
            for(int i = 0; i < v.size(); i++) {
                sum += v[i] * v[i];
            }
            
            return sum;
        }
        ```
        <|im_end|>
<|endoftext|>