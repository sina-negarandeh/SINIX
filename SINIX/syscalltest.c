#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  printf(1, "Enter the number of a system call that you would like to test?\n");
  printf(1, "1. reverse_number(int number)\n");
  printf(1, "2. trace_syscalls(int state)\n");
  printf(1, "3. get_children(int parent_id)\n");

  char buf[1024];
  read(1, buf, 1024);

  switch(atoi(buf)) {

   case 1  :
      printf(1, "Enter a number to reverse: ");
      read(1, buf, 1024);
      int number = atoi(buf);
      int ebxvalue;
      
      __asm__("movl %%ebx, %0" : "=r" (ebxvalue));  // Saved %ebx
      __asm__("movl %0, %%ebx" :  : "r"(number));  // Load number into ebx register
      __asm__("movl $22, %eax;"); // Load reverse_number system call number in eax register
      __asm__("int $64"); // Make a system call
      __asm__("movl %0, %%ebx" :  : "r"(ebxvalue));  // Load the previous value of exb register
      break;
	
   case 2  :
    printf(1, "Choose a tracing state:\n");
    printf(1, "0. Disable tracing\n");
    printf(1, "1. Enable tracing\n");
    read(1, buf, 1024);
    int state = atoi(buf);
    trace_syscalls(state);
    break;
   
   case 3  :
      printf(1, "Enter a PID: ");
      read(1, buf, 1024);
      int choice = atoi(buf);
      if(choice == 0){
        if(fork() == 0 || fork() == 0 || fork() == 0 || fork() == 0) {
          sleep(15);
        } else {
          get_children(getpid());
          wait();
          wait();
          wait();
          wait();
        }
      } else if(choice == 1) {
        if(fork() == 0) {
          if(fork() == 0 || fork() == 0) {
            sleep(20);
          } else {
              wait();
              wait();
          }
          sleep(15);
          } else {
          sleep(5);
          get_children(getpid());
          wait();
        }
      }
      break;

   default :
   printf(1, "systest: Not a valid number\n");
  }
  exit();
}
