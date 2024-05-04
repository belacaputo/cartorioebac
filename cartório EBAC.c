#include <stdio.h> //biblioteca de comunica��o com o unsu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings (vari�veis)

int registro()//fun��o de cadastro de strings(vari�veis/usu�rios)
{
	//in�cio cria��o strings
	char arquivo[40];//char s�o as strings, arquivo cria��o do banco de dados
	char cpf[40];//string
	char nome[40];//string
	char sobrenome[40];//string
	char cargo[40];//string
	//fim cria��o strings
	
	printf("Digite o CPF a ser cadastrado:");//coleta de informa��es
	scanf("%s", cpf);//%s string, adiciona a string
	
	strcpy(arquivo, cpf);//copia os valores das strings 
	
	FILE *file;// cria o arquivo
	file = fopen(arquivo, "w");//w write, l� o arquivo (banco de dados)
	fprintf (file,cpf);//salva a string
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//a analise, analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome do usu�rio: ");//direciona a a��o
	scanf("%s",nome);//adiciona a variavel
	
	file = fopen(arquivo, "a");//analise dos dados
	fprintf(file,nome);//salva a string
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome do usu�rio: ");//direciona a a��o
	scanf("%s",sobrenome);//adiciona string
	
	file = fopen(arquivo, "a");//analise dos dados
	fprintf(file,sobrenome);//salva a string
	fclose(file);//feccha o arquivo
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,",");//salva a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo do usu�rio: ");//direciona a a��o
	scanf("%s",cargo);//adiciona a string
	
	file = fopen(arquivo, "a");//analisa os dados
	fprintf(file,cargo);//salva a string
	fclose(file);//fecha o arquivo
	
	system("pause");//pausa o sistema
}

int consulta()//fun��o das strings
{
	
	setlocale(LC_ALL, "Portuguese");//add setlocale em todas as fun��es
	
	char cpf[40];//strings
	char conteudo[200];//strings
	
	printf("Digite o CPF a ser consultado: ");//direcciona a a��o
	scanf("%s",cpf);//adiciona a string
	
	FILE *file;//arquivo
	file = fopen(cpf, "r");//r read, ler o  arquivo
	
	if(file == NULL)//se os dados est�o incorretos/n�o existem
	{
		printf("N�o foi poss�vel localizar o arquivo.\n");//o arquivo n�o � localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)//pesquisa os dados no conteudo do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio:  ");//direciona a a��o
		printf("%s", conteudo);//mostra os dados do usu�rio
		printf("\n\n\n");//espa�os para visual
	}
	
	system("pause");//pausa o sistema
}

int deletar()//fun��o de deletar strings
{
	char cpf[40];//v�riavel principal(�nica)
	
	printf("Digite o CPF a ser deletado: ");//direciona a a��o
	scanf("%s", cpf);//adiciona a string
	
	remove(cpf);//fun��o de remover dados do arquivo
	
	FILE *file;//arquivo
	file = fopen(cpf, "r");//abrir e ler o arquivo
	
	if(file == NULL)//se o dado foi deletado do arquivo
	{
		printf("\nO usu�rio foi deletado do sistema.\n\n");//o dado n�o aparece
		system("pause");//pausa no sistema
	}
	
}

int main()//menu principal
{
	int opcao=0;//definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//vari�vel de repeti��o
	{
		
		system("cls");//limpa a tela
	
	
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//in�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");//direciona a a��o
		printf("\t 1 - Registrar nomes\n");//direciona a a��o
		printf("\t 2 - Consultar nomes\n");//direciona a a��o
		printf("\t 3 - Deletar nomes\n\n\n");//direciona a a��o
		printf("\t 4 - Sair do sistema\n\n");//direciona a a��o
		printf("Op��o:\t");//fim do menu
	
		scanf("%d",&opcao);//armazenando a escolha do usu�rio
	
		system("cls");//limpa a tela
		
		switch(opcao)//escolha da a��o
		{
			case 1://op��o de a��o
			registro();//() chamada de fun��o
			break;//pausa a fun��o
			
			case 2://op��o de a��o
			consulta();//chamada de fun��o
			break;//pausa a fun�ao
			
			case 3://op��o de a��o
			deletar();//chamada de fun��o
			break;//pausa a fun��o
			
			case 4://op��o de a��o
			printf("Obrigado por utilizar nosso sistema!\n");//direciona a a��o
			return 0;//sucesso na execu��o do programa
			break;//pausa a fun��o
			
			default://op��o de a��o indispon�vel
			printf("Op��o n�o dispon�vel no momento.\n\n");//direciona a a��o
			system("pause");//pausa o sistema
			break;//pausa a a��o
			//fim menu	
		}
		
    }
}
