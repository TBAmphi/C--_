#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>

int CreatePlayer();
void TabInitialization(int nbPlayer);

int main()
{
    int nbPlayer = CreatePlayer();
    std::vector<int> playerScores(nbPlayer, 0);
    TabInitialization(nbPlayer);
    /*nbPlayer += 1;
    TabInitialization(nbPlayer);*/
}

int CreatePlayer()
{
    int nbPlayers = 0;
    do
    {
        std::cout << "How many player do you want ?" << std::endl;
        std::cin >> nbPlayers;
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    } while (nbPlayers <= 0);

    return nbPlayers;
}

void TabInitialization(int nbPlayer)
{
    int tabSize = 10 + 2*nbPlayer;
    std::vector<std::vector<bool>> tab(tabSize, std::vector<bool>(tabSize, false));
    int newTabSize = tabSize + 1;
    tab.resize(newTabSize, std::vector<bool>(tabSize, false));
}