#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void agendaSemana(int);

int main()
{
    int iDia =0;
    cin >> iDia;
    agendaSemana(iDia);
}

// 1 - para segunda, 2 - para terça, ... , 5 - para sexta
void agendaSemana(int iDia)
{
    switch (iDia)
    {
    case 1:
        cout <<  "7:30 Estrutura de Dados" << endl << "9:20 - Probabilidade" << endl << "11:10 - Calculo Vetorial";
        break;
    case 2:
        cout <<  "7:30 Livre" << endl << "9:20 - ALN" << endl << "11:10 - TACD";
        break;
    default:
        cout << "Invalid day" << endl;
    }
}
