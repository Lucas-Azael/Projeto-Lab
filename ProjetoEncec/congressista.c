#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "congressista.h"

struct congressista
{
    char nome[60];
    int ins;
    char email[60];
    char telefone[60];
};
void setCongressista()
{
    int num;
    CO C;
//    arq_cong = fopen("congressista.txt", "a+b");

    printf("\nDigite o numero de inscricao: \n");
    scanf("%d",&num); //aprimorar esse trecho
    C.ins=num;
    printf("johuhgigug %d\n", buscaInscricao(num));
    /*if(buscaInscricao(num)==0)
    {
        printf("Nome: ");
        setbuf(stdin,NULL);
        gets(C.nome);
        strupr(C.nome);
        printf("\nE-mail: ");
        setbuf(stdin,NULL);
        gets(C.email);
        printf("\nTelefone: ");
        setbuf(stdin,NULL);
        gets(C.telefone);
        fwrite(&C,sizeof(C),1,arq_cong);
        getchar();
    }
    else
    {
        printf("Codigo repetido\n");
    }
    fclose(arq_cong);*/
}
int buscaInscricao(int ins)
{
    /*CO C;
    arq_cong = fopen("congressista.txt","r+b");
    fread(&C,sizeof(C),1,arq_cong);
    while(!feof(arq_cong)){
        if(C.ins==ins){
            fseek(arq_cong,sizeof(C),SEEK_CUR);
            return 1;
        }
        fread(&C,sizeof(C),1,arq_cong);
    }
    fclose(arq_cong);
    return 0;*/
    return access(("C:\\Users\\azael\\OneDrive\\Documentos\\GitHub\\Projeto-Lab\\ProjetoEncec\\data\\congressista\\%d",ins), F_OK);
}
char nomeCongressista(int ins)
{
    CO C;
    arq_cong = fopen("congressista.txt","r+b");
    fread(&C,sizeof(C),1,arq_cong);
    while(!feof(arq_cong))
    {
        if(C.ins==ins)
        {
            fseek(arq_cong,sizeof(C),SEEK_CUR);
            return C.nome;
        }
        fread(&C,sizeof(C),1,arq_cong);
    }
    fclose(arq_cong);
    return 'NAO EXISTE ESSE CONGRESSISTA';
}
void buscarCongressista()
{
    int num;
    CO C;
    arq_cong = fopen("congressista.txt","r+b");
    if(arq_cong==NULL)
    {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite a inscricao: ");
    scanf("%d",&num);
    if(buscaInscricao(num)==0)
    {
        printf("Congressista nao cadastrado\n");
    }
    else
    {
        setbuf(stdin,NULL);
        fread(&C,sizeof(C),1,arq_cong);
        printf("Nome:%s",C.nome);
        printf("\nE-mail:%s",C.email);
        printf("\nIncricao:%d",C.ins);
        putchar('\n');
        printf("\nTelefone:%s",C.telefone);
        getchar();
    }
    fclose(arq_cong);
}
void listarCongressista()
{
    CO C;
    arq_cong = fopen("congressista.txt","rb");
    int i=0;
    if(arq_cong==NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    fread(&C,sizeof(C),1,arq_cong);
    printf("------------------CONGRESSISTAS-----------------------\n");

    while(!feof(arq_cong))
    {
        printf("\n+----------------------------+\n");
        printf("INCRICAO: %2d",C.ins);
        printf("\nNOME: %s",C.nome);
        printf("\nE-MAIL: %s",C.email);
        printf("\nTELEFONE: %s",C.telefone);
        fread(&C,sizeof(C),1,arq_cong);
        printf("\n+----------------------------+\n");
        if(feof(arq_cong)|| (i==300))
        {
            break;
            getchar();
            getchar();
        }
    }
    getchar();
    fclose(arq_cong);
}

void editarCongressista()
{
    int ins, num;
    CO C;
    arq_cong=fopen("congressista.txt","a+b");

    if(arq_cong==NULL)
    {
        printf("Erro ao abrir arquivo\n");
    }

    printf("Digite o codigo do congressista: ");
    scanf("%d",&ins);

    if(buscaInscricao(ins)==0)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    else
    {
        arq_cong = fopen("congressista.txt","wb");
    }
    if(arq_cong==NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("\n\nDigite o numero de inscricao: \n");
    scanf("%d",&num);
    C.ins=num;

    if(C.ins!=0)
    {
        printf("Nome: ");
        setbuf(stdin,NULL);
        gets(C.nome);
        strupr(C.nome);
        printf("\nE-mail: ");
        setbuf(stdin,NULL);
        gets(C.email);
        printf("\nTelefone: ");
        setbuf(stdin,NULL);
        gets(C.telefone);
        fwrite(&C,sizeof(C),1,arq_cong);
        getchar();
    }
    else
    {
        printf("Codigo repetido\n");
    }
    fclose(arq_cong);
}
void removeCongressista()
{
    CO C;
    arq_cong = fopen("congressista.txt","a+b");
    arq_temp = fopen("temp.txt","a+b");
    if(arq_cong==NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    int ins;

    printf("Digite o numero de inscrição: ");
    scanf("%d",&ins);

    if(buscaInscricao(ins)==0)
    {
        printf("Congressista não cadastrado\n");
        return;
    }
    while(!feof(arq_cong))
    {
        fread(&C,sizeof(C),1,arq_cong);
        if(C.ins==ins)
        {
            fwrite(&C,sizeof(C),1,arq_temp);
        }
    }
    fclose(arq_temp);
    fclose(arq_cong);
    remove("C:\\Users\\azael\\OneDrive\\Documentos\\GitHub\\Projeto-Lab\\ProjetoEncec\\congressista.txt");
    rename("C:\\Users\\azael\\OneDrive\\Documentos\\GitHub\\Projeto-Lab\\ProjetoEncec\\temp.txt","C:\\Users\\azael\\OneDrive\\Documentos\\GitHub\\Projeto-Lab\\ProjetoEncec\\congressista.txt");
}

