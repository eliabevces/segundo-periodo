#include <stdio.h>
#include <string.h>

float media(float n1, float n2, float n3);
int situacao(int f, float m);
void printar(char *mat, char *nom, float n1, float n2, float n3, float m, int f, int s);


typedef struct aluno{
    char nummatricula[8];
    char nome[30];
    float nota[3];
    float m;
    int faltas;
    int sit;
}aluno;

void est(aluno A[3]);
void editar(aluno A[3]);

int main(){
    aluno a[3];
    int i;
    char x;

    strcpy(a[0].nummatricula, "123456");
    strcpy(a[1].nummatricula, "123457");
    strcpy(a[2].nummatricula, "123458");

    strcpy(a[0].nome, "the nardo");
    strcpy(a[1].nome, "marcus");
    strcpy(a[2].nome, "rogerio");

    //printf("++++++++++++%s++++++++", a[0].nome);
    a[0].nota[0]= 10;
    a[0].nota[1]= 7;
    a[0].nota[2]= 5;

    a[1].nota[0]= 5;
    a[1].nota[1]= 7;
    a[1].nota[2]= 6;

    a[2].nota[0]= 5;
    a[2].nota[1]= 7;
    a[2].nota[2]= 4;

for(i=0;i<3;i++){
    a[i].m= media(a[i].nota[0], a[i].nota[1], a[i].nota[2]);
}
    //printf("-----%f------\n\n\n", m[2]); teste

    a[0].faltas=0;
    a[1].faltas=20;
    a[2].faltas=15;

    a[0].sit=situacao(a[0].faltas, a[0].m);
    a[1].sit=situacao(a[1].faltas, a[1].m);
    a[2].sit=situacao(a[2].faltas, a[2].m);

  for( i=0;i<3;i++)
{
    printar(a[i].nummatricula, a[i].nome, a[i].nota[0], a[i].nota[1], a[i].nota[2], a[i].m, a[i].faltas, a[i].sit);
}

//estatisticas: aluno com maior nota EM CADA PROVA---- aluno com maior media geral----  aluno com menor media geral----- alunos com media acima ou igual a da turma

est(a);


do{
        printf("editar aluno? ");
        setbuf(stdin, NULL);
        scanf("%c", &x);
    }while(x != 'y' && x != 'n' && x != 'Y' && x!= 'N');

if(x == 'y' || x == 'Y')editar(a);

for( i=0;i<3;i++)
{
    printar(a[i].nummatricula, a[i].nome, a[i].nota[0], a[i].nota[1], a[i].nota[2], a[i].m, a[i].faltas, a[i].sit);
}

}

float media(float n1, float n2, float n3){
    float m;
    m= (n1+n2+n3)/3;
     return m;
}

int situacao(int f, float m){
    int n;

    if(f>18) return 0;
    if(m<6.0) return 1;
    else return 2;
}

void printar(char *mat, char *nom, float n1, float n2, float n3, float m, int f, int s){
    printf("matricula: %s\n", mat);
    printf("aluno: %s\n", nom);
    printf("prova 1: %f\n", n1);
    printf("prova 2: %f\n", n2);
    printf("prova 3: %f\n", n3);
    printf("media: %f\n", m);
    printf("faltas: %d\n", f);
    //printf("--%d--",s);
    if(s==0)printf("Reprovado por faltas.\n\n");
    if(s==1)printf("Reprovado por media menor que 6\n");
    if(s==2) printf("Aprovado\n\n");

}


void est(aluno A[3]){
int i,j,pos=0, pos_menor=0; // Questão (e)
    float media_turma=0.0, maior = A[0].nota[0], menor = 999999;
    for(j = 0; j < 3; j++)
    {
        printf("\n--\t--\t--\t--\n");
        printf("maior nota na prova %d: \n", j+1);
        for(i=0; i<3; i++)
        {
            if(A[i].nota[j]>maior)
            {
                maior=A[i].nota[j];
                pos=i;
            media_turma += A[i].nota[j];

            }
        }

        printf("Aluno: %s\n Nota: %.2f\n", A[pos].nome, maior);
        maior=0.0;

    }

    media_turma/=3.0;
    printf("\n--\t--\t--\t--\n");
printf("maior media geral:\n");
maior=0.0;
pos=0;
        for(i = 0; i < 3; i++)
        {
            if(A[i].m>maior)
            {
                maior=A[i].m;
                pos=i;
            }
            if(A[i].m<menor)
            {
                menor= A[i].m;
                pos_menor=i;
            }
        }

        printf("Aluno: %s\n Media: %.2f\n", A[pos].nome, maior);
        printf("\n--\t--\t--\t--\n");
        printf("menor media geral: \n");
        printf("Aluno: %s\n Media: %.2f\n", A[pos_menor].nome, menor);
        printf("\n--\t--\t--\t--\n");
        printf("media da turma: %.2f\n", media_turma);
        printf("Alunos com a media maior ou igual  a media da turma:\n");
        for(i=0; i<3; i++)
        {
            if(A[i].m>=media_turma)printf("Aluno: %s\n Media: %.2f\n", A[i].nome, A[i].m);
        }
}

void editar(aluno A[3]){
    char s[8];
    int k, i, j;

        printf("Digite a matricula do aluno: ");
        scanf("%s", &s);

    for(i=0;i<3;i++){
        k= strcmp(s,A[i].nummatricula);
        if(k==0){
            printf("Digite as 3 notas do aluno: \n");
            for(j=0;j<3;j++){
            scanf("%f", &A[i].nota[j]);
            }
    }
}
}
