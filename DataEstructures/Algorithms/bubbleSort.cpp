#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void swapValue(int&, int&);
void printArray(int[], int);
void bubbleSort(int[], int);
void bubbleSortRuim(int[], int);
void optimizedBubbleSort(int[], int);

int main()
{
    cout << "===================================" << endl;
    cout << "-- Bubble Sort Ruim --" << endl;
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);
    cout << "Arrayy original: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeStart = high_resolution_clock::now();
    bubbleSortRuim(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Arrayy ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;
    
    cout << "===================================" << endl;
    cout << "--Optimized Bubble Sort--" << endl;
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize_2 = sizeof(arriNumbers)/sizeof(arriNumbers[0]);
    cout << "Array 2 original: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeStart = high_resolution_clock::now();
    optimizedBubbleSort(arriNumbers_2, iArraySize_2);
    timeStop = high_resolution_clock::now();
    
    cout << "Array 2 ordenado: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;
     
    return 0;
}

void swapValue(int& irefValue1, int& irefValue2)
{
    int iTemp = irefValue1;
    irefValue1 = irefValue2;
    irefValue2 = iTemp;
}

void printArray(int arriNumbers[], int iLength)
{
    for(int i =0; i<iLength; i++) cout << arriNumbers[i] << " ";
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLength)
{
    int count = 1;
    while(count)
    {
        count = 0;
        for(int i = 0; i < iLength-1; i++)
        {
            if(arriNumbers[i] > arriNumbers[i+1])
            {
                swapValue(arriNumbers[i], arriNumbers[i+1]);
                count++;
            }
        } 
    }
}

void bubbleSortRuim(int arriNumbers[], int iLength)
{
    for(int iOuterLoop = 0; iOuterLoop<iLength-1; iOuterLoop++)
        for(int iInnerLoop = 0; iInnerLoop<iLength-1; iInnerLoop++)
            if(arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop+1])    
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
}

void optimizedBubbleSort(int arriNumbers[], int iLength)
{
    bool bUnordered = false;
    
    for(int iOuterLoop = 0; iOuterLoop<iLength-1; iOuterLoop++)
    {
        bUnordered = false;
        for(int iInnerLoop = 0; iInnerLoop<iLength-1-iOuterLoop; iInnerLoop++)
        {
            if(arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop+1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop+1]);
                bUnordered = true;
            }
        }
        if(bUnordered == false) break;
    }
}
