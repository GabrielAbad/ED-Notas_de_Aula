#include <iostream>
#include <string> // Para usar std::string
#include <cstdlib> // Para usar malloc e free

using std::cout;
using std::endl;
using std::string;

typedef struct NodeAutor
{
    string strNome;
    NodeAutor* ptrNext;
} NodeAutor;

typedef struct LinkedList
{
    NodeAutor* ptrFirst;
} LinkedList;

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
    cout << endl;
}

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

int main()
{
    LinkedList* lista = newLinkedList();
    addAutor(lista, "Gb");
    addAutor(lista, "Mamae");
    addAutor(lista, "Papai");
    addAutor(lista, "Gb");
    addAutor(lista, "Papai");
    printLista(lista);
    cout << "----" << endl;
    LinkedList* listau = unique(lista);
    printLista(listau);
    return 0;
}
