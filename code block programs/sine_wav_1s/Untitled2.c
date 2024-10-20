#include<stdio.h>
#include<conio.h>

int main()
{
    long a[10];

    FILE *fp;


    fp=fopen("C:\\Adnan\\Audacity\\wav file\\original\\1k square 10ms.wav","rb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");

}
getch();
}
