#ifndef FUNCIONES_H
  #define FUNCIONES_H
	using namespace std;
	#include "fecha_hora.h"
	#include <string>
	#include <iostream>
	#include <list>
	#include "Paciente.h"

	bool buscarPaciente(Paciente &p);
	void AgregaP();
	void menuPaciente(Paciente p);
	void leerPacientes(list<Paciente> &P);						//Lee los pacientes del fichero de pacientes
	void mostrarPacientes(list<Paciente> &p);					//Muestra los datos de la lista de pacientes
	bool filtrarPacientes(int filtro,list<Paciente> &p);
	void ordenarPacientes(int parametro,list<Paciente> &p);
	bool modificarCita(Cita &C);
	//Abre el menu de modificación de la cita y si se elimina la cita pone a -1 paciente_, devuelve false si el usuario decide no modificar la cita
	//¡No modificar el fichero de las citas!//
  void consultarCitas(Paciente &p);
	bool modificarTratamiento(Tratamiento &t);
	//Abre el menu de modificación del tratamiento y si se elimina el tratamiento pone a -1 paciente_, devuelve false si el usuario decide no modificar el tratamiento
	//¡No modificar el fichero de tratamientos!//
	void consultarTramientos(Paciente &p);						//Muestra los tratamientos que está siguiendo el paciente y da la opción de seleccionar y modificar esos tratamientos
	list<Cita> getCitas(fecha f1,fecha f2);						//Devuelve una lista con las citas de la fecha 1 a la fecha 2
	void anadirCita(Paciente &p);
	void anadirTratamiento(Paciente &p);
	void anadirNota(Paciente &p);
	bool ContieneA(string cad1,string cad2);
	int nuevoID();
	bool Nombre_Apellidos(Paciente p1,Paciente p2);
    bool Apellidos_Nombre(Paciente p1,Paciente p2);
    bool ordenarporFecha(Paciente p1,Paciente p2);
    void consultarAgenda();

#endif
