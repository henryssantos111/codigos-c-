#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;

struct Produto {
    int id;
    string nome;
    int quantidade;
    float valor;
    string status; 
};

struct Venda {
    int id;
    int idProduto;
    string data;
    int quantidadecomprada;
    float total;
};

Produto produtos[100];
Venda vendas[100];

int qtdProduto = 0;
int qtdVenda = 0;

void Menu() {
    cout<<"\n=== Menu Principal ===\n";
    cout<<"1 - Adicionar Produto\n";
    cout<<"2 - Registrar Venda\n";
    cout<<"3 - Exibir Produto Especifico\n";
    cout<<"4 - Exibir produtos com status 'danificado'\n";
    cout<<"5 - Exibir Produto com maior Quantidade\n";
    cout<<"6 - Alterar Status do Produto para 'valido'\n";
    cout<<"7 - Sair\n";
}

void Cadastrarproduto() {
    if (qtdProduto >= 100) {
        cout<<"\nLimite atingido!";
    }

    cout<<"\n=== Cadastro de Produto ===\n";
    cout<<"ID: ";
    cin>>produtos[qtdProduto].id;

    cin.ignore();
    cout<<"Nome: ";
    getline(cin, produtos[qtdProduto].nome);

    cout<<"Quantidade: ";
    cin>>produtos[qtdProduto].quantidade;
    cout<<"Valor: ";
    cin>>produtos[qtdProduto].valor;

    cin.ignore();
    cout<<"Status: ";
    getline(cin, produtos[qtdProduto].status);

    qtdProduto++;
    cout<<"\nProduto cadastrado com sucesso!\n";
}

void Listarproduto() {
    if (qtdProduto == 0) {
        cout<<"\nSem produtos cadastrados.\n";
    }

    cout<<"\n=== Lista de Produtos ===\n";
    for(int i = 0; i < qtdProduto; i++) {
        cout<<"\nProduto "<<(i + 1)<<endl;
        cout<<"ID: "<<produtos[i].id<<endl;
        cout<<"Nome: "<<produtos[i].nome<<endl;
        cout<<"Quantidade: "<<produtos[i].quantidade<<endl;
        cout<<"Valor: "<<produtos[i].valor<<endl;
        cout<<"Status: "<<produtos[i].status<<endl;
    }
}

void Registrarvenda() {
    if (qtdProduto == 0) {
        cout<<"\nSem produtos para vender!\n";
    }

    cout<<"\n=== Registrar Venda ===\n";
    Listarproduto();

    int idBusca;
    cout<<"\nDigite o ID do produto que deseja vender: ";
    cin>>idBusca;

    int index = -1;
    for(int i = 0; i < qtdProduto; i++) {
        if (produtos[i].id == idBusca) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout<<"\nProduto não encontrado!\n";
    }

    cout<<"Data da venda: ";
    cin.ignore();
    getline(cin, vendas[qtdVenda].data);

    cout<<"Quantidade comprada: ";
    cin>>vendas[qtdVenda].quantidadecomprada;

    if(vendas[qtdVenda].quantidadecomprada > produtos[index].quantidade) {
        cout<<"\nQuantidade insuficiente em estoque!\n";
    }

    produtos[index].quantidade -= vendas[qtdVenda].quantidadecomprada;

    vendas[qtdVenda].id = qtdVenda + 1;
    vendas[qtdVenda].idProduto = produtos[index].id;
    vendas[qtdVenda].total = vendas[qtdVenda].quantidadecomprada * produtos[index].valor;
        

    cout<<"\nVenda registrada com sucesso!";
    cout<<"\nTotal: R$ "<<vendas[qtdVenda].total<<endl;

    qtdVenda++;
}

void ExibirProdutoEspecifico() {
    if (qtdProduto == 0) {
        cout<<"\nSem produtos cadastrados.\n";
    }

    int idBusca;
    cout<<"\nDigite o ID do produto: ";
    cin>>idBusca;

    for (int i = 0; i < qtdProduto; i++) {
        if (produtos[i].id == idBusca) {
            cout<<"\nProduto encontrado:\n";
            cout<<"ID: "<<produtos[i].id<<endl;
            cout<<"Nome: "<<produtos[i].nome<<endl;
            cout<<"Quantidade: "<<produtos[i].quantidade<<endl;
            cout<<"Valor: "<<produtos[i].valor<<endl;
            cout<<"Status: "<<produtos[i].status<<endl;
        }
    }

    cout<<"\nProduto não encontrado!\n";
}

void ExibirDanificados() {
    cout<<"\n=== Produtos Danificados ===\n";
    bool achou = false;

    for (int i = 0; i < qtdProduto; i++) {
        if (produtos[i].status == "danificado") {
            cout<<"\nID: "<<produtos[i].id<<endl;
            cout<<"Nome: "<<produtos[i].nome<<endl;
            cout<<"Quantidade: "<<produtos[i].quantidade<<endl;
            cout<<"Valor: "<<produtos[i].valor<<endl;
            achou = true;
        }
    }

    if (!achou)
        cout<<"Nenhum produto danificado encontrado!\n";
}

void ProdutoMaiorQuantidade() {
    if (qtdProduto == 0) {
        cout<<"\nSem produtos cadastrados!";
    }

    int maior = 0;
    for(int i = 1; i < qtdProduto; i++) {
        if (produtos[i].quantidade > produtos[maior].quantidade) {
            maior = i;
        }
    }

    cout<<"\n=== Produto com maior quantidade ===\n";
    cout<<"ID: "<<produtos[maior].id<<endl;
    cout<<"Nome: "<<produtos[maior].nome<<endl;
    cout<<"Quantidade: "<<produtos[maior].quantidade<<endl;
}

void AlterarStatus() {
    int idBusca;
    cout<<"\nDigite o ID do produto para validar: ";
    cin>>idBusca;

    for (int i = 0; i < qtdProduto; i++) {
        if (produtos[i].id == idBusca) {
            produtos[i].status = "valido";
            cout<<"Status alterado para 'valido'!\n";
        }
    }

    cout<<"Produto não encontrado!\n";
}

int main() {
    int op;
    
	SetConsoleOutputCP(65001);
	
    do{
        Menu();
        cout<<"\nEscolha: ";
        cin>>op;

        switch (op) {
        case 1: 
			Cadastrarproduto();
			break;
        case 2: 
			Registrarvenda(); 
			break;
        case 3:
			ExibirProdutoEspecifico(); 
			break;
        case 4: 
			ExibirDanificados(); 
			break;
        case 5:
			ProdutoMaiorQuantidade(); 
			break;
        case 6: 
			AlterarStatus(); 
			break;
        case 7: 
			cout<<"\nSaindo...\n";
		    break;
		}
	}while(op!=7);
	
}
