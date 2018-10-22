
typedef struct lista Lista;

Lista* cria_lista();
Lista* intercala_ord(Lista *lst, Lista *lst1);
int lista_vazia(Lista *lst);
int lista_cheia(Lista *lst);
int insere_ord(Lista *lst, int elem);
int remove_ord (Lista *lst, int elem);
int printar(Lista *lst);
int remove_todos(Lista *lst, int elem);
int remove_par(Lista *lst);
int maior(Lista  *lst);
int tamanho(Lista *lst);
int compara(Lista *lst, Lista *lst1);
