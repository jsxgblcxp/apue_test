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

int main()
{

	if ( lseek( STDIN_FILENO , 0 , SEEK_CUR ) == -1 ) {
		fprintf( stderr , "seek error" );
	} else {
		fprintf( stderr , "seek done" );
	}
	return 0;
}
