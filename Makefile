
CFLAGS=-D TARGET_DIR=\"$(shell pwd)\" -D GIT_INST=\"$(shell which git)\"

default: site

pull: pull.c
	$(CC) $(CFLAGS) pull.c -o pull

site: webroot/assets/styles.css

webroot/assets/styles.css: sass/*
	sass sass/* webroot/assets/styles.css

