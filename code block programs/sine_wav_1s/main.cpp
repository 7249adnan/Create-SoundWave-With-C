#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
//#include<iostream>
//#include<alloca.h>


void write( int tms);
long data( unsigned char h[]);
long data2( unsigned char h[]);
long power(long p);

int main()
{
long a,chunk_size,i=0,sub_chunk1_size,audio_format,num_channels,sample_rate;
long byte_rate,block_aligin,bits_per_sample,sub_chunk2_size;
long us=1,sz;

FILE *fp;

unsigned char sizes[10], id[10],fmt[20],subsize1[10],adfmt[5],numch[5],sprate[10];
unsigned char btrate[10],blaln[10],bpsmp[10],subsize2[10];



sz=(88.2*us)+36;
printf("\n \n User size :- %ld",sz);



fp=fopen("C:\\Adnan\\Audacity\\wav file\\original\\t22050.wav","rb");
//C:\Adnan\Audacity\wav file\original
if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");
     int i=0;

        while(i<46)
        {
            a=fgetc(fp);

            if(i<4)
            id[i]=a;

            if(i>3 && i<8)
            {
                sizes[i-4]=a;

            }

            if(i>7 && i<16)
            {
                fmt[i-8]=a;
                //printf("%c",fmt[i-8]);
            }

            if(i>15 && i<20)
            {
                subsize1[i-16]=a;
            }


            if(i>19 && i<22)
            {
                adfmt[i-20]=a;
            }

            if(i>21 && i<24)
                numch[i-22]=a;

            if(i>23 && i<28)
                sprate[i-24]=a;

            if(i>27 && i<32)
                btrate[i-28]=a;

            if(i>31 && i<34)
            {
                blaln[i-32]=a;

            }

            if(i>33 && i<36)
                bpsmp[i-34]=a;

            if(i>39 && i<44)
                subsize2[i-40]=a;

        i++;
    }

    int l=0,m=0;


if(id[0]=='R' && id[1]=='I' && id[2]=='F' && id[3]=='F')
{
    l++;

}

if(fmt[0]=='W' && fmt[1]=='A' && fmt[2]=='V' && fmt[3]=='E')
{
    m++;

}

if(l==0)
    printf("\n FILE is NOT RIFF ");

else if(m==0 && l==1)
printf("\n FILE is RIFF and not in WAVE FORMAT");


else if(l=1 && m==1)
{

printf("\n \n FILE is RIFF and in WAVE FORMAT \n \n  ");


chunk_size=data(sizes);
printf("\n Chunk size               :- %ld Bytes",chunk_size);


sub_chunk1_size=data(subsize1);
printf("\n Sub Chunk 1 size         :- %ld Bytes",sub_chunk1_size);


audio_format=data2(adfmt);
printf("\n Audio format             :- %ld ",audio_format);


num_channels=data2(numch);
printf("\n Number of Channels       :- %ld",num_channels);


sample_rate=data(sprate);
printf("\n Number of Sample Rate    :- %ld ",sample_rate);


byte_rate=data(btrate);
printf("\n Byte rate                :- %ld ", byte_rate);


//blaln[0]=2;
//blaln[1]=0;

    //printf("\n ----- %x",blaln[]);


block_aligin=data2(blaln);
printf("\n Block Aligin             :- %ld",block_aligin);

bits_per_sample=data2(bpsmp);
printf("\n Bits Per Sample          :- %ld",bits_per_sample);

sub_chunk2_size=data(subsize2);
printf("\n Sub Chunk 2 Size         :- %ld ",sub_chunk2_size);

}

int  *arrp ,g=0;

l=0;
i=44;



/*
arrp=(int *)malloc(sizeof(int)*chunk_size);

fseek(fp,44,SEEK_SET);

printf("\n \n %ld\n\n  ",sz);

while(g!=EOF)
{

    g=fgetc(fp);

    if((l%16)==0)
    {
        printf("\n");
    }

    printf("%d ",g);
l++;
}


*/

printf("\n \n \n ");

    fclose(fp);
}

int mills;

printf(" \n \n Enter Time in milli second :- ");
scanf("%d",&mills);

write(mills);


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



    //for(i=0;h[i]!='\0';i++);
    len=4;



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
long data2(unsigned char h[]) //172 68
{
    long i,j=0,p,l=0,sum=0;

    long n[10],f[10],len=0;



    //for(i=0;h[i]!='\0';i++);
    len=2;



    for(i=1;i>=0;i--)
    {
        n[1-i]=h[i];
    }


    for(i=0;i<2;i++)
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



void write(int tms)
{
   long i=0,p,us=1
    ,sz,n,u=0,t=0,h=0,th=0,u1=0,t1=0,h1=0,th1=0;
    unsigned char a[10];

    char c[10]={"918"};

    FILE *fp;


    sz=(88.2*tms)+36;
    n=sz;
printf("\n \n User size :- %ld",sz);



    fp=fopen("C:\\Adnan\\Audacity\\wav file\\original\\1k square 1ms5.wav","wb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");
int r,j=0;

    i=0;
    j=0;

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

    i=0;
    j=0;

    n=(88.2*tms);

    while(n>0)
    {
        r=n%16;

        if(i==0 || i==1)
        {
            if(j==0)
                u1=r;
            else
                u1=u1+r*16;
            j++;
        }

        else if(i==2 || i==3)
            {
            if(j==2)
                t1=r;
            else
                t1=t1+r*16;
            j++;
        }


        else if(i==4 || i==5)
            {
            if(j==4)
                h1=r;
            else
                h1=h1+r*16;
            j++;
        }

        else
            {
            if(j==0)
                th1=r;
            else
                th1=th1+r*16;
            j++;
        }


        i++;
        n=n/16;
    }



    fseek(fp,0,SEEK_SET);


int  da[45]={82,73,70,70,u,t,h,th,87,65,86,69,102,109,116,32,16,0,0,0,1,0,1,0,68,172,0,0,136,88,1,0,2,0,16,0,100,97,116,97,u1,t1,h1,th1};

long crest,trough,mill;

float amp,amps;

printf("\n Enter Amplitude in percent :- ");
scanf("%f",&amp);

amps=amp;

amp=amp/100.0;

printf("\n amp = %f",amp);

crest=(amp)*255*0.5;
trough=255-crest;

printf("\n \n crest=%ld trough =%ld ",crest,trough);






//    fprintf(fp,"RIFF%c%c%c%c",u,t,h,th);

i=0;
j=0;
while(i<44)
{
    fputc(da[i],fp);
    i++;
}

mill=tms;

i=1;
j=0;

while(j!=mill)
{
    if(i>=0 && i<=44)
        fputc(crest,fp);
    if(i>44 && i<=88)
        fputc(trough,fp);

       // printf("\n %ld",i);

    if(i%88==0)
    {
        j++;
        i=0;
    }
    i++;
}



    fclose(fp);




}
}

