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
    CO C;
    arq_cong = fopen("congressista.txt", "a+b");
    if(arq_cong == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite o numero de inscricao: \n");
    scanf("%d",&C.ins); //aprimorar esse trecho

    if(C.ins!=0){
        printf("Nome: ");
        setbuf(stdin,NULL);
        fgets(C.nome,60,stdin);
        strupr(C.nome);
        printf("\nE-mail: ");
        setbuf(stdin,NULL);
        fgets(C.email,60,stdin);
        printf("\nTelefone: ");
        setbuf(stdin,NULL);
        fgets(C.telefone,60,stdin);
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
