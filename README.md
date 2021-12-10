# C-OS-es27-messages-queue
Una coda di messaggi viene creata e letta da 2 processi P1 e P2.

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
