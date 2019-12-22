#include "Paciente.h"
#include "iostream"
#include "Tratamiento.h"
#include "funciones.h"
#include <list>
#include <cstdlib>
#include <unistd.h>
#include <dirent.h>
using namespace std;
bool buscarPaciente(Paciente &p){		//Sin completar filtrar y ordenar
	int menu,id,orden;
	list<Paciente> pacientes;
	list<Paciente>::iterator i;
	printf("0 Listar pacientes\nBuscar por:\n1 Nombre completo\n2 Nombre\n3 Apellidos\n4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Telefono\n9 Pacientes públicos\n10 Pacientes privados\n-1 Salir\n");
	scanf("%d",&menu);
	if(menu>=0){
		filtrarPacientes(menu,pacientes);
	}
	while(menu>=0){				//se sale con -1 o con negativo?
		system("clear");
		mostrarPacientes(pacientes);
		printf("1 Seleccionar paciente\n2 Ordenar pacientes\n3 Filtra pacientes\n-1 Salir\n");
		scanf("%d",&menu);
		system("clear");
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
	cout<<"Introdzuca el cododico postal del paciente"<<endl;
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
	p.mostrarPaciente();
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

				//-----------------------

				menu=0;
				system("clear");
			break;
			case 6:
				anadirNota(p);
				menu=0;
				system("clear");
			break;
			case 7:	//Eliminar paciente
			printf("Hola\n");
				//Eliminar paciente?
				menu=0;
				system("clear");
			break;
			default:
				if(menu>0){
					printf("Error, introduzca:\n");
					menu=0;
				}
			}
	}
	//......
}
bool Registro::modificable_=false;
int main(){
	int menu=0;
	Paciente p;	
	hoy(HOY);
	DIR * carpeta;
	string saludo;
	fstream ajustes;
	ajustes.open("Ajustes.txt",ios::in);
	if(carpeta=opendir("Pacientes")){
		closedir(carpeta);
	}
	else{
		system("mkdir Pacientes");
	}
	if(carpeta=opendir("Agenda")){
		closedir(carpeta);
	}
	else{
		system("mkdir Agenda");
	}
	if(!ajustes.is_open()){
		printf("Buenos días usuario.¿Como le gustaria que le llamara?\n");
		getline(cin,saludo);
		ajustes.open("Ajustes.txt",ios::out);
		ajustes<<"Buenos días "<<saludo<<endl<<1;
		ajustes.close();
	}
	else{
		getline(ajustes,saludo,'\n');
		cout<<saludo<<endl<<endl;
	}
	while(menu>=0){
		switch(menu){
			case 0:
			printf("1 Seleccionar paciente\n2 Añair paciente\n3 Añadir cita\n4 Consultar agenda\n-1 Salir\n");
				cin>>menu;
				system("clear");
			break;
			case 1:		//Buscar paciente +Hecho  -Funciones
				if(buscarPaciente(p)){
					menuPaciente(p);
				}
				menu=0;
				system("clear");
			break;
			case 2:		//Añadir paciente
				AgregaP();
				menu=0;
				system("clear");
			break;
			case 3:		//Añadir cita
				buscarPaciente(p);
				anadirCita(p);
				menu=0;
				system("clear");
			break;
			case 4:		//Consultar agenda
				consultarAgenda();
				menu=0;
				system("clear");
			break;
			default:
			if(menu>0){
				printf("Error, introduzca:\n");
				menu=0;
			}
		}
	}
	printf("Cerrando programa\n");
	//......
}
