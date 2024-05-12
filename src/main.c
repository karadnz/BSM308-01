#include "main.h"

int main(int argc, char **argv)
{
	FILE	*out_file;
	IS		is;

	

	init(&out_file, &is, argc, argv);

	while (get_line(is) != -1)
		command(is->fields[0], out_file, is);
	
	destruct(out_file, is);

	return (0);
}