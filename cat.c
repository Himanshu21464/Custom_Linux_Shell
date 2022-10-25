#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define size 60

int main(int Cmd_Count, char **Argument){

  char Buff[size];
  int File, Read_size;
  char filename[50];
  printf("Enter filename to open: ");
  scanf("%[^\n]%*c", filename);
  File = open(filename, O_RDONLY);
  if (File == -1){
      fprintf(stderr, "Error: '%s' File not found\n", filename);
      return (-1);
    }
  while ((Read_size = read(File, Buff, size)) > 0)
    write(1, &Buff, Read_size);
  close(File);
  return (0);
}