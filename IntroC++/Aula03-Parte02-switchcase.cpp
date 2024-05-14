#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;


int main()
{
    int iValor = 42;
    // boa prática iniciar variável int como 0
    int iValorLido = 0;
    int iResultado = 0;
    
    cin >> iValorLido;
    
    iResultado = (iValorLido<iValor) ? 0 : 1;
    
    cout << "Resultado: " << iResultado << endl;
    
    int iDia = 1;
    
    // Ele roda tudo até achar um break
    // default: se nada acontecer acontece o que ta no default
    switch(iDia)
    {
        case 1:
            cout << "Segunda-Feira" << endl;
            break;
        case 2:
            cout << "Terça-Feira" << endl;
            break;
        case 3:
            cout << "Quarta-Feira" << endl;
            break;
        case 4:
            cout << "Quinta-Feira" << endl;
            break;
        default:
            cout << "Dia Locuo" << endl;
    }
    
    return 0;
}
