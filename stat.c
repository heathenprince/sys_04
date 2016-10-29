#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

struct stat st;
int main() {
  stat("test.txt", &st);
  //size
  int size = st.st_size;
  printf( "%d\n" , size );

  //mode
  int mode = st.st_mode;
  printf( "%o\n" , mode );
  
  return 0;
}
