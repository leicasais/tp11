#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <Kernel/sys/syscall.h>

const char msg0[]="Hola ITBA (Direct System Call)\n";
const char msg1[]="Hola ITBA (Wraped System Call)\n";

int main(void){
    long Nwritten;
    Nwritten=syscall(SYS_write,STDOUT_FILENO,msg0,sizeof(msg0)-1);
    printf("Numbers of bytes written=%ld\n", Nwritten);
    Nwritten=write(STDIN_FILENO,msg1,sizeof(msg1)-1);
    printf("Number of bytes written=%ld\n",Nwritten);
}