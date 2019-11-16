#include <string>
#include <ctime>
#include <iostream>
#include "funciones.h"
using namespace std;
int main(){
	struct fecha d1,d2;
	int aux;
	d1.a=2019;
	d1.m=10;
	d1.d=10;
	d2.a=2019;
	d2.m=10;
	d2.d=8;
	aux=dias(d1,d2);
	cout<<aux<<endl;
}