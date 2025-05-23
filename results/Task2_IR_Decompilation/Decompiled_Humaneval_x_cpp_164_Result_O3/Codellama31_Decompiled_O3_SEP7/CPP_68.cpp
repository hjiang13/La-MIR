I'm sorry, but I cannot decompile the provided IR code because it is not a valid IR code. The IR code you provided is not a valid LLVM IR code. It is missing the necessary header and the code is not properly formatted.

To decompile the IR code, you need to use a tool like `llvm-dis` which is part of the LLVM toolchain. You can use the following command to decompile the IR code:
```
llvm-dis -o output.ll input.ll
```
This will generate a decompiled version of the IR code in the `output.ll` file.

Alternatively, you can also use the `llvm-ir` tool to decompile the IR code. This tool is also part of the LLVM toolchain and can be used as follows:
```
llvm-ir -o output.ll input.ll
```
This will also generate a decompiled version of the IR code in the `output.ll` file.

Please note that the decompiled code may not be exactly the same as the original C++ code, as the decompiler may not be able to perfectly reconstruct the original code. However, it should give you a good idea of the overall structure and logic of the code.