IR Code:

; ModuleID = '../../Human_xBenchmarks_164/CPP_60/CPP_60.cpp'
source_filename = "../../Human_xBenchmarks_164/CPP_60/CPP_60.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn
define dso_local i32 @_Z8sum_to_ni(i32 %0) local_unnamed_addr #0 {
  %2 = add nsw i32 %0, 1
  %3 = mul nsw i32 %2, %0
  %4 = sdiv i32 %3, 2
  ret i32 %4
}

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"uwtable", i32 1}
!2 = !{!"clang version 13.0.0 (https://github.com/llvm/llvm-project.git d7b669b3a30345cfcdb2fde2af6f48aa4b94845d)"}

Decompiled C++ source code:

#include<stdio.h>

int sum_to_n(int n){
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

Explanation:
The provided IR code defines a function named "_Z8sum_to_ni" which takes an integer argument "n" and returns an integer value. The function calculates the sum of all integers from 1 to "n" and returns the result.

The decompiled C++ source code defines a function named "sum_to_n" with the same functionality as the IR code. The function takes an integer argument "n" and returns an integer value. The function calculates the sum of all integers from 1 to "n" and returns the result.

The decompiled C++ source code is equivalent to the IR code, and it preserves the program logic as closely as possible.