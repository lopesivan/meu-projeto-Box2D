from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        # escolha uma versao:
        # self.requires("box2d/3.1.1") # C PURO
        self.requires("box2d/2.4.1")  # C++

    def layout(self):
        cmake_layout(self)
