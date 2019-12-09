#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "congressista.h"


typedef struct congressista{
    char nome[60];
    int ins;
    char email[60];
    char telefone[60];
};
void setCongressista(){
    int num;
    CO C;
    arq_cong = fopen("congressista.txt", "a+b");
    if(arq_cong == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite o numero de inscricao: \n");
    scanf("%d",&num); //aprimorar esse trecho
    C.ins=num;

    if(C.ins!=0){
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
    }else{
        printf("Codigo repetido\n");
    }
    fclose(arq_cong);
}
int buscaInscricao(int ins){
    CO C;
    arq_cong = fopen("congressista.txt","r+b");
    fread(&C,sizeof(C),1,arq_cong);
    while(!feof(arq_cong)){
        if(C.ins==ins){
            fseek(arq_cong,sizeof(C),SEEK_CUR);
            return 1;
        }
        fread(&C,sizeof(C),1,arq_cong);
    }
    return 0;
}

void buscarCongressista(){
    int num;
    CO C;
    arq_cong = fopen("congressista.txt","r+b");
    if(arq_cong==NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite a inscricao: ");
    scanf("%d",&num);
    if(buscaInscricao(num)==0){
        printf("Congressista nao cadastrado\n");
    }else{
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
void listarCongressista(){
    CO C;
    arq_cong = fopen("congressista.txt","r+b");
    int i=0;
    if(arq_cong==NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }
    fread(&C,sizeof(C),1,arq_cong);
    printf("------------------CONGRESSISTAS-----------------------\n");

    while(!feof(arq_cong)){
        printf("\n+----------------------------+\n");
        printf("INCRICAO: %2d",C.ins);
        printf("\nNOME: %s",C.nome);
        printf("\nE-MAIL: %s",C.email);
        printf("\nTELEFONE: %s",C.telefone);
        fread(&C,sizeof(C),1,arq_cong);
        printf("\n+----------------------------+\n");
        if(feof(arq_cong)|| (i==300)){
            break;
            getchar();
            getchar();
        }
    }
    getchar();
    fclose(arq_cong);
}
