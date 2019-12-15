#ifndef REGISTRO_H
	#define REGISTRO_H
	#include "fecha_hora.h"
	#include <string>
	class Registro{
	protected:
		int id_;
		struct fecha fecha_;	//Fecha de creación
		struct hora hora_;		//Hora de creación
		int paciente_;			//id del paciente del registro
	public:
	static bool modificable_;
	Registro(int paciente){				//Constructor
		paciente_=paciente;
		hoy(fecha_);
		hoy(hora_);
	}
	inline struct fecha getFecha()const{
			return fecha_;
		}
	inline hora getHora()const{
			return hora_;
		}
	virtual void mostrarRegistro();
	virtual bool modificable(); //Devuelve true si el registro puede modificarse y false si no puede
	virtual bool borrar();		//Borra el registro del historial
	};
#endif

