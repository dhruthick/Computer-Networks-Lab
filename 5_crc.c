#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char remain[50],data[500];
int dlength,glength,n,ebits;
char text[100],bin[8];
char generator[]="1101";
void crc(){
    int i,j;
    printf("Performing CRC check...\n");
    for(j=0;j<glength;j++)
        remain[j]=data[j];
    do{     //perform division
        if(remain[0]=='1')
            for(i=1;i<glength;i++)
                remain[i]=((remain[i]==generator[i])?'0':'1');    //XOR operation
        for(i=0;i<glength-1;i++)
            remain[i]=remain[i+1];
        remain[i]=data[j++];
    }while(j<=dlength+glength-1);
}

void binary(char letter){
    int i=7,d,r;
    d=(int)letter;
    while(i>=0){
        r=d%2;
        d/=2;
        bin[i--]=r+'0';
    }
    bin[8]='\0';
}

char ascii(char letter[]){
    int i=7,c=0;
    while(i>=0)
        c+=pow(2,7-i)*(letter[i--]-'0');
    return c;
}
void main(){
    printf("Enter data: ");
    fflush(stdin);  //to clear input buffer as gets() is dangerous
    gets(text);
    binary(text[0]);
    strcpy(data,bin);
    int i,j;
    for(i=1;i<strlen(text);i++){    //to convert the given string into a binary string
        binary(text[i]);
        strcat(data,bin);
    }
    //printf("Data word: ");
    //puts(data);
    printf("Enter generator in binary: ");
    gets(generator);
    glength=strlen(generator);  //n=no. of bits in generator
    dlength=strlen(data);
    for(i=dlength;i<dlength+glength-1;i++)  //to append n-1 zeros to the data to perform division
        data[i]='0';
    //printf("Padded data: %s\n",data);
    crc();
    printf("Remainder: %s\n",remain);
    for(i=dlength;i<dlength+glength-1;i++)  //append the remain obtained to the data
        data[i]=remain[i-dlength];
    //printf("Codeword: %s\n",data);
    printf("Testing error detection\nEnter the no. of error induced bits: ");
    scanf("%d",&ebits);
    srand(time(0));     //to seed rand() to obtain different random numbers on multiple execution
    for(i=0;i<ebits;i++){
        j=rand()%dlength;       //limiting the random number to less than the length of data
        data[j]=(data[j]=='0')?'1':'0';     //inducing the error
        printf("Error %d generated at %dth bit i.e %dth character\n",i+1,j+1,(j/8)+1);
    }
    crc();
    for(i=0;i<glength-1 && remain[i]=='0';i++){}    //checking if remainder is all 0's
    if(i<glength-1)
        printf("Remainder= %s Error detected\n",remain);
    else
        printf("Remainder= %s No errors\n",remain);
    for(i=0,j=0;i<dlength;i+=8){    //to convert the binary data back to a sentence
        strncpy(bin,&data[i],8);
        bin[8]='\0';
        text[j++]=ascii(bin);
    }
    printf("Received data: ");
    puts(text);
}
