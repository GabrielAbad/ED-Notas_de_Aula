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
void insertAfter(Node*, int);
void insertBefore(Node*, int);
void deleteNode(Node**, Node*);


// TAREFA EXTRA:
void insertBefore(Node**, Node*, int);
Node* searchNodebyValue(Node**, int);
void deleteNodebyValue(Node**, int);
void swapNodeWithNext(Node**, Node*);

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
    cout << "==============================" << endl;
    insertFront(&head, 99);
    displayList(head);
    cout << "==============================" << endl;
    insertAfter(nullptr, 501);
    insertAfter(head, 1000);
    displayList(head);
    cout << "==============================" << endl;
    deleteNode(&head, head);
    displayList(head);
    cout << "==============================" << endl;
    cout << "------" << endl;
    cout << "TAREFA EXTRA:" << endl;
    cout << "------" << endl;
    insertBefore(&head, nullptr, 501);
    cout << head->iPayload << endl;
    insertBefore(&head, head, 442);
    displayList(head);
    cout << "==============================" << endl;
    cout << searchNodebyValue(&head, 1000) << endl;
    cout << head->ptrNext << endl;
    cout << "==============================" << endl;
    deleteNodebyValue(&head, 442);
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
    
    if(*head != nullptr) 
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    
    (*head) = newNode;
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

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (!ptrLocation)
    {
        cout << "Location eh null" << endl; 
        return;   
    }
    Node* newNode = createNode(iPayload);
    
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;
    
    ptrLocation->ptrNext = newNode;
    
    if(newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}


void deleteNode(Node** head, Node* ptrDelete)
{
    if((*head) == nullptr || ptrDelete == nullptr)
    {
        cout << "deleteNode: Lista vazia." << endl;
        return;
    }
    
    // caso: primeiro da lista vai ser deletado
    if((*head) == ptrDelete) (*head) = ptrDelete->ptrNext;
    
    // caso: ptrDelete nao é o ultimo node
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // caso: ptrDelete nao é o primeiro node
    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete);
}

void insertBefore(Node** head, Node* ptrLocation, int iPayload) 
{
    Node* newNode = createNode(iPayload);
    
    if (ptrLocation == nullptr) 
    {
        cout << "insertBefore: Local vazio" << endl;
        return;
    }

    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;
    ptrLocation->ptrPrev = newNode;

    if (newNode->ptrPrev != nullptr) 
    {
        newNode->ptrPrev->ptrNext = newNode;
    } 
    else 
    {
        *head = newNode;
    }
}

Node* searchNodebyValue(Node** head, int iPayload)
{
    if((*head) == nullptr)
    {
        cout << "searchNodebyValue: Lista vazia." << endl;
        return nullptr;
    }
    
    Node* current = *head;
    while(current)
    {
        if(current->iPayload == iPayload)
        {
            return current;
        }
        current = current->ptrNext;
    }
    cout << "searchNodebyValue: Valor nao encontrado" << endl;
    return nullptr;
}

void deleteNodebyValue(Node** head, int iPayload)
{
    Node* temp = searchNodebyValue(head,iPayload);
    deleteNode(head,temp);
}


void swapNodeWithNext(Node** head, Node* x)
{
    Node* next = x->ptrNext;
    if(next == nullptr)
    {
        cout << "swapNodeWithNext: Nao existe proximo elemento" << endl;
        return;
    }
    
    Node* prev = x->ptrPrev;

    // padrao para qualquer nó existente da lista que não seja o último
    x->ptrNext = next->ptrNext;
    x->ptrPrev = next;
    
    // se nao for o penultimo
    if(next->ptrNext != nullptr)
    {
        x->ptrNext->ptrPrev = x;
    }
    
    next->ptrNext = x;
    next->ptrPrev = prev;

    // se nao for o primeiro
    if(prev != nullptr)
    {
        next->ptrPrev->ptrNext = next;
    }   

    // se o primeiro da lista vai ser o trocado
    if(*head == x)
    {
        *head = next;
    }
    
    return;
}