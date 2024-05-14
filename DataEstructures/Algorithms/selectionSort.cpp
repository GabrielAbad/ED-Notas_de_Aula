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
void selectionSortRuim(int[], int);
void optimizedselectionSort(int[], int);

int main()
{
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);
    cout << "Arrayy original: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeStart = high_resolution_clock::now();
    selectionSortRuim(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now();

    cout << "Arrayy ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;

    cout << "===================================" << endl;
    
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize_2 = sizeof(arriNumbers_2)/sizeof(arriNumbers_2[0]);
    cout << "Array 2 original: ";
    printArray(arriNumbers_2, iArraySize_2);
    
    timeStart = high_resolution_clock::now();
    optimizedselectionSort(arriNumbers_2, iArraySize_2);
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

void selectionSortRuim(int arriNumbers[], int iLength)
{
    for(int i = 0; i<iLength; i++)
    {
        for(int j = i+1; j<iLength; j++)
        {
            if(arriNumbers[i] > arriNumbers[j])
            {
                swapValue(arriNumbers[i], arriNumbers[j]);
            }
        }
    }
}

void optimizedselectionSort(int arriNumbers[], int iLength)
{
    int minValue = 0;
    int iSwapValue = 0;
    for(int i = 0; i<iLength; i++)
    {
        minValue = arriNumbers[i];
        iSwapValue = i;
        for(int j = i+1; j<iLength; j++)
        {
            if(minValue > arriNumbers[j])
            {
                minValue = arriNumbers[j];
                iSwapValue = j;
            }
        }
        swapValue(arriNumbers[i], arriNumbers[iSwapValue]);
    }
}