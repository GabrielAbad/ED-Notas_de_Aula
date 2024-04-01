#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

// temas
// ponteiros são resetaveis
// como atribuir um valor a um ponteiro


int main() 
{
    // o nome do vetor é o mesmo que o endereço do primeiro elemento
    int arriValores[5] = {0,7,13,42,666};
    cout << "Endereço de [0]: " << arriValores << endl;
    
    int* ptrArrayValores1 = arriValores;
    cout << "PTR1: " << ptrArrayValores1 << endl;
    
    int* ptrArrayValores2 = &arriValores[0];
    cout << "PTR2: " << ptrArrayValores2 << endl;
    
    cout << "==============================" << endl;
    
    cout << "Valor de ptrArrayValores1[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[0]: " << ptrArrayValores1 << endl;
    
    // somando 4 bytes no endereço 
    ptrArrayValores1++;
    cout << "Valor de ptrArrayValores1[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[1]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1+=3;
    cout << "Valor de ptrArrayValores1[4]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[4]: " << ptrArrayValores1 << endl;

    cout << "Subtração de Ponteiros: " << ptrArrayValores1 - ptrArrayValores2;
    
    return 0;
}











































