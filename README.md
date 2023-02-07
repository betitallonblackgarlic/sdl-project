# sdl-project

## Some design ideas

the window is top of the heirarchy, as such, I'm going to try declaring it as a global static

there only needs to be one renderer but it relies on window so declared as static within main window function

all classes that manage data that needs to be updated will be managed by the render manager

the texture manager loads things into memory but access needs to be made by rendering systems so will i need to allow render manager to access texture components? the memory will be managed by another high-level system, so maybe that's okay
