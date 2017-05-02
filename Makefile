
CFLAGS=-D TARGET_DIR=\"$(shell pwd)\" -D GIT_INST=\"$(shell which git)\"

default: pull

%: %.c
	$(CC) $(CFLAGS) $< -o $@

