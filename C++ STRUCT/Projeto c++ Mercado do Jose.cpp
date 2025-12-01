#include <iostream
#include <locale>
#include <windows.h>

using namespace std;

struct Cliente{
   string nome;
   string cpf;
   string cep;
   strig telefone;
   int idade;
   string email;
   string endereco;
   string sexo;
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

      
}


int main(){

}