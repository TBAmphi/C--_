#include <iostream>
#include <cstdlib>

int fibonacci(int n)
{
    if(n < 0)
    {
        return -1;
    }
    else if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        int a = 0;
        int b = 1;
        int resultat;
        for (int i = 2; i <= n; i++)
        {
            resultat = a + b;
            a = b;
            b = resultat;
        }
        return resultat;
    }
}

int main()
{
    int n;
    std::cout << "Jusqu'a quel entier n voulez vous calculer la suite de Fibonacci ?" << std::endl;
    std::cin >> n;

    std::cout << "Fib(" << n << ") : " << fibonacci(n) << std::endl;
}