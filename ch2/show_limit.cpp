#include "stdio.h"
#include "string.h"
#include <unistd.h>
#include <stdlib.h>
#include "sys/wait.h"
#include "sys/types.h"
#include "errno.h"
#include "limits.h"

#define MAXLINE 1000

static void pr_sysconf( const char * , int );

int main()
{
	pr_sysconf( "argvalue max len" , _SC_ARG_MAX );
	pr_sysconf( "link num max len" , _PC_LINK_MAX );
	pr_sysconf( "pipe buf max" , _PC_PIPE_BUF );
	pr_sysconf( "timer max max" , _SC_TIMER_MAX );
	pr_sysconf( "off_t value " , _SC_V6_ILP32_OFF32 );
	pr_sysconf( "off_t big value " , _SC_V6_ILP32_OFFBIG );
	return 0;
}

static void pr_sysconf( const char * msg , int name )
{
	long val;

	fputs( msg , stdout );
	errno = 0;
	if ( ( val = sysconf( name ) ) < 0 ) {
		if ( 0 != errno ) {
			if ( EINVAL == errno ) {
				fputs( "not supported\n",  stdout );
			} else {
				fputs( "error of sysconf \n" ,stderr );
			}
		} else {
			fputs( "this value is not limited\n" , stdout );
		}
	} else {
		printf( " %ld\n" ,  val );
	}
}
