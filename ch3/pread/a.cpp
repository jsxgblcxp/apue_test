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
	int fd = open( "a.in" , O_RDONLY );
	char buffer[ 20 ] = { 0 };
	pread( fd , buffer , 1 , 5 );
	fprintf( stderr , "pread a char at position 5 : %c\n" , buffer[ 0 ] );
	read( fd , buffer , 1 ); 
	fprintf( stderr , "read from the beginning %c\n" , buffer[ 0 ] );
	close( fd );
	return 0;
}
