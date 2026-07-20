#ifndef MAGO_HPP
#define MAGO_HPP
#include "Unidad.hpp"

class Mago : public Unidad {
private:
    int mana;
public:
    Mago();
    Mago(int _vida, int _ataque, int _nivel, int _mana);
    
    int getMana() const;
    void setMana(int _mana);
    
    int calculaAtaque(Unidad& objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;
};
#endif