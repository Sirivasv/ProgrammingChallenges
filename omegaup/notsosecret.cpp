#include "fascist.h"

// Funciones disponibles:
//   interrogar(i, j) (o interrogate(i, j))
//   acusar(i) (o accuse(i))

void eval(int n) {

    // Envia respuesta; termina ejecucion.
    int *cola = new int[n + 5];
	cola[0] = 0;
	int pos = 1;
	
	for (int i = 1; i < n; ++i)
		if (pos == 0)
			cola[pos++] = i;
		else if (interrogar(i, cola[pos - 1])) 
				pos--;
			else 
				cola[pos++] = i;
	
	for (int i = 0; i < n; ++i)
		if (interrogar(cola[0], i)) 
			acusar(i);
    responder();
    //answer();
}