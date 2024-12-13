// task.h
#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

// Estructura

struct task
{
    int id;
    std::string descripcion;
    std::string fechaLimite;
    std::string prioridad;
    bool completada;

};

//Funciones
void mostrarMenu();
void agregartask(std::vector<task> &tasks);
void listartasks(const std::vector<task> &tasks);
void marcartaskCompleta(std::vector<task> &tasks);
void eliminartask(std::vector<task> &tasks);
void guardartasks(const std::vector<task> &tasks, const std::string &nombreArchivo);
void cargartasks(std::vector<task> &tasks, const std::string &nombreArchivo);

#endif // TASK_H

