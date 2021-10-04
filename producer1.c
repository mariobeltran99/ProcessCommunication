#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#define URL "/dev/shm/process1"

int cousin(int x){
    int init=0,p=0;
    int flag = 0;
    while (init < x)
    {
        init++;
        if(x % init == 0){
            p++;
        }
    }
    if (p <= 2){
        flag = 1;
    }
    return flag;
}

int main(void)
{
    int i = 0, fd;
    int cousins[20];
    char sentences[8500];
    srand(time(NULL));
    printf("** Productor 1  Enviado ** \n");
    printf("Números Primos: \n");
    while (i < 20)
    { 
        int num = rand() % 10000;
        if (cousin(num))
        {
            cousins[i] = num;
            sprintf(&sentences[strlen(sentences)], "%d \t", cousins[i]);
            if(i == 19 || i == 4 || i == 9 || i == 14){
                strcat(sentences, "\n");
            }
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