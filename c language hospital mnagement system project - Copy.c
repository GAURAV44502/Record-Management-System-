#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
/****prototype declaration*****/
void welcome();
void header();
void login();
void menu();
void add();
void list();
void search();
void del();
void left();
/****structure declaration****/
struct patient
{
    int age;
    char firstname[20];
    char lastname[20];
    char contactno[10];
    char gender;
    char address[20];
    char email[50];
    char doctor[20];
    char problem[20];
};
struct patient p;/***structure variable declaration****/
int valid=0,curent=0,meta=0;/****global variable declaration**/
void gotoxy(int x,int y)
{
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int main()
{
    system("color a");
    welcome();/**welcome function calling***/
    header();/**header function calling***/
    login();/**login function calling***/
}
/****welcome function***/
void welcome()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t#################################################");
    printf("\n\t\t\t\t\t\t\t#\t\tWELCOME TO \t\t\t#");
    printf("\n\t\t\t\t\t\t\t#\t\t\t\t\t\t#");
    printf("\n\t\t\t\t\t\t\t# \t SHARMA HOSPITAL MANAGEMENT SYSTEM  \t#");
     printf("\n\t\t\t\t\t\t\t#################################################");
     printf("\n\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\n\n\n\nPress any key to continue..........\n");
    getch();
    system("cls");
}
/****header function*****/
void header()
{
   printf("\n\n\n\n\t\t\t\t\t\t######################################################################");
    printf("\n\t\t\t\t\t\t!!!!!!!!!!!!!!\t\t\t\t\t\t!!!!!!!!!!!!!!");
    printf("\n\t\t\t\t\t\t\t\t\t  SHARMA HOSPITAL");
    printf("\n\t\t\t\t\t\t!!!!!!!!!!!!!!\t\t\t\t\t\t!!!!!!!!!!!!!!");
    printf("\n\t\t\t\t\t\t######################################################################");
}
/****login function****/
void login()
{
    system("color c");
char username[20];
char password[20];
char setusername[20]="gaurav";
char setpassword[20]="44502";
int a=0;
do
{
    printf("\n\n\n\t\t\t\t\t\t\t\tEnter the username and password:...");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tUSERNAME:");
    scanf("%s",&username);
    printf("\n\n\t\t\t\t\t\t\t\t\tPASSWORD:");
     scanf("%s",&password);
     if(strcmp(username,setusername)==0&&strcmp(password,setpassword)==0)
     {
         printf("\n\n\t\t\t\t\t\t\tLOGIN SUCCESSFULLY............");
         getch();
         menu();
         break;
     }
     else
     {
        printf("\n\n\t\t\t\t\t\tINCORRECT USERNAME AND PASSWORD.....!!");
        a++;
        getch();
     }
}
while(a<3);
if(a>=3)
{
    printf("\n\n\t\t\t\t\t\tyou have cross your limit...you cannot login....!!");
    getch();
    exit(0);
}

}
/******menu function*****/
void menu()
{
    system("color a");
system("cls");
header();
    int choose;
    printf("\n\n\n\n\t\t\t\t\t\t\t\t!!!! MAIN MENU!!!!");
    printf("\n\n\n\t\t\t\t\t\t\t\t 1.Add patients record.");
    printf("\n\n\t\t\t\t\t\t\t\t 2.Search patients record.");
    printf("\n\n\t\t\t\t\t\t\t\t 3.List patients record.");
    printf("\n\n\t\t\t\t\t\t\t\t 4.Delete patients record.");
    printf("\n\n\t\t\t\t\t\t\t\t 5.Exit.\n");
    A:
    printf("\n\n\n\n\t\t\t\t\t\t\tChoose from 1 to 6:");
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        list();
        break;
    case 4:
        del();
        break;
    case 5:
            left();
            break;
    default:
        printf("\n\n\t\t\t\t\t\t\tINVALID ENTRY !!PLEASE ENTER CORRECT OPTION");
        goto A;
    }
    getch();

}
/****add function*****/
void add()
{
    system("color b");
    system("cls");
header();
char ya;
int z;
FILE *jk;
jk=fopen("handel.txt","a");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!ADD PATIENTS RECORD!!!!\n");
    /****first-name****/
   B:
   printf("\n\n\t\t\t\t\t\t\t\t\tFIRST-NAME:");
   scanf("%s",p.firstname);
   for(z=0;z<strlen(p.firstname);z++)
   {
       if(isalpha(p.firstname[z]))
       {
           valid=1;
       }
       else
       {
           valid=0;
       }
   }
   if(valid==0)
   {
       printf("\n\t\t\t\t\t\tNAME CONTAINED INVALID CHARACTER.......!!PLEASE ENTER AGAIN...");
       goto B;
   }
/****last-name****/
C:
   printf("\n\n\t\t\t\t\t\t\t\t\tLAST-NAME:");
   scanf("%s",p.lastname);
   for(z=0;z<strlen(p.lastname);z++)
   {
       if(isalpha(p.lastname[z]))
       {
           curent=1;
       }
       else
       {
           curent=0;
       }
   }
   if(curent==0)
   {
       printf("\n\t\t\t\t\t\tNAME CONTAINED INVALID CHARACTER.......!!PLEASE ENTER AGAIN...");
       goto C;
   }
/****age*****/
 printf("\n\n\t\t\t\t\t\t\t\t\tAGE:");
 scanf("%d",&p.age);
 /*****gender*****/
E:
	 fflush(stdin);
  printf("\n\n\t\t\t\t\t\t\t\t\tGENDER[M/F]:");
   scanf("%c",&p.gender);
if((p.gender)=='m'||(p.gender)=='f'||(p.gender)=='F'||(p.gender)=='M')
{
    meta=1;
}
else
{
    meta=0;
}
if(meta==0)
{
    printf("\n\t\t\t\t\t\t\tINVALID ........!! PLEASE ENTER EITHER FROM M/F");
    goto E;
}
/****address*****/
printf("\n\n\t\t\t\t\t\t\t\t\tADDRESS:");
   scanf("%s",p.address);
/*****contact no***/
F:
 printf("\n\n\t\t\t\t\t\t\t\t\tCONTACT-NO:");
   scanf("%s",p.contactno);
   if(strlen(p.contactno)>10||strlen(p.contactno)!=10)
   {
        printf("\n\t\t\t\t\t\tCONTACT-NO MUST CONTAIN 10 NUMBERS.......!!PLEASE ENTER AGAIN...");
        goto F;
   }
   else
   {
   for(z=0;z<strlen(p.contactno);z++)
   {
       if(!isalpha(p.contactno[z]))
       {
           valid=1;
       }
       else
       {
           valid=0;
       }
   }
   if(valid==0)
   {
       printf("\n\t\t\t\t\t\tCONTACT-NO CONTAIN INVALID NUMBERS.......!!PLEASE ENTER AGAIN...");
       goto F;
   }
   }

/***address****/
printf("\n\n\t\t\t\t\t\t\t\t\tE-MAIL:");
   scanf("%s",p.email);
/****problem****/
G:
printf("\n\n\t\t\t\t\t\t\t\t\tPROBLEM:");
   scanf("%s",p.problem);
   for(z=0;z<strlen(p.problem);z++)
   {
       if(isalpha(p.problem[z]))
       {
           valid=1;
       }
       else
       {
           valid=0;
       }
   }
   if(valid==0)
   {
       printf("\n\t\t\t\t\t\tPROBLEM CONTAIN INVALID NUMBERS.......!!PLEASE ENTER AGAIN...");
       goto G;
   }
/****prescribed doctor****/
f:
printf("\n\n\t\t\t\t\t\t\t\t\tPRESCRIBED-DOCTOR:");
   scanf("%s",p.doctor);
   for(z=0;z<strlen(p.doctor);z++)
   {
       if(isalpha(p.doctor[z]))
       {
           valid=1;
       }
       else
       {
           valid=0;
       }
   }
   if(valid==0)
   {
       printf("\n\t\t\t\t\t\tDOCTOR-NAME CONTAIN INVALID NUMBERS.......!!PLEASE ENTER AGAIN...");
       goto f;
   }
   fprintf(jk,"%s %s %c %d %s %s %s %s %s",p.firstname,p.lastname,p.gender,p.age,p.address,p.email,p.contactno,p.doctor,p.problem);
   fprintf(jk,"\n");
   printf("\n\t\t\t\t\t\t!!!......INFORMATION HAS RECORDED SUCCESSFULLY.....!!!");
   fclose(jk);
   getch();
   H:
       fflush(stdin);
    printf("\n\t\t\t\t\t\tDO YOU WANT TO ADD MORE RECORD[Y/N]:");
    scanf("%c",&ya);
    if(ya=='y'||ya=='Y')
    {
        add();/****add function calling***/
    }
    if(ya=='n'||ya=='N')
    {
        menu();/***menu function calling***/
    }
    else
    {
         printf("\n\t\t\t\t\t\tINVALID INPUT .....!!PLEASE ENTER AGAIN:");
         goto H;
    }
}
/****list function***/
void list()
{

 system("cls");
 header();
 FILE *jk;
jk=fopen("handel.txt","r");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!LIST PATIENTS RECORD!!!!\n");
    gotoxy(1,16);
    printf("FULL-NAME");
    gotoxy(22,16);
    printf("GENDER");
    gotoxy(35,16);
    printf("AGE");
    gotoxy(50,16);
    printf("ADDRESS");
    gotoxy(72,16);
    printf("E-MAIL");
    gotoxy(90,16);
     printf("CONTACT-NO");
         gotoxy(110,16);
   printf("PRESCRIBED-DOCTOR");
   gotoxy(140,16);
   printf("PROBLEM");
   printf("\n========================================================================================================================================================================\n");
int row=19;


while(fscanf(jk,"%s %s %c %d %s %s %s %s %s\n",p.firstname,p.lastname,&p.gender,&p.age,p.address,p.email,p.contactno,p.doctor,p.problem)!=EOF)
{

    gotoxy(1,row);
    printf("%s %s",p.firstname,p.lastname);
    gotoxy(22,row);
    printf("%c",p.gender);
    gotoxy(35,row);
    printf("%d",p.age);
    gotoxy(48,row);
    printf("%s",p.address);
    gotoxy(67 ,row);
    printf("%s",p.email);
    gotoxy(90,row);
     printf("%s",p.contactno);
    gotoxy(110,row);
   printf("%s",p.doctor);
   gotoxy(140,row);
   printf("%s",p.problem);
   row++;
}
 fclose(jk);
getch();
menu();
}
/****search function****/
void search()
{
system("cls");
 header();
 char da;
 int row=21;
 FILE *jk;
jk=fopen("handel.txt","r");
 printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!SEARCH PATIENTS RECORD!!!!\n");
char name[30];
printf("\n\n\t\t\t\t\t\t\tENTER PATIENT NAME TO VIEW INFORMATION:");
scanf("%s",name);
fflush(stdin);
while(fscanf(jk,"%s %s %c %d %s %s %s %s %s\n",p.firstname,p.lastname,&p.gender,&p.age,p.address,p.email,p.contactno,p.doctor,p.problem)!=EOF)
{
    if(strcmp(p.firstname,name)==0)
    {
    gotoxy(1,19);
    printf("FULL-NAME");
    gotoxy(22,19);
    printf("GENDER");
    gotoxy(35,19);
    printf("AGE");
    gotoxy(50,19);
    printf("ADDRESS");
    gotoxy(72,19);
    printf("E-MAIL");
    gotoxy(90,19);
     printf("CONTACT-NO");
         gotoxy(110,19);
   printf("PRESCRIBED-DOCTOR");
   gotoxy(140,19);
   printf("PROBLEM");
    printf("\n========================================================================================================================================================================\n");
   gotoxy(1,row);
    printf("%s %s",p.firstname,p.lastname);
    gotoxy(22,row);
    printf("%c",p.gender);
    gotoxy(35,row);
    printf("%d",p.age);
    gotoxy(48,row);
    printf("%s",p.address);
    gotoxy(67 ,row);
    printf("%s",p.email);
    gotoxy(90,row);
     printf("%s",p.contactno);
    gotoxy(110,row);
   printf("%s",p.doctor);
   gotoxy(140,row);
   printf("%s",p.problem);
   break;
    }

}
  if(strcmp(p.firstname,name)!=0)
  {
    printf("\n\n\n\n\t\t\t\t\t\t\t!!!......RECORD NOT FOUND.....!!!");
  }
 fclose(jk);
   getch();
  l:
    fflush(stdin);
 printf("\n\n\n\n\t\t\t\t\t\t\tDO YOU WANT TO SEARCH MORE RECORD[Y/N]:");
    scanf("%c",&da);
    if(da=='y'||da=='Y')
    {
        search();/****search function calling***/
    }
    if(da=='n'||da=='N')
    {
        menu();/***menu function calling***/
    }
    else
    {
         printf("\n\n\n\n\t\t\t\t\t\tINVALID INPUT .....!!PLEASE ENTER AGAIN:");
         goto l;
    }
}
/****delete function***/
void del()
{
system("cls");
 header();
 char da;
 int flag;
 int row=21;
 FILE *jk,*tp;
jk=fopen("handel.txt","r");
tp=fopen("tempr.txt","w+");
 printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!DELETE PATIENTS RECORD!!!!\n");
char name[30];
printf("\n\n\t\t\t\t\t\t\tENTER PATIENT NAME TO DELETE INFORMATION:");
scanf("%s",name);
fflush(stdin);
while(fscanf(jk,"%s %s %c %d %s %s %s %s %s\n",p.firstname,p.lastname,&p.gender,&p.age,p.address,p.email,p.contactno,p.doctor,p.problem)!=EOF)
{
    if(strcmp(p.firstname,name)==0)
    {
    gotoxy(1,19);
    printf("FULL-NAME");
    gotoxy(22,19);
    printf("GENDER");
    gotoxy(35,19);
    printf("AGE");
    gotoxy(50,19);
    printf("ADDRESS");
    gotoxy(72,19);
    printf("E-MAIL");
    gotoxy(90,19);
     printf("CONTACT-NO");
         gotoxy(110,19);
   printf("PRESCRIBED-DOCTOR");
   gotoxy(140,19);
   printf("PROBLEM");
    printf("\n========================================================================================================================================================================\n");
   gotoxy(1,row);
    printf("%s %s",p.firstname,p.lastname);
    gotoxy(22,row);
    printf("%c",p.gender);
    gotoxy(35,row);
    printf("%d",p.age);
    gotoxy(48,row);
    printf("%s",p.address);
    gotoxy(67 ,row);
    printf("%s",p.email);
    gotoxy(90,row);
     printf("%s",p.contactno);
    gotoxy(110,row);
   printf("%s",p.doctor);
   gotoxy(140,row);
   printf("%s",p.problem);

   flag=1;
    }



  if(strcmp(p.firstname,name)!=0)
  {
    fprintf(tp,"%s %s %c %d %s %s %s %s %s\n",p.firstname,p.lastname,p.gender,p.age,p.address,p.email,p.contactno,p.doctor,p.problem);
  }
}
  if(flag==0)
  {
  	printf("record not found!!!!!!!!!!!!!!!!!");
  	getch();
  	menu();
  }
  else
  {
  	fclose(jk);
  	fclose(tp);
  	remove("handel.txt");
  	rename("tempr.txt","handel.txt");
  	 printf("\n\n\n\n\t\t\t\t\t\t\t\t\t!!!!RECORD DELETED SUCCESSFUL!!!!\n");
  	getch();
  	menu();

  }
}
void left()
{
   system("cls");
 header();
   printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t!!!......THANKFUL TO YOU.....!!!");
  getch();

}
