# Thread-Safe Singleton Design Pattern Lab

This repository features a professional-grade implementation of the **Singleton Design Pattern** in C++. It is specifically architected for embedded systems (such as ESP32 or STM32) and high-performance applications where resource integrity and thread safety are critical.

## 🎯 Project Objective

The goal of this lab is to demonstrate how to centralize access to a unique hardware resource (e.g., UART configuration, Baudrate registers, or Global State) while ensuring:
1.  **Unique Identity:** Prevention of object duplication or accidental cloning.
2.  **Thread-Safety:** Protection against race conditions in multi-core or multi-tasking environments (RTOS/Linux).
3.  **Memory Efficiency:** Utilizing "Lazy Initialization" to minimize RAM footprint.

## 🛠️ Technical Architecture

### 1. The Singleton Pattern (Meyers' Implementation)
The `SystemConfig` class ensures a single point of truth by using:
- **Private Constructor:** Prevents direct instantiation.
- **Deleted Copy Constructor:** `SystemConfig(const SystemConfig&) = delete;`
- **Deleted Assignment Operator:** `SystemConfig& operator=(const SystemConfig&) = delete;`

This ensures that the compiler stops any attempt to duplicate the object before it ever reaches the hardware.

### 2. Concurrence & Thread-Safety
The lab simulates a high-stress environment where multiple "virtual devices" (threads) attempt to access the configuration simultaneously:
- **`std::mutex`:** Acts as the hardware lock.
- **RAII `std::lock_guard`:** Automatically manages the locking/unlocking lifecycle to prevent system deadlocks.



### 3. Header-Only Interface
The library is designed as a **CMake INTERFACE**, allowing for a lightweight, header-only integration that simplifies portability across different embedded toolchains.

## 🚀 Getting Started

### Prerequisites
- **Docker** and **Docker Compose**
- A C++11 (or higher) compatible compiler

### Build Instructions
```bash
# Enter the build directory
mkdir -p build && cd build

# Configure and Compile
cmake ..
make

./src/cxx_app
./test/test_runner

Developed by: Jesus Jimenez (Tyler Jmz)

Systems & Data Engineer | Iot Edge Engineer