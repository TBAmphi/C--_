#include <cstdlib>
#include <iostream>

int main()
{
    int tab[5][5];
    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            result = (i+j) % 2;
            std::cout << result << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}