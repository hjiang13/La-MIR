<|im_start|>human
        Sounds easy. Let me try.
        <|im_end|>
        <|im_start|>system
        ```
        void f(std::vector<int> * a, int b) {
          if (b < 1) {
            memset(a, 0, 24);
          } else {
            int * c = a->vector_impl_data;
            int * d = a->vector_impl_data - 1;
            int * e = a->vector_impl_data - 2;
            if (d + 1 == c) {
              c[-1] = b * b;
              a->vector_impl_data = c;
            } else {
              long long f = (long long) ((char *) c - (char *) e);
              long long g = f >> 2;
              long long h = (f == -1) ? 1 : g;
              long long i = h + g;
              long long j = i + g;
              long long k = j < g;
              long long l = (k || j > 2305843009213693951) ? 2305843009213693951 : j;
              if (l == 0) {
                c = 0;
              } else {
                if (f == 0) {
                  c = (int *) malloc(l << 2);
                } else {
                  c = (int *) malloc(l << 2);
                  memmove(c, e, f);
                }
              }
              c[h] = b * b;
              a->vector_impl_data = (c + h + 1);
              a->vector_impl_data[-1] = c + l;
            }
          }
        }
        ```
        <|im_end|>
        <|im_start|>user
        Wow! It works! Thank you!
        <|im_end|>
        <|im_start|>system
        You are welcome!
        <|im_end|>
        '''

        self.add_text(text)

        self.add_text('<|im_start|>system')
        self.add_text('<|im_end|>')
        self.add_text('<|im_start|>user')
        self.add_text('<|im_end|>')


if __name__ == '__main__':

    print('DISPLAY', os.getenv('DISPLAY'))

    app = QApplication([])
    ex = App()
    sys.exit(app.exec_())