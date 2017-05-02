
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	// Set our real user ID, to take advantage of the setuid bit
	setreuid(geteuid(),  geteuid());
	
	// Make sure we are in the right directory
	if(chdir(TARGET_DIR) != 0) return -1;
	
	printf("Working on: %s\n", TARGET_DIR);
	
	int res = fork();
	
	if(res == -1) {
		exit(0); // shouldn't happen
	} else if(res == 0) {
		// We are the child process
		execl(GIT_INST, "git", "pull", (char*) 0);
	} else {
		printf("Spawned child %i!\n", res);
		
		int ret = wait(NULL);
		
		printf("Done running git: %i\n", ret);
	}
	
	// Git pull
	execl(JEKYLL_INST, "jekyll", "build", (char*) 0);
	
	// If execl returns, we have a problem
	
	return -1;
}

