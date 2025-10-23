#include <iostream>
#include <windows.h>
#include <locale>
#include <string>

using namespace std;

string produtos[100] = {""};
float precos[100] = {0}, totalvenda;
int qtdestoque[100], quantidade = 0, opcao, qtd;

void menu() {
	cout<<"\nSistema de Compras"<<endl;
	cout<<"1. Cadastrar Produtos"<<endl;
	cout<<"2. Listar Produtos"<<endl;
	cout<<"3. Realizar Venda (Controlar Estoque)"<<endl;
	cout<<"4. Calcular Valor total"<<endl;
	cout<<"5. Produto mais caro"<<endl;
	cout<<"6. Produto mais barato"<<endl;
	cout<<"0 - Sair"<<endl;
}

void cadastrarProdutos() {
	for (int i = 0; i < 100; i++) {
		if (produtos[i] == "" && precos[i] == 0 && qtdestoque[i] == 0) {
			cout<<"\nInforme o nome do produto"<<endl;
			cin>>produtos[i];
			cout<<"\nInforme o valor do produto"<<endl;
			cin>>precos[i];
			cout<<"\nQual a quantidade do produto?"<<endl;
			cin>>qtdestoque[i];
			
			quantidade++;
			break;
		}
	}
}

void listarProdutos(int n) {
	if(quantidade ==0){
		cout<<"Nenhum Produto cadastrado!!"<<endl;
	}
	
		cout<<"\n---Lista de Produtos---\n";
			for(int i = 0; i < n; i++){
				cout<<(i + 1)<<" - "<<produtos[i]<<" | Estoque =  "<<qtdestoque[i]<<" | R$ "<<precos[i]<<endl;
	}
}

void realizarvenda(){
	if(quantidade ==0 ){
		cout<<"\nImpossivel realizar venda, não existe produtos cadastrados."<<endl;
		return;
	}	
		listarProdutos(quantidade);
		
	cout<<"\nDigite o produto que deseja vender"<<endl;
	cin>>opcao;
	
	cout<<"\nQual a quantidade do produto?"<<endl;
	cin>>qtd;
	
	if (qtdestoque[opcao - 1] >=qtd){
	   qtdestoque[opcao - 1] -=qtd;
	float totalvenda = qtd * precos[opcao - 1];
		cout<<"\nValor Total da venda: R$"<<totalvenda<<endl;
	}else {
		cout<<"\nEstoque insuficiente.. Estoque atual: "<<qtdestoque[opcao - 1]<<endl;
	}

}

float calcularValorTotal() {
	float total = 0;
		for (int i = 0; i < quantidade; i++) {
			total += precos[i];
		}
	return total;
}

string produtoMaisCaro() {
	float maiorValor = 0;
	string maiorProduto = "";
		for (int i = 0; i < quantidade; i++) {
			if (maiorValor < precos[i]) {
				maiorValor = precos[i];
				maiorProduto = produtos[i];
			}
		}
		return maiorProduto;
}

string produtoMaisBarato() {
	float menorValor = precos[0];
	string menorProduto = "";
		for (int i = 0; i < quantidade; i++) {
			if (menorValor > precos[i]) {
				menorValor = precos[i];
				menorProduto = produtos[i];
			}
		}
		return menorProduto;
}

int main() {
	int op = 0;
	
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
	
	
	do {
		menu();
		cout<<"Informe a opção desejada: ";
		cin>>op;
		switch (op) {
			
			case 1:
				cadastrarProdutos();
				break;
			case 2:
				listarProdutos(quantidade);
				break;
			case 3:
				realizarvenda();
				break;
			case 4:
				cout<<"\nTotal: R$"<<calcularValorTotal()<<endl;
			
				break;
			case 5:
				cout<<"\nProduto Mais Caro: "<<produtoMaisCaro()<<endl;
				
				break;
			case 6:
				cout<<"\nProduto mais barato: "<<produtoMaisBarato()<<endl;
				break;	
			}
	}while (op != 0);


}