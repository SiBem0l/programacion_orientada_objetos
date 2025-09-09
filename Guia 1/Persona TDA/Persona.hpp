#ifndef PERSONA_HPP
#define PERSONA_HPP

class Persona
{
    private: //Atributos de la persona
        int edad;
        char* nombre;
    public:
        Persona(int newEdad, char* newNombre);
        ~Persona();
        void saludar();
};

#endif