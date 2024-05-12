#include "main.h"

//handles special characters \n, \b
//if its not special it returns the first character
char get_char(char *str)
{
	if (!strcmp(str, "\\n"))
		return ('\n');
	
	if (!strcmp(str, "\\b"))
		return (' ');

	return (str[0]);
}


//sil

//returns the new file after chars deleted
//assumes numbers are correct
char *get_deleted(FILE *out_file,char to_del, int len, int left_most)
{
	char	*buff = (char *)malloc(sizeof(char) * ( len -  left_most + 1));
	int		i = 0;
	char	c;

	//fseek(out_file, left_most, SEEK_SET); //in index 0 but why no err on others

	while((c = ft_getc()) != EOF)
	{
		if (c == to_del)
			continue;
		buff[i++] = c;
	}
	buff[i] = '\0';

	return buff;
}