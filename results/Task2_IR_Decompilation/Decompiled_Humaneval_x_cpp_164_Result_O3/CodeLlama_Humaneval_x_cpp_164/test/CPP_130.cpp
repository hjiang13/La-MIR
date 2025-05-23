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
#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
    if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(tri(3) , {1, 3, 2, 8}));
    assert (issame(tri(4) , {1, 3, 2, 8, 3}));
    assert (issame(tri(5) , {1, 3, 2, 8, 3, 15}));
    assert (issame(tri(6) , {1, 3, 2, 8, 3, 15, 4}));
    assert (issame(tri(7) , {1, 3, 2, 8, 3, 15, 4, 24}));
    assert (issame(tri(8) , {1, 3, 2, 8, 3, 15, 4, 24, 5}));
    assert (issame(tri(9) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35}));
    assert (issame(tri(20) , {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11}));
    assert (issame(tri(0) , {1}));
    assert (issame(tri(1) , {1, 3}));
}
