#include<reg52.h> 
init(); 
lcd_init(); 
void lcd_disp(char []); 
w_d(); 
line_1(); 
line_2(); 
delay(long); 
void load_t0(); 
int kbd_scan(); 
void time(); 
sbit P1_7=P1^7; 
char xdata lcdp_at_0x01; 
char xdata lcdc_at_0x00; 
unsigned int freq=0; 
unsigned int save=0; 
int a=0; 
char bdata y; 
sbit f=y^0; 
sbit col_0=Pl^4; 
sbit col_1=P1^5; 
sbit col_2=PI^6; 
 

main() 
{
int 
i,x[4]; 
init(); 
lcd_init); 
lcd_disp("welcome"); 
line_2(); 
lcd_disp("choose: 1,2,*,#"); 
while (kbd_scan()==13) w_d(); 
while (1) 
  {
line_1(); 
lcd_disp("choose key"); 
line_2(); 
lcd_disp("for oper.."); 
while (kbd_scan()==13); 
switch(kbd_scan)) 
{ 
  case 1: 
    line_1(); 
    led_disp("frequency is:"); 
    while(f) 
      {
        EX0=0; 
        line_2(); 
        for(i-3;i>-0;i-) 
          {
            x[i]-(save%10)+0x30; 
            save=save/10: 
              }
        for(i-0;i<4;i++) 
          {
            lcdp=x(i]; 
            delay(20);
            SBUF=x[i]; 
            TI=0; 
          }
        lcd_disp("Hz");
        EX0=1; 
        delay(50000); 
        load_t0();
        f=0; 
      }
    break; 
  case 2: 
    line_1(); 
    lcd_disp("time cycle is:"); 
    line_2();
    time(); 
    delay(50000); 
    break; 
  case 10: 
    line_1(); 
    lcd_disp("YANA"); 
    line_2(); 
    lcd_disp("abizyana"); 
    delay(50000); 
    break; 
  case 12: 
    line_1(); 
    lcd_disp("ANNA"); 
    line_2(); 
    lcd_disp("BANANNA"): 
    delay(50000); 
    break; 
  default: 
    break;
}
}
}

init() 
{
SCON=0x40; 
PCON=0x0; 
TMOD=0x21; 
load_t0(); 
TH1=253; 
TL1=253; 
TR1=1; 
IT0=1; 
EX0=1; 
ET0=1; 
EA=1; 
f=0; 
}

void load_t0() 
{
TR0=0; 
TH0=0x3c; 
TL0=0xb0; 
TR0=1; 
}

lcd init() 
{ 
char code codes[4]={0x01,0x06,0x0E,0x3F}; 
char i; 
for(i-0;i<4;i++)
  {
    lcde=codes[i]; 
    delay(5000); 
  } 
} 

void lcd_disp(char h[]) 
{
char i;
for(i-0:h[i]!='\0' ;i++) 
  {
lcdp=h[i]; 
delay(20); 
}
}

w_d()
{
P1_7=0;  
P1_7=1; 
}

delay(long j) 
{
for(;j>0;j--) w_d(); 
}

int_0() interrupt 0 
{
freq=freq++;  
} 

timer_0() interrupt 1 
{
a++; 
if(a>=20) 
{
save=freg; 
freq=0; 
f=1; 
a=0; 
TR0=0; 
}
load_t0(); 
}

line_1()
{
lcdc=0x01; 
delay(5000); 
} 

line_2()
{
lcdc=0x0C0; 
delay(5000); 
}

void time() 
{
float t_cycle; 
int s[7],i,tc; 
while(f)
{
EX0=0; 
line_2(); 
t_cycle=(float)1/save*1000000; 
tc=(int)t_cycle; 
for(i=6;i>=0;i--) 
{
s[i]=(tc%10)+0x30; 
tc=tc/10; 
}
for(i=0;i<7;i++) 
{ 
lcdp=s[i]; 
delay(20); 
}
lcd_disp(" usec"); 
EX0=1; 
delay(50000); 
load_t0();
f=0; 
}
}
 
int kbd_scan() 
{
int c[]={0x0fe,0x0fd,0x0fb,0x0f7},i,key; 
w_d(); 
for(i=0,key=1;i<4;it) 
{
w_d(); 
Pl=c[i]; 
if(!col_0) break; 
key++; 
if(!col_1) break; 
key++; 
if(!col_2) break; 
key++; 
}
return(key); 
}


/* The frequency meter*/
#include<reg52.h> 
init(); 
lcd_init(); 
lcd_display(); 
w_d(); 
enter(); 
hz(); 
delay(int); 
sbit P1_7-P1^7; 
char xdata lcdp_at_0x01; 
char xdata lcdc_at_0x00; 


main() 
int x[4],i; 
init(); 
lcd_init(); 
lcd_display(); 
w_d(); 
enter(); 
while(1) 
{ 
while(!RI);  
RI=0; 
for(i=0;i<4;it+) 
{ 
x[i]=SBUF; 
lcdp=x[i]; 
delay(1); 
}
hz(); 
}
}

init() 
SCON=0x50; 
PCON=0x0; 
TMOD=0x20; 
TH1=253; 
TL1=253; 
TR1=1; 
}

lcd_init() 
{
char code codes[4]={0x01,0x03,0x07,0x0F}; 
char i; 
for(i=0;i<4;it+) 
{ 
lcde=codes[il; 
delay(1000);  
}
}

lcd_display ()
{
char code msg[]="frequency="; 
char i=0; 
} 
for(;msg[i]!='\0';i++) 
{
lcdp=msg[i]: 
delay(1); 
}
}

w_d() 
{
P1_7=0; 
P1_7=1; 
}

delay(int j)
{
w_d(); 
for(j=j*40;j>0;j--); 
}

enter() 
{
lcdc=0x0C0; 
delay(1000); 
}

hz() 
{ 
char code hertz[]=" Hz"; 
char i; 
for(i=0;hertz[i]!='\0';i++)
{
lcdp=hertz[i]; 
delay(1); 
}
}
