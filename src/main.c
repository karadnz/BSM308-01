
#include "main.h"

void ft_err(char *str)
{
	//return;
	printf("Hata!: %s", str);
	exit(1);
}

void init(FILE **out_file, IS *is, int argc, char **argv)
{
	char *input_file = "giris.dat";
	char *output_file = "cikis.dat";

	if (argc != 2)
		ft_err(ERR_ARGS);

	if ((*out_file = fopen(output_file, "w+")) == NULL)
		ft_err(ERR_OUT);

	if ((*is = new_inputstruct(input_file)) == NULL) //!
		ft_err(ERR_IN);
}

void destruct(FILE *out_file, IS is)
{
	//check fclose and close if not
	jettison_inputstruct(is);

	return;
}

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