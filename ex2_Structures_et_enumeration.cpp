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

int MovePlayer(Player p, int x, int y)
{
    int moveX;
    int moveY;
    std::cout << "Position: (" << p.x << ", " << p.y << ")" << std::endl;
    std::cout << "Avancer de combiens en X ?" << std::endl;
    std::cin >> moveX;
    std::cout << "Avancer de combiens en Y ?" << std::endl;
    std::cin >> moveY;

    p.x += moveX;
    p.y += moveY;
    std::cout << p.name << " est desormais en " << p.x << "X et " << p.y << "Y" << std::endl;
    return 0;
}

int main()
{
    Player player = CreateNewPlayer(142, 120);
    bool movePlayer = false;

    std::cout << "Joueur cree" << std::endl;
    std::cout << "Nom: " << player.name << std::endl;
    std::cout << "Vie: " << player.health << std::endl;
    std::cout << "Position: (" << player.x << ", " << player.y << ")" << std::endl;

    std::cout << "Faire bouger le joueur ?" << std::endl;   
    (std::cin.get() == 'y') ? movePlayer = true : movePlayer = false;

    if(movePlayer == true)
    {
        MovePlayer(player, player.x, player.y);       
    }

    return 0;
}
