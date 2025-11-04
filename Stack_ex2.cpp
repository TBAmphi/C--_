#include <iostream>

struct Coordinate {
int i;
int j;
};

Coordinate max(int tab[5][5], Coordinate North, Coordinate West, Coordinate East, Coordinate South, Coordinate actual)
{
    Coordinate maxCoord = actual;
    if(North.i >= 0 && North.i <= 4 && North.j >= 0 && North.j <= 4)
    {
        if(tab[North.i][North.j] > tab[maxCoord.i][maxCoord.j]) maxCoord = North;
    }

    if(West.i >= 0 && West.i <= 4 && West.j >= 0 && West.j <= 4)
    {
        if(tab[West.i][West.j] > tab[maxCoord.i][maxCoord.j]) maxCoord = West;
    }

    if(East.i >= 0 && East.i <= 4 && East.j >= 0 && East.j <= 4)
    {
        if(tab[East.i][East.j] > tab[maxCoord.i][maxCoord.j]) maxCoord = East;
    }

    if(South.i >= 0 && South.i <= 4 && South.j >= 0 && South.j <= 4)
    {
        if(tab[South.i][South.j] > tab[maxCoord.i][maxCoord.j]) maxCoord = South;
    }

    return maxCoord;
}

Coordinate FindhighestAdjacent(int tab[5][5], Coordinate start)
{

    Coordinate North = {start.i - 1, start.j};
    Coordinate West = {start.i, start.j - 1};
    Coordinate East = {start.i, start.j + 1};
    Coordinate South = {start.i + 1, start.j};

    Coordinate highest = max(tab, North, West, East, South, start);
    Coordinate direction = {highest.i - start.i, highest.j - start.j};

    if(tab[highest.i][highest.j] == 0)
    {
        return {-1, -1};
    }

    return highest;
}

void MaxPath(int tab[5][5], int i, int j, int &limite, int index = 0)
{
    while(index < limite)
    {
        Coordinate start = {i, j};
        Coordinate result = FindhighestAdjacent(tab, start);
        if(result.i == -1 && result.j == -1) 
        {
            std::cout << "Toutes les valeurs adjacentes sont de 0, fin du programme. "<< std::endl;
            break;
        }

        std::cout << "New postion : (" << result.i << ", " << result.j << ")" << std::endl;
        std::cout << "The value is : " << tab[result.i][result.j] << std::endl;

        tab[result.i][result.j] = 0;

        i = result.i;
        j = result.j;
        std::cout << "The new value is : " << tab[result.i][result.j] << std::endl;

        index++;
        std::cout << "Index : " << index << ". "<< std::endl;
    }
}

int main() 
{  
    int i;
    int j;
    int limite = 10;

    int tab[5][5] = {{0,8,7,1,5}, {3,5,2,8,9}, {0,4,0,1,0}, {2,4,3,6,1}, {1,4,3,1,0}};

    std::cout << "Entrez i (de 0 a 4) : ";
    std::cin >> i;
    std::cout << "Entrez j (de 0 a 4) : ";
    std::cin >> j;
    std::cout << "Entrez une limite de tours : ";
    std::cin >> limite;

    if (i < 0 || i > 4 || j < 0 || j > 4) 
    {
        std::cout << "Valeur de i ou de j invalide. Veuillez entrer des valeurs entre 0 et 4." << std::endl;
        return 1;
    }

    MaxPath(tab, i, j, limite, 0);

    return 0;
}

