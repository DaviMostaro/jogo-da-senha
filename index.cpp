#include <iostream>
#include <random>
using namespace std;

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

char retornaSimbolo(int senhaReal, int chuteN, int posicao) {
    int senha1 = senhaReal / 1000;
    int senha2 = (senhaReal / 100) % 10;
    int senha3 = (senhaReal / 10) % 10;
    int senha4 = senhaReal % 10;

    if ((posicao == 1 && chuteN == senha1) ||
        (posicao == 2 && chuteN == senha2) ||
        (posicao == 3 && chuteN == senha3) ||
        (posicao == 4 && chuteN == senha4)) {
        return 'O';
    } else if (chuteN == senha1 || chuteN == senha2 ||
               chuteN == senha3 || chuteN == senha4) {
        return 'X';
    } else {
        return '_';
    }
    
}

void verificarSenha(int senhaReal) {
    int tentativas = 0;
    char simbolo1, simbolo2, simbolo3, simbolo4;

    while (tentativas < 10) {
        int chute;
        cout << "Digite sua tentativa (4 dígitos de 1 a 6): ";
        cin >> chute;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Tente novamente." << endl;
            continue;
        }

        int chute1 = chute / 1000;
        int chute2 = (chute / 100) % 10;
        int chute3 = (chute / 10) % 10;
        int chute4 = chute % 10;

        if (chute1 < 1 || chute1 > 6 ||
            chute2 < 1 || chute2 > 6 ||
            chute3 < 1 || chute3 > 6 ||
            chute4 < 1 || chute4 > 6) {
            cout << "Chute inválido. Tente novamente." << endl;
            continue;
        }

        simbolo1 = retornaSimbolo(senhaReal, chute1 , 1);
        simbolo2 = retornaSimbolo(senhaReal, chute2, 2);
        simbolo3 = retornaSimbolo(senhaReal, chute3, 3);
        simbolo4 = retornaSimbolo(senhaReal, chute4, 4);

        if (chute == senhaReal) {
            cout << "Parabéns! Você acertou a senha!" << endl;
            return;
        }
        
        cout << chute << endl;
        cout << simbolo1 << simbolo2 << simbolo3 << simbolo4 << endl;

        tentativas++;
    }

    if(tentativas == 10) {
        cout << "Número máximo de tentativas atingido. A senha era: "
             << senhaReal << endl;
    }
}

int main() {
    cout << "Bem vindo ao jogo da senha!" << endl;
    int senhaReal = gerarSenha();
    verificarSenha(senhaReal);
    return 0;
}