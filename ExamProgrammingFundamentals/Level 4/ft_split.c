#include <stdio.h>
#include <stdlib.h>

int isDelim(int c)
{
        return(c == 32 || (c >= 9 && c <= 13));
}

int word_count(const char *str)
{
        int i = 0;
        int count = 0;
        while(str[i] != '\0')
        {
                while(str[i] && isDelim(str[i]))
                        i++;
                if(str[i] && !isDelim(str[i]))
                        count++;
                while(str[i] && !isDelim(str[i]))
                        i++;
        }
	return count;
}

char **ft_split(const char *str)
{
        char **result;
        int i = 0;
        int j = 0;
        int size = 0;
        //size calculation && allocation for pointers
        size = word_count(str);
        result = malloc((sizeof(char *) * (size + 1)));
        if(!result)
                return NULL;
        //word_length calculation && allocation for each word
        int k = 0;
        int start = 0;
        int w_size = 0;
        while(size > i)
        {
                while(str[j] && isDelim(str[j]))
                        j++;
                start = j;
                while(str[j] && !isDelim(str[j]))
                        j++;
                w_size = j - start;
                result[i] = malloc((w_size + 1) * sizeof(char));
                if(!result[i]){
                        return NULL;
                }
                k = 0;
                while(w_size > k)
                {
                        result[i][k] = str[start + k];
                        k++;
                }
                result[i][k] = '\0';
                i++;
        }
	result[size] = NULL;
        return (result);
}

//tests

int main()
{
        const char *s = "  Hello 423  world\tthis is a\n test ";

    char **tab = ft_split(s);

    for (int i = 0; tab[i]; i++)
    {
     	printf("word: %s\n",  tab[i]);
        free(tab[i]);
    }
    free(tab);

    return 0;
}















