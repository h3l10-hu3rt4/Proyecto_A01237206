#include "Guerrero.hpp"
#include <iostream>

Guerrero::Guerrero() : Unidad() { fuerza = 10; }

Guerrero::Guerrero(int _vida, int _ataque, int _nivel, int _fuerza) 
    : Unidad(_vida, _ataque, _nivel) {
    fuerza = _fuerza;
}

int Guerrero::getFuerza() const { return fuerza; }
void Guerrero::setFuerza(int _fuerza) { fuerza = _fuerza; }

int Guerrero::calculaAtaque(Unidad& objetivo) {
    int ataqueBase = Unidad::calculaAtaque(objetivo);
    int ataqueTotal = ataqueBase + (fuerza / 2);
    std::cout << " [Guerrero] ataca con fuerza bruta (" << ataqueTotal << " pts de dano)!\n";
    return ataqueTotal;
}

void Guerrero::recibeAtaque(int ptosAtaque) {
    int mitigacion = fuerza / 4;
    int danoFinal = ptosAtaque - mitigacion;
    if (danoFinal < 0) danoFinal = 0;
    
    std::cout << " [Guerrero] usa su armadura para mitigar " << mitigacion << " pts de dano.\n";
    Unidad::recibeAtaque(danoFinal);
}

void Guerrero::imprimir() {
    std::cout << "--- GUERRERO ---" << std::endl;
    Unidad::imprimir();
    std::cout << "Fuerza: " << fuerza << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}