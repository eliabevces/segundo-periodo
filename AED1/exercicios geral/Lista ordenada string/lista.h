
typedef struct lista Lista;
typedef char* palavra;

Lista* cria_lista();
int lista_vazia(Lista *lst);
int lista_cheia(Lista *lst);
void printar(Lista *lst);
void libera(Lista **a);
int insere_ord(Lista *, palavra x); //(lista*)
int remove_ord (Lista *lst, palavra x);