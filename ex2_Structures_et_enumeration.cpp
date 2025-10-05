#include <iostream>
#include <string>

struct Player
{
    std::string name;
    int health;
    int x;
    int y;
};

enum class PlayerState
{
    Healthy,
    Dead,
    Hurt
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

void MovePlayer(Player &p, int x, int y)
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
    std::cout << p.name << " est desormais en " << p.x << " X et " << p.y << " Y" << std::endl;
}

PlayerState GetPlayerState(Player &p)
{
    if(p.health <= 0) return PlayerState::Dead;
    else if(p.health == 100) return PlayerState::Healthy;
    else return PlayerState::Hurt;
}

std::string PlayerStateToString(PlayerState state)
{
    switch (state)
    {
        case PlayerState::Healthy: return "Healthy";
        case PlayerState::Hurt:    return "Hurt";
        case PlayerState::Dead:    return "Dead";
        default:                   return "Unknown";
    }
}

void PrintPlayer(Player &p)
{
    std::cout << "------ Information Joueur ------" << std::endl;
    std::cout << "Nom :        " << p.name << std::endl;
    std::cout << "Vie :        " << p.health << std::endl;
    std::cout << "Etat :       " << PlayerStateToString(GetPlayerState(p)) << std::endl;
    std::cout << "Position :   " << p.x << ", " << p.y << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

int main()
{
    Player player = CreateNewPlayer(142, 120);
    char choix;

    std::cout << "Joueur cree" << std::endl;
    PrintPlayer(player);
    std::cout << "Faire bouger le joueur ?" << std::endl;   
    std::cin >> choix;

    while(choix == 'y' || choix == 'Y')
    {
        MovePlayer(player, player.x, player.y);
        PrintPlayer(player);
        std::cout << "Continue ?" << std::endl;   
        std::cin >> choix;
    }
}
