#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

int main() {
    srand(time(0));
    std::cout << "=== INICIANDO SIMULADOR: POLIMORFISMO ===\n\n";

    // 1. Crear vector de apuntadores y objetos dinámicos
    std::vector<Unidad*> combatientes;
    combatientes.push_back(new Guerrero(150, 20, 3, 40));
    combatientes.push_back(new Arquero(100, 25, 3, 60));
    combatientes.push_back(new Mago(80, 30, 4, 80)); // 80 de maná para asegurar que pueda revivir

    // 2. Ciclo FOR para imprimir los tres personajes
    std::cout << "--- PRESENTACION DE COMBATIENTES ---\n";
    for (int i = 0; i < combatientes.size(); i++) {
        combatientes[i]->imprimir();
    }

    // 3. Ciclo FOR para hacerlos pelear en cadena
    std::cout << "\n--- INICIA EL COMBATE EN CADENA ---\n";
    for (int i = 0; i < combatientes.size() - 1; i++) {
        std::cout << "\n>>> Ronda " << i + 1 << " <<<\n";
        // El de la posición actual ataca al de la siguiente posición
        combatientes[i]->atacar(*combatientes[i+1]);
        combatientes[i+1]->imprimir();
    }

    // 4. Probar la sobrecarga del operador << y forzar el revive()
    std::cout << "\n--- PRUEBA DE SOBRECARGA Y RESURRECCION ---\n";
    
    // Imprimiendo con el operador sobrecargado usando el valor apuntado (*)
    std::cout << "Estado rapido del Mago: " << *combatientes[2] << "\n";
    
    std::cout << "\nUn meteoro gigante cae sobre el Mago!\n";
    // Le quitamos 500 de salud de golpe para forzar que llegue a 0 y se ejecute su revive()
    combatientes[2]->recibeAtaque(500); 
    
    std::cout << "\nEstado final del Mago: " << *combatientes[2] << "\n";

    // 5. Liberar la memoria dinámica para evitar fugas (Memory Leaks)
    for (int i = 0; i < combatientes.size(); i++) {
        delete combatientes[i];
    }

    return 0;
}