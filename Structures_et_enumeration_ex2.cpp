#include <iostream>
#include <string>
#include <cmath>

struct Position
{
    int x;
    int y;
};

struct Player
{
    std::string name;
    int health;
    Position position;
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
    p.position.x = x;
    p.position.y = y;
    return p;
}

void MovePlayer(Player &p)
{
    int moveX;
    int moveY;
    std::cout << "C'est ton tour " << p.name << std::endl;
    std::cout << "Position: (" << p.position.x << ", " << p.position.y << ")" << std::endl;
    std::cout << "Avancer de combiens en X ?" << std::endl;
    std::cin >> moveX;
    std::cout << "Avancer de combiens en Y ?" << std::endl;
    std::cin >> moveY;

    p.position.x += moveX;
    p.position.y += moveY;
    std::cout << p.name << " est desormais en " << p.position.x << " X et " << p.position.y << " Y" << std::endl;
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

float DistanceBetweenPlayers(Player a, Player b)
{
    int dx = a.position.x - b.position.x;
    int dy = a.position.y - b.position.y;
    std::cout << "Distance entre " << a.name << " et " << b.name << " : " << sqrt(dx * dx + dy * dy) << std::endl;
    return 0;
}

void PrintPlayer(Player &p)
{
    std::cout << "------ Information Joueur ------" << std::endl;
    std::cout << "Nom :        " << p.name << std::endl;
    std::cout << "Vie :        " << p.health << std::endl;
    std::cout << "Etat :       " << PlayerStateToString(GetPlayerState(p)) << std::endl;
    std::cout << "Position :   " << p.position.x << ", " << p.position.y << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

int main()
{
    Player p;
    std::cout << "Creation du joueur 1" << std::endl;
    Player player_1 = CreateNewPlayer(142, 120);
    PrintPlayer(player_1);

    std::cout << "Creation du joueur 2" << std::endl;
    Player player_2 = CreateNewPlayer(200, 150);
    PrintPlayer(player_2);    

    char choix;
    std::cout << "Faire bouger le joueur ?" << std::endl;   
    std::cin >> choix;

    while(choix == 'y' || choix == 'Y')
    {
        MovePlayer(player_1);
        PrintPlayer(player_1);
        DistanceBetweenPlayers(player_1, player_2);
        MovePlayer(player_2);
        PrintPlayer(player_2);
        DistanceBetweenPlayers(player_1, player_2);
        
        std::cout << "Continue ?" << std::endl;   
        std::cin >> choix;
    }
}
