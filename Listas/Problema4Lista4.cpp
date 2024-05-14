#include <iostream>

using std::cout;
using std::endl;


typedef struct Node{
    int iValue;
    Node* ptrNext;
} Node;

typedef struct LinkedList{
    Node* ptrFirst;
} LinkedList;

typedef struct Node2{
    LinkedList* ptrList;
    Node2* ptrNextList;
} Node2;

typedef struct LinkedList2{
    Node2* ptrFirstList;
} LinkedList2;

typedef struct Stack{
    Node* ptrTop;
} Stack;

LinkedList* newList();
LinkedList2* newList2();
Node* newNode(int);
Node2* newNode2(LinkedList* const);
Stack* newStack();
void insert2(LinkedList2* const, LinkedList* const);
void print2(LinkedList2* const);
void insert(LinkedList* const, int);
void inversa(LinkedList* const);
void push(Stack* const, int);
void freeStack(Stack* const);
void inversa(LinkedList* const);
void printLista(LinkedList* const);

int main()
{
    LinkedList2* mainLista = newList2();  // mainLista está vazia
    LinkedList* miniListaA = newList();   // miniListaA está vazia
    LinkedList* miniListaB = newList();   // miniListaB está vazia

    for(int i = 0; i<10; i++)
    {
        insert(miniListaB, i+1);
    }

    insert2(mainLista, miniListaA);  // mainLista: [miniListaA]
    insert2(mainLista, miniListaB);  // mainLista: [miniListaA, miniListaB]
    print2(mainLista);
    cout << endl;
    cout << "=================================" << endl;
    printLista(miniListaB);
    inversa(miniListaB);
    printLista(miniListaB);

    return 0;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iValue = iValue;
    temp->ptrNext = nullptr;
    return temp;
}

Node2* newNode2(LinkedList* const listValue)
{
    Node2* temp = (Node2*) malloc(sizeof(Node2));
    temp->ptrList = listValue;
    temp->ptrNextList = nullptr;
    return temp;
}

LinkedList* newList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    return temp;
}

LinkedList2* newList2()
{
    LinkedList2* temp = (LinkedList2*) malloc(sizeof(LinkedList2));
    temp->ptrFirstList = nullptr;
    return temp;
}

void insert2(LinkedList2* const mainLista, LinkedList* const miniLista)
{
    Node2* novoNode2 = newNode2(miniLista);
    if (mainLista->ptrFirstList == nullptr) 
    {
        mainLista->ptrFirstList = novoNode2;
    } 
    else 
    {
        Node2* temp = mainLista->ptrFirstList;
        while (temp->ptrNextList != nullptr) {
            temp = temp->ptrNextList;
        }
        temp->ptrNextList = novoNode2;
    }
}

void print2(LinkedList2* const mainLista)
{
    if(mainLista->ptrFirstList == nullptr)
    {
        cout << "Lista sem listas" << endl;
        return;
    }
    
    Node2* currentMiniList = mainLista->ptrFirstList;
    while(currentMiniList)
    {
        if(currentMiniList->ptrList->ptrFirst == nullptr)
        {
            cout << "MiniLista vazia" << " ";
        }
        else
        {
            Node* current = currentMiniList->ptrList->ptrFirst;
            while(current)
            {
                cout << current->iValue << " ";
                current = current->ptrNext;
            }
        }
        currentMiniList = currentMiniList->ptrNextList;
    }
}

void insert(LinkedList* const lista, int iValue)
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

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;
    return temp;
}

void push(Stack* const pilha, int iValue)
{
    Node* temp = newNode(iValue);
    temp->ptrNext = pilha->ptrTop;
    pilha->ptrTop = temp;
}

void freeStack(Stack* const pilha)
{
    Node* current = pilha->ptrTop;
    while (current)
    {
        Node* temp = current;
        current = current->ptrNext;
        free(temp);
    }
    free(pilha);
}


void inversa(LinkedList* const lista)
{
    Stack* auxStack = newStack();
    Node* current = lista->ptrFirst;
    while(current)
    {
        push(auxStack, current->iValue);
        current = current->ptrNext;
    }

    current = lista->ptrFirst;
    Node* auxStackCurrent = auxStack->ptrTop;
    while(current)
    {
        current->iValue = auxStackCurrent->iValue;
        current = current->ptrNext;
        auxStackCurrent = auxStackCurrent->ptrNext;
    }
    freeStack(auxStack);
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