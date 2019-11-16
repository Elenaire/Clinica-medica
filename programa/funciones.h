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

	void hoy(struct fecha &f);			//Actualiza f con la fecha actual
	void hoy(struct hora &h);			//Actualiza h con la hora actual
	bool leerFecha(struct fecha &f);		//--Lee d/m/a por teclado y devulve false si la fecha introducida no es correcta -Sin crear -Sin Usar
	bool leerHora(struct hora &h);			//--Lee h:m:s por teclado y devulve false si la hora introducida no es correcta -Sin crear -Sin Usar
	int dias(struct fecha f1,struct fecha f2);		//Devulve los dias transcurridos desde f1 hasta f2, si ha transcurrido mas de un mes devulve 100, f2 es anterios a f1 devuelve -1