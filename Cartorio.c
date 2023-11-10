#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() //Fun��o para cadastrar os usu�rios
{
	char arquivo[40]; //Inicio da cria��o das variaveis/string([])
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40]; //Final da cria��o das variaveis/string
	
	printf("Digite o cpf a ser cadastrado:"); //Coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado!. \n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
    	fclose(file);
    	printf("Usu�rio n�o encontrado no sistema!\n");
    	system("pause");
	}
	if (file != NULL)
	{
		fclose(file);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	    
}

int main()
{
    int opcao=0; // Definimdo vari�veis
	int x=1;
	
	for(x=1;x=1;)
    {
        system("cls");  //Respons�vel por limpar a tela (sls)
      
	    setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	    printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
	    printf("escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("op��o:"); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao) //In�cio das escolhas do menu
	    
	    { 
	    
	    case 1:
	    registro(); //Chamada das fun��es
	    break; 
	    
	    case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigada por usar o nosso sistema!\n");
		return 0;
		break;
		
		default:
		printf("Essa op��o est� indisponivel!\n");
		system("pause");
		break;
	    	
		} // Fim das escolhas
		
    }
    
}
