#ifndef PACIENTE_H
#define PACIENTE_H

#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include "funciones.h"
#include "Cita.h"
#include "Tratamiento.h"
#include "Nota.h"

class Paciente
{
private:
  list <Cita> citas_;
  list <Cita>::iterator c_;
  list <Tratamiento> tratamientos_;
  list <Tratamiento>::iterator t_;
  list <Notas> notas_;
  list <Notas>::iterator n_;
  int id_;
  string nombre_;
  string apellidos_;
  string direccion_;
  struct fecha fechanacimiento_;
	int telefono_;
	int codpostal_;
	int tipo_;
public:
  Paciente(int telefono);
  inline int getID(){return id_;}
  inline string getNombre(){return nombre_;}
  inline string getApellidos(){return apellidos_;}
  inline string getDireccion(){return direccion_;}
  inline struct fecha getFechanacimiento(){return fechanacimiento_;}
  inline int getTelefono(){return telefono_;}
  inline int getCodPostal(){return codpostal_;}
  inline int getTipo(){return tipo_;}
  inline void setID(int id){id_=id;}
  inline void setNombre(string name){nombre_=name;}
  inline void setApellidos(string surname){apellidos_=surname;}
  inline void setDireccion(string adress){nombre_=name;}
  inline void setFechanacimiento(struct fecha date){fechanacimiento_=date;}
  inline void setTelefono(int tlf){telefono_=tlf;}
  inline void setCodPostal(int cp){codpostal_=cp;}
  inline void setTipo(int type){tipo_=type;}
  list <Cita> getCitas();
  list <Tratamiento> getTratamiento();
  list <Nota> getNotas();
  void mostrarPaciente();

};

#endif
