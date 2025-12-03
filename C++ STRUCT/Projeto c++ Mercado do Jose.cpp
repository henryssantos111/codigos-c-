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


int main(){

}
