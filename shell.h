#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *get_line(void);
char *func_strtok(char *mensaje);
void execute_program(char *token);

#endif
