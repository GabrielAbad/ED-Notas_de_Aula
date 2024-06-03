#include <iostream>

using namespace std;

typedef struct Node
{
  int iPayload;
  Node* ptrLeft;
  Node* ptrRight;

} Node;

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);

int main()
{
    Node* root = nullptr;
    root = insertNode(root,42);
    root = insertNode(root,13);
    root = insertNode(root,11);
    root = insertNode(root,10);
    root = insertNode(root,28);
    root = insertNode(root,51);
    root = insertNode(root,171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    return 0;
}

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
  
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;

    return tmp;
}


Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}


// jeito tosco, vamos ter que mudar (fazer com uma estrutura de Fila)
void bfsTraversal(Node* startingNode)
{
    if(startingNode == nullptr) return;
    
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
}
