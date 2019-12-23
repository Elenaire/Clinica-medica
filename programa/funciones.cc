#include "fecha_hora.h"
#include "funciones.h"
#include "Paciente.h"
#include "Registro.h"
#include "Nota.h"
#include "Cita.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
bool Nombre_Apellidos(Paciente p1,Paciente p2);
bool Apellidos_Nombre(Paciente p1,Paciente p2);


using namespace std;

bool buscarPaciente(Paciente &p){
	int menu,id,orden;
	list<Paciente> pacientes;
	list<Paciente>::iterator i;
	printf("0 Listar pacientes\nBuscar por:\n1 Nombre completo\n2 Nombre\n3 Apellidos\n4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Telefono\n9 Pacientes públicos\n10 Pacientes privados\n-1 Salir\n");
	scanf("%d",&menu);
	if(menu>=0){
		filtrarPacientes(menu,pacientes);
		if(pacientes.empty()){
			printf("No se han encontrado pacientes\n");
			menu=-1;
			sleep(1);
		}
	}
	while(menu>=0){				//se sale con -1 o con negativo?
		system("clear");
		mostrarPacientes(pacientes);
		printf("1 Seleccionar paciente\n2 Ordenar pacientes\n3 Filtra pacientes\n-1 Salir\n");
		scanf("%d",&menu);
		switch(menu){
			case 1:			//Seleccionar paciente
				printf("Introduzca el id del paciente\n");
				scanf("%d",&id);
				for(i=pacientes.begin();i!=pacientes.end();++i){
					if((*i).getID()==id){
						p=*i;
						return true;
					}
				}
				printf("El paciente seleccionado no coincide con los que se muestran por pantalla\n");
				sleep(1);
				menu=0;
			break;
			case 2:			//Ordenar pacientes
				printf("Ordenar por:\n1 Nombre\n2 Apellidos\n3 Fecha de nacimiento");
				scanf("%d",&menu);
				if(menu>0){
					printf("¿Orden ascendente(1) o descendente(-1)? \n");  	//Ordena si es positivo ascendente, si es negativo descendente y si es 0 cancela
					scanf("%d",&orden);
					if(orden!=0){
						ordenarPacientes(menu,pacientes);
						if(orden<0){pacientes.reverse();}
					}
				}
			break;
			case 3:			//Filtrar pacientes
				do{
					printf("0 Reiniciar busqueda\n1 Nombre completo\n2 Nombre\n3 Apellidos\n4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Telefono\n9 Pacientes públicos\n10 Pacientes privados\n-1 Salir\n");
					scanf("%d",&menu);

				}while((menu>=0)&&(!filtrarPacientes(menu,pacientes)));
			break;
			default:
				if(menu>0){
					printf("Error, introduzca:\n");
					menu=0;
				}
		}
	}
	return false;
}

void AgregaP()
{
	Paciente p;
	fecha f;
	string aux;
	int n;
	bool bucle=true;
	getline(cin,aux);
	cout<<"Introdzuca nombre del paciente"<<endl;
	getline(cin,aux);
	p.setNombre(aux);
	cout<<"Introdzuca apellidos del paciente"<<endl;
	getline(cin,aux);
	p.setApellidos(aux);
	cout<<"Introdzuca la fecha de nacimiento del paciente"<<endl;
	while(bucle){
		if(leerFecha(f)!=true){
			printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
		}
		else if(dias(f,HOY)<0){
			printf("Esa fecha aun no ha pasado\n");
		}
		else{
			bucle=false;
		}
	}
	p.setFechanacimiento(f);
	cout<<"Introdzuca el telefono del paciente"<<endl;
	getline(cin,aux);
	getline(cin,aux);
	if(aux.size()>0){
		p.setTelefono(stoi(aux));
	}
	else{
		p.setTelefono(0);
	}
	cout<<"Introdzuca el codigo postal del paciente"<<endl;
	getline(cin,aux);
	if(aux.size()>0){
		p.setCodPostal(stoi(aux));
	}
	else{
		p.setCodPostal(0);
	}
	cout<<"Introdzuca la dirección del paciente"<<endl;
	getline(cin,aux);
	p.setDireccion(aux);
	cout<<"Introdzuca el tipo del paciente(0 Publico/1 Privado)"<<endl;
	cin>>n;
	p.setTipo(n);
	cout<<endl;
	p.mostrarPaciente(1);
	cout<<"¿Está seguro de querer guardar este Paciente? (s/n)"<<endl;
	char elec;
	cin>>elec;
	if(elec=='s')
	{
		p.setID(nuevoID());
		AddPaciente(p);
		aux="mkdir Pacientes/"+to_string(p.getID());
		system(aux.c_str());
	}
}


void menuPaciente(Paciente p){
	int menu=0;
	system("clear");
	while(menu>=0){
		p.mostrarPaciente();
		cout<<endl;
		switch(menu){
			case 0:
				printf("1 Mostrar historial\n2 Recetar tratamiento\n3 Consultar tratamientos\n4 Añadir cita\n5 Modificar datos del paciente\n6 Añadir nota\n7 Eliminar paciente\n-1 Atras\n");
				cin>>menu;
				system("clear");
			break;
			case 1:
			//	p.mostrarHistorial();
				menu=0;
				system("clear");
				break;
			case 2:		//Añadir tratamiento +Hecho  -Funciones
				anadirTratamiento(p);
				menu=0;
				system("clear");
			break;
			case 3:	//Consultar tratamientos
				consultarTramientos(p);
				menu=0;
				system("clear");
			break;
			case 4:	//Añadir cita
				anadirCita(p);
				menu=0;
				system("clear");
			break;
			case 5:	//Modificar datos del paciente
				p.modificarPaciente();
				menu=0;
				system("clear");
			break;
			case 6:
				anadirNota(p);
				menu=0;
				system("clear");
			break;
			case 7:
				p.eliminarPaciente();
				menu=-1;
				system("clear");
			break;
			default:
				if(menu>0){
					printf("Error, introduzca:\n");
					menu=0;
				}
			}
	}
}

void leerPacientes(list<Paciente> &P){
	list<Paciente> p;
	Paciente aux(0);
	ifstream file;
	file.open("Pacientes.txt");
	fecha f;
	char fech[32];
	string cad;
	getline(file,cad,'\n');
	if(file.is_open()){
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
		P=p;
	}
}
void mostrarPacientes(list<Paciente> &p){					//Sin probar
	list<Paciente>::iterator i;
	for(i=p.begin();i!=p.end();++i){
		(*i).mostrarPaciente();
	}
}
bool filtrarPacientes(int filtro,list<Paciente> &p){			//Sin terminar, escribe tal cosa:
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
			case 1:			//Nombre completo
				getline(cin,aux);
				printf("Nombre y Apellidos:\n");
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){		//Podria no leer el ultimo paciente
					aux2=(*i).getNombre()+" "+(*i).getApellidos();
					if(aux2.find(aux)!=string::npos){				//Si en aux se encuentra aux2 es positivo, si no coincide algun caracter es negativo
						lista.push_back(*i);
					}
				}
			break;
			case 2:			//Nombre
				getline(cin,aux);
				printf("Nombre:\n");
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(((*i).getNombre()).find(aux)!=string::npos){
						lista.push_back(*i);
					}
				}
			break;
			case 3:			//Apellidos
				getline(cin,aux);
				printf("Apellidos:\n");
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(((*i).getApellidos()).find(aux)!=string::npos){
						lista.push_back(*i);
					}
				}
			break;
			case 4:			//Edad
				printf("Edad:\n");
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->getEdad()){
						lista.push_back(*i);
					}
				}
			break;
			case 5:			//Fecha de nacimiento
				printf("Fecha de nacimiento:\n");
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
			case 6:			//Dirección
				getline(cin,aux);
				printf("Dirección:\n");
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare(i->getDireccion())){
						lista.push_back(*i);
					}
				}
			break;
			case 7:		//Código postal
				printf("Código postal\n");
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->getCodPostal()){
						lista.push_back(*i);
					}
				}
			break;
			case 8:		//Telefono
				printf("Telefono\n");
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->getTelefono()){
						lista.push_back(*i);
					}
				}
			break;
			case 9:		//Pacientes públicos
			for(i=p.begin();i!=p.end();++i){
				if(i->getTipo()==0){
					lista.push_back(*i);
				}
			}
			break;
			case 10:	//Pacientes privados
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
			sleep(2);
			system("clear");
			return false;
		}
		else{
			p=lista;
		}
		return true;
}

void ordenarPacientes(int parametro,list<Paciente> &p){
	switch(parametro){
		case 1:		//Nombre y apellidos
			p.sort(Nombre_Apellidos);
		break;
		case 2:		//Apellidos y nombre
			p.sort(Apellidos_Nombre);
		break;
		case 3:
			p.sort(ordenarporFecha);
		break;
		case 0:		//Ordena por id

		break;
	}
}
bool modificarCita(Cita &C){		//Sin probar
	if(C.modificable()){
		char c;
		bool bucle=true;
		string aux;
		fecha f;
		hora h;
		list<Cita> agenda;
		list<Cita>::iterator i;
		system("clear");
		int num,menu=0;
		C.mostrarRegistro();
		while(menu<=0){
			if(menu==0){
				printf("1 Modificar fecha\n2 Modificar paciente\n3 Modificar comentario\n4 Eliminar cita\n-1Salir\n");
				cin>>menu;
			}
			if(menu==1){	//Modificar fecha y hora
				while(bucle){
					printf("Día:");
					if(leerFecha(f)!=true){
					printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
					}
					else if(dias(HOY,f)<0&&Registro::modificable_==false){
					printf("Ese día ya ha pasado\n");
					}
					else{
						bucle=false;
					}
				}
				bucle=true;
				while(bucle){
					printf("Hora:");
					if(leerHora(h)!=true){
					printf("Formato de hora incorrecto, introduzca hh:mm\n");
					}
					else {
						agenda=getCitas(f,f);
						bucle=false;
						for(i=agenda.begin();((i!=agenda.end())&&(!bucle));i++){
							num=minutos(h,(*i).getHora());
							if(num<0){
								num=num*-1;
							}
							if(num<5){
								printf("No puede ser a esa hora porque tiene otra cita a las %s\n",escribeHora((*i).getHora()));
								bucle=true;
							}
						}
					}
				}
				C.setFecha(f);
				C.setHora(h);
				printf("¿Desea seguir modificando?(s/n)\n");
				cin>>c;
				if(c!='s'){
					return true;
				}
				menu=0;
			}
			if(menu==2){	//Modificar paciente
				Paciente p;
				if(buscarPaciente(p)){
					C.setID(p.getID());
					printf("¿Desea seguir modificando?(s/n)\n");
					cin>>c;
					if(c!='s'){
						return true;
					}
				}
				menu=0;
			}
			if(menu==3){	//Modificar comentario
				printf("Nuevo comentario:\n");
				getline(cin,aux);
				getline(cin,aux);
				C.setComentario(aux);

				printf("¿Desea seguir modificando?(s/n)\n");
				cin>>c;
				if(c!='s'){
					return true;
				}
				menu=0;
			}
			if(menu==4){
				C.setID(-1);
				return true;
			}
		}
	}
		else{
		printf("No está permitido modificar esta cita\n");
		return false;
	}
	return false;
}




bool modificarTratamiento(Tratamiento &t){
	if(t.modificable()){
		char c;
		bool bucle;
		string aux;
		fecha f1,f2;
		system("clear");
		int menu=0;
		t.mostrarRegistro();
		while(menu>=0){
			switch(menu){
				case 0:
					printf("1 Finalizar tratamiento\n2 Modificar tratamiento\n3 Modificar fechas de inicio y finalización\n4 Modificar comentario\n5 Eliminar tratamiento\n-1 Atras\n");
					cin>>menu;
				break;
				case 1:		//Finalizar tratamiento
					printf("Hacer esto significa que el tratamiento no ha finalizado correctamente.\n¿Desea continuar?(s/n)\n");
					cin>>c;
					if(c=='s'){
						t.setEstado(-1);
					}
					return true;			//Aqui no preguntará si quiere seguir modificando
				break;
				case 2:	//Modificar tratamiento
					printf("Medicamento: ");
					getline(cin,aux);
					getline(cin,aux);
					t.setMedicamento(aux);
					printf("Concentración: ");
					getline(cin,aux);
					t.setConcentracion(aux);
					printf("Regularidad: ");
					getline(cin,aux);
					t.setRegularidad(aux);
					printf("¿Desea seguir modificando?(s/n)\n");
					cin>>c;
					if(c!='s'){
						return true;
					}
					menu=0;
				break;
				case 3:	//Modificar fechas de inicio y finalización
					do{
						bucle=true;
						printf("Fecha de inicio: ");
						while(bucle){
							if(leerFecha(f1)!=true){
							printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
							}
							else if(dias(HOY,f1)<0&&Registro::modificable_==false){			//Modificable_
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
							else{
								bucle=false;
							}
						}
						if(dias(f1,f2)<0){
							printf("El tratamiento no puede finalizar antes de empezar\n");
							bucle=true;
						}
						else{
							bucle=false;
						}
					}while(bucle);
					t.setFechaInicio(f1);
					t.setFechaFinal(f2);
					printf("¿Desea seguir modificando?(s/n)\n");
					cin>>c;
					if(c!='s'){
						return true;
					}
					menu=0;
				break;
				case 4:	//Modificar comentario
					printf("Nuevo comentario:\n");
					getline(cin,aux);
					getline(cin,aux);
					t.setComentario(aux);
					printf("¿Desea seguir modificando?(s/n)\n");
					cin>>c;
					if(c!='s'){
						return true;
					}
					menu=0;
				break;
				case 5:	//Eliminar tratamiento
					t.setID(-1);
				break;
				default:
					if(menu>0){
						printf("Error, introduzca:\n");
						menu=0;
					}
				}
		}
		return false;
	}
	else{
		printf("No está permitido modificar este tratamiento\n");
		return false;
	}
}

void consultarCitas(Paciente &p)
{
	list <Cita> citas;
	list <Cita>::iterator c;
	fstream file;
	citas=p.getCitas();
	c=citas.begin();
	if(citas.empty())
	{
		cout<<"No existen citas para este paciente"<<endl;
	}else{
		int i=0;
		for(c=citas.begin();c!=citas.end();c++)
		{
			printf("%i: ",i);
			(*c).mostrarRegistro();
			printf("\n");
			i++;
		}

	}
}

void consultarTramientos(Paciente &p){
  	int i;
  	char c;
	list <Tratamiento> tratamientos;
	list <Tratamiento>::iterator t;
	fstream file;
	tratamientos=p.getTratamientos();		//Modificar getTratamientos
	t=tratamientos.begin();
	while(t!=tratamientos.end()){
		if((*t).getEstado()!=0){
			tratamientos.erase(t);
		}
		else{t++;}
	}
	i=1;
	if(tratamientos.empty()){
		printf("El paciente no está siguiendo ningun tratamiento actualmente\n");
	}
	else{
		for(t=tratamientos.begin();t!=tratamientos.end();t++){
			printf("%d.\n",i);
			(*t).mostrarRegistro();
			i++;
		}
		printf("Selecione un tratamiento o introduzca 0:");
		cin>>i;
		if(i>0){
			if(i<=(tratamientos.size()+1)){
				t=tratamientos.begin();
				advance(t,i-1);
				if(modificarTratamiento(*t)){
					if((i=(*t).getID())==-1){
						tratamientos.erase(t);
						printf("¿Seguro que desea eliminar el tratamiento?(s/n)\n");
					}
					else{
						system("clear");
						(*t).mostrarRegistro();
						printf("¿Desea guardar los cambios?(s/n)\n");
					}
					cin>>c;
					if(c=='s'){
						file.open("Pacientes/"+to_string(p.getID())+"/Tratamientos.txt",ofstream::out|ofstream::trunc);
						if(file.is_open()){
							for(t=tratamientos.begin();t!=tratamientos.end();t++){
							file<<escribeFecha((*t).getFecha())<<"|"<<escribeHora((*t).getHora())<<'|'<<(*t).getMedicamento()<<'|'<<(*t).getConcentracion()<<'|'<<(*t).getRegularidad()<<'|'<<escribeFecha((*t).getFechaInicio())<<'|'<<escribeFecha((*t).getFechaFinal())<<'|'<<(*t).getEstado()<<'|'<<(*t).getComentario()<<endl;
							}
							file.close();
							if(i==-1){
								printf("Tratamiento eliminado correctamente\n");
							}
							else{
								printf("Tratamiento modificado correctamente\n");
							}
						}
						else{
							if(i==-1){
								printf("Tratamiento no se ha podido eliminar\n");
							}
							else{
								printf("Tratamiento no se ha podido modificar\n");
							}
						}
						sleep(2);
					}
				}

			}
		}
	}
}


list<Cita> getCitas(fecha f1,fecha f2){		//Tienen que ser fechas validas
	list<Cita> C;
	struct Cita aux(0);
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
			file.open("Agenda/"+to_string(i.m)+"_"+to_string(i.a)+".txt");
			if(file.is_open()){
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
				C.pop_back();
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
void anadirCita(Paciente &p){
	int num;
	Cita C(p.getID());
	char c;
	list<Cita> agenda;
	list<Cita>::iterator i;
	bool bucle=true;
	string aux;
	fecha f;
	hora h;
	while(bucle){
		printf("Día:");
		if(leerFecha(f)!=true){
		printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
		}
		else if(dias(HOY,f)<0&&Registro::modificable_==false){
		printf("Ese día ya ha pasado\n");
		}
		else{
			bucle=false;
		}
	}
	bucle=true;
	while(bucle){
		printf("Hora:");
		if(leerHora(h)!=true){
		printf("Formato de hora incorrecto, introduzca hh:mm\n");
		}
		else {
			agenda=getCitas(f,f);
			bucle=false;
			for(i=agenda.begin();((i!=agenda.end())&&(!bucle));i++){
				num=minutos(h,(*i).getHora());
				if(num<0){
					num=num*-1;
				}
				if(num<5){
					printf("No puede ser a esa hora porque tiene otra cita a las %s\n",escribeHora((*i).getHora()));
					bucle=true;
				}
			}
		}
	}
	printf("Introduzca un comentario(opcional): ");
	getline(cin,aux);
	getline(cin,aux);
	C.setFecha(f);
	C.setHora(h);
	C.setComentario(aux);			//Termina de pedir datos
	printf("¿Desea guardar la cita? s/n\n");		//Pide confirmación (Si no confirma se sale)
	cin>>c;
	if(c=='s'){
		if(C.addCita()){
			printf("Cita guardada correctamente\n");
		}
		else{
			printf("Ha ocurrido un error inesperado\n");
		}
	}
}

void anadirTratamiento(Paciente &p){
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
	do{
		bucle=true;
		printf("Fecha de inicio: ");
		while(bucle){
			if(leerFecha(f1)!=true){
			printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			else if(dias(HOY,f1)<0&&Registro::modificable_==false){			//Modificable_
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
			else{
				bucle=false;
			}
		}
		if(dias(f1,f2)<0){
			printf("El tratamiento no puede finalizar antes de empezar\n");
			bucle=true;
		}
		else{
			bucle=false;
		}
	}while(bucle);
	t.setFechaInicio(f1);
	t.setFechaFinal(f2);
	printf("Introduzca un comentario(opcional): ");
	getline(cin,aux);
	getline(cin,aux);
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
		sleep(2);
	}
}
void anadirNota(Paciente &p){
	Nota n(p.getID());
	char c;
	string aux;
	printf("Nota:\n");
	cin>>aux;
	n.setContenido(aux);			//Termina de pedir datos
	printf("¿Desea guardar la nota? s/n\n");		//Pide confirmación (Si no confirma se sale)---------
	cin>>c;
	if(c=='s'){
		if(p.addNota(n)){
			printf("Nota guardada correctamente\n");
		}
		else{
			printf("Ha ocurrido un error inesperado\n");
		}
		sleep(1);
	}
}
bool Nombre_Apellidos(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.nombre_+p1.apellidos_;
    s2=p2.nombre_+p2.apellidos_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}
bool Apellidos_Nombre(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.apellidos_+p1.nombre_;
    s2=p2.apellidos_+p2.nombre_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}
bool ordenarporFecha(Paciente p1,Paciente p2){
  return ((p1.getFechanacimiento())<(p2.getFechanacimiento()));
}

int nuevoID(){
	string aux,aux2;
	int n;
	ifstream f1;
	ofstream f2;
	f1.open("Ajustes.txt");
	getline(f1,aux,'\n');
	getline(f1,aux2,'\n');
	f1.close();
	f2.open("Ajustes.txt",ios::trunc);
	n=stoi(aux2);
	n++;
	f2<<aux<<endl<<n<<endl;
	f2.close();
	return n;
}

void consultarAgenda(){
	int n;
	string aux;
	list<Cita> citas;
	list<Cita>::iterator c;
	printf("1 Mostrar citas del día\n2 Mostrar citas en intervalo\n");
	cin>>n;
	if((n==1)||(n==2)){
		if(n==1){
			citas=getCitas(HOY,HOY);
			if(citas.size()==0){printf("No hay citas programadas para hoy\n");}
		}
		if(n==2){
			bool bucle;
			fecha f1,f2;
			printf("Mostrar citas desde:\n");
			if(leerFecha(f1)!=true){			//Lee fecha 1
				printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			printf("Hasta:\n");
			if(leerFecha(f2)!=true){			//Lee fecha 2
				printf("Formato de fecha incorrecto, introduzca dia/mes/año\n");
			}
			if(dias(f1,f2)<0){
				printf("Intervalo no valido\n");
			}
			else{
				citas=getCitas(f1,f2);
				if(citas.size()==0){printf("No hay citas programadas para ese intervalo\n");}
			}
		}
		for(c=citas.begin();c!=citas.end();c++){
			(*c).mostrarRegistro();
		}
	}
	printf("Pulse enter para volver al menu\n");
	getline(cin,aux);
	getline(cin,aux);
}
