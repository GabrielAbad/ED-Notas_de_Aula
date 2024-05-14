#include <iostream>

using std::cout;
using std::endl;

// contar frequencia dos elementos de uma lista
// criar uma lista so com valores unicos de uma lista


typedef struct Node
{
    int iValue;
    Node* ptrNext;
} Node;

typedef struct Queue
{
    Node* ptrFront;
    Node* ptrRear;
} Queue;

typedef struct Stack
{
    Node* ptrTop;
} Stack;

Stack* newStack();
void push(Stack* const, int);
void freeStack(Stack* const);
Node* newNode(int);
Queue* newQueue();
void addElement(Queue* const,int);
void printElements(Queue* const);
bool isEqual(Queue* const, Queue* const);
int maxNodeValue(Queue* const);
int minNodeValue(Queue* const);
float meanQueue(Queue* const);
void invQueue(Queue* const);
Queue* copy(Queue* const);
int countImpar(Queue* const);
int countPar(Queue* const);

int main()
{
    Queue* fila1 = newQueue();
    addElement(fila1,1);
    addElement(fila1,2);
    addElement(fila1,3);
    cout << "Fila 1: " << endl;
    printElements(fila1);
    Queue* fila2 = newQueue();
    addElement(fila2,1);
    addElement(fila2,2);
    addElement(fila2,3);
    addElement(fila2,4);
    cout << "Fila 2: " << endl;
    printElements(fila2);
    cout << "As filas sao iguais? " << isEqual(fila1,fila2) << endl; // 1 significa que sim 0 significa que nao
    cout << "Maximo da fila1: " << maxNodeValue(fila1) << endl;
    cout << "Maximo da fila2: " << maxNodeValue(fila2) << endl;
    cout << "Minimo da fila1: " << minNodeValue(fila1) << endl;
    cout << "Minimo da fila2: " << minNodeValue(fila2) << endl;
    cout << "Media da fila1: " << meanQueue(fila1) << endl;
    cout << "Media da fila2: " << meanQueue(fila2) << endl;
    Queue* copyfila1 = copy(fila1);
    cout << "copyfila1: " << endl;
    printElements(copyfila1);
    cout << "Inversa da copyfila1: " << endl;
    invQueue(copyfila1);
    printElements(copyfila1);
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
    temp->ptrFront = nullptr;
    temp->ptrRear = nullptr;
    return temp;
}

void addElement(Queue* const fila,int iValue)
{
    Node* temp = newNode(iValue);
    if(fila->ptrFront == nullptr)
    {
        fila->ptrFront = temp;
        fila->ptrRear = temp;
        return;
    }

    fila->ptrRear->ptrNext = temp;
    fila->ptrRear = temp;
}

void printElements(Queue* const fila)
{
    if(fila->ptrFront == nullptr) cout << "printELements: A fila esta vazia." << endl;
    else
    {
        Node* current = fila->ptrFront;
        while(current)
        {
            cout << current->iValue << " ";
            current = current->ptrNext;
        }
        cout << endl;
    }
}

bool isEqual(Queue* const fila1, Queue* const fila2)
{
    Node* current1 = fila1->ptrFront;
    Node* current2 = fila2->ptrFront;
    int count1 = 0;
    int count2 = 0;

    while (current1)
    {
        count1++;
        current1 = current1->ptrNext;
    }
    while (current2)
    {
        count2++;
        current2 = current2->ptrNext;
    }

    if(count1 != count2)
    {
        if(count1 > count2)
        {
            cout << "Fila 1 maior que fila 2" << endl;
        }
        else
        {
            cout << "Fila 2 maior que fila 1" << endl;
        }
        return false;
    }

    else
    {
        Node* current1 = fila1->ptrFront;
        Node* current2 = fila2->ptrFront;
        while(current1)
        {
            if(current1->iValue != current2->iValue)
            {
                return false;
            }
            current1 = current1->ptrNext;
            current2 = current2->ptrNext;
        }
        return true;
    }
}

int maxNodeValue(Queue* const fila)
{
    if(fila->ptrFront == nullptr) cout << "maxNodeValue: Fila nao tem ninguem." << endl;
    
    Node* current = fila->ptrFront;
    int max = current->iValue;
    while(current!=nullptr)
    {
        if(current->iValue > max)
        {
            max = current->iValue;
        }
        current = current->ptrNext;
    }
    return max;    
}

int minNodeValue(Queue* const fila)
{
    if(fila->ptrFront == nullptr) cout << "minNodeValue: Fila nao tem ninguem." << endl;
    
    Node* current = fila->ptrFront;
    int min = current->iValue;
    while(current!=nullptr)
    {
        if(current->iValue < min)
        {
            min = current->iValue;
        }
        current = current->ptrNext;
    }
    return min;    
}

float meanQueue(Queue* const fila)
{
    float length = 0;
    float sum = 0;

    Node* current = fila->ptrFront;
    while(current)
    {
        sum+= current->iValue;
        length++;
        current = current->ptrNext;
    }
    return sum/length;
}

Queue* copy(Queue* const fila)
{
    Queue* temp = newQueue();
    Node* current = fila->ptrFront;
    while (current)
    {
        addElement(temp,current->iValue);
        current = current->ptrNext;
    }
    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;
    return temp;
}
void push(Stack* const stack, int iValue)
{
    Node* temp = newNode(iValue);
    temp->ptrNext = stack->ptrTop;
    stack->ptrTop = temp;
}

void freeStack(Stack* const stack)
{
    Node* current = stack->ptrTop;
    Node* temp;
    while(current != NULL)
    {
        temp = current;
        current = current->ptrNext;
        free(temp);
    }
    free(stack);
}

// precisa de uma pilha auxiliar, lembrar de criar freeStack que apaga tudo de uma pilha
void invQueue(Queue* const fila)
{
    Stack* auxStack = newStack();
    Node* current = fila->ptrFront;
    // empilha um stack auxiliar em que o topo é o ultimo da fila
    while(current)
    {
        push(auxStack,current->iValue);
        current = current->ptrNext;
    }
    
    current = fila->ptrFront;
    while(current && auxStack->ptrTop)
    {
        current->iValue = auxStack->ptrTop->iValue;
        auxStack->ptrTop = auxStack->ptrTop->ptrNext;
        current = current->ptrNext;
    }
    freeStack(auxStack);
}