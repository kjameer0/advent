// Source - https://stackoverflow.com/a
// Posted by Oliver Charlesworth, modified by community. See post 'Timeline' for change history
// Retrieved 2025-12-12, License - CC BY-SA 3.0

#include <stdio.h>
#include "../include/string-utils.h" /* Include the header here, to obtain the function declaration */

const char *make_string()
{
  
  return "hi";
}
int main(void)
{
  const char *x = make_string();
  printf("%s\n", x);
  return 0;
}

// gcc - o my_app main.c foo.c
