define dso_local i32 @_Z8multiplyii(i32 %0, i32 %1) local_unnamed_addr #0 {
  %3 = call i32 @llvm.abs.i32(i32 %0, i1 true)
  %4 = urem i32 %3, 10
  %5 = call i32 @llvm.abs.i32(i32 %1, i1 true)
  %6 = urem i32 %5, 10
  %7 = mul nuw nsw i32 %6, %4
  ret i32 %7
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}
