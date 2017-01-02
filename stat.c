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


int mypow( int base, int exp ) {
  while( exp > 0 ) {
    base *= base;
    exp--;
  }
  return base;
}

//ls -l representation -- WIP
void printMode(int mode){
  char ans[10] = "-";
  mode %= 512; //isolates last 3 digits
  int expt = 3;
  int temp;
  while( expt > 1 ) {
    temp = mode / mypow( 8, expt );
    printf( "%o\n\n" , temp );
    mode /= mypow( 10, expt ); 

    if( mode >= 4 ) {
      strcat( ans, "r" );
      mode -= 4;
    }
    else {
      strcat( ans, "-" );
    }
    
    if( mode >= 2 ) {
      strcat( ans, "w" );
      mode -=2;
    }

    else {
      strcat( ans, "-" );
    }
    
    if( mode >= 1 ) {
      strcat( ans, "x" );
      mode -= 1;
    }
    else {
      strcat( ans, "-" );
    }
    
    mode %= mypow( 8, expt );
    expt--;
  }
  printf( "%s\n", ans );
  
}


int main() {
  stat("test.txt", &buff);

  //size =====
  //printf("Size of file: %d\n" , buff.st_size);
  printSize(buff.st_size);

  //mode =====
  printf("File Mode: %o\n" , buff.st_mode);
  printMode(buff.st_mode);

  //time of last access =====
  printf("Time of last access: %s\n", ctime(&buff.st_atime));

  return 0;
}
