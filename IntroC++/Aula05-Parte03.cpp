#include <iostream>

using std::cout;
using std::endl;

// cada funcao tem uma assinatura, ex: soma(int,int) é uma assinatura
int soma(int iValor1, int iValor2)
{
    return iValor1 + iValor2;
}

// mesmo nome mas assinatura diferente
int soma(int iValor1, int iValor2, int iValor3)
{
    return iValor1 + iValor2 + iValor3;
}


int main()
{
    
    int iValor1 = 10;
    int iValor2 = 20;
    int iValor3 = 30;
    cout << soma(iValor1,iValor2) << endl;
    cout << soma(iValor1,iValor2,iValor3) << endl;
    cout << "=====================" << endl;
    
    return 0;
}
