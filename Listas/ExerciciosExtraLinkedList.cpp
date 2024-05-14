#include <iostream>

using std::cout;
using std::endl;

// contar quantas vezes um elemento aparece na lista
// criar uma lista so com valores unicos de uma lista

typedef struct Node{
    int iValue;
    Node* ptrNext;
} Node;

typedef struct LinkedList{
    Node* ptrFirst;
} LinkedList;

LinkedList* newList();
Node* newNode(int);
int valueCount(LinkedList* const, int);
void addElement(LinkedList* const, int);
void printLista(LinkedList* const);
LinkedList* set(LinkedList* const);
void deleteList(LinkedList* const);
int sum(LinkedList* const);
LinkedList* concat(LinkedList* const,LinkedList* const);
void sort(LinkedList* const);

int main()
{
    LinkedList* lista = newList();
    for(int i = 1; i<10; i++)
    {
        addElement(lista,1+i);
    }
    LinkedList* lista2 = newList();
    for(int i = 1; i<10; i++)
    {
        addElement(lista2,1+i);
    }

    printLista(lista);
    cout << "Quantas vezes aparece o numero 1? " << endl;
    cout << valueCount(lista,1) << endl;

    cout << "======================" << endl;
    cout << "Lista sem repeticao de numero: " << endl;
    LinkedList* listaUnique = set(lista);
    printLista(listaUnique);

    cout << "======================" << endl;
    printLista(listaUnique);
    deleteList(listaUnique);
    printLista(listaUnique);

    cout << "======================" << endl;
    cout << "Soma dos elementos da lista 1: " << sum(lista) << endl;
    cout << "Lista concat: " << endl;
    LinkedList* listaconcat = concat(lista,lista2);
    printLista(listaconcat);

    cout << "======================" << endl;
    sort(listaconcat);
    printLista(listaconcat);

    return 0;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iValue = iValue;
    temp->ptrNext = nullptr;
    return temp;
}

LinkedList* newList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    return temp;
}

void addElement(LinkedList* const lista, int iValue)
{
    Node* temp = newNode(iValue);
    
    if(lista->ptrFirst == nullptr)
    {
        lista->ptrFirst = temp;
        return;
    }   
    
    Node* current = lista->ptrFirst;
    while(current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    current->ptrNext = temp;
}

void printLista(LinkedList* const lista)
{
    if(lista->ptrFirst == nullptr)
    {
        cout << "Lista vazia " << endl;
        return;
    }
    Node* current = lista->ptrFirst;
    cout << "[";
    while(current != nullptr)
    {
        cout << current->iValue;
        if (current->ptrNext != nullptr)
        {
            cout << ", ";
        }
        current = current->ptrNext;
    }
    cout << "]" << endl;
}

int valueCount(LinkedList* const lista, int iValue)
{
    if(lista->ptrFirst == nullptr)
    {
        cout << "Lista vazia " << endl;
        return 0;
    }
    Node* current = lista->ptrFirst;
    int count = 0;
    while(current)
    {
        if(current->iValue == iValue)
        {
            count++;
        }
        current = current->ptrNext;
    }
    return count;
}

LinkedList* set(LinkedList* const lista)
{
    LinkedList* temp = newList();
    Node* current = lista->ptrFirst;
    while(current)
    {
        if(valueCount(temp,current->iValue) == 0)
        {
            addElement(temp,current->iValue);
        }
        current = current->ptrNext;
    }
    return temp;
}

void deleteList(LinkedList* const lista)
{
    Node* current = lista->ptrFirst;
    Node* temp = nullptr;
    while(current)
    {
        temp = current->ptrNext; 
        free(current); 
        current = temp;  
    }
    lista->ptrFirst = nullptr;
}

int sum(LinkedList* const lista)
{
    Node* current = lista->ptrFirst;
    int sum = 0;
    while(current)
    {
        sum+=current->iValue;
        current = current->ptrNext;
    }
    return sum;
}

LinkedList* concat(LinkedList* const lista1, LinkedList* const lista2)
{
    LinkedList* listaconcat = newList();

    Node* current = lista1->ptrFirst;
    while(current != nullptr)
    {
        addElement(listaconcat, current->iValue);
        current = current->ptrNext;
    }

    Node* current2 = lista2->ptrFirst;
    while(current2 != nullptr)
    {
        addElement(listaconcat, current2->iValue);
        current2 = current2->ptrNext;
    }
    
    return listaconcat;
}

void sort(LinkedList* const lista)
{
    if (lista->ptrFirst->ptrNext == nullptr || lista->ptrFirst == nullptr) 
    {
        return;
    }
    
    int swapepd = 1;
    Node* current = nullptr;
    while (swapepd) 
    {
        current = lista->ptrFirst;
        swapepd = 0;
        while (current->ptrNext != nullptr)
        {
            if (current->ptrNext->iValue < current->iValue)
            {
                int temp = current->iValue;
                current->iValue = current->ptrNext->iValue;
                current->ptrNext->iValue = temp;
                swapepd = 1;
            }
            current = current->ptrNext;
        }
    }
}