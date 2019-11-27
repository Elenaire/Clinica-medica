#ifndef PACIENTE_H
  #define PACIENTE_H

  #include <cstdio>
  #include <fstream>
  #include <string>
  #include <list>
  #include "funciones.h"
  #include "Cita.h"
  #include "Tratamiento.h"
  #include "Nota.h"

  using namespace std;

  class Paciente
  {
  private:
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
    friend bool filtraPacientes(int filtro,list<Paciente> p);
    friend void ordenarPacientes(int parametro,list<Paciente> p);
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
    inline void setDireccion(string adress){nombre_=adress;}
    inline void setFechanacimiento(struct fecha date){fechanacimiento_=date;}
    inline void setTelefono(int tlf){telefono_=tlf;}
    inline void setCodPostal(int cp){codpostal_=cp;}
    inline void setTipo(int type){tipo_=type;}
    //int getEdad();

    int getEdad(){
  int aux=HOY.a-fechanacimiento_.a;
  if(fechanacimiento_.m>HOY.m){
    aux--;
  }
  else if(fechanacimiento_.m==HOY.m){
    if(fechanacimiento_.d>HOY.d){
      aux--;
    }
  }
  return aux;
}

    list <Cita> getCitas();
    list <Tratamiento> getTratamiento();//Javi esto te toca a ti no te fies mucho de lo que he escrito yo
    list <Nota> getNotas();
    void mostrarPaciente();
    void mostrarRegistro();
    void mostarHistorial();
    void addTratamiento(const Tratamiento t);	//Sin probar
  };

  #endif
