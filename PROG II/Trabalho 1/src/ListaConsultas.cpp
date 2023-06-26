//
// Created by vinic on 28/09/2022.
//
#include "iostream"
#include "ctime"

using namespace std;

#include "ListaConsultas.hpp"

int ListaConsultas::length = 0;

ListaConsultas::ListaConsultas() {
    primeiro = nullptr;
}

void ListaConsultas::inserirConsulta(Consulta *consulta) {

    consulta->setProx(primeiro);
    primeiro = consulta;
    length++;

}

void ListaConsultas::removerConsulta(int consulta) {

    if (length == 0) {
        return;
    }

    //Removendo caso seja o primeiro elemento
    if (primeiro->getId() == consulta) {

        Consulta *aux = primeiro;
        primeiro = primeiro->getProx();

        delete aux;
        length--;
        return;

    }

    Consulta *aux = primeiro;
    Consulta *elemento = primeiro->getProx();

    while (elemento) {

        if (consulta == elemento->getId()) {
            aux->setProx(elemento->getProx());
            delete elemento;
            length--;
            return;
        }

        aux = elemento;
        elemento = elemento->getProx();
    }

}

void ListaConsultas::imprimirConsultas() {

    if (length == 0) {
        cout << "Nenhuma consulta cadastrada!\n";
        return;
    }

    Consulta *elemento = primeiro;

    while (elemento) {
        elemento->imprimir();
        elemento = elemento->getProx();
    }

}

int ListaConsultas::numeroConsultas() {
    return length;
}

int ListaConsultas::buscarConsultasPorMedico(string cpf) {

    int count = 0;

    Consulta *elemento = primeiro;

    while (elemento) {

        if (elemento->getMedico().getCpf() == cpf) {
            count++;
        }

        elemento = elemento->getProx();
    }

    return count;
}

void ListaConsultas::removerTodasConsultasMedicoOuPaciente(string cpf) {

    if (length == 0) {
        return;
    }

    //Removendo caso a lista tenha só um elemento
    if (length == 1) {

        string cpfMedico = primeiro->getMedico().getCpf();
        string cpfPaciente = primeiro->getPaciente().getCpf();

        if (cpfMedico == cpf || cpfPaciente == cpf) {
            Consulta *aux = primeiro;
            primeiro = nullptr;

            delete aux;
            length--;
            return;
        }

    }

    Consulta *aux = primeiro;
    Consulta *elemento = primeiro->getProx();

    while (elemento) {

        string cpfMedico = elemento->getMedico().getCpf();
        string cpfPaciente = elemento->getPaciente().getCpf();

        if (cpfMedico == cpf || cpfPaciente == cpf) {

            aux->setProx(elemento->getProx());

            delete elemento;
            length--;

            this->removerTodasConsultasMedicoOuPaciente(cpf);
            return;
        }

        aux = elemento;
        elemento = elemento->getProx();

    }

}

void ListaConsultas::imprimirConsultasPorMedicoOuPaciente(string cpf) {

    if (length == 0) {
        cout << "Não há consultas cadastradas! \n";
    }

    Consulta *elemento = primeiro;

    while (elemento) {

        if (elemento->getMedico().getCpf() == cpf || elemento->getPaciente().getCpf() == cpf) {
            elemento->imprimir();
        }

        elemento = elemento->getProx();
    }

}

Data ListaConsultas::buscarUltimaConsulta(string cpf) {

    Data data;

    Consulta* aux = primeiro;

    while (aux) {

        if (aux->getPaciente().getCpf() == cpf)
        {
            Data auxData = aux->getData();

            if (aux->getData().getAno() >= data.getAno() && aux->getData().getMes() >= data.getMes() &&
                aux->getData().getDia() >= data.getDia() && aux->getData().getHoras() >= data.getHoras()) {
                data = aux->getData();
            }

        }

        aux = aux->getProx();
    }
    return data;
}

Data ListaConsultas::buscarProximaData(string cpf) {

    int consultasMedico = buscarConsultasPorMedico(cpf);

    if (consultasMedico == 0) {

        time_t t = std::time(0);   // get time now

        tm *now = std::localtime(&t);

        if (now->tm_wday == 0) {
            return Data(now->tm_mday + 1, now->tm_mon + 1, now->tm_year + 1900, 8, 0);
        }

        if (now->tm_wday == 6) {
            return Data(now->tm_mday + 2, now->tm_mon + 1, now->tm_year + 1900, 8, 0);
        }

        return Data(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, now->tm_hour + 1, 0);
    }

    Data ultimaData;

    Consulta *aux = primeiro;

    while (aux) {

        if (aux->getMedico().getCpf() == cpf) {

            if (ultimaData.dataVazia()) {
                ultimaData = aux->getData();
            }

            if (aux->getData().getAno() >= ultimaData.getAno() && aux->getData().getMes() >= ultimaData.getMes() &&
                aux->getData().getDia() >= ultimaData.getDia() && aux->getData().getHoras() >= ultimaData.getHoras()) {
                ultimaData = aux->getData();
            }

        }

        aux = aux->getProx();
    }

    if ((ultimaData.getHoras() + 1) > 18) {

        ultimaData.setDia(ultimaData.getDia() + 1);

    } else {
        ultimaData.setHoras(ultimaData.getHoras() + 1);
    }

    return ultimaData;

}

int ListaConsultas::buscarProximoId() {

    if (length == 0) {
        return 1;
    }

    return this->primeiro->getId() + 1;
}
