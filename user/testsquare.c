#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    fprintf(2, "Inavllid argument!");
    exit(1);
  }

  int base = 6;
  int base1 = 69;

  int result = square(base);
  int expected_result = base * base;

  int result1 = square(base1);
  int expected_result1 = base1 * base1;

  if (result == expected_result && result1 == expected_result1)
  {
    fprintf(2, "Success!");
    exit(0);
  }
  else
  {
    fprintf(2, "Some problem!");
    exit(1);
  }

  exit(0);
}