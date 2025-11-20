#include <iostream>
#include <cstdlib>
#include <list>

// Declarations
struct Element;
struct List;
List* CreateList();
Element* GetElementAt(List* liste, int pos);
void AddElement(List* liste, char valeur);
void RemoveElementAt(List* liste, int pos);
void DestroyList(List* liste);

struct Element
{
    Element* previous;
    Element* next;
    char value;
};

struct List
{
    Element* first;
    int count;
};

int main()
{
    List* liste = CreateList();

    //char valeur = '1';
    AddElement(liste, 'A');
    AddElement(liste, 'B');
    AddElement(liste, 'C');
    AddElement(liste, 'D');
    //int nbElements = 0;
    std::cout << GetElementAt(liste, 0)->value << std::endl;
    std::cout << GetElementAt(liste, 1)->value << std::endl;
    std::cout << GetElementAt(liste, 2)->value << std::endl;
    std::cout << GetElementAt(liste, 3)->value << std::endl;
    std::cout << std::endl;

    RemoveElementAt(liste, 1);

    std::cout << GetElementAt(liste, 0)->value << std::endl;
    std::cout << GetElementAt(liste, 1)->value << std::endl;
    std::cout << GetElementAt(liste, 2)->value << std::endl;
    std::cout << std::endl;

    RemoveElementAt(liste, 0);

    std::cout << GetElementAt(liste, 0)->value << std::endl;
    std::cout << GetElementAt(liste, 1)->value << std::endl;
    std::cout << std::endl;

    RemoveElementAt(liste, 1);

    std::cout << GetElementAt(liste, 0)->value << std::endl;

    DestroyList(liste);
    //std::cout << GetElementAt(liste, 0)->value << std::endl;
    //std::cout << GetElementAt(liste, 1)->value << std::endl;

}

List* CreateList()
{
    List* liste = new List{nullptr, 0};
    return liste;
}

Element* GetElementAt(List* liste, int pos)
{
    if(pos < 0 || pos >= liste->count)
    {
        return nullptr;
    }
    Element* searchedElement = liste->first;
    for(int i = 0; i < pos; i++)
    {
        searchedElement = searchedElement->next;
    }
    return searchedElement;
}

void AddElement(List* liste, char valeur)
{
    Element* element = new Element{nullptr, nullptr, valeur};
    if(liste->first == nullptr)
    {
        liste->first = element;
        element->previous = nullptr;
    }
    else if(liste->first != nullptr)
    {
        Element* last = GetElementAt(liste, liste->count - 1);
        last->next = element;
        element->previous = last;
    }
    liste->count += 1;
}

void RemoveElementAt(List* liste, int pos)
{
    Element* element = GetElementAt(liste, pos);
    if(element == nullptr)
    {
        return;
    }

    Element* previousElement = element->previous;
    Element* nextElement = element->next;

    if(previousElement == nullptr)
    {
        liste->first = nextElement;
    }
    else
    {
        previousElement->next = nextElement;
    }
    if(nextElement != nullptr)
    {
        nextElement->previous = previousElement;
    }

    delete element;
    liste->count -= 1;
}

void DestroyList(List* liste)
{
    /*for(int i = 0; i < liste->count; i++)
    {
        RemoveElementAt(liste, i);
    }
    delete liste;*/
    Element* current = liste->first;
    while(current != nullptr)
    {
        Element* next = current->next;
        delete current;
        current = next;
    }
    delete liste;
}