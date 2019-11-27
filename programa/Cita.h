#ifndef CITA_H
	#define CITA_H
	#include "Registro.h"			//Contiene struct fecha y struct hora
	class Cita:public Registro{	
	private:
		string comentario_;
	public:
		Cita();					//Constructor

		// get y set

		void mostrarRegistro() override;			//Muestra por pantalla los datos de la cita
		bool modificable() override;
		bool borrar() override;
		//-Cita();				//Destructor
	};
#endif