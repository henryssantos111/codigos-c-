#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <iomanip>
#include <sstream> 

using namespace std;

string produtos[100];
float precos[100];
int quantidade = 0; 


void cadastrarProdutos(int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nDigite o nome do produto " << (quantidade + 1) << ": ";
        cin.ignore(); 
        getline(cin, produtos[quantidade]);

        cout << "Digite o preço do produto: R$ ";
        cin >> precos[quantidade];

        quantidade++;
    }
    cout << "\nProdutos cadastrados com sucesso!\n";
}


void listarProdutos(int n) {
    if (n == 0) {
        cout << "\nNenhum produto cadastrado!\n";
        return;
    }
    cout << "\n===== LISTA DE PRODUTOS =====\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << " - " << produtos[i]
             << " | R$ " << fixed << setprecision(2) << precos[i] << endl;
    }
}


float calcularTotal(int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += precos[i];
    }
    return soma;
}


string produtoMaisCaro(int n) {
    if (n == 0) return "Nenhum produto cadastrado!";
    int Maior = 0;
    for (int i = 1; i < n; i++) {
        if (precos[i] > precos[Maior]) {
            Maior = i;
        }
    }

    ostringstream ss;
    ss<<fixed<<setprecision(2)<<precos[Maior];

    return produtos[Maior] + " (R$ " + ss.str() + ")";
}


string produtoMaisBarato(int n) {
    if (n == 0) return "Nenhum produto cadastrado!";
    int Menor = 0;
    for (int i = 1; i < n; i++) {
        if (precos[i] < precos[Menor]) {
            Menor = i;
        }
    }

    ostringstream ss;
    ss<<fixed<<setprecision(2)<<precos[Menor];

    return produtos[Menor] + " (R$ " + ss.str() + ")";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int opcao, n;

    do {
        cout<< "\n====== MENU SISTEMA DE COMPRAS ======\n";
        cout<< "1 - Cadastrar produtos\n";
        cout<< "2 - Listar produtos\n";
        cout<< "3 - Calcular valor total\n";
        cout<< "4 - Mostrar produto mais caro\n";
        cout<< "5 - Mostrar produto mais barato\n";
        cout<< "0 - Sair\n";
        cout<< "Escolha uma opção: ";
        cin>>opcao;

        switch (opcao) {
            case 1:
                cout<<"\nQuantos produtos deseja cadastrar? ";
                cin>>n;
                cadastrarProdutos(n);
                break;

            case 2:
                listarProdutos(quantidade);
                break;

            case 3:
                cout<<"\nValor total dos produtos: R$ "<<fixed<<setprecision(2)<<calcularTotal(quantidade)<<endl;
                break;

            case 4:
                cout<<"\nProduto mais caro: "<<produtoMaisCaro(quantidade)<<endl;
                break;

            case 5:
                cout<<"\nProduto mais barato: "<<produtoMaisBarato(quantidade)<<endl;
                break;

            case 0:
                cout<<"\nSaindo do sistema..."<<endl;
                break;

            default:
                cout << "\nOpção inválida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}
