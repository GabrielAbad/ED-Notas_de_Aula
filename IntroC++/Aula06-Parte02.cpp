#include <iostream>

using std::cout;
using std::endl;
using std::string;



int main()
{
    
    enum Streaming{AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};
    
    Streaming streamingSubscription = CrunchyRoll;
    
    switch (streamingSubscription)
    {
        case AppleTV:
            cout << "Nunca usei.. não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
            cout << "NADA" << endl;
    }
    
    cout << "============================================" << endl;
    
    enum Mes {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    Mes mesProvas = MAIO;
    cout << mesProvas << endl;
    
    enum Semana {Segunda =10, Terca = 1, Quarta = -3};
    
    Semana diaPalestra = Quarta;
    cout << Quarta << endl;
    
    return 0;
}




















