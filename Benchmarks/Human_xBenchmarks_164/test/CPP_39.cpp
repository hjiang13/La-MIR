/*
prime_fib returns n-th number that is a Fibonacci number and it's also prime.
>>> prime_fib(1)
2
>>> prime_fib(2)
3
>>> prime_fib(3)
5
>>> prime_fib(4)
13
>>> prime_fib(5)
89
*/
#include<stdio.h>
using namespace std;
int prime_fib(int n){

    int f1,f2,m;
    f1=1;f2=2;
    int count=0;
    while (count<n)
    {
        f1=f1+f2;
        m=f1;f1=f2;f2=m;
        bool isprime=true;
        for (int w=2;w*w<=f1;w++)
            if (f1%w==0)
            {
             isprime=false; break;
            }
        if (isprime) count+=1;
        if (count==n) return f1;
    }

}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_fib(1) == 2);
    assert (prime_fib(2) == 3);
    assert (prime_fib(3) == 5);
    assert (prime_fib(4) == 13);
    assert (prime_fib(5) == 89);
    assert (prime_fib(6) == 233);
    assert (prime_fib(7) == 1597);
    assert (prime_fib(8) == 28657);
    assert (prime_fib(9) == 514229);
    assert (prime_fib(10) == 433494437);
}
