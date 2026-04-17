#include <gtest/gtest.h>

#include "SystemConfig.h"

// Test 1: Verificar que siempre obtenemos la misma instancia (dirección de memoria)
TEST(SingletonSuite, IdentityTest) {
    SystemConfig& instance1 = SystemConfig::getInstance();
    SystemConfig& instance2 = SystemConfig::getInstance();

    EXPECT_EQ(&instance1, &instance2) << "Error: Las direcciones de memoria son distintas";
}

// Test 2: Verificar que los datos persisten globalmente
TEST(SingletonSuite, DataPersistenceTest) {
    SystemConfig::getInstance().setBaudRate(9600);

    // Simulamos acceso desde otra parte del código
    uint32_t currentBaud = SystemConfig::getInstance().getBaudRate();
    EXPECT_EQ(currentBaud, 9600);
}