#include <stdio.h>
#include <stdlib.h>

int manipula_pares(int *vetor, int N);

int main(){
    int N= 5, i, temp;
    int numeros[5];

    for(i=0;i<N;i++){
        printf("\nDigite o %do numero", i+1);
        scanf("%d", &numeros[i]);
    }
    manipula_pares(numeros, N);

    for(i=0;i<N;i++){
        printf("\n O %do numero do vetor resultante ")
    }
}
