#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct ALUNO{
	int RA;
	char nome[30];
	char curso[10];
} Al;

typedef struct PROFESSOR{
	int matricula;
	char nome[30];
	char curso[10];
} Prof;

void escolhaCursos(char *curso){
	int escolha;
	printf("\tCursos: ");
	printf("1 - ADS\n");
	printf("\t\t2 - Agro\n");
	printf("\t\t3 - Logistica\n");
	printf("\t\t4 - RH\n\t");
    do{
        printf("Escolha o curso: ");
        scanf("%i", &escolha);
        if(escolha < 1 || escolha > 4){
            printf("\tOpcao invalida, ");
        }
    }while(escolha < 1 || escolha > 4);
	
	switch (escolha){
		case 1: strcpy(curso, "ADS"); break;
		case 2: strcpy(curso, "Agro"); break;
		case 3: strcpy(curso, "Logistica"); break;
		case 4: strcpy(curso, "RH");
	}
}

int continuar(){
	int continua;
	do{
		printf("Escolha: ");
		scanf("%i", &continua);
		if(continua!=1 && continua!=0)
			printf("Opcao invalida, nova ");
	}while(continua!=1 && continua!=0);
	
	if (continua)
		return 1;
	else
		return 0;
}

void cadastrarAluno(Al **aluno, int *qtd, int *max){
	
	if(*qtd==*max){
		*max += 10;
		*aluno = (Al*)realloc(*aluno, (*max) * sizeof(Al));
	}
	
	printf("\nAluno %i:\n", *qtd+1);
	if(*qtd==0)
		(*aluno)[0].RA=1;
	else
		(*aluno)[*qtd].RA = (*aluno)[*qtd-1].RA+1;
	printf("\tNome: ");
	scanf("%s", (*aluno)[*qtd].nome);
	escolhaCursos((*aluno)[*qtd].curso);
		
	(*qtd)++;

	printf("\nCadastrar mais um aluno?\n1 - sim | 0 - nao\n");
	if(continuar())
		cadastrarAluno(aluno, qtd, max);
}

void pesquisarAluno(Al aluno[], int *qtd){
	int RA, i;
	
    if(*qtd == 0){
        printf("Nenhum aluno cadastrado");
        return;
    }
	printf("Finais de RA disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", aluno[i].RA);

	printf("\nDigite o final do RA do aluno que deseja ver (Digite 0 para ver todos): ");
	scanf("%i", &RA);
	
    if (RA == 0){
	    for(i=0; i<*qtd; i++)
			printf("Aluno %i:\n\tRA: 18404825120%i\n\tNome: %s\n\tCurso: %s\n", i+1, aluno[i].RA, aluno[i].nome, aluno[i].curso);
		return;
	}
    else{
		for(i=0; i<=*qtd; i++)
			if(aluno[i].RA == RA)
				break;

		if (i < *qtd && i >= 0)
			printf("Aluno %i:\n\tRA: 18404825120%i\n\tNome: %s\n\tCurso: %s\n", i+1, aluno[i].RA, aluno[i].nome, aluno[i].curso);
		else
			printf("Aluno nao existente");
	}

    printf("\nPesquisar mais um aluno?\n1 - sim | 0 - nao\n");
	if(continuar())
		pesquisarAluno(aluno, qtd);
}

void alterarAluno(Al aluno[], int *qtd){
    int RA, escolha, i;
	
    if(*qtd == 0){
        printf("Nenhum aluno cadastrado");
        return;
    }

	printf("Finais de RA disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", aluno[i].RA);

    printf("\nDigite o final do RA do aluno que deseja alterar: ");
	scanf("%i", &RA);

	for(i=0; i<=*qtd; i++)
			if(aluno[i].RA == RA)
				break;
	
    if (i < *qtd && i >= 0){
        printf("\tO que deseja alterar?\n\t1 - Nome | 2 - Curso | 3 - Ambos | 0 - Cancelar\n\t");
        do{
			printf("Escolha: ");
			scanf("%i", &escolha);
			if(escolha<0 || escolha>3)
				printf("\tOpcao invalida, nova ");
		}while(escolha<0 || escolha>3);

        switch(escolha){
            case 3:
            case 1:
                printf("Nome atual: %s\nDigite o novo nome: ", aluno[i].nome);
                scanf("%s", aluno[i].nome); 
                if (escolha==1) break;
				// fall through
            case 2:
                printf("Curso atual: %s\nEscolha o novo curso:\n", aluno[i].curso);
                escolhaCursos(aluno[i].curso);
        }
    }
    else
        printf("Aluno nao existente");

    printf("\nAlterar mais um aluno?\n1 - sim | 0 - nao\n");   
	if(continuar())
		alterarAluno(aluno, qtd);
}

void excluirAluno(Al aluno[], int *qtd){
    int RA, i;

    if(*qtd == 0){
        printf("Nenhum aluno cadastrado");
        return;
    }

	printf("Finais de RA disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", aluno[i].RA);

    printf("\nDigite o final do RA do aluno que deseja excluir: ");
	scanf("%i", &RA);

	for(i=0; i<=*qtd; i++)
		if(aluno[i].RA == RA)
			break;

    if (i < *qtd-1 && i >= 0){
		for(; i<*qtd; i++){
			aluno[i].RA = aluno[i+1].RA;
			strcpy(aluno[i].nome, aluno[i+1].nome);
			strcpy(aluno[i].curso, aluno[i+1].curso);
		}
		(*qtd)--;
    }
    else
        printf("Aluno nao existente");

    printf("\nExcluir mais um aluno?\n1 - sim | 0 - nao\n"); 
	if(continuar())
		excluirAluno(aluno, qtd);
}

void cadastrarProfessor(Prof **professor, int *qtd, int *max){
	
	if(*qtd==*max){
		*max += 10;
		*professor = (Prof*)realloc(*professor, (*max) * sizeof(Prof));
	}
	
	printf("\nProfessor %i:\n", *qtd+1);
	if(*qtd==0)
		(*professor)[0].matricula=1;
	else
		(*professor)[*qtd].matricula = (*professor)[*qtd-1].matricula+1;
	printf("\tNome: ");
	scanf("%s", (*professor)[*qtd].nome);
	escolhaCursos((*professor)[*qtd].curso);
		
	(*qtd)++;
	printf("\nCadastrar mais um Professsor?\n1 - sim | 0 - nao\n");
	if(continuar())
		cadastrarProfessor(professor, qtd, max);
}

void pesquisarProfessor(Prof professor[], int *qtd){
	int matricula, i;
	
    if(*qtd == 0){
        printf("Nenhum Professor cadastrado");
        return;
    }
	printf("Finais de matricula disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", professor[i].matricula);

	printf("\nDigite o final da matricula do professor que deseja ver (Digite 0 para ver todos): ");
	scanf("%i", &matricula);
	
    if (matricula == 0){
	    for(i=0; i<*qtd; i++)
			printf("Professor %i:\n\tMatricula: 50012%i\n\tNome: %s\n\tCurso: %s\n", i+1, professor[i].matricula, professor[i].nome, professor[i].curso);
		return;
	}
    else{
		for(i=0; i<=*qtd; i++)
			if(professor[i].matricula == matricula)
				break;

		if (i < *qtd && i >= 0)
			printf("Professor %i:\n\tMatricula: 50012%i\n\tNome: %s\n\tCurso: %s\n", i+1, professor[i].matricula, professor[i].nome, professor[i].curso);
		else
			printf("Professor nao existente");
	}

    printf("\nPesquisar mais um Professor?\n1 - sim | 0 - nao\n");
	if(continuar())
		pesquisarProfessor(professor, qtd);
}

void alterarProfessor(Prof professor[], int *qtd){
    int matricula, escolha, i;
	
    if(*qtd == 0){
        printf("Nenhum professor cadastrado");
        return;
    }

	printf("finais de matricula disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", professor[i].matricula);

    printf("\nDigite o final da matricula do professor que deseja alterar: ");
	scanf("%i", &matricula);

	for(i=0; i<=*qtd; i++)
			if(professor[i].matricula == matricula)
				break;
	
    if (i < *qtd && i >= 0){
        printf("\tO que deseja alterar?\n\t1 - Nome | 2 - Curso | 3 - Ambos | 0 - Cancelar\n\t");
        do{
			printf("Escolha: ");
			scanf("%i", &escolha);
			if(escolha<0 || escolha>3)
				printf("\tOpcao invalida, nova ");
		}while(escolha<0 || escolha>3);

        switch(escolha){
            case 3:
            case 1:
                printf("Nome atual: %s\nDigite o novo nome: ", professor[i].nome);
                scanf("%s", professor[i].nome); 
                if (escolha==1) break;
				// fall through
            case 2:
                printf("Curso atual: %s\nEscolha o novo curso:\n", professor[i].curso);
                escolhaCursos(professor[i].curso);
        }
    }
    else
        printf("Professor nao existente");

    printf("\nAlterar mais um Professor?\n1 - sim | 0 - nao\n");   
	if(continuar())
		alterarProfessor(professor, qtd);
}

void excluirProfessor(Prof professor[], int *qtd){
    int matricula, i;

    if(*qtd == 0){
        printf("Nenhum professor cadastrado");
        return;
    }

	printf("finais de matricula disponiveis:");
	for(int i=0; i<*qtd; i++)
		printf(" %i", professor[i].matricula);

    printf("\nDigite o final da matricula do professor que deseja excluir: ");
	scanf("%i", &matricula);

	for(i=0; i<=*qtd; i++)
		if(professor[i].matricula == matricula)
			break;

    if (i < *qtd-1 && i >= 0){
		for(; i<*qtd; i++){
			professor[i].matricula = professor[i+1].matricula;
			strcpy(professor[i].nome, professor[i+1].nome);
			strcpy(professor[i].curso, professor[i+1].curso);
		}
		(*qtd)--;
    }
    else
        printf("Professor nao existente");

    printf("\nExcluir mais um professor?\n1 - sim | 0 - nao\n"); 
	if(continuar())
		excluirProfessor(professor, qtd);
}

int main(){
	int escolha, continua=0, qtdalunos=0, qtdprofessores=0, maxalunos=10, maxprofessores=10;
	Al *alunos = (Al*)malloc(maxalunos*sizeof(Al));
	Prof *professores = (Prof*)malloc(maxprofessores*sizeof(Prof));
	
	printf("Sistema Academico");
	
	do{
		printf("\n\nEscolha uma das opcoes:\n");
		printf("\t1 - Cadastrar aluno | Quantidade atual: %i\n", qtdalunos);
		printf("\t2 - Pesquisar aluno\n");
		printf("\t3 - Alterar aluno\n");
		printf("\t4 - Excluir aluno\n");
		printf("\t5 - Cadastrar professor | Quantidade atual: %i\n", qtdprofessores);
		printf("\t6 - Pesquisar professor\n");
		printf("\t7 - Alterar professor\n");
		printf("\t8 - Excluir professor\n");
        printf("\t9 - Sair\n");
	
        do{
            printf("Escolha: ");
            scanf("%i", &escolha);
            if(escolha<1 || escolha>9)
                printf("Opcao invalida, ");
        }while (escolha<1 || escolha>9);

		switch (escolha){
			case 1: cadastrarAluno(&alunos, &qtdalunos, &maxalunos); break;
			case 2: pesquisarAluno(alunos, &qtdalunos); break;
			case 3: alterarAluno(alunos, &qtdalunos); break;
			case 4: excluirAluno(alunos, &qtdalunos); break;
			case 5: cadastrarProfessor(&professores, &qtdprofessores, &maxprofessores); break;
			case 6: pesquisarProfessor(professores, &qtdprofessores); break;
			case 7: alterarProfessor(professores, &qtdprofessores); break;
			case 8: excluirProfessor(professores, &qtdprofessores); break;
            case 9:
                printf("Deseja mesmo sair?\n1 - sim | 0 - nao\n");
                do{
                    printf("Escolha: ");
                    scanf("%i", &continua);
                    if(continua!=1 && continua!=0)
                        printf("Opcao invalida, ");
                }while(continua!=1 && continua!=0);
            }
	}while(!continua);
}