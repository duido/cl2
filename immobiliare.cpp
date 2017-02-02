//Progettare per una società immobiliare una struttura di dati che descriva in modo adeguato le caratteristiche di un generico
//appartamento di abitazione civile (città, via, dimensione superficie, numero vani, numero balconi, con garage o senza,
//prezzo di vendita). Creare un vettore di dimensione n di tale struttura. 
//Scrivere una procedura di ricerca in questo vettore per individuare tutti gli appartamenti che hanno certe caratteristiche
//richieste (es. lista di tutti gli appartamenti di almeno 100mq dotati di garage). 
#include <iostream>

using namespace std;

#define N 3

struct appartamento {
	string citta;
	string via;
	int superficie;
	int vani;
	int balconi;
	double prezzo;
	bool garage;
};

void stampaRecord(appartamento a);
void ricerca(appartamento criterio, appartamento archivio[]); 

int main(){
	appartamento criterio = {"","",0,0,0,false};
	appartamento archivio[] = {
		{"pescara", "via celestino v", 110, 5, 2, 200000.00, true},
		{"pescara", "via volta", 90, 4, 2, 100000.00, false},
		{"chieti", "via milano", 105, 5, 1, 150000.00, true}		
	};
	int scelta;

	do{
		cout << "*** IMPOSTAZIONE PARAMETRI DI RICERCA ***\n";
		cout << "1. imposta citta'\n";
		cout << "2. imposta via\n";
		cout << "3. imposta superficie\n";
		cout << "4. imposta vani\n";
		cout << "5. imposta balconi\n";
		cout << "6. imposta prezzo\n";
		cout << "7. imposta garage\n";
		cout << "0. fai la ricerca\n";
		cin >> scelta;
		switch(scelta){
			case 1: 
				cin.get();
				cout << "Citta': "; getline(cin, criterio.citta);
				break;
			case 2: 
				cin.get();
				cout << "Via: "; getline(cin, criterio.via);
				break;
			case 3: 
				cout << "Superficie (minimo): "; cin >> criterio.superficie;
				break;
			case 4: 
				cout << "Vani (minimo): "; cin >> criterio.vani;
				break;
			case 5: 
				cout << "Balconi (minimo): "; cin >> criterio.balconi;
				break;
			case 6: 
				cout << "Prezzo (massimo): "; cin >> criterio.prezzo;
				break;	
			case 7: 
				cout << "Con garage\n"; criterio.garage = true;
				break;
		}
		//stampaRecord(criterio);
	}while(scelta != 0);
	
	ricerca(criterio, archivio);
		
	return 0;
}

void ricerca(appartamento c, appartamento archivio[]){
	
	
	for(int i = 0;i < N;i++){
		bool trovato = false;
		if((c.citta == "" || archivio[i].citta == c.citta) &&
		   (c.via == "" || archivio[i].via == c.via) &&
		   (c.superficie == 0 || archivio[i].superficie >= c.superficie) &&
		   (c.balconi == 0 || archivio[i].balconi >= c.balconi)  &&
		   (c.prezzo == 0 || archivio[i].prezzo <= c.prezzo) &&
		   (c.vani == 0 || archivio[i].vani >= c.vani) &&
		   (c.garage == false || archivio[i].garage == c.garage))
			trovato = true;
		if(trovato)
			stampaRecord(archivio[i]);	
		cout << endl; 
	}
}

void stampaRecord(appartamento a){
	cout << "Citta': " << a.citta << endl;
	cout << "Via: " << a.via << endl;
	cout << "Superficie: " << a.superficie << " Vani: " << a.vani << endl;
	cout << "Balconi: " << a.balconi << endl;
	cout << "Prezzo: " << a.prezzo << (a.garage?" con ":" senza ") << "garage." << endl;

}
