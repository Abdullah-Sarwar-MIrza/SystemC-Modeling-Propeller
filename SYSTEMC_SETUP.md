# SystemC & SystemC-AMS Setup Guide

## Environment Configuration Created

This workspace has been configured with the following JSON files in `.vscode/`:

### 1. **c_cpp_properties.json**
   - **Purpose**: Provides include paths and compiler settings for VS Code IntelliSense
   - **Configurations**: 
     - *SystemC & SystemC-AMS* (default): Includes both libraries
     - *SystemC Only*: SystemC core only
     - *SystemC-AMS Only*: SystemC-AMS library only
   - **Includes**:
     - SystemC 3.0.2 source path
     - SystemC-AMS 2.3.4 source path
     - C++17 standard
     - SystemC-specific defines

### 2. **tasks.json**
   - **Purpose**: Defines build tasks executable from VS Code
   - **Available Tasks**:
     - `Build SystemC-AMS Project` (Ctrl+Shift+B): Builds all files using Makefile
     - `Build and Run SystemC-AMS Project`: Builds and executes the program
     - `Clean SystemC-AMS Project`: Cleans build artifacts
     - `Run Executable`: Runs the compiled executable

### 3. **settings.json**
   - **Purpose**: Configures VS Code editor and extension settings
   - **Features**:
     - C++17 standard enabled
     - Code formatting on save
     - IntelliSense optimization for SystemC
     - Tab size set to 4 spaces

### 4. **launch.json**
   - **Purpose**: Enables debugging within VS Code
   - **Configuration**: GDB-based debugging with automatic build before launch

### 5. **Makefile Updates**
   - Updated paths to your local SystemC installations
   - Compiler: `g++.exe` (requires MinGW or similar)

## Prerequisites

Before running the project, you need:

### 1. **C++ Compiler**
   Install one of the following:
   - **MinGW** (Recommended for Windows)
     - Download: https://www.mingw-w64.org/
     - Add to PATH: `C:\MinGW\bin`
   
   - **Visual C++ (MSVC)** 
     - Part of Visual Studio
   
   - **Clang/LLVM**
     - https://releases.llvm.org/

### 2. **SystemC Libraries**
   Verify these are built in your installation:
   - `D:\UAV LAB JOB\Systemc\systemc-3.0.2\build\src` contains `libsystemc.a`
   - `D:\UAV LAB JOB\Systemc\systemc-ams-2.3.4\build\src` contains `libsystemc-ams.a`

### 3. **GDB Debugger** (Optional, for debugging)
   Usually comes with MinGW or can be installed separately

## How to Build & Run

### Option 1: Using VS Code Tasks
1. Press `Ctrl+Shift+B` to run the default build task
2. Or press `Ctrl+Shift+P` and select task:
   - "Build SystemC-AMS Project"
   - "Build and Run SystemC-AMS Project"

### Option 2: Using Terminal
```bash
cd d:\UAV LAB JOB\Systemc\Propeller
make all
make run
```

### Option 3: Using Makefile Targets
```bash
make clean      # Clean build artifacts
make all        # Build executable
make run        # Build and run
```

## Configuration Selection in VS Code

To switch between different configurations:
1. Click on the configuration name in the bottom-right corner of VS Code
2. Select one of:
   - "SystemC & SystemC-AMS" (default)
   - "SystemC Only"
   - "SystemC-AMS Only"

## Debugging

1. Set breakpoints by clicking on line numbers
2. Press `F5` or go to Run → Start Debugging
3. Use the Debug Console to inspect variables and step through code

## Troubleshooting

### Compiler Not Found
- Ensure your compiler is installed and added to Windows PATH
- Update `compilerPath` in `c_cpp_properties.json` if needed

### Include Path Errors
- Verify SystemC installation paths in `c_cpp_properties.json`
- Check that paths use forward slashes `/` not backslashes `\`

### Build Fails
- Run `make clean` first
- Ensure SystemC libraries are built
- Check the Makefile paths match your installation

### IntelliSense Not Working
- Reload VS Code window: `Ctrl+Shift+P` → "Developer: Reload Window"
- Delete `.vscode/browse.VC.db` if it exists
- Restart VS Code

## File Structure
```
d:\UAV LAB JOB\Systemc\Propeller\
├── .vscode/                    # VS Code configuration
│   ├── c_cpp_properties.json  # Include paths & compiler settings
│   ├── tasks.json             # Build tasks
│   ├── settings.json          # Editor settings
│   └── launch.json            # Debugging configuration
├── Makefile                   # Build configuration
├── sc_main.cpp                # Main entry point
├── Motor_module.cpp/h
├── PID_controller_module.cpp/h
├── boom_system.cpp/h
├── hall_sensor.cpp/h
├── reference_model.cpp/h
└── tr.vcd                     # VCD trace file output
```

## Notes

- **VCD Files**: Trace files are generated in `tr.vcd` (viewable with GTKWave)
- **C++ Standard**: Set to C++17 as per your Makefile
- **SystemC-AMS**: Uses TDF (Timed Data Flow) modules
- **Compiler Flags**: Includes debug symbols (-g3), warnings, and C++17 support

---

For more information on SystemC:
- Official: https://www.systemc.org/
- SystemC-AMS: https://www.esa.cs.tu-darmstadt.de/systemc-ams/
