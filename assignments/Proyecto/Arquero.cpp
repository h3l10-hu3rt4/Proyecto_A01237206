#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>

Arquero::Arquero() : Unidad() { precision = 50; }

Arquero::Arquero(int _vida, int _ataque, int _nivel, int _precision) 
    : Unidad(_vida, _ataque, _nivel) {
    precision = _precision;
}

int Arquero::getPrecision() const { return precision; }
void Arquero::setPrecision(int _precision) { precision = _precision; }

int Arquero::calculaAtaque(Unidad& objetivo) {
    int ataqueBase = Unidad::calculaAtaque(objetivo);
    int probabilidad = rand() % 100 + 1;
    
    if (probabilidad <= precision) {
        int ataqueCritico = ataqueBase * 1.5;
        std::cout << " [Arquero] logra un TIRO CRITICO! (" << ataqueCritico << " pts de dano)!\n";
        return ataqueCritico;
    }
    std::cout << " [Arquero] dispara una flecha normal (" << ataqueBase << " pts de dano).\n";
    return ataqueBase;
}

void Arquero::recibeAtaque(int ptosAtaque) {
    int probabilidad = rand() % 100 + 1;
    if (probabilidad <= (precision / 2)) {
        int danoEvadido = ptosAtaque / 2;
        std::cout << " [Arquero] esquiva rapidamente y reduce el dano a la mitad!\n";
        Unidad::recibeAtaque(danoEvadido);
    } else {
        Unidad::recibeAtaque(ptosAtaque);
    }
}

void Arquero::imprimir() {
    std::cout << "--- ARQUERO ---" << std::endl;
    Unidad::imprimir();
    std::cout << "Precision: " << precision << "%" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}