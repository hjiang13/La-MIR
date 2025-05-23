"""
        )

        self.assertEqual(len(outputs), 3)
        self.assertTrue(outputs[0]["is_completed"])
        self.assertEqual(
            outputs[0]["completed_solutions"][0]["code"],
            """
        #include <iostream>
        #include <string>
        #include <iomanip>
        #include <bitset>
        #include <sstream>
        #include <openssl/md5.h>

        using namespace std;

        void string_to_md5(string& plain_text, string& encrypted_text) {
            unsigned char digest[MD5_DIGEST_LENGTH];
            char mdString[33];

            MD5((const unsigned char*) plain_text.c_str(), strlen(plain_text.c_str()), (unsigned char*) &digest);

            for (int i = 0; i < 16; i++) {
                sprintf(&mdString[i*2], "%02x", (unsigned int) digest[i]);
            }

            encrypted_text = mdString;
        }


        int main(int argc, char** argv) {
            string plain_text = "Hello World!";
            string encrypted_text = "";

            string_to_md5(plain_text, encrypted_text);

            cout << "plain text: " << plain_text << "\\n";
            cout << "encrypted text: " << encrypted_text << "\\n";
        }
        """
        )

    def test_text_to_text_generation_with_multiple_prompts(self):
        outputs = generate_text(
            [
                "Question: What is the meaning of life?",
                "Answer: To be happy.",
                "Question: What is the meaning of life?",
                "Answer:",
                "Question: What is the meaning of life?",
                "Answer: To be happy.",
            ],
            max_length=100
        )
        self.assertEqual(len(outputs), 3)
        self.assertTrue(outputs[0]["is_completed"])
        self.assertEqual(outputs[0]["completed_solutions"][0]["text"], " To be happy.")

        self.assertTrue(outputs[1]["is_completed"])
        self.assertEqual(outputs[1]["completed_solutions"][0]["text"], " The meaning of life is happiness. To be happy.")

        self.assertTrue(outputs[2]["is_completed"])
        self.assertEqual(outputs[2]["completed_solutions"][0]["text"], " To be happy. The meaning of life is happiness. To be happy.")


if __name__ == '__main__':
    unittest.main()