# miniRT

// check open file descriptor in the current process
	printf("Listing open file descriptors using lsof:\n");
    char command[256];
    snprintf(command, sizeof(command), "lsof -p %d", getpid());
    system(command);