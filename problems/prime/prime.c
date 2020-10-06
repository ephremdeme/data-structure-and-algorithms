#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void) {
	float wurzelHeron = 0;
	float x = 0;

	int zahl = 0;
	int teiler = 0;
	int i;
	
	bool prim;
	
	printf("\nBitte geben Sie eine Zahl ein: ");
	scanf("%d",&zahl);
	if (zahl < 2)  {
		printf("Das ist KEINE primzahl");
		return (EXIT_SUCCESS);
	}
	
	x = (zahl + 1)/2;
	
	for (i = 0; i < 3; i++); {
		wurzelHeron = 0.5*(x+zahl/x);
		x = wurzelHeron;
	}
	
	int wurzel = wurzelHeron;
	
	prim = true;
	for (teiler = 2; teiler <= wurzel2; teiler++) {	
		if (zahl%teiler == 0) {
			prim = false;
		}
	}
	
	if (prim == true) {
		printf("\n++++++++ BINGO ++++++++ \n\n %d ",zahl);
		}
	}else{
		printf("\n++++++++ ZONK ++++++++ \n\n %d ",zahl);
	}
	
	
	return (EXIT_SUCCESS);
}