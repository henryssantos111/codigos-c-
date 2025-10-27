#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;

string nome[10] = {""};
int frequencia[10] = {0}, quantidade = 0;

void Menu(){
	cout<<"\n---MENU ACADEMIA---\n";
	cout<<"1 - Cadastrar Aluno"<<endl;
	cout<<"2 - Listar Frequencia"<<endl;
	cout<<"3 - Sair"<<endl;
}

void CadastrarA(){
	for(int i = 0; i < 10; i++){
		if(nome[i] == "" && frequencia[i] == 0){
			cout<<"\nQual nome do Aluno? "<<endl;
			cin.ignore();
			getline(cin,nome[i]);
			cout<<"\nQuantas vezes treinou na semana?"<<endl;
			cin>>frequencia[i];
			quantidade++;
			break;
		}
	}
}

string DesempenhoA(int i){
    if (frequencia[i] >= 5) {
        return "Excelente";
    } else if (frequencia[i] > 3) {
        return "Regular";
    } else {
        return "Horrivel";
    }
}

void ListarF(int n){
	if(quantidade == 0){
		cout<<"Nenhum Aluno cadastrado"<<endl;
		return;
	}else {
		cout<<"\n---Lista de Alunos---\n";
		for(int i = 0; i < n; i++){
			cout<<(i + 1)<<" Aluno - "<<nome[i]<<" / Frequencia - "<<frequencia[i]<<" Vezes"<<" / Situação - "<<DesempenhoA(i)<<endl;
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
    		cout<<"Informe uma opção: ";
    		cin>>op;
    		
    		switch(op){
    			
    			case 1: 
    				CadastrarA();
    				break;
    			case 2:
					ListarF(quantidade);
					break;
				case 3:
					cout<<"Saindo do sistema..."<<endl;
					break;		
			}
		
		}while(op != 3);
	
	
}