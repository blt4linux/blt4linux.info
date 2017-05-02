
#include <stdio.h>
#include <unistd.h> 

int main (int argc, char *argv[]) {
	// Set our real user ID, to take advantage of the setuid bit
	setreuid(geteuid(),  geteuid());
	
	// Make sure we are in the right directory
	if(chdir(TARGET_DIR) != 0) return -1;
	
	// Git pull
	return execl(GIT_INST, "git", "pull", (char*) 0);
}

