desna tipka na Project->Properties->Linker->Input->Additional Dependencies i unutar toga unjeti slijedeće:
sfml-graphics-d.lib
sfml-system-d.lib
sfml-window-d.lib

također pod C/C++-> Additional Include Directions treba upisati putanju do include foldera nakon što se raspakira .zip file prilikom skidanja SFML biblioteke.
Pod Configuration treba biti odabrano "All Configurations".
