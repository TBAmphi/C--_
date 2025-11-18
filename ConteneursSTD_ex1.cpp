#include <iostream>
#include <cstdlib>
#include <list>
#include <string>

void Find_IN(std::list<std::string> nains);
void FindLastLongest(std::list<std::string> nains);

int main()
{
    std::list<std::string> nains = {"Balin","Bifur","Bofur","Bombur","Dori","Dwalin","Fili","Gloin","Kili","Nori","Oin","Ori","Thorin","Bilbo"};

    nains.pop_back();

    Find_IN(nains);

    FindLastLongest(nains);

    return 0;
}

void Find_IN(std::list<std::string> nains)
{
    std::list<std::string>::iterator it = nains.begin();
    while(it != nains.end())
    {
        std::string current = *it;
        if(current.substr(current.size() - 2) == "in")
        {
            std::cout << current << std::endl;
        }
        it++;
    }
}

void FindLastLongest(std::list<std::string> nains)
{
    std::list<std::string> longest;
    std::string current = "";
    for(const auto name : nains)
    {
        if(name.size() >= current.size())
        {
            if(name.size() != current.size())
            {
                longest.clear();
            }
            longest.push_back(name);
            current = name;
        }
    }
    std::cout << "Le dernier nain avec le nom le plus long est : " << longest.back() << std::endl;
}