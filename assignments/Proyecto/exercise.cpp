#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

int main() {
    // Semilla para los números aleatorios
    srand(time(0));

    std::cout << "=== INICIANDO SIMULADOR DE COMBATE ===\n\n";

    // Instanciando objetos (Vida, Ataque, Nivel, Atributo Especial)
    Guerrero g1(150, 20, 3, 40); // 40 de Fuerza
    Arquero a1(100, 25, 3, 60);  // 60% de Precisión
    Mago m1(80, 30, 4, 50);      // 50 de Maná, Nivel 4

    std::cout << "ESTADO INICIAL:\n";
    g1.imprimir();
    a1.imprimir();
    m1.imprimir();

    std::cout << "\n=== RONDA 1: Mago vs Guerrero ===\n";
    m1.atacar(g1);
    g1.imprimir();

    std::cout << "\n=== RONDA 2: Guerrero vs Arquero ===\n";
    g1.atacar(a1);
    a1.imprimir();

    std::cout << "\n=== RONDA 3: Arquero vs Mago ===\n";
    a1.atacar(m1);
    m1.imprimir();
    
    std::cout << "\n=== RONDA 4: Mago sin Mana vs Arquero ===\n";
    m1.setMana(5); 
    m1.atacar(a1);
    a1.imprimir();

    return 0;
}