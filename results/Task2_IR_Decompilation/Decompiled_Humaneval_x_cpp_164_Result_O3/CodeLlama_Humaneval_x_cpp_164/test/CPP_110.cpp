<|im_start|>user
        What is the C source code format?
        <|im_end|>

        <|im_start|>system
        ```
        #include <bits/stdc++.h>

        using namespace std;

        int main() {
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i = 0; i < n; i++) {
                cin >> v[i];
            }
            random_shuffle(v.begin(), v.end());
            for(int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
            return 0;
        }
        ```
        <|im_end|>

        <|im_start|>user

        <|im_end|>

        <|im_start|>system
        Your input is not a valid C source code.
        <|im_end|>
        """,
    ],
    [
        "Simple code output after `User` input",
        """
        <|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>

        <|im_start|>user
        What is the C source code format?
        <|im_end|>

        <|im_start|>system
        ```
        #include <bits/stdc++.h>

        using namespace std;

        int main() {
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i = 0; i < n; i++) {
                cin >> v[i];
            }
            random_shuffle(v.begin(), v.end());
            for(int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
            return 0;
        }
        ```
        <|im_end|>

        <|im_start|>user

        <|im_end|>

        <|im_start|>system
        Your input is not a valid C source code.
        <|im_end|>
        """,
        [
            "C",
            "C code",
            "C Lang",
            "C lang",
            "C source code",
            "C Source Code",
        ],
        """
        <|im_start|>system
        Your task is to generate a C source code format without any extra explanation or comments from the IR code.
        <|im_end|>

        <|im_start|>user
        What is the C source code format?
        <|im_end|>

        <|im_start|>system
        ```
        #include <bits/stdc++.h>

        using namespace std;

        int main() {
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i = 0; i < n; i++) {
                cin >> v[i];
            }
            random_shuffle(v.begin(), v.end());
            for(int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
            return 0;
        }
        ```
        <|im_end|>

        <|im_start|>user
        C
        <|im_end|>

        <|im_start|>system
        Your input is not a valid C source code.
        <|im_end|>
        """,
    ],
]


@pytest.mark.parametrize("description,input_text,expected_output", TEST_DATA)
def test_function(description, input_text, expected_output):
    normalize_output = inj.translate(input_text)
    print("-" * 50)
    print(normalize_output)
    print("-" * 50)
    assert normalize_output == expected_output
#undef NDEBUG
#include<assert.h>
int main(){
    assert (exchange({1, 2, 3, 4}, {1, 2, 3, 4}) == "YES");
    assert (exchange({1, 2, 3, 4}, {1, 5, 3, 4}) == "NO");
    assert (exchange({1, 2, 3, 4}, {2, 1, 4, 3}) == "YES" );
    assert (exchange({5, 7, 3}, {2, 6, 4}) == "YES");
    assert (exchange({5, 7, 3}, {2, 6, 3}) == "NO" );
    assert (exchange({3, 2, 6, 1, 8, 9}, {3, 5, 5, 1, 1, 1}) == "NO");
    assert (exchange({100, 200}, {200, 200}) == "YES");
}
