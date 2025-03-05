#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//bibliote de alocação de espaço em memória
#include <locale.h>//bibliotece de alocações de texto por região
#include <string.h>//biblioteca responsável por todas as strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	system ("pause \n");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int exclui()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser excluído: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n\n");
		printf("\t4 - Sair do Programa\n\n");
		
		printf("Opção: ");
		
		
	
		scanf("%d", &opcao);
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
				registro();
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
				exclui();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema, fim!\n");
				return 0;
				break;
					
			default:
				printf("Opção Invalida\n");
				system("pause");
				break;
		}
	}
}
  
