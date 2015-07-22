rm a.out
g++ a.cpp 
./a.out 2 2>> tmp.foo
./a.out 0 < /dev/tty
./a.out 1 > tmp.foo
cat tmp.foo
./a.out 5 5<> temp.foo
