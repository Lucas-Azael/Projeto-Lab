#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct {
    int capacidade;
    char local[30];
    int cargaHoraria;
    char tema[80];
    char horario[20];
}Palestra;

typedef struct {
    int capacidade;
    char local[30];
    int cargaHoraria;
    char tema[80];
    char horario[20];
}Oficina;

typedef struct {
    int capacidade;
    char local[30];
    int cargaHoraria;
    char tema[80];
    char horario[20];
}GpDiscussao;

typedef struct {
    int capacidade;
    char local[30];
    int cargaHoraria;
    char tema[80];
    char horario[20];
}Curso;

typedef struct {
    int capacidade;
    char local[30];
    int cargaHoraria;
    char tema[80];
    char horario[20];
}Oficina;

void cadastrarPalestra(Palestra *p) {
    setbuf(stdin, NULL);
    printf("Digite o local\n");
    gets(p->local);
    printf("Carga horária: ");
    gets(p->cargaHoraria);
    printf("Tema: ");
    gets(p->tema);
    printf("Horário: ");
    gets(p->horario);
}


int main() {
    
    
    setlocale(LC_ALL, "Portuguese");
    int i;

    printf("Digite 1 para cadastrar congressista \n");
    scanf("%d",&i);

    switch (i)
    {
    case 1:
        

        break;
    
    default:
        break;
    }
       
    return 0;
}