#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include <string.h>
#include <ctype.h>
#include <time.h>  
#include "libftFunctions.c"


int randomNumber(int max)
{

    int i = rand() % max;
    return(i);
}

int randomCharac()
{

    int i = rand() % 90 + 33;
    return(i);
}

char * randomChar(char *src)
{
  int x;

  x = randomNumber(50);
  while (x >= 0)
  {
    src[x] = randomCharac();
    x--;
  }
  return (src);
}

char * randomnChar(char *src, int n)
{
  int x;

  x = randomNumber(n);
  src[x] = '\0';
  x--;

  while (x >= 0)
  {
    src[x] = randomCharac();
    x--;
  }
  return (src);
}

void helpDisplay()
{
  printf("\033[0;32m");
  printf("   -------------------------------------\n");
  printf("\033[0m");
  printf("   \033[0;32m|\033[0m  Besoin d'aide avec une fontion ? \033[0;32m|\033[0m\n");
  printf("   \033[0;32m|\033[0m   ./a.out 'Function name' -help   \033[0;32m|\033[0m\n");
  printf("\033[0;32m");
  printf("   -------------------------------------\033[0m\n");
  printf("   \033[0;32m|\033[0m        Liste des fonctions        \033[0;32m|\033[0m\n");
  printf("   \033[0;32m|\033[0m           ./a.out -list           \033[0;32m|\033[0m\n");
  printf("\033[0;32m");
  printf("   -------------------------------------\n\n");
  printf("\033[0m");
}

void listDisplay()
{
  printf("\033[0;32m");
  printf(" ------------------------\n");
  printf(" \033[0;32m|\033[0m Fonctions Basiques : \033[0;32m|\n");
  printf(" ------------------------\n\n");
  printf("\033[0m");


  printf("  - memset '' '' ''\n");
  printf("  - bzero 'void *s' 'size_t n'\n");
  printf("  - memcpy 'void *dest' 'void *src' 'size_t n'\n");
  printf("  - memccpy 'void *dest' 'void *src' 'char c' 'size_t n'\n");
  printf("  - memmove 'void *dest' 'void *src' 'size_t n'\n");
  printf("  - memchr '' '' ''\n");
  printf("  - memcmp '' '' ''\n");
  printf("  - strlen '' '' ''\n");
  printf("  - isalpha 'char c'\n");
  printf("  - isdigit 'char c'\n");
  printf("  - isalnum 'char c'\n");
  printf("  - isascii 'char c'\n");
  printf("  - isprint 'char c'\n");
  printf("  - toupper 'char c'\n");
  printf("  - tolower 'char c'\n");
  printf("  - strchr '' '' ''\n");
  printf("  - strrchr '' '' ''\n");
  printf("  - strncmp '' '' ''\n");
  printf("  - strlcpy '' '' ''\n");
  printf("  - strlcat '' '' ''\n");
  printf("  - strnstr '' '' ''\n");
  printf("  - atoi '' '' ''\n");
  printf("  - calloc '' '' ''\n");
  printf("  - strdup '' '' ''\n\n");


  printf("\033[0;32m");
  printf(" ------------------------\n");
  printf(" \033[0;32m|\033[0m Fonctions Avancées : \033[0;32m|\n");
  printf(" ------------------------\n\n");
  printf("\033[0m");
  printf("  - substr '' '' ''\n");
  printf("  - strjoin '' '' ''\n");
  printf("  - strtrim '' '' ''\n");
  printf("  - split '' '' ''\n");
  printf("  - itoa '' '' ''\n");
  printf("  - strmapi '' '' ''\n");
  printf("  - putchar_fd '' '' ''\n");
  printf("  - putstr_fd '' '' ''\n");
  printf("  - putendl_fd '' '' ''\n");
  printf("  - putnbr_fd '' '' ''\n\n");

}

int main(int argc, char **argv)
{
  srand(time(NULL));
  /*ERRORS*/
  if(argc < 2)
  {
          printf("MainLibft de gde-sant :\n\n");
          printf("Help : (./a.out -help) : \n\n");
          helpDisplay();
          printf("Liste des Fonctions : (./a.out -list) : \n\n");
          listDisplay();
          return 0;
  }
  else if(strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "-h") == 0) 
  {
    helpDisplay();
    return 0;
  }
  else if(strcmp(argv[1], "-list") == 0) 
  {
    listDisplay();
    return 0;
  }

  /*Start EasyOnes*/
    /* BZERO Main*/
    else if(strcmp(argv[1], "bzero") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("./a.out bzero  'void *s' 'size_t n'\n");
          printf("------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out bzero -r 'int nt(0-40)'\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 40)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 40 inclus !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char tmp1[100];
          char tmp2[100];
          int i = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(tmp1);
            strcpy(tmp2, tmp1);
            i = randomNumber(20);
            
            bzero(tmp1, i);
            ft_bzero(tmp2, i);

            if ( strcmp(tmp1, tmp2) == 0)
            {
            printf("Test %d = succès\n", atoi(argv[3]) - x + 1);
            printf("-------> *s True: %s\n", tmp1);
            printf("-------> *s False: %s\n", tmp2);

            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
            if (tmp1 != tmp2)
               printf("Function Result Error.");
            else 
               printf("Unkown.");
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }
      else
      {
        int i = atoi(argv[3]);
        char *c1 = argv[2];
        char *c2= argv[2];;
        printf("Source *s: %s\n", argv[2]);
        printf("Source n: %d\n", i);
        printf("------------------------------------\n");
        bzero(c1, i);
        printf("Real Function :\n");
        printf("*s : %s\n", c1);
        printf("------------------------------------\n");
        ft_bzero(c2, i);
        printf("FT Function :\n");
        printf("*s : %s\n", c2);
        if (strcmp(c1, c2) == 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!!\n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (strcmp(c1, c2) != 0)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }


      }

      return 0;
    }

    /*FT_MEMSET Main*/
    else if(strcmp(argv[1], "memset") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("-------------------------------------------\n");
          printf("./a.out memset  'void *s' 'char c' size_t n'\n");
          printf("-------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memset -r 'int nt(0-40)'\n");
          printf("-------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }

      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 40)
        {
          printf("\033[0;31m");
          printf("------------------------------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 40 inclus !\n");
          printf("------------------------------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char tmp1[100];
          char s[100];
          char tmp2[100];
          char c;
          int i = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(tmp1);
            c = randomCharac();
            strcpy(tmp2, tmp1);
            strcpy(s, tmp2);
            i = randomNumber(30);
            if (i == 0)
              i = randomNumber(40);

            ft_memset(tmp2, c, i);
            memset(tmp1, c ,i);

            if ( strcmp(tmp1, tmp2) == 0)
            {
            printf("Test %d = succès (Size : %d)\n", atoi(argv[3]) - x + 1, i);
              printf("----------> *s Source: %s\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);

            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
            if (tmp1 != tmp2)
            {
              printf("Function Result Error. Size : %d)\n", i);
              printf("----------> *s Source: %s\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            else 
            {
              printf("Unkown. (Size : %d)\n", i);
              printf("----------> *s Source: %s\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }

      else
      {
        int i = atoi(argv[4]);
        char c1[100] = "";
        char c2[100] = "";
        char c = argv[3][0];
        strcpy(c1, argv[2]);
        strcpy(c2, argv[2]);
        printf("Source *s: %s\n", argv[2]);
        printf("Source  c: %c\n", c);
        printf("Source  n: %d\n", i);
        printf("------------------------------------\n");
        memset(c1, c, i);
        printf("        Real Function :\n");
        printf("*s : %s\n", c1);
        printf("------------------------------------\n");
        ft_memset(c2, c, i);
        printf("         FT Function :\n");
        printf("*s : %s\n", c2);
        if (strcmp(c1, c2) == 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (strcmp(c1, c2) != 0)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    }

    /*FT_MEMCPY Main WIP*/
    else if(strcmp(argv[1], "memcpy") == 0)  
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("----------------------------------------------\n");
          printf("./a.out memcpy  'void *dest' 'void *src' 'size_t n'\n");
          printf("----------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memcpy -r 'int nt(0-40)'\n");
          printf("-------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }

      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 40)
        {
          printf("\033[0;31m");
          printf("------------------------------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 40 inclus !\n");
          printf("------------------------------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char tmp1[100];
          char s[100];
          char src[100];
          char tmp2[100];
          int i = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(tmp1);
            randomnChar(src, 10);
            strcpy(tmp2, tmp1);
            strcpy(s, tmp2);
            i = randomNumber(20);
            if (i == 0)
              i = randomNumber(25);

            ft_memcpy(tmp2, src, i);
            memcpy(tmp1, src ,i);

            if (strcmp(tmp1, tmp2) == 0)
            {
            printf("Test %d = succès (Size : %d)\n", atoi(argv[3]) - x + 1, i);
              printf("----------> *src Source: %s\n", src);            
              printf("----------> *dest Source: %s\n\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);

            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
            if (tmp1 != tmp2)
            {
              printf("Function Result Error. Size : %d)\n", i);
              printf("----------> *src Source: %s\n", src);            
              printf("----------> *dest Source: %s\n\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            else 
            {
              printf("Unkown. (Size : %d)\n", i);
              printf("----------> *src Source: %s\n", src);            
              printf("----------> *dest Source: %s\n\n", s);

              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }
      
      else
      {
        int i = atoi(argv[4]);
        char dest1[100] = "";
        char dest2[100] = "";
        char src[100] = "";
        strcpy(dest1, argv[2]);
        strcpy(dest2, dest1);
        strcpy(src, argv[3]);
        printf("Source *dest: %s\n", argv[2]);
        printf("Source *src: %s\n", argv[3]);
        printf("Source  n: %d\n", i);
        printf("------------------------------------\n");
        memcpy(dest1, src, i);
        printf("        Real Function :\n");
        printf("*s : %s\n", dest1);
        printf("------------------------------------\n");
        ft_memcpy(dest2, src, i);
        printf("         FT Function :\n");
        printf("*s : %s\n", dest2);
        if (strcmp(dest1, dest2) == 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (strcmp(dest1, dest2) != 0)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    }

    /*FT_MEMCCPY Main*/
    else if(strcmp(argv[1], "memccpy") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("------------------------------------------------------------\n");
          printf("./a.out memccpy  'void *dest' 'void *src' 'char c' 'size_t n'\n");
          printf("------------------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memccpy -r 'int nt(0-40)'\n");
          printf("------------------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }

      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 200)
        {
          printf("\033[0;31m");
          printf("------------------------------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 200 inclus !\n");
          printf("------------------------------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char tmp1[100];
          char s[100];
          char src[100];
          char tmp2[100];
          char c;
          int i = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(tmp1);
            randomnChar(src, 20);
            c = randomCharac();
            strcpy(tmp2, tmp1);
            strcpy(s, tmp2);
            i = randomNumber(30);
            if (i == 0)
              i = randomNumber(25);

            ft_memccpy(tmp2, src , c, i);
            memccpy(tmp1, src, c,i);

            if (strcmp(tmp1, tmp2) == 0)
            {
            printf("Test %d = succès (Size : %d)\n", atoi(argv[3]) - x + 1, i);
              printf("----------> c Source: %c\n", c);
              printf("----------> *src Source: %s\n", src);
              printf("----------> *dest Source: %s\n\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);

            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
            if (tmp1 != tmp2)
            {
              printf(" Function Result Error : (Size : %d)\n", i);
              printf("----------> c Source: %c\n", c); 
              printf("----------> *src Source: %s\n", src);            
              printf("----------> *dest Source: %s\n\n", s);
              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            else 
            {
              printf(" Unkown : (Size : %d)\n", i);
              printf("----------> c Source: %c\n", c); 
              printf("----------> *src Source: %s\n", src);            
              printf("----------> *dest Source: %s\n\n", s);

              printf("----------> *s True: %s\n", tmp1);
              printf("----------> *s False: %s\n\n", tmp2);
            }
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }
      
      else
      {
        int i = atoi(argv[5]);
        char dest1[100] = "";
        char dest2[100] = "";
        char src[100] = "";
        char c = argv[4][0];
        strcpy(dest1, argv[2]);
        strcpy(dest2, dest1);
        strcpy(src, argv[3]);
        printf("Source *dest: %s\n", argv[2]);
        printf("Source *src: %s\n", argv[3]);
        printf("Source  c: %c\n", c);
        printf("Source  n: %d\n", i);
        printf("------------------------------------\n");
        memccpy(dest1, src, c, i);
        printf("        Real Function :\n");
        printf("*s : %s\n", dest1);
        printf("------------------------------------\n");
        ft_memccpy(dest2, src, c, i);
        printf("         FT Function :\n");
        printf("*s : %s\n", dest2);
        if (strcmp(dest1, dest2) == 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (strcmp(dest1, dest2) != 0)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    }

    /*FT_MEMMOVE Main*/
    else if(strcmp(argv[1], "memmove") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("----------------------------------------------\n");
          printf("./a.out memmove  'void *dest' 'void *src' 'size_t n'\n");
          printf("----------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memmove -r 'int nt(0-40)'\n");
          printf("-------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }

      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 40)
        {
          printf("\033[0;31m");
          printf("------------------------------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 40 inclus !\n");
          printf("------------------------------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char tmp1[100];
          char s[100];
          char src[100];
          char tmp2[100];
          int i = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(tmp1);
            randomnChar(src, 10);
            strcpy(tmp2, tmp1);
            strcpy(s, tmp2);
            i = randomNumber(20);
            if (i == 0)
              i = randomNumber(25);

            ft_memmove(tmp2, src, i);
            memmove(tmp1, src ,i);

            if (strcmp(tmp1, tmp2) == 0)
            {
              printf("Test %d = succès (Size : %d)\n", atoi(argv[3]) - x + 1, i);
                printf("----------> *src Source: %s\n", src);            
                printf("----------> *dest Source: %s\n\n", s);
                printf("----------> *s True: %s\n", tmp1);
                printf("----------> *s False: %s\n\n", tmp2);
            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
              if (tmp1 != tmp2)
              {
                printf("Function Result Error. Size : %d)\n", i);
                printf("----------> *src Source: %s\n", src);            
                printf("----------> *dest Source: %s\n\n", s);
                printf("----------> *s True: %s\n", tmp1);
                printf("----------> *s False: %s\n\n", tmp2);
              }
              else 
              {
                printf("Unkown. (Size : %d)\n", i);
                printf("----------> *src Source: %s\n", src);            
                printf("----------> *dest Source: %s\n\n", s);

                printf("----------> *s True: %s\n", tmp1);
                printf("----------> *s False: %s\n\n", tmp2);
              }
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }
      
      else
      {
        int i = atoi(argv[4]);
        char dest1[100] = "";
        char dest2[100] = "";
        char src[100] = "";
        strcpy(dest1, argv[2]);
        strcpy(dest2, dest1);
        strcpy(src, argv[3]);
        printf("Source *dest: %s\n", argv[2]);
        printf("Source *src: %s\n", argv[3]);
        printf("Source  n: %d\n", i);
        printf("------------------------------------\n");
        memmove(dest1, src, i);
        printf("        Real Function :\n");
        printf("*s : %s\n", dest1);
        printf("------------------------------------\n");
        ft_memmove(dest2, src, i);
        printf("         FT Function :\n");
        printf("*s : %s\n", dest2);
        if (strcmp(dest1, dest2) == 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (strcmp(dest1, dest2) != 0)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    }

    /*FT_MEMCHR Main*/
      else if(strcmp(argv[1], "memchr") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out memchr 'void *c' 'int c' 'size_t n' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memchr -r 'int n' (-t for time) \n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail, tx, timer, detail = 0;

          unsigned int z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          
          char *tru;
          char *fals;


          char s[200];
          char c;
          int n;
          
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1)
          {
            srand(time(NULL)*x+x);
            c = randomCharac();
            n = randomNumber(15);
            randomnChar(s, 80);
            tru = memchr(s, c, n);
            fals = ft_memchr(s, c, n);
            if(tru != NULL || fals != NULL)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = x-fail+1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              strcpy(errors[fail+1][0], s);
              errors[fail+1][1][0] = c;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != NULL || fals != NULL)
            {
              if (tru != fals)
              printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);       
              printf("----------> *S Random: %s\n", s);          
              printf("----------> True Function Return : %p\n", tru);
              printf("----------> FT Function Return: %p\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> Char Random: %c\n", errors[i+1][1][0]);  
                printf("----------> *s Random: %s\n", errors[i+1][0]);             
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char *c = argv[2];
        char *tru = memchr(argv[2], argv[3][0], atoi(argv[4]));
        char *fals = ft_memchr(argv[2], argv[3][0], atoi(argv[4]));
        printf("Source *s: %s\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %s\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %s\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*FT_MEMCMP Main*/
        else if(strcmp(argv[1], "memcmp") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out memcmp 'const void *s1' 'const void *s2' 'size_t n' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out memcmp -r 'int n' (-t for time) \n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail, tx, timer, detail = 0;

          unsigned int z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          
          int tru;
          int fals;


          char s[200];
          char s2[200];
          int n;
          
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1)
          {
            tru = 0;
            fals = 0;
            srand(time(NULL)*x+x);
            n = randomNumber(80);
            randomnChar(s, 82);
            randomnChar(s2, 82);
            if(n > 40)
            {
              tru = memcmp(s, s, n);
              fals = ft_memcmp(s, s, n);
            }
            else
            {
              tru = memcmp(s, s2, n);
              fals = ft_memcmp(s, s2, n);
            }
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = x-fail+1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              strcpy(errors[fail+1][0], s);
              strcpy(errors[fail+1][1], s2);
              errors[fail+1][2][0] = tru;
              errors[fail+1][2][1] = fals;
              errors[fail+1][2][2] = n;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
              printf("\033[0;31m");
              printf(" :\n");
              printf("----------> *s1 Random: %s\n", s);      
              printf("----------> *s2 Random: %s\n", s2);     
              printf("----------> N Random: %d\n", n);       
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *s1 Random: %s\n", errors[i+1][0]);
                printf("----------> *s2 Random: %s\n", errors[i+1][1]);
                printf("----------> N Random: %d\n", errors[i+1][2][2]);    
                printf("----------> True Function Return : %d\n", errors[i+1][2][0]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);             
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char *s1 = argv[2];
        char *s2 = argv[2];
        int tru = memcmp(argv[2], argv[3], atoi(argv[4]));
        int fals = ft_memcmp(argv[2], argv[3], atoi(argv[4]));
        printf("Source *s1: %s\n", s1);
        printf("------------------------------------\n");
        printf("Source *s2: %s\n", s2);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*FT_STRLEN Main*/
    else if(strcmp(argv[1], "strlen") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("---------------------------------\n");
          printf("./a.out strlen  'void *dest'\n");
          printf("---------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out strlen -r 'int nt(0-200)'\n");
          printf("---------------------------------\n");
          printf("\033[0m");
          return 0;
      }

      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        /*else if(atoi(argv[3]) > 100000)
        {
          printf("\033[0;31m");
          printf("-----------------------------------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 100 000 inclus !\n");
          printf("-----------------------------------------------------------------\n");
          printf("\033[0m");
        }*/

        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          long long int timing;
          long long int timing2;


          int x;

          x = 0;
          char src[255];
          int tru = 0;
          int fals;
          timing = time(NULL);
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);
            strcpy(src, "");
            randomnChar(src, 90);
            tru = strlen(src);
            fals = ft_strlen(src);

            if (tru == fals)
            {
              printf("Test %d = succès :\n", x + 1);
              printf("----------> *src Random: %s\n", src);            
              printf("----------> True Function Lenght : %d\n", tru);
              printf("----------> FT Function Lenght : %d\n\n", fals);
            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", x + 1) ;
              if (tru != fals)
              {
                printf("Function Result Error.\n");
              printf("----------> *src Random: %s\n", src);            
              printf("----------> True Function Lenght : %d\n", tru);
              printf("----------> FT Function Lenght : %d\n", fals);
              }
              else 
              {
                printf("Unkown.\n");
              printf("----------> *src Random: %s\n", src);            
              printf("----------> True Function Lenght : %d\n", tru);
              printf("----------> FT Function Lenght : %d\n", fals);
              }
            printf("\n");
            printf("\033[0;32m");
            }
            x++;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
          timing2 = time(NULL);
          if (strcmp(argv[4], "-t") == 0 && timing2-timing > 0)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
          else
            return 0;
        }
      }
      
      else
      {
        unsigned int tru;
        unsigned int fals;
        char src[100] = "";
        strcpy(src, argv[2]);
        printf("Source *s: %s\n", argv[2]);
        printf("------------------------------------\n");
        tru = strlen(src);
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        fals = ft_strlen(src);
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru != fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*FT_ISALPHA Main*/
    else if(strcmp(argv[1], "isalpha") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out isalpha 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out isalpha -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(200);
            tru = isalpha(c);
            fals = ft_isalpha(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = isalpha(c);
        int fals = ft_isalpha(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*ISDIGIT Main*/
    else if(strcmp(argv[1], "isdigit") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out isdigit 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out isdigit -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(200);
            tru = isdigit(c);
            fals = ft_isdigit(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = isdigit(c);
        int fals = ft_isdigit(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*ISALNUM Main*/
    else if(strcmp(argv[1], "isalnum") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out isalnum 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out isalnum -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(200);
            tru = isalnum(c);
            fals = ft_isalnum(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = isalnum(c);
        int fals = ft_isalnum(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*ISASCII Main*/
    else if(strcmp(argv[1], "isascii") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out isascii 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out isascii -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(200);
            tru = isascii(c);
            fals = ft_isascii(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = isascii(c);
        int fals = ft_isascii(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*ISPRINT Main*/
      else if(strcmp(argv[1], "isprint") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out isprint 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out isprint -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(200);
            tru = isprint(c);
            fals = ft_isprint(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = isprint(c);
        int fals = ft_isprint(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %d\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*TOUPPER Main*/
    else if(strcmp(argv[1], "toupper") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out toupper 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out toupper -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(127);
            tru = toupper(c);
            fals = ft_toupper(c);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != c)
            {
              if (tru != fals)
              printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %c\n", tru);
              printf("----------> FT Function Return: %c\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> Char Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %c\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %c\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = toupper(c);
        int fals = ft_toupper(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %c\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %c\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*TOLOWER Main*/
    else if(strcmp(argv[1], "tolower") == 0) 
    {
      if (argc <= 2 || (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0 ))
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out tolower 'char c' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out tolower -r 'int n' (-t for time) (-c for detail)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(argc == 3 || atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          
          int timer = 0;
          int detail = 0;
          unsigned int z;
          z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          int tru;
          int fals;
          char c;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);

            c = randomNumber(127);
            tru = tolower(c);
            fals = ft_tolower(c);
            if(tru != c)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              errors[fail+1][0][0] = c;
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != c)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> Char Random: %c\n", c);             
              printf("----------> True Function Return : %c\n", tru);
              printf("----------> FT Function Return: %c\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
                printf("----------------------------------------------------------\n");
            if (fail != 0)
            {
              while (i <= fail && i < 100)
              {
                printf("\033[0;31m");
                printf("Echec n°%d :\n", i);
                printf("----------> *nptr Random: %c\n", errors[i+1][0][0]);             
                printf("----------> True Function Return : %c\n", errors[i+1][1][1]);
                printf("----------> FT Function Return: %c\n", errors[i+1][2][1]);
                printf("\033[0m");
                printf("----------------------------------------------------------\n");

                i++;
              }
            }
            else
            {
                printf("\033[0;32m");
                printf("SUCCESS : Aucun échec !\n");
                printf("\033[0m");
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
        if(timer == 1)
        {
          if(timing2-timing >= 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
        }
        else
            return 0;
        }
      }
      
      else
      {

        char c = argv[2][0];
        int tru = tolower(c);
        int fals = ft_tolower(c);
        printf("Source *nptr: %c\n", c);
        printf("------------------------------------\n");
        printf("Real Function : %c\n", tru);
        printf("------------------------------------\n");
        printf("FT Function : %c\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 


    /*FT_STRCHR Main*/
    else if (strcmp(argv[1], "strchr") == 0) 
    {
    	(void)argc;

      printf("-------------------\n"); 
      printf("Real strchr : ");
      printf("%s --> %s\n", argv[2], strchr(argv[2], argv[3][0]));
      printf("False strchr : ");
      printf("%s --> %s\n", argv[2], ft_strchr(argv[2], argv[3][0]));
      printf("-------------------\n"); 
    }

    /*FT_STRRCHR Function*/
    else if(strcmp(argv[1], "strrchr") == 0) 
    {
      (void)argc;

      printf("-------------------\n"); 
      printf("Real strrchr : ");
      printf("%s --> %s\n", argv[2], strrchr(argv[2], argv[3][0]));
      printf("False strrchr : ");
      printf("%s --> %s\n", argv[2], ft_strrchr(argv[2], argv[3][0]));
      printf("-------------------\n"); 
    }

    /*FT_STRNCMP Function*/
    else if(strcmp(argv[1], "strncmp") == 0) 
    {
    	(void)argc;

      printf("-------------------\n"); 
      printf("Real strncmp : ");
      printf("%s && %s --> %d\n", argv[2],argv[3], strncmp(argv[2], argv[3], 5));
      printf("False strncmp : ");
      printf("%s && %s --> %d\n", argv[2], argv[3], ft_strncmp(argv[2], argv[3], 5));
      printf("-------------------\n"); 
      return 0;
    }

    /*FT_STRLCPY Function*/
    else if(strcmp(argv[1], "strlcpy") == 0) 
    {
      (void)argc;
        char stockdest1[100];
        char stocksrc1[100];
        char stockdest2[100];
        char stocksrc2[100];
        strcpy(stockdest1, argv[2]);
        strcpy(stockdest2, argv[2]);
        strcpy(stocksrc1, argv[3]);
        strcpy(stocksrc2, argv[3]);

        char *dest = argv[2];
        char *src = argv[3];
        int i = atoi(argv[4]) + 1;
        printf("Before return src: %s\n", src);
        printf("Before return dest: %s\n", dest);
        printf("------------------------------------\n");
        strlcpy(stockdest1, stocksrc1, i);
        printf("Real return src: %s\n", stocksrc1);
        printf("Real return dest: %s\n", stockdest1);
        printf("------------------------------------\n");
        ft_strlcpy(stockdest2, stocksrc2, i);
        printf("FT return src: %s\n", stocksrc2);
        printf("FT return dest: %s\n", stockdest2);
        return 0;
    }


    /*FT_STRLCAT Main*/
    else if(strcmp(argv[1], "strlcat") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("./a.out strlcat  'char *dst' 'char *src' 'size_t size'\n");
          printf("------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out strlcat -r 'int nt(0-40)'\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 4)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 40)
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Le nombre de Random doit etre compris entre 1 et 40 inclus !\n");
          printf("------------------------------------\n");
          printf("\033[0m");
         return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");

          int x;
          x = atoi(argv[3]);
          char src1[100];
          char src2[100];
          char dest1[100];
          char dest2[100];
          int i = 0;
          size_t t = 0;
          size_t f = 0;
          while (x > 0) 
          {

            srand(time(NULL)*x*4);
            randomChar(src1);
            randomChar(dest1);
            strcpy(src2, src1);
            strcpy(dest2, dest1);
            i = randomNumber(30);

            t = strlcat(dest2, src2, i);
            f = ft_strlcat(dest1, src1, i);
            
            if ( f == t && (strcmp(dest1, dest2) == 0))
            {
            printf("Test %d = succès\n", atoi(argv[3]) - x + 1);
            printf("-------> Dest True: %s\n", dest2);
            printf("-------> Dest False: %s\n", dest1);

            }
            else
            {
            printf("\033[0;31m");
            printf("Test %d = échec :", atoi(argv[3]) - x + 1) ;
            if (strlcat(dest1, src1, i) != ft_strlcat(dest2, src2, i))
               printf("Function Result Error : True = %ld vs False = %ld . ", t, f);
            if (strcmp(dest1, dest2) != 0)
               printf("Destination Error. ");
            printf("\n");
            printf("\033[0;32m");
            }
            x--;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
                  return 0;
        }
      }

        (void)argc;
        char stockdest1[100];
        char stocksrc1[100];
        char stockdest2[100];
        char stocksrc2[100];
        strcpy(stockdest1, argv[2]);
        strcpy(stockdest2, argv[2]);
        strcpy(stocksrc1, argv[3]);
        strcpy(stocksrc2, argv[3]);

        char *dest = argv[2];
        char *src = argv[3];
        int i = atoi(argv[4]);
        printf("Before return src: %s\n", src);
        printf("Before return dest: %s\n", dest);
        printf("Before return size: %d\n", i);
        printf("------------------------------------\n");
        printf("Real Function : %ld\n", strlcat(stockdest1, stocksrc1, i));
        printf("Real return src: %s\n", stocksrc1);
        printf("Real return dest: %s\n", stockdest1);
        printf("------------------------------------\n");
        printf("FT Function : %ld\n", ft_strlcat(stockdest2, stocksrc2, i));
        printf("FT return src: %s\n", stocksrc2);
        printf("FT return dest: %s\n", stockdest2);
        if (strcmp(stockdest1, stockdest2) != 0||
         strlcat(stockdest1, stocksrc1, i) == ft_strlcat(stockdest2, stocksrc2, i))
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!!\n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (stockdest1 != stockdest2)
          {
            printf("          Dest Error !!!\n");
          }
          if (stocksrc1 != stocksrc2)
          { 
            printf("          Src Error !!!\n");
          }
          if (strlcat(stockdest1, stocksrc1, i) != ft_strlcat(stockdest2, stocksrc2, i))
          {
            printf("          Return Error !!!\n");
          }
          printf("------------------------------------\n");
          printf("\033[0m");
        }

        return 0;
    }

    /*FT_STRNSTR Main*/
    else if(strcmp(argv[1], "strnstr") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out strnstr 'void *Big' 'void *Little' 'size_t n'\n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out strnstr -r 'int n' (-t for time)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int x;
          int i;
          char bigc[255];
          char littlec[255];
          const char *big;
          const char *little;
          char *tru;
          char *fals;
          long long int timing;
          long long int timing2;
          timing = time(NULL);

          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);
            randomnChar(bigc, 90);
            randomnChar(littlec, 5);
            big = bigc;
            little = littlec;
            i = randomNumber(90);
            tru = strnstr(big, little, i);
            fals = ft_strnstr(big, little, i);

            if (tru == fals)
            {
              if(tru != NULL && little[0] != '\0')
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
                printf("Test %d = succès", x + 1);
            }
            else
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }

            }
            if(tru != NULL && little[0] != '\0')
            {
              printf(" :\n");
              printf("----------> *Big Random: %s\n", big);
              printf("----------> *Little Random: %s\n", little); 
              printf("----------> *Len Random: %d\n", i);              
              printf("----------> True Function Return : %s\n", tru);
              printf("----------> FT Function Return: %s\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 

          
          printf("------------------------------------\n");
          printf("\033[0m");
          timing2 = time(NULL);
          if (strcmp(argv[4], "-t") == 0 && timing2-timing > 0)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
          else
            return 0;
        }
      }
      
      else
      {
        const char *big = argv[2];
        const char *little = argv[3];
        char* tru;
        char* fals;
        int i = 0;
        i = atoi(argv[4]);
        printf("Source *Big: %s\n", argv[2]);
        printf("Source *Little: %s\n", argv[3]);
        printf("Source *Len: %d\n", i);
        printf("------------------------------------\n");
        tru = strnstr(big, little, i);
        printf("Real Function : %s\n", tru);
        printf("------------------------------------\n");
        fals = ft_strnstr(big, little, i);
        printf("FT Function : %s\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 

    /*FT_ATOI Main*/
    else if(strcmp(argv[1], "atoi") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out atoi 'char *nptr' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out atoi -r 'int n' (-t for time)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          int timer = 0;
          int detail = 0;

          unsigned int z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          char nptrc[255];
          char *nptr;
          int tru;
          int fals;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);
            randomnChar(nptrc, 10);
            nptr = nptrc;
            tru = atoi(nptr);
            fals = ft_atoi(nptr);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              strcpy(errors[fail+1][0], nptr);
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> *nptr Random: %s\n", nptr);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
            while (i <= fail && i < 100)
            {
              printf("\033[0;31m");
              printf("Echec n°%d :\n", i);
              printf("----------> *nptr Random: %s\n", errors[i+1][0]);             
              printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
              printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");

              i++;
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
          if (timer == 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timer == 1 && timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
          else
            return 0;
        }
      }
      
      else
      {
        char *nptr = argv[2];
        int tru = 0;
        int fals = 0;
        printf("Source *nptr: %s\n", nptr);
        printf("------------------------------------\n");
        tru = atoi(nptr);
        printf("Real Function : %d:\n", tru);
        printf("------------------------------------\n");
        fals = ft_atoi(nptr);
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 
  /*End EasyOnes*/

  /*Start RAMSPEC CUSTOM*/
    /*FT_CALLOC Main*/
    else if(strcmp(argv[1], "calloc") == 0) 
    {
      if (strcmp(argv[2] , "-help") == 0 || strcmp(argv[2] , "-h") == 0)
      {
          printf("\033[0;32m");
          printf("-----------------------------------------------------\n");
          printf("./a.out atoi 'char *nptr' \n");
          printf("-----------------------------------------------------\n");
          printf("Randoms Test :\n");
          printf("./a.out atoi -r 'int n' (-t for time)\n");
          printf("-----------------------------------------------------\n");
          printf("\033[0m");
          return 0;
      }
      else if (strcmp(argv[2] , "-r") == 0)
      {
        if (argc < 3)
        {
          printf("\033[0;31m");
          printf("-------------------------\n");
          printf("Nombre de test invalide !\n");
          printf("-------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) < 0)
        {
          printf("\033[0;31m");
          printf("---------------------------------------\n");
          printf("Le nombre de Random doit etre positif !\n");
          printf("---------------------------------------\n");
          printf("\033[0m");
          return 0;
        }
        else if(atoi(argv[3]) > 0)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          int succes = 0;
          int fail = 0;
          int tx = 0;
          int timer = 0;
          int detail = 0;

          unsigned int z = argc;
          while (z > 0) 
          {
            if(strcmp(argv[z-1], "-t") == 0)
            {
              timer = 1;
              z--;
            }
            else if (strcmp(argv[z-1], "-c") == 0)
            {
              detail = 1;
              z--;
            }
            else
              z--;
          }

          char errors[100][255][255];

          int x;
          char nptrc[255];
          char *nptr;
          int tru;
          int fals;
          long long int timing;
          long long int timing2;
          timing = time(NULL);
          x = 0;
          while (x <= atoi(argv[3])-1) 
          {
            srand(time(NULL)*x+x);
            randomnChar(nptrc, 10);
            nptr = nptrc;
            tru = atoi(nptr);
            fals = ft_atoi(nptr);
            if(tru != 0 || fals != 0)
              {
                printf("\033[0m");
                printf("----------------------------------------------------------\n");
                printf("\033[0;32m");
               }
            if (tru == fals)
            {

              printf("\033[0;32m");
              printf("Test %d = succès", x + 1);
              succes = succes + 1;
            }
            else if(tru != fals)
            {
              printf("\033[0;31m");
              printf("Test %d = échec : ", x + 1) ;
              fail = fail+1;
              strcpy(errors[fail+1][0], nptr);
              errors[fail+1][1][1] = tru;
              errors[fail+1][2][1] = fals;
              if (tru != fals)
              {
                printf("Function Result Error");
              }
              else 
              {
                printf("Unkown");
              }


            }
            if(tru != 0 || fals != 0)
            {
              if (tru != fals)
                printf("\033[0;31m");
              printf(" :\n");
              printf("----------> *nptr Random: %s\n", nptr);             
              printf("----------> True Function Return : %d\n", tru);
              printf("----------> FT Function Return: %d\n", fals);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
              printf("\033[0;32m");
            }
            else
            {
              printf(".\n");
            }
            x++;
          } 


          if(detail == 1)
          {
            int i = 1;
              printf("\033[0m");
              printf("----------------------------------------------------------\n");
            while (i <= fail && i < 100)
            {
              printf("\033[0;31m");
              printf("Echec n°%d :\n", i);
              printf("----------> *nptr Random: %s\n", errors[i+1][0]);             
              printf("----------> True Function Return : %d\n", errors[i+1][1][1]);
              printf("----------> FT Function Return: %d\n", errors[i+1][2][1]);
              printf("\033[0m");
              printf("----------------------------------------------------------\n");

              i++;
            }
          }



          tx = (atoi(argv[3])/succes) * 100;
          if (tx == 100 && fail != 0)
            tx = 99;
          printf("------------------------------------\n");
          printf("\033[0m");
          printf("Nombre de succès : %d\n", succes);
          printf("Nombre d'échecs : %d\n", fail);
          printf("Taux de réussite = ");
          if (tx < 100)
          {
            printf("\033[0;31m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          else
          {
            printf("\033[0;32m");
            printf("%d", tx);
            printf("\033[0m");
            printf(" %%");
            printf("\n");
          }
          printf("------------------------------------\n");
          timing2 = time(NULL);
          if (timer == 1)
          {
            printf("%d Oppérations se sont effectuées en %lld secondes\n", atoi(argv[3]), timing2 - timing);
            printf("Soit %lld oppérations/seconde\n", (atoi(argv[3])/(timing2 - timing)));
            printf("\n");
            return 0;
          }
          else if (timer == 1 && timing2-timing < 1)
          {
            printf("%d Oppérations se sont effectuées en moins d'une seconde\n", atoi(argv[3]));
            printf("\n");
          }
          else
            return 0;
        }
      }
      
      else
      {
        char *nptr = argv[2];
        int tru = 0;
        int fals = 0;
        printf("Source *nptr: %s\n", nptr);
        printf("------------------------------------\n");
        tru = atoi(nptr);
        printf("Real Function : %d:\n", tru);
        printf("------------------------------------\n");
        fals = ft_atoi(nptr);
        printf("FT Function : %d\n", fals);
        if (tru == fals)
        {
          printf("\033[0;32m");
          printf("------------------------------------\n");
          printf("            WORKING !!! \n");
          printf("------------------------------------\n");
          printf("\033[0m");
        }
        else
        {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("          NOT WORKING !!!\n");
          printf("------------------------------------\n");
          if (tru == fals)
          {
            printf("          Return Error !!!\n");
          }
          else
          { 
            printf("          Unknown Error !!!\n");
          }
          printf("\033[0m");
        }

        return 0;
      }
    } 
  /*End RAMSPEC CUSTOM*/

  /*ERRORS*/
  else 
  {
          printf("\033[0;31m");
          printf("------------------------------------\n");
          printf("Unknown Function !!!\n");
          printf("------------------------------------\n");
          printf("\033[0m");
          return 0;
  }
return 0;

}