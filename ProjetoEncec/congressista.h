#ifndef CONGRESSITA_HEADERS
#define CONGRESSISTA_HEADERS
typedef struct congressista CO;
void setCongressista();
FILE *arq_cong;
void buscarCongressista();
int buscaNome(char nome);
void removeCongressista(char nome);
void listarCongressista();
void editarCongressista();
#endif // CONGRESSITA_HEADERS
