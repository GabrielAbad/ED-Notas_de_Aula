#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


// definindo uma estrutura livre, que pode ser chamada deposis
struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
};

struct Ponto
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};


int main()
{
    struct Livro livro1;
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcom Gladwell";
    livro1.iPublicacao = 2008;
    
    struct Livro livro2;
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "Marus Tullius Cicero";
    livro2.iPublicacao = -44;
    
    cout << "Titulo1: " << livro1.strTitulo << ", por " << livro1.strAutor << endl;
    cout << "Publicado em: " << livro1.iPublicacao << "." << endl;
    
    cout << "Titulo2: " << livro2.strTitulo << ", por " << livro2.strAutor << endl;
    cout << "Publicado em: " << livro2.iPublicacao << "." << endl;
    
    
    
    struct Ponto telaComputador[640][480];
    telaComputador[0][0].usRed = 0;
    telaComputador[0][0].usGreen = 0;
    telaComputador[0][0].usBlue = 0;
    
    cout << "RGB [0,0]: " << "(" << telaComputador[0][0].usRed << ", " << telaComputador[0][0].usGreen << ", " << telaComputador[0][0].usBlue << ")" << endl;
    
    return 0;
}