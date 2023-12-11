#ifndef LISTADINENCAD_H_
#define LISTADINENCAD_H_

#define FALSO 0
#define VERDADEIRO 1

#define OK 1
#define ERRO 0

typedef char Tipo_Dado;

//Definição do tipo lista
struct elemento
{
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento *Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
int remove_lista(Lista *li, int *);
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
void imprime_lista(Lista *li);

int insere_lista_final(Lista *li, Tipo_Dado dt);
// Novas rotinas: Insere Antes e Insere Depois
int insere_lista_antes(Lista *li, Tipo_Dado dt, int *cursor);

int le_arquivo(Lista *li, char arq[]);
int salva_arquivo(Lista *li, char arq[]);
#endif

void move_cursor(int *cursor, Lista *li);
