#include "main.h"

void ft_err(char *str)
{
	//return;
	printf("Hata!: %s", str);
	exit(1);
}

void init(myFILE **tmp, FILE **out_file, IS *is, int argc, char **argv)
{
	char *input_file = get_input_file(argc, argv); //"giris.dat";
	char *output_file = get_output_file(argc, argv);//"cikis.dat";


	if ((*out_file = fopen(output_file, "w+")) == NULL)
		ft_err(ERR_OUT);

	if ((*is = new_inputstruct(input_file)) == NULL) //!
		ft_err(ERR_IN);
	
	*tmp = ft_open();
}

void destruct(myFILE *tmp, FILE *out_file, IS is)
{
	if (fileno(out_file) != -1)//check if closed
	{
		fputs(tmp->_buff, out_file);
		printf("Dosya basariyla yazdirildi!\n");
		fclose(out_file);
	} 
	jettison_inputstruct(is);
	ft_close(tmp);
	return;
}

//no leaks since its string literal 
char *get_input_file(int argc, char **argv)
{
	if (argc > 1)
		return (argv[1]);
	
	printf("Uyari!: giris dosyasi verilmedi \"./files/giris.dat\" kullanilacak\n");
	printf("Kullanim: ./bin/main \"giris_dosyasi\" \"cikis_dosyasi\"\n");
	return "./files/giris.dat";
}

char *get_output_file(int argc, char **argv)
{
	if (argc > 2)
		return (argv[2]);
	
	printf("Uyari!: cikis dosyasi verilmedi \"./files/cikis.dat\" kullanilacak\n");
	printf("Kullanim: ./bin/main \"giris_dosyasi\" \"cikis_dosyasi\"\n");
	return "./files/cikis.dat";
}


