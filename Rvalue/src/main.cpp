#include <iostream>
#include <algorithm> // Necesario para std::copy

class Recurso
{
private:    
    // CORRECCIÓN: 'tam' debe declararse ANTES que 'datos',
    // porque 'datos' depende de 'tam' para su inicialización.
    size_t tam;
    int *datos;

public:
    Recurso(size_t t) : tam(t), datos(new int[t])
    {
        std::cout << "Constructor: " << tam << " elementos\n";
    }

    // Ahora la lista de inicialización está en el orden correcto
    // (tam primero, luego datos)
    Recurso(const Recurso &otro) : tam(otro.tam), datos(new int[tam])
    {
        std::copy(otro.datos, otro.datos + tam, datos);
        std::cout << "COPIA: " << tam << " elementos\n";
    }

    // Ahora la lista de inicialización está en el orden correcto
    Recurso(Recurso &&otro) noexcept : tam(otro.tam), datos(otro.datos)
    {
        otro.datos = nullptr;
        otro.tam = 0;
        std::cout << "MOVIMIENTO: recursos transferidos\n";
    }
    
    ~Recurso()
    {
        // Pequeña mejora: comprobar si datos es nulo 
        // (aunque delete[] nullptr es seguro, es buena práctica 
        // en este caso por el constructor de movimiento)
        delete[] datos;
    }
    
    // Faltaba el operador de asignación por copia (Regla de 3/5)
    Recurso& operator=(const Recurso& otro)
    {
        if (this == &otro)
        {
            return *this;
        }
        
        // Liberar recursos antiguos
        delete[] datos;
        
        // Copiar nuevos recursos
        tam = otro.tam;
        datos = new int[tam];
        std::copy(otro.datos, otro.datos + tam, datos);
        
        std::cout << "ASIGNACION POR COPIA: " << tam << " elementos\n";
        
        return *this;
    }
    
    // Faltaba el operador de asignación por movimiento (Regla de 5)
    Recurso& operator=(Recurso&& otro) noexcept
    {
        if (this == &otro)
        {
            return *this;
        }
        
        // Liberar recursos antiguos
        delete[] datos;
        
        // Robar recursos
        tam = otro.tam;
        datos = otro.datos;
        
        // Dejar al otro objeto en estado válido
        otro.tam = 0;
        otro.datos = nullptr;
        
        std::cout << "ASIGNACION POR MOVIMIENTO: recursos transferidos\n";
        
        return *this;
    }
};

Recurso crear()
{
    Recurso temp(1000);
    return temp; // ✓ Movimiento automático (o RVO)
}

int main()
{
    Recurso r1(100);

    // Constructor de copia (r1 es lvalue)
    Recurso r2 = r1; // Salida: COPIA: 100 elementos

    // Constructor de movimiento (temporal es rvalue)
    Recurso r3 = crear(); // Salida: MOVIMIENTO (o nada, por RVO)

    // Constructor de movimiento (función retorna rvalue)
    Recurso r4 = Recurso(50); // Salida: CONSTRUCTOR: 50 ... (y MOVIMIENTO)

    // Prueba de asignaciones
    Recurso r5(10);
    r5 = r1; // Asignación por copia
    r5 = crear(); // Asignación por movimiento

    return 0;
}