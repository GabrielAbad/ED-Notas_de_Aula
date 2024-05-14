#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int x[100] = {0};
    cout << " x[0] = " << x[0] << ", endereço: " << &x[0] << endl;
    cout << " x[1] = " << x[1] << ", endereço: " << &x[1] << endl;
    cout << " x[99] = " << x[99] << ", endereço: " << &x[99] << endl;
    cout << "Len de x = " << sizeof(x)/sizeof(x[0]) << endl;
    // endereço de x[1] feito artesanalmente
    cout << &x[0] + 1 << endl;
    cout << "------------------------------------------" << endl;
    
    int array[4];
    
    array[0] = 8;
    array[1] = 64;
    array[2] = 256;
    array[3] = 512;
    
    cout << " array[0] = " << array[0] << ", endereço: " << &array[0] << endl;
    cout << " array[1] = " << array[1] << ", endereço: " << &array[1] << endl;
    cout << " array[2] = " << array[2] << ", endereço: " << &array[2] << endl;
    cout << " array[3] = " << array[3] << ", endereço: " << &array[3] << endl;
    cout << " array[4] = " << array[4] << ", endereço: " << &array[4] << endl;
    //Calcular a len de algo
    cout << "Len de array = " << sizeof(array)/sizeof(array[0]) << endl;
    if(&array[0] == array) cout << "Faz sentido!!" <<endl;
    
    cout << "------------------------------------------" << endl;
    cout << array + 2 << endl;
    
    // Questão de Prova: Pegar um row major e colocar pra trabalhar como column major
    
    // Row Majo
    int arriTest1[2][3] = {2,4,5,9,0,19};
    int arriTest2[2][3] = {{2,4,5},{9,0,19}};
    
    cout << "--- Testando Major 1 ---" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << "Array 1 em [" << i << "][" << j << "] = " << arriTest1[i][j] << ", Endereço: " << &arriTest1[i][j] << endl;
        }
    }
    
    cout << "--- Testando Major 2 ---" << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    cout << "--- Aluno com TDAh ---" << endl;
    // Matriz_m_n (i,j) em (i,j) = (i*n + j) * sizeof(elemento)
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<2; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    cout << "--- Aluno com Transtorno ---" << endl;
    // Matriz_m_n (i,j) em (i,j) = (i*n + j) * sizeof(elemento)
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<8; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    return 0;
}
