# LinuxKernel
A kernel module that lists all current tasks in a Linux system. Output is the task name, state and process id of each task in a tree structure.

To run (On a linux system) :
  1. Open the command prompt in the directory where both files are saved.
  2. Run the command : make
  3. run the command : sudo insmod project.ko
  4. run the command : sudo dmesg

To remove the module run the command : sudo rmmod project.ko
