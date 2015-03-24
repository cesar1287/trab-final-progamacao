#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "./lista.h"
#include "./cores.h"

char *cor[] = {"vm","vd","am","az","mg","ci"};
char *cores[] = {"\x1B[31mvm \x1B[0m","\x1B[32mvd \x1B[0m","\x1B[33mam \x1B[0m","\x1B[34maz \x1B[0m","\x1B[35mmg \x1B[0m","\x1B[36mci \x1B[0m"};
char *senha,*tentativa,*senha1;	

void gerarSenha(int sen,int pos){
	int cont=0,i=0,num;
	senha = (char*) malloc(sizeof(char));
	senha1 = (char*) malloc(sizeof(char));
	if(senha==NULL){
		printf("Memória insuficiente,o programa será encerrado agora!\n");
		exit(1);
	}
	srand(time(NULL));
	for(i=0;i<sen;i++){
		num = rand()%pos;
		if(i==sen-1){
			strcat(senha,cor[num]);
		}else{
			strcat(senha,cor[num]);
			strcat(senha,",");
		}
	}
	printf("\nSenha:%s\n",senha);
	strcpy(senha1,senha);
}

int validar(char *se,int sen,int pos){
	char *teste,*copia,*copiase;
	copia = (char*) malloc(sizeof(char));
	copiase = (char*) malloc(sizeof(char));
	strcpy(copia,se);
	strcpy(copiase,se);
	int cont=0,j;
	if(strpbrk(",",se)==NULL){
		return 0;
	}else if(strlen(se)<(sen*3)-1){
		return 0;
	}
	
	teste = strtok(se,", ");
	while(teste != NULL){
		if(strlen(teste)!=2){
			return 0;
		}
		cont++;
		teste = strtok(NULL,", ");
	}
	if(cont==sen){
		teste = strtok(copia,", ");
		while(teste != NULL){
			cont = 0;
			for(j=0;j<pos;j++){
				if(strcmp(teste,cor[j])==0){
					cont++;	
				}
			}
			if(cont==0){
				return 0;
			}
			teste = strtok(NULL,", ");
		}			
		tentativa = (char*) malloc(sizeof(char));
		teste = strtok(copiase,", ");
		j=0;
		while(teste != NULL){
			if(j==sen-1){
				strcat(tentativa,teste);
			}else{
				strcat(tentativa,teste);
				strcat(tentativa,",");	
			}
			teste = strtok(NULL,", ");
			j++;
		}
		return 1;			
	}else{		
		cont=0;
		return 0;
	}
}
int tentativas(palpites **ll,int se,int lim){
	if(strcmp(tentativa,senha1)==0)
		return 1;
	else{
		char *teste,*aux1,*aux2,*copsenha,*tent,*coptent;
		copsenha = (char*) malloc(sizeof(char));
		coptent = (char*) malloc(sizeof(char));
		strcpy(copsenha,senha1);
		strcpy(coptent,tentativa);
		aux1 = malloc(sizeof(char));
		aux2 = malloc(sizeof(char));
		tent = malloc(sizeof(char));
		int i=0,cont=0,x,y;
		palpites *novo,*aux;
		novo=(palpites*)malloc(sizeof(palpites));
		novo->prox = NULL;
		novo->cor = tentativa;
		if ((*ll) == NULL){
			(*ll) = novo;

			teste = strtok(tentativa,",");
			printf("\n");
			while(teste!=NULL){
				for(i=0;i<6;i++){
					if(strcmp(teste,cor[i])==0){
						printf("%s",cores[i]);
						cont++;
					}
				}
				if(cont==se){
					printf(" --> ");
				}
				teste = strtok(NULL,",");
			}
			senha[0] = '\0';
			tentativa[0] = '\0';
			teste = strtok(coptent,",");
			while(teste!=NULL){
				memmove(tent,copsenha,2);
				memset(copsenha,' ',3);
				for(x = 0; x < strlen(copsenha); x++) {
					if(copsenha[x] == ' ') 
						continue;
					copsenha[y] = copsenha[x];
					y++;
    			}
    			copsenha[y] = '\0';
				y=0;
				if(strcmp(tent,teste)==0)
					strcat(aux1,"@ ");
				else{
					strcat(senha,tent);
					strcat(tentativa,teste);
					strcat(tentativa," ");
				}
				teste = strtok(NULL,",");	
			}
			
			tent[0] = '\0';
			teste = strtok(tentativa," ");
			while(teste!=NULL){
				if(strstr(senha,teste)!=NULL)
					strcat(aux1,"! ");
				teste = strtok(NULL," ");	
			}
			printf("%s",aux1);
			tentativa[0] = '\0';
		}/*else{
			aux = (*ll);
			cont = 0;
			while ( (aux->prox != NULL) ) )
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}*/
	}
}	


