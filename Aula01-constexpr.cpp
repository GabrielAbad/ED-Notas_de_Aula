#include <cstdio>
    
// constexpr - valor é calculado no tempo de compilação, então quando 
// rodar o código o valor ja vai estar calculado.
constexpr int isqrt(int n){
    int i = 1;
    // enquanto i vezes i for menor que n pré incrementa 1 em i, ou seja,
    // qualque nova operação com i ja vai ser com o novo valor
    while(i*i<n)++i;
    return i-(i*i!=n);
}

int main(){
    constexpr int x = isqrt(16);
    // %d - para printr inteiro 
    printf("%d",x);
}