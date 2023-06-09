#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
void border();
void border()
{	setfillstyle(6,6);
	for(int counter=20;counter<getmaxx();counter+=30)
	{	bar(0,0,counter,20);
		bar(getmaxx(),getmaxy(),(getmaxx()-counter),(getmaxy()-20));
		bar(0,0,20,counter);
		bar(getmaxx(),getmaxy(),(getmaxx()-20),(getmaxy()-counter));
		delay(40);
	}
}
class customer
{       char name[20],code[11];
	long bal;
	public:
		void read();
		void display()
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Current Balance is:"<<bal<<endl;
		}
		char* c_code()
		{
			return code;
		}
		long getbal()
		{	return bal;
		}
		void changebal(long amnt)
		{	bal=amnt;
		}
		void bal_update(int);

}c;
void customer::read()
{
	cout<<endl<<"Enter your name:";
	gets(name);
	randomize();
	int x;
	ifstream ifile;
	customer obj;
	ifile.open("Customers.dat",ios::binary|ios::in);
	do
	{
		for(int i=0;i<10;++i)
		{
			x=random(10)+48;
			code[i]=x;
		}
		ifile.seekg(0);
		ifile.read((char*)&obj,sizeof(obj));
		while(!ifile.eof())
		{	if(strcmp(obj.c_code(),code)==0)
			{	break;
			}
			ifile.read((char*)&obj,sizeof(obj));
		}
	}while(strcmp(obj.c_code(),code)==0);
	cout<<"Your code is:"<<code<<endl;
	cout<<"Enter your current balance:";
	cin>>bal;
	ifile.close();
}
void customer::bal_update(int check)
{       long amnt;
	do{
		if(check>0)
		{	cout<<"Enter the extra chips : ";
			cin>>amnt;
		}
		else
		{	cout<<"Enter the withdrawal ammount : ";
			cin>>amnt;
		}
	}while(amnt<0);
	if(check>0)
	{	bal+=amnt;
	}
	else
	{	bal-=amnt;
	}
}
//#############################ROULLETE###################################
class roulette_bet
{	private :
		int value[36];
		int numb;
		int row_num;
		int row_value[3];
		int spl1_num;
		int spl1_value[3];
		int spl2_num;
		int spl2_value[6];

		long avail;
		long casino;

	public :
		void selection();
		void row();
		void spl1();
		void spl2();
		void result(int);
		void display_avail()
		{	char ch[6];
			itoa(avail,ch,10);
			setfillstyle(SOLID_FILL,BLACK);
			bar(20,420,getmaxx()-20,getmaxy()-20);
			setcolor(WHITE);
			settextstyle(1,0,1);
			outtextxy(80,430,"CHIPS : ");
			outtextxy(180,430,ch);
		}
		roulette_bet();
};
roulette_bet::roulette_bet()
{       int i;
	avail=c.getbal();
	casino=0;
	for(i=0;i<36;i++)
	{	value[i]=0;
	}
	for(i=0;i<3;i++)
	{	row_value[i]=0;
	}
	for(i=0;i<3;i++)
	{	spl1_value[i]=0;
	}
	for(i=0;i<6;i++)
	{	spl2_value[i]=0;
	}
}
void roulette_bet :: selection()
{       char key;
	int x=80,y=120;
	setlinestyle(0,0,3);
	setcolor(BLUE);
	rectangle(x,y,x+40,y+60);
	while(kbhit)
		{	key=getch();
			switch(key)
			{	case 77:	//right key
				{	setcolor(WHITE);
					rectangle(x,y,x+40,y+60);

					x+=40;
					if(x>520)
						x=80;
					setcolor(BLUE);
					rectangle(x,y,x+40,y+60);

					break;
				}
				case 75:	//left key
				{	setcolor(WHITE);
					rectangle(x,y,x+40,y+60);

					x-=40;
					if(x<80)
						x=520;
					setcolor(BLUE);
					rectangle(x,y,x+40,y+60);

					break;
				}
				case 72:	//top key
				{	setcolor(WHITE);
					rectangle(x,y,x+40,y+60);

					y-=60;
					if(y<120)
						y=240;
					setcolor(BLUE);
					rectangle(x,y,x+40,y+60);

					break;
				}
				case 80:	//bottom key
				{	setcolor(WHITE);
					rectangle(x,y,x+40,y+60);

					y+=60;
					if(y>240)
						y=120;
					setcolor(BLUE);
					rectangle(x,y,x+40,y+60);

					break;
				}


			}
			if(key==13)break;
		}
	switch(y)
	{
		case 120:
		{       switch(x)
			{	case 80:
				{	numb=1;
					break;
				}
				case 120:
				{	numb=4;
					break;
				}
				case 160:
				{	numb=7;
					break;
				}
				case 200:
				{	numb=10;
					break;
				}
				case 240:
				{	numb=13;
					break;
				}
				case 280:
				{	numb=16;
					break;
				}
				case 320:
				{	numb=19;
					break;
				}
				case 360:
				{	numb=22;
					break;
				}
				case 400:
				{	numb=25;
					break;
				}
				case 440:
				{	numb=28;
					break;
				}
				case 480:
				{	numb=31;
					break;
				}
				case 520:
				{	numb=34;
					break;
				}
			}
			break;
		}
		case 180:
		{       switch(x)
			{	case 80:
				{	numb=2;
					break;
				}
				case 120:
				{	numb=5;
					break;
				}
				case 160:
				{	numb=8;
					break;
				}
				case 200:
				{	numb=11;
					break;
				}
				case 240:
				{	numb=14;
					break;
				}
				case 280:
				{	numb=17;
					break;
				}
				case 320:
				{	numb=20;
					break;
				}
				case 360:
				{	numb=23;
					break;
				}
				case 400:
				{	numb=26;
					break;
				}
				case 440:
				{	numb=29;
					break;
				}
				case 480:
				{	numb=32;
					break;
				}
				case 520:
				{	numb=35;
					break;
				}
			}
			break;
		}
		case 240:
		{       switch(x)
			{	case 80:
				{	numb=3;
					break;
				}
				case 120:
				{	numb=6;
					break;
				}
				case 160:
				{	numb=9;
					break;
				}
				case 200:
				{	numb=12;
					break;
				}
				case 240:
				{	numb=15;
					break;
				}
				case 280:
				{	numb=18;
					break;
				}
				case 320:
				{	numb=21;
					break;
				}
				case 360:
				{	numb=24;
					break;
				}
				case 400:
				{	numb=27;
					break;
				}
				case 440:
				{	numb=30;
					break;
				}
				case 480:
				{	numb=33;
					break;
				}
				case 520:
				{	numb=36;
					break;
				}
			}
			break;
		}
	}

	char betch[6],blank[6]="     ";
	char input;
	int temp=0;
	setcolor(WHITE);
	settextstyle(1,0,1);
	if(avail==0)
	{	return;
	}
	if(value[numb-1]==0)
	{	do{
		do{
			bar(20,20,getmaxx()-20,120);
			outtextxy(30,40,"Place the bet (MAX -> 5000) : ");
			strcpy(betch,blank);
			for(int counter=0;counter<5;counter++)
			{	betch[counter]=getch();
				if(betch[counter]<48||betch[counter]>57)
				{      if(betch[counter]==13)
						break;
					counter--;
					continue;
				}
				outtextxy(330,40,betch);
			}
			value[numb-1]=atoi(betch);
			temp=value[numb-1];
		}while(temp>=avail||temp>5000);
			outtextxy(30,60,"Press 'Y' to confirm bet");
			input=getch();
		}while(input!='y'&&input!='Y');
	}
	else
	{       itoa(value[numb-1],betch,10);
		outtextxy(30,40,"Bet is : ");
		outtextxy(200,40,betch);
		getch();
	}
	avail-=temp;
	casino+=temp;
	display_avail();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,120);
}
void roulette_bet::row()
{       char key;
	int const x=80;
	int y=120;
	setlinestyle(0,0,3);
	setcolor(BLUE);
	rectangle(x,y,x+480,y+60);
	while(kbhit)
	{	key=getch();
		switch(key)
		{	case 72:	//top key
				setcolor(WHITE);
				rectangle(x,y,x+480,y+60);
				switch(y)
				{	case 120:
						y=240;
						break;

					case 180:
						y-=60;
						break;
					case 240:
						y-=60;
						break;
				}
				break;
			case 80:	//bottom key
			       setcolor(WHITE);
				rectangle(x,y,x+480,y+60);
				switch(y)
				{	case 120:
						y+=60;
						break;

					case 180:
						y+=60;
						break;
					case 240:
						y=120;
						break;
				}
				break;
		}
		setcolor(BLUE);
		rectangle(x,y,x+480,y+60);
		if(key==13)
			break;
	}
	switch(y)
	{	case 120:
			row_num=0;
			break;
		case 180:
			row_num=1;
			break;
		case 240:
			row_num=2;
			break;
	}
	char betch[6],blank[6]="     ";
	char input;
	int temp=0;
	setcolor(WHITE);
	settextstyle(1,0,1);
	if(avail==0)
	{	return;
	}
	if(row_value[row_num]==0)
	{	do{
		do{
			bar(20,20,getmaxx()-20,120);
			outtextxy(30,40,"Place the bet (MAX -> 5000) : ");
			strcpy(betch,blank);
			for(int counter=0;counter<5;counter++)
			{	betch[counter]=getch();
				if(betch[counter]<48||betch[counter]>57)
				{      if(betch[counter]==13)
						break;
					counter--;
					continue;
				}
				outtextxy(330,40,betch);
			}
			row_value[row_num]=atoi(betch);
			temp=row_value[row_num];
		}while(temp>=avail||temp>=5000);
			outtextxy(30,60,"Press 'Y' to confirm bet");
			input=getch();
		}while(input!='y'&&input!='Y');
	}
	avail-=temp;
	casino+=temp;
	display_avail();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,120);
}
void roulette_bet::spl1()
{       char key;
	int x=80;
	const y=300;
	setlinestyle(0,0,3);
	setcolor(BLUE);
	rectangle(x,y,x+160,y+60);
	while(kbhit)
	{	key=getch();
		switch(key)
		{	case 77:	//right key
				setcolor(WHITE);
				rectangle(x,y,x+160,y+60);
				switch(x)
				{	case 80:
						x+=160;
						break;

					case 240:
						x+=160;
						break;
					case 400:
						x=80;
						break;
				}
				break;
			case 75:	//left key
				setcolor(WHITE);
				rectangle(x,y,x+160,y+60);
				switch(x)
				{	case 80:
						x=400;
						break;

					case 240:
						x-=160;
						break;
					case 400:
						x-=160;
						break;
				}
				break;
		}
		setcolor(BLUE);
		rectangle(x,y,x+160,y+60);
		if(key==13)
			break;
	}
	switch(x)
	{	case 80:
			spl1_num=0;
			break;
		case 240:
			spl1_num=1;
			break;
		case 400:
			spl1_num=2;
			break;
	}
	char betch[6],blank[6]="     ";
	char input;
	int temp=0;
	setcolor(WHITE);
	settextstyle(1,0,1);
	if(avail==0)
	{	return;
	}
	if(spl1_value[spl1_num]==0)
	{	do{
		do{
			bar(20,20,getmaxx()-20,120);
			outtextxy(30,40,"Place the bet (MAX -> 5000) : ");
			strcpy(betch,blank);
			for(int counter=0;counter<5;counter++)
			{	betch[counter]=getch();
				if(betch[counter]<48||betch[counter]>57)
				{      if(betch[counter]==13)
						break;
					counter--;
					continue;
				}
				outtextxy(330,40,betch);
			}
			spl1_value[spl1_num]=atoi(betch);
			temp=spl1_value[spl1_num];
		}while(temp>=avail||temp>5000);
			outtextxy(30,60,"Press 'Y' to confirm bet");
			input=getch();
		}while(input!='y'&&input!='Y');
	}
	avail-=temp;
	casino+=temp;
	display_avail();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,120);

}
void roulette_bet::spl2()
{       char key;
	int x=80;
	const y=360;
	setlinestyle(0,0,3);
	setcolor(BLUE);
	rectangle(x,y,x+80,y+60);
	while(kbhit)
	{	key=getch();
		switch(key)
		{	case 77:	//right key
				setcolor(WHITE);
				rectangle(x,y,x+80,y+60);
				switch(x)
				{	case 80:
						x+=80;
						break;
					case 160:
						x+=80;
						break;
					case 240:
						x+=80;
						break;
					case 320:
						x+=80;
						break;
					case 400:
						x+=80;
						break;
					case 480:
						x=80;
						break;
				}
				break;
			case 75:	//left key
				setcolor(WHITE);
				rectangle(x,y,x+80,y+60);
				switch(x)
				{	case 80:
						x=480;
						break;
					case 160:
						x-=80;
						break;
					case 240:
						x-=80;
						break;
					case 320:
						x-=80;
						break;
					case 400:
						x-=80;
						break;
					case 480:
						x-=80;
						break;
				}
				break;
		}
		setcolor(BLUE);
		rectangle(x,y,x+80,y+60);
		if(key==13)
			break;
	}
	switch(x)
	{       case 80:
			spl2_num=0;
			break;
		case 160:
			spl2_num=1;
			break;
		case 240:
			spl2_num=2;
			break;
		case 320:
			spl2_num=3;
			break;
		case 400:
			spl2_num=4;
			break;
		case 480:
			spl2_num=5;;
			break;
	}
	char betch[6],blank[6]="     ";
	char input;
	int temp=0;
	setcolor(WHITE);
	settextstyle(1,0,1);
	if(avail==0)
	{	return;
	}
	if(spl2_value[spl2_num]==0)
	{	do{
		do{
			bar(20,20,getmaxx()-20,120);
			outtextxy(30,40,"Place the bet (MAX -> 5000) : ");
			strcpy(betch,blank);
			for(int counter=0;counter<5;counter++)
			{	betch[counter]=getch();
				if(betch[counter]<48||betch[counter]>57)
				{      if(betch[counter]==13)
						break;
					counter--;
					continue;
				}
				outtextxy(330,40,betch);
			}
			spl2_value[spl2_num]=atoi(betch);
			temp=spl2_value[spl2_num];
		}while(temp>=avail||temp>5000);
			outtextxy(30,60,"Press 'Y' to confirm bet");
			input=getch();
		}while(input!='y'&&input!='Y');
	}
	avail-=temp;
	casino+=temp;
	display_avail();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,120);
}
void roulette_bet :: result(int spin)
{	long amt=0;
	if(numb==spin)	 //number bet
	{ 	amt+=(38*value[numb-1]);
		avail+=value[numb-1];
		casino-=value[numb-1];
	}
	if(spin%3==0)		//row bet
	{	amt+=row_value[2];
		avail+=row_value[2];
		casino-=row_value[2];
	}
	else
	{       int found=-1;
		for(int i=1;i<=34;i+=3)
		{	if(spin==i)
			{       found=0;
				amt+=row_value[0];
				avail+=row_value[0];
				casino-=row_value[0];
				break;
			}
		}
		if(found==-1)
		{	amt+=row_value[1];
			avail+=row_value[1];
			casino-=row_value[1];
		}
	}
	if(spin>=1&&spin<=12)
	{	amt+=(2*spl1_value[0]);
		avail+=spl1_value[0];
		casino-=spl1_value[0];
	}
	if(spin>=13&&spin<=24)
	{	amt+=(2*spl1_value[1]);
		avail+=spl1_value[1];
		casino-=spl1_value[1];
	}
	if(spin>=25&&spin<=36)
	{	amt+=(2*spl1_value[2]);
		avail+=spl1_value[2];
		casino-=spl1_value[2];
	}
	if(spin>=1&&spin<=18)
	{	amt+=spl2_value[0];
		avail+=spl2_value[0];
		casino-=spl2_value[0];
	}
	if(spin>=19&&spin<=36)
	{	amt+=spl2_value[5];
		avail+=spl2_value[5];
		casino-=spl2_value[5];
	}
	if(spin%2==0)
	{	amt+=spl2_value[1];
		amt+=spl2_value[2];
		avail+=spl2_value[1];
		casino-=spl2_value[1];
		avail+=spl2_value[2];
		casino-=spl2_value[2];
	}
	else
	{	amt+=spl2_value[3];
		amt+=spl2_value[4];
		avail+=spl2_value[3];
		casino-=spl2_value[3];
		avail+=spl2_value[4];
		casino-=spl2_value[4];
	}
	setcolor(WHITE);
	settextstyle(3,0,2);
	char amtch[6];
	itoa(amt,amtch,10);
	outtextxy(160,300,"Winning ammount : ");
	outtextxy(350,300,amtch);
	avail+=amt;
	casino-=amt;
	char availch[6];
	itoa(avail,availch,10);
	outtextxy(160,330,"CHIPS : ");
	outtextxy(240,330,availch);

	unsigned long val;
	char initial[9];
	ifstream ifile;
	ifile.open("manage.txt");
	ofstream ofile;
	ofile.open("new.txt");
	ifile.getline(initial,9);
	ofile<<initial<<endl;
	ifile>>val;
	val+=casino;
	ofile<<val<<endl;
	ifile.close();
	ofile.close();
	remove("manage.txt");
	rename("new.txt","manage.txt");

	customer obj;
	ofile.open("New.dat",ios::binary);
	ifile.open("Customers.dat",ios::binary);
	ifile.read((char*)&obj,sizeof(obj));
	while(ifile)
	{	if(strcmp(c.c_code(),obj.c_code())==0)
		{       obj.changebal(avail);
			c.changebal(avail);
		}
		ofile.write((char*)&obj,sizeof(obj));
		ifile.read((char*)&obj,sizeof(obj));
	}
	ifile.close();
	ofile.close();
	remove("Customers.dat");
	rename("New.dat","Customers.dat");

}
void display_board()
{       setlinestyle(0,0,3);
	setfillstyle(1,2);
	for(int counter=40;counter<=480;counter+=40)
	{	bar(80,120,(80 + counter),180);
		bar(80,180,(80 + counter),240);
		bar(80,240,(80 + counter),300);
	}
	rectangle(80,120,560,180);
	rectangle(80,180,560,240);
	rectangle(80,240,560,300);
	setfillstyle(0,5);
	for(counter=40;counter<=480;counter+=40)
	{	line((80+counter),120,(80 + counter),300);
		fillellipse(60 + counter,150,16,26);
		fillellipse(60 + counter,210,16,26);
		fillellipse(60 + counter,270,16,26);
	}
	setfillstyle(1,RED);
	for(counter=80;counter<=480;counter+=80)
	{	floodfill(70 + counter,150,15);
		floodfill(30+counter,210,15);
		floodfill(70+counter,270,15);
	}
	settextstyle(4,0,2);
	setcolor(15);
	char temp[3];int i=10;
	for(counter=40;counter<=368;counter+=40)
	{       itoa(i,temp,10);
		outtextxy(168+counter,140,temp);
		itoa(i+1,temp,10);
		outtextxy(168+counter,200,temp);
		itoa(i+2,temp,10);
		outtextxy(168+counter,260,temp);
		i+=3;
	}
	i=1;
	for(counter=40;counter<=120;counter+=40)
	{       itoa(i,temp,10);
		outtextxy(55+counter,140,temp);
		itoa(i+1,temp,10);
		outtextxy(52+counter,200,temp);
		itoa(i+2,temp,10);
		outtextxy(57+counter,260,temp);
		i+=3;
	}
	setfillstyle(1,2);
	bar(80,300,240,360);
	bar(240,300,400,360);
	bar(400,300,560,360);

	setlinestyle(0,0,7);
	rectangle(80,300,240,360);
	rectangle(240,300,400,360);
	rectangle(400,300,560,360);

	setfillstyle(1,GREEN);
	sector(80,210,90,270,40,90);
	sector(560,210,0,90,40,90);
	sector(560,210,270,360,40,90);
	setcolor(GREEN);
	line(560,210,600,210);
	setcolor(WHITE);
	settextstyle(3,1,2);
	outtextxy(45,160,"ROULETTE");
	outtextxy(565,180,"BOARD");


	settextstyle(4,0,2);
	bar(80,360,560,420);
	for(counter=80;counter<=480;counter+=80)
	{	rectangle(counter,360,counter+80,420);
	}

	setfillstyle(1,RED);
	bar(242,362,318,418);
	setfillstyle(1,BLACK);
	bar(322,362,398,418);

	outtextxy(125,320,"1st 12");
	outtextxy(285,320,"2nd 12");
	outtextxy(445,320,"3rd 12");
	outtextxy(82,380,"1 to 18");
	outtextxy(162,380,"E.V.E.N");
	outtextxy(415,380,"O D D");
	outtextxy(483,380,"19to36");
}
void spin_display()
{       cleardevice();
	border();
	int i=0;
	do{
		int rnd_font=random(5);
		int rnd_size=random(4);
		int rnd_color=random(15)+1;
		int rndx=random(550)+30;
		int rndy=random(400)+30;
		int rnd=random(36)+1;
		char rndch[3];
		itoa(rnd,rndch,10);
		setcolor(rnd_color);
		settextstyle(rnd_font,0,rnd_size);
		outtextxy(rndx,rndy,rndch);
		delay(10);
		i++;
	}while(i<=500);
	setfillstyle(8,BLUE);
	bar(100,80,getmaxx()-100,400);
	setcolor(LIGHTBLUE);
	rectangle(100,80,getmaxx()-100,400);
	setfillstyle(1,RED);
	bar(140,120,getmaxx()-140,360);
	setcolor(YELLOW);
	rectangle(140,120,getmaxx()-140,360);
}
void roulette()
{       int driver = DETECT,mode;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	randomize();
	char input;
	do
	{
	cleardevice();
	roulette_bet bet;
	border();
	display_board();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,110);
	settextstyle(1,0,1);
	setcolor(GREEN);
	outtextxy(30,40,"Do you wanna bet on a number(y/n)?");
	input=getch();
	if(input=='y')
	{	do
		{	bet.display_avail();
			setcolor(GREEN);
			bet.selection();
			bet.display_avail();
			outtextxy(30,40,"Press Enter to proceed(press any key to place another bet)");
			setfillstyle(1,0);
			input=getch();
			bar(20,20,getmaxx()-20,110);
		}while(input!=13);
	}
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,110);
	outtextxy(30,40,"Do you wanna bet on row(y/n)?");
	input=getch();
	if(input=='y')
	{		bet.display_avail();
			setfillstyle(1,0);
			bar(20,20,getmaxx()-20,110);
			outtextxy(30,40,"Select the row");
			bet.display_avail();
			bet.row();
	}
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,110);
	outtextxy(30,40,"Do you wanna bet at second last row (y/n)?");
	input=getch();
	if(input=='y')
	{	bet.display_avail();
		setfillstyle(1,0);
		bar(20,20,getmaxx()-20,110);
		outtextxy(30,40,"Select :");
		bet.display_avail();
		bet.spl1();
	}
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,110);
	outtextxy(30,40,"Do you wanna bet at last row (y/n)?");
	input=getch();
	if(input=='y')
	{	bet.display_avail();
		setfillstyle(1,0);
		bar(20,20,getmaxx()-20,110);
		outtextxy(30,40,"Select :");
		bet.display_avail();
		bet.spl2();
	}
	bet.display_avail();
	setfillstyle(1,0);
	bar(20,20,getmaxx()-20,110);
	settextstyle(3,0,5);
	setcolor(LIGHTRED);
	outtextxy(80,40,"SPIN THE WHEEL");
	getch();

	spin_display();
	settextstyle(4,0,8);
	int spin=random(36)+1;
	char spinch[3]="  ";
	itoa(spin,spinch,10);
	outtextxy(290,180,spinch);
	bet.result(spin);
	setcolor(WHITE);
	settextstyle(3,0,2);
	outtextxy(220,130,"PLAY AGAIN (y/n) : ");
	input=getch();
	}while(input=='y'||input=='Y');
}
//######################ROULETTE END######################################

//#############################BACCARAT####################################
unsigned bet;
int card_no(int x,int y);
int betting(long avail)
{       int x=175;
	const y=220,max=5000;
	char key;
	getch();
	char input,betch[6]="    ",blank[6]="     ";
	int counter,choice;
	do
	{
	do
	{
	setfillstyle(1,LIGHTBLUE);
	bar(20,290,getmaxx()-20,345);

	setfillstyle(1,BLACK);
	bar(282,352,588,398);

	settextstyle(0,0,1);
	setcolor(WHITE);
	outtextxy(320,365,"SELECT and Press ENTER");

	setlinestyle(0,0,3);
	setcolor(GREEN);
	circle(x,y,60);
	while(kbhit)
	{	key=getch();
		switch(key)
		{	case 77:
			{	setcolor(WHITE);
				circle(x,y,60);

				x+=145;
				if(x>465)
					x=175;
				setcolor(GREEN);
				circle(x,y,60);
				break;
			}
			case 75:
			{	setcolor(WHITE);
				circle(x,y,60);

				x-=145;
				if(x<175)
					x=465;
				setcolor(GREEN);
				circle(x,y,60);
				break;
			}
		}
		if(key==13)break;
	}
//***************************************************************
		setfillstyle(1,LIGHTBLUE);
		bar(20,290,getmaxx()-20,345);
		setfillstyle(1,BLACK);
		bar(282,352,588,398);
		setcolor(WHITE);
		settextstyle(0,0,1);
		strcpy(betch,blank);
		switch(x)
		{       case 320:
			{       outtextxy(320,365,"BANKER is selected.Enter bet.");
				outtextxy(330,375,"MAX -> 5000");
				settextstyle(0,0,2);
				setcolor(BROWN);
				for(counter=0;counter<5;counter++)
				{	betch[counter]=getch();
					if(betch[counter]<48||betch[counter]>57)
					{      if(betch[counter]==13)
							break;
						counter--;
						continue;
					}
					outtextxy(270,300,betch);
				}
				choice=1;
				break;
			}
			case 465:
			{       outtextxy(320,365,"PLAYER is selected.Enter bet.");
				outtextxy(330,375,"MAX -> 5000");
				settextstyle(0,0,2);
				setcolor(BROWN);
				for(counter=0;counter<5;counter++)
				{	betch[counter]=getch();
					if(betch[counter]<48||betch[counter]>57)
					{      if(betch[counter]==13)
							break;
						counter--;
						continue;
					}
					outtextxy(415,300,betch);
				}
				choice=2;
				break;
			}
			case 175:
			{       outtextxy(320,365,"TIE is selected.Enter bet.");
				outtextxy(330,375,"MAX -> 5000 ");
				settextstyle(0,0,2);
				setcolor(BROWN);
				for(counter=0;counter<5;counter++)
				{	betch[counter]=getch();
					if(betch[counter]<48||betch[counter]>57)
					{      if(betch[counter]==13)
							break;
						counter--;
						continue;
					}
					outtextxy(125,300,betch);
				}
				choice=3;
				break;
			}
		}
		bet=atoi(betch);
	}while(bet>max||bet>avail);
		bar(282,352,588,398);
		setcolor(WHITE);
		settextstyle(0,0,1);
		outtextxy(320,365,"Press 'Y' to confirm bet");
		input=getch();
	}while(input!='y'&&input!='Y');
	return choice;
}
int thirdcard(int n)
{       int card;
	setlinestyle(0,0,0);
	switch(n)
	{	case 1: //player
		{       setfillstyle(SOLID_FILL,BLACK);
			bar(162,64,208,130);
			setcolor(WHITE);
			rectangle(160,62,210,132);
			return card_no(170,75);
		}
		case 2: //banker
		{       setfillstyle(SOLID_FILL,BLACK);
			bar(512,64,562,130);
			setcolor(WHITE);
			rectangle(510,62,560,132);
			return card_no(520,75);
		}
	}
}
int judge(int &p,int &b)
{	if(p==8||p==9)
	{	if(p>b)
			return 1;
		else if(p<b)
			return 2;
		else if(p==b)
			return 0;
	}

	if(b==8||b==9)
	{	if(p>b)
			return 1;
		else if(p<b)
			return 2;
		else if(p==b)
			return 0;
	}
	int card;
	if(p>=0&&p<=5)
	{	card=thirdcard(1);
		p+=card;
		if(b==3&&card!=8)
		{	b+=thirdcard(2);
		}
		else if(b==4&&card!=0&&card!=1&&card!=8&&card!=9)
		{	b+=thirdcard(2);
		}
		else if(b==5&&card==4&&card==5&&card==6&&card==7)
		{	b+=thirdcard(2);
		}
		else if(b==6&&card==6&&card==7)
		{	b+=thirdcard(2);
		}
	}
	else
	{	card=0;
		if(b==3&&card!=8)
		{	b+=thirdcard(2);
		}
		else if(b==4&&card!=0&&card!=1&&card!=8&&card!=9)
		{	b+=thirdcard(2);
		}
		else if(b==5&&card==4&&card==5&&card==6&&card==7)
		{	b+=thirdcard(2);
		}
		else if(b==6&&card==6&&card==7)
		{	b+=thirdcard(2);
		}
	}

	if(p>b)
		return 1;
	else if(p<b)
		return 2;
	else
		return 0;
}
int card_no(int x,int y)
{       int card;
	card=random(310)+1; //random generated 1to311
	card=(card%13)+1;//random generated 1to13 w.r.t 312 cards or 6 decks;
	setcolor(LIGHTGRAY);
	settextstyle(4,0,4);
	switch(card)
		{	case 1:
			{	outtextxy(x,y,"A");
				break;
			}
			case 2:
			{	outtextxy(x,y,"2");
				break;
			}
			case 3:
			{	outtextxy(x,y,"3");
				break;
			}
			case 4:
			{	outtextxy(x,y,"4");
				break;
			}
			case 5:
			{	outtextxy(x,y,"5");
				break;
			}
			case 6:
			{	outtextxy(x,y,"6");
				break;
			}
			case 7:
			{	outtextxy(x,y,"7");
				break;
			}
			case 8:
			{	outtextxy(x,y,"8");
				break;
			}
			case 9:
			{	outtextxy(x,y,"9");
				break;
			}
			case 10:
			{	outtextxy(x-7,y,"10");
				card=0;
				break;
			}
			case 11:
			{	outtextxy(x,y,"J");
				card=0;
				break;
			}
			case 12:
			{	outtextxy(x,y,"Q");
				card=0;
				break;
			}
			case 13:
			{	outtextxy(x,y,"K");
				card=0;
				break;
			}
		}
		return card;
}
void baccarat()
{       randomize();
	int driver = DETECT, mode= DETECT;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	int input;
	long avail=c.getbal();
	do
	{
	cleardevice();
	border();
//############################################################
//		baccrat board
//############################################################
	setfillstyle(1,9);
	bar(20,20,getmaxx()-20,getmaxy()-20);
	settextstyle(0,0,3);
	setcolor(RED);
	outtextxy(60,30,"PlAYER");
	outtextxy(410,30,"BANKER");

	setcolor(BLACK);
	setlinestyle(0,0,7);
	rectangle(50,62,100,132);
	rectangle(105,62,155,132);
	rectangle(400,62,450,132);
	rectangle(455,62,505,132);

	setfillstyle(8,LIGHTGRAY);
	floodfill(51,63,BLACK);
	floodfill(106,63,BLACK);
	floodfill(401,63,BLACK);
	floodfill(456,63,BLACK);

	setcolor(WHITE);
	setlinestyle(0,0,3);
	circle(175,220,60);
	circle(320,220,60);
	circle(465,220,60);
	setfillstyle(1,BLUE);
	floodfill(175,220,15);
	floodfill(320,220,15);
	floodfill(465,220,15);

	settextstyle(0,0,2);
	setcolor(MAGENTA);
	outtextxy(150,210,"TIE");
	outtextxy(275,210,"BANKER");
	outtextxy(420,210,"PlAYER");

	setcolor(WHITE);
	setfillstyle(1,0);
	setlinestyle(0,0,1);
	rectangle(30,350,210,400);
	floodfill(51,351,15);
	rectangle(280,350,590,400);
	floodfill(351,351,15);

	setcolor(RED);
	settextstyle(0,0,3);
	outtextxy(65,410,"CHIPS");
	outtextxy(360,410,"STATUS");

	char ch_avail[9];
	setcolor(WHITE);
	settextstyle(0,0,2);
	itoa(avail,ch_avail,10);
	outtextxy(65,365,ch_avail);
	settextstyle(0,0,1);
	outtextxy(320,365,"Press any key");
//##################################################
	int choice=betting(avail); //return 1 for banker,2 for player ,
				//3 for tie
//##################################################
	setfillstyle(1,BLACK);
	bar(282,352,588,398);
	setcolor(WHITE);
	settextstyle(0,0,1);
	outtextxy(320,365,"BET CONFIRMED");
//#######################################################
//	GAME
//###########################################################

	int p1,p2,b1,b2;
	int p,b;

	setfillstyle(1,BLACK);
	bar(50,62,100,132);
	bar(105,62,155,132);
	bar(400,62,450,132);
	bar(455,62,505,132);
	setcolor(WHITE);
	setlinestyle(0,0,0);
	rectangle(50,62,100,134);
	rectangle(105,62,155,134);
	rectangle(400,62,450,134);
	rectangle(455,62,505,134);

	p1=card_no(60,75);
	p2=card_no(115,75);
	b1=card_no(415,75);
	b2=card_no(470,75);

	p=p1+p2;
	p=(p>9)?(p-10):p;
	b=b1+b2;
	b=b>9?(b-10):b;

	int result;
	result=judge(p,b);//returns 0 for tie,1 for player and 2 for banker
	//display the numbers;

	setfillstyle(1,BLACK);
	bar(282,352,588,398);
	setcolor(WHITE);
	settextstyle(0,0,1);
	long casino=0;
	avail-=bet;
	casino+=bet;
	switch(result)
	{	case 2:
			outtextxy(320,365,"BANKER HAND WON !!");
			if(choice==1)
			{	avail+=(bet + (int)((0.95)*bet));
				casino-=(bet+(int)((0.95)*bet));
			}
			break;
		case 1:
			outtextxy(320,365,"PLAYER HAND WON !!");
			if(choice==2)
			{	avail+=(bet+bet);
				casino-=(bet+bet);
			}
			break;
		case 0:
			outtextxy(320,365,"TIE HAND WON !!");
			if(choice==3)
			{	avail+=(bet+(8*bet));
				casino-=(bet+(8*bet));
			}
			break;
	}
	unsigned long val;
	char initial[9];
	ifstream ifile;
	ifile.open("manage.txt");
	ofstream ofile;
	ofile.open("new.txt");
	ifile.getline(initial,9);
	ofile<<initial<<endl;
	ifile>>val;
	val+=casino;
	ofile<<val<<endl;
	ifile.close();
	ofile.close();
	remove("manage.txt");
	rename("new.txt","manage.txt");

	customer obj;
	ofile.open("New.dat",ios::binary);
	ifile.open("Customers.dat",ios::binary);
	ifile.read((char*)&obj,sizeof(obj));
	while(ifile)
	{	if(strcmp(c.c_code(),obj.c_code())==0)
		{       obj.changebal(avail);
			c.changebal(avail);
		}
		ofile.write((char*)&obj,sizeof(obj));
		ifile.read((char*)&obj,sizeof(obj));
	}
	ifile.close();
	ofile.close();
	remove("Customers.dat");
	rename("New.dat","Customers.dat");

	setfillstyle(SOLID_FILL,BLACK);
	bar(30,350,210,400);
	setcolor(WHITE);
	rectangle(30,350,210,400);
	setcolor(WHITE);
	settextstyle(0,0,2);
	itoa(avail,ch_avail,10);
	outtextxy(65,365,ch_avail);
	settextstyle(0,0,1);
	getch();

	setfillstyle(1,BLACK);
	bar(282,352,588,398);
	outtextxy(320,365,"PLAY AGAIN (y/n) ?");
	input=getch();
	}while(input=='y'||input=='Y');
}
//#########################BACCARAT END#####################################
int management()
{	closegraph();
	int choice;
	do{
	link:
	ifstream ifile;
	ofstream ofile;
	char initial[9],final[9];
	clrscr();
	int option,found;
	char ans,s_code[10];
	cout<<setw(34)<<"MANAGEMENT"<<endl;
	cout<<"1.Casino Balance"<<endl
	    <<"2.Investment"<<endl
	    <<"3.Change Password "<<endl
	    <<"4.Back to previous menu"<<endl;
	cin>>choice;
	switch(choice)
	{	case 1:
			ifile.open("manage.txt",ios::nocreate);
			ifile.getline(initial,9);
			ifile.getline(initial,9);
			cout<<"Balance : "<<initial;
			ifile.close();
			getch();
			goto link;
		case 2:
			long amnt;
			unsigned long val;
			cout<<"Enter the ammount : ";
			cin>>amnt;
			if(amnt<0)
			{       cout<<endl<<"Not Allowed"<<endl;
				getch();
				goto link;
			}
			ifile.open("manage.txt");
			ofile.open("new.txt");
			ifile.getline(initial,9);
			ofile<<initial<<endl;
			ifile>>val;
			amnt+=val;
			ofile<<amnt<<endl;
			ifile.close();
			ofile.close();
			remove("manage.txt");
			rename("new.txt","manage.txt");
			cout<<endl<<"Invesment added"<<endl;
			getch();
			goto link;
		case 3:
			cout<<"Enter the old password : ";
			gets(final);
			ifile.open("manage.txt");
			ifile.getline(initial,9);
			if(strcmp(initial,final)==0)
			{	cout<<"Enter the new password : ";
				gets(final);
				ofile.open("New.txt");
				ofile<<final<<endl;
				ifile.getline(initial,9);
				while(ifile)
				{
					ofile<<initial<<endl;
					ifile.getline(initial,9);
				}
				ifile.close();
				ofile.close();
				remove("manage.txt");
				rename("New.txt","manage.txt");
			}
			else
			{	cout<<"Wrong Password"<<endl;
				getch();
			}
			goto link;
		case 4:
			int driver = DETECT, mode= DETECT;
			initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
			return -1;
		default:
			cout<<"Wrong Entry!";
			getch();
			break;
	}
	}while(choice>4||choice<1);
	clrscr();
	int driver = DETECT, mode= DETECT;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	return 0;
}
void update()
{       int choice=1;
	customer obj;
	ofstream ofile;
	ifstream ifile;
	for(;;)
	{do{
		clrscr();
		c.display();
		cout<<endl<<"1. PLAY "
		    <<endl<<"2. Update Chips -> Cash into Chips "
		    <<endl<<"3. Withdraw Chips -> Chips into Cash "<<endl;
		cin>>choice;
	}while(choice>3||choice<1);
	switch(choice)
	{	case 1:
			return;
		case 2:
			ofile.open("New.dat",ios::binary);
			ifile.open("Customers.dat",ios::binary);
			ifile.read((char*)&obj,sizeof(obj));
			while(ifile)
			{	if(strcmp(c.c_code(),obj.c_code())==0)
				{       obj.bal_update(1);
					c.changebal(obj.getbal());
				}
				ofile.write((char*)&obj,sizeof(obj));
				ifile.read((char*)&obj,sizeof(obj));
			}
			ifile.close();
			ofile.close();
			remove("Customers.dat");
			rename("New.dat","Customers.dat");
			cout<<endl<<"Chips updated!"<<endl;
			getch();
			break;
		case 3:
			ofile.open("New.dat",ios::binary);
			ifile.open("Customers.dat",ios::binary);
			ifile.read((char*)&obj,sizeof(obj));
			while(ifile)
			{	if(strcmp(c.c_code(),obj.c_code())==0)
				{       obj.bal_update(-1);
					c.changebal(obj.getbal());
				}
				ofile.write((char*)&obj,sizeof(obj));
				ifile.read((char*)&obj,sizeof(obj));
			}
			ifile.close();
			ofile.close();
			remove("Customers.dat");
			rename("New.dat","Customers.dat");
			cout<<endl<<"Money Withdrawn!"<<endl;
			getch();
			break;

	}
	}
}
int login()
{
	int found=0,logch;
	char tcode[11]="/0";
	cout<<"Enter your unique code:";
	for(int i=0;i<10;i++)
	{
		tcode[i]=getch();
		if (tcode[i]==13)
			break;
		cout<<"*";
	}
	ifstream ifile;
	ifile.open("Customers.dat",ios::binary|ios::in);
	ifile.read((char*)&c,sizeof(c));
	while (!ifile.eof())
	{
		if (strcmp(c.c_code(),tcode)==0)
		{
			found=1;
			cout<<endl;
			break;
		}
		ifile.read((char*)&c,sizeof(c));
	}
	ifile.close();
	if (found==0)
	{	cout<<endl<<"Customer doesn't exist."<<endl;
		getch();
		return -1;
	}
	if(found==1)
		update();
	return 0;
}
int service()
{       closegraph();
	int choice;
	do{
	link:
	clrscr();
	int option,found;
	char ans,s_code[10];
	ifstream ifile;
	ofstream ofile;
	cout<<setw(34)<<"SERVICE"<<endl;
	cout<<"1. View the Details of our Customers."<<endl
	    <<"2. Add as a Memeber"<<endl
	    <<"3. Login "<<endl
	    <<"4. Delete Membership "<<endl
	    <<"5. Back to Previous Menu"<<endl;
	cin>>choice;
	switch(choice)
	{	case 1:
			ifile.open("Customers.dat",ios::binary|ios::nocreate);
			ifile.read((char*)&c,sizeof(c));
			while (!ifile.eof())
			{
				c.display();
				cout<<endl;
				ifile.read((char*)&c,sizeof(c));
			}
			ifile.close();
			getch();
			goto link;
		case 2:
			ofile.open("Customers.dat",ios::binary|ios::ate|ios::nocreate);
			c.read();
			ofile.write((char*)&c,sizeof(c));
			ofile.close();
			cout<<"Customer added."<<endl;
			getch();
			goto link;
		case 3:
			if(login()==-1)
				goto link;
			break;
		case 4:
			int found=0,logch;
			char tcode[11]="/0";
			cout<<"Enter the Unique Code of Member:";
			for(int i=0;i<10;i++)
			{
				tcode[i]=getch();
				if (tcode[i]==13)
				break;
				cout<<"*";
			}
			ifile.open("Customers.dat",ios::binary|ios::in);
			ifile.read((char*)&c,sizeof(c));
			while (!ifile.eof())
			{
				if (strcmp(c.c_code(),tcode)==0)
				{
					found=1;
					cout<<endl;
					break;
				}
				ifile.read((char*)&c,sizeof(c));
			}
			ifile.close();
			if (found==0)
			{	cout<<endl<<"Customer doesn't exist."<<endl;
				getch();
			}
			if(found==1)
			{       customer obj;
				ifile.open("Customers.dat",ios::binary);
				ofile.open("New.dat",ios::binary);
				ifile.read((char*)&obj,sizeof(obj));
				while(!ifile.eof())
				{	if(strcmp(obj.c_code(),c.c_code())!=0)
					{	ofile.write((char*)&obj,sizeof(obj));
					}
					else
					{	cout<<endl<<"Customer that is Deleted : "<<endl;
						obj.display();
					}
					ifile.read((char*)&obj,sizeof(obj));
				}
				ifile.close();
				ofile.close();
				remove("Customers.dat");
				rename("New.dat","Customers.dat");
				cout<<endl<<"Money Withdrawn "
				    <<endl<<"Membership Deleted "<<endl;
				getch();
			}
			goto link;
		case 5:
			int driver = DETECT, mode= DETECT;
			initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
			return -1;
		default:
			cout<<"Wrong Entry!";
			getch();
			break;
	}
	}while(choice>5||choice<1);
	clrscr();
	int driver = DETECT, mode= DETECT;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	return 0;

}
void display()
{	setcolor(LIGHTRED);
	setfillstyle(1,0);
	for(int i=getmaxx()/2, j=getmaxy()/2, size=1;size<=9;size++)
	{       setcolor(BLACK);
		bar(20,20,600,400);
		setcolor(MAGENTA);
		settextstyle(4,0,size);
		outtextxy(i-40,j-30,"CASINO");
		delay(25);
		i-=22;
		j-=15;
	}
	setlinestyle(0,0,3);
	setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setcolor(WHITE);
	rectangle(50,220,590,420);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(100,270,300,370);
	bar(350,270,550,370);
	setcolor(WHITE);
	rectangle(100,270,300,370);
	rectangle(350,270,550,370);
	setcolor(BLACK);
	settextstyle(3,0,4);
	outtextxy(150,300,"START");
	outtextxy(420,300,"EXIT");
	int key,x=100;
	const y=270;
	setcolor(GREEN);
	rectangle(x,y,x+200,y+100);
	while(kbhit)
	{       key=getch();
		switch(key)
		{	case 77:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x+=250;
				if(x>350)
					x=100;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
			case 75:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x-=250;
				if(x<100)
					x=350;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
		}
		if(key==13)break;
	}
	if(x==350)
	{	exit(0);
	}

}
int front()
{       int x=100,key;
	const y=270;

	setfillstyle(SOLID_FILL,BLACK);
	bar(20,20,600,400);
	setcolor(MAGENTA);
	settextstyle(4,0,9);
	outtextxy(135,75,"CASINO");

	setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setlinestyle(0,0,3);
	setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setcolor(WHITE);
	rectangle(50,220,590,420);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(100,270,300,370);
	bar(350,270,550,370);
	setcolor(WHITE);
	rectangle(100,270,300,370);
	rectangle(350,270,550,370);
	setcolor(BLACK);
	settextstyle(3,0,3);
	outtextxy(120,300,"MANAGEMENT");
	outtextxy(410,300,"SERVICE");
	setcolor(WHITE);
	outtextxy(30,430,"Help : Use the Tab Key to go to the Previous Menu");
	//x and y already declared
	setcolor(GREEN);
	rectangle(x,y,x+200,y+100);
	while(kbhit)
	{       key=getch();
		switch(key)
		{	case 77:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x+=250;
				if(x>350)
					x=100;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
			case 75:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x-=250;
				if(x<100)
					x=350;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
			case 9:
				return -1;
		}
		if(key==13)break;
	}
	return x;
}
int selectgame()
{       cleardevice();
	border();

	setfillstyle(SOLID_FILL,BLACK);
	bar(20,20,600,400);
	setcolor(MAGENTA);
	settextstyle(4,0,9);
	outtextxy(125,75,"GAMES");

	setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setlinestyle(0,0,3);
	setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setcolor(WHITE);
	rectangle(50,220,590,420);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(100,270,300,370);
	bar(350,270,550,370);
	setcolor(WHITE);
	rectangle(100,270,300,370);
	rectangle(350,270,550,370);
	setcolor(BLACK);
	settextstyle(3,0,3);
	outtextxy(140,300,"ROULETTE");
	outtextxy(400,300,"BACCARAT");
	setcolor(WHITE);
	outtextxy(30,430,"Help : Use the Tab Key to go to the Previous Menu");

	int key,x=100;
	const y=270;
	setcolor(GREEN);
	rectangle(x,y,x+200,y+100);
	while(kbhit)
	{       key=getch();
		switch(key)
		{	case 77:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x+=250;
				if(x>350)
					x=100;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
			case 75:
				setcolor(WHITE);
				rectangle(x,y,x+200,y+100);

				x-=250;
				if(x<100)
					x=350;
				setcolor(GREEN);
				rectangle(x,y,x+200,y+100);
				break;
			case 9:
				return -1;
		}
		if(key==13)break;
	}
	return x;
}
int password()
{       setfillstyle(SOLID_FILL,BLUE);
	bar(50,220,590,420);
	setcolor(GREEN);
	settextstyle(3,0,4);
	outtextxy(210,250,"Enter Password ");
	char word[9]="        ",fi_password[9]="        ";
	settextstyle(3,0,5);
	for(int counter=0;counter<8;counter++)
	{	word[counter]=getch();
		if(word[counter]<33||word[counter]>126)
		{      if(word[counter]==13)
		       {	word[counter]='\0';
				break;
		       }
		       counter--;
		       continue;
		}
		outtextxy((280+(12*counter)),310,"*");
	}

	ifstream fi;
	fi.open("manage.txt",ios::nocreate);
	fi>>fi_password;
	if(strcmp(fi_password,word)==0)
	{	return 0;
	}
	else
	{       setfillstyle(SOLID_FILL,BLUE);
		bar(50,220,590,420);
		settextstyle(3,0,6);
		outtextxy(140,280,"Wrong Password");
		getch();
		return 1;
	}

}
void main()
{	int driver = DETECT, mode= DETECT;
	initgraph(&driver, &mode, "C:\\TURBOC3\\BGI");
	cleardevice();
	int check;
	do{
		check=0;
		border();
		display();
		temp:
		switch(front())
		{       case 100:
				if(password())
					goto temp;
				check=management();
				break;
			case 350:
				check=service();
				break;
			case -1:
				check=-1;
		}
	}while(check==-1);
	for(;;)
	{       switch(selectgame())
		{	case 100:
				roulette();
				break;
			case 350:
				baccarat();
				break;
			case -1:
				goto temp;
		}
	}
}