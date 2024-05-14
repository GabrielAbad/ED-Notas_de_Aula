#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef struct Node{
    int iValue;
    Node* ptrLow;
} Node;

typedef struct Stack{
    Node* ptrTop;
} Stack;

Node* newNode(int);
Stack* newStack();
void push(Stack* const, int);
void pop(Stack* const);
void printTop(Stack* const);
void printBottom(Stack* const);
void printAll(Stack* const);
void printAoContrario(Stack* const);


int main()
{

    Stack* stack = newStack();
    printBottom(stack);
    printTop(stack);
    pop(stack);
    printAll(stack);

    cout << "===================" << endl;
    
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    printTop(stack);
    printBottom(stack);
    printAll(stack);
    printAoContrario(stack);
    pop(stack);
    pop(stack);
    printTop(stack);
    printBottom(stack);
    printAll(stack);

    cout << "===================" << endl;

    printAoContrario(stack);

    return 0;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->ptrLow = nullptr;
    temp->iValue = iValue;
    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;
    return temp;
}

// nao precisa verificar nada
void push(Stack* const stack, int iValue)
{
    Node* temp = newNode(iValue);

    temp->ptrLow = stack->ptrTop;
    stack->ptrTop = temp;

}

void pop(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "pop: Nada esta empilhado"  << endl;
        return;  
    }
    
    Node* temp = stack->ptrTop;
    
    cout << "Elemento removido: " << temp->iValue << endl;

    stack->ptrTop = stack->ptrTop->ptrLow;
    
    free(temp);
}

void printBottom(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "printBottom: Nada esta empilhado"  << endl;
        return;  
    }
    
    Node* current = stack->ptrTop;
    while(current->ptrLow != nullptr)
    {
        current = current->ptrLow;
    }
    cout << "O ultimo elemento: " << current->iValue << endl;
}

void printTop(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "printTopo: Nada esta empilhado" << endl;
        return;
    }
    cout << "O elemento do topo: " << stack->ptrTop->iValue << endl;
}

void printAll(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "printAll: Nada esta empilhado" << endl;
        return;
    }

    Node* current = stack->ptrTop;
    while(current != nullptr)
    {
        cout << current->iValue << " ";
        current = current->ptrLow;
    }
    cout << endl;
}

// funcao que vai printar do de baixo ate o de cima
void printAoContrario(Stack* const stack)
{
    Stack* stackInv = newStack();

    Node* current = stack->ptrTop;

    while(current != nullptr)
    {
        push(stackInv,current->iValue);
        current = current->ptrLow;
    }

    printAll(stackInv);    
}