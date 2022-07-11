#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    return sum % 10;
}

long long fibonacci_sum_fast(long long n) {
    long long f[100001],sum_last_digit=1;
    long long reminder;
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
        reminder = (n+2) % 60;     //Period of 10 is 60
        sum_last_digit = (f[reminder] + 9)%10;
        return sum_last_digit;
    }
       
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}

