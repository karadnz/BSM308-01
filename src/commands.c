#include "main.h"

int command(char *cmd, FILE *out_file, IS is) //const cmd maybe
{
    //char *args = strdup(strchr(is->text1, ':'));
    //printf("cmd: %s \t\targ: %s", cmd, args);

    if (!strcmp(cmd, YAZ))
		return yaz(out_file, is);
        
    if (!strcmp(cmd, SIL))
        return sil(out_file, is);

    if (!strcmp(cmd, SONAGIT))
        return sonagit(out_file, is);

    if (!strcmp(cmd, DUR))
        return dur(out_file, is);
}

int yaz(FILE *out_file, IS is)
{
	//add check for uneven args // possible out of bounds
	for (int i = 1; i < is->NF; i += 2)
	{
		int count = atoi(is->fields[i]);

		for (int j = 0; j < count; j++)
		{
			char ch = get_char(is->fields[i + 1]);
			fprintf(out_file, "%c", ch);
		}
		
	}

    return 0;
}

//fix \n
int sil(FILE *out_file, IS is)
{
	int del_count = atoi(is->fields[1]); //3
	int to_del = is->fields[2][0]; //a
	int found = 0;

	int len = ftell(out_file); //get the len of the file (len of current pos)
	int left_most = len - 1; //index of the current char

	for (; left_most > 0; left_most--)
	{
		//one char back
		if (fseek(out_file, -1, SEEK_CUR) != 0)
			ft_err(ERR_SEEK);
		
		if (getc(out_file) == to_del)
			found++;

		//one char back cause we moved forward with getc
		if (fseek(out_file, -1, SEEK_CUR) != 0)
			ft_err(ERR_SEEK);
		
		if (found == del_count)
			break;
	}

	char *buff = get_deleted(out_file, to_del, len, left_most);
	
	// Rewrite the file from the correct position
    fseek(out_file, left_most, SEEK_SET);
	int curr = ftell(out_file);
	printf("curr: %d\n", curr);
    fputs(buff, out_file);
    ftruncate(fileno(out_file), ftell(out_file));  // delete the chracters after write
	fseek(out_file, curr, SEEK_SET); // nerde kalmasi hakkinda

	free(buff);

	return 0;
	
}


int sonagit(FILE *out_file, IS is)
{
	fseek(out_file, 0, SEEK_END);
    //printf("%ld", ftell(out_file));
    return 0;
}

int dur(FILE *fd, IS is)
{
	fclose(fd); //assumes nothing will be called after
    return 0;
}