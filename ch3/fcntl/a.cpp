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

int main( int arc ,char * argv[] )
{
	int val;
	if ( ( val = fcntl( atoi( argv[ 1 ] ), F_GETFL , 0 ) ) < 0 )  {
		perror( "fcntl" );
	}
	switch( val & O_ACCMODE )
	{
		case O_RDONLY:
			printf( "file for read only" );
			break;
		case O_WRONLY:
			printf( "file for write only" );
			break;
		case O_RDWR:
			printf( "file for read & write" );
			break;
		default:
			printf( "unknown access mode" );
			break;
	}
#if defined( O_SYNC )
	if ( val & O_SYNC ) {
		printf( ", synchronous writes" );
	}
#endif

#if defined( _POSIX_C_SOURCE ) && defined( O_FSYNC )
	if ( val & O_FSYNC ) {
		printf( ", synchronous writes" );
	}
#endif
	putchar( '\n' );
	exit( 0 );
}
