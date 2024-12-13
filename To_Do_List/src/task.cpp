#include "task.h"
#include <iostream>
#include <fstream>

//Funcion de menu

void mostrarMenu(){
        std::cout << "\n=== Sistema de Gestión de tasks ===\n";
    std::cout << "1. Agregar task\n";
    std::cout << "2. Listar tasks\n";
    std::cout << "3. Marcar task como Completada\n";
    std::cout << "4. Eliminar task\n";
    std::cout << "5. Guardar y Salir\n";
}

void agregartask(std::vector<task> &tasks) {
    task nuevatask;
    static int contador = 1; // Para asignar un ID único

    std::cin.ignore(); // Limpiar el buffer

    nuevatask.id = contador++;

    std::cout << "Ingrese la descripción de la task: ";
    std::getline(std::cin, nuevatask.descripcion);

    std::cout << "Ingrese la fecha límite (DD/MM/AAAA): ";
    std::getline(std::cin, nuevatask.fechaLimite);

    std::cout << "Ingrese la prioridad (Alta, Media, Baja): ";
    std::getline(std::cin, nuevatask.prioridad);

    nuevatask.completada = false;

    tasks.push_back(nuevatask);

    std::cout << "task agregada exitosamente.\n";
}

// Función para listar todas las tasks
void listartasks(const std::vector<task> &tasks) {
    if(tasks.empty()) {
        std::cout << "No hay tasks para mostrar.\n";
        return;
    }

    std::cout << "\n--- Lista de tasks ---\n";
    for(const auto &task : tasks) {
        std::cout << "ID: " << task.id << "\n";
        std::cout << "Descripción: " << task.descripcion << "\n";
        std::cout << "Fecha Límite: " << task.fechaLimite << "\n";
        std::cout << "Prioridad: " << task.prioridad << "\n";
        std::cout << "Completada: " << (task.completada ? "Sí" : "No") << "\n";
        std::cout << "--------------------------\n";
    }
}

// Función para marcar una task como completada
void marcartaskCompleta(std::vector<task> &tasks) {
    int id;
    std::cout << "Ingrese el ID de la task a marcar como completada: ";
    std::cin >> id;

    for(auto &task : tasks) {
        if(task.id == id) {
            task.completada = true;
            std::cout << "task marcada como completada.\n";
            return;
        }
    }

    std::cout << "task con ID " << id << " no encontrada.\n";
}

// Función para eliminar una task
void eliminartask(std::vector<task> &tasks) {
    int id;
    std::cout << "Ingrese el ID de la task a eliminar: ";
    std::cin >> id;

    for(auto it = tasks.begin(); it != tasks.end(); ++it) {
        if(it->id == id) {
            tasks.erase(it);
            std::cout << "task eliminada exitosamente.\n";
            return;
        }
    }

    std::cout << "task con ID " << id << " no encontrada.\n";
}

// Función para guardar las tasks en un archivo
void guardartasks(const std::vector<task> &tasks, const std::string &nombreArchivo) {
    std::ofstream archivoSalida(nombreArchivo);

    if(!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for(const auto &task : tasks) {
        archivoSalida << task.id << "|" 
                      << task.descripcion << "|" 
                      << task.fechaLimite << "|" 
                      << task.prioridad << "|" 
                      << task.completada << "\n";
    }

    archivoSalida.close();
}

// Función para cargar las tasks desde un archivo
void cargartasks(std::vector<task> &tasks, const std::string &nombreArchivo) {
    std::ifstream archivoEntrada(nombreArchivo);
    if(!archivoEntrada.is_open()) {
        // Si el archivo no existe, no hacemos nada
        return;
    }

    std::string linea;
    while(std::getline(archivoEntrada, linea)) {
        task task;
        size_t pos = 0;
        size_t nextPos;

        // ID
        nextPos = linea.find('|', pos);
        task.id = std::stoi(linea.substr(pos, nextPos - pos));
        pos = nextPos + 1;

        // Descripción
        nextPos = linea.find('|', pos);
        task.descripcion = linea.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        // Fecha Límite
        nextPos = linea.find('|', pos);
        task.fechaLimite = linea.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        // Prioridad
        nextPos = linea.find('|', pos);
        task.prioridad = linea.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        // Completada
        task.completada = (std::stoi(linea.substr(pos)) == 1);

        tasks.push_back(task);
    }

    archivoEntrada.close();
}