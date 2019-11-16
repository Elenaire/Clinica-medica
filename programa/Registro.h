#ifndef REGISTRO_H
	#define REGISTRO_H
	#include "funciones.h"
	using namespace std;
	class Registro{
		static bool modificable_;
	protected:
		struct fecha fecha_;	//Fecha de creación
		struct hora hora_;		//Hora de creación
		int paciente_;			//id del paciente del registro
		public:
		Registro(int paciente){				//Constructor
			paciente_=paciente;
			hoy(fecha_);
			hoy(hora_);
		}
		virtual void mostrarRegistro();
		virtual bool modificable(); //Devuelve true si el registro puede modificarse y false si no puede
		virtual bool borrar();		//Borra el registro del historial
	}
#endif
