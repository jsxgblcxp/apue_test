#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "errno.h"
#include "limits.h"

#define BUFFSIZE  4096

int main()
{
	int n;
	char buf[ BUFFSIZE ];
	while ( ( n = read( STDIN_FILENO , buf , BUFFSIZE ) ) > 0 ){
	}
	return 0;
}
