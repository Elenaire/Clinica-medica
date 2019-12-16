#ifndef FUNCIONES_H
  #define FUNCIONES_H
	using namespace std;
	#include "fecha_hora.h"
	#include <string>
	#include <iostream>
	#include <list>
	#include "Paciente.h"

	list<Paciente> leerPacientes();								//Lee un paciente del fichero de pacientes -Sin probar
	void mostrarPacientes(list<Paciente> &p);					//Muestra los datos de la lista de pacientes -Sin probar
	bool filtrarPacientes(int filtro,list<Paciente> p);			//Sin probar
	void ordenarPacientes(int parametro,list<Paciente> p);		//Sin completar
	bool modificarTratamiento(Tratamiento &t);					//Sin hacer   //Mal, tiene que ser de tratamiento
	void consultarTramientos(Paciente &p);
	void anadirTratamiento(Paciente &p);
	

#endif