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

void Ajustes(){
	int n;
	fstream ajustes;
	string aux;
	printf("1 Cambiar nombre\n");
	if(Registro::modificable_){
		printf("2 Deshabilitar restricciones\n");
	}
	else{
		printf("2 Habilitar restricciones\n");
	}
	cin>>n;
	if(n==1){
		ajustes.open("Ajustes.txt",ios::in);
		getline(ajustes,aux,'\n');
		getline(ajustes,aux,'\n');
		n=stoi(aux);
		ajustes.close();
		printf("Nuevo nombre: ");
		getline(cin,aux);
		getline(cin,aux);
		ajustes.open("Ajustes.txt",ios::out|ios::trunc);
		ajustes<<"Buenos días "<<aux<<endl<<n;
		ajustes.close();
	}
	if(n==2){
		if(Registro::modificable_){
			Registro::modificable_=false;
		}
		else{
			Registro::modificable_=true;
		}
	}
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
	if((carpeta=opendir("Pacientes"))){		//Esto está bien
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
			printf("1 Seleccionar paciente\n2 Añadir paciente\n3 Añadir cita\n4 Consultar agenda\n5 Ajustes\n-1 Salir\n");
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
				printf("Seleccione el paciente con el tendrá la cita:\n\n");
				p.setID(-1);
				buscarPaciente(p);
				if(p.getID()!=-1){
					system("clear");
					p.mostrarPaciente();
					anadirCita(p);
				}
				menu=0;
				system("clear");
			break;
			case 4:		//Consultar agenda
				consultarAgenda();
				menu=0;
				system("clear");
			break;
			case 5:
				Ajustes();
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
