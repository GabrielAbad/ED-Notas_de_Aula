#include <iostream>

using std::cout;
using std::endl;


typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;
 
typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;

LinkedList* newLinkedList();
Node* newNode(int);
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void removeElement(LinkedList* const, int);

int main()
{
    LinkedList* linkedlist = newLinkedList();
    addElement(linkedlist, 1);
    addElement(linkedlist, 3);
    addElement(linkedlist, 7);
    addElement(linkedlist, 8);
    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showElements(linkedlist);
    cout << "-------------" << endl;
    removeElement(linkedlist, 1);
    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showElements(linkedlist);
    cout << "-------------" << endl;
    removeElement(linkedlist,8);
    showFirstElement(linkedlist);
    showLastElement(linkedlist);
    showElements(linkedlist);

    return 0;
}

Node* newNode(int iData)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iData;
    temp->ptrNext = nullptr;
    return temp;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;
    return temp;
}

void showFirstElement(LinkedList* const linkedlist)
{
    if(linkedlist->ptrFirst == nullptr) cout << "showFirstElement: Nao tem elemento na lista" << endl;
    else cout << "O primeiro elemento da lista: " << linkedlist->ptrFirst->iData << endl;
}

void showLastElement(LinkedList* const linkedlist)
{
    if(linkedlist->ptrFirst == nullptr) 
    {
        cout << "showLastElement: Nao tem elemento na lista" << endl;
        return;
    }
    
    Node* current = linkedlist->ptrFirst;
    while(current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    cout << "O ultimo elemento da lista: " << current->iData << endl;

}

void addElement(LinkedList* const linkedlist, int iData)
{
    Node* temp = newNode(iData);
    if(linkedlist->ptrFirst == nullptr)
    {
        linkedlist->ptrFirst = temp;
        return;
    } 
    
    Node* current = linkedlist->ptrFirst;
    while(current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    current->ptrNext = temp;
}

void removeElement(LinkedList* const linkedlist, int iData)
{
    if(linkedlist->ptrFirst == nullptr)
    {
        cout << "removeElement: Lista vazia nao tem o que remover" << endl;
        return;
    }
    
    Node* previous = nullptr;
    Node* current = linkedlist->ptrFirst;

    // Verifica se o primeiro nó tem o dado a ser removido
    if(current->iData == iData)
    {
        linkedlist->ptrFirst = current->ptrNext;
        free(current);
        return;
    }

    // Percorre a lista para encontrar o nó com o dado a ser removido
    while(current != nullptr && current->iData != iData)
    {
        previous = current;
        current = current->ptrNext;
    }

    // Se o nó não foi encontrado, imprime mensagem e retorna
    if(current == nullptr)
    {
        cout << "Elemento nao encontrado na lista" << endl;
        return;
    }
    
    // Remove o nó da lista e libera a memóriase tem algum valor igual iData
    previous->ptrNext = current->ptrNext;
    free(current);
}

void showElements(LinkedList* const linkedlist)
{
    if(linkedlist->ptrFirst == nullptr)
    {
        cout << "showElements: Lista vazia" << endl;
        return;
    }

    Node* current = linkedlist->ptrFirst;
    while(current != nullptr)
    {
        cout << current->iData << " ";
        current = current->ptrNext;
    }
    cout << endl;
}