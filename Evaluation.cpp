#include <iostream>
#include <cstdlib>

void Exercice2Partie1()
{
    // Exercice 2 - 1 :
    int tab[10];
    int index = 0;
    while(index < 10)
    {
        tab[index] = index;
        std::cout << tab[index] << std::endl;
        index++;
    } 
}

void Exercice2Partie2()
{
    // Exercice 2 - 2 :
    int somme = 0;
    int i = 0;
    while(somme < 100)
    {
        somme += i;
        i++;
        std::cout << "Somme = " << somme << std::endl;
        std::cout << i << " tour." << std::endl;
    }
}

int Abs(int nb)
{
    int result = 0;
    if(nb < 0)
    {
        result -= nb;
        return result;
    }
    else
    {
        result = nb;
        return result;
    } 
}

void Exercice3()
{
    int nb = -5;  
    std::cout << "Rentrez un int" << std::endl;
    std::cin >> nb;
    int abs_nb = Abs(nb);
    std::cout << abs_nb << std::endl;

}

int Attak(std::string typeAtt, int power, std::string typeDef)
{
    if(typeAtt == "electric" && typeDef == "water")
    {
        power = power * 2;
    }
    if(typeAtt == "water" && typeDef == "fire")
    {
        power = power * 2;
    }
    if(typeAtt == "fire" && typeDef == "water")
    {
        power = power / 2;
    }

    return power;
}

void Exercice4()
{
    std::string name[5] = {"Pikachu", "Carapuce", "Salameche", "Grenousse", ""};
    std::string type[5] = {"electric", "water", "fire", "water", ""};
    int power[5] = {100, 40, 60, 80, 0};

    std::cout << "Les degats de pikachu sur carapuce seront de : " << Attak(type[0], power[0], type[1]) << std::endl;
    
    
    
    std::string newname = "";
    std::string newtype = "";
    int newpower = 0;
    std::cout << "Ajouton votre propre pokemon a la liste." << std::endl;
    std::cout << "Quel est son nom ?" << std::endl;
    std::cin >> newname;
    std::cout << "Quel est son type ?" << std::endl;
    std::cin >> newtype;
    std::cout << "Quel est son power ?" << std::endl;
    std::cin >> newpower;

    name[4] = newname;
    type[4] = newtype;
    power[4] = newpower;

    std::cout << "Voici votre nouveau Pokemon : " << std::endl;
    std::cout << newname << std::endl;
    std::cout << newtype << std::endl;
    std::cout << newpower << std::endl;

    std::cout << "Resume de votre pokedex : " << std::endl;
    int i = 0;
    while (i < 5)
    {
        std::cout << "Pokemon numero " << i+1 << std::endl;
        std::cout << name[i] << std::endl;
        std::cout << type[i] << std::endl;
        std::cout << power[i] << std::endl;
        i++;
    }

}

int main()
{
    // Exercice 2 - 1 :

    //Exercice2Partie1();

    // Exercice 2 - 2 :

    // Exercice2Partie2();

    // Exercice 3 :

    //Exercice3();

    // Exercice 4 :

    //Exercice4();
}