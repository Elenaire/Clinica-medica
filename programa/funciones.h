#ifndef FUNCIONES_H
  #define FUNCIONES_H
	using namespace std;
	#include <string>
	#include <ctime>
	#include <iostream>
	#include <list>
	#include "Paciente.h"
	struct fecha{
		int d;					//Dia
		int m;					//Mes
		int a;					//Año

		public:
		bool operator==(fecha f){
			if(f.a==a){
				if(f.m==m){
					if(f.d==d){
						return true;
					}
				}
			}
			else{
				return false;
			}
		}
		/*public fecha operator-(fecha f){
			int mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
			struct fecha aux;
			if((aux=f1-f2)<0){}

		}*/
		bool operator<(fecha f){
			if(a<f.a){return true;}
			else if(a>f.a){return false;}
			else{
				if(m<f.m){return true;}
				else if(m>f.m){return false;}
				else{
					if(d>f.d){return false;}
					else {return true;}
				}
			}
		}
	};
	static fecha HOY;
	struct hora{
		int h;					//Hora
		int m;					//Minuto
		int s;					//Segundo
	};

	void hoy(struct fecha &f);			//Actualiza f con la fecha actual
	void hoy(struct hora &h);			//Actualiza h con la hora actual
	bool leerFecha(struct fecha &f);		//--Lee d/m/a por teclado y devulve false si la fecha introducida no es correcta -Sin probar
	bool leerHora(struct hora &h);			//--Lee h:m por teclado y devulve false si la hora introducida no es correcta -Sin probar
	char* escribeFecha(struct fecha const &f);		//-Sin probar
	char* escribeHora(struct hora const &h);		//-Sin probar
	int dias(struct fecha f1,struct fecha f2);		//Devulve los dias transcurridos desde f1 hasta f2, si ha transcurrido mas de un mes devulve 100, f2 es anterios a f1 devuelve -1
	int minutos(struct hora h1,struct hora h2);		//Devulve los minutos transcurridos desde h1 hasta h2, si hay mas de 2 horas de diferencia devulve 100 o -100
	list<Paciente> leerPacientes();								//Sin probar
	void mostrarPacientes(list<Paciente> &p);					//Sin probar
	bool filtrarPacientes(int filtro,list<Paciente> &p);		//Sin probar
	void ordenarPacientes(int parametro,list<Paciente> &p);		//Sin completar
	bool modificarTratamiento(Tratamiento &t);					//Sin hacer   //Mal, tiene que ser de tratamiento
	

#endif