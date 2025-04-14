#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
//autore: Carmelo Panepinto - Programma: Blackjack definitivo 


void stampa_carta( int a, char seme[]) {
	
	if (a<10) {
		printf("\t\t\t\t\t\t ___\n");
		printf("\t\t\t\t\t\t| %d |\n", a);
		printf("\t\t\t\t\t\t| %c |\n", seme[rand() %4]);
		printf("\t\t\t\t\t\t ---\n");
	}	
	else if (a>=10) {                        //stampa della carta di dimensione corretta (se il numero è a due cifre, la carta sarà più grande
		printf("\t\t\t\t\t\t ____\n");
		printf("\t\t\t\t\t\t| %d |\n", a);
		printf("\t\t\t\t\t\t|  %c |\n", seme[rand() %4]);
		printf("\t\t\t\t\t\t ----\n");
	}
}

void stampa_carte( int a, int b, char seme[]) {
	
	if (a<10 && b<10) {
		printf("\t\t\t\t\t\t ___\t ___\n");
		printf("\t\t\t\t\t\t| %d |\t| %d |\n", a, b);
		printf("\t\t\t\t\t\t| %c |\t| %c |\n", seme[rand() %4], seme[rand() %4]);
		printf("\t\t\t\t\t\t ---\t ---\n");
		printf("\n\n");
	}
	else if (a>=10 && b>=10){
		printf("\t\t\t\t\t\t ____\t ____\n");
		printf("\t\t\t\t\t\t| %d |\t| %d |\n", a, b);
		printf("\t\t\t\t\t\t|  %c |\t|  %c |\n", seme[rand() %4], seme[rand() %4]);
		printf("\t\t\t\t\t\t ----\t ----\n");
		printf("\n\n");
	}
	else if (a>=10) {
		printf("\t\t\t\t\t\t ____\t ___\n");
		printf("\t\t\t\t\t\t| %d |\t| %d |\n", a, b);
		printf("\t\t\t\t\t\t|  %c |\t| %c |\n", seme[rand() %4], seme[rand() %4]);
		printf("\t\t\t\t\t\t ----\t ---\n");
		printf("\n\n");
	}	
	else if (b>=10) {
		printf("\t\t\t\t\t\t ___\t ____\n");
		printf("\t\t\t\t\t\t| %d |\t| %d |\n", a, b);
		printf("\t\t\t\t\t\t| %c |\t|  %c |\n", seme[rand() %4], seme[rand() %4]);
		printf("\t\t\t\t\t\t ---\t ----\n");
		printf("\n\n");
	}
}

void stampa_tot_carte(int carte[], int contatore) {
	int i;
	
	printf("\t\t\t\t\t\t");
	for (i=0; i<contatore; i++) {
		if (carte[i]<10) printf(" ___\t");   //stampa della carta di dimensione corretta (se il numero è a due cifre, la carta sarà più grande
		else printf(" ____\t");	
	}
	printf("\n");
	
	printf("\t\t\t\t\t\t");
	for (i=0; i<contatore; i++) printf("| %d |\t", carte[i]);
	printf("\n");
	
	printf("\t\t\t\t\t\t");
	for (i=0; i<contatore; i++) {
		if (carte[i]<10) printf(" ---\t");
		else printf(" ----\t");
	}
	printf("\n\n");
	
	}

int estrazione(int righe, int colonne, int mazzo[righe][colonne], int carte[], int posizione) {
	
	int i, j;
	
	while (1) {
		carte[posizione]= mazzo [rand() %13] [rand() %4];  //carta del banco = un valore casuale della matrice mazzo
		if (carte[posizione]==0) continue;  //se il valore estratto è zero, ripetere l'estrazione finchè viene estratto un valore valido
		else break;
	};
	//SOSTITUIZIONE DEL VALORE ESTRATTO DAL MAZZO CON 0
	for (i=0; i<13; i++){
		for (j=0; j<4; j++){
			if (carte[posizione]==mazzo[i][j]) {
				mazzo[i][j]= 0;      
				break;
			}
		}
	};
	
	return carte[posizione];
}

int main () {
	
//-----------------------------------------------------------------DICHIARAZIONE VARIABILI, VETTORI E MATRICE MAZZO---------------------------------------------------------------------------------------------
	
	int i, j, k=2, scelta, scelta_2, tot_banco=0, tot_giocatore=0, intervallo_operazioni = 2; //k (contatore) =2 perchè le prime due carte si estraggono prima
	bool blackjack;                                                //bandiera per segnalare il blackjack
	float conto_iniziale, conto=500, puntata;	
	int carte_giocatore[10];             						   //vettore contenente le carte del giocatore	
	int carte_banco[10];                  					   	   //Vettore contentente le carte del banco
	char seme[4] = {'C', 'Q', 'F', 'P'};  						   //vettore seme	
	int mazzo[13][4]= {                   					 	   //matrice carte
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{4, 4, 4, 4},
		{5, 5, 5, 5},
		{6, 6, 6, 6},
		{7, 7, 7, 7},
		{8, 8, 8, 8},
		{9, 9, 9, 9},
		{10, 10, 10, 10},
		{10, 10, 10, 10},
		{10, 10, 10, 10},
		{10, 10, 10, 10},
	};
	
//--------------------------------------------------------------------------------------------BODY PROGRAMMA---------------------------------------------------------------------------------------------		
	printf("Benvenuto del tavolo di blackjack.\n");
	printf("Il tuo conto iniziale \x8a: [ $%.2f ]", conto);
	printf("\n\n");
	printf("Per iniziare la partita, inserisci la puntata iniziale: ");
	
	do{
		//------------------------------PULIZIA VETTORI E VARIABILI PER RIPETIZIONE CICLO-------------------------------------------------------
		conto_iniziale=conto;
		for (int i = 0; i < 10; ++i) {
			carte_banco[i] = 0;            //Pulizia vettore banco
        	carte_giocatore[i] = 0;        //Pulizia vettore giocatore
    	}	
		k=2;                               // reset variabile
		blackjack=false;
		srand(time(NULL));                 //seed della funzione random
		
		//---------------------------------------------ESTRAZIONE CARTA 1 BANCO------------------------------------------------------------------
		while (1) {
			scanf("%f", &puntata);
			if (puntata>conto) {
				printf("La puntata supera il tuo saldo totale. Inserisci un valore idoneo (max $%.2f): ", conto);
				continue;
			}
			else break;
		}
		
		printf("\n\n");
		printf("\t\t\t\t\t\t\t\tIl tuo conto: [ $%.2f ]\tPuntata: [ $%.2f ]\n\n", conto, puntata);
		printf("Inizio partita...\n");
		sleep(intervallo_operazioni-1);
		printf("\n\n\t\t----------------------------------------------------------------------Partita iniziata----------------------------------------------------------------------\n\n");
		printf("Prima carta del banco: \n");
		stampa_carta(estrazione(13,4,mazzo,carte_banco,0), seme);
		
		//-----------------------------------------ESTRAZIONE CARTE 1 E 2 GIOCATORE--------------------------------------------------------------
		
		printf("\nLe tue carte sono: \n");
		stampa_carte(estrazione(13,4,mazzo,carte_giocatore,0), estrazione(13,4,mazzo,carte_giocatore,1), seme);
		tot_giocatore=carte_giocatore[0]+carte_giocatore[1];
		printf("\n\t\t\t\t\t\tTotale : [ %d ]\n\n", tot_giocatore);
		
		//CASO BLACKJACK
		if (tot_giocatore==21){
			printf("Complimenti, hai fatto Blackjack. Hai vinto!\n\n\n");
			conto+=puntata*1.5;
			blackjack=true;
			break;
		};
		printf("\t\t--------------------------------------------------------------------------------------\n");
		//------------------------------------------------------CICLO CHIAMATA GIOCATORE--------------------------------------------------------------------------------------------
		
		do {
			printf("\n");
			printf("1) Chiamo carta\n");
			printf("2) Mi sto\n");
			printf("Cosa vuoi fare? ");
			scanf("%d", &scelta_2);
			printf("\n");
			
			switch (scelta_2) { 
				case 1: //----------------------------------------------CHIAMATA CARTA------------------------------------------------
					printf("Peschi una carta... \n");
					printf("La carta pescata \x8a: \n\n");
					stampa_carta(estrazione(13,4,mazzo,carte_giocatore,k), seme);
					tot_giocatore+=carte_giocatore[k];                                     //accumulatore
					printf("\n\t\t\t\t\t\tTotale : [ %d ]\n\n", tot_giocatore);
					k++;                                                                   //accumulatore
					//-----------------------------------CASI DURANTE CHIAMATA-----------------------------------------
					//SE LA SOMMA DELLE CARTE SUPERA 21
					if (tot_giocatore>21) {
						printf("Mi dispiace, hai fatto palazzo..\n\n\n");
						conto-=puntata;
						break;           //USCITA SWITCH(1 CICLO)
					}
					
					//CASO BLACKJACK
					else if (tot_giocatore==21){
						printf("Complimenti, hai fatto Blackjack. Hai vinto!\n\n\n");
						conto+=puntata*1.5;
						blackjack=true;
						break;           //USCITA SWITCH(1 CICLO)
					};
					
					break; 
					
				case 2://----------------------------------------------STAMPA CARTE----------------------------------------------------
					printf("Hai deciso di fermarti. Le tue carte sono:\n");
					stampa_tot_carte(carte_giocatore, k);                                  //accumulatore
					printf("\t\t\t\t\t\tTotale : [ %d ]\n\n", tot_giocatore);
					break;	
					
				default: printf("Scelta non valida.\n");
			}
			if (tot_giocatore>=21) {		//USCITA DO WHILE(2 CICLO)
				break; 
			}
		}
		while (scelta_2!=2);
		printf("\t\t--------------------------------------------------------------------------------------\n");
		k=2;                                                                            //reset accumulatore
		//------------------------------------------------------CICLO BANCO--------------------------------------------------------------------------------------------
		while(tot_giocatore<21) { //primo ciclo
			//-----------------------------------ESTRAZIONE SECONDA CARTA BANCO-----------------------------------------
			sleep(intervallo_operazioni);
			printf("Il banco rivela la seconda carta...\n\n");
			printf("La seconda carta del banco \x8a: \n");
			stampa_carta(estrazione(13,4,mazzo,carte_banco, 1), seme);
			printf("\nLe carte del banco sono: \n"); 
			stampa_tot_carte(carte_banco, k);                                            //accumulatore
			tot_banco=carte_banco[0]+carte_banco[1];
			printf("\n\t\t\t\t\t\tTotale : [ %d ]\n\n", tot_banco);
			printf("\t\t--------------------------------------------------------------------------------------\n");
			
			//-----------------------------------CASI ESTRAZIONE BANCO-----------------------------------------
			
			//SE CON LE PRIME DUE CARTE IL MANCO HA GIA' PIU' I 16, CONFRONTA
			if (tot_banco>16) {
				printf("Il banco si ferma.\n");
				if (tot_giocatore>tot_banco) {
					printf("Complimenti, hai vinto!\n\n");
					conto+=puntata;
					break; //USCITA CICLO WHILE(1)
				}
				else if (tot_giocatore<tot_banco) {
					printf("Mi dispiace, hai perso..\n\n");
					conto-=puntata;
					break; //USCITA CICLO WHILE (1)
				}
			}
			//SE NON HA 16, CHIAMA
			while (tot_banco<=16) { //finchè non arrivi almeno a 16
				printf("Il banco pesca una carta...\n");
				sleep(intervallo_operazioni);
				printf("Carta pescata: \n");
				stampa_carta(estrazione(13,4,mazzo,carte_banco,k), seme);
				tot_banco+=carte_banco[k];                                               //accumulatore
				printf("\n\t\t\t\t\t\tTotale : [ %d ]\n\n", tot_banco);
				k++;                                                                     //accumulatore
			}
			printf("Il banco si ferma. Le carte del banco sono: \n");
			stampa_tot_carte(carte_banco, k);
			
			//-----------------------------------RISULTATI FINALE-----------------------------------------------
			
			//CARTE DEL BANCO MAGGIORE DI 21
			if (tot_banco>21) {
				printf("Il banco ha fatto palazzo. \nComplimenti, hai vinto!\n\n");
				conto+=puntata;
				break;       //USCITA CICLO WHILE (1)
			}
			//BANCO = 21
			else if (tot_banco==21) {
				printf("\nIl banco ha fatto blackjack. \nMi dispiace, hai perso..\n\n");
				conto-=puntata;
				break;       //USCITA CICLO WHILE (1)
			}
			//GIOCATORE VINCENTE
			else if (tot_giocatore>tot_banco){
				printf("\nComplimenti, hai vinto!\n\n");
				conto+=puntata;
				break;       //USCITA CICLO WHILE (1)
			}
			//BANCO VINCENTE
			else if (tot_banco>tot_giocatore){
				printf("\nMi dispiace, hai perso..\n\n");
				conto-=puntata;
				break;       //USCITA CICLO WHILE (1)
			}
			//PAREGGIO
			else if (tot_banco==tot_giocatore){
				printf("\nHai pareggiato..\n\n");
				break;       //USCITA CICLO WHILE (1)
			}
		}//chiusura while(ciclo chiamata banco)
		
		printf("\n\n\t\t----------------------------------------------------------------------Partita conclusa----------------------------------------------------------------------\n");
		printf("Il tuo conto:");
		if (conto_iniziale<conto) {
			if (blackjack==true) printf(" [ $%.2f (+%.2f)]\n\n", conto, puntata*1.5);
			else printf(" [ $%.2f (+%.2f)]\n\n", conto, puntata);
		}
		else if (conto_iniziale>conto) printf(" [ $%.2f (-%.2f)]\n\n", conto, puntata);
		
		if (conto<=0) {
			printf("Hai esaurito il conto..\n\n");
			printf("\t\t--------------------------------------------------------------------------GAME OVER--------------------------------------------------------------------------------------\n");
			break;
		}
		printf("1)Si\n");
		printf("2)No\n");
		printf("Vuoi continuare? ");
		scanf("%d", &scelta);
		printf("\n\n");
		if (scelta==1) printf("Quanto vuoi puntare? ");
		
	}//chiusura do while principale 
	while (scelta!=0);	
		
	return 0;
}