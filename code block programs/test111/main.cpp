#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int read_data();
int square_wav(long tms,long freq,float amp,char loc[]);
int triangle_wav(long tms,long freq,float amp,char loc[]);
int sawtooth_wav(long tms,long freq,float amp,char loc[]);
int sine_wav(long tms,long freq,float amp,char loc[]);
int stero_wav(long tms,long freq,long freq_s,float amp,float amp_s,long l,long r,char loc[]);
int mono_channel();
int stero_channel();

int main()
{

mono_channel();

//stero_channel();
}


int mono_channel()
{


long i=0,p,us=1,sz,n,u=0,t=0,h=0,th=0,u1=0,t1=0,h1=0,th1=0,j=0,k=0;
unsigned char a[10];

FILE *fp;

long tms;

long crest,trough,mill,freq;

float amp,amps;


printf(" \n \n Enter Time in milli second :- ");
scanf("%ld",&tms);

printf("\n Enter Frequency in Hz :- ");
scanf("%ld",&freq);

printf("\n Enter Amplitude in percent :- ");
scanf("%f",&amp);


if(freq>0 && freq <20001 && amp>0 && amp<101 && tms>0)

{


char loc[150]={"C:\\Adnan\\Audacity\\wav file\\original\\1k square 1ms5.wav"};


    sz=(88.2*tms)+36;
    n=sz;

fp=fopen(loc,"wb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");
long r,j=0;

    i=0;
    j=0;

    while(n>0)    // 882036
    {
        r=n%16;

        if(i==0 || i==1)                  //
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

printf(" %x %x %x %x",u,t,h,th);
amps=amp;

i=0;
j=0;
while(i<44)
{
    fputc(da[i],fp);
    i++;
}


    fclose(fp);
}

int choice;
 i=1;


printf("\n\n");
printf("\n    Enter 1 for Square Wave");
printf("\n    Enter 2 for Triangular Wave");
printf("\n    Enter 3 for Sawtooth Wave");
printf("\n    Enter 4 for Sine Wave");
printf("\n    Enter 5 To Read Data In A File");

printf("\n \n  Enter Number :   ");
scanf("%ld",&choice);

if(choice==1)
{
square_wav( tms, freq, amp,loc);

}
else if(choice==2)
{
triangle_wav( tms, freq, amp,loc);

}
else if(choice==3)
{
sawtooth_wav( tms, freq, amp,loc);
}
else if(choice==4)
{
sine_wav( tms, freq, amp,loc);
}
else if(choice==5)
read_data();

else
{
    printf("\n Enter Correct number \n ");
i=0;
}

if(i==1)
    printf("\n\n  wave generated Successfully \n Open Wave File To run it \n  \n ");
else
printf("\n\n  !!! wave not generated Due to data enter Error !!!! \n \n \n ");


}

else
{
    printf("\n \n -- !!! Enter Correct Data !!! -- \n \n \n  ");
}

}


int stero_channel()
{

long i=0,p,us=1,sz,n,u=0,t=0,h=0,th=0,u1=0,t1=0,h1=0,th1=0,j=0,k=0,r=0,l=0;
unsigned char a[10];

FILE *fp;

long tms;

long crest,trough,mill,freq,freq_s;

float amp,amps,amp_s;


printf(" \n \n Enter Time in milli second :- ");
scanf("%ld",&tms);

printf("\n Enter Frequency 1 in Hz :- ");
scanf("%ld",&freq_s);

printf("\n Enter Frequency 2 in Hz :- ");
scanf("%ld",&freq);

printf("\n Enter Amplitude 1 in percent :- ");
scanf("%f",&amp_s);

printf("\n Enter Amplitude 2 in percent :- ");
scanf("%f",&amp);

printf("\n Select Wave For Left Channel :- ");
scanf("%ld",&l);

printf("\n Select Wave For right Channel :- ");
scanf("%ld",&r);

tms=tms*2;

char loc[150]={"C:\\Adnan\\Audacity\\wav file\\original\\1k square 1ms5.wav"};


    sz=(88.2*tms)+36;
    n=sz;

fp=fopen(loc,"wb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");
long r,j=0;

    i=0;
    j=0;

    while(n>0)    // 882036
    {
        r=n%16;

        if(i==0 || i==1)                  //
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


int  da[45]={82,73,70,70,u,t,h,th,87,65,86,69,102,109,116,32,16,0,0,0,1,0,2,0,68,172,0,0,136,88,1,0,2,0,16,0,100,97,116,97,u1,t1,h1,th1};

printf(" %x %x %x %x",u,t,h,th);
amps=amp;

i=0;
j=0;
while(i<44)
{
    fputc(da[i],fp);
    i++;
}


    fclose(fp);
}

int choice;
/*
printf("\n\n  Enter 1 for Square Wave");
printf("\n    Enter 2 for Triangular Wave");
printf("\n    Enter 3 for Sawtooth Wave");
printf("\n    Enter 4 for Sine Wave");
printf("\n    Enter 5 To Read Data In A File");

printf("\n \n  Enter Number :-  ");
scanf("%ld",&choice);

if(choice==1)
{
square_wav( tms, freq, amp,loc);

}
else if(choice==2)
{
triangle_wav( tms, freq, amp,loc);

}
else if(choice==3)
{
sawtooth_wav( tms, freq, amp,loc);
}
else if(choice==4)
{
sine_wav( tms, freq, amp,loc);
}
else if(choice==5)
read_data();

else
    printf("\n Enter Correct number \n \n \n");

    */


    stero_wav( tms, freq,freq_s, amp,amp_s,l,r,loc);

}


int stero_wav(long tms,long freq,long freq_s,float amp,float amp_s,long l,long r,char loc[])
{

int k=0,j=0;
float crest,trough,crest1,trough1,crest2,trough2,freq1,amps;
float crest_s,trough_s;

long i;
FILE *fp;

printf("\n %s",loc);

fp=fopen(loc,"ab");

fseek(fp,44,SEEK_SET);

amps=amp_s/100.0;                    // .90
crest_s=(amps)*255*0.5;             // 114.75
trough_s=255-crest_s;                // 140.25

amps=amp/100.0;                    // .90
crest=(amps)*255*0.5;             // 114.75
trough=255-crest;                // 140.25


i=1;



long cf=(44000/freq),tf=(88000/freq);                                          //  4    8
long cf1=(4400000/freq),tf1=(8800000/freq);                      //  440 880
long nums=tf,nums1=cf1,s,gs,cs,ts,cs1,ts1,cs2,ts2,si=1,i1=0,i2=0,i3=0,i4=0;
long iii=1,kl=1;
float ss=0,rd=0;

cf1=cf1%100;  // 40
tf1=tf1%100;  // 80
nums1=cf1;    // 40



long cf_s=(44000/freq_s),tf_s=(88000/freq_s);                                          //  4    8
long cf1_s=(4400000/freq_s),tf1_s=(8800000/freq_s);                      //  440 880
long nums_s=tf_s,nums1_s=cf1_s,s_s,gs_s,cs_s,ts_s,cs1_s,ts1_s,cs2_s,ts2_s,si_s=1,i1_s=0,i2_s=0,i3_s=0,i4_s=0;
float ss_s=0,rd_s=0;


cf1_s=cf1_s%100;  // 40
tf1_s=tf1_s%100;  // 80
nums1_s=cf1_s;    // 40


//-----------------------------------

printf("\n %ld",freq_s);

k=0;
j=0;
kl=1;
si=1;
iii=1;

tms=tms*0.1+tms;

while(j<tms)           // 10
{

k=0;

while(k<90)
{



{


if(ss_s>1)
{
ss_s=0;
s_s=1;
}
ss_s=(nums1_s*0.01)+ss_s;                     //0.4
gs_s=nums_s+ss_s+s_s;                           //8 8 9
s_s=0;


cs_s=gs_s/2;
ts_s=gs_s-cs_s;

//printf(" %ld",gs_s);


cs1_s=cs_s/2;
cs2_s=cs_s-cs1_s;

if(cs2_s%2!=0)
    cs2_s=cs2_s-1;


ts1_s=ts_s/2;
ts2_s=ts_s-ts1_s;

if(ts2_s%2!=0)
{
    ts2_s=ts2_s-1;
}


if(ss>1)
{
ss=0;
s=1;
}
ss=(nums1*0.01)+ss;                     //0.4
gs=nums+ss+s;                           //8 8 9
s=0;

cs=gs/2;
ts=gs-cs;

cs1=cs/2;
cs2=cs-cs1;

if(cs2%2!=0)
    cs2=cs2-1;


ts1=ts/2;
ts2=ts-ts1;

if(ts2%2!=0)
{
    ts2=ts2-1;
}


}

if(iii<3)
{
//printf("  %ld  ",(cs1_s+cs2_s+1));


if(kl>(ts2_s+cs1_s+cs2_s+ts1_s+1))
{
   kl=1;
}


if(l==1)
{


if(kl<=(cs1_s+cs2_s+1))                                //2     2
{

    i1=(kl*100.0)/(cs1_s+cs2_s);
   crest1=crest_s*i1*0.01;
    fputc((unsigned char)crest1,fp);


   kl=kl+1;
}


else if(kl<=(ts2_s+cs1_s+cs2_s+ts1_s+1))              // 8   2
 {


        i4=((cs1_s+cs2_s+ts1_s+ts2_s-kl)*100.0)/(ts2_s+ts1_s);
        i2=(128.0*amp_s)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        kl=kl+1;
 }

}

if(l==2)
{


if(kl<=(cs1_s+cs2_s+1))                                //2     2
{

    i1=(kl*100.0)/(cs1_s+cs2_s);

    rd=sin((180*0.01*i1)*0.0175);

   crest1=crest_s*rd*1.0;
    fputc((unsigned char)crest1,fp);

   kl=kl+1;
}


else if(kl<=(ts2_s+cs1_s+cs2_s+ts1_s+1))              // 8   2
 {
        i4=((cs1_s+cs2_s+ts1_s+ts2_s-kl)*100.0)/(ts2_s+ts1_s);
        i2=(128.0*amp_s)/100;
         rd=sin((180*0.01*i4)*0.0175);


        trough1=255-(i2*rd*1.0);

        fputc((unsigned char)trough1,fp);

        kl=kl+1;
 }


}

if(l==3)
{

if(kl>(ts2_s+cs1_s+cs2_s+ts1_s+1))
    kl=1;

if(kl<=cs1_s)                                //2     2
{

    i1=(kl*100.0)/cs1_s;
   crest1=crest_s*i1*0.01;
    fputc((unsigned char)crest1,fp);

   kl=kl+1;
}



else if(kl<= (cs2_s+cs1_s)+1 )                  // 4    2
    {
        i2=((cs2_s-kl+cs2_s+1)*100.0)/cs2_s;
        crest1=crest_s*i2*0.01;
         fputc((unsigned char)crest1,fp);

        kl=kl+1;
    }



else if(kl<=(ts1_s+cs1_s+cs2_s)-1)                  //6    2
   {
            i3=((kl-cs1_s-cs2_s+1)*100.0)/ts1_s;
            i4=(128.0*amp_s)/100;
            trough1=255-(i4*i3*0.01);




        fputc((unsigned char)trough1,fp);
            kl=kl+1;
   }

else if(kl<=(ts2_s+cs1_s+cs2_s+ts1_s+1))              // 8   2
 {
        i4=((cs1_s+cs2_s+ts1_s+ts2_s-kl)*100.0)/ts2_s;
        i2=(128.0*amp_s)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        kl=kl+1;
 }


}


if(l==4)
{


if(kl<=(cs1_s+cs2_s+1))                                //2     2
{

   crest1=crest_s;
    fputc((unsigned char)crest1,fp);
   kl=kl+1;
}


else if(kl<=(ts2_s+cs1_s+cs2_s+ts1_s+1))              // 8   2
 {

        trough1=trough_s;
        fputc((unsigned char)trough1,fp);
        kl=kl+1;
 }

}




 iii=iii+1;
}




if(iii<5 && iii>2)

{

if(si>(ts2+cs1+cs2+ts1+1))
{
    si=1;
}


if(r==1)
{


if(si<=(cs1+cs2+1))                                //2     2
{

    i1=(si*100.0)/(cs1+cs2);
   crest1=crest*i1*0.01;
    fputc((unsigned char)crest1,fp);
   si=si+1;
}


else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {


        i4=((cs1+cs2+ts1+ts2-si)*100.0)/(ts2+ts1);
        i2=(128.0*amp)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        si=si+1;
 }

}

if(r==2)
{


if(si<=(cs1+cs2+1))                                //2     2
{

    i1=(si*100.0)/(cs1+cs2);

    rd=sin((180*0.01*i1)*0.0175);

   crest1=crest*rd*1.0;
    fputc((unsigned char)crest1,fp);
   si=si+1;
}


else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {
        i4=((cs1+cs2+ts1+ts2-si)*100.0)/(ts2+ts1);
        i2=(128.0*amp)/100;
         rd=sin((180*0.01*i4)*0.0175);
        trough1=255-(i2*rd*1.0);
        fputc((unsigned char)trough1,fp);

        si=si+1;
 }


}

if(r==3)
{

if(si<=cs1)                                //2     2
{
    i1=(si*100.0)/cs1;
   crest1=crest*i1*0.01;
    fputc((unsigned char)crest1,fp);
   si=si+1;
}



else if(si<= (cs2+cs1)+1 )                  // 4    2
    {
        i2=((cs2-si+cs2+1)*100.0)/cs2;
        crest1=crest*i2*0.01;
         fputc((unsigned char)crest1,fp);

        si=si+1;
    }

else if(si<=(ts1+cs1+cs2)-1)                  //6    2
   {
            i3=((si-cs1-cs2+1)*100.0)/ts1;
            i4=(128.0*amp)/100;
            trough1=255-(i4*i3*0.01);




        fputc((unsigned char)trough1,fp);
            si=si+1;
   }

else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {
        i4=((cs1+cs2+ts1+ts2-si)*100.0)/ts2;
        i2=(128.0*amp)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        si=si+1;
 }


}


if(r==4)
{


if(si<=(cs1+cs2+1))                                //2     2
{

   crest1=crest;
    fputc((unsigned char)crest1,fp);
   si=si+1;
}


else if(si<=(ts2+cs1+cs2+ts1+1))
 {

        trough1=trough;
        fputc((unsigned char)trough1,fp);
        si=si+1;
 }

}




iii=iii+1;
}

if(iii==5)
    iii=1;





i++;
k=k+1;

}

j++;
}

    fclose(fp);

}




int square_wav(long tms,long freq,float amp,char loc[])
{

int k=0,j=0;
float crest,trough;

long i;
FILE *fp;

fp=fopen(loc,"ab");

fseek(fp,44,SEEK_SET);

amp=amp/100.0;

crest=(amp)*255*0.5;
trough=255-crest;

i=1;

long cf=(44000/freq),tf=(88000/freq);
long cf1=(4400000/freq),tf1=(8800000/freq),ll,mm,x=0,z=0;
float aa=0,bb=0,mc,mt;

cf1=cf1%100;
tf1=tf1%100;


k=0;
j=0;

{

k=0;

while(k<88*tms)
{

if(aa>1)
{
aa=0;
x=1;
}
aa=(cf1*0.019)+aa;
ll=cf+aa+x;

x=0;

if(bb>1)
{bb=0;
z=1;
}

bb=(tf1*0.019)+bb;
mm=tf+bb+z;

z=0;



    if(i>=0 && i<=ll)
        fputc((unsigned char)crest,fp);
    if(i>ll && i<=mm)
        fputc((unsigned char)trough,fp);

    if(i%mm==0)
            i=1;

i++;
k=k+1;

}

j++;
}


    fclose(fp);

}


int triangle_wav(long tms,long freq,float amp,char loc[])
{

int k=0,j=0;
float crest,trough,crest1,trough1,crest2,trough2,freq1;

long i;
FILE *fp;

fp=fopen(loc,"ab");

fseek(fp,44,SEEK_SET);
trough2=amp;
amp=amp/100.0;                    // .90

crest=(amp)*255*0.5;             // 114.75
trough=255-crest;                // 140.25

i=1;

freq1=freq;

long cf=(44000/freq1),tf=(88000/freq1);                                          //  4    8
long cf1=(4400000/freq1),tf1=(8800000/freq1),ll,mm,x=0,z=0;                      //  440 880
long nums=tf,nums1=cf1,s,gs,cs,ts,cs1,ts1,cs2,ts2,si=1,i1=0,i2=0,i3=0,i4=0,ii=1;
long si1=1,o1=0,o2=0,o3=0,o4=0,iii;

float aa=0,bb=0,mc,mt,ss=0;

cf1=cf1%100;  // 40
tf1=tf1%100;  // 80

nums1=cf1;    // 40



printf("\n -- %f",k);

k=0;
j=0;

tms=tms*0.1+tms;



while(j<tms)           // 10
{

k=0;

while(k<90)
{

if(ss>1)
{
ss=0;
s=1;
}
ss=(nums1*0.01)+ss;                     //0.4
gs=nums+ss+s;                           //8 8 9
s=0;

cs=gs/2;
ts=gs-cs;

cs1=cs/2;
cs2=cs-cs1;

if(cs2%2!=0)
    cs2=cs2-1;


ts1=ts/2;
ts2=ts-ts1;

if(ts2%2!=0)
{
    ts2=ts2-1;
}

if(si<=cs1)                                //2     2
{

    i1=(si*100.0)/cs1;
   crest1=crest*i1*0.01;
    fputc((unsigned char)crest1,fp);

   si=si+1;
}



else if(si<= (cs2+cs1)+1 )                  // 4    2
    {
        i2=((cs2-si+cs2+1)*100.0)/cs2;
        crest1=crest*i2*0.01;
         fputc((unsigned char)crest1,fp);

        si=si+1;
    }



else if(si<=(ts1+cs1+cs2)-1)                  //6    2
   {
            i3=((si-cs1-cs2+1)*100.0)/ts1;
            i4=(128.0*trough2)/100;
            trough1=255-(i4*i3*0.01);




        fputc((unsigned char)trough1,fp);
            si=si+1;
   }

else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {
        i4=((cs1+cs2+ts1+ts2-si)*100.0)/ts2;
        i2=(128.0*trough2)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        si=si+1;
 }

else
{


    si=1;
}


i++;
k=k+1;

}

j++;
}

    fclose(fp);

}


int sawtooth_wav(long tms,long freq,float amp,char loc[])
{

int k=0,j=0;
float crest,trough,crest1,trough1,crest2,trough2,freq1;

long i;
FILE *fp;

fp=fopen(loc,"ab");

fseek(fp,44,SEEK_SET);
trough2=amp;
amp=amp/100.0;                    // .90

crest=(amp)*255*0.5;             // 114.75
trough=255-crest;                // 140.25


i=1;

freq1=freq;

long cf=(44000/freq1),tf=(88000/freq1);                                          //  4    8
long cf1=(4400000/freq1),tf1=(8800000/freq1),ll,mm,x=0,z=0;                      //  440 880
long nums=tf,nums1=cf1,s,gs,cs,ts,cs1,ts1,cs2,ts2,si=1,i1=0,i2=0,i3=0,i4=0,ii=1;
long si1=1,o1=0,o2=0,o3=0,o4=0,iii;

float aa=0,bb=0,mc,mt,ss=0;

cf1=cf1%100;  // 40
tf1=tf1%100;  // 80

nums1=cf1;    // 40

k=0;
j=0;

tms=tms*0.1+tms;

while(j<tms)
{

k=0;

while(k<90)
{

if(ss>1)
{
ss=0;
s=1;
}
ss=(nums1*0.01)+ss;                     //0.4
gs=nums+ss+s;                           //8 8 9
s=0;

cs=gs/2;
ts=gs-cs;

cs1=cs/2;
cs2=cs-cs1;

if(cs2%2!=0)
    cs2=cs2-1;

ts1=ts/2;
ts2=ts-ts1;

if(ts2%2!=0)
{
    ts2=ts2-1;
}

if(si<=(cs1+cs2+1))                                //2     2
{

    i1=(si*100.0)/(cs1+cs2);
   crest1=crest*i1*0.01;
    fputc((unsigned char)crest1,fp);

   si=si+1;
}

else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {
        i4=((cs1+cs2+ts1+ts2-si)*100.0)/(ts2+ts1);
        i2=(128.0*trough2)/100;

        trough1=255-(i2*i4*0.01);

        fputc((unsigned char)trough1,fp);

        si=si+1;
 }

else
{


    si=1;
}


i++;
k=k+1;

}

j++;
}

    fclose(fp);

}


int sine_wav(long tms,long freq,float amp,char loc[])
{

int k=0,j=0;
float crest,trough,crest1,trough1,crest2,trough2,freq1;

long i;
FILE *fp;

printf("\n %s",loc);

fp=fopen(loc,"ab");

fseek(fp,44,SEEK_SET);
trough2=amp;
amp=amp/100.0;                    // .90

crest=(amp)*255*0.5;             // 114.75
trough=255-crest;                // 140.25


i=1;

freq1=freq;

long cf=(44000/freq1),tf=(88000/freq1);                                          //  4    8
long cf1=(4400000/freq1),tf1=(8800000/freq1),ll,mm,x=0,z=0;                      //  440 880
long nums=tf,nums1=cf1,s,gs,cs,ts,cs1,ts1,cs2,ts2,si=1,i1=0,i2=0,i3=0,i4=0,ii=1;
long si1=1,o1=0,o2=0,o3=0,o4=0,iii;

float aa=0,bb=0,mc,mt,ss=0,rd,tt;

cf1=cf1%100;  // 40
tf1=tf1%100;  // 80

nums1=cf1;    // 40

printf("\n -- %f",k);

k=0;
j=0;

tms=tms*0.1+tms;

while(j<tms)           // 10
{

k=0;

while(k<90)
{

if(ss>1)
{
ss=0;
s=1;
}
ss=(nums1*0.01)+ss;                     //0.4
gs=nums+ss+s;                           //8 8 9
s=0;

cs=gs/2;
ts=gs-cs;

cs1=cs/2;
cs2=cs-cs1;

if(cs2%2!=0)
    cs2=cs2-1;


ts1=ts/2;
ts2=ts-ts1;

if(ts2%2!=0)
{
    ts2=ts2-1;
}


if(si<=(cs1+cs2+1))                                //2     2
{

    i1=(si*100.0)/(cs1+cs2);

    rd=sin((180*0.01*i1)*0.0175);

   crest1=crest*rd*1.0;
    fputc((unsigned char)crest1,fp);

   si=si+1;
}


else if(si<=(ts2+cs1+cs2+ts1+1))              // 8   2
 {
        i4=((cs1+cs2+ts1+ts2-si)*100.0)/(ts2+ts1);
        i2=(128.0*trough2)/100;
         rd=sin((180*0.01*i4)*0.0175);


        trough1=255-(i2*rd*1.0);

        fputc((unsigned char)trough1,fp);

        si=si+1;
 }

else
{
    si=1;
}

i++;
k=k+1;

}

j++;
}

    fclose(fp);

}


int read_data()
{

int  *arrp ,g=0,l,i;

l=0;
i=44;

FILE *fp;


    fp=fopen("C:\\Adnan\\Audacity\\wav file\\original\\1k square 1ms5.wav","rb");

if(fp==NULL)
    printf("\n FILE CAN'T OPEN ERROR ");

else{

    printf("\n FILE OPEN SUCCESFULLY ");


fseek(fp,44,SEEK_SET);

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

    fclose(fp);
}

return 0;

}



