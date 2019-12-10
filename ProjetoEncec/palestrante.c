
<<<<<<< Updated upstream
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palestrante.h"

typedef struct palestrante{
    char nome[60];
    int ins;
    char email[60];
    char telefone[60];
    char especialidade[100];
};
void setPalestrante(){
    int num;
    PA P;
    arq_pales = fopen("palestrante.txt", "a+b");
    if(arq_pales == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite o numero de inscricao: \n");
    scanf("%d",&num); //aprimorar esse trecho
    P.ins=num;

    if(P.ins!=0){
        printf("Nome: ");
        setbuf(stdin,NULL);
        gets(P.nome);
        strupr(P.nome);
        printf("\nEspecialidade: ");
        setbuf(stdin,NULL);
        gets(P.especialidade);
        printf("\nE-mail: ");
        setbuf(stdin,NULL);
        gets(P.email);
        printf("\nTelefone: ");
        setbuf(stdin,NULL);
        gets(P.telefone);
        fwrite(&P,sizeof(C),1,arq_pales);
        getchar();
    }else{
        printf("Codigo repetido\n");
    }
    fclose(arq_pales);
}
int buscaInscricaoPalestrante(int ins){
    PA P;
    arq_pales = fopen("palestrante.txt","r+b");
    fread(&C,sizeof(C),1,arq_pales);
    while(!feof(arq_pales)){
        if(P.ins==ins){
            fseek(arq_pales,sizeof(P),SEEK_CUR);
            return 1;
        }
        fread(&P,sizeof(C),1,arq_pales);
    }
    fclose(arq_pales);
    return 0;
}

void buscarPalestrante(){
    int num;
    PA P;
    arq_cong = fopen("palestrante.txt","r+b");
    if(arq_pales==NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }
    printf("\nDigite a inscricao: ");
    scanf("%d",&num);
    if(buscaInscricaoPalestrante(num)==0){
        printf("Palestrante não cadastrado\n");
    }else{
        setbuf(stdin,NULL);
        fread(&C,sizeof(C),1,arq_pales);
        printf("Nome:%s",P.nome);
        printf("\nE-mail:%s",P.email);
        printf("\nEspecialidade:%s",P.especialidade);
        printf("\nIncricao:%d",P.ins);
        putchar('\n');
        printf("\nTelefone:%s",P.telefone);
        getchar();
    }
    fclose(arq_pales);
}
void listarPalestrante(){
    PA P;
    arq_pales = fopen("palestrante.txt","rb");
    int i=0;
    if(arq_pales==NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }
    fread(&P,sizeof(C),1,arq_pales);
    printf("------------------PALESTRANTES-----------------------\n");

    while(!feof(arq_pales)){
        printf("\n+----------------------------+\n");
        printf("INCRICAO: %2d",P.ins);
        printf("\nNOME: %s",P.nome);
        printf("\nESPECIALIDADE: %s",P.especialidade);
        printf("\nE-MAIL: %s",P.email);
        printf("\nTELEFONE: %s",P.telefone);
        fread(&P,sizeof(C),1,arq_pales);
        printf("\n+----------------------------+\n");
        if(feof(arq_pales)){
            break;
            getchar();
            getchar();
        }
    }
    getchar();
    fclose(arq_pales);
}
void editarPalestrante(){
    int ins, num;
    PA P;
    arq_pales=fopen("palestrante.txt","a+b");

    if(arq_pales==NULL){
        printf("Erro ao abrir arquivo\n");
    }

    printf("Digite o codigo do congressista: ");
    scanf("%d",&ins);

    if(buscaInscricaoPalestrante(ins)==0){
        printf("Erro ao abrir o arquivo\n");
        return;
    }else{
        arq_pales = fopen("palestrante.txt","wb");
    }if(arq_pales==NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

     printf("\n\nDigite o numero de inscricao: \n");
     scanf("%d",&num);
     P.ins=num;

    if(P.ins!=0){
        printf("Nome: ");
        setbuf(stdin,NULL);
        gets(P.nome);
        strupr(P.nome);
        printf("\nE-mail: ");
        setbuf(stdin,NULL);
        gets(P.email);
        printf("\nTelefone: ");
        setbuf(stdin,NULL);
        gets(P.telefone);
        fwrite(&P,sizeof(C),1,arq_pales);
        getchar();
    }else{
        printf("Codigo repetido\n");
    }
    fclose(arq_pales);
}
>>>>>>> Stashed changes
