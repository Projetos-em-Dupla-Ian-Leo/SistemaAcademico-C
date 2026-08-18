# Sistema Acadêmico em C
Projeto desenvolvido em dupla para a disciplina de Linguagem de Programação, implementando um sistema completo de CRUD (Create, Read, Update, Delete) para gerenciamento de alunos e professores, sem utilização de banco de dados externo.

# Funcionalidades
* [x] Cadastro de Alunos e Professores (com autoincremento de RA/Matrícula)
* [x] Pesquisa individual ou listagem geral de todos os registros
* [x] Alteração de Nome ou Curso (com validação de opções)
* [x] Exclusão lógica e física (com rearranjo do vetor em memória)
* [x] Alocação dinâmica de memória (`realloc`) para crescimento sob demanda
* [x] Tratamento de erros e validação de entradas do usuário

## Tecnologias Utilizadas
* **Linguagem:** C (Padrão C99)
* **Bibliotecas:** `stdio.h`, `stdlib.h`, `string.h`
* **Conceitos aplicados:** Ponteiros, Estruturas (Structs), Alocação Dinâmica, Manipulação de Strings.

## ⚙️ Como Executar

``bash
# Clone o repositório
git clone https://github.com/Projetos-em-Dupla-Ian-Leo/SistemaAcademico-C.git

# Entre no diretório
cd sistema-academico-c

# Compile o programa
gcc -o sistema src/SistemaAcademico.c -Wall -Wextra

# Execute
./sistema
