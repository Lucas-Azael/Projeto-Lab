#include <stdio.h>


typedef struct
{
    char nome[30];
    char palestra[30];
    char oficina[30];
    char grupoDiscussao[30];
    char cursos[30];
}Congressista;

Congressista setCongressista(char nome[30], char palestra[30], char oficina[30], char grpDisc[30],char cursos[30], Congressista C){
    C.nome[30] = nome[30];
    C.palestra[30] = palestra[30];
    C.oficina[30] = oficina[30];
    C.grupoDiscussao[30] = grpDisc[30];
    C.cursos[30] = cursos[30];
    return C;
}

void armazenaCongressista(Congressista C, int n) {
    Congressista qtd[300];
    int i;
    for(i=0;i<300;i++){
        qtd[n] = C;
    }
}

int main() {
    
    char nome[30];
    char palestra[30];
    char oficina[30];
    char grupoDiscussao[30];
    char curso[30];
    Congressista C;

    int i;

    printf("Digite 1 para cadastrar congressista \n");
    scanf("%d",&i);

    switch (i)
    {
    case 1:
        printf("Nome: ");
        fgets(nome, 30, stdin);
        printf("Palestra: ");
        fgets(palestra, 30, stdin);
        printf("Oficina: ");
        fgets(oficina, 30, stdin);
        printf("Grupo de Discussao: ");
        fgets(grupoDiscussao, 30, stdin);
        printf("Nome: ");
        fgets(curso, 30, stdin);
        setCongressista(nome, palestra, oficina, grupoDiscussao, curso, C);

        printf("Nome: %c // palestra: %c\n", C.nome, C.palestra);

        break;
    
    default:
        break;
    }
       
    return 0;
}