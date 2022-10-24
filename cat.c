#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define size 60

int main(int Cmd_Count, char **Argument){

  char Buff[size];
  int File, Read_size;
  if (Cmd_Count < 2){
      fprintf(stderr, "Error: ./cat filename\n");
      return (-1);
    }
  File = open(Argument[1], O_RDONLY);
  if (File == -1){
      fprintf(stderr, "Error: '%s' File not found\n", Argument[1]);
      return (-1);
    }
  while ((Read_size = read(File, Buff, size)) > 0)
    write(1, &Buff, Read_size);
  close(File);
  return (0);
}