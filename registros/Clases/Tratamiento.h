#ifndef TRATAMIENTO_H
	#define TRATAMIENTO_H
	#include <string>
	#include "fecha"
	class Tratamiento{			//Hereda de otra clase
	private:
		int id_;				//Numero para poder seleccionar el tratamiento
		string medicamento_;
		string concentracion_;
		string regularidad_;
		struct fecha inicio_;
		struct fecha final_;
		int estado_;			//Sin concluir 0,finalizado con exito 1, concluido -1
		strict comentario_;
		bool modificable_;
	public:
		Tratamiento();					//Constructor

		// get y set

		mostrarTratamiento();		//Muestra por pantalla los datos del tratamiento
		borrarTratamiento();
		-Tratamiento();				//Destructor
	}
#endif