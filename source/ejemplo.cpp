#include <fmt/format.h>
#include <ejemplo/ejemplo.h>

using namespace ejemplo;

Ejemplo::Ejemplo(std::string _name) : name(std::move(_name)) {}

std::string Ejemplo::hello(int num) const {
  return fmt::format("Hola, {}!", num);
}
