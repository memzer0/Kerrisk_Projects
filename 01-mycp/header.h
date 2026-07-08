#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define    SUCCESSFUL       1
#define    FAILURE         -1

#define BUF_SZ          4096
#define MODE            S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

extern char buffer[];

#endif