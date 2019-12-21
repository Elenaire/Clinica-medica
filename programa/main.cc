#include "Paciente.h"
#include "iostream"
#include "Tratamiento.h"
#include "funciones.h"
#include <list>

	void leerPacientes(list<Paciente> &p);						//Lee un paciente del fichero de pacientes -Sin probar
	void mostrarPacientes(list<Paciente> &p);					//Muestra los datos de la lista de pacientes -Sin probar
	bool filtrarPacientes(int filtro,list<Paciente> &p);		//Sin probar
	void ordenarPacientes(int parametro,list<Paciente> &p);		//Sin completar
	bool modificarTratamiento(Tratamiento &t);					//Sin hacer   //Mal, tiene que ser de tratamiento
	void consultarTramientos(Paciente &p);
	list<Cita> getCitas(fecha f1,fecha f2);						//Devuelve una lista con las citas de la fecha 1 a la fecha 2
	void anadirCita(Paciente &p);
	void anadirTratamiento(Paciente &p);
	void anadirNota(Paciente &p);
	//bool addCita(Cita &c);
	void anadirCita(Paciente &p);
	bool ContieneA(string cad1,string cad2);
	void AddPaciente(Paciente p);
    	void AgregaP();

using namespace std;
bool buscarPaciente(Paciente &p){		//Sin completar filtrar y ordenar
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

void AgregaP()
{
	Paciente p;
	fecha f;
	string auxs;
	int auxi;
	cout<<"Introdzuca nombre del paciente"<<endl;
	cin>>auxs;
	p.setNombre(auxs);
	cout<<"Introdzuca apellidos del paciente"<<endl;
	cin>>auxs;
	p.setApellidos(auxs);
	cout<<"Introdzuca la dirección del paciente"<<endl;
	cin>>auxs;
	p.setDireccion(auxs);
	cout<<"Introdzuca la fecha de nacimiento del paciente"<<endl;
	leerFecha(f);
	p.setFechanacimiento(f);
	cout<<"Introdzuca el telefono del paciente"<<endl;
	cin>>auxi;
	p.setTelefono(auxi);
	cout<<"Introdzuca el cod.postal del paciente"<<endl;
	cin>>auxi;
	p.setCodPostal(auxi);
	cout<<"Introdzuca el tipo del paciente"<<endl;
	cin>>auxi;
	p.setTipo(auxi);
	AddPaciente(p);
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
				printf("1 Mostrar historial\n2 Recetar tratamiento\n3 Consultar tratamientos\n4 Añadir cita\n5 Modificar datos del paciente\n6 Añadir nota\n7 Eliminar paciente\n-1 Atras\n");
				cin>>menu;
			break;
			case 2:		//Añadir tratamiento +Hecho  -Funciones
				anadirTratamiento(p);
				menu=0;
			break;
			case 3:	//Consultar tratamientos
				consultarTramientos(p);
				menu=0;
			break;
			case 4:	//Añadir cita
				anadirCita(p);
				menu=0;
			break;
			case 5:	//Modificar datos del paciente

				//-----------------------

				menu=0;
			break;
			case 6:
				anadirNota(p);
				menu=0;
			break;
			case 7:	//Eliminar paciente
			printf("Hola\n");
				//Eliminar paciente?
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
				//AgregaP();
			break;
			case 3:		//Añadir cita
				buscarPaciente(p);
				anadirCita(p);
				menu=0;
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
