#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void printArray(int [], int);
void operarArrays(int [], int [], char, int);
int jogoPedraPapelTesouraLagartoSpock(string, string);
void jogar(char [], int, char);

int main()
{
    /*int a[] = {1,1,2,3,5,8,13};
    printArray(a,7);
    cout << endl;
    cout << "=================" << endl;

    int b[] = {2, 4, 1, 2, 3};
    int c[] = {1, 2, 3, 4, 5};
    printArray(c,5);
    cout << endl;
    printArray(b,5);
    cout << endl;
    operarArrays(c,b,'+',5);
    printArray(c,5);
    cout << "=================" << endl;

    int iRodadas = 0;
    int iPontosJogador1 = 0;
    int iPontosJogador2 = 0;
    while(iRodadas<3)
    {
        string strJogadaJogador1;
        string strJogadaJogador2;
        cout << "Jogador 1 escolha: ";
        cin  >> strJogadaJogador1;
        cout << endl;
        cout << "Jogador 2 escolha: ";
        cin  >> strJogadaJogador2;
        
        int iResult = 0; 
        iResult = jogoPedraPapelTesouraLagartoSpock(strJogadaJogador1,strJogadaJogador2);
        if(iResult==0)
        {

        }
        else if(iResult==1)
        {
            iPontosJogador1+=1;
            iRodadas+=1;
        }
        else if(iResult==2)
        {
            iPontosJogador2+=1;
            iRodadas+=1;
        }
        cout << iPontosJogador1 << " " << iPontosJogador2 << endl;
    }
    if (iPontosJogador1 > iPontosJogador2)
    {
        cout << "Bazinga. O primeiro jogador ganhou.";
    }
    else
    {
        cout << "Bazinga. O segundo jogador ganhou.";
    }*/
    cout << "=================" << endl;

    char carrJogoVelha[9] = {'?','?','?','?','?','?','?','?','?'};
    bool bJogando = true;
    int iJogada = 1;
    while(bJogando)
    {
        int iPosicao;
        if(iJogada % 2 != 0)
        {
            cout << "Vez do X, qual posicao?" << endl << "Insira aqui: ";
            cin >> iPosicao;
            jogar(carrJogoVelha,iPosicao,'X');
        }
        else
        {
            cout << "Vez do O, qual posicao?" << endl << "Insira aqui: ";
            cin >> iPosicao;
            jogar(carrJogoVelha,iPosicao,'O');
        }
        
        iJogada+=1;
        string acabou;
        cout << "Acabou o jogo? (Responda sim ou nao) "<< endl << "Insira aqui: ";
        cin >> acabou;
        if(acabou=="sim")
        {
            bJogando = 0;
        }
        else if(acabou=="nao")
        {
            bJogando = 1;
        }
        else
        {
            cout << "Digitou errado, insira novamente." << endl << "Insira aqui: ";
            cin >> acabou;
        }    
    }
}


void printArray(int iArr[] , int iSize)
{
    cout << "{";
    for(int i =0; i < iSize-1; i++) cout << iArr[i] << ", ";
    cout << iArr[iSize-1];
    cout << "}";
}

void operarArrays(int iArr[], int iArrB[], char cOperator, int iSize)
{
    if (cOperator != '+' && cOperator != '-') 
    {
        cout << "Operação Inexistente" << endl;
    }
    else if (cOperator == '+')
    {
        for(int i = 0; i < iSize; i++)
        {
            iArr[i] = iArr[i] + iArrB[i];
        }
    }
    else
    {
        for(int i = 0; i < iSize; i++)
        {
            iArr[i] = iArr[i] - iArrB[i];
        }
    }
}

int jogoPedraPapelTesouraLagartoSpock(string strJogadaJogador1, string strJogadaJogador2)
{
    if (strJogadaJogador1 == strJogadaJogador2) 
    {
        return 0;
    }

    if ((strJogadaJogador1 == "tesoura" && (strJogadaJogador2 == "papel" || strJogadaJogador2 == "lagarto"))||
        (strJogadaJogador1 == "papel" && (strJogadaJogador2 == "pedra" || strJogadaJogador2 == "Spock"))||
        (strJogadaJogador1 == "pedra" && (strJogadaJogador2 == "tesoura" || strJogadaJogador2 == "lagarto"))||
        (strJogadaJogador1 == "lagarto" && (strJogadaJogador2 == "papel" || strJogadaJogador2 == "Spock"))||
        (strJogadaJogador1 == "Spock" && (strJogadaJogador2 == "pedra" || strJogadaJogador2 == "tesoura")))
        {
            return 1;
        }
    
    else
    {
        return 2;
    }
}

void jogar(char carrJogoVelha[9], int iPos, char cSimbolo)
{
    if(carrJogoVelha[iPos] == 'X' || carrJogoVelha[iPos] == 'O')
    {
        cout << "Jogada inválida" << endl;
        return;
    }
    
    carrJogoVelha[iPos] = cSimbolo;

    for(int i = 0; i < 9; i++)
    {
        if(i == 2 || i == 5 || i == 8)
            cout << carrJogoVelha[i] << endl;
        else
            cout << carrJogoVelha[i] << " ";
    }

    char vencedor = ' ';
    if (
        (carrJogoVelha[0] == carrJogoVelha[1] && carrJogoVelha[1] == carrJogoVelha[2] && carrJogoVelha[0] == 'X') ||
        (carrJogoVelha[3] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[5] && carrJogoVelha[3] == 'X') ||
        (carrJogoVelha[6] == carrJogoVelha[7] && carrJogoVelha[7] == carrJogoVelha[8] && carrJogoVelha[6] == 'X') ||
        (carrJogoVelha[0] == carrJogoVelha[3] && carrJogoVelha[3] == carrJogoVelha[6] && carrJogoVelha[0] == 'X') ||
        (carrJogoVelha[1] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[7] && carrJogoVelha[1] == 'X') ||
        (carrJogoVelha[2] == carrJogoVelha[5] && carrJogoVelha[5] == carrJogoVelha[8] && carrJogoVelha[2] == 'X') ||
        (carrJogoVelha[0] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[8] && carrJogoVelha[0] == 'X') ||
        (carrJogoVelha[2] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[6] && carrJogoVelha[2] == 'X')
    )
    {
        vencedor = 'X';
    }
    else if (
        (carrJogoVelha[0] == carrJogoVelha[1] && carrJogoVelha[1] == carrJogoVelha[2] && carrJogoVelha[0] == 'O') ||
        (carrJogoVelha[3] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[5] && carrJogoVelha[3] == 'O') ||
        (carrJogoVelha[6] == carrJogoVelha[7] && carrJogoVelha[7] == carrJogoVelha[8] && carrJogoVelha[6] == 'O') ||
        (carrJogoVelha[0] == carrJogoVelha[3] && carrJogoVelha[3] == carrJogoVelha[6] && carrJogoVelha[0] == 'O') ||
        (carrJogoVelha[1] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[7] && carrJogoVelha[1] == 'O') ||
        (carrJogoVelha[2] == carrJogoVelha[5] && carrJogoVelha[5] == carrJogoVelha[8] && carrJogoVelha[2] == 'O') ||
        (carrJogoVelha[0] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[8] && carrJogoVelha[0] == 'O') ||
        (carrJogoVelha[2] == carrJogoVelha[4] && carrJogoVelha[4] == carrJogoVelha[6] && carrJogoVelha[2] == 'O')
    )
    {
        vencedor = 'O';
    }

    if (vencedor != ' ')
    {
        cout << "Parabéns! O jogador " << vencedor << " venceu." << endl;
    }
}