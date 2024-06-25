# miniRT

// check open file descriptor in the current process
	printf("Listing open file descriptors using lsof:\n");
    char command[256];
    snprintf(command, sizeof(command), "lsof -p %d", getpid());
    system(command);

//most important things to do 
fix object deformation where center is not the center of the window
handle all camera features

//lighting

handle case where lights is inside the object
handle case where lights is behind the object
handle case where ray from intersection to light and normal vector are not on the same origin
Add coefficient to alpha to represent the brightness
Normalize color value 

//ambient

add ambient to the base color of each shapes in the scene
