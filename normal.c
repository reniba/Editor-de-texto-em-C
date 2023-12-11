#include "normal.h"
#include "ListaDinEncad.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

//recebe a quantidade de linhas e colunas(em caracteres) declaradas na main
extern int linhas, colunas;

char modo_normal(int *cursor, Lista *lista_char)
{
    char entrada = 'a', retorno;
    int controle = 1;
    while (controle)
    {
        clear_screen();

        printf("\033[%d;%dH --NORMAL-- \033[%d;%dH", linhas, colunas, 0, 0); //printa o modo

        imprime_lista(lista_char);       //imprime os caracteres na tela
        move_cursor(cursor, lista_char); //move o cursor
        entrada = mygetch();             //recebe uma entrada

        //primeiro getch
        if (entrada == 27)
        {
            char c1 = mygetch(), c2 = mygetch();

            if (c1 == 27 && c2 == 27) // segundo ESC
            {
                retorno = 27;
                controle = 0;
                break;
            }
            entrada = c2;
        }
        //

        switch (entrada)
        {
        case 67: //move cursor para direita
            incrementa_cursor(cursor, lista_char);
            break;

        case 68: //move cursor para esquerda
            decrementa_cursor(cursor);
            break;

        case 'i': //modo inserir
            retorno = 'i';
            controle = 0;
            break;

            //case 27: //esc (sai do programa)
            //    retorno = 27;
            //    controle = 0;
            //    break;
            //
        }
    }
    return retorno;
}
