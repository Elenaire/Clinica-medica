#ifndef NOTA_H
	#define NOTA_H
	#include "Registro.h"
	using namespace std;
	class Nota:public Registro{
	private:
		string contenido_;
	public:
		Nota(int paciente):Registro(paciente){				//Constructor
			contenido_="";
		}
		inline string getContenido()const{
			return contenido_;
		}
		inline void setContenido(const string cad){
			contenido_=cad;
		}
		void mostrarRegistro() override;			//Muestra por pantalla los datos del tratamiento
		bool modificable() override;
		bool borrar() override;
		void modificarNota()
		//-Nota();				//Destructor
	};
#endif
