# miniRT

## before defense

- remove commentary in makefile and in is_light_ratio_valid
- verify norminette
- remove unecessary file
- clone the correct mlx (macos, linux)
- test malloc protection and external functions error protection
---
### check open file descriptor in the current process
	
```
printf("Listing open file descriptors using lsof:\n");
char command[256];
snprintf(command, sizeof(command), "lsof -p %d", getpid());
system(command);
```
---
### light

- check if the light is behind a plane
- handle case where lights is inside the object
---
### Jittered grid

#### possible changes to handle plane border shadow glitch:

- implement a distance limit and beyond set the color to black
- implement light brightness decreasing with distance
- fine-tune the value used with the shadow grid, e.g. determine the size of
  the perturbations based on the dimension of the object or the distance from the camera
---

