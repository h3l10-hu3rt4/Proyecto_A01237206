#ifndef GUERRERO_HPP
#define GUERRERO_HPP
#include "Unidad.hpp"

class Guerrero : public Unidad {
private:
    int fuerza;
public:
    Guerrero();
    Guerrero(int _vida, int _ataque, int _nivel, int _fuerza);
    
    int getFuerza() const;
    void setFuerza(int _fuerza);
    
    int calculaAtaque(Unidad& objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;
};
#endif