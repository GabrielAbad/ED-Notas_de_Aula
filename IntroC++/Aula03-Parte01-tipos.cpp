#include <iostream>
using std::cout;
using std::endl;
using std::string;

// Declarando tipos: int, short, long, long long, float, double, long double, string, unsigned


int main()
{
    // -2,147,483,648 até 2,147,483,647
    // 4 bytes
    int iNum1 = 42; 
    int iNum2 = 0;
    int iNum3 = 17; // Não faça isso!
    
    cout << "iNum1: " << iNum1 << "\nTamanho de iNum1: " << sizeof(iNum1) << endl;
    cout << "iNum2: " << iNum2 << "\nTamanho de iNum2: " << sizeof(iNum2) << endl;
    cout << "iNum3: " << iNum3 << "\nTamanho de iNum3: " << sizeof(iNum3) << endl;
    
    // -32,768 a 32,767
    // 2 bytes
    // Inteiro pequeno, ocupa menos espaço
    short sNum = 17;
    cout << "sNum: " << sNum << "\nTamanho de sNum: " << sizeof(sNum) << endl;
    
    // ?
    // 8 bytes
    // Inteiro longo, ocupa mais espaço
    long lNum = 17;
    cout << "lNum: " << lNum << "\nTamanho de lNum: " << sizeof(lNum) << endl;
    
    // ?
    // 8, 12 ou 16 bytes
    long long llNum = 17;
    cout << "llNum: " << llNum << "\nTamanho de llNum: " << sizeof(llNum) << endl;
    
    float fNum = 42.123456789;
    double dNum = 42.123456789;
    long double ldNum = 42.123456789;
    
    cout << "fNum: " << fNum << "\nTamanho de fNum: " << sizeof(fNum) << endl;
    cout << "dNum: " << dNum << "\nTamanho de dNum: " << sizeof(dNum) << endl;
    cout << "ldNum: " << ldNum << "\nTamanho de ldNum: " << sizeof(ldNum) << endl;
    
    char cValue = 'E';
    cout << "cValue: " << cValue << "\nTamanho de cValue: " << sizeof(cValue) << endl;
    // Da pra converter o char pra int , porque o char 'E' é representado como um número na tabela ASCII
    cout << "int(cValue): " << int(cValue) << endl;
    
    char cPalavraPreferida_1 = 77;
    // declarar hexadecimal deve colocar 0x na frente
    char cPalavraPreferida_2 = 0x41;
    // declarando um binario deve colocar 0b na frente 
    char cPalavraPreferida_3 = 0b1110000;
    
    // Porque printa EMAp? R: O compilador passa tudo pra binario e ve o caractere correspondente na tabela ASCi
    // pois foi declarado como char
    cout << cValue;
    cout << cPalavraPreferida_1;
    cout << cPalavraPreferida_2;
    cout << cPalavraPreferida_3;
    
    string strValue_1 = "Eu adoro a";
    string strValue_2 = "EMAp";
    
    cout << "strValue_1: " << strValue_1 << "\nTamanho de strValue_1: " << sizeof(strValue_1) << endl;
    cout << "strValue_2: " << strValue_2 << "\nTamanho de strValue_2: " << sizeof(strValue_2) << endl;
    
    // 0 é falso e o resto é true se voce declarar como bool a variavel
    bool bValue_1 = true;
    bool bValue_2 = false;
    bool bValue_3 = 42;
    bool bValue_4 = 0;
    
    cout << "bValue_1: " << bValue_1 << "\nTamanho de bValue_1: " << sizeof(bValue_1) << endl;
    cout << "bValue_2: " << bValue_2 << "\nTamanho de bValue_2: " << sizeof(bValue_2) << endl;
    cout << "bValue_3: " << bValue_3 << "\nTamanho de bValue_3: " << sizeof(bValue_3) << endl;
    cout << "bValue_4: " << bValue_4 << "\nTamanho de bValue_4: " << sizeof(bValue_4) << endl;
    
    const int iNUMERO = 42;
    cout << "iNUMERO: " << iNUMERO << "\nTamanho de iNUMERO: " << sizeof(iNUMERO) << endl;
    
    // o unsigned diz para nao ter numero negativo
    unsigned short usNum = 42;
    cout << "usNum: " << usNum << "\nTamanho de usNum: " << sizeof(usNum) << endl;
    
    unsigned long long int ulliNum_1 = 42;
    cout << "ulliNum_1: " << ulliNum_1 << "\nTamanho de ulliNum_1: " << sizeof(ulliNum_1) << endl;
       
}