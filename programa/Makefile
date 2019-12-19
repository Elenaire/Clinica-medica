CXXFLAGS += -g -Wall -Wextra -std=gnu++11
all : main.x

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

fecha_hora.o : fecha_hora.cc fecha_hora.h
		$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c fecha_hora.cc

funciones.o : funciones.cc funciones.h fecha_hora.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c funciones.cc fecha_hora.o

Cita.o : Cita.cc Cita.h Registro.h funciones.o fecha_hora.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Cita.cc funciones.o fecha_hora.o

Tratamiento.o : Tratamiento.cc Tratamiento.h Registro.h funciones.o fecha_hora.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Tratamiento.cc funciones.o fecha_hora.o

Nota.o : Nota.cc Nota.h Registro.h funciones.o fecha_hora.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Nota.cc funciones.o fecha_hora.o

Paciente.o : Paciente.cc Paciente.h funciones.o fecha_hora.o Cita.o Tratamiento.o Nota.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Paciente.cc funciones.o fecha_hora.o Cita.o Tratamiento.o Nota.o

main.x : main.cc Paciente.o Cita.o Tratamiento.o Nota.o funciones.o fecha_hora.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o main.x main.cc Paciente.o funciones.o fecha_hora.o Tratamiento.o

