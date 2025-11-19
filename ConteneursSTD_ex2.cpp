#include <iostream>
#include <cstdlib>
#include <map>

void FindInList(std::map<std::string, int> animaux, std::string animalName);
void NbPattesFinder(std::map<std::string, int> animaux, int nbPattes);

int main()
{
    std::map<std::string, int> animaux
    {
        {"Chat", 4},
        {"Humain", 2},
        {"Araignee", 8},
        {"Chien", 4},
        {"Dodo", 2},
        {"Mouton", 4},
        {"Serpent", 0},
    };

    FindInList(animaux, "Chien");
    FindInList(animaux, "Licorne");

    FindInList(animaux, "Dodo");
    animaux.erase("Dodo");
    FindInList(animaux, "Dodo");

    FindInList(animaux, "Mouton");
    animaux["Mouton"] = 5;
    FindInList(animaux, "Mouton");

    NbPattesFinder(animaux, 4);
}

void FindInList(std::map<std::string, int> animaux, std::string animalName)
{
    std::map<std::string, int>::iterator found = animaux.find(animalName);
    if (found != animaux.end()) 
    {
        std::cout << "Animal : " << (*found).first << std::endl;
        std::cout << "Nombre de pattes : " << (*found).second << "\n" << std::endl;
    }
}

void NbPattesFinder(std::map<std::string, int> animaux, int nbPattes)
{
    std::cout << "Voici les animaux a " << nbPattes << " pattes qui se trouvent dans la liste :" << std::endl;
    std::map<std::string, int>::iterator it = animaux.begin();
    while(it != animaux.end())
    {
        if((*it).second == nbPattes)
        {
            std::cout << (*it).first << std::endl;
        }
        it++;
    }
}