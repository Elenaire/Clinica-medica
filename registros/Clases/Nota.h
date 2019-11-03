#ifndef NOTA_H
	#define NOTA_H
	#include <string>
	#include "fecha"			//Contiene struct fecha y struct hora
	class Nota{					//Hereda de otra clase
	private:
		int id_;				//Numero para poder seleccionar la nota
		struct fecha fecha_;
		struct hora hora_;
		strict contenido_;
		bool modificable_;
	public:
		Nota();					//Constructor

		// get y set

		mostrarNota();			//Muestra por pantalla los datos de la nota
		borrarNota();			//Elimina la nota dle historial
		-Nota();				//Destructor
	}
#endif