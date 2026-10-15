# SystemC Modeling of a Propeller System

A SystemC-based ESL (Electronic System Level) simulation model designed to simulate and analyze the behavior, timing, and control response of a propeller system.

---

## 📌 Project Overview
This project models the functional architecture of a propeller system using **SystemC**. It includes control logic, driver interface, and behavioral models to simulate motor speeds and thrust outputs based on control input signals.

- **Language:** C++ / SystemC
- **Level:** Behavioral / Transaction-Level Modeling (TLM)
- **Application:** Embedded system hardware modeling, control logic evaluation, and waveform trace analysis.

---

## 🛠️ Prerequisites
- **C++ Compiler:** `g++` (v7.0+) or `clang++` with C++11/C++14 support
- **SystemC Core Library:** Accellera SystemC 2.3.x or later
- **Build System:** `make` or `cmake`
- **Waveform Viewer (Optional):** GTKWave for inspecting VCD traces

---

## 🚀 Getting Started

### 1. Set SystemC Path
Export the path to your local SystemC installation:
```bash
export SYSTEMC_HOME=/usr/local/systemc-2.3.3
export LD_LIBRARY_PATH=$SYSTEMC_HOME/lib-linux64:$LD_LIBRARY_PATH

```

### 2. Clone the Repository

```bash
git clone [https://github.com/Abdullah-Sarwar-MIrza/SystemC-Modeling-Propeller.git](https://github.com/Abdullah-Sarwar-MIrza/SystemC-Modeling-Propeller.git)
cd SystemC-Modeling-Propeller

```

### 3. Compile & Run

If using **Make**:

```bash
make
./sim

```

If using **CMake**:

```bash
mkdir build && cd build
cmake ..
make
./sim

```

---

## 📊 Viewing Simulation Output

If VCD tracing is enabled in the testbench, view the generated execution waveforms using GTKWave:

```bash
gtkwave waveform.vcd

```



```
