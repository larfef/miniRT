# miniRT

## before defense

- remove commentary in makefile and in is_light_ratio_valid
- verify norminette
- remove unecessary file
- clone the correct mlx (macos, linux)

### check open file descriptor in the current process
	
```
printf("Listing open file descriptors using lsof:\n");
char command[256];
snprintf(command, sizeof(command), "lsof -p %d", getpid());
system(command);
```

### light

- check if the light is behind a plane
- handle case where lights is inside the object
