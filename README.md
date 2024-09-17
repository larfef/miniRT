# miniRT

// check open file descriptor in the current process
	printf("Listing open file descriptors using lsof:\n");
    char command[256];
    snprintf(command, sizeof(command), "lsof -p %d", getpid());
    system(command);

//orientation
add parsing rule to check if the given orientation is normalized

//parsing
handle this case with color and coordinate
255,,255

check coordinate inversion

//lighting

handle case where lights is inside the object
handle case where lights is behind the object
check if the vector hit_point -> light intersect with an object, if so set the hit point color to black

//ambient

add ambient to the base color of each shapes in the scene

//jittering grid

set the number of ray
set the grid size
loop for each point in the 3d grid
modify the hit_point -> light vector direction 
check how many ray intersect another object
set the shadow factor [0, 1] based on the number of intersection
mulitply the shape color by the shadow factor

//cylinder

add a check for the 3d orientation who must be normalized
fix error with coordinate: coordinate must be the center of the cylinder instead of the center of the base of the cylinder