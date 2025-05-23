int is_bored(const char *str) {
    int count = 0;
    int len = strlen(str);
    int flag = 0;
    int n = 0;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == ' ') {
            count += n;
            n = 0;
        }
        if (c == 'I' && flag) {
            n = 1;
        }
        if (c == '.' || c == '?' || c == '!') {
            flag = 1;
        } else {
            flag = 0;
        }
    }

    return count;
}
