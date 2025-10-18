#include <iostream>
#include <windows.h>
#include <locale>


using namespace std;

string placas[10] = {""}, modelos[10] = {""}, statusOS[10] =  {""};
int ano[10] = {0}, quantidade = 0;

void Menu(){
	cout<<"\n---OFICINA RODOBENS---\n";
	cout<<"1 - Cadastrar Veiculo / nova OS "<<endl;
	cout<<"2 - Listar ordens de serviço"<<endl;
	cout<<"3 - Atualizar Status da OS"<<endl;
	cout<<"4 - Pesquisar veiculo por Placa"<<endl;
	cout<<"5 - Total de Serviços concluidos"<<endl;
	cout<<"6 - OS em Andamento"<<endl;
	cout<<"7 - Sair"<<endl;
}

void Cadastrar(){
	for(int i = 0; i < 10; i++){
		if(placas[i] == "" && modelos[i] == "" && statusOS[i] == "" && ano[i] == 0){
			cout<<"\n---Bem vindo a oficina---"<<endl;
			
			cin.ignore();
			cout<<"\nInforme a placa do Veiculo"<<endl;
			getline(cin, placas[i]);
			cout<<"\nInforme o Modelo do veiculo"<<endl;
			getline(cin, modelos[i]);
			cout<<"\nDigite o Ano de fabricação"<<endl;
			cin>>ano[i];
			
			statusOS[i] = "Em andamento";
			cout<<"\nVeiculo cadastrado com status 'Em andamento'"<<endl;
			
			quantidade++;
			break;
		}
	}
}

void listarOS(){
	if(quantidade == 0){
		cout<<"Sem OS Registradas"<<endl;
		return;
	}
	for(int i = 0; i < quantidade; i++){
		cout<<"\nVeiculo "<<(i + 1)<<endl;
		cout<<"Placa: "<<placas[i]<<endl;
		cout<<"Modelo: "<<modelos[i]<<endl;
		cout<<"Ano: "<<ano[i]<<endl;
		cout<<"Status OS: "<<statusOS[i]<<endl;
	}
}

void atualizarStatus() {
	string placa;
	
    if (quantidade == 0) {
        cout << "Nenhum veiculo cadastrado.\n";
        return;
    }
    cout<<"\nDigite a placa para atualizar: ";
    cin.ignore();
    getline(cin, placa);

    for (int i = 0; i < quantidade; i++) {
        if (placas[i] == placa) {
            if (statusOS[i] != "Em andamento") {
                cout<<"So pode atualizar status de OS em andamento.\n";
                return;
            }

            cout<<"\nEscolha novo status:\n";
            cout<<"\n1 - Concluida\n2 - Cancelada\n";
            
            int opcao;
            cin>>opcao;
            cin.ignore();
            
				if (opcao == 1) {
    				statusOS[i] = "Concluida";
    				cout << "\nStatus atualizado para 'Concluída'.\n";
				}else if (opcao == 2) {
    				statusOS[i] = "Cancelada";
   				 	cout << "\nStatus atualizado para 'Cancelada'.\n";
			    }else {
    				cout << "Opção inválida.\n";
				}
					return;
			}
}

}
			

void pesquisarVeiculo() {
    if (quantidade == 0) {
        cout<<"Nenhum veiculo cadastrado.\n";
        return;
    }

    string placa;
    cout<<"\nDigite a placa para pesquisar: ";
    cin.ignore();
    getline(cin,placa);

    for (int i = 0; i < quantidade; i++) {
        if (placas[i] == placa) {
            cout<<"\nVeiculo encontrado:\n";
            cout<<"Placa: "<<placas[i]<<endl;
            cout<<"Modelo: "<<modelos[i]<<endl;
            cout<<"Ano: "<<ano[i]<<endl;
            cout<<"Status OS: "<<statusOS[i]<<endl;
            return;
        }
    }
    cout<<"\nPlaca nao encontrada.\n";
}

void totalOSconcluida(){
	int total = 0;
		if(quantidade == 0){
		cout<<"\nSem OS Registradas"<<endl;
		return;
		}
		
		for(int i = 0; i < quantidade; i++){
			if(statusOS[i] == "Concluida"){
					total++;
			}
		}	
			cout<<"\nTotal de Serviços concluidos: "<<total<<endl;		
}

void totalOSandamento() {
    bool tem = false;
    cout << "\n--- ORDENS DE SERVIÇO EM ANDAMENTO ---\n";

    for (int i = 0; i < quantidade; i++) {
        if (statusOS[i] == "Em andamento") {
            cout << "\nOS Nº " << (i + 1) << endl;
            cout << "Placa: " << placas[i] << endl;
            cout << "Modelo: " << modelos[i] << endl;
            cout << "Ano: " << ano[i] << endl;
            cout << "Status: " << statusOS[i] << endl;
            tem = true;
        }
    }

    if (!tem)
        cout << "\nNenhuma ordem em andamento.\n";
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
					Cadastrar();
					break;
				case 2:
					listarOS();
					break;
				case 3:
					atualizarStatus();
					break;
				case 4:
					pesquisarVeiculo();
					break;
				case 5:
					totalOSconcluida();		
					break;
				case 6:
					totalOSandamento();		
					break;
				case 7:
					cout<<"\nSaindo do Sistema.."<<endl;
					break;		
			}
		
		}while(op!=7);
}
