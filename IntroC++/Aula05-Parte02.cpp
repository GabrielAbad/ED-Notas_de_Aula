#include <iostream>

using std::cout;
using std::endl;

void minhaFuncao(int arriNumeros[], int iTamanhoVetor)
{
    for(int i =0; i<iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl;
    }
    
}


int main()
{
    
    int arriVetorTeste[5] = {0,7,13,42,666};
    int iTamanhoVetor = sizeof(arriVetorTeste)/sizeof(arriVetorTeste[0]);
    cout << sizeof(arriVetorTeste)<< endl;
    cout << sizeof(arriVetorTeste[0])<< endl;
    cout << iTamanhoVetor <<endl;
    minhaFuncao(arriVetorTeste, iTamanhoVetor);
    
    cout << "=====================" << endl;
    
    return 0;
}
