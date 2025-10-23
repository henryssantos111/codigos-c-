#include <iostream>
#include <locale>
#include <windows.h>


using namespace std;

struct Aluno{
	string nome;
	float av1;
	float av2;
	float media;
	string situacao;
	
};

Aluno alunos[100];
int quantidade = 0;
 

void Menu(){
	cout<<"\n---Escola Senai---\n";
	cout<<"1 - Adicionar Aluno"<<endl;
	cout<<"2 - Exibir Média e Situação do Aluno"<<endl;
	cout<<"3 - Sair "<<endl;
	cout<<"Informe uma opção: ";
}

void Situacao(){
	for(int i = 0; i < quantidade; i++){
		alunos[i].media = (alunos[i].av1 + alunos[i].av2) / 2;
		
		if(alunos[i].media >= 7){
			alunos[i].situacao = "Aprovado!";
		}else if (alunos[i].media >= 5 && alunos[i].media <=6.9){
			alunos[i].situacao = "Em Recuperação!";
		}else {
			alunos[i].situacao = "Aluno Reprovado!";
		}
	}
	
}



void Adicionar(){
	if (quantidade < 100){
		cout<<"\nDigite o Nome do Aluno"<<endl;
		cin.ignore();
		getline(cin, alunos[quantidade].nome);
		cout<<"\nDigite a nota da AV1"<<endl;
		cin>>alunos[quantidade].av1;
		cout<<"\nDigite a nota da AV2"<<endl;
		cin>>alunos[quantidade].av2;
		
		quantidade++;
		
		Situacao();
		
		cout<<"\nAluno Cadastrado com sucesso!!\n";
	}else {
		cout<<"\nLimite de Alunos atingidos\n";
	}
}

void exibirAlunos(){
	if(quantidade == 0){
		cout<<"\nNenhum aluno Cadastrado!"<<endl;
	}else {
		Situacao();
		
		cout<<"\n---Lista de Alunos---\n";
		for(int i = 0; i < quantidade; i++){
			cout<<"\nAluno "<<(i + 1)<<": "<<alunos[i].nome<<endl;
			cout<<"AV1: "<<alunos[i].av1<<endl;
			cout<<"AV2: "<<alunos[i].av2<<endl;
			cout<<"Média: "<<alunos[i].media<<endl;
			cout<<"Situação: "<<alunos[i].situacao<<endl;
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
				Adicionar();
				break;
			case 2:
				exibirAlunos();
				break;
			case 3:
				cout<<"\nEncerrando o Programa..."<<endl;		
		}    	
	}while(op != 3 );
	
}