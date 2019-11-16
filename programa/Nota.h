#ifndef NOTA_H
	#define NOTA_H
	#include "Registro.h"
	class Nota:public Registro{
	private:
		string contenido_;
	public:
		Nota();					//Constructor

		// get y set

		void mostrarRegistro() override;			//Muestra por pantalla los datos de la nota
		bool modificable() override;
		bool borrar() override;
		-Nota();				//Destructor
	}
#endif