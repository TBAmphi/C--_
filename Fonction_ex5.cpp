#include <iostream>
#include <cstdlib>

int bissextile(int a)
{
    if(a % 4 == 0 && a % 100 != 0)
    {
        std::cout << a << " : TRUE" << std::endl;
    }
    else if(a % 400 == 0)
    {
        std::cout << a << " : TRUE" << std::endl;
    }
    else
    {
        std::cout << a << " : FALSE" << std::endl;
    }

    return 0;
}

int main()
{
    int analyse;
    std::cout << "Donnez une annee pour savoir si elle est bissextile" << std::endl;
    std::cin >> analyse;
    bissextile(analyse);

    for (int i = 2000; i < 2026; i++)
    {
        bissextile(i);
    }
    
}