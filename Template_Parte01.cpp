#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T MAX(T x, T y)
{
    cout << typeid(T).name() << endl;
    return x > y? x:y;
}

// instanciacao explicita
template char MAX(char x, char y);

//
template<> const char* MAX<const char*>(const char* x, const char* y)
{
    return strcmp(x,y) > 0? x:y;
}

template<typename T>
T somaElementos(T* arr, int size)
{
    T soma;
    for(int i = 0; i<size; i++)
    {
        soma+=arr[i];
    }
    return soma;
}

int main()
{
    cout << MAX(13,42) << endl;
    cout << MAX(13.7f,42.11f) << endl;
    
    cout << "==========================" << endl;
    
    auto resultado_1 = MAX<double>(13,42.11f);
    cout << resultado_1 << endl;
    
    cout << "==========================" << endl;
    
    const char* b {"B"};
    const char* a {"A"};
    
    cout << "Endereço de B: " << &b << endl;
    cout << "Endereço de A: " << &a << endl;
    
    auto maior = MAX(a,b);
    cout << maior << endl;
    
    int arr[4] = {1,2,3,4};
    int soma = somaElementos(arr,5);
    cout << "Soma: " << soma << endl;    

    return 0;
}
