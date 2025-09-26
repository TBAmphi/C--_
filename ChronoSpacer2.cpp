#include <iostream>
#include "Windows.h"
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

// Get Input
bool isKeyPressed()
{
    if (_kbhit())
    {
        while (_kbhit()) 
        {
            _getch();
        }
        return true; 
    }
    return false; 
}

int main()
{
    std::cout << "Pour jouer,\nle joueur doit appuyer sur un boutton compter le temps affiche et lorsque le joueur pense avoir le bon temps re-appyer.\nIl y a 5 parties,\na la fin de celles-ci vous obtiendrez une note." << std::endl;
    float maxTime = 10.0f;
    float minTime = 0.1f;
    float winInterval = 0.5f;
    float elapsedTime;
    float perfect = 0.0f;
    int victoire = 0;
    int defaite = 0;
    srand(time(NULL));
    for(int i = 0; i <= 4; i++)
    {
        float timeToFind = ((float)rand() / ((float)RAND_MAX) * (maxTime - minTime)) + minTime;
        std::cout << "Vous devez faire " << timeToFind << " secondes" << std::endl;
        system("pause");
        std::cout << "C'est parti !" << std::endl;
        float startTime = (float)clock() / (float)CLOCKS_PER_SEC;
        system("pause");
        float endTime = (float)clock() / (float)CLOCKS_PER_SEC;
        elapsedTime = endTime - startTime;

        if(abs(elapsedTime - timeToFind) <= perfect)
        {
            std::cout << "Incroyable vous avez fait le temps exact BRAVO!!" << std::endl;
            victoire++;
        } 
        if(abs(elapsedTime - timeToFind) <= winInterval)
        {
            std::cout << "Vous avez gagne !" << std::endl;
            victoire++;
        }
        else
        {
            std::cout << "Vous avez perdu !" << std::endl;
            defaite++;
        }


        std::cout << "Votre temps est " << elapsedTime << " secondes" << std::endl;
    }

    std::cout << "Vous avez " << victoire << " victoires" << " et " << defaite << " defaites" << std::endl;

    return 0;
}