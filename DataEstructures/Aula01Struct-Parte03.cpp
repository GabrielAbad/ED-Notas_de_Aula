#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


// definindo uma estrutura livre, que pode ser chamada deposis
typedef struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
}Livro;

// pode usar struct dentro de struct
typedef struct Biblioteca // typedef da um alias para a struct
{
    string strNome;
    int iTamAcervo;
    struct Livro livros[1000];
}Biblioteca;



void listarLivros(Biblioteca);
void adicionarLivros(Biblioteca&,Livro);

int main()
{
    Biblioteca biblioteca;
    biblioteca.strNome = "Biblioteca do Palacio Botafogo";
    biblioteca.iTamAcervo = 0;
    
    Livro livro1;
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcom Gladwell";
    livro1.iPublicacao = 2008;
    
    Livro livro2;
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "Marus Tullius Cicero";
    livro2.iPublicacao = -44;
    
    Livro livro3;
    livro3.strTitulo = "1984";
    livro3.strAutor = "George Orwell";
    livro3.iPublicacao = 1949;
    
    biblioteca.livros[0] = livro1;
    biblioteca.iTamAcervo+=1;
    biblioteca.livros[1] = livro2;
    biblioteca.iTamAcervo+=1;
    
    
    adicionarLivros(biblioteca, livro1);
    adicionarLivros(biblioteca, livro2);
    adicionarLivros(biblioteca, livro3);
    
    listarLivros(biblioteca);

    return 0;
}


// Dever de casa, verificar tamanho vazio
// se o tamanho do acervo for 0, tratar
void listarLivros(Biblioteca biblioteca)
{
    cout << "\nLivros do Acervo da " << biblioteca.strNome << "\n" << endl;
    if (biblioteca.iTamAcervo == 0) cout << "Não temos livros" << endl;
    for(int i = 0; i < biblioteca.iTamAcervo; i++)
    {
       cout << "Titulo: " << biblioteca.livros[i].strTitulo << ", por " << biblioteca.livros[i].strAutor << endl;
       cout << "Publicado em: " << biblioteca.livros[i].iPublicacao << "." << endl; 
    }
};


// Dever de casa: verificar se a biblioteca está cheia
void adicionarLivros(Biblioteca& biblioteca,Livro novoLivro)
{
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo+=1;
}































