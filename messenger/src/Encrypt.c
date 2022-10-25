/*This file includes the encrypt function*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* password)
{
    char en[2000];
    int a;
    char* pass_holder=password;
    /*goes through 2 cycles of encryption*/
    for(int i=0;i<2;i++)
    {
        a = 0;
        if(en[0] != '\0')
            en[0] = '\0';
        while(pass_holder[a]!='\0')
        {
            switch(pass_holder[a])
            {
                case 'a':
                    strcat(en,"T3GC");
                    break;
                case 'b':
                    strcat(en,"Kyyj");
                    break;
                case 'c':
                    strcat(en,"Ykwg");
                    break;
                case 'd':
                    strcat(en,"aqkg");
                    break;
                case 'e':
                    strcat(en,"fZhA");
                    break;
                case 'f':
                    strcat(en,"N4U8");
                    break;
                case 'g':
                    strcat(en,"X4IK");
                    break;
                case 'h':
                    strcat(en,"Qn7H");
                    break;
                case 'i':
                    strcat(en,"4Pyc");
                    break;
                case 'j':
                    strcat(en,"YBcd");
                    break;
                case 'k':
                    strcat(en,"bZfl");
                    break;
                case 'l':
                    strcat(en,"4eTu");
                    break;
                case 'm':
                    strcat(en,"LEG2");
                    break;
                case 'n':
                    strcat(en,"IhON");
                    break;
                case 'o':
                    strcat(en,"qbQB");
                    break;
                case 'p':
                    strcat(en,"GDi9");
                    break;
                case 'q':
                    strcat(en,"l38B");
                    break;
                case 'r':
                    strcat(en,"JpJV");
                    break;
                case 's':
                    strcat(en,"sby2");
                    break;
                case 't':
                    strcat(en,"Oyx2");
                    break;
                case 'u':
                    strcat(en,"IcED");
                    break;
                case 'v':
                    strcat(en,"zDjL");
                    break;
                case 'w':
                    strcat(en,"Q2fI");
                    break;
                case 'x':
                    strcat(en,"4phD");
                    break;
                case 'y':
                    strcat(en,"2Y7p");
                    break;
                case 'z':
                    strcat(en,"e264");
                    break;
                case 'A':
                    strcat(en,"g3o2");
                    break;
                case 'B':
                    strcat(en,"mgYC");
                    break;
                case 'C':
                    strcat(en,"mFYQ");
                    break;
                case 'D':
                    strcat(en,"Wd8X");
                    break;
                case 'E':
                    strcat(en,"pZaO");
                    break;
                case 'F':
                    strcat(en,"88MS");
                    break;
                case 'G':
                    strcat(en,"5s80");
                    break;
                case 'H':
                    strcat(en,"WBiQ");
                    break;
                case 'I':
                    strcat(en,"e3ey");
                    break;
                case 'J':
                    strcat(en,"6CNm");
                    break;
                case 'K':
                    strcat(en,"26Tg");
                    break;
                case 'L':
                    strcat(en,"5OuF");
                    break;
                case 'M':
                    strcat(en,"iJtZ");
                    break;
                case 'N':
                    strcat(en,"4WSj");
                    break;
                case 'O':
                    strcat(en,"bPqG");
                    break;
                case 'P':
                    strcat(en,"1u2K");
                    break;
                case 'Q':
                    strcat(en,"QV0x");
                    break;
                case 'R':
                    strcat(en,"sVLv");
                    break;
                case 'S':
                    strcat(en,"xO3U");
                    break;
                case 'T':
                    strcat(en,"47ke");
                    break;
                case 'U':
                    strcat(en,"NQtC");
                    break;
                case 'V':
                    strcat(en,"FOKf");
                    break;
                case 'W':
                    strcat(en,"WPZM");
                    break;
                case 'X':
                    strcat(en,"7ahM");
                    break;
                case 'Y':
                    strcat(en,"gLnW");
                    break;
                case 'Z':
                    strcat(en,"dNXw");
                    break;
                case '1':
                    strcat(en,"vy44");
                    break;
                case '2':
                    strcat(en,"w6PI");
                    break;
                case '3':
                    strcat(en,"I62F");
                    break;
                case '4':
                    strcat(en,"sEo9");
                    break;
                case '5':
                    strcat(en,"bVjM");
                    break;
                case '6':
                    strcat(en,"rjfC");
                    break;
                case '7':
                    strcat(en,"33xq");
                    break;
                case '8':
                    strcat(en,"6JzE");
                    break;
                case '9':
                    strcat(en,"Wjxf");
                    break;
                case '0':
                    strcat(en,"3dHs");
                    break;
                case '!':
                    strcat(en,"DhfX");
                    break;
                case '@':
                    strcat(en,"exbX");
                    break;
                case '#':
                    strcat(en,"gciW");
                    break;
                case '$':
                    strcat(en,"Ijke");
                    break;
                case '%':
                    strcat(en,"7gUV");
                    break;
                case '^':
                    strcat(en,"wz1T");
                    break;
                case '&':
                    strcat(en,"6eoJ");
                    break;
                case '*':
                    strcat(en,"FJOt");
                    break;
                case '(':
                    strcat(en,"BVBL");
                    break;
                case ')':
                    strcat(en,"hKuH");
                    break;
            }
            a++;
        }
	/*creates a pointer of the encrypted password to be returned*/
        char* empty = malloc(sizeof(en)+1);
        for(int j=0;j<sizeof(en);j++)
        {
            empty[j] = en[j];
        }
        empty[sizeof(en)+1] = '\0';
        pass_holder = malloc(sizeof(empty)+1);
	pass_holder = empty;
    }
    return pass_holder;
}

/*Testing*/
/*int main()
{
    char* a;
    char* b;
    //char* c;
    char* d;
    a="abcbhtgdrgdsf3se";
    printf("Password: %s\n",a);
    b=encrypt(a);
    printf("Encrypted Password b: %s\n",b);
    //c=encrypt(b);
    //printf("Encrypted Password c: %s\n",c);
    //printf("sizeof: %lu\n",strlen(b),strlen(c));
    d=encrypt(a);
    printf("Encrypted Password d: %s\n",d);
    if(strcmp(b,d) == 0)
      printf("They are the same\n");
    return 0;
}*/

