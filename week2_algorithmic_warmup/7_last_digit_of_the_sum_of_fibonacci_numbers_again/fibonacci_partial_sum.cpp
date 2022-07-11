#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long long get_fibonacci_partial_sum_fast(long long m,long long n) {
    long long f[100001],sum_last_digit=1;
    long long reminder1,reminder2;
    f[0] = 0;
    f[1] = 1;
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        for(long long i=2;i<=100000;i++)     // fabonacci 
        {
            f[i] = (f[i-1] + f[i-2])%10;
        
        }
        reminder1 = (n+2) % 60;     //Period of 10 is 60
        reminder2 = (m+1) % 60;
        sum_last_digit = (f[reminder1] +(10- f[reminder2]))%10;
        return sum_last_digit;
    }
       
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from,to) << '\n';
}
