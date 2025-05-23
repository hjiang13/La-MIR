define dso_local float @_Z11max_elementSt6vectorIfSaIfEE(%"class.std::vector"* %0) #0 {
  %2 = alloca float, align 4
  %3 = alloca i32, align 4
  store float -1.000000e+04, float* %2, align 4
  store i32 0, i32* %3, align 4
  br label %4

4:                                                ; preds = %22, %1
  %5 = load i32, i32* %3, align 4
  %6 = sext i32 %5 to i64
  %7 = call i64 @_ZNKSt6vectorIfSaIfEE4sizeEv(%"class.std::vector"* nonnull align 8 dereferenceable(24) %0) #1
  %8 = icmp ult i64 %6, %7
  br i1 %8, label %9, label %25

9:                                                ; preds = %4
  %10 = load float, float* %2, align 4
  %11 = load i32, i32* %3, align 4
  %12 = sext i32 %11 to i64
  %13 = call nonnull align 4 dereferenceable(4) float* @_ZNSt6vectorIfSaIfEEixEm(%"class.std::vector"* nonnull align 8 dereferenceable(24) %0, i64 %12) #1
  %14 = load float, float* %13, align 4
  %15 = fcmp olt float %10, %14
  br i1 %15, label %16, label %21

16:                                               ; preds = %9
  %17 = load i32, i32* %3, align 4
  %18 = sext i32 %17 to i64
  %19 = call nonnull align 4 dereferenceable(4) float* @_ZNSt6vectorIfSaIfEEixEm(%"class.std::vector"* nonnull align 8 dereferenceable(24) %0, i64 %18) #1
  %20 = load float, float* %19, align 4
  store float %20, float* %2, align 4
  br label %21

21:                                               ; preds = %16, %9
  br label %22

22:                                               ; preds = %21
  %23 = load i32, i32* %3, align 4
  %24 = add nsw i32 %23, 1
  store i32 %24, i32* %3, align 4
  br label %4, !llvm.loop !4

25:                                               ; preds = %4
  %26 = load float, float* %2, align 4
  ret float %26
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
