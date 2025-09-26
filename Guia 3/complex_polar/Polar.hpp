#ifndef POLAR_HPP
#define POLAR_HPP

#include "Complex.hpp"

class Polar : public Complex
{
public:
    Polar();
    Polar(float, float);
    float GetModulo();
    void SetModulo(float);
    float GetFase();
    void SetFase(float);
    float Modulo(Complex&);
    float Fase(Complex&);
    float Modulo();
    friend Complex Rectang(float, float);
    void operator= (Complex);
    
private:
    float fModulo;
    float fFase;
    
};

#endif