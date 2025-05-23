<|endoftext|>
"""
    # print(LLVM_IR_CODE)
    print(hf_pipeline(LLVM_IR_CODE))
    print(hf_pipeline(LLVM_IR_CODE) == "return 0;")


if __name__ == "__main__":
    main()