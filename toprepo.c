#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
  int rc;

  printf("calling suba\n");
  rc = system("suba");
  printf("calling subb\n");
  rc = system("subb");
  printf("calling subc\n");
  rc = system("subc");
  return 0;
}

