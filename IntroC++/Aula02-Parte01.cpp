#include <iostream>;

using std::cout;

int main()
{
    // define o tipo de uma variavel automaticamente, péssimo
    auto i = 1;
    
    cout << "Exemplo de pós incremento: " << "\n";
    cout << "Valor de i: " << i << "\n";
    
    auto c = ++i; // Pré incremento, também existe pós incremento (i++)
    
    cout << "Valor de c: " << c << "\n";
    cout << "Valor de i: " << i << "\n";
    
    return 0;
}