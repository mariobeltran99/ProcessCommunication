#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#define URL "/dev/shm/process4"

int letter(int x){
    int flag = 0;
    if(x > 33 && x < 48 || x > 57 && x < 127){
        flag = 1;
    }
    return flag;
}

int main (void){
    int i = 0, next = 0, fd;
    char letters[20];
    char sentences[8500];
    srand(time(NULL));
    printf("** Productor 4  Enviado ** \n");
    printf("Caracteres: \n");
    while (i < 20)
    { 
        int num = rand() % 255;
        if (letter(num) && next != num)
        {
            char character = num;
            letters[i] = character;
            sprintf(&sentences[strlen(sentences)], "%c \t", letters[i]);
            if(i == 19 || i == 4 || i == 9 || i == 14){
                strcat(sentences, "\n");
            }
            next = num + 1;
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