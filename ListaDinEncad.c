#include "ListaDinEncad.h"

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

//cria a lista encadeada
Lista *cria_lista()
{
    Lista *li;

    li = (Lista *)malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

//libera a lista e todos os seus elementos
void libera_lista(Lista *li)
{
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//insere um nó no final da lista
//importante na leitura do arquivo
int insere_lista_final(Lista *li, Tipo_Dado dt)
{
    Elem *no;

    if (li == NULL)
        return ERRO;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    no->prox = NULL;
    if ((*li) == NULL)
    { //lista vazia: insere início
        *li = no;
    }
    else
    {
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return OK;
}

//insere um elemento antes de uma determinada posição determinada por "cursor"
//importante na função de mostrar ponteiro
int insere_lista_antes(Lista *li, Tipo_Dado dt, int *cursor)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;

    no->dado = dt;
    if ((*cursor == 0) && (*li == NULL))
    { // Lista vazia
        no->prox = NULL;
        *li = no;
        *cursor = 1;
        return OK;
    }
    else
    {
        Elem *ant, *atual = *li;
        int num = 1;
        while (atual != NULL && num != *cursor)
        { // Acha o nodo e seu anterior
            ant = atual;
            atual = atual->prox;
            num++;
        }

        if (atual == *li)
        { //insere antes (no inicio da lista)
            no->prox = (*li);
            *li = no;
            (*cursor)++;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
            (*cursor)++;
        }
        return OK;
    }
}

//remove uma nó da lista de acordo com a posição do cursor
//se cursor = 1, não remove
int remove_lista(Lista *li, int *cursor)
{
    if (li == NULL)
        return ERRO;
    if ((*li) == NULL) //lista vazia
        return ERRO;

    Elem *ant, *no = *li;
    int num = 1;
    while (no != NULL && num < *cursor - 1)
    {
        ant = no;
        no = no->prox;
        num++;
    }

    if (*cursor == 1 || tamanho_lista(li) == 1)
    {
        return ERRO;
    }

    if (*li == no)
    { //remover o primeiro?
        *li = no->prox;
        *cursor = 1;
    }
    else
    {
        ant->prox = no->prox;
        (*cursor)--;
    }
    free(no);
    return OK;
}

//retorna o tamanho da lista
int tamanho_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

//retorna o "status" da lista
int lista_vazia(Lista *li)
{
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

//imprime_lista a lista de caracteres na tela
void imprime_lista(Lista *li)
{
    if (li == NULL)
        return;
    Elem *no = *li;
    while (no != NULL)
    {
        printf("%c", no->dado);
        no = no->prox;
    }
}

//lê o arquivo dado e coloca cada caracter deste em uma lista encadeada dada
//adiciona um " " no final da lista
int le_arquivo(Lista *li, char arq[])
{
    FILE *fp;
    fp = fopen(arq, "r");

    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return 0;
    }

    char ch;
    while ((ch = getc(fp)) != EOF)
        insere_lista_final(li, ch);

    insere_lista_final(li, ' ');

    fclose(fp);
    return 1;
}

//move o cursor de acordo com a sequencia de caracteres recebidas
//"\n" = move para baixo e volta para o começo da linha
//se não, move para a direita
void move_cursor(int *cursor, Lista *li)
{
    if (li == NULL)
        return;

    Elem *no = *li;
    int num = 1;
    printf("\033[0;0H"); //move pro começo

    while (num < *cursor && num < tamanho_lista(li))
    {
        if (no->dado != '\n')
            printf("\033[1C"); // Move right 1 column;
        else
            printf("\033[1B\r"); // Move down + go back

        no = no->prox;
        num++;
    }
}

//salva cada letra da lista encadeada no arquivo
int salva_arquivo(Lista *li, char arq[])
{
    FILE *fp;
    fp = fopen(arq, "w");

    if (arq == NULL)
    {
        printf("Problemas na ABERTURA do arquivo\n");
        return 0;
    }

    Elem *no = *li;
    while (no != NULL)
    {
        fputc(no->dado, fp);
        no = no->prox;
    }

    fclose(fp);
    return 1;
}
