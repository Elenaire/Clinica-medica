#include "Paciente.h"
#include "iostream"
#include "Tratamiento.h"
#include "funciones.h"
#include <list>
#include <cstdlib>
#include <unistd.h>
#include <dirent.h>
using namespace std;

fecha HOY;

bool Registro::modificable_=false;
int main(){
	int menu=0;
	Paciente p;
	hoy(HOY);
	printf("Hoy es: %s\n",escribeFecha(HOY));
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
			printf("1 Seleccionar paciente\n2 Añadir paciente\n3 Añadir cita\n4 Consultar agenda\n-1 Salir\n");
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
