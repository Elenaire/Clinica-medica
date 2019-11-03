#ifndef CITA_H
	#define CITA_H
	#include <string>
	#include "fecha"			//Contiene struct fecha y struct hora
	class Cita{					//Hereda de otra clase
	private:
		int id_;				//Numero para poder seleccionar la cita
		struct fecha fecha_;
		struct hora hora_;
		int paciente_;			//id del paciente con el que se tiene la cita
		strict comentario_;
	public:
		Cita();					//Constructor

		// get y set

		mostrarCita();			//Muestra por pantalla los datos de la cita
		borrarCita();			//Elimina la cita de la agenda
		-Cita();				//Destructor
	}
#endif