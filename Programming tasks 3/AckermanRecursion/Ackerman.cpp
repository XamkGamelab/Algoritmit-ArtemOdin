
#include <iostream>
int AckermanVaalue(int m, int n);

int main()
{
    int a = 3;
    int b = 4;
    std::cout << "Ackerman value for " << a << " and " << b << " is " << AckermanVaalue(a, b);
}


int AckermanVaalue(int m, int n) 
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return AckermanVaalue(m - 1, 1);
    else
        return AckermanVaalue(m - 1, AckermanVaalue(m, n - 1));
}