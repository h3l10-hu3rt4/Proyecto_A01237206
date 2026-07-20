#include "Unidad.hpp"
#include <iostream>
#include <cstdlib> // Para rand()

// 2. Constructores
Unidad::Unidad() {
    vida = 100;
    salud = 100;
    ataque = 10;
    nivel = 1;
}

Unidad::Unidad(int _vida, int _ataque, int _nivel) {
    vida = _vida;
    salud = _vida;
    ataque = _ataque;
    nivel = _nivel;
}

// Getters y Setters
int Unidad::getVida() const { return vida; }
void Unidad::setVida(int _vida) { vida = _vida; }

int Unidad::getSalud() const { return salud; }
void Unidad::setSalud(int _salud) { salud = _salud; }

int Unidad::getAtaque() const { return ataque; }
void Unidad::setAtaque(int _ataque) { ataque = _ataque; }

int Unidad::getNivel() const { return nivel; }
void Unidad::setNivel(int _nivel) { nivel = _nivel; }

// 3. Método que calcule su porcentaje de salud
int Unidad::porcentajeSalud() {
    if (vida <= 0) return 0;
    return (salud * 100) / vida;
}

// 4. Método que imprima su barra de vida (20 caracteres en total)
void Unidad::imprimeBarra() {
    int pct = porcentajeSalud();
    // Cada carácter equivale a un 5% (100% / 20 caracteres = 5%)
    int caracteresVida = pct / 5; 
    int caracteresPerdidos = 20 - caracteresVida;

    for (int i = 0; i < caracteresVida; i++) {
        std::cout << "%";
    }
    for (int i = 0; i < caracteresPerdidos; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

// 5. Método que calcule los puntos de ataque de acuerdo al objetivo
int Unidad::calculaAtaque(Unidad& objetivo) {
    int puntos = 0;
    int mitadAtaque = ataque / 2;

    if (mitadAtaque < 1) mitadAtaque = 1; // Evitar rangos inválidos si el ataque es muy bajo

    if (objetivo.getNivel() > nivel) {
        // Aleatorio entre 1 y la mitad del ataque
        puntos = rand() % mitadAtaque + 1;
    } else {
        // Aleatorio entre la mitad del ataque y el total del ataque
        int rango = ataque - mitadAtaque + 1;
        puntos = rand() % rango + mitadAtaque;
    }
    return puntos;
}

// 6. Método para descontar puntos de un ataque
void Unidad::recibeAtaque(int ptosAtaque) {
    salud -= ptosAtaque;
    if (salud < 0) {
        salud = 0;
    }
}

// 7. Método para atacar a otra unidad
void Unidad::atacar(Unidad& objetivo) {
    int daño = calculaAtaque(objetivo);
    objetivo.recibeAtaque(daño);
}

// 8. Método para visualizar el estado de la unidad
void Unidad::imprimir() {
    std::cout << "Nivel: " << nivel << " | Vida: " << salud << "/" << vida << " | Ataque Base: " << ataque << std::endl;
    std::cout << "Barra de Salud: ";
    imprimeBarra();
    std::cout << "----------------------------------------" << std::endl;
}

// Sobrecarga del operador
std::ostream& operator<<(std::ostream& os, const Unidad& u) {
    os << "[Nivel " << u.getNivel() << "] Salud: " << u.getSalud() << "/" << u.getVida() << " | Atk: " << u.getAtaque();
    return os;
}