#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>

void display();
void complete();
void newgame();
void loadgame();
void instructions();
void gexit();
void level1(int score);
void level2(int score);
void level3(int score);
void word(char g[],char k[],char clue[]);
int menu(int pr);
void complete();
void scram()
{ cout<<setw(36);
  cout<<"S";
  delay(200);
  cout<<"C";
  delay(200);
  cout<<"R";
  delay(200);
  cout<<"A";
  delay(200);
  cout<<"M";
  delay(200);
  cout<<"B";
  delay(200);
  cout<<"L";
  delay(200);
  cout<<"E";
  delay(200);
  cout<<"R";
  delay(1000);
}
class rec
{ char name[50], rank[20];
  int stat;
  public:
  void enter();
  void calc(int a);
  int cmp(char a[],int i);
  int showscore();
  void display();
};
void rec:: enter()
{ cout<<"\nEnter your gaming name : ";
  gets(name);
}
void rec:: calc(int a)
{ stat=a;
  if(stat>=1 && stat<3)
  strcpy(rank,"Beginner");
  else if(stat>=3 && stat<6)
  strcpy(rank,"Blazer");
  else
  strcpy(rank,"Veteran");
}
int rec :: cmp(char a[],int i)
{ if(i==0)
  { if(strcmp(a,name)==0)
    return 0;
    else
    return 1;
  }
}
int rec :: showscore()
{
  return stat;
}
void rec:: display()
{ clrscr();
  gotoxy(35,1);
  cout<<"Player details : ";
  cout<<"\n\n\nName : ";
  puts(name);
  cout<<"\n\nRank : ";
  puts(rank);
}
rec p;
void intro()
{ clrscr();
  int ch;
  gotoxy(19,1);
  cout<<"Welcome to the ultimate code breaker program\n\n\n";
  scram();
  cout<<"\n\n\n\nHere is a list of the options you can select : \n\n";
  gotoxy(35,11);
  cout<<"1. New Game\n"<<setw(47)<<"2. Load Game\n"<<setw(50)<<"3. Instructions\n"<<setw(48)<<"4. Exit";
  cout<<"\n\nEnter the correct serial number of the option you want to perform : ";
  a:
  cin>>ch;
  switch(ch)
  {
   case 1 : newgame();
	    break;
   case 2 : loadgame();
	    break;
   case 3 : instructions();
	    break;
   case 4 : gexit();
	    break;
   default : cout<<"Enter correctly : ";
	     goto a;

  }
}
void newgame()
{ char c;
clrscr();
cout<<"\n\nAre you ready to be stunned by the spell of codes of scrambler? Do you wish to continue? (Y/N) (Press enter after typing your choice) : ";
b:
cin>>c;
if(c=='y'||c=='Y')
{ clrscr();
gotoxy(40,1);
cout<<"ALIAS";
cout<<"\nThe game requires an alias to be created.";
p.enter();
clrscr();
level1(1);
}
else if(c=='n'||c=='N')
gexit();
else
{
cout<<"\n\nPlease enter a valid choice : ";
goto b;
}
}
void loadgame()
{
clrscr();
int i, f=0, ret,score=1,ch;
char name[50],an;
gotoxy(35,1);
cout<<"Load Game\n\n\n\n";
cout<<"Load game using your gaming name ";
clrscr();
m:
cout<<"\n\nEnter name : ";
gets(name);
fstream fo;
fo.open("record.txt",ios::in);
while(!fo.eof())
{ fo.read((char*)& p,sizeof(p));
ret=p.cmp(name,0);
if(ret==0)
{p.display();
 f=1;
 break;
}
}
fo.close();
if(f==0)
{ cout<<"\n\nRecord not found!";
  cout<<"\nWant to try again?(y/n) : ";
  cin>>an;
  if(an=='y'||an=='Y')
  goto m;
  else
  { cout<<"\n\n\n\nHere is a list of the options you can select : \n\n";
  gotoxy(35,11);
  cout<<"1. New Game\n"<<setw(50)<<"2. Instructions\n"<<setw(48)<<"3. Exit";
  cout<<"\n\nEnter the correct serial number of the option you want to perform : ";
  a:
  cin>>ch;
  switch(ch)
  {
   case 1 : newgame();
	    break;
   case 2 : instructions();
	    break;
   case 3 : gexit();
	    break;
   default : cout<<"Enter correctly : ";
	     goto a;

  }
  }
  getch();
}
else
{ cout<<"Press enter to continue.....";
getch();
score=p.showscore();
if(score>=1 && score<=3)
level1(++score);
else if(score>3 && score<7)
level2(++score);
else
level3(++score);
}
}
void instructions()
{ clrscr();
int ch;
gotoxy(35,1);
cout<<"INSTRUCTIONS\n\n\n\n";
delay(1100);
cout<<"1. The game involves guessing an unknown code with the help of clues.\n\n";
delay(2800);
cout<<"2. There are 3 levels in the game, each containing 3 codes.\n\n";
delay(2400);
cout<<"3. You will be provided with a certain number of lifes for each code.\n\n";
delay(2800);
cout<<"4. Each incorrect guess will cost you 1 life.\n\n";
delay(1800);
cout<<"5. To make a guess,type the required position. Press enter then type the guessed letter.\n\n";
delay(3200);
cout<<"6. Each level consist of seven lifes for each word.\n\n";
delay(2000);
cout<<"7. You will be given only 1 code at a time.\n\n\n\n";
delay(3000);
cout<<"Press enter to continue....";
getch();
clrscr();
cout<<"\n\n\n\nHere is a list of the options you can select : \n\n";
gotoxy(35,11);
cout<<"1. New Game\n"<<setw(47)<<"2. Load Game\n"<<setw(48)<<"3. Exit";
cout<<"\n\nEnter the correct serial number of the option you want to perform : ";
  t:
  cin>>ch;
  switch(ch)
  {
   case 1 : newgame();
	    break;
   case 2 : loadgame();
	    break;
   case 3 : gexit();
	    break;
   default : cout<<"Enter correctly : ";
	     goto t;

  }
}
void gexit()
{ clrscr();
gotoxy(35,12);
cout<<"THANK";
delay(500);
cout<<"\tYOU";
delay(1300);
clrscr();
gotoxy(35,5);
cout<<"PROGRAMMERS";
delay(700);
gotoxy(20,12);
cout<<"Concept and Framework : ";
delay(500);
cout<<"ISH TAKKAR";
delay(1000);
gotoxy(20,14);
cout<<"Design and Data : ";
delay(500);
cout<<"ARNAV BATRA";
delay(2000);
clrscr();
gotoxy(35,12);
cout<<"Special Thanks To ";
delay(1000);
gotoxy(37,15);
cout<<"MUKTA AMBA";
delay(2500);
exit(0);
}
void level1(int score)
{ clrscr();
int c=0,j=score,ret=0;
char g[20],k[20],clue[100],ch, r;
clrscr();
gotoxy(33,12);
cout<<"LEVEL ";
delay(1000);
cout<<"1  ";
delay(1000);
cout<<"BEGINS";
delay(2000);
clrscr();
while(j<4)
{ randomize();
int num=7;
c=random(num)+1;
switch(c)
{ case 1 : strcpy(g,"cash");
	   strcpy(k,"_a__");
	   strcpy(clue, "Money which is immediately available.");
	   break;
  case 2 : strcpy(g,"code");
	   strcpy(k,"_o_e");
	   strcpy(clue, "Any system of sign or symbols that has a meaning.");
	   break;
  case 3 : strcpy(g,"menu");
	   strcpy(k,"_e_u");
	   strcpy(clue, "A list of choices");
	   break;
  case 4 : strcpy(g,"help");
	   strcpy(k,"_e__");
	   strcpy(clue, "Doing this for people makes it easier for them to do something.");
	   break;
  case 5 : strcpy(g,"king");
	   strcpy(k,"_i__");
	   strcpy(clue, "The most important member of the royal family of his country");
	   break;
  case 6 : strcpy(g,"test");
	   strcpy(k,"_e__");
	   strcpy(clue, "A deliberate action or experiment to find out how well something will work.");
	   break;
  case 7 : strcpy(g,"hell");
	   strcpy(k,"_e__");
	   strcpy(clue, "A noun used as a description of a place that is extremely unpleasant.");
	   break;
  default : cout<<"\n\nBah!";
	    break;
}
word(g,k,clue);
ret=menu(j);
if(ret==0)
{j++;
continue;
}
else
gexit();
j++;
} //End of while loop
clrscr();
gotoxy(35,12);
cout<<"Level 1 Cracked!";
delay(1000);
level2(j);
}
void level2(int score)
{ clrscr();
int c=0,j=score,ret=0;
char g[20],k[20],clue[100],ch, r;
clrscr();
gotoxy(33,12);
cout<<"LEVEL ";
delay(200);
cout<<"2  ";
delay(100);
cout<<"BEGINS";
delay(200);
clrscr();
while(j<7)
{ randomize();
int num=7;
c=random(num)+1;
switch(c)
{ case 1 : strcpy(g,"abandon");
	   strcpy(k,"a_a__o_");
	   strcpy(clue, "Stop doing an activity or piece of work before it is finished.");
	   break;
  case 2 : strcpy(g,"avenger");
	   strcpy(k,"a_e__e_");
	   strcpy(clue, "The one who punishes the person responsible for a wrong or harmful act.");
	   break;
  case 3 : strcpy(g,"ayurveda");
	   strcpy(k,"a_u__e_a");
	   strcpy(clue, "An ancient medical science.");
	   break;
  case 4 : strcpy(g,"bacteria");
	   strcpy(k,"_a__e_ia");
	   strcpy(clue, "Causative agent for curding of milk.");
	   break;
  case 5 : strcpy(g,"squash");
	   strcpy(k,"__ua__");
	   strcpy(clue, "A game played with a raquet and a ball.");
	   break;
  case 6 : strcpy(g,"baffle");
	   strcpy(k,"_a___e");
	   strcpy(clue, "If something does this to you, you cannot understand or explain it.");
	   break;
  case 7 : strcpy(g,"bakelite");
	   strcpy(k,"_a_e_i_e");
	   strcpy(clue, "A polymer made from the condensation of benzene and formaldehyde.");
	   break;
  default : cout<<"\n\nBah!";
	    break;
}
word(g,k,clue);
ret=menu(j);
if(ret==0)
{j++;
continue;
}
else
gexit();
j++;
} //End of while loop
clrscr();
gotoxy(35,12);
cout<<"Level 2 Cracked!";
delay(1000);
level3(j);
}
void level3(int score)
{ clrscr();
int c=0,j=score,ret=0;
char g[20],k[20],clue[100],ch, r;
clrscr();
gotoxy(33,12);
cout<<"LEVEL ";
delay(200);
cout<<"3  ";
delay(100);
cout<<"BEGINS";
delay(200);
clrscr();
while(j<10)
{ randomize();
int num=7;
c=random(num)+1;
switch(c)
{ case 1 : strcpy(g,"alchemist");
	   strcpy(k,"a___e_i__");
	   strcpy(clue, "A person who transforms or creates something through a seemingly magical process.");
	   break;
  case 2 : strcpy(g,"awestruck");
	   strcpy(k,"a_e___u__");
	   strcpy(clue, "Having or showing a feeling of mixed reverence and respect and wonder and dread.");
	   break;
  case 3 : strcpy(g,"heartache");
	   strcpy(k,"_ea__a__e");
	   strcpy(clue, "Worry or grief");
	   break;
  case 4 : strcpy(g,"gendarme");
	   strcpy(k,"_e__a__e");
	   strcpy(clue, "A police officer in french speaking countries.");
	   break;
  case 5 : strcpy(g,"dermatology");
	   strcpy(k,"_e__a_o_o__");
	   strcpy(clue, "The branch of medicines concerned with skin disorders.");
	   break;
  case 6 : strcpy(g,"backtrack");
	   strcpy(k,"_a____a__");
	   strcpy(clue, "Retrace your steps.");
	   break;
  case 7 : strcpy(g,"aerodrome");
	   strcpy(k,"ae_o__o_e");
	   strcpy(clue, "A small airport or airfield.");
	   break;
  default : cout<<"\n\nBah!";
	    break;
}
word(g,k,clue);
ret=menu(j);
if(ret==0)
{j++;
continue;
}
else
gexit();
j++;
} //End of while loop
clrscr();
gotoxy(35,12);
cout<<"Level 3 Cracked!";
delay(1000);
complete();
}
void word(char g[],char k[],char clue[])
{ char a,pos;
int l=6, f=8, count=0, s,i;
clrscr();
cout<<"The code to be unlocked is : ";
gotoxy(38,4);
puts(k);
cout<<"The clues for code is : ";
puts(clue);
while(f!=0)
{ count=0;
  for(int i=0;k[i]!='\0';++i)
  { if(k[i]=='_')
    count++;
  }
  if(count!=0)
  {
    cout<<"\n\n\nEnter the position at which you want to try : ";
    g:
    cin>>pos;
    if(isdigit(pos)==0)
    { cout<<"Enter the position in numbers : ";
      goto g;
    }
    s=pos;
    s-=48;
    if(k[s-1]!='_')
    { cout<<"Enter the position correctly : ";
      goto g;
    }
    cout<<"Enter the letter with which you want to try : ";
    p:
    cin>>a;
    if (k[s-1]=='_')
    { if (g[s-1]==a||g[s-1]==tolower(a))
      { clrscr();
	gotoxy(35,4);
	cout<<"Correct!";
	k[s-1]=a;
	gotoxy(1,7);
	cout<<"Now the code becomes as : ";
	gotoxy(36,11);
	for(i=0;k[i]!='\0';++i)
	{ cout<<k[i];
	  delay(100);
	}
	cout<<"\n\n\nThe clue was : ";
	puts(clue);
	continue;
      }
      else
      { if(l!=0)
	{ cout<<setw(35)<<"Wrong letter!";
	  delay(500);
	  cout<<setw(35)<<"Lives left : "<<l--;
	  delay(500);
	  cout<<"\n\n\nTry again by entering the guessed letter : ";
	  goto p;
	}
	else
	{ clrscr();
	  gotoxy(35,9);
	  cout<<"GAME OVER!!!";
	  gotoxy(28,14);
	  cout<<"BETTER LUCK NEXT TIME!!!";
	  gotoxy(1,24);
	  cout<<"Press enter to exit...";
	  getch();
	  clrscr();
	  cout<<"Try Again (y/n) : ";
	  char z;
	  cin>>z;
	  if(z=='y'||z=='Y')
	  {
	    intro();
	    break;
	  }
	  else(z=='n'||z=='N');
	  {
	    gexit();
	    break;
	  }
	}
      }
    }
}
  else
  { cout<<"\n\n\n\n\t\t\tYou discovered the word!!!\n\n";
    delay(1000);
    cout<<"press enter to continue...";
    getch;
    clrscr();
  }
  break;
 }
}
int menu(int pr)
{ char q,ch;
  cout<<"\n\n\nIn-game menu : ";
  cout<<"\n\n1.Continue\n\n2. Exit\n\nEnter the serial number for further continuation : ";
  x:
  cin>>q;
  if(q=='1')
  {
  return(0);
  }
  else if(q=='2')
  { clrscr();
    cout<<"Exit menu : \n\n"<<"1. Save and exit\n\n2. Exit";
    cout<<"\n\nEnter the serial number : ";
    y:
    cin>>ch;
    if(ch=='1')
    { p.calc(pr);
      fstream f;
      f.open("record.txt",ios::app|ios::out);
      f.write((char*)&p,sizeof(p));
      f.close();
      cout<<"\n\nWorking....";
      delay(400);
      cout<<"Saving process has been successfully completed.";
      cout<<"\n\nPress enter to continue....";
      getch();
      return(-1);
    }
    else if(ch==2)
    {
    gexit();
    }
    else
    { cout<<"\n\nPlease enter a valid choice : ";
      goto y;
    }
  }
  else
  { 
    cout<<"\n\nPlease enter a valid choice : ";
    goto x;
  }
  return 0;
}
void complete()
{ 
  clrscr();
  gotoxy(33,11);
  cout<<"CONGRATULATION!!!";
  delay(600);
  gotoxy(32,14);
  cout<<"ALL LEVELS CRACKED!!!";
  delay(2000);
  gexit();
}
void main()
{ 
  intro();
}
