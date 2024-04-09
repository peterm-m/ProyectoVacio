#include <doctest/doctest.h>
#include <ejemplo/ejemplo.h>
#include <ejemplo/version.h>

#include <string>

TEST_CASE("Ejemplo") {
  using namespace ejemplo;

  Ejemplo ejemplo("Tests");

// Esto es un ejemplo de un test

  CHECK(ejemplo.hello(0) == "Hola, 0!");
  CHECK(ejemplo.hello(1) == "Hola, 1!");
  CHECK(ejemplo.hello(2) == "Hola, 2!");
  CHECK(ejemplo.hello(3) == "Hola, 3!");
}

TEST_CASE("Ejemplo version") {
  static_assert(std::string_view(EJEMPLO_VERSION) == std::string_view("1.0"));
  CHECK(std::string(EJEMPLO_VERSION) == std::string("1.0"));
}
