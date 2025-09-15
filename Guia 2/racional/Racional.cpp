#include "Racional.hpp"
#include <cmath>

// Constructor y copia
Racional::Racional(int num, int den) : numerador(num),
                                       denominador(den)
{
    if (denominador == 0)
    {
        denominador = 1;
    }
    simplificar();
}

Racional::Racional(const Racional &r1)
{
    numerador = r1.numerador;
    denominador = r1.denominador;
}

// Metodos
static int mcd(int a, int b)
{
    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
void Racional::simplificar()
{
    int divisor = mcd(abs(numerador), abs(denominador));
    numerador = numerador / divisor;
    denominador = denominador / divisor;
    if (denominador < 0)
    {
        numerador = -numerador;
        denominador = -denominador;
    }
}

Racional Racional::inversa() const
{
    return Racional(denominador, numerador);
}

bool Racional::esPositivo() const
{
    bool esPositivo = true;
    if (numerador < 0)
    {
        esPositivo = !esPositivo;
    }
    if (denominador < 0)
    {
        esPositivo = !esPositivo;
    }
    return esPositivo;
}

bool Racional::esNegativo() const
{
    return !(this->esPositivo());
}

// Sobrecarga de operadores
ostream &operator<<(ostream &outStream, const Racional &r1)
{
    outStream << r1.numerador << "/" << r1.denominador;
    return outStream;
}

Racional Racional::operator+(const Racional &r1) const
{
    Racional ans;
    ans.numerador = (this->numerador * r1.denominador) + (this->denominador * r1.numerador);
    ans.denominador = this->denominador * r1.denominador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator-(const Racional &r1) const
{
    Racional ans;
    ans.numerador = (this->numerador * r1.denominador) + (this->denominador * r1.numerador * (-1));
    ans.denominador = this->denominador * r1.denominador;
    ans.simplificar();
    return ans;
}

Racional Racional::operator*(const Racional &r1) const
{
    Racional ans(numerador * r1.numerador, denominador * r1.denominador);
    ans.simplificar();
    return ans;
}

Racional Racional::operator/(const Racional &r1) const
{
    return (*this) * (r1.inversa());
}

// + - Unarios
Racional Racional::operator+() const
{
    Racional ans;
    if (this->esPositivo())
    {
        ans = *this;
    }
    else if (this->esNegativo())
    {
        ans = -(*this);
    }
    return ans;
}

Racional Racional::operator-() const
{
    return (Racional(-1, 1) * (*this));
}


// Incrementos y decrementos
Racional &Racional::operator++() // preincrementos
{
    *this = *this + Racional(1, 1);
    return *this;
}

Racional Racional::operator++(int) // postincremento
{
    Racional temp(*this);
    *this = *this + Racional(1, 1);
    return temp;
}

Racional &Racional::operator--() // predecremento
{
    *this = *this - Racional(1, 1);
    return *this;
}

Racional Racional::operator--(int) // postdecremento
{
    Racional temp(*this);
    *this = *this - Racional(1, 1);
    return temp;
}

// Operadores relacionales
bool Racional::operator==(const Racional& number) const
{
    bool iguales = false;
    if(numerador == number.numerador && denominador == number.denominador)
    {
        iguales = true;
    }
    return iguales;
}

bool Racional::operator!=(const Racional& number) const
{
    return !(*this == number);
}

bool Racional::operator>(const Racional& number) const
{
    return (numerador*number.denominador > number.numerador*denominador);
}

bool Racional::operator<(const Racional& number) const
{
    return (numerador*number.denominador < number.numerador*denominador);
}

bool Racional::operator>=(const Racional& number) const
{
    return (numerador*number.denominador >= number.numerador*denominador);
}

bool Racional::operator<=(const Racional& number) const
{
    return (numerador*number.denominador <= number.numerador*denominador);
}

// Funciones publicas
float Racional::decimal() const
{
    return static_cast<double>(numerador)/denominador;
}

bool Racional::esCero() const
{
    return numerador == 0;
}

bool Racional::esEntero() const
{
    return denominador == 1;
}

Racional Racional::reciproco() const
{
    return Racional(this->inversa());
}

// Casteo
Racional::operator float() const
{
    return static_cast<double>(numerador)/denominador;
}

// Operadores de asignacion
Racional &Racional::operator=(const Racional &number)
{
    this->numerador = number.numerador;
    this->denominador = number.denominador;
    return *this;
}

Racional &Racional::operator+=(const Racional &number)
{
    *this = *this + number;
    return *this;
}

Racional &Racional::operator-=(const Racional &number)
{
    *this = *this - number;
    return *this;
}

Racional &Racional::operator*=(const Racional &number)
{
    *this = *this * number;
    return *this;
}

Racional &Racional::operator/=(const Racional &number)
{
    *this = *this / number;
    return *this;
}