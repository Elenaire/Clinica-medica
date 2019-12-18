#ifndef PACIENTE_H
  #define PACIENTE_H

  #include <cstdio>
  #include <fstream>
  #include <string>
  #include <list>
  #include "fecha_hora.h"
  #include "Cita.h"
  #include "Tratamiento.h"
  #include "Nota.h"


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
    Paciente(int id_);
    friend bool filtrarPacientes(int filtro,list<Paciente> p);
    friend void ordenarPacientes(int parametro,list<Paciente> p);
    friend bool Nombre_Apellidos(Paciente p1,Paciente p2);
    friend bool Apellidos_Nombre(Paciente p1,Paciente p2);
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
    int getEdad();
    list <Cita> getCitas();//Javi esto te toca a ti no te fies mucho de lo que he escrito yo
    list <Tratamiento> getTratamientos();
    list <Nota> getNotas();//Javi esto te toca a ti no te fies mucho de lo que he escrito yo
    void mostrarPaciente();
    void mostrarHistorial();
    bool addTratamiento(const Tratamiento t);	//Sin probar
  };

  #endif
