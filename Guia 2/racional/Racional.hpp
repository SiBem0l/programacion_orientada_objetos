#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

using namespace std;

class Racional
{
    // Compatibilidad Racional con std::cout
    friend ostream &operator<<(ostream &, const Racional &);

public:
    // Constructores y copias
    Racional(int num = 1, int den = 1);
    Racional(const Racional &);

    //Metodos publicos
    float decimal() const;
    bool esCero() const;
    bool esEntero() const;
    Racional reciproco() const;
    
    // Casteos
    operator float() const;

    // Operaciones matematicas
    Racional operator+(const Racional &) const;
    Racional operator-(const Racional &) const;
    Racional operator*(const Racional &) const;
    Racional operator/(const Racional &) const;

    // + - Unarios
    Racional operator+() const;
    Racional operator-() const;

    // Incrementos y decrementos
    Racional &operator++();   // PRE  incremento
    Racional operator++(int); // POST incremento
    Racional &operator--();   // PRE  decremento
    Racional operator--(int); // POST decremento

    // Operadores relacionales
    bool operator==(const Racional&) const;
    bool operator!=(const Racional&) const;
    bool operator>(const Racional&) const;
    bool operator<(const Racional&) const;
    bool operator>=(const Racional&) const;
    bool operator<=(const Racional&) const;

    // Operadores de asignacion
    Racional &operator=(const Racional &);
    Racional &operator+=(const Racional &);
    Racional &operator-=(const Racional &);
    Racional &operator*=(const Racional &);
    Racional &operator/=(const Racional &);

private: 
    int numerador;
    int denominador;
    void simplificar();
    Racional inversa() const;
    bool esPositivo() const;
    bool esNegativo() const;
};

#endif // RACIONAL_H
