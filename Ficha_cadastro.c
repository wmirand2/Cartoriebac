#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //responsavel por criar o arquivo
	file = fopen(arquivo, "w"); //responsavel por criar o arquivo
	fprintf(file,cpf); //armazenar no arquivo
	fclose(file); //responsavel por fechar o arquivo
	
	file = fopen(arquivo,"a"); //colocar virgula entre informações
	fprintf(file,","); //salva a virgula dentro do arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //responsavel por deletar a informação digitada
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel ppr limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
		printf("### Ficha de cadastro da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Digite a opção desejada: "); //final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); 
		
	switch(opcao) //inicio da seleção do menu
	{
		case 1:
		registro(); // chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar(); 
		break;
		
		default:
		printf("Opção invalida!\n"); //final da seleção
		system("pause");
		break; //fim da seleção
		
	}	
	
	
	}
}
