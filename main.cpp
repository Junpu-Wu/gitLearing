#include <stdio.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int countc(char *file)
{   
	int cchar = 0;
	FILE *f;
    f = fopen(file, "r");
    char a;
    if(NULL==(f=fopen(file,"r")))
    {
        printf("file is NULL");
        return 0;
    }
    else
    while (!feof(f)) { 
	a=fgetc(f);
	if (a != ' '&&a != '\n'&&a != '\t') cchar++;
	} 
	fclose(f);
	printf("字符数量:%d ",cchar); 
	return 0;
}

int countw(char *file)//???????? 
{   
	int word_num = 0;
	int single_word = 0;
	FILE *f;
    f=fopen(file,"r");
    char ch;
    if(NULL==(f=fopen(file,"r"))){
     printf("file is NULL");
    }
    else
    while(!feof(f)) { 
		ch=fgetc(f);
		if((ch >= 'a'&&ch <= 'z')||(ch>='A'&&ch<='Z')||ch=='_') single_word=1;
		else if (single_word) { 
		word_num++; single_word=0; 
		} 
	} 
	fclose(f); 
	printf("单词数量:%d ",word_num); 
	return 0;
}

int main(int argc, char* argv[])             
{
    FILE *fp;
        if((fp=fopen(argv[2],"r"))==NULL){  
        printf("FileNull\n\n\n");
        return 0;
		} 
		else if(strcmp(argv[1],"-w")==0) countw(argv[2]); 
		else if(strcmp(argv[1],"-c")==0) countc(argv[2]); 
		else printf("NullPoint\n"); 
		return 0; 
}


