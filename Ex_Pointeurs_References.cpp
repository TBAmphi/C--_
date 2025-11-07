#include <iostream>
#include <cstdlib>

struct Item;
struct Player;
enum class ItemType;
enum class Hand;
void DisplayItem(Item& item);
void Grab(Player& player, Item& item,Hand hand);
void Drop(Player& player, Hand hand);
void DisplayPlayer(Player& player);
std::string ItemName(Item& item);


enum class ItemType{
    Sword,
    Shield,
    Wand,
    Bow
}; // use::

struct Item
{
    ItemType type;
    std::string name = "Name";
    int durability = 100;
    int quality = 100;

    Player* owner = nullptr;
}; // use .

struct Player
{
    std::string name = "New Player";
    int health = 100;
    Item *ptrLeftHand;
    Item *ptrRightHand;
};

enum class Hand
{
    Left,
    Right,
    Both
};

int main()
{
    Item sword{ItemType::Sword, "Sword"}; 
    Item shield{ItemType::Shield, "Shield"};
    Item wand{ItemType::Wand, "Wand"};
    Item bow{ItemType::Bow, "Bow"};

    Player playerA{"PlayerA"};
    Player playerB{"PlayerB"};
    std::cout << "Nouveau joueur cree, " << playerA.name << std::endl;
    std::cout << "Nouveau joueur cree, " << playerB.name << std::endl;
    playerA.ptrLeftHand = nullptr;
    playerA.ptrRightHand = nullptr;
    playerB.ptrLeftHand = nullptr;
    playerB.ptrRightHand = nullptr;    

    /*
    Grab(playerA, sword, Hand::Right);
    Grab(playerA, shield, Hand::Left);
    DisplayPlayer(playerA);
    Drop(playerA, Hand::Right);
    DisplayPlayer(playerA);
    Drop(playerA, Hand::Left);
    Grab(playerA, bow, Hand::Both);
    DisplayPlayer(playerA);
    */

    /*
    Grab(playerA, sword, Hand::Right);
    Grab(playerB, sword, Hand::Right);
    Grab(playerA, sword, Hand::Right);
    Grab(playerA, sword, Hand::Left);
    Grab(playerB, sword, Hand::Left);
    */

    Grab(playerB, bow, Hand::Both);
    Grab(playerA, wand, Hand::Left);
    DisplayPlayer(playerA);
    DisplayPlayer(playerB);


    return 0;
}

void DisplayItem(Item& item)
{
    switch (item.type)
    {
    case ItemType::Sword:
        std::cout << "Item type: Sword" << std::endl;
        break;
    case ItemType::Shield:
        std::cout << "Item type: Shield" << std::endl;
        break;
    case ItemType::Wand:
        std::cout << "Item type: Wand" << std::endl;
        break;
    case ItemType::Bow:
        std::cout << "Item type: Bow" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Durability: " << item.durability << std::endl;
    std::cout << "Quality: " << item.quality << std::endl;
}

void Grab(Player& player, Item& item, Hand hand)
{
    if(item.owner != nullptr && item.owner != &player)
    {
        std::cout << "Item already taken by " << item.owner->name << "."<< std::endl;
        return;
    }

    int result = 0;
    if(hand == Hand::Left)
    {result = 1;}
    if(hand == Hand::Right) 
    {result = 2;}
    if(hand == Hand::Both) 
    {result = 3;}

    switch (result)
    {
    case 1:
        if(player.ptrLeftHand == nullptr)
        {
            player.ptrLeftHand = &item;
            item.owner = &player;
            std::cout << ItemName(*player.ptrLeftHand) << " is now equiped on your left hand." << std::endl;
        }
        else
        {
            std::cout << "Left hand is not empty." << std::endl;
        }
        break;
    case 2:
        if(player.ptrRightHand == nullptr)
        {
            player.ptrRightHand = &item;
            item.owner = &player;
            std::cout << ItemName(*player.ptrRightHand) << " is now equiped on your right hand." << std::endl;
        }
        else
        {
            std::cout << "Right hand is not empty." << std::endl;
        }
        break;
    case 3:
        if(player.ptrLeftHand == nullptr && player.ptrRightHand == nullptr)
        {
            player.ptrLeftHand = &item;
            player.ptrRightHand = &item;
            item.owner = &player;
            std::cout << ItemName(*player.ptrLeftHand) << " is now equiped on your two hands." << std::endl;
        }
        else
        {
            std::cout << "Your hands are not empty." << std::endl;
        }
        break;
    default:
        std::cout << "error" << std::endl;
        break;
    }
}

void Drop(Player& player, Hand hand)
{
    int result = 0;
    if(hand == Hand::Left)
    {result = 1;}
    if(hand == Hand::Right) 
    {result = 2;}
    if(hand == Hand::Both) 
    {result = 3;}

    switch (result) 
    {
        case 1:
            if(player.ptrLeftHand != nullptr)
            {
                player.ptrLeftHand->owner = nullptr;
                player.ptrLeftHand = nullptr;
                std::cout << "You have drop your left hand item." << std::endl;
            }
            else
            {
                std::cout << "The left hand is already empty" << std::endl;
            }
            break;
        case 2:
            if(player.ptrRightHand != nullptr)
            {
                player.ptrLeftHand->owner = nullptr;
                player.ptrRightHand = nullptr;
                std::cout << "You have drop your right hand item." << std::endl;
            }
            else
            {
                std::cout << "The right hand is already empty" << std::endl;
            }
            break;
        case 3:
            if(player.ptrLeftHand != nullptr && player.ptrRightHand != nullptr)
            {
                player.ptrLeftHand->owner = nullptr;
                player.ptrLeftHand = nullptr;
                player.ptrRightHand = nullptr;
                std::cout << "You have drop your item." << std::endl;
            }
            else
            {
                std::cout << "The hands are already empty" << std::endl;
            }
            break;
    }
}

void DisplayPlayer(Player& player)
{
    std::cout << "========== " << player.name << "'s Informations ==========" << std::endl;
    std::cout << "Name: " << player.name << std::endl;
    std::cout << "HP: " << player.health << std::endl;

    if(player.ptrLeftHand == nullptr)
    {
        std::cout << "Left hand is empty."<< std::endl;
    }
    else
    {
        std::cout << "------------------------- " << std::endl;
        std::cout << "Left hand: " << ItemName(*player.ptrLeftHand) << std::endl;
        DisplayItem(*player.ptrLeftHand);
        std::cout << "------------------------- " << std::endl;
    }
    if(player.ptrRightHand == nullptr)
    {
        std::cout << "Right hand is empty."<< std::endl;
    }
    else    
    {
        std::cout << "------------------------- " << std::endl;
        std::cout << "Right hand: " << ItemName(*player.ptrRightHand) << std::endl;
        DisplayItem(*player.ptrRightHand);
        std::cout << "------------------------- " << std::endl;
    }
    std::cout << '\n' << std::endl;
}

std::string ItemName(Item& item)
{
    return item.name;
}