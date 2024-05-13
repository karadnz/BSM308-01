
#include "myio.h"

//int _i = 0; //ftell
//char *_buff; //



myFILE *ft_open()
{
	myFILE *rt = (myFILE *)malloc(sizeof(myFILE));

	rt->_buff = (char *)malloc(sizeof(char));
	rt->_buff[0] = '\0';

	rt->_fpos = 0;

	return rt;
}

void ft_close(myFILE *file)
{
	free(file->_buff);
}

//inserts a char into current fpos
//fpos = 3 (b)
//buff = aaabc
//before = aaa
//after = bc
//new_buff = aaaXbc 
void	ft_putc2(myFILE *file, char c)
{
	char *after = strdup(file->_buff + file->_fpos);
	file->_buff[file->_fpos] = '\0';
	char *before = strdup(file->_buff);
	char toAdd[2] = {c, '\0'};

	char *new_buff = (char *)malloc(sizeof(char) * (strlen(before) + strlen(after) + 2)); //\0 and c

	strcat(new_buff, before);
	strcat(new_buff, toAdd);
	strcat(new_buff, after);
	int i = 0;
	//printf("buff\t%s, before:\t%s, after:\t%s, new_buff:\t%s\n",_buff, before, after, new_buff);
	free(after);
	free(before);
	free(file->_buff);
	file->_buff = new_buff;
	file->_fpos++;
}

void	ft_putc(myFILE *file, char c)
{
	int		len = strlen(file->_buff);
	char	*new_buff = (char *)malloc(sizeof(char) * (len + 2)); //\0 and c

	//before the offset
	//aaa bcc 3
	memcpy(new_buff, file->_buff, file->_fpos); //aaa

	new_buff[file->_fpos] = c; //aaac 

	memcpy(new_buff + file->_fpos + 1, file->_buff + file->_fpos, len - file->_fpos); //aaacbcc

	new_buff[len + 1] = '\0';

	free(file->_buff);
	file->_buff = new_buff;
	file->_fpos++;

}

//inserts a string into current fpos
void ft_puts(myFILE *file,char *str)
{
	file->_buff[file->_fpos] = '\0';
	char *new_buff = (char *)malloc(sizeof(char) * (strlen(file->_buff) + strlen(str) + 1)); //\0 and c

	strcat(file->_buff, str); //nulla
	file->_fpos += strlen(str);

}

//makes the current fpos \0 
//TODO: implement the correct behavior
void ft_truncate(myFILE *file, int len)
{
	file->_buff[file->_fpos + 1] = '\0'; //??

}

char ft_getc(myFILE *file)
{
	if (file->_fpos >= strlen(file->_buff))
		return EOF;
	//to maintain compatibility
	return file->_buff[file->_fpos++];
 
}

//returns fpos
int ft_tell(myFILE *file)
{
	return file->_fpos;
}

//changes the fpos based on given flag
int ft_seek(myFILE *file, int offset, int flag)
{

	switch (flag)
	{
		case SEEK_CUR:
			file->_fpos = file->_fpos + offset;
			break;

		case SEEK_SET:
			file->_fpos = offset;
			break;
		case SEEK_END:
			file->_fpos = strlen(file->_buff);
			break;
	
		default:
			break;
	}
	return 0; //CHANGE
}