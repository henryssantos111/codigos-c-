#include <iostream>
#include <locale>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Cliente{
	string nome;
	string cpf;
	string telefone;
};

struct Pet{
	string nome;
	string especie;
};

struct Servico{
	string tipo;
	float valor;
};

struct Atendimento{
	string cliente;
	string pet;
	string servico;
	float total;	
};

Cliente clientes[100];
Pet pets[100];
Servico servicos[100];
Atendimento atendimentos[100];

int qtdCliente = 0;
int qtdPet = 0;
int qtdServico = 0;
int qtdAtendimento = 0;

void Menu(){
	cout<<"\n=== BEM VINDO A PETZ ===\n";
	cout<<"\n=== Menu Principal ===\n";
	cout<<"1 - Cadastros"<<endl;
	cout<<"2 - Atendimento"<<endl;
	cout<<"3 - Sair"<<endl;
	cout<<"\n informe uma opção: ";
}

void Menucadastro(){
	
	cout<<"\n=== Menu Cadastros ===\n";
	cout<<"1 - Cadastrar Cliente"<<endl;
	cout<<"2 - Cadastrar Pet"<<endl;
	cout<<"3 - Cadastrar Serviço"<<endl;
	cout<<"4 - Voltar ao Menu Principal"<<endl;
	cout<<"\n Informe uma opção: ";
}

void Cadastrarcliente(){
	if(qtdCliente >=100){
		cout<<"\nMaximo de cadastros atingidos!"<<endl;
	}
	
		cout<<"\n=== Cadastro de Clientes ===\n";
		
		cin.ignore();
		cout<<"Nome: ";
		getline(cin, clientes[qtdCliente].nome);
		cout<<"CPF: ";
		getline(cin, clientes[qtdCliente].cpf);
		cout<<"Telefone - ";
		getline(cin, clientes[qtdCliente].telefone);
		
		qtdCliente++;
		
		cout<<"\nCliente cadastrado com sucesso!"<<endl;
}

void Listarcliente(){
	if(qtdCliente == 0){
		cout<<"\nSem clientes cadastrado!"<<endl;
	}
	
		cout<<"\n=== Lista de Clientes ===\n";
			for(int i = 0; i < qtdCliente; i++){
				cout<<"\n"<<(i+1)<<" Cliente"<<endl;
				cout<<"Nome - "<<clientes[i].nome<<endl;
				cout<<"CPF - "<<clientes[i].cpf<<endl;
				cout<<"Telefone - "<<clientes[i].telefone<<endl;
			}
		
}

void Cadastrarpet(){
	if(qtdPet >= 100){
		cout<<"\nMaximo de cadastros atingidos!"<<endl;
	}
		cout<<"\n=== Cadastro de Pet ===\n";
		
		cin.ignore();
		cout<<"Nome: ";
		getline(cin, pets[qtdPet].nome);
		cout<<"Especie: ";
		getline(cin, pets[qtdPet].especie);
		
		qtdPet++;
		
		cout<<"\nPet cadastrado com sucesso!"<<endl;	
}

void Listarpet(){
	if(qtdPet == 0){
		cout<<"\nSem Pets Cadastrados"<<endl;
	}
	
		cout<<"\n=== Lista de Pets ===\n";
			for(int i = 0; i < qtdPet; i++){
				cout<<"\n"<<(i + 1)<<" Pet"<<endl;
				cout<<"Nome - "<<pets[i].nome<<endl;
				cout<<"Especie - "<<pets[i].especie<<endl;
			}
}

void Cadastrarservico(){
	if(qtdServico >= 100){
		cout<<"\nMaximo de cadastrado atingido!"<<endl;
	}
	
		cout<<"\n=== Cadastro de Serviço ===\n";
		
		cin.ignore();
		cout<<"Tipo - ";
		getline(cin, servicos[qtdServico].tipo);
		cout<<"Valor - ";
		cin>>servicos[qtdServico].valor;
		
		qtdServico++;
		
		cout<<"\nServiço cadastrado!"<<endl;
}

void Listarservico(){
	if(qtdServico == 0){
		cout<<"\nSem serviço cadastrados!"<<endl;
	}
	
		cout<<"\n===Lista de Serviços ===\n";
			for(int i = 0; i < qtdServico; i++){
				cout<<"Tipo - "<<servicos[i].tipo<<" || Valor: R$"<<fixed<<setprecision(2)<<servicos[i].valor<<endl;
			}
}

void Realizaratendimento(){
	int opCliente = 0;
	int opPet = 0;
	int opServico = 0;
	float total;
	
	if(qtdCliente == 0){
		cout<<"\n Sem clientes cadastrados!"<<endl;
	}
	if(qtdPet == 0){
		cout<<"\nSem Pets cadastrados!"<<endl;
	}
	if(qtdServico == 0){
		cout<<"\nSem Serviços cadastrados!"<<endl;
	}
	
		cout<<"\n=== Realizar Atendimento ===\n";
		
		cout<<"\nSelecione o cliente: "<<endl;
		Listarcliente();
		cin>>opCliente;
		
		cout<<"\nSelecione o Pet do cliente: "<<endl;
		Listarpet();
		cin>>opPet;
		
		cout<<"\nSelecione o Serviço que deseja fazer: "<<endl;
		Listarservico();
		cin>>opServico;
		
		total = servicos[opServico - 1].valor;
		
		atendimentos[qtdAtendimento].cliente = clientes[opCliente - 1].nome;
		atendimentos[qtdAtendimento].pet = pets[opPet - 1].nome;
		atendimentos[qtdAtendimento].servico = servicos[opServico - 1].tipo;
		atendimentos[qtdAtendimento].total = total;
		
		qtdAtendimento++;
		
		cout<<"\nAtendimento realizado com sucesso!!"<<endl;
		cout<<"Total: R$"<<fixed<<setprecision(2)<<total<<endl;
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
					
						Menucadastro();
						cin>>op2;
						
						switch(op2){
							case 1:
								Cadastrarcliente();
								Listarcliente();
								break;
							case 2:
								Cadastrarpet();
								Listarpet();
								break;
							case 3:
								Cadastrarservico();
								Listarservico();
								break;
							case 4: 			
								cout<<"Voltando ao Menu Principal"<<endl;
						}
						
					}while(op2!=4);
					break;
					
				case 2:
					Realizaratendimento();
					break;
					
				case 3: 
					cout<<"Saindo do PETZ..."<<endl;
					break;			
			}
			
			
		}while(op!=3);
}