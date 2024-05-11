#include "main.h"

void ft_err(char *str)
{
	//return;
	printf("Hata!: %s", str);
	exit(1);
}

void init(FILE **out_file, IS *is, int argc, char **argv)
{
	char *input_file = get_input_file(argc, argv); //"giris.dat";
	char *output_file = get_output_file(argc, argv);//"cikis.dat";


	if ((*out_file = fopen(output_file, "w+")) == NULL)
		ft_err(ERR_OUT);

	if ((*is = new_inputstruct(input_file)) == NULL) //!
		ft_err(ERR_IN);
}

void destruct(FILE *out_file, IS is)
{
	if (out_file->_file != -1) //check if closed
		fclose(out_file);;
	jettison_inputstruct(is);

	return;
}

//no leaks since its string literal 
char *get_input_file(int argc, char **argv)
{
	if (argc > 1)
		return (argv[1]);
	
	printf("Uyari!: giris dosyasi verilmedi \"giris.dat\" kullanilacak\n");
	printf("Kullanim: ./bin/main giris_dosyasi cikis_dosyasi\n");
	return "giris.dat";
}

char *get_output_file(int argc, char **argv)
{
	if (argc > 2)
		return (argv[2]);
	
	printf("Uyari!: cikis dosyasi verilmedi \"cikis.dat\" kullanilacak\n");
	printf("Kullanim: ./bin/main giris_dosyasi cikis_dosyasi\n");
	return "cikis.dat";
}

