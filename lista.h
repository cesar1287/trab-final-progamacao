typedef struct _Palpite {
	char *cor;
	struct _Palpite *prox;
} palpites;

void gerarSenha(int,int);
int tentativas(palpites**,int,int);
int validar(char*,int,int);
