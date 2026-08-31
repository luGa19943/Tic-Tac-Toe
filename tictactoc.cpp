#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

const int TAMANIO = 9;

void dibujarTablero(char espacios[]);
void turnoJugador(char espacios[], char jugador);
void turnoComputadora(char espacios[], char computadora);
bool verificarGanador(char espacios[], char marca);
bool verificarEmpate(char espacios[]);

int main() {

    srand(time(0));
    char respuesta;

    do {

        char espacios[TAMANIO] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char jugador = 'X';
        char computadora = 'O';
        bool ejecutando = true;

        dibujarTablero(espacios);

        while (ejecutando) {

            turnoJugador(espacios, jugador);
            system("cls");
            dibujarTablero(espacios);

            if (verificarGanador(espacios, jugador)) {
                cout << "GANASTE!\n";
                ejecutando = false;
                break;
            }

            if (verificarEmpate(espacios)) {
                cout << "EMPATE!\n";
                ejecutando = false;
                break;
            }

            turnoComputadora(espacios, computadora);
            system("cls");
            dibujarTablero(espacios);

            if (verificarGanador(espacios, computadora)) {
                cout << "PERDISTE!\n";
                ejecutando = false;
                break;
            }

            if (verificarEmpate(espacios)) {
                cout << "EMPATE!\n";
                ejecutando = false;
                break;
            }
        }

        cout << "\nQuieres jugar de nuevo? (s/n): ";
        cin >> respuesta;
        system("cls");

    } while (respuesta == 's' || respuesta == 'S');

    system("cls");
    cout << "Gracias por jugar!\n";

    return 0;
}

void dibujarTablero(char espacios[]) {

    cout << '\n';
    cout << "     |     |     \n";
    cout << "  " << espacios[0] << "  |  " << espacios[1] << "  |  " << espacios[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << espacios[3] << "  |  " << espacios[4] << "  |  " << espacios[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << espacios[6] << "  |  " << espacios[7] << "  |  " << espacios[8] << "  \n";
    cout << "     |     |     \n";
    cout << '\n';
}

void turnoJugador(char espacios[], char jugador) {

    int numero;

    do {
        cout << "Ingresa una casilla a jugar (1-9): ";
        cin >> numero;

        if (numero < 1 || numero > 9) {
            cout << "Numero invalido, intenta de nuevo.\n";
            continue;
        }

        if (espacios[numero - 1] != ' ') {
            cout << "Casilla ocupada, intenta de nuevo.\n";
            continue;
        }

        espacios[numero - 1] = jugador;
        break;

    } while (true); 
}

void turnoComputadora(char espacios[], char computadora) {

    int numero;

    while (true) {
        numero = rand() % TAMANIO;
        if (espacios[numero] == ' ') {
            espacios[numero] = computadora;
            break;
        }
    }
}

bool verificarGanador(char espacios[], char marca) {

    const int combinaciones[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        int a = combinaciones[i][0];
        int b = combinaciones[i][1];
        int c = combinaciones[i][2];

        if (espacios[a] != ' ' && espacios[a] == espacios[b] && espacios[b] == espacios[c]) {
            return true;
        }
    }

    return false;
}

bool verificarEmpate(char espacios[]) {

    for (int i = 0; i < TAMANIO; i++) {
        if (espacios[i] == ' ') {
            return false;
        }
    }

    return true;
}
