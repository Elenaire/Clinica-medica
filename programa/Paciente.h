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
	public:
		Paciente();				//Constructor  (Tengo que mirar si se pueden hacer 2 constructores, uno pasandole los datos y solo con la id y que lo lea de un fichero)

		// get y set
		getCitas();
		getTratamientos();
		getNotas();
		mostrarPaciente();		//Muestra por pantalla los datos del paciente
		mostrarTratamientos ();		// Muestra los tratamientos actuales
		mostrarHCitas ();		// Muestra el historial de citas
		mostrarHTratamientos ();	// Muestra el historial de tratamientos
		mostrarHNotas ();		// Muestra el historial de notas
		mostrarHistorial ();		// Muestra el historial de citas, estudios y notas ordenadas por fecha sin distinguir el tipo
		addCita();
		addTratamiento();
		addNota();
		guardarPaciente();		//Añade o modifica al paciente en el fichero de pacientes
		borrarPaciente();		//Elimina al paciente del fichero de pacientes y elimina todos sus datos
		-Paciente();			//Destructor
	}
#endif
