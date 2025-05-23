<|im_start|>user

        class Vector {
        public:
            void sort(){
                size_t n = size();
                for (size_t i=0; i<n-1; ++i) {
                for (size_t j=i+1; j<n; ++j) {
                    if (data()[j] < data()[i]) {
                        std::swap(data()[j], data()[i]);
                   }}}
                }
        private:
            int * _start;
            int * _finish;
            int * _end_of_storage;
        };
        void sort_array(Vector & arr){
            arr.sort();
        }
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user
So how does it work?
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user
I'm not sure how it works. I just used the default "sort" function and it seems to work.
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user
Okay, I found a bug in the code. 
I try to sort my array of 100 elements and it only sorts the first 32 elements.
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user
The default implementation of the sort function I use is a quicksort which is not stable. 
It means that the relative ordering of equal elements is not preserved. 
I tried to use a slower but stable sorting function and it seems to work better.
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user

        class Vector {
        public:
            void sort(){
                std::stable_sort(data(), data() + size());
            }
        private:
            int * _start;
            int * _finish;
            int * _end_of_storage;
        };
        void sort_array(Vector & arr){
            arr.sort();
        }
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user

        Thank you for your help.
        ```
<|im_end|>
<|im_start|>system
<|im_end|>
<|im_start|>user

        You're welcome!
        ```
<|im_end|>
<|im_start|>system
<|im_end|>
"""

def parse_story(story):
    res = []
    for line in story.splitlines():
        line = line.strip()
        if line.startswith("<|im_start|>system"):
            line = line.replace("<|im_start|>system", "###SYSTEM: ")
        elif line.startswith("<|im_start|>user"):
            line = line.replace("<|im_start|>user", "###USER: ")
        elif line.startswith("<|im_end|>"):
            continue
        elif line.startswith("```"):
            # ignore code examples
            line = ""
        else:
            line = line.replace("```", "")
        res.append(line)
    return "\n".join(res)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", help="Path to the source file", required=True)
    parser.add_argument("--target", help="Path to the target file", required=True)
    args = parser.parse_args()

    with open(args.source, "r") as f:
        source_text = f.read()

    with open(args.target, "w") as f:
        parsed_text = parse_story(source_text)
        f.write(parsed_text)


if __name__ == "__main__":
    main()
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
    assert (issame(sort_array({1,5,2,3,4}) , {1, 2, 4, 3, 5}));
    assert (issame(sort_array({-2,-3,-4,-5,-6}) , {-4, -2, -6, -5, -3}));
    assert (issame(sort_array({1,0,2,3,4}) , {0, 1, 2, 4, 3}));
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({2,5,77,4,5,3,5,7,2,3,4}) , {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77}));
    assert (issame(sort_array({3,6,44,12,32,5}) , {32, 3, 5, 6, 12, 44}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
}
