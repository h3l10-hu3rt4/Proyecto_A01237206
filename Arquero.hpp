#ifndef ARQUERO_HPP
#define ARQUERO_HPP
#include "Unidad.hpp"

class Arquero : public Unidad {
private:
    int precision;
public:
    Arquero();
    Arquero(int _vida, int _ataque, int _nivel, int _precision);
    
    int getPrecision() const;
    void setPrecision(int _precision);
    
    int calculaAtaque(Unidad& objetivo) override;
    void recibeAtaque(int ptosAtaque) override;
    void imprimir() override;
};
#endif