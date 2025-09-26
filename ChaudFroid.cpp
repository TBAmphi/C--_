#include <cstdlib>
#include <ctime>
#include <iostream>

struct AI_Data
{
    bool useAI = false;
    int minBorne = 1;
    int maxBorne = 100;
    int aiLevel = 10;
};

int CompareAndDisplay(int answer, int value)
{
    if(answer == value)
    {
        std::cout << "You win !" << std::endl;
        return 0;            
    }
    else if (answer < value)  
    {
        std::cout << "Higher" << std::endl;
        return 1;
    }
    else if (answer > value)
    {
        std::cout << "Lower" << std::endl;
        return -1;
    }
}

int AI_Guess(AI_Data ai, int min, int max)
{
    float level = ai.aiLevel / 10.0f; // ex : 0.5 pour niveau 5
    int range = max - min;
    int interval = (range * (1.0f - level));

    int center = (min + max) / 2;
    int left = center - interval / 2;
    int right = center + interval / 2;

    if(left < min) left = min;
    if(right > max) right = max;

    int guess = left + rand() % (right - left + 1);
    return guess;
}

int UpdateBounds(int result, int& min, int& max, int answer)
{
    if(result == 1)
    {
        min = answer + 1;
    }
    else if(result == -1)
    {
        max = answer - 1;
    }
    else 
    {
        return 0;
    }
}

int PlayAI(AI_Data ai, int maxValue)
{
    int valueToFind = rand() % (maxValue + 1);
    int min = 0;
    int max = maxValue;

    int attempts = 0;
    int result;
    int guess;

    do
    {
        guess = AI_Guess(ai, min, max);
        std::cout << guess << std::endl;
        result = CompareAndDisplay(guess, valueToFind);
        UpdateBounds(result, min, max, guess);
        attempts++;
    } 
    while (result !=0);

    return attempts;
    
}

int main()
{
    AI_Data ai;
    int maxValue = 100; 
    int playerInput;
    srand(time(NULL));
    //randomValue = rand() % 100;
    std::cout << "Do you want to use AI ?" << std::endl;   
    (std::cin.get() == 'y') ? ai.useAI = true : ai.useAI = false;
    //std::cout << "What is the max value ?" << std::endl;
    //std::cin >> playerInput;
    //maxValue = playerInput;
    //std::cout << valueToFind << std::endl;
    float moyennes[11];

    if(ai.useAI)
    {
        ai.minBorne = 0;
        ai.maxBorne = maxValue;

        /*std::cout << "Between 1 and 10 what is AI level ?" << std::endl;
        std::cin >> playerInput;
        std::cout << playerInput << std::endl;
        */
       int level;

        for(level = 1; level <= 10; level++)
        {
            ai.aiLevel = level;
            int totalAttempts = 0;

            for(int i = 0; i < 100; i++)
            {
                totalAttempts += PlayAI(ai, maxValue);
            }

            float moyenne = totalAttempts / 100.0f;
            moyennes[level] = totalAttempts / 100.0f;
            std::cout << "Au niveau " << level << " l'ia fait en moyenne " << moyenne << " coups." << std::endl;

        }

        std::cout << "Resume des moyennes :" << std::endl;
        for(int level = 1; level <= 10; level++)
        {
            std::cout << "Niveau " << level << " : " << moyennes[level] << " coups en moyenne" << std::endl;
        }          
    }
    else
    {
        int valueToFind = rand() % (maxValue + 1);
        std::cout << "What is your guess ?" << std::endl;
        do
        {
            std::cin >> playerInput;
        }
        while(CompareAndDisplay(playerInput,valueToFind) != 0);
    }

    return 0;
}