#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>

#define STRDIM 50

struct dati {				//in questo modo posso aggiungere anche altri dati alla struttura
	char stringa[STRDIM];
};

struct messaggio {
	long int mtype;
	struct dati info;
};

int main(){

	//creazione coda dei messaggi
	int msgid; //definiamo un identificatore
	int turno = 0;
	struct messaggio msg;
	
	msgid=msgget((key_t)7777, 0666 | IPC_CREAT);
	//if(msgid==-1) controllo errore
	
	while(1){
		printf("[P3]Attendo un messaggio...\n");
		msgrcv(msgid, &msg, sizeof(struct dati), 4, 0); //invece di 1: 0 se li voglio ricevere tutti
		//inserire controlo
		printf("Messaggio ricevuto: %s", msg.info.stringa);
		if(strncmp(msg.info.stringa, "esci", 4)==0){
			break;
		}
	}
		//qui non si rimuove la coda di mesaggi, conviene farla rimuovere all'ultimo processo
}
