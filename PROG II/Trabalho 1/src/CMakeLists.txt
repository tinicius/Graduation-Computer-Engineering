cmake_minimum_required(VERSION 3.22)
project(Trabalho_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Trabalho_2 main.cpp Pessoa.cpp Pessoa.hpp Medico.cpp Medico.hpp Paciente.cpp Paciente.hpp Data.cpp Data.hpp Consulta.cpp Consulta.hpp ListaPacientes.cpp ListaPacientes.hpp ListaMedicos.cpp ListaMedicos.hpp ListaConsultas.cpp ListaConsultas.hpp Consultorio.cpp Consultorio.hpp)
