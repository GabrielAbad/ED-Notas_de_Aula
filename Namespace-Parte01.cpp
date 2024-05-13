#include <iostream>

using namespace std;

namespace EMAp
{
    int iValor =42;
    void mockFunction()
    {
        cout << "Namespace EMAp" << endl;
    }
}

namespace FGV
{
    int iValor =666;
    void mockFunction()
    {
        cout << "Namespace FGV" << endl;
    }
}

int iValor = 1;

using EMAp::mockFunction;

int main()
{
    int iValor = 10;
    cout << "Namespace local: " << iValor << endl;
    cout << "Namespace global: " << ::iValor << endl;
    cout << "Namespace FGV: " << FGV::iValor << endl;
    cout << "Namespace EMAp: " << EMAp::iValor << endl;
    
    FGV::mockFunction();
    EMAp::mockFunction();
    
    mockFunction();
    
    return 0;
}


