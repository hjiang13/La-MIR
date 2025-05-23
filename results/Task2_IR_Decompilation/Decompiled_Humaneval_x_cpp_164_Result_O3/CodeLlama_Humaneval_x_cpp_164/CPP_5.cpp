<|im_start|>user
        ```
        void intersperse(std::vector<int> &v, std::vector<int> &result, int sep) {
          for (auto it = v.cbegin(); it != v.cend(); it++) {
            result.push_back(*it);
            result.push_back(sep);
          }
        }
        ```
        <|im_end|>
        <|im_start|>system
        Code generated successfully.
        <|im_end|>
        '''

        self.system.add_content(input_text)
        self.assertEqual(input_text, self.system.content)
        self.system.add_content(output_text)
        self.assertEqual(input_text + output_text, self.system.content)
        self.system.clear_content()
        self.assertEqual('', self.system.content)


if __name__ == '__main__':
    unittest.main()