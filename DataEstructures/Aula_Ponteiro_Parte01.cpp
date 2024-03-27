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
    int* ptrInt = NULL;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "===========================" << endl;
    
    int iNumMagico = 42;
    cout << "Endereço de iNumMagico: " << &iNumMagico << endl;
    
    // Ponteiro recebe um endereço como conteúdo
    ptrInt = &iNumMagico;
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "Conteudo de iNumMagico: " << *ptrInt << endl;
    cout << "===========================" << endl;
    
    int iNumSagrado = 7;
    cout << "Endereço de iNumSagrado: " << &iNumSagrado << endl;
    
    ptrInt = &iNumSagrado;
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "Conteudo de iNumSagrado: " << *ptrInt << endl;
    cout << "===========================" << endl;
    
    return 0;
}

