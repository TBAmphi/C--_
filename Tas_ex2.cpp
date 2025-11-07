#include <iostream>
#include <cstdlib>

float* AllocateSquare(float f)
{
    float *square = new float;
    *square = f*f;
    return square;
}

int main()
{
    float* ptrfloat = AllocateSquare(5);

    std::cout << ptrfloat << std::endl;
    std::cout << *ptrfloat << std::endl;

    *ptrfloat *= 2;
    std::cout << *ptrfloat << std::endl;
    
    delete ptrfloat;
}