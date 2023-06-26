#include <iostream>

using namespace std;

const int TAM_VENDEDORES = 4;
const int TAM_MESES = 12;

typedef struct vendedor {
    string nome;
    int cod;
    double vendas[TAM_MESES];
} Vendedor;

void printMenu() {
    cout << "[a] Cadastrar vendedor\n";
    cout << "[b] Cadastrar venda\n";
    cout << "[c] Consultar vendas de um funcionário em determinado mês\n";
    cout << "[d] Consultar vendas totais de um vendedor\n";
    cout << "[e] Consultar vendedor que vendeu mais em determinado mês\n";
    cout << "[f] Consultar mẽs com mais vendas\n";
    cout << "[g] Sair\n";
}

void printAllVendedor(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    for (int i = 0; i < vendedoresLength; i++) {
        cout << "Nome: " << vendedores[i].nome << endl;
        cout << "Código: " << vendedores[i].cod << endl;
    }

}

Vendedor readVendedor() {

    Vendedor aux;

    cout << "Digite o nome do vendedor: ";
    getline(cin, aux.nome);

    cout << "Digite o código do vendedor:";
    cin >> aux.cod;

    for (double & venda : aux.vendas) {
        venda = -1;
    }

    return aux;
}

void cadastrarVendedor(Vendedor vendedores[TAM_VENDEDORES], int* vendedoresLength) {

    if (*vendedoresLength >= 4)
        return;

    Vendedor newVendedor = readVendedor();

    for (int i = 0; i < *vendedoresLength; i++) {

        if (vendedores[i].cod == newVendedor.cod) {
            cout << "Código já utilizado\n";
            return;
        }

    }

    vendedores[*vendedoresLength] = newVendedor;
    *vendedoresLength = *vendedoresLength + 1;

}

void cadastrarVenda(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    int aux_cod;
    int aux_mes;
    int aux_valor;

    cout << "Código do vendedor: ";
    cin >> aux_cod;

    cout << "Mês da venda (0-12):";
    cin >> aux_mes;

    cout << "Valor: ";
    cin >> aux_valor;

    for (int i = 0; i < vendedoresLength; ++i) {

        if (vendedores[i].cod == aux_cod) {
            if (vendedores[i].vendas[aux_mes - 1] == -1) {
                vendedores[i].vendas[aux_mes - 1] = aux_valor;
                return;
            } else {
                cout << "Esse vendedor já realizou alguma venda esse mês\n";
            }
        }

    }

    cout << "Código inválido!\n";

}

void consultarVendasPorVendedorEMes(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    int aux_cod;
    int aux_mes;

    cout << "Código do vendedor: ";
    cin >> aux_cod;

    cout << "Mês da venda (0-12):";
    cin >> aux_mes;

    for (int i = 0; i < vendedoresLength; ++i) {
        if (vendedores[i].cod == aux_cod) {
            if (vendedores[i].vendas[aux_mes - 1] != -1) {
                cout << "Vendas no mês: " << vendedores[i].vendas[aux_mes - 1] << endl;
            } else {
                cout << "Esse vendedor não tem vendas esss mês";
            }

            return;
        }

    }

    cout << "Código inválido!\n";

}

void consultarTodasVendasPorVendedor(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    double valor_total = 0;
    int aux_cod;

    cout << "Código do vendedor: ";
    cin >> aux_cod;

    for (int i = 0; i < vendedoresLength; ++i) {

        if (vendedores[i].cod == aux_cod) {

            for (double venda : vendedores[i].vendas) {
                if (venda != -1) {
                    valor_total += venda;
                }
            }

            cout << "Valor: " << valor_total << endl;
            return;

        }

    }

    cout << "Código inválido!\n";

}

void consultarVendedorComMaisVendarPorMes(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    double maiorValorTotal= 0;
    Vendedor maiorVendedor;

    int aux_mes;

    cout << "Mês (0-12):";
    cin >> aux_mes;


    for (int i = 0; i < vendedoresLength; ++i) {

        double aux = 0;

        for (double venda : vendedores[i].vendas) {

            if (venda != -1) {
                aux += venda;
            }

        }

        if (aux > maiorValorTotal) {
            maiorValorTotal = aux;
            maiorVendedor = vendedores[i];
        }

    }

    cout << "Vendedor: " << maiorVendedor.nome << "(" << maiorVendedor.cod << ")" << endl;

}

void consultarMesComMaiorVenda(Vendedor vendedores[TAM_VENDEDORES], int vendedoresLength) {

    int maiorMes;
    double maiorValor = 0;

    for (int i = 0; i < TAM_MESES; ++i) {

        double aux = 0;

        for (int j = 0; j < vendedoresLength; ++j) {
            if(vendedores[j].vendas[i] != -1) {
                aux += vendedores[j].vendas[i];
            }
        }

        if (aux > maiorValor) {
            maiorValor = aux;
            maiorMes = i;
        }

    }

    cout << "Maior mês: " << maiorMes << endl;

}

int main() {

    Vendedor vendedores[TAM_VENDEDORES];
    int vendedoresLength  = 0;

    char op;

    do {

        printMenu();

        cout << "Digite uma opção: ";
        cin >> op;
        getchar();

        switch (op) {
            case 'a':
                cadastrarVendedor(vendedores, &vendedoresLength);
                break;

            case 'b' :
                cadastrarVenda(vendedores, vendedoresLength);
                break;

            case 'c' :
                consultarVendasPorVendedorEMes(vendedores, vendedoresLength);
                break;

            case 'd':
                consultarTodasVendasPorVendedor(vendedores, vendedoresLength);
                break;

            case 'e':
                consultarVendedorComMaisVendarPorMes(vendedores, vendedoresLength);
                break;

            case 'f':
                consultarMesComMaiorVenda(vendedores, vendedoresLength);
                break;

            default:
                cout << "Opção inválida! \n";
                break;
        }

    }while (op != 'g');

}
