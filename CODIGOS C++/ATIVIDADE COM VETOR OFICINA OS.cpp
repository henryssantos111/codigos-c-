#include <iostream>
#include <windows.h>
#include <locale>


using namespace std;

string placas[10] = {""}, modelo[10] = {""}, statusOS[10] =  {""};
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
	for(int i = 0; i < 100; i++){
		if(placas[i] == "" && modelo[i] == "" && statusOS[i] == "" && ano[i] == 0){
			cout<<"\nBem vindo a oficina"<<endl;
			cout<<"\nInforme a placa do Veiculo"<<endl;
			getline(cin, placas[i]);
			cout<<"\nInforme o Modelo do veiculo"<<endl;
			getline(cin, modelo[i]);
			cout<<"\nDigite o Ano de fabricação"<<endl;
			cin>>ano[i];
			
			statusOS[quantidade] = "Em andamento";
			cout<<"\nVeiculo cadastrado com status 'Em andamento'"<<endl;
			
			quantidade++;
		}
	}
}

void listarOS(){
	if(quantidade == 0){
		cout<<"Sem OS Registradas"<<endl;
		return;
	}
	for(int i = 0; i < quantidade; i++){
		cout<<"Veiculo "<<(1+1)<<endl;
		cout<<"Placa: "<<placas[i]<<endl;
		cout<<"Modelo: "<<modelo[i]<<endl;
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
    cout<<"Digite a placa para atualizar: ";
    cin.ignore();
    getline(cin, placa);

    for (int i = 0; i < quantidade; i++) {
        if (placas[i] == placa) {
            if (statusOS[i] != "Em andamento") {
                cout<<"So pode atualizar status de OS em andamento.\n";
                return;
            }

            cout<<"Escolha novo status:\n";
            cout<<"1 - Concluida\n2 - Cancelada\n";
            int opcao;
            cin>>opcao;
            cin.ignore();

            if (opcao == 1) statusOS[i] = "Concluida";
		
            else if (opcao == 2) statusOS[i] = "Cancelada";
            	cout<<"Opcao invalida.\n";
            	
            else(cout<<"Status atualizado.\n");
            	return;
        	}
        }
    	cout<<"Placa nao encontrada.\n";
}

void pesquisarVeiculo() {
    if (quantidade == 0) {
        cout<<"Nenhum veiculo cadastrado.\n";
        return;
    }

    string placa;
    cout<<"Digite a placa para pesquisar: ";
    cin.ignore();
    getline(cin,placa);

    for (int i = 0; i < quantidade; i++) {
        if (placas[i] == placa) {
            cout<<"Veiculo encontrado:\n";
            cout<<"Placa: "<<placas[i]<<endl;
            cout<<"Modelo: "<<modelos[i]<<endl;
            cout<<"Ano: "<<ano[i]<<endl;
            cout<<"Status OS: "<<statusOS[i]<<endl;
            return;
        }
    }
    cout<<"Placa nao encontrada.\n";
}

void totalOSconcluida(){
	int total = 0;
		if(quantidade == 0){
		cout<<"Sem OS Registradas"<<endl;
		return;
		}
		
		for(int i = 0; i < quantidade; i++){
			if(statusOS[i] == "Concluida"){
					total++;
			}
				cout<<"Total de Serviços concluidos: "<<total<<endl;
		}			
}

void totalOSandamento(){
	bool tem = false;
	for (int i = 0; i < quantidade; i++) {
        if (statusOS[i] == "Em andamento") {
            cout<<"Placa: "<<placas[i]<<endl;
			cout<<"Modelo: "<<modelos[i]<<endl;
			cout<<"Ano: "<<ano[i]<<endl;
            tem = true;
        }
    }
    if(!tem) cout<<"Nenhuma ordem em andamento"<<endl;
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
					atualizarstatus();
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
					cout<<"Saindo do Sistema.."<<endl;
					break;		
			}
		
		}while(op!=7);
}