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
  int ans = 1;
  while( exp ) {
    ans *= base;
    exp--;
  }
  return ans;
}

//ls -l representation -- WIP
void printMode(int mode){
  char ans[10] = "-";
  
  mode %= 512; //isolates last 3 digits
  int expt = 2;
  int temp; //que es?
  
  while( expt > -1) {
    temp = mode / mypow( 8, expt ); //you want the end result to be a single digit number i.e. 6
    mode %= mypow( 8, expt );
    if( temp >= 4 ) {
      strcat( ans, "r" );
      temp -= 4;
    }
    else {
      strcat( ans, "-" );
    }
    
    if( temp >= 2 ) {
      strcat( ans, "w" );
      temp -=2;
    }

    else {
      strcat( ans, "-" );
    }
    
    if( temp >= 1 ) {
      strcat( ans, "x" );
      temp -= 1;
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
  stat("test.txt", &buff); //put all the stat info inside buff struct

  //size =====
  //printf("Size of file: %d\n" , buff.st_size);
  //printSize(buff.st_size);

  //mode =====
  printf("File Mode: %o\n" , buff.st_mode);
  printMode(buff.st_mode);

  //time of last access =====
  //  printf("Time of last access: %s\n", ctime(&buff.st_atime));

  return 0;
}
