This is a module for reading a file and then printing it.

Steps
1.Compile the Linux kernel:
(1)Download the Linux kernel source, for example, linux-source-3.0.0;
(2)Configure and compile the kernel according to the README file in the source.

2.Change to the directory where the file read.c, Makefile are.

3.Type "make".

4.Type "sudo insmod ./read.ko filename="directory/file" ", for example, if file "test.txt" is in the directory "/home/user/", then the command should be "sudo insmod ./read.ko filename="/home/user/test.txt" ".

5.See the output by typing "dmesg";

6.Type "sudo rmmod read" to remove this module. 
