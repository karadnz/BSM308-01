#ifndef MYIO_H
#define MYIO_H

#include <stdlib.h> //malloc
#include <string.h>

#	ifndef SEEK_CUR
#	define SEEK_CUR 1
#	endif

#	ifndef SEEK_SET
#	define SEEK_SET 0
#	endif

#	ifndef SEEK_END
#	define SEEK_END 2
#	endif

#	ifndef EOF
#	define EOF (-1)
#	endif

typedef long long my_fpos;


typedef struct s_myFILE
{
	my_fpos	_fpos;
	char	*_buff; //file->_buff

} myFILE;

myFILE	*ft_open();
void	ft_close(myFILE *file);

void	ft_putc(myFILE *file, char c);
void	ft_puts(myFILE *file,char *str);
void	ft_truncate(myFILE *file, int len);
char	ft_getc(myFILE *file);
int		ft_tell(myFILE *file);
int		ft_seek(myFILE *file, int offset, int flag);

#endif