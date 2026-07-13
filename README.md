```mermaid
---
config:
  layout: elk
---
classDiagram
    class Unidad {
        - vida : int
        - salud : int
        - ataque : int
        - nivel : int
        + Unidad()
        + Unidad(int _vida, int _ataque, int _nivel)
        + getVida() int
        + setVida(int _vida) void
        + getSalud() int
        + setSalud(int _salud) void
        + getAtaque() int
        + setAtaque(int _ataque) void
        + getNivel() int
        + setNivel(int _nivel) void
        + porcentajeSalud() int
        + imprimeBarra() void
        + calculaAtaque(Unidad objetivo) int
        + recibeAtaque(int ptosAtaque) void
        + atacar(Unidad objetivo) void
        + imprimir() void
    }

    class Guerrero {
        - fuerza : int
        + Guerrero()
        + Guerrero(int _vida, int _ataque, int _nivel, int _fuerza)
        + getFuerza() int
        + setFuerza(int _fuerza) void
        + calculaAtaque(Unidad objetivo) int
        + recibeAtaque(int ptosAtaque) void
        + imprimir() void
    }

    class Arquero {
        - precision : int
        + Arquero()
        + Arquero(int _vida, int _ataque, int _nivel, int _precision)
        + getPrecision() int
        + setPrecision(int _precision) void
        + calculaAtaque(Unidad objetivo) int
        + recibeAtaque(int ptosAtaque) void
        + imprimir() void
    }

    class Mago {
        - mana : int
        + Mago()
        + Mago(int _vida, int _ataque, int _nivel, int _mana)
        + getMana() int
        + setMana(int _mana) void
        + calculaAtaque(Unidad objetivo) int
        + recibeAtaque(int ptosAtaque) void
        + imprimir() void
    }

    Unidad <|-- Guerrero
    Unidad <|-- Arquero
    Unidad <|-- Mago