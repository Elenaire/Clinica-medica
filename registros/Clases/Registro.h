#ifndef REGISTRO_H
	#define REGISTRO_H
	#include <string>
	#include "fecha"			//Contiene struct fecha y struct hora
	class Registro{
		static bool modificable_;
	protected:
		struct fecha fecha_;	//Fecha de creación
		struct hora hora_;		//Hora de creación
		int paciente_;			//id del paciente del registro
		public:
		Registro();					//Constructor
		virtual void mostrarRegistro();
		virtual bool modificable(); //Devuelve true si el registro puede modificarse y false si no puede
		virtual void borrar();		//Borra el registro del historial
	}
#endif

