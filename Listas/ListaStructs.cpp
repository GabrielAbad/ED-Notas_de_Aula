#include <iostream>
using std::cout;
using std::endl;
using std::string;

// Questao 1
typedef struct Carro
{
    string strMarca;
    string strModelo;
    int iAno;
    float fPreco;
} Carro;

// Questao 2
typedef struct Aluno
{
    string strNome;
    int iIdade;
    float fNota;

}Aluno;
void printMatriz(Aluno [3][2], int, int);

//Questao 3

typedef struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
    bool emEstoque;
}Livro;

typedef struct Biblioteca 
{
    string strNome;
    int iTamAcervo;
    struct Livro livros[1000];
}Biblioteca;

bool buscarLivro(string, Biblioteca);
void listarLivros(Livro [],int);

int main()
{
    cout << "Questao 1: " << endl;
    
    Carro carro1 = {"Ford", "Ka", 2020, 39000.0};
    Carro carro2 = {"Fiat", "Touro", 2019, 79900.0};

    cout << "=== Informações dos Carros ===" << endl;
    cout << "Carro 1:" << endl;
    cout << "Marca: " << carro1.strMarca << endl;
    cout << "Modelo: " << carro1.strModelo << endl;
    cout << "Ano: " << carro1.iAno << endl;
    cout << "Preço: R$ " << carro1.fPreco << endl;

    cout << "Carro 2:" << endl;
    cout << "Marca: " << carro2.strMarca << endl;
    cout << "Modelo: " << carro2.strModelo << endl;
    cout << "Ano: " << carro2.iAno << endl;
    cout << "Preço: R$ " << carro2.fPreco << endl;

    cout << "======================" << endl;

    cout << "Questao 2: " << endl;

    Aluno matrizAlunos[3][2];

    matrizAlunos[0][0] = {"Joao", 20, 8.5};
    matrizAlunos[0][1] = {"Maria", 22, 9.0};
    matrizAlunos[1][0] = {"Pedro", 21, 7.0};
    matrizAlunos[1][1] = {"Ana", 19, 6.5};
    matrizAlunos[2][0] = {"Carlos", 23, 8.0};
    matrizAlunos[2][1] = {"Julia", 20, 7.8};

    printMatriz(matrizAlunos,3,2);


    return 0;
}


void printMatriz(Aluno matrizAlunos[3][2], int iLinhas, int iColunas)
{
    for(int i = 0; i<iLinhas; i++)
    {
        for(int j = 0; j<iColunas; j++)
        {
            cout << "Nome: "<< matrizAlunos[i][j].strNome << endl;
            cout << "Idade: " << matrizAlunos[i][j].iIdade << endl;
            cout << "Nota: " << matrizAlunos[i][j].fNota<< endl;
            cout << endl;
        }
    }
}

bool buscarLivro(string strNomeLivro, Biblioteca biblioteca)
{
    for(int i = 0; i<biblioteca.iTamAcervo; i++)
    {
        if(biblioteca.livros[i].strTitulo == strNomeLivro)
        {
            return 1;
        }
    }
    return 0;
}

void listarLivros(Livro arrLivros[], int iQuantidadeLivros)
{
    for(int i = 0; i<iQuantidadeLivros; i++)
    {
        if(arrLivros[i].emEstoque)
        {
            cout <<"O livro: " <<arrLivros[i].strTitulo << ", esta em estoque." << endl;
        }
        else
        {
            cout <<"O livro: " <<arrLivros[i].strTitulo << ", nao foi encontrado." << endl;
        }
    }    
}