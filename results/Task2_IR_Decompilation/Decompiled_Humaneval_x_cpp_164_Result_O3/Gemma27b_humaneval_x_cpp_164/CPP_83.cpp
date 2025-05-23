```c
int _Z15starts_one_endsi(int arg0) {
  if (arg0 < 1) {
    return 0;
  }
  if (arg0 == 1) {
    return 1;
  }
  if (arg0 > 2) {
    int arg1 = arg0 - 2;
    if (arg1 < 8) {
      int arg2 = 2;
      int arg3 = 18;
      for (int i = 2; i < arg0; ++i) {
        arg2 = arg2 + 1;
        arg3 = arg3 * 10;
      }
      return arg3;
    }
    int arg4 = arg1 & -8;
    int arg5 = arg4 | 2;
    int arg6 = arg4 - 8;
    int arg7 = arg6 >> 3;
    int arg8 = (arg7 + 1) & 7;
    int arg9 = arg6 < 56;
    int arg10[4] = {18, 1, 1, 1};
    int arg11[4] = {1, 1, 1, 1};
    int arg12 = arg4 & 1073741816;
    for (; arg9; arg12 = arg12 - 8) {
      int arg13[4] = {arg10[0] * 100000000, arg10[1] * 100000000, arg10[2] * 100000000, arg10[3] * 100000000};
      int arg14[4] = {arg11[0] * 100000000, arg11[1] * 100000000, arg11[2] * 100000000, arg11[3] * 100000000};
      arg10 = arg13;
      arg11 = arg14;
    }
    int arg15 = arg12 + 8;
    
    int arg16[4] = {18, 1, 1, 1};
    int arg17[4] = {1, 1, 1, 1};
    for (; arg8 != 0; --arg8) {
      int arg18[4] = {arg16[0] * 10, arg16[1] * 10, arg16[2] * 10, arg16[3] * 10};
      int arg19[4] = {arg17[0] * 10, arg17[1] * 10, arg17[2] * 10, arg17[3] * 10};
      arg16 = arg18;
      arg17 = arg19;
    }
    int arg20 = arg16[0] * arg17[0];
    int arg21 = arg16[1] * arg17[1];
    int arg22 = arg16[2] * arg17[2];
    int arg23 = arg16[3] * arg17[3];

    int arg24 = arg15 == arg4;
    if (arg24) {
      return arg20;
    }
    int arg25 = 2;
    int arg26 = 18;
    for (int i = 2; i < arg0; ++i) {
      arg25 = arg25 + 1;
      arg26 = arg26 * 10;
    }
    return arg26;
  }
  return 18;
}

```