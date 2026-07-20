#ifndef UNIDAD_HPP
#define UNIDAD_HPP

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // Constructores y Destructor
    Unidad();
    Unidad(int _vida, int _ataque, int _nivel);
    virtual ~Unidad() = default;
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
    
    // Métodos virtuales que serán sobreescritos (redefinidos) por las clases hijas
    virtual int calculaAtaque(Unidad& objetivo);
    virtual void recibeAtaque(int ptosAtaque);
    virtual void imprimir();
    
    // Este método se queda normal porque su lógica consiste en mandar a llamar a calculaAtaque y recibeAtaque
    void atacar(Unidad& objetivo); 
};

#endif