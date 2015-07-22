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
	int fd = creat( "file.hole" , S_IRUSR | S_IWUSR | S_IXUSR );
	if ( fd < 0 ) {
		perror( "creat" );
		return -1;
	}
	if ( ( write( fd , "123312" , 6 ) != 6 ) ) {
		perror( "write" );
		return -1;
	}

	if ( ( lseek( fd , 123312 , SEEK_SET ) == -1 ) ) {
		perror( "seek" );
		return -1;
	}


	if ( ( write( fd , "123312" , 6 ) != 6 ) ) {
		perror( "write" );
		return -1;
	}
	close ( fd );
	fd = creat( "file.nohole" , S_IRUSR | S_IWUSR | S_IXUSR );
	if ( fd < 0 ) {
		perror( "creat" );
		return -1;
	}
	for ( int i = 0 ; i <  123312 ; ++ i ){
		write( fd  , "c" , 1 );
	}
	close( fd );
	return 0;
}
