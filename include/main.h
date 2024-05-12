#ifndef MAIN_H
#define MAIN_H

#include "fields.h" //provided by the assigment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //for ftruncate

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

int	command(char *cmd, FILE *fd, IS is);

int	yaz(FILE *out_file, IS is);
int	sil(FILE *out_file, IS is);
int	sonagit(FILE *out_file, IS is);
int	dur(FILE *out_file, IS is);


//command utils

char get_char(char *str);
char *get_deleted(FILE *out_file, char to_del, int len, int left_most);

//write utils
void	ft_putc(char c);
void	ft_puts(char *str);
void	ft_truncate();
char	ft_getc();
int		ft_tell();
int		ft_seek(int i, int flag);


//utils

void ft_err(char *str);

void init(FILE **out_file, IS *is, int argc, char **argv);
void destruct(FILE *out_file, IS is);

char *get_input_file(int argc, char **argv);
char *get_output_file(int argc, char **argv);


#endif