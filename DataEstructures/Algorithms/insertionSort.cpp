#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;


void printArray(int[], int);
void insertionSort(int [], int);


int main()
{
    cout << "===================================" << endl;
    cout << "-- Insertion Sort --" << endl;
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);
    cout << "Arrayy original: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeStart = high_resolution_clock::now();
    insertionSort(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Arrayy ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;   


    cout << "===================================" << endl;
    int arriNumbers_2[] = {1,2,3,4,5,6,7};
    int iArraySize_2 = sizeof(arriNumbers_2)/sizeof(arriNumbers_2[0]);
    cout << "Arrayy original: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeStart = high_resolution_clock::now();
    insertionSort(arriNumbers_2, iArraySize_2);
    timeStop = high_resolution_clock::now();
    
    cout << "Arrayy ordenado: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;   

    return 0;
}


void printArray(int arriNumbers[], int iLength)
{
    for(int i =0; i<iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
}

void insertionSort(int arriNumbers[], int iLength)
{
    int iInsertValue = 0;
    int iInnerLoop = 0;
    for(int iOuterLoop = 1; iOuterLoop < iLength; iOuterLoop++)
    {
        iInsertValue = arriNumbers[iOuterLoop];
        iInnerLoop = iOuterLoop - 1;

        while(iInsertValue < arriNumbers[iInnerLoop] && iInnerLoop >= 0)
        {
            arriNumbers[iInnerLoop + 1] = arriNumbers[iInnerLoop];
            iInnerLoop--;
        }

        arriNumbers[iInnerLoop + 1] = iInsertValue;
    }
    return;
}