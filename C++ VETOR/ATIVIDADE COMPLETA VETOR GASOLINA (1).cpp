#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;
double valor[10] = {0};
int litros[10] = {0}, quantidade, escolhaCombustivel;


void Menu(){
	cout<<"\n---Posto do Ministro---\n"<<endl;
	cout<<"(1) Registrar abastecimento"<<endl;
	cout<<"(2) Relatorio do dia"<<endl;
	cout<<"(3) Sair"<<endl;
}

void Menugaso(){
	cout<<"\nQual Tipo de combustivel? \n";
	cout<<"\n(1) Gasolina - R$ 6.50L "<<endl;
	cout<<"(2) Etanol - R$ 4.20L "<<endl;
	cout<<"(3) Diesel - R$ 5.10L "<<endl;
}
double regisAbas(int litros, int tipo){
	double preco = 0;
	
	switch(tipo){
		case 1: 
			preco = 6.50;
			break;
		case 2:
			preco = 4.20;
			break;
		case 3:
			preco = 5.10;
			break;		
	}
	return litros * preco;
}

void relatoriodia(){
	int totalLitros = 0;
	double totalFaturado = 0;
	
	cout<<"\n---Relatorio do dia---\n ";

	for(int i = 0; i < quantidade; i++){
		cout<<"Abastecimento "<<(i+1)<<" : "<<litros[i]<<" L - R$ "<<valor[i]<<endl;
		totalLitros+=litros[i];
		totalFaturado += valor[i];
	}
	
	cout<<"\nTotal de litros vendidos: "<<totalLitros<<" L"<<endl;
	cout<<"Total faturado no dia: R$"<<totalFaturado<<endl;

	
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
					Menugaso();
					cout<<"\nEscolha uma opção: ";
					cin>>escolhaCombustivel;
					
					if(escolhaCombustivel >= 1 && escolhaCombustivel <=3){
						cout<<"\nQuantos litros deseja abastecer? "<<endl;
						cin>>litros[quantidade];
						
						valor[quantidade] = regisAbas(litros[quantidade], escolhaCombustivel);
						quantidade++;
						
						cout<<"\nValor Registrado no dia!"<<endl;
						
					}else {
						cout<<"Opção invalida!"<<endl;
					}				
					break;
				
				case 2:
					relatoriodia();
					break;
				case 3:
					cout<<"Saindo do sistema..."<<endl;
					break;	
			}
			
			
	}while(op!= 3);
	
}