all:
	gcc main.c normal.c inserir.c utils.c ListaDinEncad.c -o editor_texto

clear:
	rm editor_texto
