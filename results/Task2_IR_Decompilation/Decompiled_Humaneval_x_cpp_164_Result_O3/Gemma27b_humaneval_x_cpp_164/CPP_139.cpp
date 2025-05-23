```c
long long int special_factoriali(int);

long long int special_factoriali(int a1) {
  if (a1 < 1) {
    return 1LL;
  }
  int a2 = a1 + 1;
  long long int a3 = (long long int)a2;
  long long int a4 = a3 - 1LL;
  long long int a5 = a3 - 2LL;
  long long int a6 = a4 & 7LL;
  if (a5 < 7LL) {
    long long int a7 = 1LL;
    long long int a8 = 1LL;
    long long int a9 = 1LL;
    long long int a10 = 1LL;
    if (a6 == 0LL) {
      return a7;
    } else {
      long long int a11 = a7;
      long long int a12 = a8;
      long long int a13 = a9;
      long long int a14 = a10;
      long long int a15 = a6;
      do {
        long long int a16 = a13 * a11;
        long long int a17 = a16 * a12;
        long long int a18 = a11 + 1LL;
        long long int a19 = a15 - 1LL;
        if (a19 == 0LL) {
          return a17;
        }
        a11 = a18;
        a12 = a17;
        a13 = a16;
        a14 = a19;
        a15 = a19;
      } while (1);
    }
  } else {
    long long int a20 = 1LL;
    long long int a21 = 1LL;
    long long int a22 = 1LL;
    long long int a23 = a4 & -8LL;
    long long int a24 = a20;
    long long int a25 = a21;
    long long int a26 = a22;
    long long int a27 = a23;
    do {
      long long int a28 = a26 * a24;
      long long int a29 = a28 * a25;
      long long int a30 = a24 + 1LL;
      long long int a31 = a28 * a30;
      long long int a32 = a31 * a29;
      long long int a33 = a24 + 2LL;
      long long int a34 = a31 * a33;
      long long int a35 = a34 * a32;
      long long int a36 = a24 + 3LL;
      long long int a37 = a34 * a36;
      long long int a38 = a37 * a35;
      long long int a39 = a24 + 4LL;
      long long int a40 = a37 * a39;
      long long int a41 = a40 * a38;
      long long int a42 = a24 + 5LL;
      long long int a43 = a40 * a42;
      long long int a44 = a43 * a41;
      long long int a45 = a24 + 6LL;
      long long int a46 = a43 * a45;
      long long int a47 = a46 * a44;
      long long int a48 = a24 + 7LL;
      long long int a49 = a46 * a48;
      long long int a50 = a49 * a47;
      long long int a51 = a24 + 8LL;
      a24 = a51;
      a25 = a50;
      a26 = a49;
      a27 = a27 - 8LL;
      if (a27 == 0LL) {
        break;
      }
      
    } while (1);
  }
}
```