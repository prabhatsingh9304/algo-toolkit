#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long get_fibonacci_huge_fast(long long n,long long m) {
    long long f[100001];
    long long period,reminder;
    f[0] = 0;
    f[1] = 1;
    for(long long i=2;i<=100000;i++)     // fabonacci 
    {
        f[i] = (f[i-1] + f[i-2])%m;
        
    }
  

    for(long long j=2;j<100000;j++) //Calculation of Period
    {
        if(f[j]== 0 && f[j+1] == 1)
        {
            period = j;
            break;
        }
    }
    reminder = n % period;     // F2015 % 3 = F7 % 3 , 2015 % 8 = 7 , 8 is Pisano Period

    return f[reminder] % m;
    
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std:: cout << get_fibonacci_huge_fast(n, m) << '\n';
}

/*
fn-1
fn-2
fn = fn-1 + fn-2
fn%m
 (a+b)%m = (a%m+b%m)%m
 (a*b)%m = (a%m*b%m)
*/