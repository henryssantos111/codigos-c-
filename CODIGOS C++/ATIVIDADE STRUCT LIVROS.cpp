#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;

struct Livro{
	string titulo;
	string autor;
	int ano;
	int estoque;
};

Livro livros[100];
int quantidade = 0;

void Menu(){
	cout<<"\n---Seja bem vindo a Livraria---\n";
	cout<<" 1 - Cadastrar livros"<<endl;
	cout<<" 2 - Listar livros cadastrados"<<endl;
	cout<<" 3 - Registrar empréstimo "<<endl;
	cout<<" 4 - Registrar devolução"<<endl;
	cout<<" 5 - Total de livros em estoque"<<endl;
	cout<<" 6 - Livros com baixo estoque ( Menor que 3)"<<endl;
	cout<<" 7 - Sair do sistema"<<endl;
	cout<<"Informe a Opção: ";
}

void CadastrarL(){
	for(int i = 0; i < 100; i++){
		if(livros[i].titulo.empty()){
			cout<<"\nInforme o Titulo do Livro"<<endl;
			cin.ignore();
			getline(cin,livros[i].titulo);
			cout<<"Informe o autor do livro"<<endl;
			getline(cin,livros[i].autor);
			cout<<"Informe o ano de Publicação"<<endl;
			cin>>livros[i].ano;
			cout<<"Informe a quantidade em estoque"<<endl;
			cin>>livros[i].estoque;
			
			quantidade++;
			
			break;
		}
	}
}

void Listar(){
	if(quantidade == 0){
		cout<<"Nenhum Cadastro"<<endl;
		
	}else {
	
			cout<<"\n---Lista de Livros---\n";
		for (int i = 0; i < quantidade; i++){
			cout<<"\nLivro "<<( i + 1)<<endl;
			cout<<"Titulo: "<<livros[i].titulo<<endl;
			cout<<"Autor: "<<livros[i].autor<<endl;
			cout<<"Ano de Publicação: "<<livros[i].ano<<endl;
			cout<<"Quantidade em estoque: "<<livros[i].estoque<<endl;
		}
		
	}
	
}

void registrarEmprestimo() {
	string nome;
	
	if(quantidade == 0){
		cout<<"\nNenhum Livro cadastrado"<<endl;
		return;
	}
		
		 Listar();
		 
	for (int i = 0; i < quantidade; i++) {
		cout<<"\n\nQual o nome do livro que deseja? "<<endl;
		cin.ignore();
		getline(cin,nome);	
			
		if (nome == livros[i].titulo) {
			if (livros[i].estoque > 0) {
				livros[i].estoque--;
			cout<<"\nLivro emprestado com sucesso!"<<endl;	
			}
		}
	}
}


void registrarDevolucao(){
	string nome;
	
	if(quantidade == 0){
		cout<<"\nNenhum Livro Cadastrado"<<endl;
		return;
	}
		Listar();
		
		for(int i = 0; i < quantidade; i++){
			cout<<"\nQual livro deseja devolver?"<<endl;
			cin.ignore();
			getline(cin,nome);
			
			if(nome == livros[i].titulo){
				if(livros[i].estoque > 0){
					livros[i].estoque++;
					cout<<"Livro Devolvido com sucesso!"<<endl;
				}
			}
		} 
}

void Totalestoque(){
	int total = 0;
	
		for(int i = 0; i < quantidade; i++){
			total += livros[i].estoque;
		}
		
		cout<<"\nTotal em estoque: "<<total<<endl;
}

void Menorestoque(){
	for(int i = 0; i < quantidade; i++){
		if(livros[i].estoque < 3){
			cout<<"\nTitulo: "<<livros[i].titulo<<endl;
			cout<<"Quantidade: "<<livros[i].estoque<<endl;
		}
	}
}



int main(){
	int op;
		SetConsoleOutputCP(CP_UTF8);
    	SetConsoleCP(CP_UTF8);
    	setlocale(LC_ALL, ".UTF-8");
    	
    	do{
    		Menu();
    		cin>>op;
    		
    		switch(op){
    			case 1:
    				CadastrarL();
    				break;
    			case 2:
					Listar();
					break;
				case 3:
					registrarEmprestimo();
					break;	
    			case 4:
					registrarDevolucao();
					break;
				case 5:
					Totalestoque();
					break;
				case 6:
					Menorestoque();
					break;
				case 7:
					cout<<"Encerrando Programa..."<<endl;
					break;	
			}
    		
    		
		}while(op!=7);
	
}