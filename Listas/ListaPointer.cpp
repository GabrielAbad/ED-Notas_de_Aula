#include <iostream>

using std::cout;
using std::endl;


typedef struct Aluno{
    int iMatricula;
    Aluno* ptrNext;
} Aluno;

typedef struct ListaMatriculas{
    Aluno* ptrFirst;
} ListaMatriculas;

ListaMatriculas* newList();
Aluno* newAluno(int);
void printMatriculas(ListaMatriculas* const);
void addMatricula(ListaMatriculas* const, int);
void removeMatricula(ListaMatriculas* const, int);
void trocaLastFirst(ListaMatriculas* const);
ListaMatriculas* intersectionLists(ListaMatriculas* const, ListaMatriculas* const);
bool isCycle(ListaMatriculas* const);
int tamanhoDoCiclo(ListaMatriculas* const);
void deleteEntireList(ListaMatriculas* const);
bool insertWithRepetitionCheck(ListaMatriculas* const, int);
void deleteNodeX(ListaMatriculas* const, int);

int main()
{
    /*
    ListaMatriculas* listamatriculas = newList();
    
    // questao 1
    printMatriculas(listamatriculas);
    addMatricula(listamatriculas, 1);
    addMatricula(listamatriculas, 2);
    addMatricula(listamatriculas, 3);
    addMatricula(listamatriculas, 4);
    printMatriculas(listamatriculas);

    cout << "=====================" << endl;

    // questao 2
    ListaMatriculas* listamatriculas2 = newList();
    removeMatricula(listamatriculas2, 2);
    printMatriculas(listamatriculas2);
    addMatricula(listamatriculas2, 1);
    addMatricula(listamatriculas2, 2);
    addMatricula(listamatriculas2, 3);
    addMatricula(listamatriculas2, 4);
    printMatriculas(listamatriculas2);
    removeMatricula(listamatriculas2, 2);
    printMatriculas(listamatriculas2);

    cout << "=====================" << endl;

    //questao 3
    trocaLastFirst(listamatriculas);
    printMatriculas(listamatriculas);
    trocaLastFirst(listamatriculas2);
    printMatriculas(listamatriculas2);
    ListaMatriculas* listamatriculas3 = newList();
    addMatricula(listamatriculas3, 1);
    trocaLastFirst(listamatriculas3);
    printMatriculas(listamatriculas3);

    cout << "=====================" << endl;

    //questao 4
    addMatricula(listamatriculas, 6);
    addMatricula(listamatriculas2, 9);
    addMatricula(listamatriculas2, 6);
    printMatriculas(listamatriculas);
    printMatriculas(listamatriculas2);
    ListaMatriculas* intersection = intersectionLists(listamatriculas,listamatriculas2);
    printMatriculas(intersection);

    cout << "=====================" << endl;

    ListaMatriculas* listamatriculas5 = newList();
    addMatricula(listamatriculas5, 6);
    addMatricula(listamatriculas5, 9);
    addMatricula(listamatriculas5, 1);
    addMatricula(listamatriculas5, 2);
    addMatricula(listamatriculas5, 3);
    printMatriculas(listamatriculas5);
    
    //cria um ciclo
    Aluno* temp = listamatriculas5->ptrFirst;
    while (temp->ptrNext != NULL) {
        if (temp->iMatricula == 3) {
            break;
        }
        temp = temp->ptrNext;
    }
    temp->ptrNext = listamatriculas5->ptrFirst->ptrNext->ptrNext;

    cout << isCycle(listamatriculas5) << endl;
    cout << tamanhoDoCiclo(listamatriculas5) << endl;
    */
    
    cout << "=====================" << endl;
    ListaMatriculas* lista = newList();
    addMatricula(lista, 10);
    addMatricula(lista, 20);
    addMatricula(lista, 30);
    addMatricula(lista, 40);
    addMatricula(lista, 40);
    addMatricula(lista, 40);
    printMatriculas(lista);

    cout << "=====================" << endl;
    deleteNodeX(lista,40);
    printMatriculas(lista);
    return 0;
}

Aluno* newAluno(int iMatricula)
{
    Aluno* temp = (Aluno*) malloc(sizeof(Aluno));
    temp->ptrNext = nullptr;
    temp->iMatricula = iMatricula;
    return temp;
}

ListaMatriculas* newList()
{
    ListaMatriculas* temp = (ListaMatriculas*) malloc(sizeof(ListaMatriculas));
    temp->ptrFirst = nullptr;
    return temp;
}

void addMatricula(ListaMatriculas* const listamatriculas, int iMatricula)
{
    if(listamatriculas == nullptr)
    {
        cout << "Ponteiro para lista de matriculas nao pode ser vazio" << endl;
        return;
    }
    
    Aluno* temp = newAluno(iMatricula);
    if(listamatriculas->ptrFirst == nullptr)
    {
        listamatriculas->ptrFirst = temp;
        return;
    }
    
    Aluno* current = listamatriculas->ptrFirst;
    while(current->ptrNext != nullptr)
    {
        current = current->ptrNext;
    }
    current->ptrNext = temp;
}

void printMatriculas(ListaMatriculas* const listamatriculas)
{
    if(listamatriculas == nullptr)
    {
        cout << "Essa lista nao existe" << endl;
        return;
    }
    if(listamatriculas->ptrFirst == nullptr) 
    {
        cout << "Lista sem matriculas." << endl;
        return;
    }
    
    Aluno* current = listamatriculas->ptrFirst;
    while(current)
    {
        cout << current->iMatricula << " ";
        current = current->ptrNext;
    }
    cout << endl;
}

void removeMatricula(ListaMatriculas* const listamatriculas, int iMatricula)
{
    if(listamatriculas->ptrFirst == nullptr)
    {
        cout << "Nao temos alunos a remover." << endl;
        return;
    }

    Aluno* temp = listamatriculas->ptrFirst;
    if(listamatriculas->ptrFirst->iMatricula == iMatricula)
    {
        listamatriculas->ptrFirst = listamatriculas->ptrFirst->ptrNext;
        free(temp);
        return;
    }

    // caso geral: remover um aluno, inclui fazer com que o anterior a ele, aponte pro next do elemento a ser removido

    Aluno* previous = nullptr;
    Aluno* current = listamatriculas->ptrFirst;

    while(current != nullptr && current->iMatricula != iMatricula)
    {
        previous = current;
        current = current->ptrNext;
    }

    if(current == nullptr)
    {
        cout << "Matricula nao encontrada, nao tem o que remover." << endl;
        return;
    }
    
    previous->ptrNext = current->ptrNext;

    free(current);
}

void trocaLastFirst(ListaMatriculas* const listamatriculas)
{
    Aluno* previous = nullptr;
    Aluno* current = listamatriculas->ptrFirst;
    while (current->ptrNext != nullptr)
    {
        previous = current;
        current = current->ptrNext;
    }
    
    previous->ptrNext = listamatriculas->ptrFirst;
    current->ptrNext = listamatriculas->ptrFirst->ptrNext;
    listamatriculas->ptrFirst->ptrNext = nullptr;
}

ListaMatriculas* intersectionLists(ListaMatriculas* const lista1, ListaMatriculas* const lista2)
{
    ListaMatriculas* temp = newList();
    if(lista1->ptrFirst == nullptr || lista2->ptrFirst == nullptr)
    {
        return temp;
    }
    
    Aluno* current1 = lista1->ptrFirst;
    while(current1!=nullptr)
    {
        Aluno* current2 = lista2->ptrFirst;
        while(current2 != nullptr)
        {
            if(current1->iMatricula == current2->iMatricula)
            {
                addMatricula(temp,current1->iMatricula);
            }
            current2 = current2->ptrNext;
        }
        current1 = current1->ptrNext;
    }
    return temp;
}

// usar tartaruga e coelho , se se encontrarem é ciclo
bool isCycle(ListaMatriculas* const listamatriculas)
{
    Aluno* tortoise = listamatriculas->ptrFirst;
    Aluno* hare = listamatriculas->ptrFirst;

    while (hare != NULL && hare->ptrNext != NULL)
    {
        tortoise = tortoise->ptrNext;
        hare = hare->ptrNext->ptrNext;

        if (tortoise == hare) {
            return 1;
        }
    }
    return 0;
}

int tamanhoDoCiclo(ListaMatriculas* const lista) {
    Aluno* tortoise = lista->ptrFirst;
    Aluno* hare = lista->ptrFirst;
    int encontrado = 0;
    int tamanho = 0;

    // lembrar que a quantidade de iterações até eles se encontrarem pela segunda vez é o tamanho do ciclo
    while (hare != NULL && hare->ptrNext != NULL) 
    {
        tortoise = tortoise->ptrNext;
        hare = hare->ptrNext->ptrNext;

        if (tortoise == hare && !encontrado) 
        {
            encontrado = 1;
        } else if (tortoise == hare && encontrado) 
        {
            break;
        }
        if (encontrado) 
        {
            tamanho++;
        }
    }
    return tamanho;
}

void deleteEntireList(ListaMatriculas* const lista)
{
    Aluno* current = lista->ptrFirst;
    Aluno* next = nullptr;
    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current);           
        current = next;           
    }
    lista->ptrFirst = nullptr;
}

bool insertWithRepetitionCheck(ListaMatriculas* const lista, int iMatricula)
{
    Aluno* current = lista->ptrFirst;
    while(current)
    {
        if(current->iMatricula == iMatricula)
        {
            return 1;
        }
        current = current->ptrNext;
    }
    return 0;
}

// deletar todos os nós que tenham elemento x na lista

void deleteNodeX(ListaMatriculas* const lista, int iMatricula)
{
    if(lista->ptrFirst == nullptr)
    {
        cout << "Lista Vazia" << endl;
        return;
    }

    Aluno* current = lista->ptrFirst;
    Aluno* previous = nullptr;
    while(current)
    {
        Aluno* next = current->ptrNext;

        if(current->iMatricula == iMatricula)
        {
            // caso primeiro da fila é pra ser removido
            if(previous == nullptr)
            {
                lista->ptrFirst = next;
            }
            // caso geral
            else
            {
                previous->ptrNext = next;
            }
            free(current);
            current = next;
        }
        else
        {
            previous = current;
            current = next;
        }
    }
}
