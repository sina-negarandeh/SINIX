#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
gcd(int firstnum, int secondnum)
{
  if(firstnum == 0)
    return secondnum;
  return gcd(secondnum % firstnum, firstnum);
}

int
lcm(int firstnum, int secondnum)
{
  return firstnum * secondnum / gcd(firstnum, secondnum);
}

int
numberofdigits(int number)
{
  int n = 1;

  while(number >= 10)
  {
    number /= 10;
    n += 1;
  }
  return n;
}

char
*toarray(int number)
{
  int n, i;

  n = numberofdigits(number);
  char *array = malloc((n + 1) * sizeof(char));
  for(i = n - 1; i >= 0; --i, number /= 10)
    array[i] = (number % 10) + '0';
  array[n] = '\n';
  return array;
}

int
main(int argc, char *argv[])
{
  int result, i, fd;

  if(argc < 3){
    printf(1, "too few args\n");
    exit();
  }

  result = lcm(atoi(argv[1]), atoi(argv[2]));
  for(i = 3; i < argc; i++)
    result = lcm(result, atoi(argv[i]));

  if((fd = open("lcm_result.txt", O_CREATE | O_WRONLY)) < 0)
      printf(1, "lcm: cannot open lcm_result.txt\n");
  else
  {
    char *resultptr = toarray(result);
    write(fd, resultptr, sizeof(resultptr));
    close(fd);
    free(resultptr);
  }

  exit();
}
