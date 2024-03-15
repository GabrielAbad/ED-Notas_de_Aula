#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void frasePreferida()
{
    cout << "Eu adoro a EMAp" << endl;
}

void montaFrase(char chArtigo, string strPalavra)
{
    cout << "Eu adoro" << " "<< chArtigo << " " << strPalavra << "!" << endl;
}

// da pra definir um argumento como padrao
void montaFrasePadrao(char chArtigo = 'a', string strPalavra = "EMAp")
{
    cout << "Eu adoro"<< " " << chArtigo << " " << strPalavra << "!" << endl;
}

int potenciacao(int iBase, int iExpoente)
{
    return pow(iBase, iExpoente);
}

float modulo(float iValor)
{
    return fabs(iValor);
}

int main()
{
    frasePreferida();
    frasePreferida();
    frasePreferida();
    
    cout << "=====================" << endl;
    
    // char tem que ser aspas simples, string tem que ser aspas duplas
    montaFrase('a', "EMAp");
    montaFrase('o', "Yuri");
    
    cout << "=====================" << endl;
    
    montaFrasePadrao();
    montaFrasePadrao('a');
    montaFrasePadrao('o', "Yuri");
    
    cout << "=====================" << endl;
    
    cout << "potenciacao(2,10)" << potenciacao(2,10) << endl;
    cout << "potenciacao(3,5)" << potenciacao(3,5) << endl;
    
    cout << "=====================" << endl;
    
    cout << "modulo(2)" << modulo(2) << endl;
    cout << "modulo(-2)" << modulo(-2) << endl;
    cout << "modulo(-2.7)" << modulo(-2.7) << endl;
    
    cout << "=====================" << endl;
    
    return 0;
}
