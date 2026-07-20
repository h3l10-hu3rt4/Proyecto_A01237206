#ifndef UNIDAD_HPP
#define UNIDAD_HPP
#include <iostream>

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    Unidad();
    Unidad(int _vida, int _ataque, int _nivel);
    virtual ~Unidad() = default;

    int getVida() const;
    void setVida(int _vida);
    int getSalud() const;
    void setSalud(int _salud);
    int getAtaque() const;
    void setAtaque(int _ataque);
    int getNivel() const;
    void setNivel(int _nivel);

    int porcentajeSalud();
    void imprimeBarra();
    
    virtual int calculaAtaque(Unidad& objetivo);
    virtual void recibeAtaque(int ptosAtaque);
    virtual void imprimir();
    void atacar(Unidad& objetivo); 

    virtual void revive() = 0; 

    friend std::ostream& operator<<(std::ostream& os, const Unidad& u);
};

#endif