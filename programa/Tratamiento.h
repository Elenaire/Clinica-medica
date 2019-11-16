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
		Tratamiento(int paciente);					//Constructor
		void mostrarRegistro() override;		//Muestra por pantalla los datos del tratamiento
		bool modificable() override;
		bool borrar() override;
		inline void setMedicamento(const string med){
			medicamento_=med;
		}
		inline void setConcentracion(const sting con){
			concentracion_=con;
		}
		inline void setRegularidad(const string reg){
			regularidad_=reg;
		}
		inline struct fecha getFechaInicio()const{
			return inicio_;
		}
		inline void setFechaInicio(const struct fecha f){
			inicio_=f;
		}
		inline struct fecha getFechaFinal()const{
			return final_;
		}
		inline setFechaFinal(const struct fecha f){
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
		inline setFechaFinal(const string cad){
			comentario_=cad;
		}
		//-Tratamiento();				//Destructor
	}
#endif