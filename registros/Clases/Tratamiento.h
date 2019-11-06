#ifndef TRATAMIENTO_H
	#define TRATAMIENTO_H
	#include "Registro.h"
	class Tratamiento:public Registro{
	private:
		string medicamento_;
		string concentracion_;
		string regularidad_;
		struct fecha inicio_;
		struct fecha final_;
		int estado_;			//Sin concluir 0,finalizado con exito 1, concluido -1
		strict comentario_;
	public:
		Tratamiento();					//Constructor

		// get y set

		void mostrarRegistro() override;		//Muestra por pantalla los datos del tratamiento
		bool modificable() override;
		borrarTratamiento();
		-Tratamiento();				//Destructor
	}
#endif