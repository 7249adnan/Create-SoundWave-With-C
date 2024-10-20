#include<stdio.h>
#include<conio.h>

long data(unsigned char h[]);


int main()
{
    long i=0,p,us=1500
    ,sz,n,u=0,t=0,h=0,th=0;
    unsigned char a[10];

    char c[10]={"918"};

    FILE *fp;


    sz=(88.2*us)+36;
    n=sz;
printf("\n \n User size :- %ld",sz);



    fp=fopen("C:\\Adnan\\Audacity\\wav file\\original\\test1.wav","wb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");
int r,j=0;

    i=0;

    while(n>0)
    {
        r=n%16;

        if(i==0 || i==1)
        {
            if(j==0)
                u=r;
            else
                u=u+r*16;
            j++;
        }

        else if(i==2 || i==3)
            {
            if(j==2)
                t=r;
            else
                t=t+r*16;
            j++;
        }


        else if(i==4 || i==5)
            {
            if(j==4)
                h=r;
            else
                h=h+r*16;
            j++;
        }

        else
            {
            if(j==0)
                th=r;
            else
                th=th+r*16;
            j++;
        }


        i++;
        n=n/16;
    }



    fseek(fp,0,SEEK_SET);
    fprintf(fp,"RIFF%c%c%c%c",u,t,h,th);





    fclose(fp);




}
getch();
}

long power(long p)
{
    long i,sum=1;

    if(p==0)
        return 1;
    else
    {
    for(i=1;i<=p;i++)
    {
        sum=sum*256;
    }

    }
    return sum;
}

long data(unsigned char h[]) //172 68
{
    long i,j=0,p,l=0,sum=0;

    long n[10],f[10],len=0;



    for(i=0;i<4;i++);
    len=i;



    for(i=3;i>=0;i--)
    {
        n[3-i]=h[i];
    }


    for(i=0;i<4;i++)
    {
     if(n[i]==0  && n[i+1]!=0)
        {
            l=i+1;
            break;
        }

    }
    len=len-l;

    for(i=0;i<len;i++)
    {
        f[i]=n[i+l];
    }


for(i=0;i<len;i++)
{
p=power(len-i-1);

sum=sum+f[i]*p;


}


return sum;
}
