#include "Nota.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>

void Nota::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo

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
	printf("Yuju, soy una nota y estoy mostrandome :D\n");
}
bool Nota::modificable(){
	bool modificable_=true;
	if(modificable_){
		return true;
	}
	else if(dias(fecha_,HOY)<3){			//---------------
		return true;
	}
	else{
		return false;
	}
}
bool Nota::borrar(){
	printf("Me estoy borrando\n");
	return false;
}