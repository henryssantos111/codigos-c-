#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;

struct Cliente {
	string nome;
	string cpf;
	int  idade;
};

struct Vendedor {
	string nome;
	string cpf;	
};

struct Produto {
	string nome;
	int estoque;
	float preco;
};

Cliente clientes[100];
Vendedor vendedores[100];
Produto produtos[100];

int qtdCliente = 0;
int qtdVendedor = 0;
int qtdProduto = 0;

void Menu(){
	cout<<"\n---Menu Principal---\n";
	cout<<"1 - Cadastros"<<endl;
	cout<<"2 - Vendas"<<endl;
	cout<<"3 - Relatorios"<<endl;
	cout<<"4 - Sair"<<endl;
	cout<<"Informe uma opcão: ";
}

void Menucadastros(){
	cout<<"\n---Menu Cadastros---\n";
	cout<<"1. Cadastrar Cliente"<<endl;
	cout<<"2. Cadastrar Produto"<<endl;
	cout<<"3. Cadastrar Vendedor"<<endl;
	cout<<"4. Menu Principal"<<endl;
	cout<<"Informe uma opção: "<<endl;
}

void Menurelatorio(){
	cout<<"\n=== Menu Relatorio ===\n";
	cout<<"1. Exibir o produto mais vendido, quantidade e total"<<endl;
	cout<<"2. Exibir o vendedor que mais vendeu, e total vendido"<<endl; 
	cout<<"3. Exibir a maior venda"<<endl;
	cout<<"4. Exibir a menor venda"<<endl;
	cout<<"5. Exibir o total das vendas"<<endl;
	cout<<"6. Menu Principal"<<endl;
}

void Cadastrarcliente(){
	if(qtdCliente >= 100){
		cout<<"Limite de 100 clientes atingidos!\n";
	}
	
	cout<<"\n=== Cadastro de Clientes ===\n";
	cin.ignore();
	cout<<"Nome: ";
	getline(cin, clientes[qtdCliente].nome);
	cout<<"CPF: ";
	getline(cin, clientes[qtdCliente].cpf);
	cout<<"Idade: ";
	cin>>clientes[qtdCliente].idade;
	
	qtdCliente++;
	
	cout<<"\nCliente cadastrado com sucesso!"<<endl;
}

void Cadastrarproduto(){
	if(qtdProduto >= 100){
		cout<<"\nLimite de 100 Produtos atingidos!\n";
	}
	
	cout<<"\n=== Cadastro de Produto ===\n";
	cout<<"Nome: ";
	cin.ignore();
	getline(cin, produtos[qtdProduto].nome);
	cout<<"Estoque: ";
	cin>>produtos[qtdProduto].estoque;
	cout<<"Preço: ";
	cin>>produtos[qtdProduto].preco;
	
	qtdProduto++;
	
	cout<<"\nProduto cadastrado com sucesso!"<<endl;
}

void Listarproduto(){
	if(qtdProduto == 0){
		cout<<"Nenhum Produto registrado.\n";
	}
	
	cout<<"\n=== Lista de Produtos ===\n";
		for(int i = 0; i < qtdProduto; i++){
			cout<<"\n"<<(i + 1)<<" Produto"<<endl;
			cout<<"Nome - "<<produtos[i].nome<<endl;
			cout<<"Estoque - "<<produtos[i].estoque<<endl;
			cout<<"Preço - "<<produtos[i].preco<<endl;
		}	
}

void Cadastrarvendedor(){
	if(qtdVendedor >= 100){
		cout<<"\nLimite de 100 Vendedores atingidos!\n";
	}
	
	cout<<"\n=== Cadastro de Vendedor ===\n";
	cout<<"Nome: ";
	cin.ignore();
	getline(cin, vendedores[qtdVendedor].nome);
	cout<<"CPF: ";
	getline(cin, vendedores[qtdVendedor].cpf);
	
	qtdVendedor++;
	
	cout<<"\nProduto cadastrado com Sucesso!"<<endl;
}

void Listarvendedor(){
	if(qtdVendedor ==0){
		
	}
	
	cout<<"\n=== Lista de Vendedores ===\n";
		for(int i = 0; i < qtdVendedor; i++){
			cout<<"\n"<<(i + 1)<<" Vendedor"<<endl;
			cout<<"Nome - "<<vendedores[i].nome<<endl;
		}
}

void Realizarvenda(){
	int opvendedor;
	int opproduto;
	int qtd;
	float valor;
	
	if(qtdProduto){
		cout<<"\nSem produtos para vender"<<endl;
	}	
		cout<<"\nQual funcionario está atendendo você?"<<endl;
			
			Listarvendedor();
			cin>>opvendedor;
			
			Listarproduto();
			
			cout<<"\nDigite o Produto que deseja vender?"<<endl;
			cin>>opproduto;
			cout<<"Qual a quantidade do produto? "<<endl;
			cin>>qtd;
			cout<<"Qual valor do produto? "<<endl;
			cin>>valor;		
}


int main(){
	int op;	
	int op2;
	
	SetConsoleOutputCP(65001);
	
	do{
		Menu();
		cin>>op;
		
		switch(op){
			case 1:
				do{
				Menucadastros();
				cin>>op2;
				
					switch(op2){
						case 1: 
							Cadastrarcliente();
							break;
						case 2:
							Cadastrarproduto();
							break;
						case 3:
							Cadastrarvendedor();
							break;
						case 4:
							cout<<"Voltando ao menu Principal...\n"<<endl;
							break;		
						}
				
					break;
					
				}while(op2!=4);
			break;
				
				
		}
		
	}while(op!=2);
	
}