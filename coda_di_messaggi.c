/*
P1:
1. crea la coda di messaggi
2. ciclicamente deve chiedere da tastiera una stringa
2.1. assegna un mtype=val
2.2 invia il messaggio

P2 
1.riceve messaggio con mtype=1

P3 
1.riceve messaggio con mtype=2

P4
1.riceve messaggio con mtype=3

*/

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
		//mandiamo a turno un messaggio a tutti i processi, per definire il turno uso la variabile turno. 
		msg.mtype = (turno % 3) + 1; //dà un numero da 1 a 2 più 1 = 3
		printf("Inserisci stringa: ");
		fgets(msg.info.stringa, STRDIM, stdin);

		if(strncmp(msg.info.stringa, "esci", 4) == 0){ //strcmp "esci\0"
			msg.mtype = 1;
			msgsnd(msgid, &msg, sizeof(struct dati), 0);	//mando il messaggio
			
			//controllo errore
			
			msg.mtype = 2;
			msgsnd(msgid, &msg, sizeof(struct dati), 0);

			//controllo errore
			
			msg.mtype = 3;
			msgsnd(msgid, &msg, sizeof(struct dati), 0);
			break;
		}
		
			msgsnd(msgid, &msg, sizeof(struct dati), 0);
			turno++; //incremento per passare la parola all'altro processo.
		
	}
	//proseguo con l'eliminazione della coda di messaggi
	msgctl(msgid, IPC_RMID, 0);
	
	

}




























