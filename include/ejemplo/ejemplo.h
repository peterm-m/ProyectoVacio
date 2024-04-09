#pragma once

#include <string>

namespace ejemplo {

  /**
   * @brief Esto es una clase de ejemplo 
   */
  class Ejemplo {
    std::string name;

  public:
    /**
     * @brief Creates a new ejemplo
     * @param name para ejemplo
     */
    Ejemplo(std::string name);

    /**
     * @brief Crea una cadena de texto que dice hola
     * @param num para imprimir que añade a la cadena
     * @return retorna una cadena con el texto "Hola, {num}!"
     */
    std::string hello(int num) const;
  };

}  // namespace ejemplo
