<|im_start|>system
The following is the IR code input:
```
define dso_local i32 @_Z6squarei(i32 %0) local_unnamed_addr #0 {
  %2 = mul nsw i32 %0, %0
  ret i32 %2
}

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" } ```
```
<|im_end|>
<|im_end|>"""


class TestCase(unittest.TestCase):
    def test_clean(self):
        self.assertEqual(clean(test, "system"), "You are an expert in high-performance computation.")
        self.assertEqual(
            clean(test, "user"),
            "You are an expert in high-performance computation. I will provide you with LLVM IR (Intermediate Representation) code, which is a low-level, platform-independent representation of a program. Here is the IR code input: ``` b'; ModuleID = '../../Human_xBenchmarks_164/CPP_41/CPP_41.cpp' source_filename = '../../Human_xBenchmarks_164/CPP_41/CPP_41.cpp' target datalayout = 'e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128' target triple = 'x86_64-unknown-linux-gnu' define dso_local i32 @_Z18car_race_collisioni(i32 %0) local_unnamed_addr #0 { %2 = mul nsw i32 %0, %0 ret i32 %2 } attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn 'frame-pointer'='none' 'min-legal-vector-width'='0' 'no-trapping-math'='true' 'stack-protector-buffer-size'='8' 'target-cpu'='x86-64' 'target-features'='+cx8,+fxsr,+mmx,+sse,+sse2,+x87' 'tune-cpu'='generic' } !llvm.module.flags = !{!0, !1} !llvm.ident = !{!2} !0 = !{i32 1, !'wchar_size', i32 4} !1 = !{i32 7, !'uwtable', i32 1} !2 = !{!'clang version 13.0.0 (https://github.com/llvm/llvm-project.git d7b669b3a30345cfcdb2fde2af6f48aa4b94845d)'}``` Your task is to generate a C source code format without any extra explanation or comments from the IR code.",
        )
        self.assertEqual(
            clean(test, "user"),
            "You are an expert in high-performance computation. I will provide you with LLVM IR (Intermediate Representation) code, which is a low-level, platform-independent representation of a program. Here is the IR code input: ``` b'; ModuleID = '../../Human_xBenchmarks_164/CPP_41/CPP_41.cpp' source_filename = '../../Human_xBenchmarks_164/CPP_41/CPP_41.cpp' target datalayout = 'e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128' target triple = 'x86_64-unknown-linux-gnu' define dso_local i32 @_Z18car_race_collisioni(i32 %0) local_unnamed_addr #0 { %2 = mul nsw i32 %0, %0 ret i32 %2 } attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn 'frame-pointer'='none' 'min-legal-vector-width'='0' 'no-trapping-math'='true' 'stack-protector-buffer-size'='8' 'target-cpu'='x86-64' 'target-features'='+cx8,+fxsr,+mmx,+sse,+sse2,+x87' 'tune-cpu'='generic' } !llvm.module.flags = !{!0, !1} !llvm.ident = !{!2} !0 = !{i32 1, !'wchar_size', i32 4} !1 = !{i32 7, !'uwtable', i32 1} !2 = !{!'clang version 13.0.0 (https://github.com/llvm/llvm-project.git d7b669b3a30345cfcdb2fde2af6f48aa4b94845d)'}``` Your task is to generate a C source code format without any extra explanation or comments from the IR code.",
        )


if __name__ == "__main__":
    unittest.main()