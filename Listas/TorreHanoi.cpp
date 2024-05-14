#include <iostream>

using std::cout;
using std::endl;

typedef struct Disco
{
    int iTamanho;
    Disco* ptrLow;
} Disco;

typedef struct Pino
{
    Disco* ptrTopo;
} Pino;

Pino* newPino();
Disco* newDisco(int);
void moveDisco(Pino* const, Pino* const);
void push(Pino* const, int);
void printPino(Pino* const);

int main()
{
    Pino* pinoA = newPino();
    Pino* pinoB = newPino();
    Pino* pinoC = newPino();
    push(pinoA, 5);
    push(pinoA, 4);
    push(pinoA, 3);
    push(pinoA, 2);
    push(pinoA, 1);
    printPino(pinoA);
    printPino(pinoB);
    printPino(pinoC);
    cout << "===================" << endl;
    moveDisco(pinoA,pinoB);
    printPino(pinoA);
    printPino(pinoB);
    printPino(pinoC);

    return 0;
}

Disco* newDisco(int iTamanho)
{
    Disco* temp = (Disco*) malloc(sizeof(Disco));
    temp->iTamanho = iTamanho;
    temp->ptrLow = nullptr;
    return temp;
}

Pino* newPino()
{
    Pino* temp = (Pino*) malloc(sizeof(Pino));
    temp->ptrTopo = nullptr;
    return temp;
}

void moveDisco(Pino* const pino1, Pino* const pino2)
{
    // Verifica se o pino de destino está vazio ou se o disco no topo de pino1 é menor que o disco no topo de pino2
    if (pino2->ptrTopo == nullptr || pino1->ptrTopo->iTamanho < pino2->ptrTopo->iTamanho)
    {
        Disco* temp = pino1->ptrTopo;
        pino1->ptrTopo = pino1->ptrTopo->ptrLow;
        temp->ptrLow = pino2->ptrTopo;
        pino2->ptrTopo = temp;
        
        return;
    }
    
    else
    {
        cout << "Movimentacao invalida, tamanho do disco deve ser menor que o do topo." << endl;
        return;
    }
}


void push(Pino* const pino, int iTamanho)
{
    Disco* temp = newDisco(iTamanho);
    temp->ptrLow = pino->ptrTopo;
    pino->ptrTopo = temp;
}

void printPino(Pino* const pino)
{
    if(pino->ptrTopo == nullptr)
    {
        cout << "Pino nao tem discos." << endl;
        return;
    }

    Disco* current = pino->ptrTopo;
    while(current)
    {
        cout << current->iTamanho << " ";
        current = current->ptrLow;
    }
    cout << endl;
}