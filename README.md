# Project-BlackJack

**Autore:** Carmelo Panepinto  
**Descrizione:**  
Questo programma in linguaggio C simula una partita di blackjack. Il gioco prevede l'estrazione casuale delle carte da un mazzo standard e gestisce il punteggio di giocatore e banco, verificando le condizioni di vittoria (blackjack, sballo, pareggio).

## Requisiti

- Un compilatore C: il codice è stato scritto, compilato ed eseguito con Embarcadero.  
- Ambiente compatibile (Windows, Linux, macOS).

## Istruzioni di Compilazione

Per compilare il codice sorgente con Embarcadero, segui le istruzioni fornite dall'ambiente di sviluppo (se hai già installato C basta premere F11). Se preferisci utilizzare GCC, ad esempio in un ambiente Unix-like, puoi compilare con:

```bash
gcc -o blackjack blackjack.c -Wall -Wextra
```

## Istruzioni di Esecuzione

Una volta compilato, eseguire il programma. Ad esempio, dalla riga di comando:


```bash
./blackjack
```

---

## Funzionalità Principali

### Simulazione del Mazzo
Le carte vengono estratte casualmente da un mazzo rappresentato tramite una matrice e, dopo l'estrazione, vengono "rimosse" (settate a 0) per evitare ripetizioni.

### Gestione delle Carte
Il programma differenzia la stampa delle carte in base al numero di cifre, per garantire una visualizzazione uniforme e chiara.

### Meccaniche di Gioco
Gestisce:
- L'estrazione iniziale delle carte.
- Il calcolo del punteggio del giocatore e del banco.
- Le decisioni (chiamare carta, fermarsi) durante la partita.

### Condizioni di Vittoria
Vengono verificate in tempo reale le condizioni di vittoria:
- Blackjack.
- Sballo (palazzo).
- Confronto del punteggio finale.
- Pareggio.

---

## Note Aggiuntive

- Il programma utilizza la funzione `sleep` per creare pause e rendere l'esperienza di gioco più interattiva.
- Se si utilizza **Embarcadero**, consultare la documentazione specifica per eventuali differenze nella gestione delle funzioni di I/O o di sistema.

