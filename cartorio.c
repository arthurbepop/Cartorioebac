#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de acentuação e caracteres tipo ç
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

    strcpy(arquivo, cpf); //copia o valor de arquivo para o cpf, para que não precise perguntar 2x

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
    file = fopen(cpf, "r");  //R é para ler

    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, pois o mesmo não foi localizado.\n");
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

     printf("Digite o CPF do usuário a ser deletado: ");
     scanf("%s", cpf);

     remove(cpf);

     FILE *file;
     file = fopen(cpf, "r");

     if(file == NULL){
     printf("O usuário foi deletado, ou já não se encontra mais no sistema!\n");
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

     printf("### Cartório da UNISC ###\n\n"); //inicio do menu
     printf("Escolha a opção desejada do menu\n\n");
     printf("\t1 - Registrar nomes\n");
     printf("\t2 - Consultar nomes\n");
     printf("\t3 - Deletar nomes\n");
     printf("\t4 - Sair do sistema\n\n");
     printf("Opção: "); //fim do menu

     scanf("%d", &opcao); //armazenando a escolha do usuário

     system("cls");
     switch(opcao)
     {
     case 1:
     registro(); //chamada de funções
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
     printf("Essa opção não está disponivel!\n");
     system("pause");
     break;
}


}
}
