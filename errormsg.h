#ifndef ERRORMSG_H
#define ERRORMSG_H

#include "util.h"

void EM_newline();

extern int EM_tokPos;

void EM_error(int, string, ...);
void EM_reset(string filename);

#endif
