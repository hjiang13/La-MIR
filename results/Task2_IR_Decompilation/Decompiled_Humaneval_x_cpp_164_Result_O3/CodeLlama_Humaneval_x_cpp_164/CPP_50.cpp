<|im_end|>
```
The `LLVM` IR code will be printed in the line 3 and 6 after the `<|im_start|>system` and `<|im_start|>user` token.
You can copy and paste the generated IR code into the input window in the [LLVM online demo web compiler](https://llvm.org/demo/).
Then you can click the `compile` button to get the C source code. 
The `compile` button will execute the following command to generate the C source code:
```
opt -S -mem2reg -instnamer -load LLVMSourceGen.so -gen-o
```

### Testing on a custom IR file
1. Put your own `IR` file in the `data/custom_data` folder.
2. Run the following code to generate the `IR` code into the `data/custom_data/output.txt` file:
```
# python main.py --test --ir_file custom
```
3. Run the following code to get the generated C source code from the IR code:
```
# python main.py --test --ir_file custom --c_code
```

## References
**[1]** [A Compiler Approach to Synthesizing LLVM IR Code from Source Code](https://www.computer.org/csdl/proceedings-article/icse/2022/094701a306/1sRsgRgIj5E)  
**[2]** [LLVM IR Tutorial: Going from source code to LLVM IR](https://blog.llvm.org/posts/2021-08-19-llvm-ir-source-code-to-ir-tutorial/)  
**[3]** [LLVM Essentials: Getting Started with LLVM](https://www.amazon.com/LLVM-Essentials-Getting-Started-Dietrich/dp/1784391252)  
**[4]** [LLVM Compiler Infrastructure](https://llvm.org/)  
**[5]** [LLVM 12.0.1 Documentation](https://llvm.org/docs/index.html)  
**[6]** [Github: llvm/llvm-project](https://github.com/llvm/llvm-project)  
**[7]** [Github: xiaoheng2019/synthesize-llvm-ir-from-source-code](https://github.com/xiaoheng2019/synthesize-llvm-ir-from-source-code)  
**[8]** [Github: microsoft/CodeXGLUE/Code-Code/Clone-detection-LLVM](https://github.com/microsoft/CodeXGLUE/tree/main/Code-Code/Clone-detection-LLVM)  
**[9]** [Github: llvm/llvm-project-20170507](https://github.com/llvm/llvm-project-20170507)  
**[10]** [Github: LLVM-IR-Tutorial](https://github.com/banach-space/LLVM-IR-Tutorial)