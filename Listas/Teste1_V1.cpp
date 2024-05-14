#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printPiramide2D(int);
bool isPrime(int);
int countPrimes(int);

int main()
{

	printPiramide2D(4);
    cout << isPrime(5) << endl;
    cout << isPrime(4) << endl;
	
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    cout << "Number of prime numbers up to " << n << " is: " << countPrimes(n) << endl;
}

bool isPrime(int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void printPiramide2D(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = n-1-i; j > 0 ; j--)
        {
            cout << " ";
        }
        for(int k = 0; k < i+1; k++)
        {
            cout << "##";
        }
        cout << endl;
    }
    for(int i = n; i>0 ; i--)
    {
        for(int j = 0; j<n-i+1 ; j++)
        {
            cout << " ";
        }
        for(int k = n-i+1; k<n; k++)
        {
            cout << "##";
        }
        cout << endl;
    }
    return;
}

int countPrimes(int n)
{
    if(n==1)
    {
        return 0;
    }
    return countPrimes(n-1) + isPrime(n);
}