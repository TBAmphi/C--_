#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <windows.h>
#include <cmath>

char output[11][11];
float PI = 3.14159265358979323846f;

struct Chrono
{
    int duration;
    float elapsedTime;
    bool isFinished = false;
};

int AskTime();
float GetTime();
void UpdateChrono(Chrono& chrono, float deltaTime);
void InisializeOutput();
void DisplayOutput();
void ResetDisplay();
void WriteSeconde(Chrono& chrono);
void WriteTimeLeft(Chrono& chrono);
void WriteChrono(Chrono& chrono);

int main()
{
    int time = AskTime();
    float currentTime = GetTime();
    Chrono chrono {time};
    system("cls");

    while (chrono.isFinished != true)
    {
        float newTime = GetTime();
        float deltaTime = newTime - currentTime;
        currentTime = newTime;

        UpdateChrono(chrono, deltaTime);
        ResetDisplay();
        WriteChrono(chrono);
        DisplayOutput();
    } 
}

int AskTime()
{
    int time = 0;
    do
    {
        std::cout << "Saisissez la duree du chronometre en secondes." << std::endl;
        std::cin >> time;
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    } while (time <= 0);
    return time;
}

float GetTime()
{
    float timeInSeconde = clock() / (float)CLOCKS_PER_SEC;
    return timeInSeconde;
}

void UpdateChrono(Chrono& chrono, float deltaTime)
{
    if(chrono.isFinished == true) return;

    chrono.elapsedTime += deltaTime;

    if(chrono.elapsedTime >= chrono.duration)
    {
        chrono.isFinished = true;
    }
}

void InisializeOutput()
{
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            output[i][j] = '-';
        }
    }

    output[5][5] = 'X';

    for(int i = 1; i <= 4; i++)
    {
        output[i][5] = '|';
    }
}

void DisplayOutput()
{
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            std::cout << output[i][j];
        }
        std::cout << "\n";
    }
}

void ResetDisplay()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, pos);

    InisializeOutput();
}

void WriteSeconde(Chrono& chrono)
{
    int posX = ((int)(chrono.elapsedTime * 11)) % 11;
    output[0][posX] = '0';
}

void WriteTimeLeft(Chrono& chrono)
{
    int posX = (int)((cos(chrono.elapsedTime * 2 * PI / chrono.duration - PI / 2) * 3)+ 5.5f);
    int posY = (int)((sin(chrono.elapsedTime * 2 * PI / chrono.duration - PI / 2) * 3)+ 5.5f);

    output[posY][posX] = '*';
}

void WriteChrono(Chrono& chrono)
{
    WriteSeconde(chrono);
    WriteTimeLeft(chrono);
}