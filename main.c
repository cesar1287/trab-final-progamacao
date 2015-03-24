#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./lista.h"
#include "./cores.h"

int main(){
char *cores[] = {"\x1B[31m- vm: vermelho","\x1B[32m- vd: verde","\x1B[33m- am: amarelo\x1B[0m","\x1B[34m- az: azul\x1B[0m","\x1B[35m- mg: magenta\x1B[0m","\x1B[36m- ci: ciano\x1B[0m"};
char *se;
int teste=1,i,sen=0,pos,lim,cont=0,invalida=0;;
palpites *palpite = NULL;
while(teste!=0){	
	printf("Digite o tamanho da senha(de 4 a 12):\n");
	scanf("%d", &sen);
	if(sen>=4 && sen<=12)
		teste=0;
}
teste = 1;

while(teste!=0){
	printf("Digite as possibilidades de cores(de 3 a 6):\n");
	scanf("%d", &pos);
	if(pos>=3 && pos<=6)
		teste=0;
}
teste = 1;
while(teste!=0){
	printf("Digite o limite de tentativas de adivinhação(a partir de 1):\n");
	scanf("%d", &lim);
	if(lim>=1)
		teste=0;
}
printf("\nEntre com uma combinação de %d elementos dentre as %d cores seguintes:\n",sen,pos);

for(i=0;i<pos;i++)
	printf("%s\n",cores[i]);

gerarSenha(sen,pos);

while(cont<lim){
	if(cont<1 && invalida==0){
		printf("\nEntre a sua tentativa,separando os elementos por vírgula:\n");
	}else if(cont>=1 && invalida==0){
		printf("\nEsta foi a tentativa de número %d.Você não acertou.Entre sua nova tentativa:\n",cont);
	}else if(invalida==1){
		printf("\nDigite sua entrada novamente,separando os elementos por vírgula\n");
	}
	se = (char*) malloc(sizeof(char));
	__fpurge(stdin);
	gets(se);
	__fpurge(stdin);
	if(validar(se,sen,pos)==1){
		invalida=0;
		if(tentativas(&palpite,sen,lim)==1){
			cont++;
			printf("\nParabéns. Você conseguiu adivinhar a senha com %d tentativa(s).\n",cont);
			exit(0);
		}else{
			cont++;
		}
	}else{
		invalida=1;
		printf("\nTentativa inválida");
	}
}
printf("\nVocê não conseguiu acertar a senha,e suas tentativas se esgotaram,obrigado por jogar.\n\n");
exit(0);
}
