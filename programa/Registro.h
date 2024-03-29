#ifndef REGISTRO_H
	#define REGISTRO_H
	#include "fecha_hora.h"
	#include <string>
	class Registro{
	protected:
		struct fecha fecha_;	//Fecha de creación
		struct hora hora_;		//Hora de creación
		int paciente_;			//id del paciente del registro
	public:
	int id_;
	static bool modificable_;
	Registro(int paciente){				//Constructor
		paciente_=paciente;
		hoy(fecha_);
		hoy(hora_);
	}
	inline int getID()const{
		return paciente_;
	}
	inline void setID(const int id){
		paciente_=id;
	}
	inline void setFecha(const fecha f){
		fecha_=f;
	}
	inline void setHora(const hora h){
		hora_=h;
	}
	inline struct fecha getFecha()const{
			return fecha_;
		}
	inline hora getHora()const{
			return hora_;
		}
	virtual void mostrarRegistro()=0;
	virtual bool modificable()=0; //Devuelve true si el registro puede modificarse y false si no puede
	};
	//bool Registro::modificable_=false;
#endif