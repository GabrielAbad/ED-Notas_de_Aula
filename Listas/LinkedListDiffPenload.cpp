#include <iostream>

using std::cout;
using std::endl;

typedef struct Node
{
    int iarrData[5];
    Node* ptrNext;
} Node;

typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;

LinkedList* newList();
Node* newNode(int [5]);
void insert(LinkedList* const, int [5]);
void printAll(LinkedList* const);

int main()
{
    LinkedList* lista = newList();
    int iarrData[5];
    int iarrDataB[5];
    for(int i = 0; i<5; i++)
    {
        iarrData[i] = i+1;
        iarrDataB[i] = i+1;
    }
    insert(lista,iarrData);
    insert(lista,iarrDataB);
    printAll(lista);
    return 0;
}

LinkedList* newList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    return temp;
}

Node* newNode(int iarrData[5])
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->ptrNext = nullptr;
    for(int i = 0; i<5; i++)
    {
        temp->iarrData[i] = iarrData[i];
    }
    return temp;
}

void insert(LinkedList* const lista, int iarrData[5])
{
    Node* temp = newNode(iarrData);
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

void printAll(LinkedList* const lista)
{
    if(lista->ptrFirst == nullptr)
    {
        cout << "printAll: Lista Vazia" << endl;
        return;
    }
    cout << "[";
    Node* current = lista->ptrFirst;
    while(current)
    {
        
        cout << "[";
        for(int i = 0; i<5; i++)
        {
            if(i<4) cout << current->iarrData[i] << " ";
            else cout << current->iarrData[i];
        }
        if(current->ptrNext != nullptr) cout << "]" <<", ";
        else cout << "]";
        current = current->ptrNext;
    }
    cout <<"]" << endl;
}