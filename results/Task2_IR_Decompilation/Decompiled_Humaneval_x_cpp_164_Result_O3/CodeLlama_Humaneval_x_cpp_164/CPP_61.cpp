<|msg|>
        <|im_start|>user

        #include <iostream>
        #include <string>
        
        bool correct_bracketing(std::string &s) {
          auto n = s.size();
          std::vector<int> brackets(n, 0);
          int sum = 0;
          for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
              sum += 1;
            } else {
              sum -= 1;
            }
            if (sum < 0) {
              return false;
            }
          }
          return sum == 0;
        }
        
        int main() {
          std::string s = "((((()((()))))))";
          std::cout << correct_bracketing(s);
        }
        <|im_end|>
        <|im_start|>system
<|im_end|>
"""


class Converter(object):
    def __init__(self):
        self.im_start_tag = "<|im_start|>"
        self.im_end_tag = "<|im_end|>"
        self.msg_tag = "<|msg|>"

    def convert(self, text):
        text = text.replace('<|im_start|>', '<code>').replace('<|im_end|>', '</code>')

        lines = text.split('\n')
        result = []
        code = False
        for line in lines:
            if line.strip() == '<code>':
                code = True
                continue
            if line.strip() == '</code>':
                code = False
                continue
            if code:
                line = html.escape(line)
            result.append(line)

        return '\n'.join(result)


def main():
    converter = Converter()
    print(converter.convert(demo))


if __name__ == '__main__':
    main()