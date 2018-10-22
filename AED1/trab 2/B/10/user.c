#include "deque.h"

int imprime_op(void);

int main(int argc, char **argv)
{
    int op = -1, elemento = 0;

    Deque D1 = cria_deque();

    system("clear");
    while(op != 6) {
        op = imprime_op();
        switch(op) {
            case 1:
                printf("Qual elemento será inserido no incio? ");
                scanf("%d", &elemento);
                if(insere_inicio(D1, elemento))
                    printf("Elemento inserido\n");
                else
                    printf("Erro:\n\tElemento não inserido\n");
                getchar();
                break;
            case 2:
                printf("Qual elemento será inserido no final? ");
                scanf("%d", &elemento);
                if(insere_final(D1, elemento))
                    printf("Elemento inserido\n");
                else
                    printf("Erro:\n\tElemento não inserido\n");
                getchar();
                break;
            case 3:
                printf("Removendo no inicio...\n");
                if(remove_inicio(D1))
                    printf("Elemento foi removido\n");
                else
                    printf("Erro:\n\tElemento nao foi removido\n");
                getchar();
                break;
            case 4:
                printf("Removendo no final...\n");
                if(remove_final(D1))
                    printf("Elemento foi removido\n");
                else
                    printf("Erro:\n\tElemento nao foi removido\n");
                getchar();
                break;
            case 5:
                imprime_deque(D1);
                getchar();
                break;
        }
        getchar();
        system("clear");
    }
    return 0;
}

int imprime_op()
{
    int op;

    do
    {
        printf("---------------- Qual a operacao? -----------------\n");
        printf("[1] - Inserir um elemento no inicio\n");
        printf("[2] - Inserir um elemento no final\n");
        printf("[3] - Remover um elemento no inicio\n");
        printf("[4] - Remover um elemento no final\n");
        printf("[5] - Imprimir a fila\n");
        printf("[6] - Sair do programa\n");
        printf("Operacao: "); setbuf(stdin,NULL);
        scanf("%d", &op);
    } while(op < 0);

    return op;
}