#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;

struct Aluno{
	string aluno;
	int idade;
	int frequencia;
};

Aluno alunos[100];
int quantidade = 0;

void Menu(){
	cout<<"\n---Academia Lion Fitness---\n";
	cout<<"1 - Cadastrar Aluno"<<endl;
	cout<<"2 - Listar Frequencia"<<endl;
	cout<<"3 - Sair"<<endl;
	cout<<"Informe uma opção: ";
}

void CadastrarA(){
	for(int i = 0; i < 100; i++){
		if(alunos[i].aluno.empty()){
			cout<<"\nQual nome do Aluno?"<<endl;
			cin.ignore();
			getline(cin,alunos[i].aluno);
			cout<<"Qual a idade do aluno?"<<endl;
			cin>>alunos[i].idade;
			cout<<"Quantas vezes o aluno treinou na semana?"<<endl;
			cin>>alunos[i].frequencia;
			
			quantidade++;
			break;			
		}
	}
}

string Desempenho(int i){
	if(alunos[i].frequencia >= 5){
		return "Excelente";
	}else if(alunos[i].frequencia > 3){
		return "Regular";
	}else {
		return "Horrivel";
	}
}

void ListarF(){
	if(quantidade ==0){
		cout<<"\nNenhum aluno cadastrado"<<endl;
			return;
	}else {
		cout<<"\n---Lista de Alunos da Lion Fitness---\n";
			for(int i = 0; i < quantidade; i++){
				cout<<"\n"<<(i + 1)<<" Aluno - "<<alunos[i].aluno<<endl;
				cout<<"Idade - "<<alunos[i].idade<<endl;
				cout<<"Frequencia - "<<alunos[i].frequencia<<endl;
				cout<<"Desempenho - "<<Desempenho(i)<<endl;
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
    			CadastrarA();
    			break;
    		case 2:
				ListarF();
				break;
			case 3:
				cout<<"Saindo do Programa..."<<endl;
				break;			
		}
	}while(op!=3);
}