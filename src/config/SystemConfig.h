#ifndef CONFIG_H
#define CONFIG_H

#include <chrono>
#include <cstdint>
#include <mutex>  // Nueva librería para el candado
#include <thread>

class SystemConfig {
   public:
    static SystemConfig& getInstance() {
        static SystemConfig instance;
        return instance;
    }
    /*
    solo se llama 1 vez / NO se vuelve a crear
    siempre devuelve la misma referencia
    */

    SystemConfig(const SystemConfig&) = delete;  // Estás eliminando el Constructor de Copia.
    SystemConfig& operator=(const SystemConfig&) =
        delete;  // Estás eliminando el Operador de Asignación.
    /*
    Estás garantizando la identidad única del objeto. Si alguien intenta copiarlo o asiganalo,
    el compilador detendrá la ejecución antes de que llegue al chip.
    */

    // Métodos de ejemplo para el laboratorio
    void setBaudRate(uint32_t baud) {
        std::lock_guard<std::mutex> lock(mtx);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        baudRate = baud;
    }
    uint32_t getBaudRate() const {
        std::lock_guard<std::mutex> lock(mtx);
        return baudRate;
    }

   private:
    SystemConfig() : baudRate(115200) {}  // Constructor privado
    uint32_t baudRate;
    mutable std::mutex mtx;
};

#endif

/*
1. SystemConfig(const SystemConfig&) = delete;
Qué es: Estás eliminando el Constructor de Copia.

Consecuencia: Si alguien intenta hacer algo como SystemConfig miCopia = instanciaOriginal;, el
compilador generará un error inmediatamente. No permites que existan dos objetos con el mismo estado
en diferentes posiciones de memoria.

2. SystemConfig& operator=(const SystemConfig&) = delete;
Qué es: Estás eliminando el Operador de Asignación.

Consecuencia: Evitas que una instancia ya existente sea sobrescrita por otra: instanciaA =
instanciaB;.
*/