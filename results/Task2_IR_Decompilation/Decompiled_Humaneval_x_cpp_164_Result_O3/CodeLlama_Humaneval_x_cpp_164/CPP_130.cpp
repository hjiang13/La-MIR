<|im_start|>system
        You are an expert in high-performance computation.
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|im_start|>system
        Congratulations, you've completed the task correctly.
        <|im_end|>
        '''
        out = '''
        #include <vector>
        using namespace std;
        void tri(vector<int> &arr, int n) {
            arr.push_back(1);
            arr.push_back(3);
            int l = arr.size();
            arr.resize(l + 1);
            for (int i = 0; i < n; i++) {
                int t = arr[i];
                int t1 = arr[i + 1];
                arr[i] = t + t1 + 1;
            }
        }
        '''

        self.assertEqual(out.strip(), self.transformer(inp).strip())


if __name__ == '__main__':
    unittest.main()