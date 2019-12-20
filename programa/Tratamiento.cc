#include "Tratamiento.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>
#include <iostream>
using namespace std;
void Tratamiento::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo
	cout<<"Tratamento: "<<medicamento_<<endl<<"Concentración: "<<concentracion_<<endl<<"Regularidad: "<<regularidad_<<endl;
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
	cout<<comentario_<<endl;

}
bool Tratamiento::modificable(){
	bool modificable_=false;
	if(modificable_){
		return true;
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