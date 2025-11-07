#include <iostream>
#include <cstdlib>

int main()
{
    int a = 5;
    int *pa = &a;
    int b = 10;
    int *pb =&b;

    int *pc = nullptr;

    std::cout << "a = " << a << " b = " << b << " pa = " << pa << " pb = " << pb << " *pa = " << *pa << " *pb = " << *pb << std::endl;

    pc = pa;
    pa = pb;
    pb = pc;

    std::cout << "a = " << a << " b = " << b << " pa = " << pa << " pb = " << pb << " *pa = " << *pa << " *pb = " << *pb << " pc = " << pc << " *pc = " << *pc << std::endl;
}