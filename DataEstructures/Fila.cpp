#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;


// Estrutura da fila, é first in e first out, o primeiro a chegar é o primeiro a ser atendido
// O exemplo vai ser com int, mas na prova vai ser outro tipo

// elemento da fila, sempre aponta pro próximo
typedef struct Node
{
    int iData;
    Node* next;
} Node;


typedef struct Queue
{
    // ponteiro pro primeiro da fila
    Node* front;
    // ponteiro pro ultimo da fila
    Node* rear;
} Queue;


Queue* newQueue()
{
    // pede memoria pro S.O, malloc retorna um void*
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->front = nullptr;
    temp->rear = nullptr;
    
    return temp;
}


Node* newNode(int iValue)
{
 
    Node* temp = (Node*) malloc(sizeof(Queue));
    temp->iData = iValue;
    temp->next = nullptr;
    
    return temp;
}


void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue);
    
    // Se a fila tiver vazia, o primeiro é o ultimo tambem
    if(queue->front == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

void showFirstElement(Queue* const queue)
{
    cout << "Primeiro Elemento: " << ((queue->front != NULL) ? (queue->front)->iData : -1) << endl;
}

void showLastElement(Queue* const queue)
{
    cout << "Ultimo Elemento: " << ((queue->rear != NULL) ? (queue->rear)->iData : -1) << endl;
}


void showElements(Queue* const queue)
{
    if(queue->front == nullptr)
    {
        cout << "Vazia" << endl;
        return;
    }
    
    Node* current = queue->front;
    
    while(current)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->next;
    }
}


int main()
{
    // 1. Estrutura de um nó
    // 2. Estrutura de uma fila
    // 3. Funcao que cria uma fila
    // 4. Funcao que cria um nó
    // 5. Funcao que enfileira um nó
    
    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" <<endl;
    showElements(queue);
    cout<<"===========================" << endl;
    
    enQueue(queue,0);
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" <<endl;
    showElements(queue);
    cout<<"===========================" << endl;
    
    enQueue(queue,3);
    enQueue(queue,7);
    enQueue(queue,13);
    enQueue(queue,42);
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" <<endl;
    showElements(queue);
    cout<<"===========================" << endl;

    return 0;
}

