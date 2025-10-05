#include <iostream>
#include <cstdlib>

int max(int a, int b)
{
    if( a > b)
    {
        return a;
    }
    else if( a < b)
    {
        return b;
    }
}

int min(int a, int b)
{
    if( a > b)
    {
        return b;
    }
    else if( a < b)
    {
        return a;
    }
}

int main()
{
std::cout << "max(42,66): " << max(42,66) << std::endl;
std::cout << "min(42,66): " << min(42,66) << std::endl;
}