/*
	Gestione di una lista
	Simulare la gestione di una coda di utenti, in fila
 	allo sportello. (LIFO)


 */
#include <iostream>

using namespace std;

#define ESCI 6

struct persona{
	string nome;
	int eta;
	persona *next;
};

// dichiarazione funzioni
void stampa(persona *l);
persona *aggiungiInCoda(persona *lista);
persona *eliminaInCoda(persona *l);
persona *setPersona();
int menu();
persona *eliminaInTesta(persona *l);
persona *aggiungiInTesta(persona *p);

// inizio programma
int main()
{
	persona *lista = NULL;
	int scelta;

	do{
		scelta = menu();
		switch(scelta){
			case 1:
				lista = aggiungiInTesta(lista);
				break;
			case 2:
				lista = aggiungiInCoda(lista);
				break;
			case 3:
				lista = eliminaInTesta(lista);
				break;
			case 4:
				lista = eliminaInCoda(lista);
				break;
			case 5:
				stampa(lista);
				break;
			default:
				break;
		}

	}while(scelta != ESCI);



	return 0;
}

int menu()
{
	int scelta;
	cout << "1. Aggiungi in testa\n";
	cout << "2. Aggiungi in coda\n";
	cout << "3. Elimina in testa\n";
	cout << "4. Elimina in coda\n";
	cout << "5. Visualizza\n";
	cout << "6. Esci\n\n";
	cout << "Scelta: ";cin >> scelta;

	return scelta;
}

// visualizza gli elementi della coda
void stampa(persona *l)
{
	cout << endl;
	if(!l)
		cout << "Lista vuota!" << endl;
	else
		while(l){
			cout << l->nome << " - " << l->eta << endl;
			l = l->next;
		}
	cout << endl;
}

persona *setPersona()
{
	persona *p = new persona();
	cout << "Nome: ";cin >> p->nome;
	cout << "Eta': ";cin >> p->eta;
	p->next = NULL;

	return p;
}

// aggiunge in coda un nuovo elemento
persona *aggiungiInCoda(persona *lista)
{
	// salvo l'indirizzo della testa della coda
	persona *l = lista;
	// creazione nuova persona
	persona *p = setPersona();
	// accodamento
	if(!l)
		lista = p; // inizializzo il primo elemento
	else {
		while(l->next) // scorro la coda
			l = l->next;
		l->next = p;  // aggiungo l'elemento in coda
	}
	// restituisco sempre la testa della coda
	return lista;
}

persona *eliminaInTesta(persona *l)
{
	if(l){
		persona *p = l;
		l = l->next;
		delete(p);
	}
	return l;
}

persona *aggiungiInTesta(persona *l)
{
	persona *p = setPersona();
	p->next = l;
	return p;		
}

persona *eliminaInCoda(persona *l)
{
	persona *prec;
	persona *lista = l;
	if(l){
		// controllo se è l'unico elemento in tal caso lista diventa NULL
		if(!l->next){
			lista = NULL;
			delete(l);			
		} else		
			while(l->next){
				prec = l;
				l = l->next;
			}
		delete(l);
		prec->next = NULL;
	}
		
	return lista;
}
