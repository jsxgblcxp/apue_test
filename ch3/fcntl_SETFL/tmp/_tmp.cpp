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

int main()
{
	int n;
	char buf[ BUFFSIZE ];
	while ( ( n = read( STDIN_FILENO , buf , BUFFSIZE ) ) > 0 ){
		if ( write( STDOUT_FILENO , buf , n ) != n ) {
			perror( "write error" );
		}
	}
	return 0;
}


dd if=/dev/zero of=./big_file bs=10MB count=20

g++ only_read.cpp
echo ____________________________ only read ____________________________ 
time ./a.out < big_file1

rm a.out 
echo ____________________________ read and write ____________________________ 
g++ normal_read_and_write.cpp
time ./a.out < big_file2 > big_file.output1


echo ____________________________ sync write ____________________________ 
rm a.out 
g++ read_and_sync_write.cpp
time ./a.out < big_file3  > big_file.output2
rm big_file.output

echo ____________________________ read write and fdatasync  ____________________________ 
rm a.out 
g++ read_write_and_fdatasync.cpp
time ./a.out < big_file  > big_file.output2
rm big_file.output2





rm big_file.output
cp big_file big_file1
cp big_file big_file2
cp big_file big_file3
cp big_file big_file4
cp big_file big_file5
cp big_file big_file6

cp big_file big_file1
cp big_file big_file2
cp big_file big_file4
cp big_file big_file5
cp big_file big_file6


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
