
#include "main.h"

int command(char *cmd, char *str, FILE *out_file, IS is)
{
    char *args = strdup(strchr(str, ':'));
    printf("cmd: %s \t\targ: %s", cmd, args);

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
	for (int i = 1; i < is->NF; i+=2)
	{
		int count = atoi(is->fields[i]);

		for (int j = 0; j < count; j++)
		{
			//possible out of bounds
			//%s couse of \b \t etc.
			fprintf(out_file,"%s",is->fields[i + 1]);
		}
		
	}

    return 0;
}

//fix \n
int sil(FILE *out_file, IS is)
{
	int del_count = atoi(is->fields[1]); //3
	int to_del = is->fields[2][0]; //a

	int len = ftell(out_file); //problem on consecutive sil call

	int found = 0;
	int left_most = len - 1;

	for (; left_most > 0; left_most--)
	{
		if (fseek(out_file, -1, SEEK_CUR) != 0) //make it curr
			ft_err(ERR_SEEK);
		
		int curr = ftell(out_file);
		char c = getc(out_file);
		if (c == to_del)
			found++;

		if (fseek(out_file, -1, SEEK_CUR) != 0) //make it curr
			ft_err(ERR_SEEK);
		
		if (found == del_count)
			break;
	}

	//fseek(out_file, 0, SEEK_END);
	char *buff = (char *)malloc(sizeof(char) * ( len -  left_most + 1));
	char c;

	buff[len -  left_most] = '\0';
	while((c = getc(out_file)) != EOF)
	{
		if (c == to_del)
			continue;
		char ch[2];
		ch[0] = c;
		ch[1] = '\0';
		strcat(buff,ch);
	}

	//int offset = (len - (left_most));
	//fseek(out_file, -offset, SEEK_END);
	//int curr = ftell(out_file);
	//fprintf(out_file, "%s", buff);
	
	//ftruncate(fileno(out_file), len - found);
	//fseek(out_file, curr, SEEK_SET);

	
	// Rewrite the file from the correct position
    fseek(out_file, left_most, SEEK_SET);
	int curr = ftell(out_file);
	printf("curr: %d\n", curr);
    fputs(buff, out_file);
    ftruncate(fileno(out_file), ftell(out_file));  // delete the chracters after write
	fseek(out_file, curr, SEEK_SET);


	return 0;
	
}


int sonagit(FILE *out_file, IS is)
{
	fseek(out_file, 0, SEEK_END);
 
    // Printing position of pointer
    //printf("%ld", ftell(out_file));
    return 0;
}

int dur(FILE *fd, IS is)
{
	fclose(fd); //assumes nothing will be called after
    return 0;
}