#include <iostream>
#include "Windows.h"
#include <time.h>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "Pour jouer,\nle joueur doit appuyer sur un boutton compter le temps affiche et lorsque le joueur pense avoir le bon temps re-appyer.\nIl y a 5 parties,\n a la fin de celles-ci vous obtiendrez une note." << std::endl;
    float maxTime = 10.0f;
    float minTime = 1.0f;
    float timeToFind = ((float)rand() / ((float)RAND_MAX) * (maxTime - minTime)) + minTime;
    float winInterval = 1.0f;
    float elapsedTime;
    //float perfect = 0.0f;
    for(int i = 0; i <= 4; i++)
    {
        std::cout << "Vous devez faire " << timeToFind << " secondes" << std::endl;
        system("pause");
        std::cout << "C'est parti !" << std::endl;
        float startTime = (float)clock() / (float)CLOCKS_PER_SEC;
        system("pause");
        float endTime = (float)clock() / (float)CLOCKS_PER_SEC;
        elapsedTime = endTime - startTime;

        /*if(abs(elapsedTime - timeToFind) <= perfect)
        {
            std::cout << "Incroyable vous avez fait le temps exact BRAVO!!" << std::endl;
        } */
        if(abs(elapsedTime - timeToFind) <= winInterval)
        {
            std::cout << "Vous avez gagne !" << std::endl;
        }
        else
        {
            std::cout << "Vous avez perdu !" << std::endl;
        }


        std::cout << "Votre temps est " << elapsedTime << " secondes" << std::endl;
    }


    return 0;
}