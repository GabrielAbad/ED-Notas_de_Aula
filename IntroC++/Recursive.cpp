#include <iostream>

using namespace std;

unsigned long long iterativeFactorial(unsigned int);
unsigned long long recursiveFactorial(unsigned int);

unsigned long long iterativeFibonnaci(unsigned int);
unsigned long long recursiveFibonnaci(unsigned int);

int main()
{
    unsigned int uiNumber = 1;
    
    cout << "Digite um numero inteiro positivo: ";
    
    cin >> uiNumber;
    
    cout << endl;
    
    cout << "Fatorial Iterativo de " << uiNumber << " eh: " << iterativeFactorial(uiNumber) << endl;
    
    cout << "Fatorial Recursivo de " << uiNumber << " eh: " << recursiveFactorial(uiNumber) << endl;
    
    cout << "Digite um numero inteiro positivo: ";
    
    cin >> uiNumber;
    
    cout << endl;
    
    cout << "Fibonnaci Iterativo de " << uiNumber << " eh: " << iterativeFibonnaci(uiNumber) << endl;
    
    cout << "Fibonnaci Recursivo de " << uiNumber << " eh: " << recursiveFibonnaci(uiNumber) << endl;
    
    return 0;
}


unsigned long long iterativeFactorial(unsigned int uiNumber)
{
    unsigned long long ullResult = 1;
    for(int i = 1; i <= uiNumber; i++)
    {
        ullResult*=i;
    }
    return ullResult;
}

unsigned long long recursiveFactorial(unsigned int uiNumber)
{
    if(uiNumber <= 1) return 1;
    return uiNumber * recursiveFactorial(uiNumber - 1);
}

unsigned long long iterativeFibonnaci(unsigned int uiNumber)
{
    if (uiNumber == 0) return 0;
    if (uiNumber == 1) return 1;
    
    unsigned long long ullPrevious = 0;
    unsigned long long ullCurrent = 1;
    unsigned long long ullNext = 1;
    
    for(int i = 2; i <= uiNumber; i++)
    {
        ullNext = ullCurrent + ullPrevious;
        ullPrevious = ullCurrent;
        ullCurrent = ullNext;
    }
    
    return ullCurrent;
}

unsigned long long recursiveFibonnaci(unsigned int uiNumber)
{
    if (uiNumber == 0) return 0;
    if (uiNumber == 1) return 1;
    
    return recursiveFibonnaci(uiNumber - 1) + recursiveFibonnaci(uiNumber - 2);
}




