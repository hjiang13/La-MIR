<|im_start|>
        You are an expert in high-performance computation.
        <|im_end|>
        
        <|input_start|>
        
        <|input_end|>
        </code>
        </details>
        
        <details>
        <summary><strong>Solution (click to expand)</strong></summary>
        
        <code>
        #include <bits/stdc++.h>
        using namespace std;
        const int mod = 1e9 + 7;
        
        int main()
        {
            // 2
            // 1 2 4 1
            // 3 2 2 1
            // 3 1 1 2
            // 3 2 4 4
        
            int n;
            cin >> n;
            vector<vector<int>> m(n, vector<int>(4));
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    cin >> m[i][j];
                }
            }
        
            vector<vector<int>> dp(n, vector<int>(4));
        
            dp[0][0] = m[0][0];
            dp[0][1] = max(m[0][1], dp[0][0] + m[0][1]);
            dp[0][2] = max(m[0][2], dp[0][0] + m[0][2]);
            dp[0][3] = max(m[0][3], dp[0][0] + m[0][3]);
        
            for(int i = 1; i < n; i++)
            {
                dp[i][0] = max(m[i][0], dp[i-1][0] + m[i][0]);
                dp[i][1] = max({m[i][1], dp[i-1][1] + m[i][1], dp[i-1][0] + m[i][1]});
                dp[i][2] = max({m[i][2], dp[i-1][2] + m[i][2], dp[i-1][0] + m[i][2]});
                dp[i][3] = max({m[i][3], dp[i-1][3] + m[i][3], dp[i-1][0] + m[i][3]});
            }
        
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    ans = max(ans, dp[i][j]);
                }
            }
            cout << ans;
        
            return 0;
        }
        </code>
        </details>
        """
        return text

    def get_task_comments(self):
        """
        Returns comments relevant to the task (e.g. clarifications about the prompt)
        """
        return """
        This task is to test your knowledge of LLVM IR code. Given the LLVM IR code, write a C++ program that would generate the exact same code.
        """
#undef NDEBUG
#include<assert.h>
bool issame(vector<string> a,vector<string>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(filter_by_substring({}, "john"),{}));
     assert (issame(filter_by_substring({"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"}, "xxx"), {"xxx", "xxxAAA", "xxx"}));
    assert (issame(filter_by_substring({"xxx", "asd", "aaaxxy", "john doe", "xxxAAA", "xxx"}, "xx"),{"xxx", "aaaxxy", "xxxAAA", "xxx"}));
     assert (issame(filter_by_substring({"grunt", "trumpet", "prune", "gruesome"}, "run") ,{"grunt", "prune"}));
}
