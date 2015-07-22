./t1.sh
g++ a.cpp -DBUFFSIZE=1 -o a.out
echo buff is 1 >&2 
time ./a.out < big_file1 > /dev/null
g++ a.cpp -DBUFFSIZE=2 -o a.out
echo buff is 2 >&2 
time ./a.out < big_file2 > /dev/null
g++ a.cpp -DBUFFSIZE=4 -o a.out
echo buff is 4 >&2 
time ./a.out < big_file4 > /dev/null
g++ a.cpp -DBUFFSIZE=8 -o a.out
echo buff is 8 >&2 
time ./a.out < big_file8 > /dev/null
g++ a.cpp -DBUFFSIZE=16 -o a.out
echo buff is 16 >&2 
time ./a.out < big_file16 > /dev/null
g++ a.cpp -DBUFFSIZE=32 -o a.out
echo buff is 32 >&2 
time ./a.out < big_file32 > /dev/null
g++ a.cpp -DBUFFSIZE=64 -o a.out
echo buff is 64 >&2 
time ./a.out < big_file64 > /dev/null
g++ a.cpp -DBUFFSIZE=128 -o a.out
echo buff is 128 >&2 
time ./a.out < big_file128 > /dev/null
g++ a.cpp -DBUFFSIZE=256 -o a.out
echo buff is 256 >&2 
time ./a.out < big_file256 > /dev/null
g++ a.cpp -DBUFFSIZE=512 -o a.out
echo buff is 512 >&2 
time ./a.out < big_file512 > /dev/null
g++ a.cpp -DBUFFSIZE=1024 -o a.out
echo buff is 1024 >&2 
time ./a.out < big_file1024 > /dev/null
g++ a.cpp -DBUFFSIZE=2048 -o a.out
echo buff is 2048 >&2 
time ./a.out < big_file2048 > /dev/null
g++ a.cpp -DBUFFSIZE=4096 -o a.out
echo buff is 4096 >&2 
time ./a.out < big_file4096 > /dev/null
g++ a.cpp -DBUFFSIZE=8192 -o a.out
echo buff is 8192 >&2 
time ./a.out < big_file8192 > /dev/null
g++ a.cpp -DBUFFSIZE=16384 -o a.out
echo buff is 16384 >&2 
time ./a.out < big_file16384 > /dev/null
g++ a.cpp -DBUFFSIZE=32768 -o a.out
echo buff is 32768 >&2 
time ./a.out < big_file32768 > /dev/null
g++ a.cpp -DBUFFSIZE=65536 -o a.out
echo buff is 65536 >&2 
time ./a.out < big_file65536 > /dev/null
g++ a.cpp -DBUFFSIZE=131072 -o a.out
echo buff is 131072 >&2 
time ./a.out < big_file131072 > /dev/null
g++ a.cpp -DBUFFSIZE=262144 -o a.out
echo buff is 262144 >&2 
time ./a.out < big_file262144 > /dev/null
g++ a.cpp -DBUFFSIZE=524288 -o a.out
echo buff is 524288 >&2 
time ./a.out < big_file524288 > /dev/null
rm big_file*
