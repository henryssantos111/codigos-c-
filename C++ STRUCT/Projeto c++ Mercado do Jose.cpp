#include <iostream
#include <locale>
#include <windows.h>

using namespace std;

struct Cliente{
   string nome;
   int idade;
   string cpf;
   string sexo;
   strig telefone;
   string email;
   string cep;
   string pais;
   string cidade;
   string bairro;
   
  
   
};

struct Produto{
   string nome;
   string categoria;
   float preco;
   int qtdEstoque;
};

Pessoa pessoas[100];
Produto produtos[100];

int qtdPessoa = 0;
int qtdProduto = 0;

void Menu(){
    cout<<"\n=== Seja Bem Vindo ao Cantinho do José ===\n";
    cout<<"1 - Menu de Cadastros"<<endl;
    cout<<"2 - Registrar Venda"<<endl;
    cout<<"3 - Sair do estabelecimento"<<endl;
}

void Menucadastros(){
    cout<<"\n=== Boas Vindas ao Menu de Cadastros ===\n";
    cout<<"1 - Cadastrar Cliente"<<endl;
    cout<<"2 - Cadastrar Produto"<<endl;
    cout<<"3 - Voltar ao Menu Principal"<<endl;
}

void Cadastrarcliente(){
    if(qtdCliente > 100){
        cout<<"\nLimite de Cadastros de clientes atingidos!!"<<endl;  
    }

        cout<<"\n=== Cadastro de Cliente ===\n";
        cin.ignore();
        cout<<"Nome: ";
        getline(cin, clientes[qtdCliente].nome);
        cout<<"Idade: ";
        getline(cin, clientes[qtdCliente].idade);
        cout<<"CPF: ";
        getline(cin, clientes[qtdCliente].cpf);
        cout<<"Sexo: ";
        getline(cin, clientes[qtdCliente].sexo);
        cout<<"Telefone: ";
        getline(cin, clientes[qtdCliente].telefone);
        cout<<"Email: ";
        getline(cin, clientes[qtdCliente].email);
        cout<<"CEP: ";
        getline(cin, clientes[qtdCliente].cep);
        cout<<"Pais: "
        getline(cin, clientes[qtdCliente].pais);
        cout<<"Cidade: ";
        getline(cin, clientes[qtdCliente].cidade);
        cout<<"Bairro: ";
        getline(cin, clientes[qtdCliente].bairro);

        qtdCliente ++;

        cout<<"\nCadastro de Cliente concluido com êxito!!"<<endl;
}

void Listarcliente(){
   if(qtdCliente == 0){
      cout<<"\nSem Clientes para listar"<<endl;
   }   

      cout<<"\n=== Lista de Clientes ===\n";
         for(int i = 0; i < qtdCliente; i++){
            cout<<"\n"<<(i + 1)<<" Cliente"<<endl;
            cout<<"Nome: "<<clientes[i].nome<<endl;
            cout<<"Idade: "<<clientes[i].idade<<endl;
            cout<<"CPF: "<<clientes[i].cpf<<endl;
            cout<<"Sexo: "<<clientes[i].sexo<<endl;
            cout<<"Telefone: "<<clientes[i].telefone<<endl;
            cout<<"E-mail do cliente: "<<clientes[i].email<<endl;
            cout<<"CEP - "<<clientes[i].cep<<endl;
            cout<<"Pais - "<<clientes[i].pais<<endl;
            cout<<"Cidade - "<<clientes[i].cidade<<endl;
            cout<<"Bairro - "<<clientes[i].bairro<<endl;
            cout<<"\n\n";
         }
}

void Cadastrarproduto(){
   if(qtdProduto > 100){
      cout<<"\nLimite de Produtos atingidos!!"<<endl;
   }   

      cout>>"\n=== Cadastro de Produtos ===\n";
      cin.ignore();
      cout<<"Nome do Produto - ";
      getline(cin, produtos[i].nome);
      cout<<"Categoria: ";
      getline(cin, produtos[i].categoria);
      cout<<"Preço - R$";
      cin>>produtos[i].preco<<endl;
      cout<<"Quantidade: ";
      cin>>produtos[i].qtdEstoque<<endl;

      qtdProduto++;

      cout<<"\nProduto cadastrado com sucesso!!"<<endl;
}

void Listarproduto(){
   if(qtdProduto == 0){
      cout<<"\nSem Produtos cadastrados!!"<<endl;
   }   
      cout<<"\n=== Lista de Clientes ===\n";
      for(int i = 0; i < qtdProduto; i++){
         cout<<"\n"<<(i + 1)<<" Produto"<<endl;
         cout<<"Nome do Produto - "<<produtos[i].nome<<endl;
         cout<<"Categoria: "<<produtos[i].categoria<<endl;
         cout<<"Preço do Produto - "<<produtos[i].preco<<endl;
         
         
      }   
}

int main(){
   int op = 0;
   
}

