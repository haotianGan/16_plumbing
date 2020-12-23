#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

//Fgets
//Write to pipe_write
//Read from pipe_read (blocks until this happens)
//Display what was read 

int main(){
    printf("Waiting on file1...\n");
    mkfifo("pipe_write", 0644);
    mkfifo("pipe_read", 0644);
    int write_to = open("pipe_write", O_WRONLY);
    int read_from = open("pipe_read", O_RDONLY);
    printf("---- Free oracle consultation service ----\n");
    while(1){
        char buffer[500];
        printf("Ask a yes or no question: ");
        fgets(buffer, 500, stdin);
        int i = 0; 
        while(buffer[i]){
            if(buffer[i] == '\n') buffer[i] = '\0'; 
            i++;
        }
        write(write_to, buffer, 500);
        
        char readBuffer[45];
        read(read_from, readBuffer, 45);
        printf("\n%s\n\n", readBuffer);

    }
}