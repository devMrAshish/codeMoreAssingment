#include <iostream>
#include <cmath>
bool primeNo(int n)
{
    int i;
    if (n <= 1)
    {
        return false;
    }

    for (i = 2; i * i <= n; i++)
    {

        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int reverseNo(int n)
{
    int lastDigit = n;
    int revNo = 0;
    while (lastDigit != 0)
    {
        revNo = revNo * 10 + lastDigit % 10;
        lastDigit = lastDigit / 10;
    }
    return revNo;
}
bool pallindrome(int n)
{
    if (n != reverseNo(n))
    {
        return false;
    }
    return true;
}
bool primePalindrome(int n)
{
    return pallindrome(n) && primeNo(n);
}
int countPalindrome(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pallindrome(i))
        {
            count++;
        }
    }
    return count;
}
void printPrimePalindrome(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (primePalindrome(i))
        {
            std::cout << i << " ";
        }
    }
}
int larPrime(int n)
{
    for (int i = n; i > 0; i--)
    {
        if (primeNo(i))
        {
            return i;
        }
    }
    return -1;
}
int countDigit(int n)
{
    int lastDigit = n, count = 0;
    while (lastDigit != 0)
    {
        lastDigit = lastDigit / 10;
        count++;
    }
    return count;
}
int sumDigit(int n)
{
    int lastDigit = n, sum = 0;
    while (lastDigit != 0)
    {
        sum = sum + lastDigit % 10;
        lastDigit = lastDigit / 10;
    }
    return sum;
}
bool armstrong(int n)
{
    int lastDigit = n, sum = 0;
    while (lastDigit != 0)
    {
        sum = sum + pow(lastDigit % 10, 3);
        lastDigit = lastDigit / 10;
    }
    return sum == n;
}
int nexPrimePalindrome(int n){
    for (int i = n; ; i++)
    {
       if (primePalindrome(i))
       {
        return i;
       }
       
    }
    
}
void twinPrime(int n){
    for (int i = 0; i <=  n-2; i++)
    {
       if (primeNo(i)&&primeNo(i+2))
       {
            std::cout<<i<<" "<<i+2<<std::endl;
       }
       
    }
    
}
bool emirp(int n){
    return primeNo(n)&&primeNo(reverseNo(n));
}
int main()
{
    int a;
    std::cin >> a;
    std::cout <<std::boolalpha<<emirp(a);
    // twinPrime(a);
    return 0;
}