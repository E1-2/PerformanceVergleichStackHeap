// Performance Vergleich Stack vs. Heap
#include <ctime>
#include <iostream>
using namespace std;

struct Data {
	char b[1024] = { 0 }; // 1.024 Byte werden mit 0 initialisiert.
};

int main() {
	int zahl = 10000000;  // 10.000.000 >> INT_MAX wären 2.147.483.647

	clock_t start = clock();			// Legt die Variable "start" an und starte die Zeiterfassung für die "Stack" Messung. 
	for (int i = 0; i < zahl; ++i) {	// 10 Millionen mal
		Data d{};						// wird das char b mit jeweils 1 MB im Stack angelegt. 
	}
	clock_t verbrauchte_zeit = clock() - start;		// aktuelle Zeit - start >> verbrauchte_zeit	
	cout << " Stack Time " << float(verbrauchte_zeit) / CLOCKS_PER_SEC << " sec \n";

	start = clock();
	for (int i = 0; i < zahl; ++i) {
		Data* d = new Data;				// Speicherreservierung auf dem Heap
		delete d;						// Speicherfreigabe
	}

	verbrauchte_zeit = clock() - start;
	cout << " Heap Time " << float(verbrauchte_zeit) / CLOCKS_PER_SEC << " sec \n";

	return 0;
}

