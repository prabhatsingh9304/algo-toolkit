#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm_fast(int a,int b)
{
  long long lcm,product_ab,r=-1;
  product_ab = (long long) a*b;
  while(r!=0)
  {
    r=b%a;
    b=a;
    a=r;
  }
  lcm = product_ab/b;
  return (long long) lcm;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a,b) << std::endl;
  return 0;
}
