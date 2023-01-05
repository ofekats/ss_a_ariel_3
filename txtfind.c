#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

/**
 * this function get a line from the user
 * @param s -an array that save the line input 
 * @return the size of the line
*/
int _getline(char s[])
{
    int i = 0;
    int c =0;
    while ((c = getchar()) != EOF && i < LINE)
    {
        s[i] = c;
        if (i > 1 && s[i] == '\n' )
        {
            s[i] = '\0';
            break;
        }

        i++;
    }
    if(c == EOF && i == 0)
    {
        return 0;
    }
    return (int)strlen(s);
}

/**
 * this function get a word from the user
 * @param w -an array that save the word input 
 * @return the size of the word
*/
int getword(char w[])
{
    int i = 0;
    int c = 0;
    while ((c = getchar()) != EOF && (i < WORD))
    {
        w[i] = c;
        if (((w[i] == '\n') || (w[i] == '\t') || (w[i] == '\r') || (w[i] == ' ')))
        {
            w[i] = '\0';
            break;
        }
        i++;
    }
    if(c == EOF && i == 0)
    {
        return 0;
    }
    return (int)strlen(w);
}

/**
 * this function check if str1 contains str2 (as is)
 * @param str1 -first string (check in that)
 * @param str1 -second string (check if str2 in str1)
 * @return 1- if str1 contains str2 and 0 if not
*/
int substring(char *str1, char *str2)
{
    if (strlen(str1) < strlen(str2))
    {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < (int)strlen(str1); i++)
    {
        for (int j = 0; j < (int)strlen(str2); j++)
        {
            if (str1[i] == str2[j])
            {
                count++;
                if (count == (int)strlen(str2))
                {
                    return 1;
                }
                i++;
            }
            else
            {
                i -= count;
                count = 0;
                break;
            }
        }
    }

    return 0;
}

/**
 * this function check if str1 contains str2 (as is or without one char- in any place in str1)
 * @param str1 -first string (check in that)
 * @param str1 -second string (check if str2 in str1)
 * @return 1- if str1 contains (as is or without one char- in any place in str1) str2 and 0 if not
*/
int similar(char *s, char *t)
{
    if((strlen(s) == strlen(t)) && substring(s,t))
    {
        return 1;
    }
    char s_new [WORD];
    for (int i = 0; i <= (int)strlen(s); i++)
    {
        strncpy(s_new, s, i);
        strcpy(s_new+i, s+i+1);
        int res = substring(s_new, t);
        if ((strlen(s_new) == strlen(t)) && res)
        {
            return 1;
        }
        memset(s_new ,0 ,(int)sizeof(s_new));
    }
    return 0;
}

/**
 * this function print the line that contains str (as is)
 * @param str -the string to check in line
*/
void print_lines(char * str)
{
    char r [LINE];
    char * line = r;
    int isthere =0;
    while(_getline(line) != 0)
    {
        isthere = substring(line, str);
        if(isthere)
        {
            printf("%s\n", line);
        }
    }
}

/**
 * this function print the word that contains str (as is or without one char- in any place in the word)
 * @param str -the string to check in word
*/
void print_similar_words(char * str)
{
    char r [WORD];
    char * word = r;
    int isthere =0;
    int sum =0;
    int size =0;
    while(sum < LINE && (size = getword(word) != 0 ))
    {
        isthere = similar(word, str);
        if(isthere)
        {
            printf("%s\n", word);
        }
        sum +=size;
    }
}


int main()
{
    char str1 [WORD];
    char *str = str1; 
    scanf("%s", str);
    char AorB1 [WORD];
    char * AorB = AorB1;
    scanf("%s", AorB);
    char nextline1[2];
    char * nextline = nextline1;
    scanf("%c", nextline);
    scanf("%c", &nextline[1]);
    if(AorB[0] == 'a')
    {
        print_lines(str);
    }
    if(AorB[0] == 'b')
    {
        print_similar_words(str);
    }
    return 0;
}