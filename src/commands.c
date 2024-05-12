#include "main.h"

int command(char *cmd, FILE *out_file, IS is, myFILE *tmp_file) //const cmd maybe
{
    //char *args = strdup(strchr(is->text1, ':'));
    //printf("cmd: %s \t\targ: %s", cmd, args);

	if (out_file->_file == -1) //check if closed
		ft_err(ERR_CLOSED);

    if (!strcmp(cmd, YAZ))
		return yaz(tmp_file, is);
        
    if (!strcmp(cmd, SIL))
        return sil(tmp_file, is);

    if (!strcmp(cmd, SONAGIT))
        return sonagit(tmp_file, is);

    if (!strcmp(cmd, DUR))
        return dur(out_file, is);
	
	return 0;
}

int yaz(myFILE *tmp_file, IS is)
{
	// OUT OF BOUNDS for i
	for (int i = 1; i + 1 < is->NF; i += 2)
	{
		int count = atoi(is->fields[i]);

		for (int j = 0; j < count; j++)
		{
			char ch = get_char(is->fields[i + 1]);
			//printf("TO WRITE:\t%c will be written on:\t%d\n", ch, ft_tell(tmp_file));
			//fprintf(out_file, "%c", ch);
			ft_putc(tmp_file, ch);
			//printf("WRITTEN:\t%c is written on:\t%d\n", ch, ftell(out_file));
			
		}
		
	}

    return 0;
}

int sil(myFILE *tmp_file, IS is)
{
	int del_count = atoi(is->fields[1]); //3
	int to_del = get_char(is->fields[2]); //a
	int found = 0;

	int len = ft_tell(tmp_file); //get the len of the file (len of current pos)
	int left_most = len - 1; //index of the current char

	for (; left_most >= 0; left_most--)
	{
		//one char back
		//printf("curr: %d\n", ft_tell(tmp_file));
		if (ft_seek(tmp_file, -1, SEEK_CUR) != 0) //it returns -1 if we try to read EOF
			ft_err(ERR_SEEK);

		//printf("curr: %d\n", ft_tell(tmp_file));
		char c = ft_getc(tmp_file);
		if (c == to_del)
			found++;
		
		//one char back cause we moved forward with getc
		if (ft_seek(tmp_file, -1, SEEK_CUR) != 0)
			ft_err(ERR_SEEK);
		//printf("curr: %d, leftmost: %d char: %c\n", ft_tell(tmp_file), left_most, c);
		//printf("DEL curr: %d, leftmost: %d char: %c\n", ftell(out_file), left_most, c);
		if (found == del_count)
			break;
	}
	if (left_most < 0)
		left_most++;
	char *buff = get_deleted(tmp_file, to_del, len, left_most);
	
	ft_seek(tmp_file, 0, SEEK_SET);
	char c = ft_getc(tmp_file); 
	//printf("END curr: %d, leftmost: %d char: %c\n", ft_tell(tmp_file), left_most, c);

	// Rewrite the file from the correct position
    ft_seek(tmp_file, left_most, SEEK_SET);
	int curr = ft_tell(tmp_file);
	//printf("curr: %d, buff: %s\n", curr, buff);
    ft_puts(tmp_file, buff);
    ft_truncate(tmp_file, 0);  // delete the chracters after write //ftell
	ft_seek(tmp_file, curr, SEEK_SET); // nerde kalmasi hakkinda
	//printf("recurr: %d\n", ft_tell(tmp_file));
	free(buff);

	return 0;
	
}


int sonagit(myFILE *tmp_file, IS is)
{
	ft_seek(tmp_file, 0, SEEK_END);
    return 0;
}

int dur(FILE *out_file, IS is)
{
	//fputs(_buff, out_file);
	//printf("BUFF:\t%s",_buff);
	//fclose(out_file);
    return 0;
}