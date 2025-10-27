#include <iostream>
#include <windows.h>
#include <iomanip>


using namespace std;

float valorcompra,valorpago , totaldia, troco;
int op;

void Menu(){
	cout<<"\n---Menu Caixa---\n";
	cout<<"(1) Registrar Compra"<<endl;
	cout<<"(2) Exibir total do dia"<<endl;
	cout<<"(3) Sair do caixa"<<endl;
	cout<<"Escolha a Opção: ";
}


void registrartroco(){
	troco = valorpago - valorcompra;
    
}



void registrarcompra(){
		cout<<fixed<<setprecision(2);
		
		cout<<"\nQual o valor da compra?  "<<"R$ ";
		cin>>valorcompra;
		cout<<"Qual valor pago pelo cliente? "<<"R$ ";
		cin>>valorpago;
		
		if(valorpago < valorcompra){
			cout<<"Pagamento insuficiente!"<<endl;
		}else{
			registrartroco();
			cout<<"Troco do cliente: R$ "<<troco<<endl;
			totaldia+=valorcompra;
		} 
}



void exibirtotal(){
	cout<<"Total arrecadado do dia: R$ "<<totaldia<<endl;
}





int main(){
	
	SetConsoleOutputCP(CP_UTF8);
      SetConsoleCP(CP_UTF8);
	
	do{
		
		Menu();
		cin>>op;
		
		switch(op){
			
			case 1:
				registrarcompra();
				registrartroco();
				break;
			
			case 2:
				exibirtotal();
				break;
			
			case 3:
				cout<<"Saindo do caixa..."<<endl;
				break;	
		}
		
		
		
		
	}while(op!=3);
}