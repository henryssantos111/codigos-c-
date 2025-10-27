#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

using namespace std;
int treino[10], quantidade = 0;

string nome[10];

void Menu(){
	cout<<"\n---SMART HALLS---\n";
	cout<<"(1) Cadastrar Alunoo"<<endl;
	cout<<"(2) Listar frequencia"<<endl;
	cout<<"(3) Sair"<<endl;
}

void cadastrarAluno(){
	if(quantidade > 10){
		cout<<"Limite maximo atingido.."<<endl;
}

		cout<<"\nQual nome do aluno?"<<endl;
		cin.ignore();
		getline(cin, nome[quantidade]);
		cout<<"\nQuantos treinos na semana?"<<endl;
		cin>>treino[quantidade];
		quantidade++;


}

void ListarAlunos(){
	if(quantidade == 0){
		cout<<"Nenhum aluno cadastrado!"<<endl;	
	}
	
	for(int i = 0; i < quantidade; i++){
		cout<<"\nAluno: "<<nome[i];
		cout<< "\nTreino: "<<treino[i]<<endl;
			
		if(treino[i] > 5){
			cout<<"Excelente, Continue assim!"<<endl;
		}else if( treino[i] >=3 && treino[i] <= 4){
			cout<<"Regular, Pode melhorar"<<endl;
		}else {
			cout<<"Frango, está muito baixo!"<<endl;	
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
		cout<<"Escolha uma opção: ";
		cin>>op;
		
		switch(op){
			
			case 1: 
				cadastrarAluno();
				break;
				
			case 2:
				ListarAlunos();
				break;
					
		}
		
	}while(op != 3);
	
	
}