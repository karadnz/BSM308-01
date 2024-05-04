#ifndef MAIN_H
#define MAIN_H

#include "fields.h" //provided by the assigment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for ftruncate

//macros

#define ERR_ARGS "Dosya isimi verilmedi!"
#define ERR_IN "Dosya acma hatasi(giris.dat)"
#define ERR_OUT "Dosya acma hatasi(cikis.dat)"
#define ERR_SEEK "fseek hatasi"


#define SIL "sil:"
#define YAZ "yaz:"
#define SONAGIT "sonagit:"
#define DUR "dur:"


//commands
int	command(char *cmd, FILE *fd, IS is);

int	yaz(FILE *out_file, IS is);
int	sil(FILE *out_file, IS is);
int	sonagit(FILE *out_file, IS is);
int	dur(FILE *out_file, IS is);

//command utils
char get_char(char *str);
char *get_deleted(FILE *out_file, char to_del, int len, int left_most);

//utils
void ft_err(char *str);


#endif