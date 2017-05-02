
CFLAGS=-D TARGET_DIR=\"$(shell dirname `pwd`)\" -D GIT_INST=\"$(shell which git)\" -D JEKYLL_INST=\"$(shell which jekyll)\" -D BASH_INST=\"$(shell which bash)\"

default: pull

pull: pull.c
	$(CC) $(CFLAGS) pull.c -o pull
	chmod +s pull

