#include<stdio.h>
#include<string.h>
#include<ctype.h>
void caesarCipher(char*text,int k) 
{
    int i;
    char ch;
    for(i=0;text[i]!='\0';++i) 
	{
        ch=text[i];
        if(ch>='A'&&ch<='Z') 
		{
            ch=ch+k;
            if(ch>'Z') 
			{
                ch=ch-'Z'+'A'-1;
            }
            text[i]=ch;
        }
        else if(ch>='a'&&ch<='z') 
		{
            ch=ch+k;
            if(ch>'z') 
			{
                ch=ch-'z'+'a'-1;
            }
            text[i]=ch;
        }
    }
}
int main() 
{
    char text[100];
    int k;
    printf("Enter a string:");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")]='\0';
    printf("Enter shift value:");
    scanf("%d",&k);
    if(k<1||k>25) 
	{
        printf("Invalid shift value\n");
        return 1;
    }
    caesarCipher(text,k);
    printf("Encrypted string:%s\n",text);
    return 0;
}
