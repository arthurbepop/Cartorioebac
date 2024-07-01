#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de acentua��o e caracteres tipo �
#include <string.h> // biblioteca que cuida das strings
int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo [40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //copia o valor de arquivo para o cpf, para que n�o precise perguntar 2x

    FILE *file; //cria o arquivo

    file = fopen(arquivo, "w"); //abre o arquivo, e pede para escrever com "W" (Write)
    fprintf(file, cpf); //salva o valor da variavel (cpf) no arquivo
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); //abre o arquivo, e diz que quer atualizar algo com "a"
    fprintf(file, ", "); //escreve uma virgula depois do cpf
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
     file = fopen(arquivo, "a"); //abre o arquivo, e diz que quer atualizar algo com "a"
    fprintf(file, nome);
    fclose(file);

     file = fopen(arquivo, "a"); //abre o arquivo, e diz que quer atualizar algo com "a"
    fprintf(file, ", "); //escreve uma virgula depois do cpf
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

     file = fopen(arquivo, "a"); //abre o arquivo, e diz que quer atualizar algo com "a"
    fprintf(file, ", "); //escreve uma virgula depois do cpf
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}
int consulta()
{
    setlocale(LC_ALL,"Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");  //R � para ler

    if(file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo, pois o mesmo n�o foi localizado.\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");


}
int deletar()
{
     char cpf[40];

     printf("Digite o CPF do usu�rio a ser deletado: ");
     scanf("%s", cpf);

     remove(cpf);

     FILE *file;
     file = fopen(cpf, "r");

     if(file == NULL){
     printf("O usu�rio foi deletado, ou j� n�o se encontra mais no sistema!\n");
     system("pause");
     }
}

int main()
{
    int opcao = 0; //definindo variaveis
    int laco = 1;

     for(laco = 1; laco = 1;)
    {
        system("cls");

     setlocale(LC_ALL,"Portuguese"); // ptbr puxando da biblioteca locale.h

     printf("### Cart�rio da UNISC ###\n\n"); //inicio do menu
     printf("Escolha a op��o desejada do menu\n\n");
     printf("\t1 - Registrar nomes\n");
     printf("\t2 - Consultar nomes\n");
     printf("\t3 - Deletar nomes\n");
     printf("\t4 - Sair do sistema\n\n");
     printf("Op��o: "); //fim do menu

     scanf("%d", &opcao); //armazenando a escolha do usu�rio

     system("cls");
     switch(opcao)
     {
     case 1:
     registro(); //chamada de fun��es
     break;

     case 2:
     consulta();
     break;

     case 3:
     deletar();
     break;

     case 4:
     printf("Obrigado por utilizar o sistema!\n");
     return 0;
     break;

     default:
     printf("Essa op��o n�o est� disponivel!\n");
     system("pause");
     break;
}


}
}
