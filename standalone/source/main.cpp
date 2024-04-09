#include <ejemplo/ejemplo.h>
#include <ejemplo/version.h>

#include <cxxopts.hpp>
#include <iostream>
#include <string>

auto main(int argc, char** argv) -> int {

  cxxopts::Options options(*argv, "Proyecto Vacio");

  options.add_options()
    ("h,help", "Ayuda")
    ("v,version", "Version")
  ;

  auto result = options.parse(argc, argv);

  if (result["help"].as<bool>()) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (result["version"].as<bool>()) {
    std::cout << "Ejemplo, version " << EJEMPLO_VERSION << std::endl;
    return 0;
  }

  ejemplo::Ejemplo ejemplo("ProyectoVacio");
  std::cout << ejemplo.hello(0) << std::endl;
  std::cout << ejemplo.hello(1) << std::endl;
  return 0;
}
