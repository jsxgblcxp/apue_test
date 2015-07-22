#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "sys/types.h"
#include "errno.h"
#include "limits.h"

#define MAXLINE 1000

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif // OPEN_MAX 

#define OPEN_MAX_GUESS 256

long open_max()
{
	if ( 0 == openmax ) {
		errno = 0;
		if ( ( openmax = sysconf( _SC_OPEN_MAX ) ) < 0 ) {
			if ( 0 == errno ) {
				openmax = OPEN_MAX_GUESS;
			} else {
				perror( "error while open the max" );
			}
		} 
	}
	return ( openmax );
}

int main()
{
	fprintf( stderr , "%ld is the max file open numbers\n" , open_max() );
	return 0;
}


