#include <iostream>

class Relogio {
private:
    int hora;
    int minuto;
    int segundo;

public:
    // Construtor
    Relogio() : hora(0), minuto(0), segundo(0) {}

    // Método para definir hora
    void setHora(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hora = h;
            minuto = m;
            segundo = s;
        } else {
            std::cout << "Horário inválido!" << std::endl;
        }
    }

    // Método para obter hora
    void getHora(int& h, int& m, int& s) const {
        h = hora;
        m = minuto;
        s = segundo;
    }

    // Método para avançar o horário
    void avancaSegundo() {
        segundo++;
        if (segundo >= 60) {
            segundo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                hora++;
                if (hora >= 24) {
                    hora = 0;
                }
            }
        }
    }

    // Método para exibir a hora
    void exibirHora() const {
        std::cout << "Hora: " << hora << ":" << minuto << ":" << segundo << std::endl;
    }
};

int main() {
    Relogio relogio;
    relogio.setHora(23, 59, 50);
    relogio.exibirHora();

    for (int i = 0; i < 15; i++) { // avança 15 segundos
        relogio.avancaSegundo();
        relogio.exibirHora();
    }

    return 0;
}
