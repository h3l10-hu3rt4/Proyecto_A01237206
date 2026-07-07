classDiagram
    class Unidad {
        - vida : int
        - salud : int
        - ataque : int
        - nivel : int
        + Unidad()
        + Unidad(int _vida, int _ataque, int _nivel)
        + getVida() : int
        + setVida(int _vida) : void
        + getSalud() : int
        + setSalud(int _salud) : void
        + getAtaque() : int
        + setAtaque(int _ataque) : void
        + getNivel() : int
        + setNivel(int _nivel) : void
        + porcentajeSalud() : int
        + imprimeBarra() : void
        + calculaAtaque(Unidad objetivo) : int
        + recibeAtaque(int ptosAtaque) : void
        + atacar(Unidad objetivo) : void
        + imprimir() : void
    }