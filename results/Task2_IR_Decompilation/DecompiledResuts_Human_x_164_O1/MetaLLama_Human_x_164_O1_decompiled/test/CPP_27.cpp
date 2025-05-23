#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void filp_case(char *str) {
    char *s = str;
    char *p;
    char *q;
    char *r;
    char c;
    int len;
    int i;

    len = strlen(s);
    p = (char *)malloc(len + 1);
    q = (char *)malloc(len + 1);
    r = (char *)malloc(len + 1);

    for (i = 0; i < len; i++) {
        c = s[i];
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        p[i] = c;
    }
    p[len] = '\0';

    for (i = 0; i < len; i++) {
        q[i] = p[i];
    }
    q[len] = '\0';

    for (i = 0; i < len; i++) {
        r[i] = q[i];
    }
    r[len] = '\0';

    free(p);
    free(q);
    free(r);
}

int main() {
    char *str = "Hello, World!";
    filp_case(str);
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (filp_case("") == "");
    assert (filp_case("Hello!") == "hELLO!");
    assert (filp_case("These violent delights have violent ends") == "tHESE VIOLENT DELIGHTS HAVE VIOLENT ENDS");
}
