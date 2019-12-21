#include "Nota.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>
#include <iostream>

void Nota::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo
	cout<<endl<<contenido_<<endl;
}
bool Nota::modificable(){
	bool modificable_=false;
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