#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#define MAX 9500
#define MAX_LENGTH 100

int main(void){
    char urls[][MAX_LENGTH] = {
        "/dev/shm/process1", 
        "/dev/shm/process2", 
        "/dev/shm/process3", 
        "/dev/shm/process4"
    };
    char titles[][MAX_LENGTH] = {
        "\nNúmeros Primos:\n",
        "\nNúmeros Pares:\n",
        "\nNúmeros Impares:\n",
        "\nCaracteres:\n"
    };
    printf("** Consumidor **\n");
    for (int i = 0; i < 4; i++){
        int fd;
        char buffer[MAX];
        fd = open(urls[i], O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("%s", titles[i]);
        printf("\n%s", buffer);
    }
    return 0;
}