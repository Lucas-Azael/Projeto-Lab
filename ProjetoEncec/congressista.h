#ifndef CONGRESSISTA_HEADERS
#define CONGRESSISTA_HEADERS
typedef struct congressista CO;
void setCongressista();
FILE *arq_cong;
FILE *arq_temp;
void buscarCongressista();
int buscaInscricao(int ins);
char nomeCongressista(int ins);
void removeCongressista();
void listarCongressista();
void cadastroPalestra();
void cadastroOficina();
#endif // CONGRESSITA_HEADERS
