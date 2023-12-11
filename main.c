#include "ListaDinEncad.h"
#include "inserir.h"
#include "normal.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int linhas, colunas;

int main(int argc, char *argv[])
{
    char modo;
    int cursor = 1;

    window_size(&linhas, &colunas);

    Lista *lista_caracteres;
    lista_caracteres = cria_lista();

    le_arquivo(lista_caracteres, argv[1]);

    while (1)
    {
        modo = modo_normal(&cursor, lista_caracteres);
        if (modo == 'i')
            modo = modo_inserir(&cursor, lista_caracteres);
        else if (modo == 27)
            break;
    }

    clear_screen();
    salva_arquivo(lista_caracteres, argv[1]);
    libera_lista(lista_caracteres);

    return 0;
}
