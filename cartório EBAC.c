#include <stdio.h> //biblioteca de comunicação com o unsuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings (variáveis)

int registro()//função de cadastro de strings(variáveis/usuários)
{
	//início criação strings
	char arquivo[40];//char são as strings, arquivo criação do banco de dados
	char cpf[40];//string
	char nome[40];//string
	char sobrenome[40];//string
	char cargo[40];//string
	//fim criação strings
	
	printf("Digite o CPF a ser cadastrado:");//coleta de informações
	scanf("%s", cpf);//%s string, adiciona a string
	
	strcpy(arquivo, cpf);//copia os valores das strings 
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");//w write, lê o arquivo (banco de dados)
	fprintf (file,cpf);//salva a string
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//a analise, analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome do usuário: ");//direciona a ação
	scanf("%s",nome);//adiciona a variavel
	
	file = fopen(arquivo, "a");//analise dos dados
	fprintf(file,nome);//salva a string
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome do usuário: ");//direciona a ação
	scanf("%s",sobrenome);//adiciona string
	
	file = fopen(arquivo, "a");//analise dos dados
	fprintf(file,sobrenome);//salva a string
	fclose(file);//feccha o arquivo
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo do usuário: ");//direciona a ação
	scanf("%s",cargo);//adiciona a string
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,cargo);//salva a string
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
}

int consulta()//função das strings
{
	
	setlocale(LC_ALL, "Portuguese");//add setlocale em todas as funções
	
	char cpf[40];//strings
	char conteudo[200];//strings
	
	printf("Digite o CPF a ser consultado: ");//direcciona a ação
	scanf("%s",cpf);//adiciona a string
	
	FILE *file;//arquivo
	file = fopen(cpf, "r");//r read, ler o  arquivo
	
	if(file == NULL)//se os dados estão incorretos/não existem
	{
		printf("Não foi possível localizar o arquivo.\n");//o arquivo não é localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//pesquisa os dados no conteudo do arquivo
	{
		printf("\nEssas são as informações do usuário:  ");//direciona a ação
		printf("%s", conteudo);//mostra os dados do usuário
		printf("\n\n\n");//espaços para visual
	}
	
	system("pause");//pausa o sistema
}

int deletar()//função de deletar strings
{
	char cpf[40];//vériavel principal(única)
	
	printf("Digite o CPF a ser deletado: ");//direciona a ação
	scanf("%s", cpf);//adiciona a string
	
	remove(cpf);//função de remover dados do arquivo
	
	FILE *file;//arquivo
	file = fopen(cpf, "r");//abrir e ler o arquivo
	
	if(file == NULL)//se o dado foi deletado do arquivo
	{
		printf("\nO usuário foi deletado do sistema.\n\n");//o dado não aparece
		system("pause");//pausa no sistema
	}
	
}

int main()//menu principal
{
	int opcao=0;//definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//variável de repetição
	{
		
		system("cls");//limpa a tela
	
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//início do menu
		printf("Escolha a opção desejada no menu:\n\n");//direciona a ação
		printf("\t 1 - Registrar nomes\n");//direciona a ação
		printf("\t 2 - Consultar nomes\n");//direciona a ação
		printf("\t 3 - Deletar nomes\n\n\n");//direciona a ação
		printf("\t 4 - Sair do sistema\n\n");//direciona a ação
		printf("Opção:\t");//fim do menu
	
		scanf("%d",&opcao);//armazenando a escolha do usuário
	
		system("cls");//limpa a tela
		
		switch(opcao)//escolha da ação
		{
			case 1://opção de ação
			registro();//() chamada de função
			break;//pausa a função
			
			case 2://opção de ação
			consulta();//chamada de função
			break;//pausa a funçao
			
			case 3://opção de ação
			deletar();//chamada de função
			break;//pausa a função
			
			case 4://opção de ação
			printf("Obrigado por utilizar nosso sistema!\n");//direciona a ação
			return 0;//sucesso na execução do programa
			break;//pausa a função
			
			default://opção de ação indisponível
			printf("Opção não disponível no momento.\n\n");//direciona a ação
			system("pause");//pausa o sistema
			break;//pausa a ação
			//fim menu	
		}
		
    }
}
