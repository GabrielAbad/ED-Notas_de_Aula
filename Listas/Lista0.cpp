#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

void DuracaoJogo(int, int);
void resolveEquacao2Grau(float, float, float);
void resolveEquacao2GrauMelhorada(float, float, float);

int main() {
    DuracaoJogo(0, 0);
    DuracaoJogo(10, 0);
    DuracaoJogo(0, 12);

    
    resolveEquacao2Grau(10.0, 20.1, 5.1);
    resolveEquacao2Grau(0.0, 20.0, 5.0);
    resolveEquacao2Grau(1.0, 4.0, 4.0);
    resolveEquacao2Grau(10.0, 3.0, 5.0);


    resolveEquacao2GrauMelhorada(10.0, 3.0, 5.0);

    return 0;
}

void DuracaoJogo(int iHoraInicial, int iHoraFinal) {
    int iDuracao = 0;
    if (iHoraFinal == 0) {
        iHoraFinal = 24;
        iDuracao = iHoraFinal - iHoraInicial;
        cout << "O JOGO DUROU " << iDuracao << " HORA(S)" << endl;
    }
    else if (iHoraFinal < iHoraInicial) {
        iHoraInicial = 24 - iHoraInicial;
        iDuracao = iHoraFinal + iHoraInicial;
        cout << "O JOGO DUROU " << iDuracao << " HORA(S)" << endl;
    }
    else {
        iDuracao = iHoraFinal - iHoraInicial;
        cout << "O JOGO DUROU " << iDuracao << " HORA(S)" << endl;
    }
}

void resolveEquacao2Grau(float a, float b, float c)
{
    float r1;
    float r2;
    float delta = b * b - 4 * a * c;
    if (a==0) cout << "Impossivel calcular" << endl;
    
    else if (delta < 0)
    {
        cout << "Impossivel calcular" << endl;
    }
    
    else if (delta == 0)
    {
        r1 = (-b + pow(delta, 0.5)) / (2 * a);
        cout << "R1 = " << r1 << endl;
    }
    
    else
    {
        r1 = (-b + pow(delta, 0.5)) / (2 * a);
        r2 = (-b - pow(delta, 0.5)) / (2 * a);
        cout << "R1 = " << r1 << endl;
        cout << "R2 = " << r2 << endl;
    }
}

void resolveEquacao2GrauMelhorada(float a, float b, float c)
{
    float fParteReal;
    float fParteComplexa;
    float fDelta;
    fDelta = b*b - 4*a*c;
    if (b*b - 4*a*c < 0)
    {
        fParteReal = -b/(2*a);
        fParteComplexa = pow(-fDelta,0.5)/(2*a);
        cout << "R1 = " << fParteReal << " + " << fParteComplexa << "i" << endl;
        cout << "R2 = " << fParteReal << " + " << -fParteComplexa << "i" << endl;
    }
}