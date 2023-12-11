# Editor-de-texto-em-C

Editor de texto feito em linguagem C utilizando conhecimentos de lógica de programação e estrutura de dados.
compilador usado: GCC-99

MODOS DE INSTALAÇÃO
=
1: Instalando em um único diretório

Só funciona dentro do diretório no qual os programas foram copiados.

1.1 Copie todo o repositório para algum diretório de sua máquina

1.2: Digite o comando para criar o executável
makefile

1.3: Supondo que queiramos editar o arquivo "teste.c", digite o comando:
./renvim teste.c

1.3 Exclua o comando executável com:
make clear

--------------------------------------------------------------------------------------------
2. Inserindo no PATH temporariamente

2.1 Copie o repositório para algum diretório de sua máquina.
exemplo de diretório: /usr/local/bin

2.2 Crie o executável com o seguinte comando:
makefile

2.3 adicione esse mesmo diretório para seu PATH com o seguinte comando:
echo PATH=$PATH:/usr/local/bin

Ao reiniciar a máquina, o PATH não vai estar mais no sistema

----------------------------------------------------------------------------------------------
3. Inserindo no PATH "permanentemente"

3.1 Copie o repositório para algum diretório de sua máquina.
exemplo de diretório: /usr/local/bin

3.2 Crie o executável com o seguinte comando:
makefile

3.3 Vá ao arquivo .profile (~/.profile) e, usando algum editor de texto, coloque ao final do arquivo:
echo PATH=$PATH:/usr/local/bin

INSTRUÇÕES DE USO
=
Instrutor de texto parecido com o "VIM"

Enquanto no modo normal:

Saír do programa: aperte "ESC" 3 vezes
Mude o cursor a partir das "setinhas para esquerda e para direita"
Entrar no modo de inserção : aperte "i'


Enquanto no modo de inserção:

Para voltar ao modo normal: aperte "esc" ou "setinhas para o lado"
Insere e remove caracteres normalmente.

-------------------------------------------------------------------------------------------

CUIDADO: NÃO ABRA ARQUIVOS GRANDES OU IMPORTANTES COM ESSE EDITOR
=
