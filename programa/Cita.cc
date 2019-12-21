#include "Cita.h"
#include "funciones.h"
#include "fecha_hora.h"
#include <cstdio>
#include <list>
#include <fstream>
#include <iostream>
list<Cita> getCitas(fecha f1,fecha f2);

void Cita::mostrarRegistro(){		//Comprobar el estado del tratamiento y la fecha de finalización y si deberia haber finalizado guardarlo
	//printf("El día: %s a las %s tiene una cita con el paciente %d\n%s\n",escribeFecha(fecha_),escribeHora(hora_),paciente_,comentario_);
	cout<<"El día: "<<escribeFecha(fecha_)<<" a las "<<escribeHora(hora_)<<"tiene una cita con el paciente"<<paciente_<<endl<<comentario_<<endl;
}
bool Cita::modificable(){
	bool modificable_=false;
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
	lista=getCitas(f1,f2);					//Obtengo las citas de todo el mes
	fstream file;
	for(i=lista.begin();((i!=lista.end())&&(!insertado));i++){
		(*i).mostrarRegistro();
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
	file.open("Agenda/"+to_string(fecha_.m)+"_"+to_string(fecha_.a)+".txt",ofstream::out|ofstream::trunc);
	for(i=lista.begin();i!=lista.end();i++){
		file<<(*i).getID()<<"|"<<escribeFecha((*i).getFecha())<<"|"<<escribeHora((*i).getHora())<<"|"<<(*i).getComentario()<<endl;
	}
	file.close();
	return true;
}