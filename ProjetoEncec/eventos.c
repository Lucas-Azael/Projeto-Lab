/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "congressista.h"
#include "palestrante.h"
#include "eventos.h"

struct palestra{
    char tema[60];
    char local[70];
    char horario[60];
    char cargaHoraria[60];
    char palestrante[60];
};

struct oficina{
    char tema[60];
    char local[70];
    char horario[60];
};

struct gpDis{
    char tema[60];
    char local[70];
    char horario[60];
};

enum{
    AUDITORIO1=150, AUDITORIO2=100, AUDITORIO3=5
}AUD;

int buscarPalestra(char tema[60]){
    P PA;
    pales = fopen("palestra.txt","r+b");
    fread(&PA,sizeof(PA),1,pales);

    while(!feof(pales)){
        if(strcmp(PA.tema,tema)==0){
            fseek(pales,sizeof(PA),SEEK_CUR);
            return 1;
        }
        fread(&PA,sizeof(PA),1,pales);
    }
    fclose(pales);
    return 0;
}
void setPalestra(){
    pales = fopen("palestras.txt","a+b");
    arq_pales = fopen("palestrante.txt","r+b");
    PA PALES;
    P P;
    int i;
    char teste[3];
    char tema[60];
    if(pales==NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    fread(&P,sizeof(P),1,pales);
    printf("Digite o tema: ");
    gets(tema);
    strupr(tema);
    if(buscarPalestra(tema)==1){
        printf("Palestra já cadastrada\n");
        return;
    }else{
        printf("TEMA: ");
        setbus(stdin,NULL);
        gets(P.tema);
        strupr(P.tema);
        printf("\nEscolha o auditório: ");
        printf("\nDigite 1 para auditório 1");
        printf("\nDigite 2 para auditório 2");
        printf("\nDigite 3 para auditório 3");
        scanf("%d",&i);
        switch(i){
            case 1:
                char c = "AUDITORIO 1";
                P.local = c;
                printf("\nCAPACIDADE: 150 PESSOAS");
                break;

            case 2:
                char c = "AUDITORIO 2";
                P.local = c;
                printf("\nCAPACIDADE: 100 PESSOAS");
                break;

            case 3:
                char c = "AUDITORIO 3";
                P.local = c;
                printf("\nCAPACIDADE: 50 PESSOAS");
                break;

            default:
                printf("INVALIDO\n");
                break;
        }
        printf("\nINSCRIÇÃO DO PALESTRANTE: ");
        scanf("%d",&i);
        if(buscaInscricaoPalestrante(i)==0){
            printf("Palestrante não cadastrado\n");
            printf("Deseja cadastrar palestrante?");
            printf("Aperte [Y] para sim e [N] para não cadastrar");
            setbuf(stdin,NULL);
            gets(teste);
            strupr(teste);
            if(teste='Y'){
                setPalestrante();
                printf("\nINSCRIÇÃO DO PALESTRANTE: ");
                scanf("%d",&i);
                fread(&PALES,sizeof(PALES),arq_pales);
                while(!feof(arq_cong)){
                    if(PALES.ins==i){
                        P.palestrante = PALES.nome;
                    }
                    fread(&PALES,sizeof(PALES),arq_pales);
                }
            }else{
                printf("Saindo do cadastro de palestra\n");
                fclose(pales);
                fclose(arq_pales);
                return;
            }
        }else{
            while(!feof(arq_pales)){
                    if(PALES.ins==i){
                        P.palestrante = PALES.nome;
                    }
                    fread(&PALES,sizeof(PALES),arq_pales);
                }
        }
        printf("\nCARGA HORÁRIA: ");
        setbuf(stdin,NULL);
        gets(P.cargaHoraria);
        printf("HORÁRIO: ");
        setbuf(stdin,NULL);
        gets(P.horario);
        fwrite(&P,sizeof(P),1,pales);
    }
    fclose(arq_pales);
    fclose(pales);
};
*/
