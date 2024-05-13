#include "main.h"

int command(char *cmd, FILE *out_file, IS is, myFILE *tmp_file) //return is unused
{
	if (out_file->_file == -1) //check if closed
		ft_err(ERR_CLOSED);

    if (!strcmp(cmd, YAZ))
		return yaz(tmp_file, is);
        
    if (!strcmp(cmd, SIL))
        return sil(tmp_file, is);

    if (!strcmp(cmd, SONAGIT))
        return sonagit(tmp_file, is);

    if (!strcmp(cmd, DUR))
        return dur(tmp_file, out_file, is);
	
	return (0);
}

int yaz(myFILE *tmp_file, IS is)
{
	for (int i = 1; i + 1 < is->NF; i += 2) // 1 a, 3 b, 5 c, | checking with +1 because of possible out of bounds
	{
		int count = atoi(is->fields[i]);
		int	ch = get_char(is->fields[i + 1]);

		for (int j = 0; j < count; j++)
			ft_putc(tmp_file, ch);
		
	}

    return (0);
}

int sil(myFILE *tmp_file, IS is)
{
	int del_count = atoi(is->fields[1]); //3
	int to_del = get_char(is->fields[2]); //a
	int found = 0;

	int len = ft_tell(tmp_file); //get the offset of file
	int left_most = len - 1; //index of the current char

	for (; left_most >= 0; left_most--)
	{
		ft_seek(tmp_file, -1, SEEK_CUR); //one char back

		if (ft_getc(tmp_file) == to_del)
			found++;
		
		ft_seek(tmp_file, -1, SEEK_CUR); //one char back cause we moved forward with getc

		if (found == del_count)
			break;
	}

	if (left_most < 0)
		left_most++;

	char *buff = get_deleted(tmp_file, to_del, len, left_most);
	
	// Rewrite the file from the correct position
    ft_seek(tmp_file, left_most, SEEK_SET);
	int curr = ft_tell(tmp_file);

    ft_puts(tmp_file, buff);
    ft_truncate(tmp_file, 0);  // delete the chracters after write //ftell
	ft_seek(tmp_file, curr, SEEK_SET); 
	free(buff);

	return (0);
	
}


int sonagit(myFILE *tmp_file, IS is)
{
	ft_seek(tmp_file, 0, SEEK_END);
    return (0);
}

int dur(myFILE *tmp_file, FILE *out_file, IS is)
{
	fputs(tmp_file->_buff, out_file);
	printf("Dosya basariyla yazdirildi!\n");
	fclose(out_file);
    return (0);
}

// if (ft_seek(tmp_file, -1, SEEK_CUR) != 0) //it returns -1 if we try to read EOF
// 			ft_err(ERR_SEEK);