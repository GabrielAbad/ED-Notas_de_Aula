#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);

int main()
{
    Node* head = nullptr;
    displayList(head);
    cout << "==============================" << endl;
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);
    
    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;
    return temp;
}


void displayList(Node* node)
{
    if(node == nullptr)
    {
        cout << "displayList: Node nulo, lista vazia" << endl;
        return;
    }
    
    if(node->ptrPrev != nullptr)
    {
        cout << "displayList: Node prev nao nulo, nao podemos printar" << endl;
        return;
    }

    Node* current = node;
    
    cout << "Payload: ";
    
    while(current)
    {
        cout  << current->iPayload << " ";
        current = current->ptrNext;
    }
    
    cout << endl;
    
}


void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
}


void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    if(*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    
    Node* current = (*head);
    
    while(current->ptrNext != nullptr) current = current->ptrNext;
    
    newNode->ptrPrev = current; // new node aponta pra tras para o fim da lista
    current->ptrNext = newNode;
    
    
}
