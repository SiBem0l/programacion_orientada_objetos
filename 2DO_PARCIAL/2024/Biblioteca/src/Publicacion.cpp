// #include "Publicacion.hpp"
// #include <iostream>
// #include <stdexcept>

// template <typename T, typename U>
// Publicacion::Publicacion(T &&titulo, U &&autor, Fecha fecha)
//     : titulo(std::forward<T>(titulo)),
//       autor(std::forward<U>(autor)),
//       fechaPublicacion(fecha)
// {
// }


// static void guardarString(const std::string &s, std::ofstream &outStream)
// {
//     std::string::size_type lenght = s.size();
//     outStream.write(reinterpret_cast<const char *>(&lenght), sizeof(lenght));
//     outStream.write(s.data(), lenght);
// }
// void Publicacion::guardarBinario(std::ofstream &outStream) const
// {
//     if (outStream.fail())
//     {
//         throw std::runtime_error("Archivo no abrio para guardado de publicacion.");
//     }

//     guardarString(titulo, outStream);
//     guardarString(autor, outStream);
//     fechaPublicacion.guardadBinario(outStream);
// }

// static std::string leerString(std::ifstream &inStream)
// {
//     std::string s;
//     std::string::size_type lenght;
//     inStream.read(reinterpret_cast<char *>(&lenght), sizeof(lenght));
//     s.resize(lenght);
//     inStream.read(s.data(), lenght);

//     return s;
// }
// std::unique_ptr<Publicacion> Publicacion::leer(std::ifstream &inStream)
// {
//     if (inStream.fail())
//     {
//         throw std::runtime_error("Archivo no abrio para lecutra de publicacion.");
//     }

//     std::string titulo(leerString(inStream));
//     std::string autor(leerString(inStream));
//     Fecha fechaPublicacion(Fecha::leerBinario(inStream));

//     std::unique_ptr ptr = std::make_unique<Publicacion>(std::move(titulo),
//                                                         std::move(autor),
//                                                         fechaPublicacion);

//     return ptr;
// }