#include <iostream>
#include <random>
using namespace std;

void retornaSimbolo(int senhaReal, int chute) {
    int senha1, senha2, senha3, senha4;
    senha1 = senhaReal / 1000;
    senha2 = (senhaReal / 100) % 10;
    senha3 = (senhaReal / 10) % 10;
    senha4 = senhaReal % 10;

    int chute1, chute2, chute3, chute4;
    chute1 = chute / 1000;
    chute2 = (chute / 100) % 10;
    chute3 = (chute / 10) % 10;
    chute4 = chute % 10;

    char simbolo1, simbolo2, simbolo3, simbolo4;

    // Terminar lógica de comparação e atribuição de símbolos

    if (simbolo1 == 'O' && simbolo2 == 'O' && simbolo3 == 'O' && simbolo4 == 'O') {
        cout << "Senha correta! Você venceu!" << endl;
        exit(0);
    }

    cout << "****" << endl;
    cout << simbolo1 << simbolo2 << simbolo3 << simbolo4 << endl;
}

int gerarSenha() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 6);

    int a, b, c, d;
    a = dist(gen);
    b = dist(gen);
    c = dist(gen);
    d = dist(gen);

    int senha = a * 1000 + b * 100 + c * 10 + d;
    return senha;
}

void verificarSenha(int senhaReal) {
    int tentativas = 0;
    int senha1, senha2, senha3, senha4;
    senha1 = senhaReal / 1000;
    senha2 = (senhaReal / 100) % 10;
    senha3 = (senhaReal / 10) % 10;
    senha4 = senhaReal % 10;

    while (tentativas < 10) {
        int chute;
        cout << "Digite sua tentativa (4 dígitos de 1 a 6): ";
        cin >> chute;
        retornaSimbolo(senhaReal, chute);

        tentativas++;
    }

    if(tentativas == 10) {
        cout << "Número máximo de tentativas atingido. A senha era: "
             << senha1 << senha2 << senha3 << senha4 << endl;
    }
}

int main() {
    cout << "Bem vindo ao jogo da senha!" << endl;
    int senhaReal = gerarSenha();
    verificarSenha(senhaReal);
    return 0;
}