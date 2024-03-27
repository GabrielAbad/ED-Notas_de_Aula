#include <iostream>
using std::cout;
using std::endl;

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

int main() {
    DuracaoJogo(0, 0);
    DuracaoJogo(10, 0);
    DuracaoJogo(0, 12);

    return 0;
}

