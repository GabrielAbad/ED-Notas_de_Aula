#include <iostream>

using std::cout;
using std::endl;
using std::string;

void troca(int,int);
void trocaCorreta(int&, int&);
int& trocaElemento(int,int[]);

int main()
{
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl; 
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor<< endl;
    cout << "============================================" << endl;

    
    // variavel que cria uma referência para uma variável que já existe
    string& strrefNome = strNome;
    int& irefValor = iValor;
    //int& irefValorFuturo = iValorFuturo;
    
    cout << "Valor da RefString: " << strrefNome << ". Endereço da RefString: " << &strrefNome << endl; 
    cout << "Valor do RefInteiro: " << irefValor << ". Endereço do RefInteiro: " << &irefValor<< endl;
    cout << "============================================" << endl;
    
    // se eu mudar a ref, vai mudar a variavel que ela se refere
    strrefNome = "C. Camacho";
    irefValor = iValorFuturo;
    //irefValor = irefValorFuturo;
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl; 
    cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor<< endl;
    cout << "============================================" << endl;
    
    int iNum1 = 7;
    int iNum2 = 42;
    
    
    cout << "iNum1: " << iNum1 <<endl;
    cout << "iNum2: " << iNum2 <<endl;
    troca(iNum1,iNum2);
    cout << "iNum1: " << iNum1 <<endl;
    cout << "iNum2: " << iNum2 <<endl;
    cout << "============================================" << endl;

    int& irefNum1 = iNum1;
    int& irefNum2 = iNum2;
    cout << "iNum1: " << iNum1 <<endl;
    cout << "iNum2: " << iNum2 <<endl;
    trocaCorreta(irefNum1,irefNum2);
    cout << "iNum1: " << iNum1 <<endl;
    cout << "iNum2: " << iNum2 <<endl;
    cout << "============================================" << endl;
    
    int arriVetor[5] = {0,7,13,42,666};
    for(int i =0; i<5; i++)
    {
        cout << "Vetor[" << i << "]" << arriVetor[i] << endl;
    }
    cout << "----" <<endl;
    trocaElemento(4,arriVetor) = 111;
    for(int i =0; i<5; i++)
    {
        cout << "Vetor[" << i << "]" << arriVetor[i] << endl;
    }
    
    return 0;
}

// Porque não funciona? R: Só em tempo de execução isso acontece
void troca(int iValor1, int iValor2)
{
    int iTemp = iValor1;
    iValor1 = iValor2;
    iValor2 = iTemp;
}

void trocaCorreta(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
}

// a função retorna uma referencia então pode mudar o valor da variavel que ela se referece
int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}



















