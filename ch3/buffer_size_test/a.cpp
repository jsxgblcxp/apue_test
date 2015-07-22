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
//	int fd = open( "a1.in" , O_WRONLY | O_CREAT );
//	if ( fd < 0 ) {
//		perror( "open" );
//	}
//	for ( int i = 0 ; i < 100000 ; ++ i ){
//		for ( int j = 0 ; j < 100000 ; ++ j ){
//			write( fd ,  "a" , 1 );
//		}
//	}
//	close( fd );
//	return 0;
	
	int n;
	char buf[ BUFFSIZE ];
	while ( ( n = read( STDIN_FILENO , buf , BUFFSIZE ) ) > 0 ){
		if ( write( STDOUT_FILENO , buf , n ) != n ) {
			perror( "write error" );
		}
	}
	return 0;
}
