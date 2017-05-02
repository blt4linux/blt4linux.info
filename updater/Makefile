
CFLAGS=-D TARGET_DIR=\"$(shell dirname `pwd`)\" -D GIT_INST=\"$(shell which git)\" -D JEKYLL_INST=\"$(shell which jekyll)\"

default: pull

pull: pull.c
	$(CC) $(CFLAGS) pull.c -o pull
	chmod +s pull

