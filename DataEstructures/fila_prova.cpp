#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// regras
// primeiro a entrar primeiro a sair

typedef struct Node{
    int iValue;
    Node* ptrNext;
} Node;


typedef struct Queue{
    Node* ptrFirst;
    Node* ptrLast;
} Queue;

Node* newNode(int);
Queue* newQueue();
void printFirst(Queue* const);
void printLast(Queue* const);
void printAll(Queue* const);
void enQueue(int, Queue* const);
void deQueue(Queue* const);
void enQueueasFirst(Queue* const, int);



int main()
{
    Queue* queue = newQueue();

    printFirst(queue);
    printLast(queue);
    printAll(queue);
    deQueue(queue);

    cout << "======================" << endl;
    
    enQueue(42,queue);
    printFirst(queue);
    printLast(queue);
    printAll(queue);
    deQueue(queue);
    printFirst(queue);
    printLast(queue);
    printAll(queue);

    cout << "======================" << endl;
    
    enQueue(42,queue);
    enQueue(2,queue);
    enQueue(1,queue);
    printFirst(queue);
    deQueue(queue);
    printFirst(queue);
    printLast(queue);
    printAll(queue);

    cout << "======================" << endl;
    enQueueasFirst(queue,7);
    printAll(queue);
    return 0;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iValue = iValue;
    temp->ptrNext = nullptr;
    return temp;
}

Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->ptrFirst = nullptr;
    temp->ptrLast = nullptr;
    return temp; 
}

// o que entra é sempre o ultimo, entao o next do ultimo atual eh o elemento adicionado
void enQueue(int iValue, Queue* const queue)
{
    
    Node* temp = newNode(iValue);
    // verificar 0
    if(queue->ptrFirst == nullptr)
    {
        queue->ptrFirst = temp;
        queue->ptrLast = temp;
    }
    // verificar n
    else
    {
        queue->ptrLast->ptrNext = temp;
        queue->ptrLast= temp;
    }
}

void printFirst(Queue* const queue)
{
    // verifica se tá vazia
    if(queue->ptrFirst == nullptr) cout << "printFirst: A fila esta vazia." << endl;
    else cout << "O primeiro elemento da fila: " << queue->ptrFirst->iValue << endl;
}

void printLast(Queue* const queue)
{
    // verifica se tá vazia
    if(queue->ptrFirst == nullptr) cout << "printLast: A fila esta vazia." << endl;
    else cout << "O ultimo elemento da fila: " << queue->ptrLast->iValue << endl;
}

void printAll(Queue* const queue)
{
    if(queue->ptrFirst == nullptr)
    {
        cout << "printAll: A fila esta vazia" << endl;
        return;
    }
    
    Node* current = queue->ptrFirst;
    while(current)
    {
        cout << current->iValue << " ";
        current = current->ptrNext;
    }
    cout << endl;
}

// tira o primeiro da fila, lembrar de apagar da memoria
void deQueue(Queue* const queue)
{
    if(queue->ptrFirst == nullptr)
    {
        cout << "deQueue: A fila esta vazia" << endl;
        return;
    }

    // caso em que tem mais de 1 na fila
    Node* temp = queue->ptrFirst;

    queue->ptrFirst = queue->ptrFirst->ptrNext;

    // caso só tenha um na fila tem que mudar o ultimo tambem
    if(queue->ptrFirst == nullptr)
    {
        queue->ptrLast = nullptr;
    }

    free(temp);
}

void enQueueasFirst(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue);
    if(queue->ptrFirst == nullptr)
    {
        queue->ptrFirst = temp;
        queue->ptrLast = temp;
        return;
    }
    temp->ptrNext = queue->ptrFirst;
    queue->ptrFirst = temp;
}

// conclusao
// deQueue: Tratar os casos 0, 1, n
// enQueue: Tratar os caso 0, n
// print: Tratar caso 0, n