#ifndef UTILS_H_
#define UTILS_H_

typedef struct elemento *Lista;

void window_size(int *, int *);
int mygetch();
void clear_screen();
void incrementa_cursor(int *, Lista *);
void decrementa_cursor(int *);

#endif
