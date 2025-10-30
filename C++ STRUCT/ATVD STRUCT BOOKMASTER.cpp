#include <iostream>
#include <string>
#include <windows.h> 

using namespace std;

struct Livro {
    string titulo;
    string autor;
    int ano;
    int estoque;
};

struct Aluno {
    string cpf;
    string nome;
    int idade;
};

struct Funcionario {
    int id;
    string nome;
    string cpf;
};

struct Emprestimo {
    int id;
    string data_saida;
    string data_devolucao;
    Aluno aluno;
    Livro livro;
    Funcionario funcionario;
};

Livro livros[100];
Aluno alunos[100];
Funcionario funcionarios[100];
Emprestimo emprestimos[100];

int qtdLivros = 0;
int qtdAlunos = 0;
int qtdFuncionarios = 0;
int qtdEmprestimos = 0;

void menuPrincipal() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1 - Cadastros\n";
    cout << "2 - Empréstimos\n";
    cout << "3 - Devoluções\n";
    cout << "4 - Relatórios\n";
    cout << "5 - Sair\n";
    cout << "Escolha uma opção: ";
}

void menuCadastros() {
    cout << "\n===== MENU DE CADASTROS =====\n";
    cout << "1 - Cadastrar Aluno\n";
    cout << "2 - Cadastrar Funcionário\n";
    cout << "3 - Cadastrar Livro\n";
    cout << "4 - Voltar\n";
    cout << "Escolha uma opção: ";
}


void cadastrarAluno() {
    if (qtdAlunos >= 100) {
        cout<<"Limite de 100 alunos atingido!\n";
        return;
    }

    cout<<"\n=== Cadastro de Aluno ===\n";
    cout<<"CPF: ";
    cin>>alunos[qtdAlunos].cpf;
    cin.ignore();
    cout<<"Nome: ";
    getline(cin, alunos[qtdAlunos].nome);
    cout<<"Idade: ";
    cin>>alunos[qtdAlunos].idade;

    qtdAlunos++;
    cout<<"Aluno cadastrado com sucesso!\n";
}

void cadastrarFuncionario() {
    if (qtdFuncionarios >= 100) {
        cout<<"Limite de 100 funcionários atingido!\n";
        return;
    }

    cout<<"\n=== Cadastro de Funcionário ===\n";
    funcionarios[qtdFuncionarios].id = qtdFuncionarios + 1;
    cin.ignore();
    cout<<"Nome: ";
    getline(cin, funcionarios[qtdFuncionarios].nome);
    cout<<"CPF: ";
    cin>>funcionarios[qtdFuncionarios].cpf;

    qtdFuncionarios++;
    cout<<"Funcionário cadastrado com sucesso!\n";
}

void cadastrarLivro() {
    if(qtdLivros >= 100) {
        cout << "Limite de 100 livros atingido!\n";
        return;
    }
    
    cout<<"\n=== Cadastro de Livro ===\n";
    cin.ignore();
    cout<<"Título: ";
    getline(cin, livros[qtdLivros].titulo);
    cout<<"Autor: ";
    getline(cin, livros[qtdLivros].autor);
    cout<<"Ano: ";
    cin>>livros[qtdLivros].ano;
    cout<<"Estoque: ";
    cin>>livros[qtdLivros].estoque;

    qtdLivros++;
    cout<<"Livro cadastrado com sucesso!\n";
}


void realizarEmprestimo() {
    if (qtdEmprestimos >= 100) {
        cout<<"Limite de 100 empréstimos atingido!\n";
        return;
    }

    if (qtdAlunos == 0 || qtdLivros == 0 || qtdFuncionarios == 0) {
        cout<<"Antes de emprestar, cadastre alunos, livros e funcionários!\n";
        return;
    }

    string cpfAluno, tituloLivro;
    cout<<"\n=== Novo Empréstimo ===\n";
    cout<<"CPF do aluno: ";
    cin>>cpfAluno;
    cin.ignore();
    
    
    int idxAluno = -1;
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].cpf == cpfAluno) {
            idxAluno = i;
            break;
        }
    }
    if (idxAluno == -1) {
        cout<<"Aluno não encontrado!\n";
        return;
    }

    cout<<"Título do livro: ";
    getline(cin, tituloLivro);

   
    int idxLivro = -1;
    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].titulo == tituloLivro) {
            idxLivro = i;
            break;
        }
    }
    if (idxLivro == -1) {
        cout<<"Livro não encontrado!\n";
        return;
    }

    if (livros[idxLivro].estoque <= 0) {
        cout<<"Livro sem estoque disponível!\n";
        return;
    }

    cout<<"\nFuncionários disponíveis:\n";
    for (int i = 0; i < qtdFuncionarios; i++) {
        cout<<funcionarios[i].id<<" - "<<funcionarios[i].nome<<endl;
    }

    int idFunc;
    cout<<"Digite o ID do funcionário: ";
    cin>>idFunc;

    int idxFunc = -1;
    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].id == idFunc) {
            idxFunc = i;
            break;
        }
    }
    if (idxFunc == -1) {
        cout<<"Funcionário não encontrado!\n";
        return;
    }

    emprestimos[qtdEmprestimos].id = qtdEmprestimos + 1;
    emprestimos[qtdEmprestimos].aluno = alunos[idxAluno];
    emprestimos[qtdEmprestimos].livro = livros[idxLivro];
    emprestimos[qtdEmprestimos].funcionario = funcionarios[idxFunc];

    cout<<"Data de saída (dd/mm/aaaa): ";
    cin>>emprestimos[qtdEmprestimos].data_saida;
    cout<<"Data de devolução prevista (dd/mm/aaaa): ";
    cin>>emprestimos[qtdEmprestimos].data_devolucao;

    livros[idxLivro].estoque--; // Atualiza estoque

    qtdEmprestimos++;
    cout<<"Empréstimo realizado com sucesso!\n";
}


void realizarDevolucao() {
    string tituloLivro;
    cout<<"\n=== Devolução de Livro ===\n";
    cin.ignore();
    cout<<"Título do livro devolvido: ";
    getline(cin, tituloLivro);

    bool encontrado = false;

    for (int i = 0; i < qtdEmprestimos; i++) {
        if (emprestimos[i].livro.titulo == tituloLivro) {
        	
            for (int j = 0; j < qtdLivros; j++) {
                if (livros[j].titulo == tituloLivro) {
                    livros[j].estoque++;
                    break;
                }
            }
            cout<<"Livro devolvido com sucesso!\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout<<"Nenhum empréstimo encontrado para este livro.\n";
    }
}


void listarEmprestimos() {
    cout<<"\n=== Lista de Empréstimos ===\n";
    if (qtdEmprestimos == 0) {
        cout<<"Nenhum empréstimo registrado.\n";
        return;
    }

    for (int i = 0; i < qtdEmprestimos; i++) {
        cout<<"ID: " << emprestimos[i].id<<endl;
    	cout<< " | Livro: " << emprestimos[i].livro.titulo<<endl;
        cout<< " | Aluno: " << emprestimos[i].aluno.nome<<endl;
    	cout<< " | Funcionário: " << emprestimos[i].funcionario.nome<<endl;
        cout<< " | Saída: " << emprestimos[i].data_saida<<endl;
        cout << " | Devolução prevista: " << emprestimos[i].data_devolucao<<endl;
    }
}


int main() {
    SetConsoleOutputCP(65001);

    int op1 = 0;
    do {
        menuPrincipal();
        cin>>op1;

        switch (op1) {
            case 1: {
                int op2;
                do {
                    menuCadastros();
                    cin>>op2;
                    switch (op2) {
                        case 1: cadastrarAluno(); break;
                        case 2: cadastrarFuncionario(); break;
                        case 3: cadastrarLivro(); break;
                        case 4: cout<<"Voltando ao menu principal...\n"; break;
                        default: cout<<"Opção inválida!\n";
                    }
                } while (op2 != 4);
                break;
            }

            case 2:
                realizarEmprestimo();
                break;

            case 3:
                realizarDevolucao();
                break;

            case 4:
                listarEmprestimos();
                break;

            case 5:
                cout<<"Saindo...\n";
                break;

            default:
                cout<<"Opção inválida!\n";
        }
    } while (op1 != 5);

    return 0;
}
