#include <iostream>

using namespace std;

struct Aluno {
	string nome;
	double av1;
	double av2;
	double media;
	string situacao;
};

Aluno alunos[10];
int quantidade = 0;

void menu() {
	cout<<"Boletin SENAI"<<endl;
	cout<<"1. Cadastrar"<<endl;
	cout<<"2. Gerar Media"<<endl;
	cout<<"3. Gerar Situacao"<<endl;
	cout<<"4. Sair"<<endl;
}

void add() {
	for (int i = 0; i < 10; i++) {
		if (alunos[i].nome.empty()) {
			cout<<"Informe o nome do aluno"<<endl;
			cin>>alunos[i].nome;
			cout<<"Informe a AV1"<<endl;
			cin>>alunos[i].av1;
			cout<<"Informe o AV2"<<endl;
			cin>>alunos[i].av2;
		
			quantidade++;
		
			break;
	}
		}
}

void exibir() {
	for (int i = 0; i < quantidade; i++) {
		cout<<"Nome: "<<alunos[i].nome
		<<" AV1: "<<alunos[i].av1
		<<" AV2: "<<alunos[i].av2
		<<" Media: "<<alunos[i].media
		<<" Situacao: "<<alunos[i].situacao<<endl;
	}
}

double calcularMedia(double av1, double av2) {
	return (av1 + av2) / 2;
}

void addMedia() {
	for (int i = 0; i < quantidade; i++) {
		alunos[i].media = calcularMedia(alunos[i].av1, alunos[i].av2);
	}
}

string validarSituacao(double media) {
	if (media >= 7) {
		return "Aprovado";
	}else if (media >= 5) {
		return "Recuperacao";
	}else {
		return "Reprovado";
	}
}

void registrarSituacao() {
	for (int i = 0; i < quantidade; i++) {
		alunos[i].situacao = validarSituacao(alunos[i].media);
	}
}

int main() {
	int op = 0;
		do {
			menu();
			cout<<"Informe a opcao desejada:"<<endl;
			cin>>op;
		
			switch (op) {
				case 1:
					add();
					break;
				case 2:
					addMedia();
					break;
				case 3:
					registrarSituacao();
					exibir();
					break;
			}
		
		}while (op != 4);
	

}
