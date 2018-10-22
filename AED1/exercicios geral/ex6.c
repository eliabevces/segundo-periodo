#include <stdio.h>

typedef struct dados{
    char nome[16];
    int n;
}dados;

int manipula_vetor(int b);

int main(){
    int x, i, y;
    dados *a;
    printf("digite o tamanha do vetor de dados: ");
    scanf("%d", &x); //tamanha vetor
    a=(dados *)malloc(x*sizeof(dados));

    for(i=0;i<x;i++){
        printf("digite o %d nome: ", i+1);
        scanf("%s", &a[i].nome);
        printf("digite o numero de %s: ", a[i].nome);
        scanf("%d", &a[i].n);
    }

    for(i=0;i<x;i++){
        y=manipula_vetor(a[i].n);
        a[i].n=y;

    }


    for(i=0;i<x;i++){
        printf("--\t--\t--\t--\t--\t--\t\n");
        printf("nome:%s\nnumero:%d\n", a[i].nome, a[i].n);
    }
}

int manipula_vetor(int b){
    if(b%2==0) b=b/2;

    return b;
}

