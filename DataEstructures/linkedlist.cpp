#include <iostream>

// Questao de prova
// existe ou nao na lista
// apagar tudo da lista
// media da lista
// inverter a ordem da fila

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;
 
typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;
 
LinkedList* newLinkedList();
Node* newNode(int);
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void removeElement(LinkedList* const, int);

int main()
{
	LinkedList* linkedList = newLinkedList();
    
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);

    cout << "----" << endl;
    addElement(linkedList,0);
    addElement(linkedList,3);
    addElement(linkedList,7);
    addElement(linkedList,10);
    addElement(linkedList,13);
    addElement(linkedList,42);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);



    cout << "====================" << endl;

    return 0;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr; 

    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    
    return temp;
}

void showFirstElement(LinkedList* const linkedlist)
{
    if (linkedlist == nullptr || linkedlist->ptrFirst == nullptr)
    {
        cout << "showFirstElement: Lista Vazia" << endl;
    }
    else
    {
        cout << "Primeiro da Lista: " << linkedlist->ptrFirst->iData << endl;
    }
}

void showLastElement(LinkedList* const linkedlist)
{
    if (linkedlist == nullptr || linkedlist->ptrFirst == nullptr)
    {
        cout << "showLastElement: Lista Vazia" << endl;
    }
    else
    {
        Node* lastNode = linkedlist->ptrFirst;

        while(lastNode)
        {
            lastNode = lastNode->ptrNext;
        }
        cout << "Ultimo da Lista: " << lastNode->iData << endl;
    }
}


void showElements(LinkedList* const linkedlist)
{
    if (linkedlist == nullptr || linkedlist->ptrFirst == nullptr)
    {
        cout << "showElements: Lista Vazia" << endl;
    }
    else
    {
        Node* current = linkedlist->ptrFirst;

        cout << "Elementos da Lista:" << endl;
        while (current != nullptr)
        {
            cout << " " << current->iData;
            current = current->ptrNext;
        }
        cout << endl;
    }
}


void addElement(LinkedList* const linkedlist, int iValue)
{
    if (linkedlist == nullptr)
    {
        cout << "addElement: Lista nao inicializada" << endl;
        return;
    }

    Node* node = newNode(iValue);
    if (linkedlist->ptrFirst == nullptr)
    {
        linkedlist->ptrFirst = node;
    }
    else
    {
        Node* lastNode = linkedlist->ptrFirst;
        while (lastNode->ptrNext != nullptr)
        {
            lastNode = lastNode->ptrNext;
        }
        lastNode->ptrNext = node;
    }
}

// questao de prova pergunta se um valor ta na lista


void removeElement(LinkedList* const linkedlist, int iValueRemovido)
{
    if(linkedlist->ptrFirst == nullptr)
    {
        cout << "removeElement: Lista Vazia" << endl;
        return;
    }

    Node* current = linkedlist->ptrFirst;
    Node* previous = nullptr;
    
    if(current->iData == iValueRemovido)
    {
        linkedlist->ptrFirst = linkedlist->ptrFirst->ptrNext;
        free(current);
        return;
    }

    while(current != nullptr && current->iData != iValueRemovido)
    {
        previous = current;
        current = current->ptrNext;
    }

    // elemento não encontrado
    if(current == nullptr) 
    {
        cout << "Elemento passado na funcao nao esta na lista." << endl;
        return;
    }

    previous->ptrNext = current->ptrNext;

    free(current);

}