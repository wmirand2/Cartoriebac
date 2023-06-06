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
	
	printf("Digite o CPF a ser consultado: "); //recebendo qual usuario sera consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)//faz comparação do usuario informado com o arquivo para encontrar o usuario 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//busca no arquivo e tras as informações de consulta
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	fclose(file);
	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //recebe o usuario a ser deletado
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");//le no arquivo a informação a ser deletada
	
	if(file == NULL)//faz a comparação do usurio informado com o arquivo
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf); //responsavel por deletar a informação digitada
		FILE *FILE;
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Ficha de cadastro da EBAC ###\n\n");
	printf("login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
			system("cls"); //responsavel ppr limpar a tela
		
			setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
	
			printf("### Ficha de cadastro da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
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
		
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //responsavel por sair do sistema
			break;
		
			default:
			printf("Opção invalida!\n"); //final da seleção
			system("pause");
			break; //fim da seleção
		}	
		}
  	}
  	
  	else
  		printf("Senha incorreta!");
}
