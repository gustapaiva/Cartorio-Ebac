#include <stdio.h> //biblioteca de comunicacão com usuario
#include <stdlib.h> //blioteca por alocação de espaço em memoria
#include <locale.h> //bibloteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string
 
 int registro()// funcao responsavel por cadastrar os usuarios no sitema
	{
		//inicio da criacao de variaveis/strings
		char arquivo[40];
		char cpf[40];
		char nome[40];
	    char sobrenome[40];
        char cargo[40];
        //fim da criacao de variaveis/string
        
        printf("Digite o cpf a ser consultado: "); //coletando informacion
        scanf("%s" , cpf); //%s refente a string
        
        strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
        
        FILE *file; //criar o arquivo
        file = fopen(arquivo,"w");//criar o arquivo/W de write 
        fprintf(file,cpf);//salva o valor
        fclose(file); //fecha o arquivo
        
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);          
    
        printf("Digite o nome  a ser cadastrado: ");
        scanf("%s",nome);
        
        file = fopen(arquivo, "a"); 
        fprintf(file,nome);
        fclose(file);
        
        file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
        printf("Digite o sobrenome a ser cadastrado: ");
        scanf("%s",sobrenome);
        
        file = fopen(arquivo, "a");
        fprintf(file,sobrenome);
        fclose(file);  
        
        file = fopen(arquivo,"a");
        fprintf(file,",");
        fclose(file);
        
        printf("digite o cargo a ser cadastrado: ");
        scanf("%s",cargo);
        
        file = fopen(arquivo,"a");
        fprintf(file,cargo);
        fclose(file);
        
        system("pause");       
    
}

int consulta()
{
  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
      char cpf[40];      //inicio da criacao de variaveis/strings
      char conteudo[200];
	                     //fim da criacao de variaveis/string
       printf("Digite o CPF a ser consultado: ");
       scanf("%s",cpf); //%s refente a string
  	
       FILE *file;//criar o arquivo
       file = fopen(cpf,"r");
  	
    if(file == NULL)
    {  
	    printf("Arquivo nao localizado!.\n\n\n");
    }
	
    while(fgets(conteudo, 200, file) != NULL)
	{
	   printf("\nEssas sao as informacoes  do usuario: ");
	   printf("%s", conteudo);
	   printf("\n\n");
    }
  	
	fclose(file);
    system ("pause");
       
}  

int deletar()
{
    char cpf[40];	
    
    printf("Digite o cpf a ser deletado: ");
    scanf("%s",cpf);// coleta de informacao do usuario 
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");//criar o arquivo/R de ler
    
    if(file == NULL) // verificar se o file "cpf" existe no banco de dados. caso nao mostrara uma mensagem de erro 
    {
    	printf("O usuario nao se encontra no sistema!.\n");   	
		system("pause");
	}
	
        fclose(file);
    
    
}	
			
int sair() 
{
	scanf("%s",sair); // fechar programa
}			
				
int main()
{
	int opcao=0; //definindo variaveis 
	int laco=1; //variavel de repeticao do loop
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela 
		
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	 
	printf("Cartorio do Marroca:\n\n");
	printf("\t1 - registro de nomes\n");
	printf("\t2 - consulta de nomes\n");
	printf("\t3 - deletar nomes\n"); // fim do menu
    
	printf("opcao: ");

    scanf("%d", &opcao); // armazenando a escolha do usuario 
    
	system("cls"); //responsavel por limpar a tela
	 
	 switch (opcao)// inicio da selecao
	 {
	 	case 1:
	    registro(); //chamada de funcoes registro
	    break;
	
	    case 2:
	    consulta(); //chamada de funcoes consulta	    
	    break;
	
	    case 3:
	    deletar(); //chamada de funcoes deletar
	    break;
	    
	
	    default:
	    printf("Essa opcao nao esta disponovel!\n");
	    system("pause");
	    break;
	 }     //fim da selecao   	 
	 
  }  
}
