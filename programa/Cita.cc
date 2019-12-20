#include "Cita.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>
#include <list>
#include <fstream>
list<Cita> getCitas(fecha f1,fecha f2);

void Cita::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo

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
	printf("Yuju, soy una cita y estoy mostrandome :D\n");
}
bool Cita::modificable(){
	bool modificable_=true;
	if(modificable_){
		return true;
	}
	else if(dias(fecha_,HOY)<=1){			//---------------
		return true;
	}
	else{
		return false;
	}
}
bool Cita::borrar(){
	printf("Me estoy borrando\n");
	return false;
}
bool Cita::addCita(){
	bool insertado=false;
	list<Cita> lista;
	list<Cita>::iterator i;
	fecha f1,f2;
	f1=fecha_;
	f2=fecha_;
	f1.d=0;
	f2.d=32;
	lista=getCitas(f1,f2);
	fstream file;
	for(i=lista.begin();((i!=lista.end())&&(!insertado));i++){

		if(fecha_<(*i).getFecha()){			//Si la fecha de la cita es anterior no hace nada
		}
		else if((*i).getFecha()<fecha_){		//Si es posterior se guarda antes
			lista.insert(i,*this);
			insertado=true;
		}
		else{								//Si son iguales se comprueba la hora
			if(minutos(hora_,(*i).getHora())>0){
				lista.insert(i,*this);
				insertado=true;
			}
		}
	}
	if(insertado==false){
		lista.push_back(*this);
	}
	file.open("Agenda/"+to_string(fecha_.m)+"/"+to_string(fecha_.a)+".txt",ios::out|ios::trunc);
	for(i=lista.begin();((i!=lista.end())&&(!insertado));i++){

		file<<(*i).getID()<<"|"<<escribeFecha((*i).getFecha())<<"|"<<escribeHora((*i).getHora())<<(*i).getComentario()<<endl;
	}
	file.close();
}