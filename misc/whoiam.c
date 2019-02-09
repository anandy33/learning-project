#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>

char *getUserName()
{
  uid_t uid;
  struct passwd *pw = NULL;

  uid = geteuid();
  pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return NULL;
}


int main(int argc, char *argv[])
{
  char *user = getUserName();
  printf("username isssss : %s\n" , user);
 
  return 0;
}
