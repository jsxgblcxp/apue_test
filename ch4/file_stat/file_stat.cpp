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


int main( int argc , char * argv[] )
{
	int i;
	struct stat buf;
	const char * ptr;
	for ( i = 1 ; i < argc ; ++ i ){
		printf( "%s ", argv[ i ] );
		if ( lstat( argv[ i ],  & buf ) ) {
			fprintf( stderr , "lstat error" );
			exit( 0 );
		}
		if ( S_ISREG( buf.st_mode ) ) {
			ptr = "regular";
		} else if ( S_ISDIR( buf.st_mode ) ) {
			ptr = "dir";
		} else if ( S_ISCHR( buf.st_mode ) ) {
			ptr = "charactor special";
		} else if ( S_ISBLK( buf.st_mode ) ) {
			ptr = "block special";
		} else if ( S_ISFIFO( buf.st_mode ) ) {
			ptr = "fifo";
		} else if ( S_ISLNK( buf.st_mode ) ) {
			ptr = "symbolic link";
		} else if ( S_ISSOCK( buf.st_mode ) ) {
			ptr = "socket";
		} else {
			ptr = "Unkonwn device";
		}
		printf( "%s\n",  ptr );
	}
	exit( 0 );
}
