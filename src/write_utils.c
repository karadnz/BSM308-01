#include "main.h"

int _i = 0; //ftell
char *_buff; //

//inserts a char in to current index
// i = 3
//buff = aaabc
//before = aaa
//after = bc
//new_buff = aaaXbc
void	ft_putc(char c)
{
	char *after = strdup(_buff + _i);
	_buff[_i] = '\0';
	char *before = strdup(_buff);
	char toAdd[2] = {c, '\0'};

	char *new_buff = (char *)malloc(sizeof(char) * (strlen(before) + strlen(after) + 2)); //\0 and c

	strcat(new_buff, before);
	strcat(new_buff, toAdd);
	strcat(new_buff, after);

	free(after);
	free(before);
	free(_buff);
	_buff = new_buff;
	_i++;
}

void ft_puts(char *str)
{
	_buff[_i] = '\0';
	char *new_buff = (char *)malloc(sizeof(char) * (strlen(_buff) + strlen(str) + 1)); //\0 and c

	strcat(_buff, str); //nulla
	_i += strlen(str);

}

void ft_truncate()
{
	_buff[_i + 1] = '\0'; //??

}

char	ft_getc()
{
	return _buff[_i];
	_i++; //to maintain compatibility
}

int		ft_tell()
{
	return _i;
}

void	ft_seek(int i, int flag)
{

	switch (flag)
	{
		case SEEK_CUR:
			_i = _i + i;
			break;

		case SEEK_SET:
			_i = i;
			break;
	
		default:
			break;
	}

}