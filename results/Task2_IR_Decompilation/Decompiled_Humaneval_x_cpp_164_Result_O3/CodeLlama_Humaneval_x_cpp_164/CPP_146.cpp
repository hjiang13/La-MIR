<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
<|is_end|>
"""


class TestCodeT5(unittest.TestCase):
    def setUp(self):
        self.code_t5 = CodeT5(
            model=ModelType.MT5,
            is_multilingual=False,
            model_dir="assets/mt5-base",
            max_length=64,
        )

    def test_predict_output(self):
        result = self.code_t5.predict(
            source=source,
            target="c",
        )
        pred = result["pred"]
        self.assertEqual(
            pred,
            """#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int specialFilter(const vector<int> &v) {
    stringstream str;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 10) {
            if ((v[i] % 2) == 1) {
                str << v[i] << " ";
                if (((v[i] / 10) % 2) == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}
""",
        )

    def test_predict_output_with_doctest(self):
        result = self.code_t5.predict(
            source=source,
            target="c",
            doctest=True,
        )
        pred = result["pred"]
        self.assertEqual(
            pred,
            """#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int specialFilter(const vector<int> &v) {
    stringstream str;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 10) {
            if ((v[i] % 2) == 1) {
                str << v[i] << " ";
                if (((v[i] / 10) % 2) == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 62};
    cout << "specialFilter(arr1) : " << specialFilter(arr1) << endl;
    return 0;
}
""",
        )

    def test_batch_prediction(self):
        result = self.code_t5.predict(
            source=source,
            target="c",
            doctest=True,
            batch_size=1,
        )
        pred = result["pred"]
        self.assertEqual(
            pred,
            """#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int specialFilter(const vector<int> &v) {
    stringstream str;
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 10) {
            if ((v[i] % 2) == 1) {
                str << v[i] << " ";
                if (((v[i] / 10) % 2) == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 62};
    cout << "specialFilter(arr1) : " << specialFilter(arr1) << endl;
    return 0;
}
""",
        )

    def test_evaluate(self):
        result = self.code_t5.evaluate(
            target="c",
            doctest=True,
            source=source,
        )
        self.assertTrue(result["correct"])

    def test_code_t5_with_model_dir(self):
        code_t5 = CodeT5(
            model=ModelType.MT5,
            model_dir="assets/mt5-base",
        )
        result = code_t5.evaluate(
            target="c",
            doctest=True,
            source=source,
        )
        self.assertTrue(result["correct"])


if __name__ == "__main__":
    unittest.main()