#include "Tratamiento.h"

		Tratamiento::Tratamiento(){}				//Constructor


	private:
		string medicamento_;
		string concentracion_;
		string regularidad_;
		struct fecha inicio_;
		struct fecha final_;
		int estado_;			//Sin concluir 0,finalizado con exito 1, concluido -1
		strict comentario_;



		void Tratamiento::mostrarRegistro() override{
			cout<<"Tratamento de "<<medicamento_<<ennl<<"Concentración de "<<concentracion_<<endl<<"Con regularidad "<<regularidad_<<end;
			printf("Iniciado el %d/%d/%d ",inicio_.d,inicio_.m,inicio_.a);
			switch(estado_){
				case -1:
					printf("y cancelado el dia %d/%d/%d\n",final_.d,final_.m,final_.a);
					break;
				case 0:
					printf("y con previsión de finalizarse el %d/%d/%d\n",final_.d,final_.m,final_.a);
				break;
				default:
					printf("y finalizado el dia %d/%d/%d\n",final_.d,final_.m,final_.a);
			}
			cout<<comentario_;
		}
		bool modificable() override{
			if(modificable_){
				return modificable_
			}
			else if(){
			}
		}
		bool borrar() override;