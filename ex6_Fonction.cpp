#include <iostream>
#include <cstdlib>

int bissextile(int year)
{
    if(year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if(year % 400 == 0)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}

int day_count(int month, int year)
{
    if( month < 1 || month > 12)
    {
        return -1;
    }

    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
        break;

    case 4: case 6: case 9: case 11: 
        return 30;
        break;
    
    case 2:
        if(bissextile(year) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }    
    default:
        return -1;
        break;
    }
}

int main()
{
    int month;
    int year;
    std::cout << "Donnez toutes les information en utilisant des nombres." << std::endl;
    std::cout << "Quel mois ?" << std::endl;
    std::cin >> month;
    std::cout << "De quelle annee ?" << std::endl;
    std::cin >> year;

    std::cout << day_count(month, year) << std::endl;
}