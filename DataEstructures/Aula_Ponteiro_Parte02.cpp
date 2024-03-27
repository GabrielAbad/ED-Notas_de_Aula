#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

// temas
// ponteiros são resetaveis
// como atribuir um valor a um ponteiro

int square(int*);
int somaVetor(const int[], const size_t);

int main() 
{
    int iNum1 = 42;
    int iNum2 = 666;
    
    // Ponteiro constante para inteiro
    int* const ptrNum1 = &iNum1;
    // altera o apontado
    *ptrNum1 = 7;
    // ERRO
    // ptrNum1 = &iNum2;
    
    // Ponteiro para inteiro constante
    const int* ptrNum2 = &iNum1;
    // altera o ponteiro
    ptrNum2 = &iNum2;
    // ERRO
    // *ptrNum2 = 7;
    
    //Ponteiro constante para inteiro constante
    const int* const ptrNum3 = &iNum1;
    // ERRO
    //ptrNum3 = &iNum2;
    //*ptrNum3 = 7;
    
    
    
    cout << "==============================" << endl;
    
    cout << "Quadrado " << square(&iNum1) << endl;
    
    int arriValores[3] = {0,1,2};
    
    cout << "somaVetor " << somaVetor(arriValores, 3) << endl;
    return 0;
}



int square(int* ptrNum)
{
    return *ptrNum * *ptrNum;
}

int somaVetor(const int* valores,const size_t tamVetor)
{
    return -1;
}









































