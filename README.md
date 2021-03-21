<h1 align="center">Laboratórios de Sistemas Operacionais</h1>

### Sobre o Repositorio
<p>Esse repositório vai armazenar os arquivos das aulas de laboratório da disciplina INF1316 - Sistemas Operacionais - da PUC-Rio, lecionada em 2021.1 pelo professor Luiz Fernando Bessa Seibel.  </p> 
<p> Responsável pelo repositório e pelos arquivos: Suemy Inagaki  </p>

Tabela de conteúdos
=================
<!--ts-->
   * [Sobre o Repositorio](#Sobre-o-Repositorio)
   * [Lab 01](#lab-01)   
   * [Tabela de Conteudo](#tabela-de-conteudo)
<!--te-->



### Lab 01
#### Laboratório de `fork()` e `exec()`:
Criação de processos pai, filho e neto utilizando o `fork()` e chamada de programas externos utilizando o `exec()`

#### Prerequisitos para Windows:
Ter o `wsl` instalado.

#### Para executar o exercicio 1:
* 
  ```sh
  > wsl
  $ gcc lab1-1.c -o lab1-1
  $ ./lab1-1 > lab1-1.txt
  ```
#### Para executar o exercicio 2:
* 
  ```sh
  > wsl
  $ gcc lab1-2.c -o lab1-2
  $ ./lab1-2 > lab1-2.txt
  ```
#### Para executar o exercicio 3:
* 
  ```sh
  > wsl
  $ gcc bomdia.c -o bomdia
  $ gcc meuecho.c -o meuecho
  $ gcc lab1-3-1.c -o lab1-3-1
  $ ./lab1-3-1 "testando o programa meuecho" > lab1-3-1.txt
  ```


