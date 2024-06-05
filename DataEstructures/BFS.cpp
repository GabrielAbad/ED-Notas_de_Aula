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
int treeHeight(Node*);

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
    
    cout << "Tree Height: " << treeHeight(root);
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
    
    // Parte 1 do Trabalho: Alterar para lista encadeada
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
    
    while(iQueueFront < iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout<<currentNode->iPayload<<" ";
        
        if(currentNode->ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }
        if(currentNode->ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
    }
}

// Parte 2 do Trabalho: Elaborar busca utilizando BFS (já possuimos o DFS)
// PArte 3 do Trabalho: Monitorar o desempenho de busca em arvore utilizando DFS e BFS
// Parte 4 do trabalho: Monitorar o desempenho de criação de listas
// Parte 5 do trabalho: Monitorar o desempenho de criação de arvores


int treeHeight(Node* startingNode)
{
    if(startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight,iRightHeight) + 1;
    }
}
