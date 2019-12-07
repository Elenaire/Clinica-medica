#include "Paciente.h"
#include "funciones.h"

Paciente::Paciente(int telefono)
{
  id_=0;
  telefono_=telefono;
  nombre_="";
  apellidos_="";
  direccion_="";
  fechanacimiento_->a=0;
  fechanacimiento_->m=0;
  fechanacimiento_->d=0;
  codpostal_=0;
  tipo_=-1;
}
int Paciente::getEdad(){
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

void Paciente::mostrarPaciente(){
  cout<<"ID: "<<id_<<endl;
  cout<<"NOMBRE: "<<nombre_<<endl;
  cout<<"APELLIDOS: "<<apellidos_<<endl;
  cout<<"DIRECCION: "<<direccion_<<endl;
  cout<<"FECHANACIMIENTO: "<<escribeFecha(fechanacimiento_)<<endl;
  cout<<"TELEFONO: "<<telefono_<<endl;
  cout<<"CODIGO POSTAL: "<<codpostal_<<endl;
  if(tipo_=0)
  {
    cout<<"TIPO: PUBLICO"<<endl;
  }else{
    cout<<"TIPO: PRIVADO"<<endl;
  }
}

list <Cita> Paciente::getCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,"/");
    (c->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (c->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    c->paciente_=stoi(cad);
    getline(file,(c->comentario_),"\n");
    aux.push_back(c);
  }
  file.close();
  return aux;
}

list <Tratamiento> Paciente::getTratamientos()   //Mal
{
  list <Tratamiento> aux;
  list <Tratamiento>::iterator t;
  ifstream file;
  file.open("Tratamientos.txt")
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
  return aux;
}

list <Nota> Paciente::getNotas()
{
  list <Nota> aux;
  list <Nota>::iterator n;
  ifstream file;
  file.open("citas.txt")
  string cad
  for(n=aux.begin();n!=aux.end();n++)
  {
  	getline(file,cad,"/");
    (n->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (n->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (n->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (n->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (n->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (n->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    n->paciente_=stoi(cad);
    getline(file,(n->nota_),"\n");
    aux.push_back(n);
  }
  file.close();
  return aux;
}


void AddPaciente(Paciente p)//ESTO HAY QUE CAMBIARLO TO
{
  fstream archivo;
  archivo.open("Pacientes.txt",std::fstream::app);
  archivo<<p.id_<<"||";
  archivo<<p.nombre_<<"||";
  archivo<<p.apellidos_<<"||";
  archivo<<escribeFecha(p.fechanacimiento_)<<"||";
  archivo<<p.telefono_<<"||";
  archivo<<p.codpostal_<<"||";
  archivo<<p.tipo_<<endl;
  archivo.close();
}

void Paciente::mostrarHCitas()
{
  list <Cita> aux;
  list <Cita>::iterator c;
  ifstream file;
  file.open("citas.txt") //VENDO OPEL CORSA
  string cad
  for(c=aux.begin();c!=aux.end();c++)
  {
  	getline(file,cad,"/");
    (c->fecha_)->d=stoi(cad);
    getline(file,cad,"/");
    (c->fecha_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->fecha_)->a=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->h=stoi(cad);
    getline(file,cad,":");
    (c->hora_)->m=stoi(cad);
    getline(file,cad,"||");
    (c->hora_)->s=stoi(cad);
    getline(file,cad,"||");
    c->paciente_=stoi(cad);
    getline(file,(c->comentario_),"\n"); //Javier, esto lo tienes que modificar, para que compare el numero del paciente con el ID  del paciente y solo copie los datos del paciente
    aux.push_back(c);
  }
  file.close();
  for(c=aux.begin();c!=aux.end();c++)
  {
  	if(id_=(c->paciente_))
  	{
  		cout<<(c->fecha_)->d<<endl;
  		cout<<(c->fecha_)->m<<endl;
  		cout<<(c->fecha_)->a<<endl;
  	}
  }
}

void Paciente::mostrarHistorial()
{
  // pide k kiere hase
  // llama a funcion getListaX
  // se imprimen en mostaerRegistro
  //si todo -> get citas, gt, tratamientos y get notas
  int elec;
  cout<<"Indique que historial quiere visualizar"<<endl<<"1.Notas\n2.Tratamientos\n3.Notas y tratamientos"<<endl;
  cin>>elec;
  switch(elec)
  {
    case 1:
    {
      list <Nota> notas;
      notas=getNotas();
      mostrarRegistro(notas);
      cout<<"Elija la opción a realizar"<<endl;
      cout<<"1.Modificar\n2.Eliminar\n3.Salir"<<endl;
      int elec2;
      switch(elec2)
      {
        case 1:
        {
          modificarNota();
        }break;
        case 2:
        {
          eliminarNota();
        }break;
      }
    }break;
    case 2:
    {
      list <Tratamiento> tratamientos;
      tratamientos=getTrtamientos();
      mostrarRegistro(Tratamiento);
      switch(elec2)
      {
        case 1:
        {
          modificarCita();
        }break;
        case 2:
        {
          eliminarCita();
        }break;
    }break;
    case 3:
    {
      list <Nota> notas;
      notas=getNotas();
      mostrarRegistro(notas);
      list <Tratamiento> tratamientos;
      tratamientos=getTrtamientos();
      mostrarRegistro(Tratamiento);
    }
  }
}

void Paciente::addTratamiento(const Tratamiento t){   //Sin probar
  fstream file;
  file.open(to_string(id_)+"/Tratamientos.txt",ios::out|ios::app|ios::ate);
  file<<escribeFecha(t.getFecha())<<"||"<<escribeHora(t.getHora())<<endl<<t.getMedicamento()<<endl<<t.getConcentracion()<<endl<<t.getRegularidad()<<endl<<escribeFecha(t.getFechaInicio())<<endl<<escribeFecha(t.getFechaFinal())<<endl<<t.getEstado()<<endl<<t.getComentario()<<endl;
  file.close();
}
bool Nombre_Apellidos(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.nombre_+p1.apellidos_;
    s2=p2.nombre_+p2.apellidos_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}
bool Apellidos_Nombre(Paciente p1,Paciente p2){
  int i;
  string s1,s2;
    s1=p1.apellidos_+p1.nombre_;
    s2=p2.apellidos_+p2.nombre_;
  for(i=0;((i<s1.length())&&(i<s2.length()));i++){
    if (tolower(s1[i])<tolower(s2[i])) return true;
    else if (tolower(s1[i])>tolower(s2[i])) return false;
  }
  return ( s1.length() < s2.length() );
}

void eliminarPaciente()
{
  ifstream file;
  file.open("Pacientes.txt");
  list<Paciente> aux;
  list<Paciente>::iterator i;
  Paciente p(3333,4444);
  string cad;
  while(getline(file,cad,"||"))
  {
    p->id_=stoi(cad);
    getline(file,cad,"||")
    p->nombre_=cad;
    getline(file,cad,"||")
    p->apellidos_=cad;
    getline(file,cad,"||")
    p->direccion_=cad;
    //Aqui va fecha que no se como ponerlo //ELENA SI LEES ESTO PONLO TU QUE NO ME ACUERDO COMO IBA ESO
    getline(file,cad,"||")
    p->telefono_=stoi(cad);
    p->codpostal_=stoi(cad);
    p->tipo_=stoi(cad);
    aux.push_back(p);
  }
  file.close();
  for(i=aux.begin();i!=aux.end();i++)
  {
    if(i->id_==id_)
    {
      i->id_=-1;
    }
  }
  char elec;
  cout<<"Está seguro de querer elimina el paciente "<<nombre_<<" (S/N)"<<endl;
  cin>>elec;
  if(elec=='S')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt")
    for(i=aux.begin();i!=aux.end();i++)
    {
      if(i->id_!=-1)
      {
        archivo<<i->id_<<"||";
        archivo<<i->nombre_<<"||";
        archivo<<i->apellidos_<<"||";
        archivo<<escribeFecha(i->fechanacimiento_)<<"||";
        archivo<<i->telefono_<<"||";
        archivo<<i->codpostal_<<"||";
        archivo<<i->tipo_<<endl;
      }
    }
  }
}

void ModificarPaciente()
{
  ifstream file;
  file.open("Pacientes.txt");
  list<Paciente> aux;
  list<Paciente>::iterator i;
  Paciente p(3333,4444);
  string cad;
  while(getline(file,cad,"||"))
  {
    p->id_=stoi(cad);
    getline(file,cad,"||")
    p->nombre_=cad;
    getline(file,cad,"||")
    p->apellidos_=cad;
    getline(file,cad,"||")
    p->direccion_=cad;
    //Aqui va fecha que no se como ponerlo
    getline(file,cad,"||")
    p->telefono_=stoi(cad);
    p->codpostal_=stoi(cad);
    p->tipo_=stoi(cad);
    aux.push_back(p);
  }
  file.close();
  int elec;
  cout<<"Indique que campos quiere modificar"<<endl<<"1.Nombre\n2.Apellidos\n3.Direccion\n4.Fecha de nacimiento\n5.Telefono\n6.Codigo Postal\n7.Tipo\n8.Modificar todos los campos"<<endl;
  cin>>elec;
  switch(elec)
  {
    case 1:
    {
      string name;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      cin>>name;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->nombre_=name;
        }
      }
    }break;
    case 2:
    {
      string surname;
      cout<<"Indique el nuevo apellido del paciente"<<endl;
      cin>>surname;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->apellidos_=surname;
        }
      }
    }break;
    case 3:
    {
      string adress;
      cout<<"Indique la nueva direccion del paciente"<<endl;
      cin>>adress;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->direccion_=adress;
        }
      }
    }break;
    case 4:
    {
      //AQUI VA LA FECHA PERO NO SE COMO PONERLA
    }break;
    case 5:
    {
      int tlf,
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      cin>>tlf;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->telefono_=tlf;
        }
      }
    }break;
    case 6:
    {
      int cp;
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      cin>>cp;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->codpostal_=cp;
        }
      }
    }break;
    case 7:
    {
      int type;
      cout<<"Indique el nuevo tipo del paciente"<<endl;
      cin>>type;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->tipo_=type;
        }
      }
    }break;
    case 8:
    {
      string name,surname,adress;
      int tlf,cp,type;
      cout<<"Indique el nuevo nombre del paciente"<<endl;
      cin>>name;
      cout<<"Indique el nuevo apellido del paciente"<<endl;
      cin>>surname;
      cout<<"Indique la nueva direccion del paciente"<<endl;
      cin>>adress;
      cout<<"Indique el nuevo telefono del paciente"<<endl;
      cin>>tlf;
      cout<<"Indique el nuevo codigo postal del paciente"<<endl;
      cin>>cp;
      cout<<"Indique el nuevo tipo del paciente"<<endl;
      cin>>type;
      for(i=aux.begin();i!=aux.end();i++)
      {
        if(i->id_==id_)
        {
          i->nombre_=name;
          i->apellidos_=surname;
          i->direccion_=adress;
          i->telefono_=tlf;
          i->codpostal_=cp;
          i->tipo_=type;
        }
      }
    }break;
  }
  cout<<"¿Está seguro de querer modificar estos campos? (S/N)"<<endl;
  char c;
  cin>>c;
  if(c=='S')
  {
    ofstream archivo;
    archivo.open("Pacientes.txt")
    for(i=aux.begin();i!=aux.end();i++)
    {
      if(i->id_!=-1)
      {
        archivo<<i->id_<<"||";
        archivo<<i->nombre_<<"||";
        archivo<<i->apellidos_<<"||";
        archivo<<escribeFecha(i->fechanacimiento_)<<"||";
        archivo<<i->telefono_<<"||";
        archivo<<i->codpostal_<<"||";
        archivo<<i->tipo_<<endl;
      }
    }
  }
}
