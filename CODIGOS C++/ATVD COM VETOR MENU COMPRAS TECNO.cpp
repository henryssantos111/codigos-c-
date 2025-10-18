#include <iostream>
#include <windows.h>
#include <locale>
#include <iomanip>

using namespace std;

string produtos[10];
float preco[10];
int qtdestoque[10], quantidade = 0;;

void Menu(){
	cout<<"\n1 - Cadastrar Produtos"<<endl;
	cout<<"2 - Listar produtos cadastrados"<<endl;
	cout<<"3 - Realizar venda"<<endl;
	cout<<"4 - Exibir Valor total no estoque"<<endl;
	cout<<"5 - Produtos com estoque baixo"<<endl;
	cout<<"6 - Sair do sistema"<<endl;
}

void cadastrar(int n){
	for(int i = 0; i < n; i++){
		cout<<"\nDigite o nome do Produto"<< (quantidade  + 1)<< ": "<<endl;
		cin.ignore();
		getline(cin, produtos[quantidade]);
		
		cout<<"\nDigite o preço do produto: ";
        cin>>preco[quantidade];
        
		cout<<"\nQual a quantidade que deseja cadastrar?"<<endl;
		cin>>qtdestoque[quantidade];
		
		quantidade++;
	}
		cout<<"\nProdutos cadastrados com sucesso!\n"<<endl;
}

void listarP(int n){
	if(n == 0){
		cout<<"\nNenhum Produto cadastrado."<<endl;
		return;
	}
		cout<<"\n---Lista de Produtos---\n";
		for(int i = 0; i < n; i++){
			cout<<(i + 1)<<" - "<<produtos[i]<<" | Estoque =  "<<qtdestoque[i]<<" | R$ "<<preco[i]<<endl;
		}
}

void realizarVenda() {
    if (quantidade == 0) {
        cout << "Nenhum produto cadastrado. Não é possível realizar vendas.\n";
        return;
    }
    int opcao, qtd;
    
    listarP(quantidade); 
    
    cout<<"\nDigite o número do produto que deseja vender: ";
    cin>>opcao;

    if (opcao < 1 || opcao > quantidade) {
        cout << "Produto inválido.\n";
        return;
    }

    cout<<"\nDigite a quantidade que deseja vender: ";
    cin>>qtd;

    if (qtd <= 0) {
        cout<<"Quantidade inválida.\n";
        return;
    }

    if (qtdestoque[opcao - 1] >= qtd) {
        qtdestoque[opcao - 1] -= qtd;
        float totalVenda = qtd * preco[opcao - 1];
        cout<<"\nVenda realizada com sucesso! Total: R$ " << totalVenda << endl;
    } else {
        cout<<"Estoque insuficiente. Estoque atual: " << qtdestoque[opcao - 1] << endl;
    }
}

float Totalestoque(){
	
	float Valortotal = 0;
	
	for(int i = 0; i < quantidade; i++){
		Valortotal += preco[i] * qtdestoque[i];
	}
	return Valortotal;
}

void exibiEstoqueBaixo() {
    if (quantidade == 0) {
        cout << "Nenhum produto cadastrado.\n";
        return;
    }

    cout<<"--- Produtos com Estoque Baixo ---\n";
    bool temEstoqueBaixo = false;
    
    for (int i = 0; i < quantidade; i++) {
        if (qtdestoque[i] < 5) { 
            cout<<produtos[i]<<" | Estoque = " << qtdestoque[i] << endl;
            temEstoqueBaixo = true;
        }
    }

    if (!temEstoqueBaixo) {
        cout<<"Nenhum produto com estoque baixo.\n";
    }
}


int main(){
	
	SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");
	
	int op, n;
	
		do{
					
			Menu();
			cout<<"Escolha uma opção: ";
			cin>>op;
			
			switch(op){
				
				case 1:
					cout<<"\nQuantos Produtos deseja cadastrar?"<<endl;
					cin>>n;
					cadastrar(n);
					break;
					
				case 2:
					listarP(n);
					break;
					
				case 3:
					realizarVenda();
					break;	
						
				case 4:
					cout<<"Valor total em estoque: "<<Totalestoque()<<endl;
					break;
						
				case 5: 
					exibiEstoqueBaixo();
					break;
					
				case 6: 
					cout<<"Saindo do sistema..."<<endl;
					break;	
			}
		
		}while(op != 6);
}