IR code:

; ModuleID = '../../Human_xBenchmarks_164/CPP_31/CPP_31.cpp'
source_filename = "../../Human_xBenchmarks_164/CPP_31/CPP_31.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: mustprogress noinline nounwind uwtable
define dso_local zeroext i1 @_Z8is_primex(i64 %0) #0 {
  %2 = alloca i1, align 1
  %3 = alloca i64, align 8
  %4 = alloca i64, align 8
  store i64 %0, i64* %3, align 8
  %5 = load i64, i64* %3, align 8
  %6 = icmp slt i64 %5, 2
  br i1 %6, label %7, label %8

7:                                                ; preds = %1
  store i1 false, i1* %2, align 1
  br label %26

8:                                                ; preds = %1
  store i64 2, i64* %4, align 8
  br label %9

9:                                                ; preds = %22, %8
  %10 = load i64, i64* %4, align 8
  %11 = load i64, i64* %4, align 8
  %12 = mul nsw i64 %10, %11
  %13 = load i64, i64* %3, align 8
  %14 = icmp sle i64 %12, %13
  br i1 %14, label %15, label %25

15:                                               ; preds = %9
  %16 = load i64, i64* %3, align 8
  %17 = load i64, i64* %4, align 8
  %18 = srem i64 %16, %17
  %19 = icmp eq i64 %18, 0
  br i1 %19, label %20, label %21

20:                                               ; preds = %15
  store i1 false, i1* %2, align 1
  br label %26

21:                                               ; preds = %15
  br label %22

22:                                               ; preds = %21
  %23 = load i64, i64* %4, align 8
  %24 = add nsw i64 %23, 1
  store i64 %24, i64* %4, align 8
  br label %9, !llvm.loop !4

25:                                               ; preds = %9
  store i1 true, i1* %2, align 1
  br label %26

26:                                               ; preds = %25, %20, %7
  %27 = load i1, i1* %2, align 1
  ret i1 %27
}

attributes #0 = { mustprogress noinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"uwtable", i32 1}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{!"clang version 13.0.0 (https://github.com/llvm/llvm-project.git d7b669b3a30345cfcdb2fde2af6f48aa4b94845d)"}
!4 = distinct !{!4, !5}
!5 = !{!"llvm.loop.mustprogress"}

Decompiled C++ source code:

#include<stdio.h>
#include<string>
using namespace std;
bool is_prime(int n){

    if (n<2) return false;
    for (int i=2;i<n;i++)
    {
        if (n%i==0) return false;
    }
    return true;
}


Note: The decompiled code may not be exactly the same as the original source code due to the limitations of the decompilation process.