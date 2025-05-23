<|im_start|>system
Okay, here is my output.
<|im_end|>
<|im_start|>user

        #include <stdlib.h>
        #include <stdio.h>
        #include <stdint.h>
        
        int main(int argc, char** argv) {
        int *arr = calloc(100, sizeof(int));
        int sum = 0;
        for (int i = 0; i < 100; i++) {
          arr[i] = i;
          sum += arr[i];
        }
        printf("sum=%d", sum);
        }
<|im_end|>
<|im_start|>system
Great! Here is the output.
<|im_end|>
<|im_start|>system
sum=4950
<|im_end|>
        """
        return example

    def construct_requests(self, doc, ctx):
        """Handles initializing the task.

        Returns:
            dictionary of requests
        """
        llvm_ir = doc["llvm_ir"]
        llvm_ir = llvm_ir.replace("<|im_start|>", "").replace("<|im_end|>", "")
        llvm_ir = llvm_ir.replace("<|im_start|>user", "").replace("<|im_end|>", "")
        llvm_ir = llvm_ir.replace("<|im_start|>system", "").replace("<|im_end|>", "")
        llvm_ir = llvm_ir.replace("```", "")
        llvm_ir = llvm_ir.strip()
        llvm_ir = llvm_ir[:1000]

        return [{"llvm_ir": llvm_ir}]

    def process_results(self, doc, results):
        """Take the result of the event and gets the value

        Args:
            doc: The document as returned from the task
            results: The result of the requests

        Returns:
            Nothing
        """
        if results[0] == "":
            results[0] = "Error: No output."

        if "stderr" in results[0]:
            results[0] = "Error: Compilation failed."

        if "error:" in results[0]:
            results[0] = "Error: Compilation failed."

        if "warning:" in results[0]:
            results[0] = "Error: Compilation failed."

        if "note:" in results[0]:
            results[0] = "Error: Compilation failed."

        if "fatal:" in results[0]:
            results[0] = "Error: Compilation failed."

        results[0] = results[0].replace("```", "")
        results[0] = results[0].strip()
        results[0] = results[0] + "\n"

        if len(results[0]) > 512:
            results[0] = "Error: Output too long."

        if results[0] == "":
            results[0] = "Error: No output."

        doc["output"] = results[0]

        return