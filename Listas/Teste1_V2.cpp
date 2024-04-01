#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void anoOcorrido(int iAnosAtras)
{
   if(iAnosAtras>2024)
   {
	cout << -(2024-iAnosAtras) << " A.C." << endl;
   }
   else
   {
   	cout << 2024 - iAnosAtras << " D.C." << endl;
   }
}

int Fact(int n)
{
    if(n==1)
    {
   	return 1;
    }

    return n * Fact(n-1);
}

void printNFacts(int n)
{
     for(int i = 1; i<=n; i++)
     {
	  cout << Fact(i) << " ";
     }
}

void operarArrays(int arriA[5][5], int arriB[5][5], char cOperador)
{
    for(int i = 0; i<5; i++)
    { 
 	    for(int j = 0; j<5; j++)
	    {
		    if(cOperador == '+')
		    {
			    arriA[i][j] = arriA[i][j] + arriB[i][j];
		    }
		    else if(cOperador == '-')
		    {   
			    arriA[i][j] = arriA[i][j] - arriB[i][j];
            }
        }
	}
}




int main()
{
    int iAnosAtras = 0;
    cin >> iAnosAtras;
    anoOcorrido(iAnosAtras);

    cout << "========================" << endl;

    int iNum = 0;
    cin >> iNum;
    printNFacts(iNum);
    cout << endl;
    cout << "========================" << endl;


    int b[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int c[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 0, 0, 5}
    };

    operarArrays(b, c, '+'); 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    operarArrays(b, c, '-');

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}