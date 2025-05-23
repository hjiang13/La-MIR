<|im_start|>user

       The code to compile the above LLVM IR should be
        ```
#include <cstdio>
#include <string>

bool same_chars(std::string &a, std::string &b)
{
  if (a.length() != b.length())
    return false;

  for (int i = 0; i < a.length(); i++)
    if (a[i] != b[i])
      return false;

  return true;
}

int main()
{
  std::string a = "1234567890";
  std::string b = "1234567890";

  printf("%d", same_chars(a, b));
}
        ```
        Your answer is correct!
        <|im_end|>
        <|im_start|>system
        <|im_end|>
        <|im_start|>user
        <|im_end|>
        <|endoftext|>
        ```
        """

        super(CodexLLVMIRDataset, self).__init__()
        self.type_dict = {
            "system": 0,
            "user": 1,
            "im_start": 2,
            "im_end": 3,
        }

        self.dataset = []

        Xs = []
        X_sizes = []
        X_types = []
        Ys = []
        Y_sizes = []
        Y_types = []

        for x in data:
            x = x.split("<|im_end|>")
            for x_ in x:
                if x_ == "":
                    continue

                x_ = x_.split("<|im_start|>")
                if x_[0] == "":
                    x_ = x_[1:]

                x_ = list(zip(x_[0::2], x_[1::2]))
                x_ = [(self.type_dict[y_type], y) for y_type, y in x_]

                _X = []
                _X_sizes = []
                _X_types = []

                for y_type, y in x_:
                    y = y.strip()
                    y = y.split("\n")
                    y = [y_ for y_ in y if y_ != ""]

                    _X_types.extend([y_type] * len(y))
                    _X_sizes.extend([len(y_ + "\n") for y_ in y])
                    _X.extend([y_ + "\n" for y_ in y])

                _Y = []
                _Y_sizes = []
                _Y_types = []

                for y_type, y in x_:
                    y = y.strip()
                    y = y.split("\n")
                    y = [y_ for y_ in y if y_ != ""]

                    _Y_types.extend([y_type] * len(y))
                    _Y_sizes.extend([len(y_ + "\n") for y_ in y])
                    _Y.extend([y_ + "\n" for y_ in y])

                Xs.append(_X)
                X_sizes.append(_X_sizes)
                X_types.append(_X_types)
                Ys.append(_Y)
                Y_sizes.append(_Y_sizes)
                Y_types.append(_Y_types)

        self.dataset.append(Xs)
        self.dataset.append(X_sizes)
        self.dataset.append(X_types)
        self.dataset.append(Ys)
        self.dataset.append(Y_sizes)
        self.dataset.append(Y_types)

    def __getitem__(self, idx):
        return [torch.as_tensor(self.dataset[i][idx]) for i in range(len(self.dataset))]

    def __len__(self):
        return len(self.dataset[0])