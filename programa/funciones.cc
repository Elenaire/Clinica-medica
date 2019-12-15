#include "fecha_hora.h"
#include "funciones.h"
#include "Paciente.h"
#include "Registro.h"
#include <iostream>

using namespace std;

list<Paciente> leerPacientes(){
	Paciente aux(0);
	list<Paciente> p;
	list<Paciente>::iterator i;
	ifstream file;
	file.open("Pacientes.txt");
	fecha f;
	char cad[256];
	for(i=p.begin();i!=p.end();i++){
	    file.getline(cad,32,'|');
	    aux.setID(stoi(cad));
	    file.getline(cad,64,'|');
	    aux.setNombre(cad);
	    file.getline(cad,64,'|');
	    aux.setApellidos(cad);
	    file.getline(cad,64,'|');		//Fecha....
	    sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
	    aux.setFechanacimiento(f);
	    file.getline(cad,64,'|');
	    aux.setTelefono(stoi(cad));
	    file.getline(cad,64,'|');
	    aux.setCodPostal(stoi(cad));
	    file.getline(cad,64,'\n');
	    aux.setTipo(stoi(cad));
	    p.push_back(aux);
	}
	file.close();;
	return p;
}
void mostrarPacientes(list<Paciente> &p){					//Sin probar
	list<Paciente>::iterator i;
	for(i=p.begin();i!=p.end();++i){
		(*i).mostrarPaciente();
	}
}
bool filtrarPacientes(int filtro,list<Paciente> p){			//Sin probar
	if((p.empty())||(filtro==0)){
		p=leerPacientes();
	}
	else{
		string aux;
		string aux2;
		fecha f;
		int n;
		list<Paciente> lista;
		list<Paciente>::iterator i;
		bool bucle=false;
		switch(filtro){
			case 0:
				return true;
			break;
			case 1:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){		//Podria no leer el ultimo paciente
					aux2=(*i).getNombre()+(*i).getApellidos();
					if(aux.compare(aux2)){				//Si en aux se encuentra aux2 es positivo, si no coincide algun caracter es negativo
						lista.push_back(*i);
					}
				}
			break;
			case 2:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare((*i).getNombre())){
						lista.push_back(*i);
					}
				}
			break;
			case 3:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare((*i).getApellidos())){
						lista.push_back(*i);
					}
				}
			break;
			case 4:	
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->getEdad()){
						lista.push_back(*i);
					}
				}
			break;
			case 5:
				do{
					if(leerFecha(f)==false){
						printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
					}
					else{bucle=true;}
				}while (!bucle);
				for(i=p.begin();i!=p.end();++i){
					if(f==i->getFechanacimiento()){
						lista.push_back(*i);
					}
				}
			break;
			case 6:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare(i->getDireccion())){
						lista.push_back(*i);
					}
				}
			break;
			case 7:
			scanf("%d",&n);
			for(i=p.begin();i!=p.end();++i){
				if(n==i->getCodPostal()){
					lista.push_back(*i);
				}
			}
			break;
			case 8:
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->getTelefono()){
						lista.push_back(*i);
					}
				}
			break;
			case 9:
			for(i=p.begin();i!=p.end();++i){
				if(i->getTipo()==0){
					lista.push_back(*i);
				}
			}
			break;
			case 10:
			for(i=p.begin();i!=p.end();++i){
				if(i->getTipo()==1){
					lista.push_back(*i);
				}
			}
			break;
			default:
					printf("Error, introduzca un numero valido\n");
					return false;
		}
		if(lista.empty()){
			printf("Error, ningun paciente corresponde con su busqueda\n");
			return false;
		}
		else{
			p=lista;
		}
		return true;
	}
}

void ordenarPacientes(int parametro,list<Paciente> p){		//Sin terminar  --Quiero probarlo
	printf("Estoy ordenand pacientes, si\n");
	/*
	switch(parametro){
		case 1:		//Nombre y apellidos
			p.sort(Nombre_Apellidos);
		break;
		case 2:		//Apellidos y nombre
			p.sort(Apellidos_Nombre);
		break;
		case 3:

		break;
		case 0:		//Ordena por id

		break;
	}*/
}
bool modificarTratamiento(Tratamiento &t){		//¿Tiene que ser bool?		//Sin terminar
	if(t.modificable()){
		printf("Aqui pregunta que modificar y bla bla bla\n");
	}
	else{
		printf("No está permitido modificar este tratamiento\n");
		return false;
	}
}

void consultarTramientos(Paciente &p){
  	int i;
	list <Tratamiento> tratamientos;
	list <Tratamiento>::iterator t;
	tratamientos=p.getTratamientos();		//Modificar getTratamientos
	t=tratamientos.begin();
	while(t!=tratamientos.end()){
		if((*t).getEstado()!=0){
			tratamientos.erase(t);
		}
		else{t++;}
	}
	i=1;
	for(t=tratamientos.begin();t!=tratamientos.end();t++){			//Super mal
		printf("%d.\n",i);
		(*t).mostrarRegistro();
		i++;
	}
	printf("Selecione un tratamiento o introduzca 0:");
	cin>>i;
	if(i>0){
		if(i<=(tratamientos.size()+1)){
			modificarTratamiento(*t);			//Sin terminar		//Mal
		}
	}
}
void anadirTratamiento(Paciente &p){
	Tratamiento t(p.getID());
	char c;
	bool bucle=true;
	string aux;
	fecha f,f1,f2;
	hoy(f);
	printf("Medicamento: ");		//Empieza a pedir datos
	getline(cin,aux);
	t.setMedicamento(aux);
	printf("Concentración: ");
	getline(cin,aux);
	t.setConcentracion(aux);
	printf("Regularidad: ");
	getline(cin,aux);
	t.setRegularidad(aux);
	while(bucle){
		printf("Fecha de inicio: ");
		while(bucle){
			if(leerFecha(f1)!=true){
			printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			else if(dias(f,f1)<0||Registro::modificable_==false){			//Modificable_
			printf("Esa fecha ya ha pasado\n");
		}
		else{
			bucle=false;
		}
	}
	printf("Fecha de finalización: ");
	bucle=true;
	while(bucle){
		if(leerFecha(f2)!=true){
			printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			else if(dias(f1,f2)){
				printf("El tratamiento no puede finalizar antes de empezar\n");
			}
			else{
				bucle=false;
			}
		}
	}
	t.setFechaInicio(f1);
	t.setFechaFinal(f2);
	printf("Introduzca un comentario(opcional): ");
	cin>>aux;
	t.setComentario(aux);			//Termina de pedir datos
	printf("¿Desea guardar el tratamiento? s/n\n");		//Pide confirmación (Si no confirma se sale)---------
	cin>>c;
	if(c=='s'){
		if(p.addTratamiento(t)){
			printf("Tratamiento guardado correctamente\n");
		}
		else{
			printf("Ha ocurrido un error inesperado\n");
		}
	}
}