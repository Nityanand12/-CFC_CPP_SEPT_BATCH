#include <iostream>
using namespace std;
int reverse(int num)
{
  int ans = 0;
  while (num != 0)
  {
    ans = ans * 10 + num % 10;
    num = num / 10;
  }
  return ans;
}
int numOfDigit(int n)
{
  int cnt = 0;
  if (n == 0)
    cnt = 1;
  while (n != 0)
  {
    n = n / 10;
    cnt++;
  }
  return cnt;
}
int power(int a, int b)
{
  int ans = 1;
  for (int i = 1; i <= b; i++)
  {
    ans = ans * a;
  }
  return ans;
}
int rotateByK(int num, int k)
{
  int d = numOfDigit(num);
  k = k % d; //-d<k<d
  if (k < 0)
  {
    k = k + d;
  }
  // 0<=k<d
  int p = power(10, k);
  int ans = num % p * power(10, d - k) + num / p;
  return ans;
}

void pattern1(int n)
{
  int id = 1, nst = 1, nsp = 0;
  while (id <= n)
  {
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst++;
    id++;
  }
}
void pattern2(int n)
{
  int id = 1, nst = 1, nsp = 0;
  while (id <= n)
  {
    int cst = 1;
    while (cst <= nst)
    {
      cout << cst << " ";
      cst++;
    }
    cout << "\n";
    nst++;
    id++;
  }
}
void pattern3(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst++;
    nsp--;
    id++;
  }
}

void pattern4(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << cst;
      cst++;
    }
    cout << "\n";
    nst++;
    nsp--;
    id++;
  }
}

void pattern5(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= n)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    nst = nst + 2;
    nsp--;
    id++;
  }
}
void pattern6(int n)
{
  int id = 1, nsp = n - 1, nst = 1;
  while (id <= 2 * n - 1)
  {
    int csp = 1;
    while (csp <= nsp)
    {
      cout << " ";
      csp++;
    }
    int cst = 1;
    while (cst <= nst)
    {
      cout << "*";
      cst++;
    }
    cout << "\n";
    if (id < n)
    {
      nst = nst + 2;
      nsp--;
    }
    else{
      nst = nst - 2;
      nsp++;
    }
    id++;
  }
}
int main()
{
  // cout<<reverse(64879)<<"\n";
  // cout<<rotateByK(64879,-3)<<"\n";
  // pattern1(5);
  // pattern2(5);
  // pattern3(5);
  // pattern4(5);
  // pattern5(5);
  pattern6(6);
  return 0;
}