#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Exercicio mudar pop pra retornar o elemento removido alem de fazer o pop


typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;


typedef struct Stack
{

    Node* ptrTop;

} Stack;

Stack* newStack();
Node* newNode(int);
void push(Stack* const, int);
void printTopo(Stack* const);
void showElements(Stack* const);
void pop(Stack* const);

int main()
{
    // 1. Estrutura de um nó
    // 2. Estrutura de uma fila
    // 3. Funcao que cria uma fila
    // 4. Funcao que cria um nó
    // 5. Funcao que enfileira um nó
    // 6. Funcao que exibe o elemento do topo
    // 7. Funcao que exibe os elementos
    // 8. Funcao que remove um no
    
    Stack* stack = newStack();
    cout << "----" << endl;
    pop(stack);
    cout << "----" << endl;
    push(stack, 0);
    printTopo(stack);
    cout << "----" << endl;
    showElements(stack);
    cout << "----" << endl;
    push(stack, 3);
    printTopo(stack);
    push(stack, 7);
    printTopo(stack);
    push(stack, 10);
    printTopo(stack);
    push(stack, 13);
    printTopo(stack);
    push(stack, 42);
    printTopo(stack);
    cout << "----" << endl;
    showElements(stack);
    cout << endl;
    cout << "----" << endl;
    pop(stack);
    cout << "----" << endl;
    showElements(stack);
    cout << endl;
    cout << "=========================" << endl;

    return 0;
}


Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;
    
    return temp;
}


Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;
    
    return temp;
}

void push(Stack* const stack, int iValue)
{
    Node* temp = newNode(iValue);
    
    temp->ptrNext = stack->ptrTop;
    stack->ptrTop = temp;
    
    return;
}


void printTopo(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
       cout << "Pilha vazia." << endl;
    }
    else
    {
        cout << "O topo da pilha eh o elemento: " << stack->ptrTop->iData << endl;
    }
}

void showElements(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "Pilha Vazia" << endl;
        return;
    }
    
    Node* current = stack->ptrTop;
    
    while(current)
    {
        cout << current->iData << " "; 
        current = current->ptrNext;
    }
}


void pop(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "Pilha Vazia" << endl;
        return;
    }
    
    Node* temp = stack->ptrTop;
    
    stack->ptrTop = stack->ptrTop->ptrNext;
    
    cout << "Elemento removido: " << temp->iData << endl;
    
    free(temp);
}
