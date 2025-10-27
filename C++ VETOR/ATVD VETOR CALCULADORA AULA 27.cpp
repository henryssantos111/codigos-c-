#include <iostream>

using namespace std;

double valores[10] = {0};
double valor01, valor02;
int quantidade = 0;

double somar(double a, double b) {
    return a + b;
}

double subtrair(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    return a / b;
}

void addResultado(double valor) {
    for (int i = 0; i < 10; i++) {
        if (valores[i] == 0) {
            valores[i] = valor;
            quantidade++;
            break;
        }
    }
}

void menu() {
    cout<<"Menu Calculadora:"<<endl;
    cout<<"1. Somar"<<endl;
    cout<<"2. Subtrair"<<endl;
    cout<<"3. Multiplicar"<<endl;
    cout<<"4. Dividir"<<endl;
    cout<<"5. Operações com Vetor"<<endl;
    cout<<"6. Sair"<<endl;
}

void lerValores() {
    cout << "Digite o primeiro valor"<<endl;
    cin >> valor01;
    cout << "Digite o segundo valor"<<endl;
    cin >> valor02;
}

void exibir() {
    for (int i = 0; i < quantidade; i++) {
        if (valores[i] != 0) {
            cout<<"Valores["<<i+1<<"] = "<<valores[i]<<endl;
        }
    }
}

void menuVetor() {
    cout<<"Menu Vetor:"<<endl;
    cout<<"1. Total"<<endl;
    cout<<"2. Media"<<endl;
    cout<<"3. Maior"<<endl;
    cout<<"4. Menor"<<endl;
    cout<<"5. Voltar ao Menu Calculadora"<<endl;
}

double maiorValor() {
    double maior = 0;
    for (int i = 0; i < quantidade; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
    }
    return maior;
}

double getTotal() {
    double total = 0;
    for (int i = 0; i < quantidade; i++) {
        if (valores[i] != 0) {
            total += valores[i];
        }
    }
    return total;
}

double getMedia() {
    double media = 0;
    media = getTotal() / quantidade;
    return media;
}

int main() {
    double resultado;
    int op = 0, opVetor = 0;

    do {
        menu();
        cout<<"Informe a opção desejada:"<<endl;
        cin>>op;

        switch (op) {
            case 1:
                lerValores();
                resultado = somar(valor01, valor02);
                addResultado(resultado);
                exibir();
                break;
            case 2:
                lerValores();
                resultado = subtrair(valor01, valor02);
                addResultado(resultado);
                exibir();
                break;
            case 3:
                lerValores();
                resultado = multiplicar(valor01, valor02);
                addResultado(resultado);
                exibir();
                break;
            case 4:
                lerValores();
                resultado = divisao(valor01, valor02);
                addResultado(resultado);
                exibir();
                break;
            case 5:
                do {
                    menuVetor();
                    cout<<"Informe a opção desejada ?"<<endl;
                    cin>>opVetor;
                    switch (opVetor) {
                        case 1:
                            cout<<"Total de valores: "<<getTotal()<<endl;
                            break;
                        case 2:
                            cout<<"Media "<<getMedia()<<endl;
                            break;
                        case 3:
                            cout<<"Maior valor: "<<maiorValor()<<endl;

                            break;
                    }
                }while (opVetor != 5);

                break;
        }

    }while (op != 5);

}