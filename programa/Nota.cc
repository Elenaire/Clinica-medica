#include "Nota.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>
#include <iostream>

void Nota::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo
	cout<<endl<<contenido_<<endl;
}
bool Nota::modificable(){
	if(Registro::modificable_){
		return true;
	}
	else if(dias(fecha_,HOY)<3){			//---------------
		return true;
	}
	else{
		return false;
	}
}

void Nota::modificarNota()
{
	cout<<"Introduzca el nuevo contenido de la nota"<<endl;
	string content;
	cin>>content;
	contenido_=content;
	cout<<"El nuevo contenido de la nota es: "<<contenido_<<endl;
}
