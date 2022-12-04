# Notes

Updated for Windows 11 and can be broken in legacy systems in reason of Windows SDK,
function to render screen was updated from `WriteConsoleOutputCharacter` to `WriteConsoleOutputCharacterW` to support unicode charters
stored in `src/Game/Prefab.cpp` like `░`

To run `bin/Rogesci.exe` use legacy terminal (Command Prompt) and update some properties.
 - Font: Consolas
 - Layout - Window Size W:120 H:40
 