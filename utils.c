#include "utils.h"
#include "ListaDinEncad.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

//armazena nas variáveis globais row e col, respectivamente, a quantidade de colunas e linhas do
//terminal
void window_size(int *row, int *col)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *col = w.ws_col;
    *row = w.ws_row;
}

//"scanf sem enter"
//pausa o programa, recebe o próximo caracter digitado e retorna este caracter
int mygetch(void)
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

//limpa a tela
void clear_screen(void)
{
    system("clear");
}

//incrementa o valor da variável cursor e impede que este seja maior que o tamanho da lista de
//caracteres do arquivo
void incrementa_cursor(int *cursor, Lista *lista_char)
{
    if (*cursor < tamanho_lista(lista_char))
        (*cursor)++;
    else
        return;
}

//decrementa o valor da variável cursor e impede que este seja menor que 1
void decrementa_cursor(int *cursor)
{
    if (*cursor <= 1)
        return;
    else
        (*cursor)--;
}
