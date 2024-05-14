#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int iContador = 1;
    while(iContador <= 5)
    {
        cout << iContador << '\n';
        iContador++;
    }
    
    iContador = 42;
    
    do
    {
        cout << iContador << '\n';
        iContador++;
    } while(iContador <= 5); 
    
    for (int i = 0 ; i<11; i++)
    {
        for (int j = 0 ; j<11; j++)
        {
            for (int k = 0 ; k<11; k++)
            {
                cout << "(" << i << "," << j << "," << k << ")" << "\n";
            }
        }
    }
    // o i do for não existe fora do for
    
    return 0;
}