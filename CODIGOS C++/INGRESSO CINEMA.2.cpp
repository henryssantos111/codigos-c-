#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main(){
	int op= 0, ingresso = 50, compra = 0, compraanterior = 0, vendidos = 0;
	
	do{
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		setlocale(LC_ALL,".UTF8");
		
		
		cout << "\nMenu principal"
		<< "\nIngresso - R$20,00"
		<< "\n\n1. Comprar ingresso"
		<< "\n2. Cancelar a ultima compra"
		<< "\n3. Mostrar total de ingressos e valor arrecadado"
		<< "\n4. Sair"
		<< "\n>> ";
		cin >> op;	
		
		switch(op){
			case 1:{
				cout << "\nQuantos ingressos deseja comprar?\n>> R= ";
				cin >> compra;
				
				if(compra > ingresso){
					cout << "\nQuantidade inválida! Quantidade disponível: " << ingresso;
				}	
				else{
					cout << "\nCompra realizada!";
					ingresso -= compra;
					vendidos += compra;
				}				
				break;
			}
			
			case 2:{
				compraanterior = compra;
				
				cout << "\nCancelando ultima compra";
				ingresso += compraanterior;
				vendidos -= compraanterior;
				break;
			}
			
			case 3:{
				cout << "\nQuantidade restantes de ingressos: " << ingresso
				<< "\nQuantidade de ingressos ventidos: " << vendidos
				<< "\nTotal arrecadado R$: " << fixed << setprecision(2) << vendidos*25;
				break;
			}
			
			default:{
				if(op == 4){
					cout << "\nEncerrando o programa!";
				}
				else{
					cout << "\nOpção inválida!";
				}
				break;
			}
		}
	}while(op != 4);
	
	
}