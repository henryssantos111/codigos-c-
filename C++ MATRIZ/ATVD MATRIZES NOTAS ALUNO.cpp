#include <iostream>
#include <locale>
#include <iomanip>
#include <windows.h>

using namespace std;

double alunos[3][4] = {0}; 


void Menu() {
    cout<<"\n--- Menu Principal ---\n";
    cout<<"1. Adicionar Notas (AV1, AV2, AV3)\n";
    cout<<"2. Exibir Notas e Médias por Linhas\n";
    cout<<"3. Exibir a Maior Média\n";
    cout<<"4. Exibir a Menor Média\n";
    cout<<"5. Exibir Alunos Aprovados (Média >= 7)\n";
    cout<<"6. Exibir Alunos Reprovados (Média < 7)\n";
    cout<<"7. Sair\n";
    cout<<"Escolha uma opção: ";
}

void adicionarNotas() {
    for (int i = 0; i < 3; i++) {
        cout<<"\nAluno "<<i + 1<<":\n";
        for (int j = 0; j < 3; j++) {
            cout<<"Digite a nota da AV"<<j + 1<<": ";
            cin>>alunos[i][j];
        }
        alunos[i][3] = (alunos[i][0] + alunos[i][1] + alunos[i][2]) / 3; 
    }
}

void exibirNotas() {
    cout<<"\n--- Notas e Médias ---\n";
    for (int i = 0; i < 3; i++) {
        cout<<"Aluno "<<i + 1<<": ";
        cout<<fixed<<setprecision(2);
        cout<<"AV1 = " <<alunos[i][0]<<" ";
        cout<<"AV2 = " <<alunos[i][1]<<" ";
        cout<<"AV3 = " <<alunos[i][2]<<" ";
        cout<<"Média = "<<alunos[i][3]<<endl;
    }
}

void maiorMedia() {
    double maior = alunos[0][3];
    int aluno = 0;
    for (int i = 1; i < 3; i++) {
        if (alunos[i][3] > maior) {
            maior = alunos[i][3];
            aluno = i;
        }
    }
    cout<<"\nMaior média: Aluno "<<aluno + 1<<" com média "<<maior<<endl;
}

void menorMedia() {
    double menor = alunos[0][3];
    int aluno = 0;
    for (int i = 1; i < 3; i++) {
        if (alunos[i][3] < menor) {
            menor = alunos[i][3];
            aluno = i;
        }
    }
    cout<<"\nMenor média: Aluno "<<aluno + 1<<" com média "<<menor<< endl;
}

void aprovados() {
    cout<<"\n--- Alunos Aprovados ---\n";
    bool nenhum = true;
    for (int i = 0; i < 3; i++) {
        if (alunos[i][3] >= 7) {
            cout<<"Aluno "<< i + 1<<" - Média: "<<alunos[i][3]<<endl;
            nenhum = false;
        }
    }
    if(nenhum) cout<<"Nenhum aluno aprovado.\n";
}

void reprovados() {
    cout << "\n--- Alunos Reprovados ---\n";
    bool nenhum = true;
    for (int i = 0; i < 3; i++) {
        if (alunos[i][3] < 7) {
            cout << "Aluno " << i + 1 << " - Média: " << alunos[i][3] << endl;
            nenhum = false;
        }
    }
    if(nenhum) cout<<"Nenhum aluno reprovado.\n";
}

int main() {
   	SetConsoleOutputCP(65001);

    int op;
    
    do{
        Menu();
        cin>>op;

        switch(op){
            case 1:
			 	adicionarNotas();
			 	 break;
            case 2: 
				exibirNotas(); 
				break;
            case 3: 
				maiorMedia();
				 break;
            case 4:	
				menorMedia(); 
				break;
            case 5: 	
				aprovados(); 
				break;
            case 6: 
				reprovados(); 
				break;
            case 7: 
				cout<<"\nEncerrando programa...\n"; 
				break;
        }

    }while (op!=7);
}
