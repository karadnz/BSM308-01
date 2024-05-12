#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for ftruncate

#include "fields.h" //provided by the assigment
#include "myio.h" //my implementation of file struct and functions from stdio.h

//macros

#define ERR_ARGS "Dosya ismi verilmedi!"
#define ERR_IN "Dosya acma hatasi(giris.dat)"
#define ERR_OUT "Dosya acma hatasi(cikis.dat)"
#define ERR_SEEK "fseek hatasi"
#define ERR_CLOSED "Kapali dosyada islem"


#define SIL "sil:"
#define YAZ "yaz:"
#define SONAGIT "sonagit:"
#define DUR "dur:"

//globals

extern int _i;
extern char *_buff;

//commands

int	command(char *cmd, FILE *out_file, IS is, myFILE *tmp_file_file);

int	yaz(myFILE *tmp_file, IS is);
int	sil(myFILE *tmp_file, IS is);
int	sonagit(myFILE *tmp_file, IS is);
int	dur(FILE *out_file, IS is);


//command utils

char get_char(char *str);
char *get_deleted(myFILE *tmp_file, char to_del, int len, int left_most);

// //write utils
// void	ft_putc(char c);
// void	ft_puts(char *str);
// void	ft_truncate();
// char	ft_getc();
// int		ft_tell();
// int		ft_seek(int i, int flag);


//utils

void ft_err(char *str);

void init(myFILE **tmp_file, FILE **out_file, IS *is, int argc, char **argv);
void destruct(myFILE *tmp_file, FILE *out_file, IS is);

char *get_input_file(int argc, char **argv);
char *get_output_file(int argc, char **argv);


#endif