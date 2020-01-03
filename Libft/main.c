#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
    {
      char *ptr;

      if ((ptr = (char *)malloc(sizeof(const char) * len-start+1)))
      {
        while(++start <= len)
          ptr[start-1] = s[start-1];
        ptr[len] = '\0';
        return (ptr);
      }
      return (NULL);
    }

int main(void)
{
  char str1[255];
  char str2 = "lorem ipsum"

  
}
