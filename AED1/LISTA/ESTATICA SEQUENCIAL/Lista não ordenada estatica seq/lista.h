
typedef struct lista Lista;

Lista* cria_lista();
Lista* concatena(Lista *lst, Lista *lst1);
int lista_vazia(Lista *lst);
int lista_cheia(Lista *lst);
int insere_elem(Lista *lst, int elem);
int remove_elem (Lista *lst, int elem);
int printar(Lista *lst);
int remove_todos(Lista *lst, int elem);
int add_inicius(Lista *lst, int elem, int tam);
int remove_impar(Lista *lst);
int menor_elem(Lista *lst);
int tamanho(Lista *lst);
