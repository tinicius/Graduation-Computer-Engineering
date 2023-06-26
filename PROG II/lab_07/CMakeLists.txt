cmake_minimum_required(VERSION 3.23)
project(lab_07)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_07 main.cpp Contas.cpp Contas.hpp ListaCorrente.hpp ListaCorrente.cpp Corrente.hpp Corrente.cpp CorrenteLimite.hpp CorrenteLimite.cpp ListaCorrenteLimite.hpp ListaCorrenteLimite.cpp Poupanca.hpp Poupanca.cpp ListaPoupanca.cpp ListaPoupanca.hpp ExceptionLimite.cpp ExceptionLimite.hpp)
