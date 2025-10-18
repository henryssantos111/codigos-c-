#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;

string titulo[10] = {""}, autor [10] = {""};
int anopubli[10] = {0}, qtdestoque[10] = {0}, quantidade = 0;

void Menu(){
	cout<<"\n---Seja bem vindo a Livraria---\n";
	cout<<" 1 - Cadastrar livros"<<endl;
	cout<<" 2 - Listar livros cadastrados"<<endl;
	cout<<" 3 - Registrar empréstimo "<<endl;
	cout<<" 4 - Registrar devolução"<<endl;
	cout<<" 5 - Total de livros em estoque"<<endl;
	cout<<" 6 - Livros com baixo estoque ( Menor que 3)"<<endl;
	cout<<" 7 - Sair do sistema"<<endl;
}

void cadastrarL(){
	for(int i = 0; i < 10; i++){
		if (titulo[i] == "" && autor[i] == "" && anopubli[i] == 0 && qtdestoque[i] == 0 ) {
			cout<<"\nQual o titulo do livro?"<<endl;
			cin.ignore();
			getline(cin,titulo[i]);
			cout<<"\nQual o autor do livro?"<<endl;
			getline(cin,autor[i]);
			cout<<"\nQual o Ano de Publicação?"<<endl;
			cin>>anopubli[i];
			cout<<"\nQual a quantidade?"<<endl;
			cin>>qtdestoque[i];
			
			quantidade++;
			break;
		}
	}
	
}

void ListarL(int n){
	if(quantidade ==0){
		cout<<"\nNenhum Livro cadastrado"<<endl;
	}else{
	
		cout<<"\n---Lista de Livros---\n";
		for(int i = 0; i < n; i++){
			cout<<(i + 1)<< " Livro - "<<titulo[i]<<"\nAutor - "<<autor[i]<<"\nAno - "<<anopubli[i]<<"\nEstoque - "<<qtdestoque[i]<<endl;
		}
}

}

void emprestimo() {
    if (quantidade == 0) {
        cout << "\nNenhum livro cadastrado.\n";
    	return;
	}

    int num;
    ListarL(quantidade); 
    
    cout<<"\nNúmero do livro para emprestar: "<<endl;
    cin>>num;

    if (num > 0 && num <= quantidade) {
        if (qtdestoque[num - 1] > 0) {
            qtdestoque[num - 1]--; 
            cout<<"Empréstimo realizado!\n";
        } else  {
            cout<<"Sem estoque disponível!\n";
        }
    } else {
        cout<<"Livro inválido!\n";
    }
}

void devolucao() {
    if (quantidade == 0) {
        cout<<"\nNenhum livro cadastrado.\n";
    	return;
	}

    int num;
    ListarL(quantidade);

    cout<<"Número do livro devolvido: "<<endl;
    cin>>num;

    if (num > 0 && num <= quantidade) {
        qtdestoque[num - 1]++; 
        cout<<"Devolução registrada!\n";
    } else {
        cout<<"Livro inválido!\n";
    }
}

void totalEstoque(){
	int total = 0;
	
	for(int i = 0; i < quantidade; i++){
		total += qtdestoque[i];
	}
	cout<<"\nTotal de Livros disponíveis: "<<total<<"\n";
}

void baixoEstoque(){
	bool encontrou = false;
	cout<<"\n---Livros com Baixo estoque---\n";
	
	for(int i = 0; i < quantidade; i++){
		if(qtdestoque[i] < 3) { 
			cout<<titulo[i]<<" Estoque - "<<qtdestoque[i]<<endl;
			encontrou = true;		}
	}
	if(!encontrou ){
		cout<<"\nNenhum Livro com baixo estoque"<<endl;
	}
}

int main(){
	int op;
	
		SetConsoleOutputCP(CP_UTF8);
    	SetConsoleCP(CP_UTF8);
    	setlocale(LC_ALL, ".UTF-8");
		
		
		do{
			Menu();
			cout<<"Informe a opção: ";
			cin>>op;
			
			switch(op){
				case 1:
					cadastrarL();
					break;
				case 2:
					ListarL(quantidade);
					break;
				case 3:
					emprestimo();
					break;
				case 4:
					devolucao();
					break;
				case 5:
					totalEstoque();
					break;
				case 6:
					baixoEstoque();				
					break;
				case 7:
					cout<<"Saindo do Sistema..."<<endl;
					break;	
					
				
			}
			
			
			
			
			
			
			
			
			
			
			
			
		}while(op != 7);
	
}