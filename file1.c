#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 


//Read from pipe_write
//Process what was read
//Write to pipe_read

int main(){
    printf("Run file0 before running file1\n");
    int read_from = open("pipe_write", O_RDONLY);
    int write_to = open("pipe_read", O_WRONLY);
    while(1){
        char buffer[500];
        read(read_from, buffer, 500);
        int c = 0;
        int i = 0;
        while(buffer[i]) {
            if(buffer[i] == ' ') c++;
            i++;
        }
        if(c % 2 == 0){
            write(write_to, "Oracle: I have determined the answer is yes.", 45);
        } else {
            write(write_to, "Oracle: I have determined the answer is no.", 45); 
        }
    }
}