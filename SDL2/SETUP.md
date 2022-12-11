# Configure SDL2

In case if you have build errors: `LNK2019` and `LNK1120`

## Windows 10/11 and Visual Studio 2022

Use `vcpkg` to install SDL2 library, then configure the project in VS.
Use the correct lib version for the platform on x64 or x86.

### 0. Go to VS, Open Project Properties
### 1. Edit properties: VC++ Directories/Library Directories

#### Debug cfg:
`$(VCPKG_ROOT)\installed\x64-windows\debug\lib\manual-link`

### Release cfg:
`$(VCPKG_ROOT)\installed\x64-windows\lib\manual-link`

### 2. Edit properties: Linker/Input/Additional Dependencies

#### Debug add:
`SDL2maind.lib`

### Release cfg:
`SDL2main.lib`

P.S. `VCPKG_ROOT` can be not defined in your Windows environment variables, do that manually then.
