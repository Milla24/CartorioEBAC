#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço de memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função para cadastrar os usuários
{
	char arquivo[40]; //Inicio da criação das variaveis/string([])
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40]; //Final da criação das variaveis/string
	
	printf("Digite o cpf a ser cadastrado:"); //Coletando informações do usuário
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
		printf("Arquivo não encontrado!. \n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
    	fclose(file);
    	printf("Usuário não encontrado no sistema!\n");
    	system("pause");
	}
	if (file != NULL)
	{
		fclose(file);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	    
}

int main()
{
    int opcao=0; // Definimdo variáveis
	int x=1;
	
	for(x=1;x=1;)
    {
        system("cls");  //Responsável por limpar a tela (sls)
      
	    setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	    printf("### Cartório da EBAC ###\n\n"); // Início do menu
	    printf("escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("opção:"); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao) //Início das escolhas do menu
	    
	    { 
	    
	    case 1:
	    registro(); //Chamada das funções
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
		printf("Essa opção está indisponivel!\n");
		system("pause");
		break;
	    	
		} // Fim das escolhas
		
    }
    
}
