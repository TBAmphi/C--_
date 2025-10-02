#include <cstdlib>
#include <iostream>

struct Divmod
{
    int div;
    int rem;
};

int CalculateDivMod(Divmod dm, int a, int b)
{
    dm.div = a/b;
    dm.rem = a%b;
    std::cout << a << "/" << b << ": " << dm.div << std::endl; 
    std::cout << a << "%" << b << ": " << dm.rem << std::endl; 
    return 0;
}

int main()
{
    Divmod dm;
    int a;
    int b;
    std::cout << "What is the first value ?" << std::endl;
    std::cin >> a;
    std::cout << "What is the second value ?" << std::endl;
    std::cin >> b;
    CalculateDivMod(dm, a, b);
}