#include <iostream>
#include <cstdint>

void Func1(int a) 
{
    printf("Func1 - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
}
void Func2(int &a) {
    printf("Func2 - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
}
void Func3(int *tab) {
    printf("Func3 - id: tab, value:%d, address:%x, size:%d\n", tab[0], &(tab[0]),

    sizeof(tab[0]));
}

int main()
{
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    printf("main - id: a, value:%d, address:%x, size:%d\n", a, &a, sizeof(a));
    printf("main - id: b, value:%d, address:%x, size:%d\n", b, &b, sizeof(b));
    printf("main - id: c, value:%d, address:%x, size:%d\n", c, &c, sizeof(c));
    printf("main - id: d, value:%d, address:%x, size:%d\n", d, &d, sizeof(d));
    // Ces lignes affiche dans le terminal l'id, la valeur, l'adresse, et la taille d'une variable (ici : a).



    printf("a->b address position difference:%td\n", (intptr_t)&a - (intptr_t)&b);
    printf("b->c address position difference:%td\n", (intptr_t)&b - (intptr_t)&c);
    printf("c->d address position difference:%td\n", (intptr_t)&c - (intptr_t)&d);
    // ici on compare l'adresse des variables, qui sont à 4 octets d'interval.

    Func1(a);
    // La fonction 1 fait la même chose que la première ligne, mais elle a une addresse différente.

    int &e = a;
    printf("main - id: e, value:%d, address:%x, size:%d\n", e, &e, sizeof(e));
    // Ici on pointe a, cette ligne a donc le même effet que la toute primière, et renvoie la même addresse.

    Func2(a);
    // La fonction 2 prend a en ref et fait donc la même chose que la première ligne.

    int tab[2] = {5,10};
    printf("main - id: tab, value:%x, address:%x, size:%d\n", tab, &(tab), sizeof(tab));
    // Ici on a un tableau avec sa valeur, son addresse, et sa taille ici 8 octets car il contient 2 int.

    printf("main - id: tab[0], value:%d, address:%x, size:%d\n", tab[0], &(tab[0]),
    sizeof(tab[0]));
    printf("main - id: *(tab), value:%d, address:%x, size:%d\n", *tab, tab,
    sizeof(*tab));
    // Ces 2 lignes ont pour effet de donner les informations relatives a la première valeur du tableau.

    printf("main - id: tab[1], value:%d, address:%x, size:%d\n", tab[1], &(tab[1]),
    sizeof(tab[1]));
    printf("main - id: *(tab + 1), value:%d, address:%x, size:%d\n", *(tab + 1), tab + 1,
    sizeof(*(tab + 1)));
    // Pareil mais avec +1 on va chercher la valeur suivante.

    int *ptab = tab;
    printf("main - id: ptab[0], value:%d, address:%x, size:%d\n", ptab[0], &(ptab[0]),
    sizeof(ptab[0]));
    // Le pointeur redirige vers la première valeur du tab.

    Func3(tab);
    // Prend en ref la première valeur du tableau.
}