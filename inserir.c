#include "inserir.h"
#include "ListaDinEncad.h"
#include "normal.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

//recebe a qntd de linhas e colunas (em "char") do terminal
extern int linhas, colunas;

char modo_inserir(int *cursor, Lista *lista_char)
{
    char entrada = 'a', retorno = 'a'; //inicializando para prevenir problemas
    int controle = 1;
    while (controle)
    {
        clear_screen();

        printf("\033[%d;%dH --INSERIR-- \033[%d;%dH", linhas, colunas, 0,
               0); // escreve o modo

        imprime_lista(lista_char); //imprime os caracteres na tela

        move_cursor(cursor, lista_char); // move o cursor de acordo com a lista

        entrada = mygetch(); // recebe uma entrada

        if (entrada == 27) //esc
        {
            retorno = 27;
            controle = 0;
        }

        if (entrada == 127) //backspace
        {
            remove_lista(lista_char, cursor);
        }

        else if (entrada == 10 || (entrada <= 126 && entrada >= 32))
        {
            insere_lista_antes(lista_char, entrada, cursor);
        }
    }

    return retorno;
}
