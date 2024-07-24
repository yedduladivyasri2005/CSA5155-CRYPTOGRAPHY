#include <stdio.h>
#include<string.h>
int modInverse(int a,int m) {
    a=a%m;
    int x;
    for(x=1;x<m;x++){
        if((a*x)%m==1){
            return x;
        }
    }
    return -1;
}
void decryptAffineCipher(char ciphertext[],int a,int b) {
    int a_inv=modInverse(a,26);
    if(a_inv==-1){
        printf("No modular inverse exists for a=%d\n", a);
        return;
    }
int i;
    for(i=0;ciphertext[i]!='\0';i++){
        if(ciphertext[i]>='A'&&ciphertext[i]<='Z'){
            int y=ciphertext[i]-'A';
            int x=(a_inv * (y - b + 26))%26;
            printf("%c",x+'A');
 } 
else{
            printf("%c",ciphertext[i]);
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[100];
    int x1,y1,x2,y2;
    printf("Enter the ciphertext: ");
    fgets(ciphertext,sizeof(ciphertext),stdin);
    ciphertext[strcspn(ciphertext, "\n")]='\0';
    printf("Enter x1 and y1: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%d %d", &x2, &y2);
    int a,b;
    for(a=1;a<26;a++){
        if(modInverse(a,26)==-1){
            continue;
        }
        b=(y1-a*x1)%26;
        if(b<0){
            b+=26;
        }
        int y_check=(a*x2+b)%26;
        if (y_check==y2){
            printf("Possible keys: a = %d,b = %d\n",a,b);
            printf("Decrypted message: ");
            decryptAffineCipher(ciphertext,a,b);
            break;
        }
    }
    return 0;
}
