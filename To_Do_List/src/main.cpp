// main.cpp
#include <iostream>
#include <vector>
#include "../include/task.h"

int main() {
    std::vector<task> tasks;
    int opcion;
    std::string archivo = "tasks.txt";

    // Cargar tasks existentes
    cargartasks(tasks, archivo);

    do {
        mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                agregartask(tasks);
                break;
            case 2:
                listartasks(tasks);
                break;
            case 3:
                marcartaskCompleta(tasks);
                break;
            case 4:
                eliminartask(tasks);
                break;
            case 5:
                guardartasks(tasks, archivo);
                std::cout << "tasks guardadas. ¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }

    } while(opcion != 5);

    return 0;
}
