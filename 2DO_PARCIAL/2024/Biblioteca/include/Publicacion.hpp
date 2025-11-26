// #ifndef PUBLICACION_HPP
// #define PUBLICACION_HPP

// #include <string>
// #include <fstream>
// #include <memory>
// #include "Fecha.hpp"

// class Publicacion
// {
// protected:
//     std::string titulo;
//     std::string autor;
//     Fecha fechaPublicacion;

//     void guardarBinario(std::ofstream &outStream) const;

// public:
//     using dia_type = Fecha::dia_type;
//     using mes_type = Fecha::mes_type;
//     using anio_type = Fecha::anio_type;

//     template <typename T, typename U>
//     Publicacion(T&& titulo, U&& autor, Fecha fecha);
//     virtual ~Publicacion() = default;


//     virtual void guardar(std::ofstream &outStream) const = 0;
//     static std::unique_ptr<Publicacion> leer(std::ifstream &inStream);

//     static void guardarString(const std::string &s, std::ofstream &outStream);
// };

// #endif // PUBLICACION_HPP