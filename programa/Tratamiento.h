#ifndef TRATAMIENTO_H
	#define TRATAMIENTO_H
	#include "Registro.h"
	class Tratamiento:public Registro{
	private:
		string medicamento_;
		string concentracion_;
		string regularidad_;
		fecha inicio_;
		fecha final_;
		int estado_;			//Sin concluir 0,finalizado con exito 1, concluido -1
		string comentario_;
	public:
		Tratamiento(int paciente);					//Constructor
		void mostrarRegistro() override;		//Muestra por pantalla los datos del tratamiento
		bool modificable() override;
		bool borrar() override;
		inline string getMedicamento()const{
			return medicamento_;
		}
		inline void setMedicamento(const string med){
			medicamento_=med;
		}
		inline string getConcentracion()const{
			return concentracion_;
		}
		inline void setConcentracion(const string con){
			concentracion_=con;
		}
		inline string getRegularidad()const{
			return regularidad_;
		}
		inline void setRegularidad(const string reg){
			regularidad_=reg;
		}
		inline fecha getFechaInicio()const{
			return inicio_;
		}
		inline void setFechaInicio(const fecha f){
			inicio_=f;
		}
		inline fecha getFechaFinal()const{
			return final_;
		}
		inline void setFechaFinal(const fecha f){
			final_=f;
		}
		inline int getEstado()const{
			return estado_;
		}
		inline void setEstado(const int n){		//Me fio de que no vais a introcudir ningun numero extraño
			estado_=n;
		}
		inline string getComentario()const{
			return comentario_;
		}
		inline void setComentario(const string cad){
			comentario_=cad;
		}
		//-Tratamiento();				//Destructor
	};
#endif