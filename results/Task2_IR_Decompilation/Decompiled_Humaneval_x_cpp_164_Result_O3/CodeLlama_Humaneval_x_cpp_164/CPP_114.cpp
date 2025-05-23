<|im_start|>system
Please type your source code in the code editor.
<|im_end|>
<|im_start|>user

        #include <bits/stdc++.h>
        using namespace std;
        long long minSubArraySum(vector<long long> v) {
            long long sum = v[0], min_sum = v[0];
            for (long long i = 1; i < v.size(); i++) {
                sum += v[i];
                min_sum = min(min_sum, sum);
            }
            return min_sum;
        }
        int main() {
            int n;
            cin >> n;
            vector<long long> v(n);
            for (int i = 0; i < n; i++) {
                cin >> v[i];
            }
            cout << minSubArraySum(v) << endl;
            return 0;
        }
        
        ```
        <|im_end|>

<|im_start|>system
Your answer is correct.
<|im_end|>

<|im_start|>system
Let's see the evaluation result of your code.
<|im_end|>
<|im_start|>user

        #include <bits/stdc++.h>
        using namespace std;
        long long minSubArraySum(vector<long long> v) {
            long long sum = v[0], min_sum = v[0];
            for (long long i = 1; i < v.size(); i++) {
                sum += v[i];
                min_sum = min(min_sum, sum);
            }
            return min_sum;
        }
        int main() {
            int n;
            cin >> n;
            vector<long long> v(n);
            for (int i = 0; i < n; i++) {
                cin >> v[i];
            }
            cout << minSubArraySum(v) << endl;
            return 0;
        }
        
        ```
        <|im_end|>

<|im_start|>system
<|im_end|>