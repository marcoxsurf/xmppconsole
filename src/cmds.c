#include "net.h"
#include "io.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>

#include "cmds.h"

void cmd_connect(const char * const str) {
	char* cmd;
	char* jid;
	char* pass;
	char* rest;
	char* s;

	s = strdup(str);
	if (!s) {
		abort();
	}

	cmd = strtok(s, " \t");
	jid = strtok(NULL, " \t");
	pass = strtok(NULL, " \t");
	rest = strtok(NULL, " \t");
	if (!jid || !pass || rest) {
		printf_async("usage: /connect jid pass\n");
		goto ret;
	}
	net_connect(jid, pass);
ret:
	free(s);
}

void cmd_disconnect(const char* const str) {
	char* s;
	char* cmd;
	char* rest;

	s = strdup(str);
	if (!s) {
		abort();
	}

	cmd = strtok(s, " \t");
	rest = strtok(NULL, " \t");
	if (rest) {
		printf_async("usage: /quit\n");
		goto ret;
	}
	net_disconnect();
ret:
	free(s);
}

void cmd_quit(const char * const str) {
	char* cmd;
	char* rest;
	char* s;

	s = strdup(str);
	if (!s) {
		abort();
	}

	cmd = strtok(s, " \t");
	rest = strtok(NULL, " \t");
	if (rest) {
		printf_async("usage: /quit\n");
		goto ret;
	}
	prog_running = 0;
ret:
	free(s);
}
void cmd_debug(const char * const str) {
	char* cmd;
	char* rest;
	char* s;

	s = strdup(str);
	if (!s) {
		abort();
	}

	cmd = strtok(s, " \t");
	rest = strtok(NULL, " \t");
	if (rest) {
		printf_async("usage: /debug\n");
		goto ret;
	}
	io_switch_debug();
ret:
	free(s);
}
