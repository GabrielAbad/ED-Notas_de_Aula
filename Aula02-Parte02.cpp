#include <iostream>

using std::cout;
using std::endl;

// Hungarian Notation. Systems Hunagrian x Apps. Hungarian

int main()
{
    int iNum = 1;
    
    cout << "Valor de Num: " << iNum << endl;
    // &nomedevar vai retornar o endereço em hexadecimal da variável
    cout << "Endereco de Num: " << &iNum << endl;
    
    iNum = 111;
    
    cout << "Valor de Num: " << iNum << endl;
    cout << "Endereco de Num: " << &iNum << endl;
    
    return 0;
}
