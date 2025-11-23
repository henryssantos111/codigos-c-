#include <iostream>
#include <locale>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Cliente{
	string nome;
	string cpf;
	int idade;	
};

struct Atendente{
	string nome;
	string cpf;		
};

struct Filme{
	string titulo;
	int estoque;
	float precoLocacao;
};

struct Locacao{
	string cliente;
	string atendente;
	string filme;
	int dias;
	float total;	
};

Cliente clientes[100];
Atendente atendentes[100];
Filme filmes[100];
Locacao locacoes[100];

int qtdCliente = 0;
int qtdAtendente = 0;
int qtdFilme = 0;
int qtdLocacao = 0;

void Menu(){
	cout<<"\n=== Menu Principal ===\n";
	cout<<"1 - Cadastros"<<endl;
	cout<<"2 - Locações"<<endl;
	cout<<"3 - Sair"<<endl;
	cout<<"Informe uma opção: ";
}

void MenuCadastros(){
	cout<<"\n=== Menu Cadastros ===\n";
	cout<<"1 - Cadastrar Cliente"<<endl;
	cout<<"2 - Cadastrar Filme"<<endl;
	cout<<"3 - Cadastrar Atendente"<<endl;
	cout<<"4 - Voltar ao menu Principal"<<endl;
	cout<<"\n Informe uma opção: "<<endl;
}

void Cadastrarcliente(){
	if(qtdCliente >= 100){
		cout<<"\nLimite atingido!"<<endl;
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
		
		cout<<"\nCliente Cadastrado!"<<endl;
}

void Listarcliente(){
	if(qtdCliente == 0){
		cout<<"\nSem clientes cadastrados!"<<endl;
	}
	
	cout<<"\n=== Lista de Clientes ===\n";
		for(int i = 0; i < qtdCliente; i++){
			cout<<"\n"<<(i + 1)<<" Cliente"<<endl;
			cout<<"Nome - "<<clientes[i].nome<<endl;
			cout<<"CPF - "<<clientes[i].cpf<<endl;
			cout<<"Idade - "<<clientes[i].idade<<endl;
		}
}

void Cadastraratendente(){
	if(qtdAtendente >= 100){
		cout<<"\nLimite atingido!"<<endl;
	}
	
		cout<<"\n=== Cadastro de Atendentes ===\n";
		
		cin.ignore();
		cout<<"Nome: ";
		getline(cin, atendentes[qtdAtendente].nome);
		cout<<"CPF: ";
		getline(cin, atendentes[qtdAtendente].cpf);
		
		qtdAtendente++;
		
		cout<<"\nAtendente cadastrado!"<<endl;
}

void Listaratendente(){
	if(qtdAtendente == 0){
		cout<<"\nSem atendente cadastrados!"<<endl;
	}
	
		cout<<"\n=== Lista de Atendentes ===\n";
			for(int i = 0; i < qtdAtendente; i++){
				cout<<"\n"<<(i + 1)<<" Atendente"<<endl;
				cout<<"Nome - "<<atendentes[i].nome<<endl;
				cout<<"CPF - "<<atendentes[i].cpf<<endl;
			}
}

void Cadastrarfilme(){
	if(qtdFilme >= 100){
		cout<<"\nLimite atingido!"<<endl;
	}
	
		cout<<"\n=== Cadastro de Filmes ===\n";
		cin.ignore();
		cout<<"Titulo: ";
		getline(cin, filmes[qtdFilme].titulo);
		cout<<"Estoque: ";
		cin>>filmes[qtdFilme].estoque;
		cout<<"Preço: R$ ";
		cin>>filmes[qtdFilme].precoLocacao;
		
		qtdFilme++;
		
		cout<<"\nFilme cadastrado!"<<endl;
}

void Listarfilme(){
	if(qtdFilme == 0){
		cout<<"\nSem filmes cadastrados!"<<endl;
	}
		cout<<"\n=== Lista de filmes ===\n";
			for(int i = 0; i < qtdFilme; i++){
				cout<<"\n"<<(i + 1)<<" Filme"<<endl;
				cout<<"Título - "<<filmes[i].titulo<<endl;
				cout<<"Estoque - "<<filmes[i].estoque<<endl;
				cout<<"Preço Locação - "<<fixed<<setprecision(2)<<filmes[i].precoLocacao<<endl;
			}
}

void Realizarlocacao(){
	int opCliente = 0;
	int opAtendente = 0;
	int opFilme = 0;
	int opDias = 0;
	
		if(qtdCliente == 0){
			cout<<"\nSem clientes cadastrados!"<<endl;
		}
		if(qtdAtendente == 0){
			cout<<"\nSem atendentes cadastrados!"<<endl;
		}
		if(qtdFilme == 0){
			cout<<"\nSem filmes cadastrados!"<<endl;
		}
		
		cout<<"\n=== Realizar Locação ===\n";
		
		cout<<"\nSelecione o Cliente: "<<endl;
		Listarcliente();
		cin>>opCliente;
		
		cout<<"\nSelecione o Atendente: "<<endl;
		Listaratendente();
		cin>>opAtendente;
		
		cout<<"\nSelecione o Filme: "<<endl;
		Listarfilme();
		cin>>opFilme;
		
		cout<<"\nPor quantos dias deseja locar? "<<endl;
		cin>>opDias;
		
		if(filmes[opFilme - 1].estoque <= 0 ){
			cout<<"\nEstoque insuficiente!"<<endl;
		}
		
		float total = filmes[opFilme - 1].precoLocacao * opDias;
		
		locacoes[qtdLocacao].cliente = clientes[opCliente - 1].nome;
		locacoes[qtdLocacao].atendente = atendentes[opAtendente - 1].nome;
		locacoes[qtdLocacao].filme = filmes[opFilme - 1].titulo;
		locacoes[qtdLocacao].dias = opDias;
		locacoes[qtdLocacao].total = total;
		
		qtdLocacao++;
		
		filmes[opFilme - 1].estoque--;
		
		cout<<"\nLocacão realizada com sucesso!"<<endl;
		cout<<"\nTotal: R$"<<fixed<<setprecision(2)<<total<<endl;
}

int main(){
	int op = 0;
	int op2 = 0;
	
	SetConsoleOutputCP(65001);
	
	
	do{
		Menu();
		cin>>op;
		
		switch(op){
			case 1:
				do{
					
				MenuCadastros();
				cin>>op2;
				
					switch(op2){
						case 1:
							Cadastrarcliente();
							break;
						case 2:
							Cadastrarfilme();
							break;
						case 3:
							Cadastraratendente();
							break;
						case 4:
							cout<<"\nVoltando ao menu Principal"<<endl;
							break;			
					}
				
				}while(op2!=4);
				
				break;
			
			case 2:
				Realizarlocacao();
				break;
			
			case 3:
				cout<<"\nSaindo do sistema..."<<endl;
				break;	
			
		}
		
	}while(op!=3);	
}