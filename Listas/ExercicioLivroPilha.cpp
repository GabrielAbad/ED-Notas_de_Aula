#include <iostream>

using std::cout;
using std::endl;

typedef struct Node
{
    int iValue;
    Node* ptrLow;
} Node;

typedef struct Stack
{
    Node* ptrTop;
} Stack;

Node* newNode(int);
Stack* newStack();
void push(Stack* const,int);
bool isEqual(Stack* const, Stack* const);
int maxNodeValue(Stack* const);
int minNodeValue(Stack* const);
float meanStack(Stack* const);
void printStack(Stack* const);
Stack* copy(Stack* const);
void invStack(Stack* const);
int countImpar(Stack* const);
int countPar(Stack* const);

int main()
{
    Stack* stack = newStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 4);
    Stack* stack2 = newStack();
    push(stack2, 1);
    push(stack2, 2);
    push(stack2, 3);
    cout << "Essas listas sao iguais? " << endl;
    if(isEqual(stack,stack2)) cout << "Sim!!!" << endl;
    else cout << "Nao sao iguais" << endl;

    cout << "====================" << endl;
    cout << maxNodeValue(stack) << endl;
    cout << minNodeValue(stack) << endl;
    cout << meanStack(stack) << endl;

    cout << "====================" << endl;
    printStack(stack);
    Stack* copystack = copy(stack);
    printStack(copystack);
    cout << "Numero de numeros impares: " << countImpar(stack) << endl;
    cout << "Numero de numeros pares: " << countPar(stack) << endl;

    return 0;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iValue = iValue;
    temp->ptrLow = nullptr;
    return temp;
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
    temp->ptrLow = pilha->ptrTop;
    pilha->ptrTop = temp;
}

bool isEqual(Stack* const stack1, Stack* const stack2)
{
    Node* current1 = stack1->ptrTop;
    Node* current2 = stack2->ptrTop;
    int count1=0;
    int count2=0;
    while(current1)
    {
        count1++;
        current1 = current1->ptrLow;
    }
    while(current2)
    {
        count2++;
        current2 = current2->ptrLow;
    }
    if(count1!=count2)
    {
        if(count1 > count2)
        {
            cout << "Pilha 1 maior que pilha 2" << endl;
        }
        else
        {
            cout << "Pilha 2 maior que pilha 1" << endl;
        }
        return 0;
    }
    else
    {
        Node* current1 = stack1->ptrTop;
        Node* current2 = stack2->ptrTop;
        while(current1)
        {
            if(current1->iValue!=current2->iValue)
            {
                return 0;
            }
            current1 = current1->ptrLow;
            current2 = current2->ptrLow;
        }
        return 1;
    }
}

int maxNodeValue(Stack* const pilha)
{
    Node* current = pilha->ptrTop;
    int max = current->iValue;
    while(current)
    {
        if(current->iValue > max)
        {
            max = current->iValue;
        }
        current = current->ptrLow;
    }
    return max;
}

int minNodeValue(Stack* const pilha)
{
    Node* current = pilha->ptrTop;
    int min = current->iValue;
    while(current)
    {
        if(current->iValue < min)
        {
            min = current->iValue;
        }
        current = current->ptrLow;
    }
    return min;
}

float meanStack(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "Pilha vazia" << endl;
    }
    
    float length = 0;
    float sum = 0;
    Node* current = stack->ptrTop;
    while(current)
    {
        sum+=current->iValue;
        length++;
        current = current->ptrLow;
    }
    return sum/length;
}

void invStack(Stack* const stack)
{
    Stack* temp = newStack();
    Node* current = stack->ptrTop;
    while(current)
    {
        push(temp,current->iValue);
        current = current->ptrLow;
    }
    Node* tempTop = temp->ptrTop;
    current = stack->ptrTop;
    while(tempTop)
    {
        current->iValue = tempTop->iValue;
        tempTop = tempTop->ptrLow;
        current = current->ptrLow;
    }
    free(temp);
    free(tempTop);
}

Stack* copy(Stack* const stack)
{
    Stack* temp = newStack();
    Node* current = stack->ptrTop;
    while(current)
    {
        push(temp,current->iValue);
        current = current->ptrLow;
    }
    invStack(temp);
    return temp;
}

void printStack(Stack* const stack)
{
    Node* current = stack->ptrTop;
    while(current)
    {
        cout << current->iValue << " ";
        current = current->ptrLow;
    }
    cout << endl;
}

int countImpar(Stack* const stack)
{
    int count = 0;
    Node* current = stack->ptrTop;
    while(current)
    {
        if((current->iValue%2) != 0)
        {
            count++;
        }
        current = current->ptrLow;
    }
    return count;
}

int countPar(Stack* const stack)
{
    int count = 0;
    Node* current = stack->ptrTop;
    while(current)
    {
        if((current->iValue%2) == 0)
        {
            count++;
        }
        current = current->ptrLow;
    }
    return count;
}