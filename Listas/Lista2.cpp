#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int achaQtdDeUns(int);
int achaSobrevivente(int);
int achaSobreviventeMelhorado(int, int);

int main()
{
    /*int iNum;
    cin >> iNum;
    cout << achaQtdDeUns(iNum) << endl;*/

    cout << "===========================" << endl;

    cout << achaSobrevivente(5)<< endl;
    cout << achaSobrevivente(11)<< endl;
    cout << achaSobrevivente(7)<< endl;

    cout << "===========================" << endl;
    cout << achaSobreviventeMelhorado(5,2)<< endl;
    cout << achaSobreviventeMelhorado(6,3)<< endl;
    cout << achaSobreviventeMelhorado(1234,233)<< endl;

}


int achaQtdDeUns(int iNum)
{
    // Verifica se iNum é divisível por 2 ou por 5
    if (iNum % 5 == 0 || iNum % 2 == 0)
    {
        cout << "Numero divisivel por 5 ou por 2" << endl;
        return 0;
    }

    // Aplicando o Teorema de Fermat para números primos como iNum
    int count = 1;
    long long int p = 1;
    while (p % iNum != 0)
    {
        p = (p * 10 + 1) % iNum;
        count++;
    }

    return count;
}

int achaSobrevivente(int iQtdSoldados)
{
    if (iQtdSoldados == 1)
    {
        return 1; 
    }
    else
    {

        return (achaSobrevivente(iQtdSoldados - 1) + 1) % iQtdSoldados + 1;
    }
}

int achaSobreviventeMelhorado(int iQtdSoldados, int k)
{
    if (iQtdSoldados == 1)
    {
        return 1; 
    }
    else
    {

        return (achaSobreviventeMelhorado(iQtdSoldados - 1,k) + (k-1)) % iQtdSoldados + 1;
    }
}