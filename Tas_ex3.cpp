#include <iostream>
#include <cstdlib>

int main()
{
    for(int i = 1; i < 5; i++)
    {
        int *tab = new int[i];
        std::cout << "Tableau :" << i << std::endl;
        for(int j = 0; j < i; j++)
        {
            tab[j] = j;
            std::cout << tab[j] << std::endl; 
        }
        delete[] tab;
    }
}