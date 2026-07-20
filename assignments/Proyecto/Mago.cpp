#include "Mago.hpp"
#include <iostream>

Mago::Mago() : Unidad() { mana = 100; }

Mago::Mago(int _vida, int _ataque, int _nivel, int _mana) 
    : Unidad(_vida, _ataque, _nivel) {
    mana = _mana;
}

int Mago::getMana() const { return mana; }
void Mago::setMana(int _mana) { mana = _mana; }

int Mago::calculaAtaque(Unidad& objetivo) {
    int ataqueBase = Unidad::calculaAtaque(objetivo);
    
    if (mana >= 20) {
        mana -= 20;
        int ataqueMagico = ataqueBase * 2;
        std::cout << " [Mago] conjura un hechizo poderoso! -20 Mana (" << ataqueMagico << " pts de dano)!\n";
        return ataqueMagico;
    } else {
        mana += 10;
        int ataqueDebil = ataqueBase / 2;
        std::cout << " [Mago] esta exhausto y ataca con su baculo, pero recupera mana. +10 Mana (" << ataqueDebil << " pts de dano).\n";
        return ataqueDebil;
    }
}

void Mago::recibeAtaque(int ptosAtaque) {
    if (getNivel() > 2 && mana >= 10) {
        mana -= 10;
        int danoReducido = ptosAtaque * 0.7; // Absorbe 30%
        std::cout << " [Mago] activa Escudo de Mana! -10 Mana. Absorbe parte del impacto.\n";
        Unidad::recibeAtaque(danoReducido);
    } else {
        Unidad::recibeAtaque(ptosAtaque);
    }
    
    // Validar si murió para intentar revivir
    if (getSalud() <= 0) {
        revive();
    }
}

void Mago::revive() {
    if (mana >= 40) {
        std::cout << "\n [!] El Mago ha caido... PERO REVIVE USANDO SU MAGIA! (-40 Mana)\n";
        setSalud(getVida() / 2); // Revive con la mitad de la vida total
        mana -= 40;              // Consume el mana
    } else {
        std::cout << "\n [X] El Mago ha MUERTO definitivamente. No tiene mana suficiente para revivir.\n";
    }
}

void Mago::imprimir() {
    std::cout << "--- MAGO ---" << std::endl;
    Unidad::imprimir();
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}