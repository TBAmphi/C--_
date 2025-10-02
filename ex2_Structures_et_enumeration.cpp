#include <iostream>
#include <string>

struct Player
{
    std::string name;
    int health;
    int x;
    int y;
};

Player CreateNewPlayer(int x, int y)
{
    Player p;
    std::cout << "Saisissez votre nom: " << std::endl;
    std::cin >> p.name;
    p.health = 100;
    p.x = x;
    p.y = y;

    return p;
}

int main()
{
    Player player = CreateNewPlayer(142, 120);

    std::cout << "Joueur cree" << std::endl;
    std::cout << "Nom: " << player.name << std::endl;
    std::cout << "Vie: " << player.health << std::endl;
    std::cout << "Position: (" << player.x << ", " << player.y << ")" << std::endl;

    return 0;
}
