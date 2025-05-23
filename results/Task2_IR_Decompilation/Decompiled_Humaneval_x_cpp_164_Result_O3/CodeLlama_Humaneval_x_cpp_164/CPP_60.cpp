<|im_start|>system

You have the following resources available:
- All the human knowledge stored in the internet (You can access it using Google)
- The following C++ code snippet that will help you figure how to translate the IR code to C source code:
```C++
#include <iostream>
using namespace std;

char* read(char *str) {
    if (str == NULL)
        return NULL;
    return str;
}

/* The function you are working on */
int sum_to_n(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    cin >> n;
    cout << sum_to_n(n);
    return 0;
}
```
<|im_end|>
<|im_start|>user

        Here is the IR code input:
        ```
        b'; ModuleID = \'../../Human_xBenchmarks_164/CPP_60/CPP_60.cpp\'\nsource_filename = "../../Human_xBenchmarks_164/CPP_60/CPP_60.cpp"\ntarget datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"\ntarget triple = "x86_64-unknown-linux-gnu"\n\n; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn\ndefine dso_local i32 @_Z8sum_to_ni(i32 %0) local_unnamed_addr #0 {\n  %2 = add nsw i32 %0, 1\n  %3 = mul nsw i32 %2, %0\n  %4 = sdiv i32 %3, 2\n  ret i32 %4\n}\n\nattributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }\n\n!llvm.module.flags = !{!0, !1}\n!llvm.ident = !{!2}\n\n!0 = !{i32 1, !"wchar_size", i32 4}\n!1 = !{i32 7, !"uwtable", i32 1}\n!2 = !{!"clang version 13.0.0 (https://github.com/llvm/llvm-project.git d7b669b3a30345cfcdb2fde2af6f48aa4b94845d)"}\n'
        ```
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        
        Solution:
        ```C++
        #include <iostream>
        using namespace std;

        char* read(char *str) {
            if (str == NULL)
                return NULL;
            return str;
        }

        /* The function you are working on */
        int sum_to_n(int n) {
            return (n * (n + 1)) / 2;
        }

        int main() {
            int n;
            cin >> n;
            cout << sum_to_n(n);
            return 0;
        }
        ```
<|im_end|>