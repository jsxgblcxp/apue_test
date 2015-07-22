
dd if=/dev/zero of=./big_file bs=10MB count=2
cp big_file big_file1
cp big_file big_file2

cp big_file big_file3
cp big_file big_file4
cp big_file big_file5

rm a.out
g++ only_read.cpp
echo ____________________________ only read ____________________________ 
time ./a.out < big_file1

rm a.out 
echo ____________________________ read and write ____________________________ 
g++ normal_read_and_write.cpp
time ./a.out < big_file2 > big_file.output1
rm big_file.output1

echo ____________________________ sync write ____________________________ 
rm a.out 
g++ read_and_sync_write.cpp
time ./a.out < big_file3  > big_file.output2
rm big_file.output2

echo ____________________________ read write and fdatasync  ____________________________ 
rm a.out 
g++ read_write_and_fdatasync.cpp
time ./a.out < big_file4  > big_file.output3
rm big_file.output3

echo ____________________________ read write and fsync  ____________________________ 
rm a.out 
g++ set_and_fsync.cpp
time ./a.out < big_file5  > big_file.output4
rm big_file.output4
rm big_file*

m big_file*
