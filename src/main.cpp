#include <iostream>
#include <thread>
#include <vector>

#include "config/SystemConfig.h"

void tarea_dispositivo(int id, uint32_t nuevo_baud) {
    for (int i = 0; i < 5; ++i) {
        SystemConfig::getInstance().setBaudRate(nuevo_baud);
        std::cout << "[Device " << id << "] Escribió baudrate: " << nuevo_baud << std::endl;
    }
}

int main() {
    std::cout << "=== INICIANDO LAB DE CONCURRENCIA ===\n";

    // Creamos 3 hilos (dispositivos) atacando al mismo Singleton
    std::thread t1(tarea_dispositivo, 1, 9600);
    std::thread t2(tarea_dispositivo, 2, 115200);
    std::thread t3(tarea_dispositivo, 3, 57600);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "=== FIN DEL LAB: El Singleton sobrevivió ===\n";
    return 0;
}