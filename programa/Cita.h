#ifndef CITA_H
	#define CITA_H
	#include "Registro.h"			//Contiene struct fecha y struct hora
	using namespace std;
	class Cita: public Registro{	
	private:
		string comentario_;
	public:
		Cita(int paciente):Registro(paciente){				//Constructor
			comentario_="";
		}
		inline string getComentario()const{
			return comentario_;
		}
		inline void setComentario(const string cad){
			comentario_=cad;
		}
		bool addCita();
		void mostrarRegistro() override;			//Muestra por pantalla los datos del tratamiento
		bool modificable() override;
		bool borrar() override;
	};
#endif