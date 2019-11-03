#ifndef PACIENTE_H
	#define PACIENTE_H
	#include <string>
	#include <list>
	#include "Fecha.h"
	#include "Cita.h"
	#include "Tratamiento.h"
	#include "Nota.h"
	class Paciente{
	private:
		int id_;				//Numero para poder seleccionar al paciente cuando se está buscando
		string nombre_;
		string apellidos_;
		string direccion_;
		struct fecha fechanacimiento_;
		int telefono_;
		int codpostal_;
		int tipo_;				//Publico 0, Privado 1, otro posible tipo otro numero
		list <tratamiento> tratamientos_;
		list <nota> notas_;
	public:
		Paciente();				//Constructor  (Tengo que mirar si se pueden hacer 2 constructores, uno pasandole los daots y solo con la id y que lo lea de un fichero)

		// get y set			//Incluidos cita, nota y tratamiento 

		cargarCitas();
		addTratamiento();
		addCita();
		mostrarPaciente();		//Muestra por pantalla los datos del paciente
		mostrarHCitas();		//Muestra el historial de citas
		mostrarTratamientos();	//Muestra los tratamientos historial o actuales
		mostrarHNotas();		//Muestra el historial de notas
		mostrarHistorial();		//Muestra el historial de citas,tratamientos y notas ordenado por fecha sin distinguir el tipo
		guardarPaciente();		//Añade o modifica al paciente en el fichero de pacientes
		cargarTratamientos();
		cargarNotas();
		cargarCitas();
		addTratamiento();
		addCita();
		addNota();
		borrarPaciente();		//Elimina al paciente del fichero de pacientes y elimina todos sus datos
		-Paciente();			//Destructor
	}
#endif