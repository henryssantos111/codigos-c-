#include <iostream>
#include <windows.h>
#include <locale>
#include <iomanip>

using namespace std;

double peso, altura, imc,numeros[10] = {0};
int quantidade = 0;

void menu(){
	cout<<"\n---Menu Principal---\n";
	cout<<"1 - Add imc"<<endl;
	cout<<"2 - Exibir Todos os IMCs"<<endl;
	cout<<"3 - Maior IMC"<<endl;
	cout<<"4 - Menor IMC"<<endl;
	cout<<"5 - Media dos IMCs"<<endl;
	cout<<"6 - Total"<<endl;
	cout<<"7 - Exibir Todas as Classificações"<<endl;
	cout<<"8 - Exibir a quantidade de Imcs com Peso Ideal"<<endl;
	cout<<"9 - Exibir a quantidade de Imcs com Classificação Obesidade Nivel 2"<<endl;
	cout<<"10 - Sair"<<endl;
}

double calcularimc(){
	
	imc = peso / (altura * altura);
	return imc;
}

void exibirimc(){
	for(int i = 0; i < quantidade; i++) {
	cout<<"\nnumeros["<<i<<"] = "<<fixed<<setprecision(2)<<numeros[i]<<" "<<endl;
}

}

double maiorimc(){
	double maior = 0;
	for(int i = 0; i < quantidade; i++){
		if( numeros[i] > maior){
			maior = numeros[i];
		}
	}
	return maior;
}

double menorimc(){
	double menor = numeros[0];
	for(int i = 0; i < quantidade; i++){
		if( numeros[i] < menor){
			menor = numeros[i];
		}
	}
	return menor;
}

double totalimc(){
	double total = 0;
	for(int i = 0; i < quantidade; i++){
		if(numeros[i] != 0){
			total+=numeros[i];
		}
	}
	return total;
}

double mediaimc(){
	double media;
	media = totalimc() / quantidade;
	return media;
}

void exibirTodasClassificacoes() {
    for(int i = 0; i < quantidade; i++) {
        double imcAtual = numeros[i];
        cout<<fixed<<setprecision(2)<<imcAtual<< " - ";
        if(imcAtual < 16){
            cout<< "Peso deficitario";
        } else if(imcAtual >= 16 && imcAtual < 18.5){
            cout << "Abaixo do Peso";
        } else if(imcAtual >= 18.5 && imcAtual < 24.9){
            cout << "Normal";
        } else if(imcAtual >= 25 && imcAtual < 30){
            cout << "Acima do peso";
        } else if(imcAtual >= 30 && imcAtual < 35){
            cout << "Obesidade nivel 1";
        } else if(imcAtual >= 35 && imcAtual < 40){
            cout << "Obesidade nivel 2";
        } else {
            cout<<"Obesidade nivel 3";
        }
        cout << endl;
    }
}

int contarpesodefici(){
	int count =0;
	for(int i = 0; i < quantidade; i++){
		if( numeros[i] < 16){
			count++;
		}
	}
	return count;
}

int contarobs2(){
	int conte = 0;
	for(int i = 0; i < quantidade; i++){
		if(numeros[i] >= 35 && numeros[i] <40){
			conte++;
		}
	}
	return conte;
}





int main(){

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, ".UTF-8");
	
	int op;	
	
	do{
		menu();
		cout<<"Escolha uma opção: ";
		cin>>op;	
		
		
		switch(op){
			
			case 1:
				if(quantidade < 10) {  
			        cout<<"\nQual o peso do aluno? "<<endl;
			        cin>>peso;
			        cout<<"\nQual a altura do aluno? "<<endl;
			        cin>>altura;
			        imc = calcularimc();           
			        numeros[quantidade] = imc;    
			        quantidade++;        
			        cout << "\nIMC registrado com sucesso!\n";
    			}else {
       			 	cout << "Limite de 10 IMCs atingido.\n";
             	}
   			 		break;						
			case 2:
				exibirimc();
				break;	
			case 3:
				cout<<"\nMaior IMC: "<<maiorimc()<<endl;
				break;
			case 4:
				cout<<"\nMenor IMC: "<<menorimc()<<endl;
				break;
			case 5:			
				cout<<"Total dos IMCS: "<<totalimc()<<endl;
				break;
			case 6:
				cout<<"Media do IMC: "<<mediaimc()<<endl;
				break;
			case 7:
				exibirTodasClassificacoes();
				break;	
			case 8:
				cout<<"\nQuantidade: "<<contarpesodefici()<<endl;
				break;
			case 9:
				cout<<"\nQuantidade: "<<contarobs2()<<endl;
				break;
				
			case 10:
				cout<<"Saindo do programa..."<<endl;
				break;			
	
	
	
	
	
	
	
	
	
	
	
	
		}
		
		
		
	}while(op != 10);

}