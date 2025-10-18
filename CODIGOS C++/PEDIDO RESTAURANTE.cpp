#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

int op, caso, pedido = 20.00, cancelar, escolha = 0;
int agua = 0., suco = 0., refrigerante = 0.;
float valortotal;

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	
	do{
		
	cout<<"\n---Restaurante do Ministro---\n"<<endl;
	cout<<"(1) Fazer Pedido"<<endl;
	cout<<"(2) Cancelar pedido"<<endl;
	cout<<"(3) Mostrar recibo"<<endl;
	cout<<"(4) Sair do restaurante"<<endl;
	cout<<"Escolha uma opção: ";
	cin>>op;
	
	switch(op){
		
		case 1:
			while(escolha != 2){
			
				cout<<"\n---Cardapio---\n";
				cout<<"(1) Água - R$ 5,00"<<endl;
				cout<<"(2) Refrigerante - R$ 6,00"<<endl;
				cout<<"(3) Suco - R$ 9,00"<<endl;
				cout<<"Qual o seu pedido: ";
				cin>>pedido;
				
				if(pedido == 1){
					agua++;
					cout<<"\nPedido feito!"<<endl;
				}else if(pedido == 2){
					refrigerante++;
					cout<<"\nPedido feito!"<<endl;
				}else if(pedido == 3){
					suco++;
					cout<<"\nPedido feito!"<<endl;
				}else{
					
				}
				
				cout<<"\nDeseja Pedir algo mais?"<<endl;
				cout<<"(1) Sim"<<endl;
				cout<<"(2) Não"<<endl;
				cin>>escolha;
			}
			
			
		break;
		
		case 2:
			cout<<"\nQual pedido você deseja cancelar"<<endl;
			cout<<"(1) Água "<<endl;
			cout<<"(2) Refrigerante "<<endl;
			cout<<"(3) Suco "<<endl;
			cout<<"Qual o seu pedido: ";
			cin>>cancelar;
			
			if(cancelar == 1 && agua > 0 ){
				agua--;
				cout<<"\nPedido de água cancelado"<<endl;
			}else if(cancelar == 2 && refrigerante >0){
				refrigerante--;
				cout<<"\nPedido de refri cancelado"<<endl;
			}else if(cancelar == 3 && suco > 0){
				suco--;
				cout<<"\nPedido de Suco cancelado"<<endl;
			}
			
		break;
		
		case 3:
		 	valortotal = (agua * 5) + (refrigerante * 6) + (suco * 9);
		 	cout<<"Agua: "<<agua<<endl;
		 	cout<<"Refri: "<<refrigerante<<endl;
		 	cout<<"Suco: "<<suco<<endl;
			cout<<"\nTotal do pedido: R$ "<<valortotal;
		
		break;
		
		case 4:
		
		cout<<"Saindo do Restaurante"<<endl;
		break;
				
			
}
		
}while(op != 4);


}