#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "sys/types.h"

#define MAXLINE 1000

static void sig_int( int );

int main()
{
	if ( signal( SIGINT , sig_int ) == SIG_ERR ) {
		perror( "signal error" );
		exit( -1 );
	}

	char buf[ MAXLINE ];
	pid_t pid;
	int status;
	fprintf( stderr , "%%" );
	while ( fgets( buf , MAXLINE , stdin ) != NULL ){
		if ( buf[ strlen( buf ) - 1 ] == '\n' ) {
			buf[ strlen( buf ) - 1 ] = 0;;
		}
		if ( ( pid = fork() ) < 0 ) {
			perror( "error while fork" );
		} else if ( pid == 0 ) {
			execlp( buf , buf  , ( char * ) 0 );
			fprintf( stderr , "error while execlp" );
			exit( 127 );
		}
		if ( ( pid = waitpid( pid , & status , 0 ) ) < 0 ) {
			perror( "error while waiting" );
		}
		fprintf( stderr , "%%" );
	}
	return 0;
}

static void sig_int( int )
{
	printf( "interrupted\n" );
}
