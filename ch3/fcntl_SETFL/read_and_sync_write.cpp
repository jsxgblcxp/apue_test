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
void set_fl( int fd , int flags );

int main()
{
	int n;
	char buf[ BUFFSIZE ];
	set_fl( STDOUT_FILENO ,  O_SYNC );

	while ( ( n = read( STDIN_FILENO , buf , BUFFSIZE ) ) > 0 ){
		if ( write( STDOUT_FILENO , buf , n ) != n ) {
			perror( "write error" );
		}
	}
	return 0;
}

void set_fl( int fd , int flags )
{
	int val;
	if ( ( val = fcntl( fd , F_GETFL ) ) < 0 ) {
		perror( "fcntl" );
		return;
	}
	val |= flags;
	if ( ( fcntl( fd ,F_SETFL , val ) ) < 0 ) {
		perror( "fcntl" );
	}

}
