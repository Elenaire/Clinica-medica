#include "funciones.h"

void hoy(struct fecha &f){
	time_t aux=time(0);
	tm *t=localtime(&aux);
	f.a=t->tm_year;
	f.m=t->tm_mon;
	f.d=t->tm_mday;
}
void hoy(struct hora &h){
	time_t aux=time(0);
	tm *t=localtime(&aux);
	h.h=t->tm_hour;
	h.m=t->tm_min;
	h.s=t->tm_sec;
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