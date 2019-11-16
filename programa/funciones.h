	#include <string>
	#include <ctime>
	#include <iostream>

	struct fecha{
		int d;					//Dia
		int m;					//Mes
		int a;					//Año
	};
	struct hora{
		int h;					//Hora
		int m;					//Minuto
		int s;					//Segundo
	};

	int dias(struct fecha f1,struct fecha f2);		//Devulve los dias transcurridos desde f1 hasta f2, si ha transcurrido mas de un mes devulve 100, f2 es anterios a f1 devuelve -1