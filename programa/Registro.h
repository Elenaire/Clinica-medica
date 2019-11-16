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
		Registro();				//Constructor
	/*	{
			time_t t=time(0);
			tm *fecha=localtime(&t);
			fecha_->a=fecha->tm_year;
			fecha_->m=fecha->tm_mon;
			fecha_->d=fecha->tm_mday;
			hora_->h=fecha->tm_hour;
			hora_->m=fecha->tm_min;
			hora_->s=fecha->tm_sec;
		}*/
		virtual void mostrarRegistro();
		virtual bool modificable(); //Devuelve true si el registro puede modificarse y false si no puede
		virtual bool borrar();		//Borra el registro del historial
	}
#endif

