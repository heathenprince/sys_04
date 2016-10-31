#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

struct stat buff;

//size in B, KB, MB, and GB
void printSize(int size){
	printf("Size of file: ");
	char* s[] = {"B", "KB", "MB", "GB"};
    int i = 0;
    while (size > 1024 && i < sizeof(s)){
        i++;
        size /= 1024.0;
    }
    printf("%d %s \n", size, s[i]);
}


//ls -l representation -- WIP
void printMode(int mode){

}


int main() {
  stat("test.txt", &buff);

  //size =====
  //printf("Size of file: %d\n" , buff.st_size);
  printSize(buff.st_size);

  //mode =====
  printf("File Mode: %o\n" , buff.st_mode);

  //time of last access =====
  printf("Time of last access: %s\n", ctime(&buff.st_atime));

  return 0;
}
