#include "Paciente.h"
#include "iostream"
#include "Tratamiento.h"
#include "funciones.h"
#include <list>

	void mostrarPacientes(list<Paciente> &p);					//Muestra los datos de la lista de pacientes
	bool filtrarPacientes(int filtro,list<Paciente> &p);		//Sin probar
	void ordenarPacientes(int parametro,list<Paciente> &p);		//Sin completar
	bool modificarTratamiento(Tratamiento &t);					//Sin hacer   //Mal, tiene que ser de tratamiento
	void consultarTramientos(Paciente &p);
	void anadirTratamiento(Paciente &p);
	void AddPaciente(Paciente p);
    void AgregaP();

using namespace std;
bool buscarPaciente(Paciente &p){		//Sin completar Sin probar
	int menu,id,orden;
	list<Paciente> pacientes;
	list<Paciente>::iterator i;
	printf("0 Listar pacientes\nBuscar paciente por:\n1 Nombre completo\n2 Nombre\n3 Apellidos\n4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Pacientes públicos\n9 Pacientes privados\n-1 Salir\n");
	scanf("%d",&menu);
	if(menu>=0){
		filtrarPacientes(menu,pacientes);
	}
	while(menu>=0){				//se sale con -1 o con negativo?
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
				printf("0 Reiniciar busqueda\n1 Nombre completo\n2 Nombre\n3 Apellidos\n 4 Edad\n5 Fecha de nacimiento\n6 Dirección\n7 Código postal\n8 Telefono\n9 Pacientes públicos\n10 Pacientes privados\n-1 Salir\n");
				do{
					scanf("%d",&menu);
				}while((menu>0)&&(filtrarPacientes(menu,pacientes)));
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


void menuPaciente(Paciente p){
	int menu=0;
	while(menu>=0){
		p.mostrarPaciente();
		/*
		bla bla menu
		*/
		switch(menu){
			case 0:
				printf("1 Mostrar historial\n2 Recetar tratamiento\n3 Consultar tratamientos\n4 Añadir cita\n5 Modificar datos del paciente\n7 Eliminar paciente\n-1 Atras\n");
				cin>>menu;
			break;
			case 2:		//Añadir tratamiento +Hecho  -Funciones					ID="fichero.size"
				anadirTratamiento(p);
				menu=0;
			break;
			case 3:	//Consultar tratamientos
				consultarTramientos(p);
				menu=0;
			break;
			case 4:
			printf("Hola\n");
				//anadirNota(p);
				menu=0;
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
//bool Registro::modificable_=false;
int main(){
	int menu=0;
	Paciente p;	
	hoy(HOY);		
	/*
	Inicio
	*/
	printf("Hola, bla bla bla\n");
	while(menu>=0){
		switch(menu){
			case 0:
			printf("1 Seleccionar paciente\n2 Añair paciente\n3 Añadir cita\n4 Consultar agenda\n");
				cin>>menu;
			break;
			case 1:		//Buscar paciente +Hecho  -Funciones
				if(buscarPaciente(p)){
					menuPaciente(p);
				}
				menu=0;
			break;
			case 2:		//Añadir paciente
				AgregaP();
			break;
			case 3:		//Añadir cita
			/*
				buscarPaciente(p);
				anadirCita(p);
				*/
			break;
			case 4:		//Consultar agenda

			break;
			default:
			if(menu>0){
				printf("Error, introduzca:\n");
				menu=0;
			}
			else{
				printf("Cerrando programa...\n");
			}
		}
	}
	printf("Cerrando programa\n");
	//......
}