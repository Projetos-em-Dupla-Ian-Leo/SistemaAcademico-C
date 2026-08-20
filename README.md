# Sistema Acadêmico em C

Sistema acadêmico desenvolvido em dupla para a disciplina de **Linguagem de Programação**, utilizando a linguagem C.

O projeto implementa um sistema de gerenciamento de **alunos e professores**, permitindo realizar operações de cadastro, pesquisa, alteração e exclusão de registros, utilizando **estruturas (****`struct`****) e alocação dinâmica de memória**.

> Os dados são armazenados em memória durante a execução do programa, sem utilização de banco de dados externo ou persistência em arquivos.

## Funcionalidades

### Alunos

* [x] Cadastro de alunos com geração automática de RA
* [x] Pesquisa de aluno por RA
* [x] Listagem de todos os alunos cadastrados
* [x] Alteração de nome e/ou curso
* [x] Exclusão de alunos
* [x] Validação das opções selecionadas

### Professores

* [x] Cadastro de professores com geração automática de matrícula
* [x] Pesquisa de professor por matrícula
* [x] Listagem de todos os professores cadastrados
* [x] Alteração de nome e/ou curso
* [ ] Exclusão de professores
* [x] Validação das opções selecionadas

## Tecnologias e conceitos

* **Linguagem:** C
* **Bibliotecas:** `stdio.h`, `string.h`, `malloc.h`
* **Estruturas:** `struct`
* **Ponteiros**
* **Alocação dinâmica de memória**
* **`malloc`**** e ****`realloc`**
* **Manipulação de strings**
* **Funções**
* **Vetores de estruturas**
* **Validação e tratamento de entradas**

A alocação dos vetores é expandida dinamicamente conforme a quantidade de registros aumenta, utilizando `realloc`.

## Estrutura dos dados

O sistema utiliza duas estruturas principais:

* `ALUNO`: armazena RA, nome e curso.
* `PROFESSOR`: armazena matrícula, nome e curso.

Os cursos disponíveis no sistema são:

* ADS
* Agro
* Logística
* RH

A escolha do curso possui validação para impedir opções fora do intervalo permitido.

## Menu do sistema

O programa possui um menu principal com as seguintes operações:

```text
1 - Cadastrar aluno
2 - Pesquisar aluno
3 - Alterar aluno
4 - Excluir aluno
5 - Cadastrar professor
6 - Pesquisar professor
7 - Alterar professor
8 - Excluir professor
9 - Sair
```

## Objetivos do projeto

O projeto foi desenvolvido com o objetivo de aplicar na prática conceitos fundamentais da linguagem C, principalmente:

* Manipulação de estruturas de dados;
* Uso de ponteiros;
* Alocação dinâmica de memória;
* Criação e organização de funções;
* Manipulação de strings;
* Implementação de operações de CRUD;
* Validação de entradas do usuário.
