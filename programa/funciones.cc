#include "funciones.h"
#include "Paciente.h"


void hoy(struct fecha &f){
	time_t aux=time(0);
	tm *t=localtime(&aux);
	f.a=1900+t->tm_year;
	f.m=t->tm_mon+1;
	f.d=t->tm_mday;
}
void hoy(struct hora &h){
	time_t aux=time(0);
	tm *t=localtime(&aux);
	h.h=t->tm_hour;
	h.m=t->tm_min;
	h.s=t->tm_sec;
}
bool leerFecha(struct fecha &f){
	if(scanf("%2d/%2d/%4d",&f.d,&f.m,&f.a)==EOF){
		return false;
	}
	return true;
}

bool leerHora(struct hora &h){
	h.s=0;
	if(scanf("%2d:%2d",&h.h,&h.m)==EOF){
		return false;
	}
	return true;
}

char* escribeFecha(struct fecha const &f){
	char *c=(char*)malloc(11*sizeof(char));
	sprintf(c,"%2d/%2d/%4d",f.d,f.m,f.a);
	return c;
}
char* escribeHora(struct hora const &h){
	char *c=(char*)malloc(5*sizeof(char));
	sprintf(c,"%2d:%2d",h.h,h.m);
	return c;
}

int dias(struct fecha f1,struct fecha f2){		//Devulve los dias transcurridos desde f1 hasta f2, si ha transcurrido mas de un mes devulve 100, f2 es anterios a f1 devuelve un numero negativo
	int mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int aux,a,m,d;
	a=f2.a-f1.a;
	if(a<0){
		aux=-1;
	}
	else{
		if(a>1){			//Mas de un año
			aux=100;
		}
		else{
			if(a==1){		//Distinto año
				m=12+f2.m-f1.m;
			}
			else{			//Mismo año
				m=f1.m-f2.m;
			}
			if(m<0){
				aux=-1;
			}
			else{
				if(m>1){			//Mas de un mes
					aux=100;
				}
				else{
					if(m==0){			//Mismo mes
						aux=f2.d-f1.d;
					}
					else{			//Distinto mes
						d=mes[f1.m-1]-f1.d;
						aux=d+f2.d;
					}
				}
			}
		}
	}
	return aux;	
}
int minutos(struct hora h1,struct hora h2){
	int h,m;
	h=h2.h-h1.h;
	if(h==0){
		m=h2.m-h1.m;
	}
	else if(h>0){
		m=100;
		if(h==1){
			m=(60-h1.m+h2.m);
		}
	}
	else if(h<0){
		m=-100;
		if(h==-1){
			m=-(60-h2.m+h1.m);
		}
	}
	return m;
}
bool filtraPacientes(int filtro,list<Paciente> p){			//Sin probar
	if((p.empty())||(filtro==0)){
		//lee lista de pacientes
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
					aux2=i->nombre_+i->apellidos_;
					if(aux.compare(aux2)){				//Si en aux se encuentra aux2 es positivo, si no coincide algun caracter es negativo
						lista.push_back(*i);
					}
				}
			break;
			case 2:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare(i->nombre_)){
						lista.push_back(*i);
					}
				}
			break;
			case 3:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare(i->apellidos_)){
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
					if(f==i->fechanacimiento_){
						lista.push_back(*i);
					}
				}
			break;
			case 6:
				getline(cin,aux);
				for(i=p.begin();i!=p.end();++i){
					if(aux.compare(i->direccion_)){
						lista.push_back(*i);
					}
				}
			break;
			case 7:
			scanf("%d",&n);
			for(i=p.begin();i!=p.end();++i){
				if(n==i->codpostal_){
					lista.push_back(*i);
				}
			}
			break;
			case 8:
				scanf("%d",&n);
				for(i=p.begin();i!=p.end();++i){
					if(n==i->telefono_){
						lista.push_back(*i);
					}
				}
			break;
			case 9:
			for(i=p.begin();i!=p.end();++i){
				if(i->tipo_==0){
					lista.push_back(*i);
				}
			}
			break;
			case 10:
			for(i=p.begin();i!=p.end();++i){
				if(i->tipo_==1){
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
/*
void ordenarPacientes(int parametro,list<Paciente> p){			//Necesito crear funciones de ordenación (ojalá pudiera declararlas pero si lo hago alguien me borrara el .h)
	int orden;
	switch(parametro){
		case 1:		//Nombre y apellidos
			printf("¿Orden ascendente(1) o descendente(-1)? \n");  	//Ordena si es positivo ascendente, si es negativo descendente y si es 0 cancela
			scanf("%d",&orden);
				if(orden!=0){
					//p.sort(funcion);
					if(orden<0){p.reverse();}
				}
		break;
		case 2:
																---------------------------------
		break;
		case 3:

		break;
		case 0:		//Ordena por id

		break;
	}
}				*/
/*
list<Paciente> leerPacientes(){
	list <Paciente> aux;
	ifstream file;
	file.open("Pacientes.txt");
	string cad
	for(t=aux.begin();t!=aux.end();t++)
	{
	  	getline(file,cad,"/");
	    (t->fecha_)->d=stoi(cad);
	    getline(file,cad,"/");
	    (t->fecha_)->m=stoi(cad);
	    getline(file,cad,"||");
	    (t->fecha_)->a=stoi(cad);
	    getline(file,cad,":");
	    (t->hora_)->h=stoi(cad);
	    getline(file,cad,":");
	    (t->hora_)->m=stoi(cad);
	    getline(file,cad,"||");
	    (t->hora_)->s=stoi(cad);
	    getline(file,cad,"||");
	    t->paciente_=stoi(cad);
	    getline(file,(t->medicamento_),"||");
	    getline(file,(t->concentracion_),"||");
	    getline(file,(t->regularidad_),"||");
	    getline(file,cad,"/");
	    (t->fecha_inicio_)->d=stoi(cad);
	    getline(file,cad,"/");
	    (t->fecha_inicio_)->m=stoi(cad);
	    getline(file,cad,"||");
	    (t->fecha_inicio_)->a=stoi(cad);
	    getline(file,cad,"/");
	    (t->fecha_final_)->d=stoi(cad);
	    getline(file,cad,"/");
	    (t->fecha_final_)->m=stoi(cad);
	    getline(file,cad,"||");
	    (t->fecha_final_)->a=stoi(cad);
	    getline(file,cad,"\n");
	    t->estado=stoi(cad);
	    aux.push_back(t);
	  }
	  file.close();
	}*/