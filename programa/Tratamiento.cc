#include "Tratamiento.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>


Tratamiento::Tratamiento(int paciente):Registro(paciente){				//Constructor
	medicamento_="";
	comentario_="";
	regularidad_="";
	estado_=0;
	comentario_="";
}

void Tratamiento::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo


/*	cout<<"Tratamento de "<<medicamento_<<ennl<<"Concentración de "<<concentracion_<<endl<<"Con regularidad "<<regularidad_<<end;
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
	cout<<comentario_;*/
	printf("Yuju, soy un tratamiento y estoy mostrandome :D\n");
}
bool Tratamiento::modificable(){
	if(modificable_){
		return modificable_;
	}
	else if((estado_==0)||(dias(final_,HOY)<3)){			//---------------
		return true;
	}
	else{
		return false;
	}
}
bool Tratamiento::borrar(){
	printf("Me estoy borrando\n");
	return false;
}