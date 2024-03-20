#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//UDT - user defined types: pilhas, listas, filas

int main()
{
    struct
    {
        // essa struct tem 2 mebros de dados
        int iIdade;
        string strNome;
    } alunoEMAp; // criando um tipo novo e anônimo
    
    alunoEMAp.iIdade = 18;
    alunoEMAp.strNome = "Ana";
    
    cout << "Idade do alunoEMAp: " << alunoEMAp.iIdade << endl;
    cout << "Nome do alunoEMAp: " << alunoEMAp.strNome << endl;
    
    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp1, alunoEMAp2;
    
    alunoEMAp1.iIdade = 20;
    alunoEMAp1.strNome = "Antonio";
    
    cout << "Idade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    alunoEMAp2.iIdade = 17;
    alunoEMAp2.strNome = "Henzo";
    
    cout << "Idade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;
    
    return 0;
}