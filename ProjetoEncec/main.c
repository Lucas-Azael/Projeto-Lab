#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "congressista.h"
#include "palestrante.h"

FILE *pales;

/*typedef struct palestra
{
    char tema[60];
    char cargaHoraria[60];
    char palestrante[60];
    char horario[60];
    char local[60];
    char congressista[60];
} PALES;

void cadastrarPalestra(char *palestrante)
{
    pales = fopen("palestra.txt","a+b");
    int i;
    char *c;
    PALES P;
    if(pales==NULL)
    {
        printf("Erro nao abrir arquivo\n");
        return;
    }
    printf("TEMA: ");
    setbuf(stdin, NULL);
    gets(P.tema);
    strupr(P.tema);
    printf("\nCARGA HORÁRIA: ");
    setbuf(stdin, NULL);
    gets(P.cargaHoraria);
    printf("\nHORÁRIO: ");
    setbuf(stdin, NULL);
    gets(P.horario);
    printf("\nEscolha o auditório: ");
    printf("\nDigite 1 para auditório 1");
    printf("\nDigite 2 para auditório 2");
    printf("\nDigite 3 para auditório 3\n");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        c = "AUDITORIO 1";
        strcpy(P.local,c);
        printf("\nCAPACIDADE: 150 PESSOAS");
        break;

    case 2:
        c = "AUDITORIO 2";
        strcpy(P.local,c);
        printf("\nCAPACIDADE: 100 PESSOAS");
        break;

    case 3:
        c = "AUDITORIO 3";
        strcpy(P.local,c);
        printf("\nCAPACIDADE: 50 PESSOAS");
        break;

    default:
        printf("INVALIDO\n");
        break;
    }
    strcpy(P.palestrante, palestrante);
    fwrite(&P,sizeof(P),1,pales);
    fclose(pales);
}

void cadastrarCongressPalestra(char *nome)
{
    PALES P;
    int i;
    int *p = &i;
    char *c;
    pales = fopen("palestra.txt","a+b");
    if(pales==NULL){
        printf("Erro na abetura do arquivo\n");
        return;
    }
    printf("CADASTRO DE CONGRESSISTA NA PALESTRA\n");
    printf("NOME DA PALESTRA: \n");
    setbuf(stdin,NULL);
    gets(c);
    strupr(c);
    fread(&P,sizeof(P),1,pales);
    while(!feof(pales)){
        if(P.tema==c){
            strcpy(P.congressista, nome);
            fseek(pales,sizeof(P),SEEK_CUR);
            fwrite(&P.congressista,sizeof(P.congressista),1,pales);
        }
        fread(&P,sizeof(P),1,pales);
    }
    fclose(pales);
}
void listarPalestra();
*/
int main()
{
    const char* PASTAS[5] = {"congressistas","palestrantes","palestras","oficinas","gpDiscs"};
    int i, ret;
    for(i=0;i<sizeof(PASTAS);i++){
       ret = mkdir("C:\\Users\\azael\\OneDrive\\Documentos\\GitHub\\Projeto-Lab\\ProjetoEncec\\data\\%s", PASTAS[i],0777);
       if(ret<0){
        printf("Erro ao criar diretório\n");
        return ret;
       }
    }
    setlocale(LC_ALL,"Portuguese");
    /*int ins;
    char *palestrante;
    char *congressista;*/
    setCongressista();
    //buscarCongressista();
    //listarCongressista();
    //removeCongressista();
    //listarCongressista();
    //setPalestrante();
    /*printf("Codigo do congressista\n");
    scanf("%d", &ins);
    if(buscaInscricao(ins)==0){
        printf("Palestrante não cadastrado\n");
    }else{
        congressista = nomeCongressista(ins);
        cadastrarCongressPalestra(congressista);
    }*/

    //setPalestra();
    return 0;
}
