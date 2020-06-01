#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//----------background color (orange)---------//
#define BG textbackground(6)
//----------textcolor----------------//
#define TC textcolor
//----------text background color----------//
#define BC textbackground(15)


//----------structure definition-------------//
struct daily_expenses
{
	int id;
	float amount,taxrate,tamount;
	char date[12],category[30],name[30];
}expenses;
//------------structure end---------------//

//-------first user interface-------------//
void first_ui();
//--------user interface function---------//
void user_interface();
//--------add expenses details------------//
void add();
//--------expense id counter--------------//
int expense_id();
//--------view expense details------------//
void view_details();
//--------define new categories-----------//
void define_category();
//---------see defined categories---------//
void view_categories();
//---------modify expense details---------//
void modify_details();
//---------Total Expenditure-------------//
void total_exp();
//---------annual expenditure-----------//
void total_exp_ui();
//-----total expenditure details-------//
void total_exp_details(char cate[],int count);
//------------void login -------------//
void login();
//------------sign up---------------//
void sign_up();
//------------password questions------------//
char* question();
//------------password answer--------------//
void answer();
//-------------last record------------//
void last_record(int rec_id);
//-------------orange----------------//
void orange();


//-----------global variables-------------//
int i,j,modify=0;
char c,cate[25],cate1[25],ans,username[25],ext[]=".txt",answ[20];
FILE *fp,*p,*fpp,*pp;


//void main()
//{
  //	first_ui();
//}

//------------orange--------------//
void orange()
{
	for(i=0;i<18;i++)
	{
		textbackground(6);
		for(j=0;j<44;j++)
		{
			gotoxy(35+j,5+i);
			cprintf(" ");
		}
	}
}

//------------first user interface--------------//
void first_ui()
{
	int l=0;
	textbackground(15);
	clrscr();
	gotoxy(67,24);
	TC(1);
	cprintf("Created by:");
	gotoxy(67,25);
	cprintf("Vinit Tekwani");
	for(i=0;i<11;i++,l++)
	{
		textbackground(4);
		for(j=0;j<34;j++)
		{
			gotoxy(25+j,8+i);
			cprintf(" ");
		}
	}
	for(i=0;i<9;i++)
	{
		textbackground(15);
		for(j=0;j<30;j++)
		{
			gotoxy(27+j,9+i);
			cprintf(" ");
		}
	}
	TC(4);
	gotoxy(34,10);
	cprintf("Welcome to Daily\n");
	gotoxy(30,12);
	cprintf("Expenses Record Manager");
	gotoxy(30,15);
	TC(2);
	cprintf("L");
	TC(4);
	cprintf("ogin");
	gotoxy(48,15);
	TC(2);
	cprintf("S");
	TC(4);
	cprintf("ign Up");
	gotoxy(40,17);
	TC(2);
	cprintf("E");
	TC(4);
	cprintf("xit");
	again:
	c=getch();
	if(c=='E'||c=='e')
	{
		exit(0);
	}
	else if(c=='L'||c=='l')
	{
		login();
	}
	else if(c=='S'||c=='s')
	{
		sign_up();
	}
	first_ui();
}

//------------sign up--------------//
void sign_up()
{
	char password[15],cate3[60],cate4[15];
	gotoxy(67,24);
	TC(1);
	cprintf("Created by:");
	gotoxy(67,25);
	cprintf("Vinit Tekwani");
	fp=fopen("username.txt","a+");
	TC(4);
	for(i=0;i<11;i++)
	{
		textbackground(4);
		for(j=0;j<36;j++)
		{
			gotoxy(25+j,8+i);
			cprintf(" ");
		}
	}
	for(i=0;i<9;i++)
	{
		textbackground(15);
		for(j=0;j<32;j++)
		{
			gotoxy(27+j,9+i);
			cprintf(" ");
		}
	}
	gotoxy(34,9);
	TC(6);
	cprintf("Sign Up Interface");
	TC(15);
	gotoxy(28,11);
	cprintf("Enter Username = ");
	scanf("%s",&username);
	TC(15);
	gotoxy(28,13);
	cprintf("Enter password = ");
	i=0;
	while(1)
	{
		TC(4);
		wagain:
		password[i]=getch();
		if(password[i]==8)
		{
			cprintf("\b \b");
			i=-1;
			goto wagain;
		}
		if(password[i]==13)
			break;
		cprintf("*");
		i++;
	}
	password[i]='\0';
	i=1;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t%s\t%s\t%[^\n]s\n",cate,cate1,cate4,cate3);
		if(!strcmp(cate,username))
			i=0;
		if(i==0)
			break;
	}
	if(i==0)
	{
		gotoxy(32,15);
		TC(2);
		cprintf("Username Already Exists");
		fclose(fp);
		gotoxy(28,17);
		TC(1);
		cprintf("B");
		TC(15);
		cprintf("ack");
		goto out;
	}
	strcpy(cate,question());
	fprintf(fp,"%s\t%s\t%s\t%s\n",username,password,answ,cate);
	strcat(username,ext);
	fpp=fopen(username,"w");
	fclose(fpp);
	fclose(fp);
	gotoxy(34,15);
	TC(2);
	cprintf("Sign up Successfully");
	gotoxy(28,18);
	TC(1);
	cprintf("C");
	TC(15);
	cprintf("ontinue");
	out:
	gotoxy(54,17);
	TC(1);
	cprintf("E");
	TC(15);
	cprintf("xit");
	again:
	c=getch();
	if(c=='c'||c=='C'&&i==1)
	{
		user_interface();
	}
	else if(c=='E'||c=='e')
	{
		exit(0);
	}
	else if(c=='B'||c=='b'&&i==0)
	{
		first_ui();
	}
	else
	{
		goto again;
	}
}


//-------------password questions------------------//
char* question()
{
	char *ques[3]={"Tell me your Nickname","Tell me your Cursh name","Tell me your Lowest %"};
	TC(4);
	for(i=0;i<12;i++)
	{
		textbackground(4);
		for(j=0;j<36;j++)
		{
			gotoxy(25+j,8+i);
			cprintf(" ");
		}
	}
	for(i=0;i<10;i++)
	{
		textbackground(15);
		for(j=0;j<32;j++)
		{
			gotoxy(27+j,9+i);
			cprintf(" ");
		}
	}
	gotoxy(29,9);
	TC(4);
	cprintf("In case you forgot password ");
	gotoxy(28,11);
	TC(2);
	cprintf("1");
	TC(6);
	cprintf(".%s",ques[0]);
	gotoxy(28,13);
	TC(2);
	cprintf("2");
	TC(6);
	cprintf(".%s",ques[1]);
	gotoxy(28,15);
	TC(2);
	cprintf("3");
	TC(6);
	cprintf(".%s",ques[2]);
	gotoxy(32,17);
	TC(15);
	cprintf("Press Question Number ");
	textagain:
	c=getch();
	if(c!='1'&&c!='2'&&c!='3')
		goto textagain;
	for(i=0;i<9;i++)
	{
		textbackground(15);
		for(j=0;j<32;j++)
		{
			gotoxy(27+j,10+i);
			cprintf(" ");
		}
	}
	TC(2);
	gotoxy(28,11);
	cprintf("Q. ");
	j=c-48;
	cprintf("%s",ques[j-1]);
	TC(4);
	gotoxy(28,13);
	cprintf("Ans. ");
	i=0;
	while(1)
	{
		wagain:
		answ[i]=getch();
		if(answ[i]==8)
		{
			cprintf("\b \b");
			i=-1;
			goto wagain;
		}
		if(answ[i]==13)
			break;
		cprintf("*");
		i++;
	}
	answ[i]='\0';
	return(ques[j-1]);
}



//------------login--------------//
void login()
{
	char password[15],cate3[60],cate4[15];
	gotoxy(67,24);
	TC(1);
	cprintf("Created by:");
	gotoxy(67,25);
	cprintf("Vinit Tekwani");
	fp=fopen("username.txt","r+");
	TC(4);
	for(i=0;i<12;i++)
	{
		textbackground(4);
		for(j=0;j<36;j++)
		{
			gotoxy(25+j,8+i);
			cprintf(" ");
		}
	}
	for(i=0;i<10;i++)
	{
		textbackground(15);
		for(j=0;j<32;j++)
		{
			gotoxy(27+j,9+i);
			cprintf(" ");
		}
	}
	gotoxy(35,9);
	TC(6);
	cprintf("Login Interface");
	TC(15);
	gotoxy(28,11);
	cprintf("Enter Username = ");
	scanf("%s",&username);
	j=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t%s\%s\t%[^\n]s\n",&cate,&password,&cate4,&cate3);
		if(!strcmp(username,cate))
			j=1;
	}
	fclose(fp);
	fp=fopen("username.txt","r+");
	TC(15);
	gotoxy(28,13);
	cprintf("Enter password = ");
	i=0;
	while(1)
	{
		TC(4);
		wagain:
		password[i]=getch();
		if(password[i]==8)
		{
			cprintf("\b \b");
			i-=1;
			goto wagain;
		}
		if(password[i]==13)
			break;
		cprintf("*");
		i++;
	}
	password[i]='\0';
	i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t%s\t%s\t%[^\n]s\n",&cate,&cate1,&cate4,&cate3);
		if(!strcmp(cate,username)&&!strcmp(cate1,password))
		{
			i=1;
		}
		if(i==1)
			break;
	}
	fclose(fp);
	if(i==0)
	{
		gotoxy(29,15);
		TC(2);
		cprintf("Invalid Username or Password");
		(j==1)?gotoxy(46,17):gotoxy(28,18);
		TC(1);
		cprintf("B");
		TC(15);
		cprintf("ack");
	}
	else
	{
		gotoxy(34,15);
		TC(2);
		cprintf("Login Successfully");
		gotoxy(28,18);
		TC(1);
		cprintf("C");
		TC(15);
		cprintf("ontinue");
		strcat(username,ext);
	}
	if(j==1&&i==0)
	{
		gotoxy(28,18);
		TC(1);
		cprintf("F");
		TC(15);
		cprintf("orgot Password");
	}
	gotoxy(54,18);
	TC(1);
	cprintf("E");
	TC(15);
	cprintf("xit");
	again:
	c=getch();
	if(c=='c'||c=='C'&&i==1)
	{
		user_interface();
	}
	else if(c=='F'||c=='f'&&j==1)
	{
		answer();
	}
	else if(c=='E'||c=='e')
	{
		exit(0);
	}
	else if(c=='B'||c=='b'&&i==0)
	{
		first_ui();
	}
	else
		goto again;
}


//------------password answer------------//
void answer()
{
	char cate3[60],cate4[15],password[10];
	for(i=0;i<12;i++)
	{
		textbackground(4);
		for(j=0;j<36;j++)
		{
			gotoxy(25+j,8+i);
			cprintf(" ");
		}
	}
	for(i=0;i<10;i++)
	{
		textbackground(15);
		for(j=0;j<32;j++)
		{
			gotoxy(27+j,9+i);
			cprintf(" ");
		}
	}
	gotoxy(32,9);
	TC(6);
	cprintf("Forgot Password Interface");
	TC(15);
	i=0;
	fpp=fopen("username.txt","r+");
	while(!feof(fpp))
	{
		fscanf(fpp,"%s\t%s\t%s\t%[^\n]s\n",&cate,&cate1,&cate4,&cate3);
		if(!strcmp(username,cate))
			i=1;
		if(i==1)
			break;
	}
	fclose(fpp);
	TC(2);
	gotoxy(28,11);
	cprintf("Q.%s",cate3);
	gotoxy(28,13);
	TC(4);
	cprintf("Ans.");
	i=0;
	while(1)
	{
		wagain:
		answ[i]=getch();
		if(answ[i]==8)
		{
			cprintf("\b \b");
			i-=1;
			goto wagain;
		}
		if(answ[i]==13)
			break;
		cprintf("*");
		i++;
	}
	answ[i]='\0';
	if(!strcmp(answ,cate4))
	{
		for(i=0;i<9;i++)
		{
			textbackground(15);
			for(j=0;j<32;j++)
			{
				gotoxy(27+j,10+i);
				cprintf(" ");
			}
		}
	}
	else
	{
		gotoxy(38,15);
		TC(4);
		cprintf("Wrong Answer");
		goto exit;
	}
	gotoxy(28,11);
	TC(2);
	cprintf("1");
	TC(4);
	cprintf(".See Existing Password");
	gotoxy(28,13);
	TC(2);
	cprintf("2");
	TC(4);
	cprintf(".Change Password");
	gotoxy(33,15);
	TC(15);
	cprintf("Press Option Number ");
	textagain:
	c=getch();
	if(c=='1')
	{
		for(i=0;i<9;i++)
		{
			textbackground(15);
			for(j=0;j<32;j++)
			{
				gotoxy(27+j,10+i);
				cprintf(" ");
			}
		}
		gotoxy(28,13);
		TC(2);
		cprintf("Password = ");
		TC(4);
		cprintf("%s",cate1);
	}
	else if(c=='2')
	{
		for(i=0;i<9;i++)
		{
			textbackground(15);
			for(j=0;j<32;j++)
			{
				gotoxy(27+j,10+i);
				cprintf(" ");
			}
		}
		gotoxy(28,12);
		TC(2);
		cprintf("Type new Password = ");
		i=0;
		TC(4);
		while(1)
		{
			wagai:
			password[i]=getch();
			if(password[i]==8)
			{
				cprintf("\b \b");
				i-=1;
				goto wagai;
			}
			if(password[i]==13)
				break;
			if(i<=8)
				cprintf("*"),i++;
		}
		password[i]='\0';
		fpp=fopen("username.txt","r+");
		fp=fopen("temp.txt","a+");
		while(fscanf(fpp,"%s\t%s\t%s\t%[^\n]s\n",&cate,&cate1,&cate4,&cate3)>0)
		{

			if(!strcmp(cate,username))
				fprintf(fp,"%s\t%s\t%s\t%s\n",cate,password,cate4,cate3);
			else
				fprintf(fp,"%s\t%s\t%s\t%s\n",cate,cate1,cate4,cate3);
		}
		fclose(fp);
		fclose(fpp);
		remove("username.txt");
		rename("temp.txt","username.txt");
		gotoxy(28,15);
		TC(2);
		cprintf("Password Changed Successfully");
	}
	else
		goto textagain;
	exit:
	gotoxy(28,18);
	TC(1);
	cprintf("M");
	TC(15);
	cprintf("enu");
	gotoxy(54,18);
	TC(1);
	cprintf("E");
	TC(15);
	cprintf("xit");
	c=getch();
	if(c=='E'||c=='e')
		exit(0);
	else if(c=='M'||c=='m')
		return;
	else
		goto exit;
}

//---------user interface----------//
void user_interface()
{
	int rec_id,temp;
	rec_id=expense_id()-1;
	temp=rec_id;
	choice_menu:
	BG;
	clrscr();
	gotoxy(67,24);
	TC(11);
	cprintf("Created by:");
	gotoxy(67,25);
	cprintf("Vinit Tekwani");
	for(i=0;i<21;i++)
	{
		BC;
		for(j=0;j<25;j++)
		{
			gotoxy(2+j,3+i);
			cprintf(" ");
		}
	}
	j=4;
	gotoxy(j,4);
	TC(2);
	cprintf("A");
	TC(4);
	cprintf("dd Expense Detail");
	gotoxy(j,7);
	TC(2);
	cprintf("V");
	TC(4);
	cprintf("iew Expense Details");
	gotoxy(j,10);
	TC(2);
	cprintf("D");
	TC(4);
	cprintf("efine a new Category");
	gotoxy(j,13);
	TC(2);
	cprintf("S");
	TC(4);
	cprintf("ee Defined Categories");
	gotoxy(j,16);
	TC(2);
	cprintf("M");
	TC(4);
	cprintf("odify Expense Details");
	gotoxy(j,19);
	TC(2);
	cprintf("T");
	TC(4);
	cprintf("otal Expenditure");
	gotoxy(j,22);
	TC(2);
	cprintf("L");
	TC(4);
	cprintf("og Out");
	call_last_record:
	if(rec_id>=0)
		last_record(rec_id);
	if(rec_id<temp)
	{
		TC(1);
		gotoxy(74,22);
		cprintf("N");
		TC(15);
		cprintf("ext");
	}
	if(rec_id>0)
	{
		TC(1);
		gotoxy(36,22);
		cprintf("P");
		TC(15);
		cprintf("revious");
	}
	TC(4);
	c=getch();
	if(c=='a'||c=='A')
	{
		add();
	}
	else if(c=='V'||c=='v')
	{
		view_details();
	}
	else if(c=='D'||c=='d')
	{
		define_category();
	}
	else if(c=='S'||c=='s')
	{
		view_categories();
	}
	else if(c=='M'||c=='m')
	{
		modify_details();
	}
	else if(c=='T'||c=='t')
	{
		total_exp_ui();
	}
	else if(c=='L'||c=='l')
	{
		first_ui();
	}
	else if(c=='N'||c=='n'&&rec_id<temp)
	{
		rec_id++;
		goto call_last_record;
	}
	else if(c=='P'||c=='p'&&rec_id>0)
	{
		rec_id--;
		goto call_last_record;
	}
	goto choice_menu;
}
//----------user interface end------------//

//-----------last record---------------//
void last_record(int rec_id)
{
	if(rec_id<=0)
	{
		for(i=0;i<18;i++)
		{
			textbackground(11);
			for(j=0;j<44;j++)
			{
				gotoxy(35+j,5+i);
				cprintf(" ");
			}
		}
		TC(0);
		gotoxy(48,13);
		cprintf("No Records to Show");
		TC(4);
	}
	else
	{
		fp=fopen(username,"r+");
		i=0;
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&expenses.id,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
			if(rec_id==expenses.id)
				i=1;
			if(i==1)
				break;
		}
		fclose(fp);
		for(i=0;i<18;i++)
		{
			textbackground(11);
			for(j=0;j<44;j++)
			{
				gotoxy(35+j,5+i);
				cprintf(" ");
			}
		}
		TC(15);
		gotoxy(41,5);
		cprintf("--------%d Expense Details-------",rec_id);
		//----------expense id--------------//
		gotoxy(36,7);
		cprintf("Expense id = ");
		TC(4);
		cprintf("%d",expenses.id);
		//----------enter category---------//
		TC(15);
		gotoxy(36,9);
		cprintf("Expense Category = ");
		TC(4);
		cprintf("%s",expenses.category);
		//----------enter expense name----------//
		TC(15);
		gotoxy(36,11);
		cprintf("Product Name = ");
		TC(4);
		cprintf("%s",expenses.name);
		//-----------enter date---------------//
		TC(15);
		gotoxy(36,13);
		cprintf("Expense date(dd-mm-yyyy) = ");
		TC(4);
		cprintf("%s",expenses.date);
		//----------enter amount-----------//
		TC(15);
		gotoxy(36,15);
		cprintf("Expense amount(before tax) = ");
		TC(4);
		cprintf("%.3f",expenses.amount);
		//----------enter tax rate------------//
		TC(15);
		gotoxy(36,17);
		cprintf("Expense tax rate = ");
		TC(4);
		cprintf("%.3f%",expenses.taxrate);
		//-----------total amount--------------//
		TC(15);
		gotoxy(36,19);
		cprintf("Amount after tax = ");
		TC(4);
		cprintf("%.3f",expenses.tamount);
	}
}


//----------add expenses details-----------//
void add()
{
	for(i=0;i<18;i++)
	{
		textbackground(11);
		for(j=0;j<44;j++)
		{
			gotoxy(35+j,5+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(40,5);
	//----------expense id--------------//
	if(modify==0)
	{
		cprintf("-------Fill Expense Details------");
		expenses.id=expense_id();
	}
	else
	{
		gotoxy(39,5);
		cprintf("-------Modify Expense Details-------");
	}
	gotoxy(36,7);
	cprintf("Expense id = ");
	TC(4);
	cprintf("%d",expenses.id);
	//----------enter category---------//
	TC(15);
	gotoxy(36,9);
	cprintf("Enter Category = ");
	TC(4);
	scanf("%s",&cate1);
	i=0;
	fpp=fopen("categories.txt","r");
	while(!feof(fpp))
	{
	       fscanf(fpp,"%s\n",&cate);
	       if(!strcmp(cate,cate1))
	       {
			i=1;
			goto out;
	       }
	}
	out:
	fclose(fpp);
	if(i==0)
	{
		gotoxy(46,12);
		TC(0);
		cprintf("Category not Defined");
		modify=0;
		TC(1);
		gotoxy(36,22);
		cprintf("M");
		TC(15);
		cprintf("enu");
		TC(4);
		agan:
		c=getch();
		if(c=='m'||c=='M')
			return;
		else
			goto agan;
	}
	strcpy(expenses.category,cate1);
	//----------enter expense name----------//
	TC(15);
	gotoxy(36,11);
	cprintf("Enter Product Name = ");
	TC(4);
	scanf("%s",&expenses.name);
	//-----------enter date---------------//
	TC(15);
	gotoxy(36,13);
	cprintf("Enter date(dd-mm-yyyy) = ");
	TC(4);
	scanf("%s",&expenses.date);
	//----------enter amount-----------//
	TC(15);
	gotoxy(36,15);
	cprintf("Enter amount(before tax) = ");
	TC(4);
	scanf("%f",&expenses.amount);
	//----------enter tax rate------------//
	TC(15);
	gotoxy(36,17);
	cprintf("Enter tax rate = ");
	TC(4);
	scanf("%f",&expenses.taxrate);
	//-----------total amount--------------//
	expenses.tamount=expenses.taxrate/100;
	expenses.tamount=expenses.tamount*expenses.amount;
	expenses.tamount=expenses.tamount+expenses.amount;
	TC(15);
	gotoxy(36,19);
	cprintf("Amount after tax = ");
	TC(4);
	cprintf("%.3f",expenses.tamount);
	//------------save-------------//
	gotoxy(36,22);
	TC(1);
	cprintf("S");
	TC(15);
	cprintf("ave Detail");
	//------------dont save-----------//
	TC(1);
	gotoxy(68,22);
	cprintf("D");
	TC(15);
	cprintf("on't save");
	again:
	if(modify>0)
		return;
	c=getch();
	if(c=='S'||c=='s')
	{
		//-----------writing in file--------------//
		fp=fopen(username,"a+");
		fprintf(fp,"%d\t%s\t%s\t%s\t%.3f\t%.3f\t%.3f\n",expenses.id,expenses.category,expenses.name,expenses.date,expenses.amount,expenses.taxrate,expenses.tamount);
		fclose(fp);
	}
	else if(c=='D'||c=='d')
		return;
	else
		goto again;
}

//--------------id detection----------------//
int expense_id()
{
	int idcount=0,s=0;
	fp=fopen(username,"a+");
	while(!feof(fp))
	{
		s++;
		fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&idcount,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
	}
	fclose(fp);
	if(s==0)
		return(1);
	else
		return(idcount+1);
}

//---------------view expense details-------------//
void view_details()
{
	int sid;
	orange();
	for(i=0;i<6;i++)
	{
		textbackground(11);
		for(j=0;j<35;j++)
		{
			gotoxy(39+j,11+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(41,11);
	if(modify==1)
		cprintf("-----Modify Expense Detail-----");
	else
		cprintf("------View Expense Detail------");
	gotoxy(40,13);
	cprintf("Enter Expense ID = ");
	scanf("%d",&sid);
	if(sid>expense_id()-1)
	{
		in:
		gotoxy(48,15);
		TC(0);
		cprintf("Invalid Expense ID");
		modify=0;
		TC(1);
		gotoxy(40,16);
		cprintf("M");
		TC(15);
		cprintf("enu");
		TC(4);
		agan:
		c=getch();
		if(c=='m'||c=='M')
			return;
		else
			goto agan;
	}
	else
	{
		fp=fopen(username,"r+");
		i=0;
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&expenses.id,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
			if(sid==expenses.id)
				i=1;
			if(i==1)
				break;
		}
		fclose(fp);
		if(i==0)
			goto in;
		for(i=0;i<18;i++)
		{
			textbackground(11);
			for(j=0;j<44;j++)
			{
				gotoxy(35+j,5+i);
				cprintf(" ");
			}
		}
		if(modify==1)
		{
			modify=sid;
			return;
		}
		TC(15);
		gotoxy(41,5);
		cprintf("--------%d Expense Details-------",sid);
		//----------expense id--------------//
		gotoxy(36,7);
		cprintf("Expense id = ");
		TC(4);
		cprintf("%d",expenses.id);
		//----------enter category---------//
		TC(15);
		gotoxy(36,9);
		cprintf("Expense Category = ");
		TC(4);
		cprintf("%s",expenses.category);
		//----------enter expense name----------//
		TC(15);
		gotoxy(36,11);
		cprintf("Product Name = ");
		TC(4);
		cprintf("%s",expenses.name);
		//-----------enter date---------------//
		TC(15);
		gotoxy(36,13);
		cprintf("Expense date(dd-mm-yyyy) = ");
		TC(4);
		cprintf("%s",expenses.date);
		//----------enter amount-----------//
		TC(15);
		gotoxy(36,15);
		cprintf("Expense amount(before tax) = ");
		TC(4);
		cprintf("%.3f",expenses.amount);
		//----------enter tax rate------------//
		TC(15);
		gotoxy(36,17);
		cprintf("Expense tax rate = ");
		TC(4);
		cprintf("%.3f%",expenses.taxrate);
		//-----------total amount--------------//
		TC(15);
		gotoxy(36,19);
		cprintf("Amount after tax = ");
		TC(4);
		cprintf("%.3f",expenses.tamount);
	}
	TC(1);
	gotoxy(36,22);
	cprintf("M");
	TC(15);
	cprintf("enu");
	TC(4);
	again:
	c=getch();
	if(c=='m'||c=='M')
		return;
	else
		goto again;
}

//----------define new ctegories-------------//
void define_category()
{
	orange();
	for(i=0;i<6;i++)
	{
		textbackground(11);
		for(j=0;j<39;j++)
		{
			gotoxy(39+j,11+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(44,11);
	cprintf("------Define Categories------");
	gotoxy(40,13);
	cprintf("Enter Category  = ");
	scanf("%s",&cate);
	fp=fopen("categories.txt","a+");
	i=1;
	while(!feof(fp))
	{
	       fscanf(fp,"%s\n",&expenses.category);
	       if(!strcmp(cate,expenses.category))
	       {
			i=0;
			goto out;
	       }
	}
	out:
	if(i==0)
	{
		gotoxy(46,15);
		TC(0);
		cprintf("Category Already Defined");
	}
	else
	{
		fprintf(fp,"%s\n",cate);
		gotoxy(44,15);
		TC(15);
		cprintf("Category Defined Successfully");
	}
	fclose(fp);
	TC(1);
	gotoxy(40,16);
	cprintf("M");
	TC(15);
	cprintf("enu");
	TC(4);
	again:
	c=getch();
	if(c=='m'||c=='M')
		return;
	else
		goto again;
}

//------------see defined categories------------//
void view_categories()
{
	orange();
	for(i=0;i<16;i++)
	{
		textbackground(11);
		for(j=0;j<30;j++)
		{
			gotoxy(39+j,6+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(41,6);
	cprintf("----Defined Categories----");
	fp=fopen("categories.txt","r+");
	i=0,j=8;
	while(!feof(fp))
	{
		TC(4);
		fscanf(fp,"%s\n",&cate);
		gotoxy(47,j+i);
		cprintf("%s Category",cate);
		i+=2;
		if(i==14)
		{
			TC(1);
			gotoxy(40,21);
			cprintf("M");
			TC(15);
			cprintf("enu");
			TC(1);
			gotoxy(64,21);
			cprintf("N");
			TC(15);
			cprintf("ext");
			TC(4);
			agan:
			c=getch();
			if(c=='m'||c=='M')
			{
				fclose(fp);
				return;
			}
			else if(c!='N'&&c!='n')
				goto agan;
			for(i=0;i<16;i++)
			{
				textbackground(11);
				for(j=0;j<30;j++)
				{
					gotoxy(39+j,6+i);
					cprintf(" ");
				}
			}
			j=8,i=0;
			TC(15);
			gotoxy(41,6);
			cprintf("----Defined Categories----");
		}
	}
	fclose(fp);
	TC(1);
	gotoxy(40,21);
	cprintf("M");
	TC(15);
	cprintf("enu");
	TC(4);
	again:
	c=getch();
	if(c=='m'||c=='M')
		return;
	else
		goto again;
}

//---------modify expense details----------//
void modify_details()
{
	orange();
	modify=1;
	view_details();
	if(modify>0)
	{
		fp=fopen(username,"r");
		pp=fopen("temp.txt","w");
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&expenses.id,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
			if(modify==expenses.id)
			{
				TC(4);
				add();
				if(modify==0)
					goto els;
				c=getch();
				if(c=='D'||c=='d')
				{
					fclose(pp);
					remove("temp.txt");
					fclose(fp);
					modify=0;
					return;
				}
				else if(c=='S'||c=='s')
				{
					fprintf(pp,"%d\t%s\t%s\t%s\t%.3f\t%.3f\t%.3f\n",expenses.id,expenses.category,expenses.name,expenses.date,expenses.amount,expenses.taxrate,expenses.tamount);
				}
			}
			else
			{
				els:
				fprintf(pp,"%d\t%s\t%s\t%s\t%.3f\t%.3f\t%.3f\n",expenses.id,expenses.category,expenses.name,expenses.date,expenses.amount,expenses.taxrate,expenses.tamount);
			}
		}
		fclose(pp);
		fclose(fp);
		remove(username);
		rename("temp.txt",username);
		modify=0;
	}
}

//---------Total Expenditure user interface-------------//
void total_exp_ui()
{
	orange();
	for(i=0;i<6;i++)
	{
		textbackground(11);
		for(j=0;j<29;j++)
		{
			gotoxy(39+j,11+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(40,11);
	cprintf("-----Total Expenditure-----");
	//--------Anual expenditure---------//
	gotoxy(45,13);
	TC(4);
	cprintf("A");
	TC(15);
	cprintf("nnual Expenditure");
	//--------Monthly expenditure---------//
	gotoxy(45,14);
	TC(4);
	cprintf("M");
	TC(15);
	cprintf("onthly Expenditure");
	//--------Anual expenditure---------//
	gotoxy(45,15);
	TC(4);
	cprintf("P");
	TC(15);
	cprintf("articular Date");
	TC(4);
	ans=getch();
	if(ans=='A'||ans=='a'||ans=='M'||ans=='m'||ans=='P'||ans=='p')
	{
		total_exp();
	}
}

//--------Total expenditure-----------//
void total_exp()
{
	char temp[6];
	int t,count=0;
	float sum=0;
	for(i=0;i<6;i++)
	{
		textbackground(11);
		for(j=0;j<31;j++)
		{
			gotoxy(39+j,11+i);
			cprintf(" ");
		}
	}
	TC(15);
	//--------annual----------//
	if(ans=='A'||ans=='a')
	{
		gotoxy(42,11);
		cprintf("---Annual Expenditure---");
		gotoxy(40,14);
		cprintf("Enter Year = ");
		scanf("%s",&cate);
	}
	//--------Monthly--------//
	else if(ans=='M'||ans=='m')
	{
		gotoxy(42,11);
		cprintf("---Monthly Expenditure---");
		gotoxy(40,13);
		cprintf("Enter Month = ");
		scanf("%s",&cate);
		gotoxy(40,15);
		cprintf("Enter Year = ");
		scanf("%s",&cate1);
		i=strlen(cate);
		cate[i]='-';
		cate[i+1]='\0';
		strcat(cate,cate1);
	}
	//--------date wise--------//
	else if(ans=='P'||ans=='p')
	{
		gotoxy(42,11);
		cprintf("-----Particular date-----");
		gotoxy(40,14);
		cprintf("Enter date = ");
		scanf("%s",&cate);
	}
	fp=fopen(username,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&expenses.id,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
		//----------annual-----------//
		if(ans=='A'||ans=='a')
		{
			strcpy(cate1,expenses.date);
			j=0;
			for(i=(strlen(cate1)-4);j<4;i++,j++)
				temp[j]=cate1[i];
			temp[j]='\0';
		}
		//----------particular date------------//
		else if(ans=='P'||ans=='p')
		{
			strcpy(temp,expenses.date);
		}
		//----------Monthly-----------------//
		else if(ans=='M'||ans=='m')
		{
			j=0,t=0;
			for(i=0;i<strlen(expenses.date);i++)
			{
				if(t==1)
				{
					temp[j]=expenses.date[i];
					j++;
					continue;
				}
				if(expenses.date[i]=='-')
					 t=1;
			}
			temp[j]='\0';
		}
		if(!strcmp(temp,cate))
		{
			sum=sum+expenses.tamount;
			count++;
		}
	}
	fclose(fp);
	for(i=0;i<6;i++)
	{
		textbackground(11);
		for(j=0;j<31;j++)
		{
			gotoxy(39+j,11+i);
			cprintf(" ");
		}
	}
	TC(15);
	gotoxy(41,11);
	cprintf("-----Total Expenditure-----");
	if(count>0)
	{
		TC(15);
		gotoxy(40,14);
		cprintf("Total Expenditure = ");
		TC(4);
		cprintf("%.3f",sum);
		TC(1);
		gotoxy(62,16);
		cprintf("D");
		TC(15);
		cprintf("etails");
		TC(4);

	}
	if(count==0)
	{
		TC(0);
		gotoxy(45,14);
		cprintf("Record Not exists");
	}
	TC(1);
	gotoxy(40,16);
	cprintf("M");
	TC(15);
	cprintf("enu");
	agan:
	c=getch();
	if(c=='m'||c=='M')
		user_interface();
	else if(c=='d'||c=='D'&&count!=0)
		total_exp_details(cate,count);
	else
		goto agan;
}

//-------------total expenditure details--------------//
void total_exp_details(char cate[],int count)
{
	char temp[10];
	int t=0;
	fp=fopen(username,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%d\t%s\t%s\t%s\t%f\t%f\t%f\n",&expenses.id,&expenses.category,&expenses.name,&expenses.date,&expenses.amount,&expenses.taxrate,&expenses.tamount);
		//----------annual-----------//
		if(ans=='A'||ans=='a')
		{
			strcpy(cate1,expenses.date);
			j=0;
			for(i=(strlen(cate1)-4);j<4;i++,j++)
				temp[j]=cate1[i];
			temp[j]='\0';
		}
		//----------particular date------------//
		else if(ans=='P'||ans=='p')
		{
			strcpy(temp,expenses.date);
		}
		//----------Monthly-----------------//
		else if(ans=='M'||ans=='m')
		{
			j=0,t=0;
			for(i=0;i<strlen(expenses.date);i++)
			{
				if(t==1)
				{
					temp[j]=expenses.date[i];
					j++;
					continue;
				}
				if(expenses.date[i]=='-')
					 t=1;
			}
			temp[j]='\0';
		}
		if(!strcmp(temp,cate))
		{
			count--;
			for(i=0;i<18;i++)
			{
				textbackground(11);
				for(j=0;j<44;j++)
				{
					gotoxy(35+j,5+i);
					cprintf(" ");
				}
			}
			TC(15);
			gotoxy(39,5);
			cprintf("-------Expense Details------");
			//----------expense id--------------//
			gotoxy(36,7);
			cprintf("Expense id = ");
			TC(4);
			cprintf("%d",expenses.id);
			//----------enter category---------//
			TC(15);
			gotoxy(36,9);
			cprintf("Expense Category = ");
			TC(4);
			cprintf("%s",expenses.category);
			//----------enter expense name----------//
			TC(15);
			gotoxy(36,11);
			cprintf("Product Name = ");
			TC(4);
			cprintf("%s",expenses.name);
			//-----------enter date---------------//
			TC(15);
			gotoxy(36,13);
			cprintf("Expense date = ");
			TC(4);
			cprintf("%s",expenses.date);
			//----------enter amount-----------//
			TC(15);
			gotoxy(36,15);
			cprintf("Expense amount(before tax) = ");
			TC(4);
			cprintf("%.3f",expenses.amount);
			//----------enter tax rate------------//
			TC(15);
			gotoxy(36,17);
			cprintf("Expense tax rate = ");
			TC(4);
			cprintf("%.3f%",expenses.taxrate);
			//-----------total amount--------------//
			TC(15);
			gotoxy(36,19);
			cprintf("Amount after tax = ");
			TC(4);
			cprintf("%.3f",expenses.tamount);
			TC(1);
			gotoxy(36,22);
			cprintf("M");
			TC(15);
			cprintf("enu");
			TC(1);
			if(count>0)
			{
				gotoxy(74,22);
				cprintf("N");
				TC(15);
				cprintf("ext");
			}
			TC(4);
			again:
			c=getch();
			if(c=='m'||c=='M')
			{
				fclose(fp);
				user_interface();
			}
			else if(c!='n'&&c!='N'||count==0)
				goto again;
		}
	}
}
