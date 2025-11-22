#include <iostream>
#include <locale>
#include <windows.h>

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
					
				MenuCadastros();
				cin>>op2;
				
					switch(op2){
						case 1:
							Cadastrarcliente();
							break;
						case 2:
							Cadastraratendente();
							break;
						case 3:
							Cadastrarfilme();
							break;
						case 4:
							cout<<"\nVoltando ao menu Principal";
							break;			
					}
				
				}while(op!=4);
				
				break;
			
		}
		
	}while(op!=2);	
	
	
	
}