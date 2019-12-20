#include "fecha_hora.h"
#include "funciones.h"
#include "Paciente.h"
#include "Registro.h"
#include <iostream>

using namespace std;

bool addCita(Cita c);

void leerPacientes(list<Paciente> &p){
	Paciente aux(0);
	ifstream file;
	file.open("Pacientes.txt");
	fecha f;
	char fech[32];
	string cad;
	while(!file.eof()){
	    getline(file,cad,'|');
	    aux.setID(stoi(cad));
	    getline(file,cad,'|');
	    aux.setNombre(cad);
	    getline(file,cad,'|');
	    aux.setApellidos(cad);
	    file.getline(fech,32,'|');		//Fecha....
	    sscanf(fech,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
	    aux.setFechanacimiento(f);
	    getline(file,cad,'|');
	    if(cad.size()>1){
	    	aux.setTelefono(stoi(cad));
	    }
	    else{
	    	aux.setTelefono(-1);
		}
		getline(file,cad,'|');
	    if(cad.size()>1){
	    	aux.setCodPostal(stoi(cad));
	    }
	    else{
	    	aux.setCodPostal(-1);
		}
		getline(file,cad,'|');
	    aux.setDireccion(cad);
	    getline(file,cad,'\n');
	    aux.setTipo(stoi(cad));
	    p.push_back(aux);
	}
	file.close();
}
void mostrarPacientes(list<Paciente> &p){					//Sin probar
	list<Paciente>::iterator i;
	for(i=p.begin();i!=p.end();++i){
		(*i).mostrarPaciente();
	}
}
bool filtrarPacientes(int filtro,list<Paciente> &p){			//Sin probar
	if((p.empty())||(filtro==0)){
		leerPacientes(p);
	}
	//Aqui habia un else
		string aux;
		string aux2;
		fecha f;
		int n;
		list<Paciente> lista;
		list<Paciente>::iterator i;
		bool bucle=false;
		switch(filtro){					//Compare no funcona
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
			cout<<"Escribe:"<<endl;
				getline(cin,aux);						//No lee
				getline(cin,aux);
				printf("despues de escribir\n");
				for(i=p.begin();i!=p.end();++i){
					if(0<=aux.compare((*i).getNombre())){
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
		printf("Salir de swtch\n");
		return true;
}

void ordenarPacientes(int parametro,list<Paciente> &p){		//Sin terminar  --Quiero probarlo
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
bool modificarTratamiento(Tratamiento &t){		//¿Tiene que ser bool?		//Sin terminar  ----------------------------------------
	if(t.modificable()){
		char c;
		string aux;
		fecha f1,f2;
		printf("Aqui pregunta que modificar y bla bla bla\n");
		int menu=0;
		while(menu>=0){
			t.mostrarRegistro();
			/*
			bla bla menu
			*/
			switch(menu){
				case 0:
					printf("1 Finalizar tratamiento\n2 Moficicar tratamiento\n3 Modificar fechas de inicio y finalización\n4 Modificar comentario\n-1 Atras");
					cin>>menu;
				break;
				case 1:		//Finalizar tratamiento
					printf("Hacer esto significa que el tratamiento no ha finalizado correctamente.\n¿Desea continuar?(s/n)\n");
					cin>>c;
					if(c=='s'){
						t.setEstado(-1);
					}
				break;
				case 2:	//Moficicar tratamiento
					printf("Medicamento: ");
					getline(cin,aux);
					t.setMedicamento(aux);
					printf("Concentración: ");
					getline(cin,aux);
					t.setConcentracion(aux);
					printf("Regularidad: ");
					getline(cin,aux);
					t.setRegularidad(aux);
				break;
				case 3:	//Modificar fechas de inicio y finalización
					printf("Hola\n");
				default:
					if(menu>0){
						printf("Error, introduzca:\n");
						menu=0;
					}
				}
		}


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
	for(t=tratamientos.begin();t!=tratamientos.end();t++){
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

/*
list<Cita> getCitas(fecha f1,fecha f2){		//Tienen que ser fechas validas
	list<Cita> C;
	Cita aux(0);
	fecha i,f;
	hora h;
	ifstream file;
	char cad[16];
	string comentario;
	bool bucle=true;
	if(dias(f1,f2)>=0){
		i.a=f1.a;
		i.m=f1.m;
		i.d=0;
		while(i<f2){
			file.open("Agenda/"+to_string(i.m)+"/"+to_string(i.a)+".txt");
			while((!file.eof())&&(bucle)){
				file.getline(cad,16,'|');		
	    		aux.setID(atoi(cad));
				file.getline(cad,16,'|');		
	    		sscanf(cad,"%2d/%2d/%4d",&f.d,&f.m,&f.a);
	    		file.getline(cad,16,'|');		
	    		sscanf(cad,"%2d:%2d",&h.h,&h.m);
	    		getline(file,comentario,'\n');
	    		aux.setFecha(f);
	    		aux.setHora(h);
	    		aux.setComentario(comentario);
				if(f2<aux.getFecha()){
					bucle=false;
				}
				else{
					C.push_back(aux);
				}
			}
			file.close();
			i.m=i.m+1;				//Siguiente fichero
			if(i.m>12){
				i.m=1;
				i.a=i.a+1;
			}
		}
	}
	else{
		printf("Intervalo no valido\n");
	}
	return C;
}

void anadirCita(Paciente &p){				//---------------------------------------------
	Cita C(p.getID());
	char c;
	list<Cita> agenda;
	list<Cita>::iterator i;
	bool bucle=true;
	string aux;
	fecha f;
	hora h;
	printf("Día:");
	while(bucle){
		if(leerFecha(f)!=true){
		printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
		}
		else if(dias(HOY,f)<0||Resgistro::modificable_==false){			//Modificable_
		printf("Ese día ya ha pasado\n");
		}
		else{
			bucle=false;
		}
	}
	bucle=true;
	printf("Hora:");
	while(bucle){
		if(leerHora(h)!=true){
		printf("Formato de hora incorrecto, introduzca hh:mm\n");
		}
		else {
			agenda=getCitas(f,f);
			bucle=false;
			for(i=agenda.begin();((i!=agenda.end())&&(!bucle));i++){
				if(abs(minutos(h,(*i).getHora()))<5){
					printf("Ya tiene una cita a esa hora:\n");
					(*i).mostrarRegistro();
					bucle=true;
				}
			}
		}
	}
	printf("Introduzca un comentario(opcional): ");
	cin>>aux;
	C.setFecha(f);
	C.setHora(h);
	C.setComentario(aux);			//Termina de pedir datos
	printf("¿Desea guardar la cita? s/n\n");		//Pide confirmación (Si no confirma se sale)
	cin>>c;
	if(c=='s'){
		if(addCita(C)){													//No esta hecho------------------
			printf("Cita guardada correctamente\n");
		}
		else{
			printf("Ha ocurrido un error inesperado\n");
		}
	}
}
*/
void anadirTratamiento(Paciente &p){
	bool modificable_=false;
	Tratamiento t(p.getID());
	char c;
	bool bucle=true;
	string aux;
	fecha f1,f2;
	getline(cin,aux);
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
			else if(dias(HOY,f1)<0||modificable_==false){			//Modificable_
			printf("Esa fecha ya ha pasado\n");
		}
		else{
			bucle=false;
		}
		printf("Dias desde:%d\n",dias(HOY,f1));
	}
	printf("Fecha de finalización: ");
	bucle=true;
	while(bucle){
		if(leerFecha(f2)!=true){
			printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			else if(dias(f1,f2)<0){
				printf("El tratamiento no puede finalizar antes de empezar\n");
				printf("Dias desde:%d\n",dias(f1,f2));
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

/*
bool addCita(Cita c){
	bool insertado=false;
	list<Cita> lista;
	list<Cita>::iterator i;
	fecha f1,f2;
	f1=c.getFecha();
	f2=f1;
	f1.d=0;
	f2.d=32;
	lista=getCitas(f1,f2);
	fstream file;
	for(i=lista.begin();((i!=lista.end())&&(!insertado));i++){

		if(c.getFecha()<(*i).getFecha()){			//Si la fecha de la cita es anterior no hace nada
		}
		else if((*i).getFecha()<c.getFecha()){		//Si es posterior se guarda antes
			lista.insert(i,c);
			insertado=true;
		}
		else{								//Si son iguales se comprueba la hora
			if(minutos(c.getHora(),(*i).getHora())>0){
				lista.insert(i,c);
				insertado=true;
			}
		}
	}
	if(insertado==false){
		lista.push_back(c);
	}
	file.open("Agenda/"+to_string((c.getFecha()).m)+"/"+to_string((c.getFecha()).a)+".txt",ios::out|ios::trunc);
	for(i=lista.begin();((i!=lista.end())&&(!insertado));i++){

		file<<(*i).getID()<<"|"<<escribeFecha((*i).getFecha())<<"|"<<escribeHora((*i).getHora())<<(*i).getComentario()<<endl;
	}
	file.close();
}
*/
/*
bool ContieneA(char* cad1,char* cad2)
{
	int n=strlen(cad1);
	int cont=0;
	for (int i = 0; i < n; i++) {
		if(cad1[i]==cad2[i])
		{
			cont++;
		}
	}
	if(cont==n)
	{
		return true;
	}else{
		return false;
	}
}
*/
