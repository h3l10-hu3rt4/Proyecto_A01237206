#ifndef UNIDAD_HPP
#define UNIDAD_HPP

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // Constructores
    Unidad();
    Unidad(int _vida, int _ataque, int _nivel);

    // Getters y Setters
    int getVida() const;
    void setVida(int _vida);

    int getSalud() const;
    void setSalud(int _salud);

    int getAtaque() const;
    void setAtaque(int _ataque);

    int getNivel() const;
    void setNivel(int _nivel);

    // Combate y visualización
    int porcentajeSalud();
    void imprimeBarra();
    int calculaAtaque(Unidad& objetivo);
    void recibeAtaque(int ptosAtaque);
    void atacar(Unidad& objetivo);
    void imprimir();
};

#endif