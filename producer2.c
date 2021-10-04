#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#define URL "/dev/shm/process2"

int pair(int x){
    int flag = 0;
    if(x % 2 == 0){
        flag = 1;
    }
    return flag;
}

int main (void){
    int i = 0, next = 0, fd;
    int pairs[20];
    char sentences[8500];
    srand(time(NULL));
    printf("** Productor 2  Enviado ** \n");
    printf("Números Pares: \n");
    while (i < 20)
    { 
        int num = rand() % 10000;
        if (pair(num) && next != num)
        {
            pairs[i] = num;
            sprintf(&sentences[strlen(sentences)], "%d \t", pairs[i]);
            if(i == 19 || i == 4 || i == 9 || i == 14){
                strcat(sentences, "\n");
            }
            next = num + 2;
            i++;
        }
    }
    strcat(sentences, "\n");
    printf("%s", sentences);
    mkfifo(URL, 0666);
    fd = open(URL, O_WRONLY);
    write(fd, sentences, sizeof(sentences));
    close(fd);
    return 0;
}

