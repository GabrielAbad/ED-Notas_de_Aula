#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Faca pras 3 estruturas que a gente esta vendo:
// funcao que adiciona livro na biblioteca.
// funcao que remove algum livro da biblioteca pelo nome dele, simule uma venda.
// print todos os livros da biblioteca, simule uma estante.
// diga qual autor mais aparece dentre os livros da biblioteca.
// diga a media do preco dos livros da biblioteca.
// ache o livro mais antigo da biblioteca.
// diga quantos exemplares tem de um livro especifico, lembre-se de quando nao tiver avisar.
// ordene pelo ano de publicacao

typedef struct Livro {
    string strTitulo;
    string strAutor;
    int anoPublicacao;
    int iPreco;
} Livro;

typedef struct Node
{
    Livro livro;
    Node* ptrNext;
} Node;

typedef struct Biblioteca
{
    Node* ptrFIrst;
} Biblioteca;

typedef struct NodeAutor
{
    string strNome;
    NodeAutor* ptrNext;
} NodeAutor;

typedef struct LinkedList
{
    NodeAutor* ptrFirst;
} LinkedList;

Livro* newLivro(string, string, int, int);
Node* newNode(Livro);
Biblioteca* newLibrary();
void addBook(Biblioteca* const, Livro);
void removeBook(Biblioteca* const, string);
void printLibrary(Biblioteca* const);

// ==============================
int countAutor(LinkedList* const, string);
NodeAutor* newNodeAutor(string);
LinkedList* newLinkedList();
void addAutor(LinkedList* const, string);
void removeAutor(LinkedList* const, string);
void printLista(LinkedList* const);
LinkedList* unique(LinkedList* const);
LinkedList* uniqueAutorsFromLibrary(Biblioteca* const);
string mostcommonAuthor(Biblioteca* const);
// ===============================

float meanPrice(Biblioteca* const);
string oldestBook(Biblioteca* const);

int main()
{
    Livro* livros[5];
    livros[0] = newLivro("Stephen King", "It", 35, 1986);
    livros[1] = newLivro("J.K. Rowling", "Harry Potter and the Philosopher's Stone", 25, 1997);
    livros[2] = newLivro("George Orwell", "1984", 20, 1949);
    livros[3] = newLivro("Jane Austen", "Pride and Prejudice", 18, 1813);
    livros[4] = newLivro("Mark Twain", "The Adventures of Tom Sawyer", 15, 1876);
    Biblioteca* biblioteca = newLibrary();
    for(int i = 0; i<5; i++)
    {
        addBook(biblioteca,*livros[i]);
    }
    printLibrary(biblioteca);
    cout <<"----" << endl;
    cout << mostcommonAuthor(biblioteca) << endl;
    cout <<"----" << endl;
    cout << meanPrice(biblioteca) << endl;
    cout <<"----" << endl;
    cout << oldestBook(biblioteca) << endl;
    
    
    return 0;
}

Livro* newLivro(string strAutor, string strTitulo, int iPreco, int iAno)
{
    Livro* temp = (Livro*) malloc(sizeof(Livro));
    temp->anoPublicacao = iAno;
    temp->iPreco = iPreco;
    temp->strAutor = strAutor;
    temp->strTitulo = strTitulo;
    return temp;
}

Node* newNode(Livro livro)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->livro = livro;
    temp->ptrNext = nullptr;
    return temp;
}

Biblioteca* newLibrary()
{
    Biblioteca* temp = (Biblioteca*) malloc(sizeof(Biblioteca));
    temp->ptrFIrst = nullptr;
    return temp;
}

void addBook(Biblioteca* const library, Livro book)
{
    Node* temp = newNode(book);
    if(library->ptrFIrst == nullptr)
    {
        library->ptrFIrst = temp;
        return;
    }
    Node* current = library->ptrFIrst;
    while(current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    current->ptrNext = temp;
}

void removeBook(Biblioteca* const library, string strTitulo)
{

    if(library->ptrFIrst == nullptr)
    {
        cout << "removeBook: Nada a remover." << endl;
        return;
    }

    if(library->ptrFIrst->livro.strTitulo == strTitulo)
    {
        Node* temp = library->ptrFIrst;
        library->ptrFIrst =  library->ptrFIrst->ptrNext;
        free(temp);
        return;
    }

    Node* current = library->ptrFIrst;
    Node* previous = nullptr;

    while(current != nullptr && current->livro.strTitulo != strTitulo)
    {
        previous = current;
        current = current->ptrNext;
    }

    if(current == nullptr)
    {
        cout << "Elemento nao encontrado na lista" << endl;
        return;
    }

    previous->ptrNext = current->ptrNext;
    free(current);
}

void printLibrary(Biblioteca* const biblioteca)
{
    if(biblioteca->ptrFIrst == nullptr) cout << "printLibrary: Biblioteca ta vazia" << endl;
    Node* current = biblioteca->ptrFIrst;
    while(current)
    {
        cout << current->livro.strTitulo << endl;
        current = current->ptrNext;
    }
}

// ========================================================================================
int countAutor(LinkedList* const lista, string strAutor)
{
    if(lista->ptrFirst == nullptr) return 0;
    NodeAutor* current = lista->ptrFirst;
    int count = 0;
    while (current)
    {
        if(current->strNome == strAutor)
        {
            count++;
        }
        current = current->ptrNext;
    }
    return count;    
}

NodeAutor* newNodeAutor(string strNome)
{
    NodeAutor* temp = (NodeAutor*)malloc(sizeof(NodeAutor));
    temp->ptrNext = nullptr;
    temp->strNome = strNome;
    return temp;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    return temp;
}

void addAutor(LinkedList* const lista, string strNome)
{
    NodeAutor* temp = newNodeAutor(strNome);
    if (lista->ptrFirst == nullptr)
    {
        lista->ptrFirst = temp;
        return;
    }

    NodeAutor* current = lista->ptrFirst;
    while (current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    current->ptrNext = temp;
}

void removeAutor(LinkedList* const lista, string strNome)
{
    if (lista->ptrFirst == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }

    if (lista->ptrFirst->strNome.compare(strNome) == 0)
    {
        NodeAutor* temp = lista->ptrFirst;
        lista->ptrFirst = lista->ptrFirst->ptrNext;
        free(temp);
        return;
    }

    NodeAutor* current = lista->ptrFirst;
    NodeAutor* previous = nullptr;

    while (current != nullptr && current->strNome.compare(strNome) != 0)
    {
        previous = current;
        current = current->ptrNext;
    }

    if (current == nullptr)
    {
        cout << "Nome nao encontrado" << endl;
        return;
    }

    previous->ptrNext = current->ptrNext;
    free(current);
}

void printLista(LinkedList* const lista)
{
    if (lista->ptrFirst == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }
    NodeAutor* current = lista->ptrFirst;
    while (current)
    {
        cout << current->strNome << " ";
        current = current->ptrNext;
    }
}

LinkedList* unique(LinkedList* const lista)
{
    LinkedList* temp = newLinkedList();
    NodeAutor* current = lista->ptrFirst;
    while(current)
    {
        if(countAutor(temp,current->strNome) == 0)
        {
            addAutor(temp, current->strNome);
        }
        current = current->ptrNext;
    }
    return temp;
}

LinkedList* uniqueAutorsFromLibrary(Biblioteca* const biblioteca)
{
    Node* current = biblioteca->ptrFIrst;
    LinkedList* temp = newLinkedList();
    while(current)
    {
        addAutor(temp, current->livro.strAutor);
        current = current->ptrNext;
    }
    LinkedList* uniqueAutors = unique(temp);
    return uniqueAutors;
}


// criar funcao que dado um nome de um autor conta quantos livros tem dele
// criar funcao que cria uma lista com autores unicos dada uma lista de autores
// criar uma lista com os autores que tem na biblioteca
// usar a funcao 2
// para cada autor da lista de autores unicos usar funcao 1
string mostcommonAuthor(Biblioteca* const biblioteca)
{
    LinkedList* listaAutors = newLinkedList();
    Node* current = biblioteca->ptrFIrst;
    while (current)
    {
        addAutor(listaAutors, current->livro.strAutor);
        current = current->ptrNext;
    }
    
    LinkedList* listaUniqueAutors = uniqueAutorsFromLibrary(biblioteca);
    NodeAutor* currentUniqueAutors = listaUniqueAutors->ptrFirst;
    int maxAppereance = 0;
    string mostcommonAuthor = "";
    while (currentUniqueAutors)
    {
        int count = countAutor(listaAutors, currentUniqueAutors->strNome);
        if(count > maxAppereance)
        {
            maxAppereance = count;
            mostcommonAuthor = currentUniqueAutors->strNome;
        }
        currentUniqueAutors = currentUniqueAutors->ptrNext;
    }
    return mostcommonAuthor;
}


// ========================================================================

float meanPrice(Biblioteca* const biblioteca)
{
    Node* current = biblioteca->ptrFIrst;
    float sum = 0;
    float length = 0;
    while(current)
    {
        sum += current->livro.iPreco;
        length++;
        current = current->ptrNext;
    }
    return sum/length;
}

string oldestBook(Biblioteca* const biblioteca)
{
    Node* current = biblioteca->ptrFIrst->ptrNext;
    int min = biblioteca->ptrFIrst->livro.anoPublicacao;
    string strTitulo = biblioteca->ptrFIrst->livro.strTitulo;
    while(current)
    {
        if(current->livro.anoPublicacao < min)
        {
            min = current->livro.anoPublicacao;
            strTitulo = current->livro.strTitulo;
        }
        current = current->ptrNext;
    }
    return strTitulo;
}