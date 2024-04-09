[//]: # (Esto  es un comentario en markdown)
[//]: # (Esto enlaces indica el estado de testeo del codigo para los diferentes sistemas operativos. Mirar [GitHub Actions])
blob/master/.github/workflows/documentation.yaml
[![Actions Status](https://github.com/peterm-m/ProyectoVacio/workflows/MacOS/badge.svg)](https://github.com/peterm-m/ProyectoVacio/actions)
[![Actions Status](https://github.com/peterm-m/ProyectoVacio/workflows/Windows/badge.svg)](https://github.com/peterm-m/ProyectoVacio/actions)
[![Actions Status](https://github.com/peterm-m/ProyectoVacio/workflows/Ubuntu/badge.svg)](https://github.com/peterm-m/ProyectoVacio/actions)
[![Actions Status](https://github.com/peterm-m/ProyectoVacio/workflows/Style/badge.svg)](https://github.com/peterm-m/ProyectoVacio/actions)
[![Actions Status](https://github.com/peterm-m/ProyectoVacio/workflows/Install/badge.svg)](https://github.com/peterm-m/ProyectoVacio/actions)

[//]: # (Este enlaces es para mostrar las metricas resultates de coverage. Indica que pocentaje del codigo ha sido testeado con el conjunto de test actuales. Mirar las referencias de Code coverage)
[![codecov](https://codecov.io/gh/TheLartians/ModernCppStarter/branch/master/graph/badge.svg)](https://codecov.io/gh/TheLartians/ModernCppStarter)

[//]: # (Logo)
<p align="center">
  <img src="https://pbs.twimg.com/profile_images/1479510722149294082/cKKOSG6p_400x400.png" height="175" width="auto" title="Imagen generica" />
</p>

# ProyectoVacio
Un proyecto vacio de C++ en el que estan incoporadas la mayoria de herramientas, convenciones y tecnicas presentes en los proyectos de C++ modernos.
Esta plantilla se puede usar para dos tipos de proyectos:
- [single header libraries](https://en.wikipedia.org/wiki/Header-only)
- Proyectos de sofware de cualquier tamaño que requieran de un mantenimiento y desarrollo continuo.
Este repositorio intenta tener una separacion clara entre las diferentes componentes del proyecto en su jerarquia de directorios.

## Herramientas incorporadas y referencias

### Readme con markdown
- [Referencia markdown](https://daringfireball.net/projects/markdown/)
### CMake
- [Cmake](https://medium.com/@digit.sensitivee/your-start-with-cmake-as-simple-as-it-can-get-4b1c020d4360)
- [Practicas modernas](https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/)
### Test suite
- [Test Suite](https://en.wikipedia.org/wiki/Test_suite)
- Los test estan implementados con [Doctest](https://github.com/doctest/doctest)
- [Doctest tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md)
### Sistema de integracion continua
- [Integracion Continua](https://en.wikipedia.org/wiki/Continuous_integration)
- [GitHub Actions](https://help.github.com/en/actions/)
### Code coverage
- [Code coverage](https://en.wikipedia.org/wiki/Code_coverage)
- La herramienta usada para medir el coverage es [codecov](https://codecov.io)
- [codecov quick-start](https://docs.codecov.io/docs/quick-start)
### Formateado del codigo
- [Formato del codigo](https://www.packtpub.com/en-in/product/clean-code-in-python-1-9781788835831/chapter/introduction-code-formatting-and-tools)
- Se incorpora el formato de codigo usando [clang-format](https://clang.llvm.org/docs/ClangFormat.html) y [cmake-format](https://github.com/cheshirekow/cmake_format) [Format.cmake](https://github.com/TheLartians/Format.cmake)
### Dependency
- [Referencia CPM 1](https://medium.com/swlh/cpm-an-awesome-dependency-manager-for-c-with-cmake-3c53f4376766)
- [Referencia CPM 2](https://ibob.bg/blog/2020/01/13/cmake-package-management/)
- [CPM.cmake](https://github.com/TheLartians/CPM.cmake)
### Package Project
- Installable target with automatic versioning information and header generation via [PackageProject.cmake](https://github.com/TheLartians/PackageProject.cmake)
### AutoDocumentacion
- [Generador de documentacion](https://en.wikipedia.org/wiki/Documentation_generator)
- Documentacion generada con [Doxygen](https://www.doxygen.nl) en [GitHub Pages](https://pages.github.com)
### Code Analyzers
- [Sanitizers](https://github.com/google/sanitizers/wiki)
- Support for [sanitizer tools, and more](#additional-tools)
- Se incorporan algunos [Static Analyzers](https://en.wikipedia.org/wiki/Static_program_analysis) como  [clang-tidy](https://clang.llvm.org/extra/clang-tidy/), [iwyu](https://include-what-you-use.org/) y [cppcheck](https://en.wikipedia.org/wiki/Cppcheck)
- [Ccache](https://ccache.dev/)


## Como usarlo

### Adjust the template to your needs

- Cambia "Ejemplo" en los CMakeList.txt por el nombre del proyecto. "Ejemplo" con mayusculas es el nombre del proyecto. 
- Cambia "ejemplo" en los nombres de archivo y en los #include. "ejemplo" con minuscula se usa para numbres archivos.
- Codigo en el directorio source
- Dependiendo del tipo de proyecto:
  - Para un projecto tipo header-only: Haz los cambios indicados en [CMakeLists.txt](CMakeLists.txt)
- Si quieres usar codecov en el proyecto de guit necesitas generar un [token codecov](https://docs.codecov.io/docs/quick-start) para el proyecto y guardarlo en github secrets con el nombre `CODECOV_TOKEN`
- Eliminar los archivos no utilizados, como el directorio standalone o los workflows que no sean enecesarios. 

En el [CMakeLists.txt](CMakeLists.txt) del directorio actual solo se define la libreria. El resto de archivos CMakeLists.txt  solo definen las librerias los test o las librerias necesarias como subprojectos autocontenidos en su propio directorio.

### Construir y ejecutar el directorio standalone

```bash
cmake -S standalone -B build/standalone
cmake --build build/standalone
./build/standalone/Ejemplo --help
```

### Construir y ejecutar TestSuite

```bash
cmake -S test -B build/test
cmake --build build/test
CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test
./build/test/EjemploTests
```

Si se usa codecoverage, es necesario ejecutar cmake con la opcion -DENABLE_TEST_COVERAGE=1

### ejecutar clang-format

Para corregir errores de formato en el codigo  ejecuta 

```bash
cmake -S test -B build/test

# ver los cambios
cmake --build build/test --target format

# aplicar cambios
cmake --build build/test --target fix-format
```

Si es necesario instalar dependencias ejecuta 

```bash
pip install clang-format==14.0.6 cmake_format==0.6.11 pyyaml
```

### Genera la documentación

Para construir la documentacion localmente es necesario Doxygen, jinja2 y Pygments en el pc

```bash
cmake -S documentation -B build/doc
cmake --build build/doc --target GenerateDocs
# para ver la documentacion generada
open build/doc/doxygen/html/index.html
```

### Construcir todo

```bash
cmake -S all -B build
cmake --build build

# ejecuta test
./build/test/EjemploTests
# formato del codigo
cmake --build build --target fix-format
# ejecutar standalone
./build/standalone/Ejemplo --help
# generar documentacion
cmake --build build --target GenerateDocs
```

### Additional tools

#### Sanitizers

Usa En CMake -DUSE_SANITIZER con alguna de las opciones "Address | Memory | MemoryWithOrigins | Undefined | Thread | Leak " 

#### Static Analyzers

Para usar el Static Analyzers en CMake usa -DUSE_STATIC_ANALYZER con alguna de las opciones "clang-tidy | iwyu | cppcheck" o alguna combinacion separado por  ';'. Algunos argumentos adionales que pueden usarse CLANG_TIDY_ARGS, IWYU_ARGS o CPPCHECK_ARGS.

#### Ccache

Con -DUSE_CCACHE = ON o OFF
