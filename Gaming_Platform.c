#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

int randomizer,temp,x;

FILE *fp;
FILE *fp1;
FILE *fp2;
FILE *fp3;
FILE *fp4;
FILE *g1,*g2,*g3,*g4,*g5;

int sumplayer;
int sumcomp;
int y,z;

const int W,H;

char p1,p2;
char name[50];

int sumA;
int sumB;

char s[50];
char board1[3][3];

const int T = 1;
const int F = 0;

int o,k;

struct info
{
    char loginID[50];
    char pass[50];
    char name[50];
    char phno[10];
    char games[50];

    int wallet;

    char v[3],b[3],z[3],x[3],y[3];

}
a[10];
int check5(char ch[50])
{
    fp = fopen("loginID.txt", "r");
    int i;
    for(i=0;i<10;i++)
    {
        fscanf(fp,"%s\n",a[i].loginID);
    }
     for(i=0;i<10;i++)
    {
        int r=strcmp(ch,a[i].loginID);
        if(r==0)
        {
            return 1;
        }
    }
    return 0;
    fclose(fp);
}

int login()
{
    system("cls");
    printf("\n\n\n\t\t\tSIGN IN");
    
    int i=0;

    char holder[100];
    char ID[50];
    char pass[50],name[50];
    char phno[10];

    fp = fopen("loginID.txt", "r");
    fp1= fopen("phonenumber.txt", "r");
    fp2= fopen("password.txt", "r");
    fp3= fopen("name.txt", "r");

    char phno2[10];

    for(i=0;i<10;i++)
    {
            fscanf(fp,"%s\n",a[i].loginID);
            fscanf(fp2,"%s\n",a[i].pass);
            fscanf(fp3,"%s\n",a[i].name);
            fscanf(fp1,"%s\n",a[i].phno);
    }

    printf("\nenter loginID:");
    scanf("%s",&ID);
    printf("\nenter password:");

    int p=0,c=0;
    do
    {
        pass[p]=getch();
        if(pass[p]!='\r')
            {
                printf("*");
            }
            p++;
        }
        while(pass[p-1]!='\r');
    pass[p-1]='\0';
        printf("\n\n\nLOADING\n");
        for(i=0;i<=10;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
    for(i=0;i<10;i++)
    {
        int r=strcmp(a[i].loginID,ID);
        int s=strcmp(a[i].pass,pass);
        if(r==0 && s==0)
        {
            c++;
            k=i;
            printf("\n\nYOU HAVE SUCCESSFULLY LOGGED IN\n");
            overhere:
            break;
        }

    }
    if(c==0)
    {
        int s;
        system("cls");
        printf("\nINVALID USERNAME OR PASSWORD");
        printf("\n1||RELOGIN\n2||SIGNUP");
        scanf("%d",&s);
        printf("\n\n\n\tLOADING\n");
        for(i=0;i<=10;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }

        switch(s)
        {
        case 1:
            {
                login();
                break;
            }
        case 2:
            {
                signup();
                break;
            }
        default:
            {
                printf("\nINVALID CHOICE:");
            }
        }
    }
}
int signup()
{
    system("cls");
    printf("\n\n\n\t\t\t CREATE YOUR ACCOUNT");
    char ID[50],pass[50],pass1[50],name[50];
    log:

    printf("\nEnter your details");
    printf("\nLogin id:");
    scanf("%s",&ID);

    int f=check5(ID);
    if(f==0)
    {
        fp = fopen("loginID.txt", "a");
        fputs(ID,fp);
        fputs("\n",fp);
        fclose(fp);
    }
    else
    {
        printf("\nLOGIN ID ALREADY TAKEN\n");
        goto log;
    }
    password:
    printf("password:\n");
    int p=0,c=0;
    do{
        pass[p]=getch();
        if(pass[p]!='\r'){
            printf("*");
        }
        p++;
    }while(pass[p-1]!='\r');
    pass[p-1]='\0';
    printf("\nre-password:\n");
    p=0;
    do{
        pass1[p]=getch();
        if(pass1[p]!='\r'){
            printf("*");
        }
        p++;
    }while(pass1[p-1]!='\r');
    pass1[p-1]='\0';
    int r=strcmp(pass,pass1);
   if(r==0)
    {
        fp2= fopen("password.txt", "a");
        fputs(pass,fp2);
        fputs("\n",fp2);
        fclose(fp2);

    }
    else
    {
        printf("\nPasswords do not match\n");
        goto password;
    }
    printf("\nName:");
    scanf("%s",name);
    fp3= fopen("name.txt", "a");
    fputs(name,fp3);
    fputs("\n",fp3);
    fclose(fp3);
    phone:

   printf("\nPhone number:");
    int e=0;
    char phno[10];
    scanf("%s",&phno);


    int i;
    for(i=0;i<10;i++)
    {

        if(phno[i]!='\0')
        {
            e++;
        }

    }
    if(e==10)
    {
            fp1=fopen("phonenumber.txt","a");
            fputs(phno,fp1);
            fputs("\n",fp1);
            fclose(fp1);
    }
    else
    {
        printf("Invalid phone number\n");
        goto phone;
    }
        printf("\n\n\nLOADING\n");
        for(i=0;i<=10;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
        system("cls");
        printf("\nACCOUNT CREATED SUCCESSFULLY");
        printf("\nLOGIN TO CONTINUE");
        printf("\n\n\nLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }

    o++;
    login();
}
void edit(void)
{
    system("cls");
    FILE *newrec;
    FILE *newrec1;
    FILE *newrec2;
    FILE *newrec3;
    edit1:
     printf("1||Edit Name\n");
     int s;
        printf("2||Edit Ph. No.:\n");
               printf("3||Edit Password\n");
               printf("   Edit:");
               scanf("%d",&s);
                 int i;
                int c=0;
                char login1[50];

               printf("\n\n\nLOADING\n");
                for(i=0;i<=10;i++)
                {
                    fordelay(100000000);
                    printf("%c",220);
                }
                system("cls");
                switch(s)
               {
               case 1:
                {
                    newrec2=fopen("name.txt","w");
                    for(i=0;i<10;i++)
                    {

                        if(strlen(a[i].loginID)!=0)
                        {
                             if(a[k].loginID==a[i].loginID)
                            {
                                char name[50],name1[50];

                                printf("enter new name:");
                                scanf("%s",&a[k].name);
                                fputs(a[k].name,newrec2);
                                fputs("\n",newrec2);
                                printf("\nNAME CHANGED SUCCESSFULLY\n");
                            }
                             else
                            {
                                fputs(a[i].name,newrec2);
                                fputs("\n",newrec2);
                            }
                        }
                    }
                    fclose(newrec2);
                    char a;
                    printf("DO YOU WANT TO CHANGE ANY OTHER INFORMATION:y/n\n");
                    scanf("%s",&a);
                    if(a=='y')
                    {
                        goto edit1;
                    }
                    else
                        {
                            break;
                        }


                }
               case 2:
                {
                    newrec3=fopen("phonenumber.txt","w");
                    for(i=0;i<10;i++)
                    {

                             if(a[k].loginID==a[i].loginID)
                            {

                                phone:
                                printf("\nPhone number:");
                                scanf("%s",&a[k].phno);
                                if(strlen(a[k].phno)==10)
                                {
                                     fputs(a[k].phno,newrec3);
                                    fputs("\n",newrec3);
                                        printf("\nPHONE NUMBER SUCCESSFULLY\n");
                                }
                                else
                                {
                                    printf("INVALID PHONE NUMBER\n");
                                    goto phone;
                                }
                            }
                                     else
                                    {
                                        fputs(a[i].phno,newrec3);
                                        fputs("\n",newrec3);
                                    }


                        }
                    fclose(newrec3);
                    char a;
                    printf("DO YOU WANT TO CHANGE ANY OTHER INFORMATION:y/n\n");
                    scanf("%s",&a);
                    if(a=='y')
                    {
                        goto edit1;
                    }
                    else
                        {
                            break;
                        }
                }


               case 3:
                {
                   newrec1=fopen("password.txt","w");
                   for(i=0;i<10;i++)
                    {
                        if(strlen(a[i].loginID)!=0)
                        {
                             if(a[k].loginID==a[i].loginID)
                            {

                                passwo:

                                printf("\nEnter existing password:");
                                char pass[50],pass1[50],pass2[50];
                                int p=0,c=0;
                                do{
                                    pass2[p]=getch();
                                    if(pass2[p]!='\r'){
                                        printf("*");
                                    }
                                    p++;
                                }while(pass2[p-1]!='\r');
                                pass2[p-1]='\0';
                                int r=strcmp(pass2,a[k].pass);
                                if(r==0)
                                {
                                    password:
                                    printf("\nEnter new password:");
                                    p=0,c=0;
                                    do{
                                        pass[p]=getch();
                                        if(pass[p]!='\r'){
                                            printf("*");
                                        }
                                        p++;
                                    }while(pass[p-1]!='\r');
                                    pass[p-1]='\0';
                                    printf("\nRe-enter password:\n");
                                    p=0;
                                    do{
                                        pass1[p]=getch();
                                        if(pass1[p]!='\r'){
                                            printf("*");
                                        }
                                        p++;
                                    }while(pass1[p-1]!='\r');
                                    pass1[p-1]='\0';
                                    int s=strcmp(pass,pass1);
                                    strcpy(a[k].pass,pass1);
                                    if(s==0)
                                    {
                                         fputs(a[k].pass,newrec1);
                                        fputs("\n",newrec1);

                                        printf("\nPASSWORD CHANGED SUCCESSFULLY\n");
                                    }
                                    else
                                    {
                                        printf("\nPasswords do not match\n");
                                        goto password;
                                    }
                                }
                                else
                                {
                                    printf("\nInvalid existing password\n");
                                    goto passwo;
                                }

                            }
                            else
                            {
                                fputs(a[i].pass,newrec1);
                                        fputs("\n",newrec1);
                            }
                        }
                    }
                    fclose(newrec1);
                   char a;
                    printf("DO YOU WANT TO CHANGE ANY OTHER INFORMATION\ny/n:\n");
                    scanf("%s",&a);
                    if(a=='y')
                    {
                        goto edit1;
                    }
                    else
                        {
                            break;
                        }
                }


               default:
                   {
                       printf("\nINVALID CHOICE\n");
                       goto edit1;
                   }



               }
}
void viewprofile(void)
{
    system("cls");
    printf("\n|YOUR PROFILE|\n");
    printf("\n---------------------------------------\n");
    printf("|NAME\t|PHONE NUMBER\t|LOGIN-ID|\n");
    printf("|%s\t|%s|%s|",a[k].name,a[k].phno,a[k].loginID);
    printf("\n---------------------------------------\n");
}
void viewlist()
{
    system("cls");
    printf("|LIST|\n");
    printf("\n---------------------------------------\n");
    printf("SR NO.  |NAME\t|PHONE NUMBER\t|LOGIN-ID|\n");
    int i;
    for(i=0;i<10;i++)
    {
        if(strlen(a[i].loginID)!=0)
            printf("\n%d\t|%s\t|%s\t|%s|",i+1,a[i].name,a[i].phno,a[i].loginID);
    }
    printf("\n---------------------------------------\n");
}
void money()
{
    system("cls");
    int s;
    qw:
    printf("1||Withdraw Money From Connected Account\n2||View Balance\n");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        {
            int q=0,g;char cvv[3],c[12];
            do
                {
                     if(q>0)
                     {
                         printf("Invalid Card No.");
                     }
                     q++;
                    printf("\nEnter Card No.:");
                    scanf("%s",&c);
                }while(strlen(c)!=12);
                cv:
            printf("Enter CVV");
            int p=0;
                    do{
                        cvv[p]=getch();
                        if(cvv[p]!='\r'){
                            printf("*");
                        }
                        p++;
                    }while(cvv[p-1]!='\r');
                    cvv[p-1]='\0';
                    if(strlen(cvv)!=3)
                    {
                        printf("\n");
                        printf("Invalid CVV");
                        goto cv;
                    }
                    else
                    {
                        printf("\n");
                        printf("How Much Money Would You Like To Withdraw\n");
                        scanf("%d",&g);
                        a[k].wallet=a[k].wallet+g;
                        int i;
                        printf("Current Balance: %d",a[k].wallet);
                    }
                    break;
        }
    case 2:
        {
            printf("Current Balance: %d",a[k].wallet);
            break;
        }
    default:
        {
            printf("Invalid Input");
            goto qw;
        }
        }
    }
void buygame(void)
{
    system("cls");
    abcdefg:
    system("cls");
    g1=fopen("rps.txt","r");
    g2=fopen("ttt.txt","r");
    g3=fopen("hc.txt","r");
    g4=fopen("h.txt","r");
    g5=fopen("cgl.txt","r");
    
    printf("1|| Rock Paper Scissors\n");
    printf("2|| Tic Tac Toe \n");
    printf("3|| Hand Cricket\n");
    printf("4|| Hangman\n");
    printf("5|| Conway's Game of Life\n");
    printf("6|| Exit\n");

    int s,i;
    char ch[3]="y";
    scanf("%d",&s);
    for(i=0;i<10;i++)
    {
            fscanf(g1,"%s\n",a[i].v);
            fscanf(g2,"%s\n",a[i].b);
            fscanf(g3,"%s\n",a[i].y);
            fscanf(g4,"%s\n",a[i].z);
            fscanf(g5,"%s\n",a[i].x);
    }

    switch(s)
    {
    case 1:
        {

            if(strcmp(a[k].v,ch)==0)
            {
                printf("\n\n\n\tLOADING\n");
                for(i=0;i<=20;i++)
                {
                    fordelay(100000000);
                    printf("%c",220);
                }
                system("cls");
                rps();
                goto abcdefg;
            }
            else
            {
                char c;
                printf("Buy For Rs.300\ny/n:\n");
                scanf("%s",&c);
                if(c=='y')
                {
                    ab:
                    if(a[k].wallet>300)
                    {
                        a[k].wallet=a[k].wallet-300;
                        printf("Remaining Balance:%d",a[k].wallet);
                        fclose(g1);
                        g1=fopen("rps.txt","w");
                        char ch1[3]="y";
                        for(i=0;i<10;i++)
                        {
                            if(i==k)
                            {
                                fputs(ch1,g1);
                                fputs("\n",g1);
                            }
                            else
                            {
                                fputs(a[i].v,g1);
                                fputs("\n",g1);

                            }
                        }
                        fclose(g1);
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        rps();
                        goto abcdefg;
                    }
                    else
                    {
                        money();
                        goto ab;
                    }
                }
                else
                {
                    goto abcdefg;
                }
            }
        }
    case 2:
        {
            if(strcmp(a[k].b,ch)==0)
            {
                printf("\n\n\n\tLOADING\n");
                for(i=0;i<=20;i++)
                {
                    fordelay(100000000);
                    printf("%c",220);
                }
                ttt();
                goto abcdefg;
            }
            else
            {
                char c;
                printf("Buy For Rs.1600?\ny/n:\n");
                scanf("%s",&c);
                if(c=='y')
                {
                    ac:
                    if(a[k].wallet>1600)
                    {
                        a[k].wallet=a[k].wallet-1600;
                        printf("Remaining Balance:%d",a[k].wallet);
                        fclose(g2);
                        g2=fopen("ttt.txt","w");
                        char ch1[3]="y";
                        for(i=0;i<10;i++)
                        {
                            if(i==k)
                            {

                                fputs(ch1,g2);
                                fputs("\n",g2);
                            }
                            else
                            {

                                fputs(a[i].b,g2);
                                fputs("\n",g2);
                            }
                        }
                        fclose(g2);
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        ttt();
                        goto abcdefg;
                    }
                    else
                    {
                        money();
                        goto ac;
                    }
                }
                else
                {
                    goto abcdefg;
                }
            }
        }
    case 3:
       {

            if(strcmp(a[k].y,ch)==0)
            {
                hc();
                goto abcdefg;
            }
            else
            {
                char c;
                printf("Buy For Rs.800?\ny/n:\n");
                scanf("%s",&c);
                if(c=='y')
                {
                    ad:
                    if(a[k].wallet>800)
                    {
                        a[k].wallet=a[k].wallet-800;
                        printf("Remaining Balance:%d",a[k].wallet);
                        fclose(g3);
                        g3=fopen("hc.txt","w");
                        char ch1[3]="y";
                        for(i=0;i<10;i++)
                        {
                            if(i==k)
                            {

                                fputs(ch1,g3);
                                fputs("\n",g3);
                            }
                            else
                            {

                                fputs(a[i].y,g3);
                                fputs("\n",g3);
                            }
                        }
                        fclose(g3);
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        hc();
                        goto abcdefg;
                    }
                    else
                    {
                        money();
                        goto ad;
                    }
                }
                else
                {
                    goto abcdefg;
                }
            }
        }
    case 4:
        {
            if(strcmp(a[k].z,ch)==0)
            {
                h();
                goto abcdefg;
            }
            else
            {
                char c;
                printf("Buy For Rs.600?\ny/n:\n");
                scanf("%s",&c);
                if(c=='y')
                {
                    ae:
                    if(a[k].wallet>600)
                    {
                        a[k].wallet=a[k].wallet-600;
                        printf("Remaining Balnce:%d",a[k].wallet);
                        fclose(g4);
                        g4=fopen("h.txt","w");
                        char ch1[3]="y";
                        for(i=0;i<10;i++)
                        {
                            if(i==k)
                            {

                                fputs(ch1,g4);
                                fputs("\n",g4);
                            }
                            else
                            {

                                fputs(a[i].z,g4);
                                fputs("\n",g4);
                            }
                        }
                        fclose(g4);
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        h();
                        goto abcdefg;
                    }
                    else
                    {
                        money();
                        goto ae;
                    }
                }
                else
                {
                    goto abcdefg;
                }
            }
        }
    case 5:
        {

            if(strcmp(a[k].x,ch)==0)
            {
                gol();
                goto abcdefg;
            }
            else
            {
                char c;
                printf("Buy For Rs.1200?\ny/n\n");
                scanf("%s",&c);
                if(c=='y')
                {
                    af:
                    if(a[k].wallet>1200)
                    {
                        a[k].wallet=a[k].wallet-1200;
                        printf("Remaining Balance: %d",a[k].wallet);
                        fclose(g5);
                        g5=fopen("x.txt","w");
                        char ch1[3]="y";
                        for(i=0;i<10;i++)
                        {
                            if(i==k)
                            {

                                fputs(ch1,g5);
                                fputs("\n",g5);
                            }
                            else
                            {

                                fputs(a[i].x,g5);
                                fputs("\n",g5);
                            }
                        }
                         fclose(g5);
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        gol();
                        goto abcdefg;

                    }
                    else
                    {
                        money();
                        goto af;
                    }
                }
                else
                {
                    goto abcdefg;
                }
            }
        }
        case 6:
        {
            
            printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=20;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        break;
                        
        }
        default:
        {
            printf("Invalid Input\n");
            goto abcdefg;
        }
    }
}
//RPS
int rps() {
  int i, n, x;
  int win=0, lose=0;

  int y =0;
   system("cls");
   printf("\n");
   printf("         ooooooooo.                       oooo             ooooooooo.                                                 .oooooo..o            o8o                                                \n");
   printf("         `888   `Y88.                     `888             `888   `Y88.                                              d8P'    `Y8            ` '                                                \n");
   printf("          888   .d88'  .ooooo.   .ooooo.   888  oooo        888   .d88'  .oooo.   oo.ooooo.   .ooooo.  oooo d8b      Y88bo.       .ooooo.  oooo   .oooo.o  .oooo.o  .ooooo.  oooo d8b  .oooo.o \n");
   printf("          888ooo88P'  d88' `88b d88' ` Y8  888 .8P'         888ooo88P'  `P  )88b   888' `88b d88' `88b `888  8P       ` Y8888o.  d88' ` Y8 `888  d88(   8 d88(   8 d88' `88b `888  8P d88(   8 \n");
   printf("          888`88b.    888   888 888        888888.          888          .oP 888   888   888 888ooo888  888               ` Y88b 888        888  ` Y88b.  ` Y88b.  888   888  888     ` Y88b.  \n");
   printf("          888  `88b.  888   888 888   .o8  888 `88b.        888         d8(  888   888   888 888    .o  888          oo     .d8P 888   .o8  888  o.  )88b o.  )88b 888   888  888     o.  )88b \n");
   printf("         o888o  o888o `Y8bod8P' `Y8bod8P' o888o o888o      o888o        `Y888  8o  888bod8P' `Y8bod8P' d888b         8  88888P'  `Y8bod8P' o888o 8  888P' 8  888P' `Y8bod8P' d888b    8  888P' \n");
   printf("                                                                                   888                                                                                                         \n");
   printf("                                                                                  o888o                                                                                                        \n");
   char ch[3][10]={"rock","scissors","paper"};
   int r[3];
   abcde:
   printf("\nPlay best of (odd only):");
   scanf("%d",&x);
    system("cls");
   rps1:

   if(x%2 == 0)
    {
       printf("\nEnter Odd Values Only");
       goto abcde;
    }
    else
    {
        int m=0;
        if(x==y ||lose==(x+1)/2 || win==(x+1)/2)
        {
            goto kaesrje;
        }
        else
        {
            do
            {
               srand(time(NULL));
               r[0]=rand()%4;
                m=r[0];

            }while(m==0);
            char s;
            acd:
            printf("\nenter your input");
            printf("\n1||Rock");
            printf("\n2||Scissors");
            printf("\n3||Paper");
            printf("\nYour Choice:");
            scanf("%d",&n);
            system("cls");
            if(n>3||n<1)
            {
                printf("Invalid");
                goto acd;
            }
            printf("\nYour Choice: %s\n",ch[n-1]);
            printf("\nComputer's Choice: %s\n",ch[m-1]);
                if(r[0]==n)
                {
                printf("\nIt's A Draw!");
                goto rps1;

                }
                else if(r[0]==1 && n==2)
                {
                printf("\nThe Computer Wins!");
                y++;
                 lose++;
                goto rps1;
                }
                else if(r[0]==1 && n==3)
                {
                printf("\nYou Won!");
                y++;
                 win++;
                goto rps1;
                }
                else if(r[0]==2 && n==1)
                {
                printf("\nYou Won!");
                y++;
                 win++;
                goto rps1;
                }
                else if(r[0]==2 && n==3)
                {
                printf("\nThe Computer Wins!");
                y++;
                 lose++;
                goto rps1;
                }
                else if(r[0]==3 && n==1)
                {
                printf("\nThe Computer Wins!");
                y++;
                lose++;
                goto rps1;
                }
                else if(r[0]==3 && n==2)
                {
                printf("\nYou Won!");
                y++;
                win++;
                goto rps1;
                 }

     }
    }


   kaesrje:
       printf("\nTotal Computer Wins: %d\n",lose);
       printf("\nYour Total Wins: %d\n",win);
   if(win>lose){
       printf("\nWell Played!\nYou Won!\n");

   }
   else
    {
       printf("\nBetter Luck Next Time\nYou Lost\n");
   }
}

//TICTACTOE SINGLEPLAYER
void fordelay(int j)
{   int i,l;
    for(i=0;i<j;i++)
         l=i;
}

char gridChar(int i) {
  switch (i) {
  case -1:
    return 'X';
  case 0:
    return ' ';
  case 1:
    return 'O';
  }
}

void draw(int b[9]) {
  printf(" %c | %c | %c\n", gridChar(b[0]), gridChar(b[1]), gridChar(b[2]));
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", gridChar(b[3]), gridChar(b[4]), gridChar(b[5]));
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", gridChar(b[6]), gridChar(b[7]), gridChar(b[8]));
}

int win(const int board[9])
{
  unsigned wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                         {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
  int i;

  for (i = 0; i < 8; ++i)
  {
    if (board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] &&
        board[wins[i][0]] == board[wins[i][2]])
      return board[wins[i][2]];
  }
  return 0;
}

int minimax(int board[9], int player) {

  int winner = win(board);
  if (winner != 0)
    return winner * player;

  int move = -1;
  int score = -2;
  int i;
  for (i = 0; i < 9; ++i) {
    if (board[i] == 0) {
      board[i] = player;
      int thisScore = -minimax(board, player * -1);
      if (thisScore > score) {
        score = thisScore;
        move = i;
      }
      board[i] = 0;
    }
  }
  if (move == -1)
    return 0;
  return score;
}

void computerMove(int board[9]) {
  int move = -1;
  int score = -2;
  int i;
  for (i = 0; i < 9; ++i) {
    if (board[i] == 0) {
      board[i] = 1;
      int tempScore = -minimax(board, -1);
      board[i] = 0;
      if (tempScore > score) {
        score = tempScore;
        move = i;
      }
    }
  }

  board[move] = 1;
}
 int check6(char n) {
  int i, flag = 0;
      if (n!= 88 &&  n!= 79) {

        flag = 0;
      } else {
          printf("\nTry A Different Square\n");
        flag = 1;
      }

    return flag;
  }

void playerMove(int board[9]) {
  int move = 0;
 do {

    printf("\nInput (0-8): ");
    scanf("%d", &move);
    printf("\n");
    system("cls");
 }
  while (move >= 9 || move < 0 && board[move] == 0 || check6(gridChar(board[move]))==1);
  board[move] = -1;
}

void tttsingle()
{
    printf("\nSinglePlayer Mode\n");

  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  printf("Board:\n");
  printf(" 0 | 1 | 2 \n---+---+---\n 3 | 4 | 5 \n---+---+---\n 6 | 7 | 8 \n");
  printf("Computer: O, You: X\n Would You Like To Go First Or Second ");
  int player = 0;
  scanf("%d", &player);
  printf("\n");

  printf("\n");

  unsigned turn;
  for (turn = 0; turn < 9 && win(board) == 0; ++turn) {
    if ((turn + player) % 2 == 0)
      computerMove(board);
    else {
      draw(board);
      playerMove(board);
    }
  }
  switch (win(board)) {
  case 0:
    printf("Good Try, It's A Draw\n");
    break;
  case 1:
    draw(board);
    printf("You Can't Beat The Computer, You Lose.\n");
    break;
  case -1:
    printf("You Beat The Computer!\n");
    break;
  }
}


int check2()
{
    int i,j,flag=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board1[i][j]!=88 && board1[i][j]!=79 )
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
    }
    return flag;
}

int space(int e,int d)
{
      if(board1[e][d]!=88 && board1[e][d]!=79)
      {
          return 1;
      }
      else
      {
          return 0;
      }
}

int player1()
{
  int e=check2();
  if(e==0)
  {
      char column;
      char row;
      abcgg:
      printf("\nPlayer 1:");
      printf("\nEnter Row(A,B,C) and Column(1,2,3):");
      scanf(" %c %c", &row, &column);
      if(row==65 || row==66 || row==67)
      {
            if(column=='1' || column=='2' || column=='3')
            {
                int rowind = row - 'A';
                int colind = column - '1';
                int d=space(rowind,colind);
                if (d==1)
                {
                    board1[rowind][colind] = p1;
                    system("cls");
                    tttboard();
                    int r=check();
                    if(r!=1)
                    {
                        player2();

                    }
                    else{}
                }
                else
                {
                    printf("\nSquare Occupied, Try Again:");
                    goto abcgg;
                }
            }
            else
            {
                printf("\nInvalid, Try Again:");
                goto abcgg;
            }
      }
      else
      {
            printf("\nInvalid, Try Again:");
            goto abcgg;
      }
  }
  else
  {
        printf("\nIt's A Draw");
  }
}


int player2()
{
  int e=check2();
  if(e==0)
  {
      char column;
      char row;
      abcgg:
      printf("\nPlayer 2:");
      printf("\nEnter Row(A,B,C) and Column(1,2,3):");
      scanf(" %c %c", &row, &column);
      int rowind = row - 'A';
      int colind = column - '1';
      int d=space(rowind,colind);
      if(row==65 || row==66 || row==67)
      {
          if(column=='1' || column=='2' || column=='3')
          {
            if (d==1)
            {
                board1[rowind][colind] = p2;
                system("cls");
                tttboard();
                int r=check();
                if(r!=1)
                {
                    player1();

                }
            }
            else
            {
                printf("\nSquare Occupied, Try Again:");
                goto abcgg;
            }
           }
           else
           {
                printf("\nInvalid, Try Again:");
                goto abcgg;
           }
      }
      else
      {
          printf("\nInvalid, Try Again:");
            goto abcgg;
      }
  }
  else
  {
        printf("\nIt's A Draw");
  }
}

  int check()
  {
     char ch;
     int i=0,j=0;
     int flag=0;
  for(i=0;i<3;i++)
  {

          if(board1[i][0]==board1[i][1] && board1[i][1]==board1[i][2])
      {
           if(board1[i][2]==88 || board1[i][2]==79)
           {
               flag=1;
             ch=board1[i][j];
             if(ch==p1)
             {
                 printf("\nPlayer 1 (%c) Wins!",ch);
                 return 1;
             }
             else
             {
                 printf("\nPlayer 2 (%c) Wins!",ch);
                 return 1;
             }
           }
      }
      }

  for(j=0;j<3;j++)
  {
        flag=1;

        if(board1[0][j]==board1[1][j] && board1[1][j]==board1[2][j] )
        {
            if(board1[2][j]==88 || board1[2][j]==79)
            {
                ch=board1[0][j];
                if(ch==p1)
                {
                    printf("Player 1 (%c) Wins!",ch);
                    return 1;
                }
                else
                {
                    printf("Player 2 (%c) Wins!",ch);
                    return 1;
                }
            }

        }

  }
  if(board1[0][0]==board1[1][1] && board1[1][1]==board1[2][2])
  {
     if(board1[0][0]==88 || board1[0][0]==79)
     {
        ch=board1[0][0];
        if(ch==p1)
        {
            printf("Player 1 (%c) Wins!",ch);
            return 1;
        }
        else
        {
            printf("Player 2 (%c) Wins!",ch);
            return 1;
        }
     }
  }
  else if(board1[0][2]==board1[1][1] && board1[1][1]==board1[2][0])
  {
    ch=board1[0][2];
    if(board1[2][0]==88 || board1[2][0]==79)
    {
        if(ch==p1)
        {
            printf("Player 1 (%c) Wins!",ch);
            return 1;
        }
        else
        {
            printf("Player 2 (%c) Wins!",ch);
            return 1;
        }
    }
  }
}

int tttboard()
{
    int i, j;
    printf(" | 1| 2| 3|\n");
    for (int i = 0; i < 3; i++)
    {

        printf("%c| ", 'A' + i);
        for (int j = 0; j < 3; j++)
        {
            if(board1[i][j]!='\0')
            {
               printf("%c| ", board1[i][j]);
            }
            else
            {
                printf(" | ");
            }

        }
        printf("\n");
    }
}

void tttmulti()
{

    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board1[i][j]=0;
        }
    }
    printf("\nMultiplayer Tic Tac Toe\n");
    abcgg:
    printf("\nPlayer 1 choose X or O:");
    scanf("%c", &p1);
    system("cls");

    switch (p1)
    {
    case 'X':
        p2 = 'O';
        printf("board1\n");
        tttboard();
        player1();
        break;

    case 'O':
        p2 = 'X';
        printf("board1\n");
        tttboard();
        player1();
        break;
    default:
        goto abcgg;
    }
}


void ttt()
{
    int f,i;
    system("cls");
printf("ooooooooooooo  o8o                 ooooooooooooo                          ooooooooooooo                      \n");
printf("8'   888   `8  ` '                 8'   888   `8                          8'   888   `8                        \n");
printf("     888      oooo   .ooooo.            888       .oooo.    .ooooo.            888       .ooooo.   .ooooo.       \n");
printf("     888      `888  d88' ` Y8           888      `P  )88b  d88' ` Y8           888      d88' `88b d88' `88b      \n");
printf("     888       888  888                 888       .oP 888  888                 888      888   888 888ooo888      \n");
printf("     888       888  888   .o8           888      d8(  888  888   .o8           888      888   888 888    .o      \n");
printf("    o888o     o888o `Y8bod8P'          o888o     `Y888  8o `Y8bod8P'          o888o     `Y8bod8P' `Y8bod8P'      \n");
printf("                                                                                                                 \n");
printf("                                                                                                                 \n");
printf("                                                                                                                 \n");
printf("               ooooooo  ooooo      88   .oooooo.                                                                 \n");
printf("                `8888    d8'      .8'  d8P'  `Y8b                                                                \n");
printf("                  Y888..8P       .8'  888      888                                                               \n");
printf("                   `8888'       .8'   888      888                                                               \n");
printf("                  .8PY888.     .8'    888      888                                                               \n");
printf("                 d8'  `888b   .8'     `88b    d88'                                                               \n");
printf("               o888o  o88888o 88       `Y8bood8P'               \n");

    qwerty:
    printf("\n1||Singleplayer\n");
    printf("2||Multiplayer\n");
    printf("3||Exit\n");
    scanf("%d",&f);
    switch(f)
    {
    case 1:
        {
            printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
            tttsingle();
            goto qwerty;
        }
    case 2:
        {
            printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
            tttmulti();
            goto qwerty;
        }
    }
}

//HANDCRICKET
int bat()
{
    int i,j;
    y++;int n;
    int r[10];int m;
   do
    {
        srand(time(NULL));
        r[0]=rand()%10;
        m=r[0];
    }while(m==0);
    bat:
    printf("\nEnter Runs (1-10):");
    scanf("%d",&n);
    if(n<10)
    {
        printf("\tComputer Bowls a: %d",m);
        if(m!=n)
        {
            sumplayer=sumplayer+n;
            int s=check7();
            if(s==0 || s==2)
            {
                y=0;
                bat();

            }
            else if(s==1)
            {
                system("cls");
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nYou Won!\n");
            }
        }
        else
        {
            int r=check7();

            if(r==0)
            {
                printf("\n\xB2\xB2OUT\xB2\xB2\n");
                printf("\n\n\n\tLOADING\n");
                for(i=0;i<=20;i++)
                {
                    fordelay(100000000);
                    printf("%c",220);
                }
                system("cls");
                printf("\nYour Score of the Innings:%d",sumplayer);
                printf("\nCOMPUTER IS ON STRIKE\n");
                bowl();
            }
            else if(r==1)
            {
                system("cls");
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nThe Computer Won!");
            }
            else
            {
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nThe Computer Won!");
            }
        }
    }
    else
    {
        printf("\nInvalid Input\n");
        goto bat;
    }
}
int bowl()
{
    int i,j;
     z++;int n;
     int r[10];int m;
   do
    {
        srand(time(NULL));
        r[0]=rand()%10;
        m=r[0];
    }while(m==0);
    dcba:
    printf("\nBowl A Number (1-10):");
    scanf("%d",&n);
    if(n<10)
    {
        printf("\tComputer Runs: %d",m);
        if(m!=n)
        {
            sumcomp=sumcomp+m;
            int s=check7();
            if(s==1 || s==0)
            {
                z=0;
                bowl();
            }
            else
            {
                system("cls");
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nThe Computer Won!");
            }
        }
        else
        {
            int r=check7();
            if(r==0)
            {
                printf("\n\xB2\xB2OUT\xB2\xB2\n");
                printf("\n\n\n\tLOADING\n");
                for(i=0;i<=20;i++)
                {
                    fordelay(100000000);
                    printf("%c",220);
                }
                system("cls");
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nYOU'RE ON STRIKE");
                bat();
            }
            else if(r==1)
            {
                system("cls");
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nYou Won!");
            }
            else
            {
                system("cls");
                printf("\nYour Score of the Innings: %d",sumplayer);
                printf("\nComputers Score of the Innings: %d\n",sumcomp);
                printf("\nThe Computer Won!");
            }
        }
    }
    else
    {
        printf("\nInvalid Input\n");
        goto dcba;
    }

}
int check7()
{

    if(y==1 && z==1)
    {
        if(sumplayer>sumcomp)
        {
            return 1;
        }
        else if(sumcomp>sumplayer)
        {
            return 2;
        }
        else
        {
            return 0;
        }

    }
}
int hc()
{
    system("cls");
    int i,j;
   y=0;z=0;
   printf(" ooooo   ooooo                             .o8         .oooooo.             o8o            oooo                      .    \n");
   printf(" `888'   `888'                             888        d8P'  `Y8b            ` '            `888                    .o8  \n");
   printf("  888     888   .oooo.   ooo. .oo.    .oooo888       888          oooo d8b oooo   .ooooo.   888  oooo   .ooooo.  .o888oo \n");
   printf("  888ooooo888  `P  )88b  `888P Y88b  d88' `888       888          `888  8P `888  d88' ` Y8  888 .8P'   d88' `88b   888 \n");
   printf("  888     888   .oP 888   888   888  888   888       888           888      888  888        888888.    888ooo888   888  \n");
   printf("  888     888  d8(  888   888   888  888   888       `88b    ooo   888      888  888   .o8  888 `88b.  888    .o   888 . \n");
   printf(" o888o   o888o `Y888  8o o888o o888o `Y8bod88P        `Y8bood8P'  d888b    o888o `Y8bod8P' o888o o888o `Y8bod8P'    888  \n");
                                                                                                                                                       
   int r[10];int m;
   do
    {
        srand(time(NULL));
        r[0]=rand()%10;
        m=r[0];
    }while(m==0);

    int n,e;
    in:
    printf("\nTOSS\n");
    printf("\nCHOOSE ODD(1) OR EVEN(2):");
    scanf("%d",&e);
    if(e>0 && e<3)
    {
            printf("\nENTER A NUMBER(0-10):");
            scanf("%d",&n);
            printf("Computer's Input:%d",m);
            int sum=n+m;
            printf("\nsum=%d",sum);
            if(sum%2==0)
            {
                printf("\nSum is Even\n");
                if(e==1)
                {
                    printf("\nComputer wins the toss\n");
                    if(m%2==0)
                    {
                        printf("\nComputer choose to bat\n");
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=30;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        system("cls");
                        bowl();
                    }
                    else
                    {
                        printf("\nComputer choose to ball\n");
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=30;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        system("cls");
                        bat();
                    }

                }
                else
                {
                    int a;
                    printf("\nYou Won The Toss\n");
                    amp:
                    printf("1||Batting\n2||Bowling");
                    scanf("%d",&a);
                    switch(a)
                    {
                        case 1:
                        {
                            printf("You're On Strike");
                            printf("\n\n\n\tLOADING\n");
                            for(i=0;i<=20;i++)
                            {
                                fordelay(100000000);
                                printf("%c",220);
                            }
                            system("cls");
                            bat();
                            break;
                        }
                        case 2:

                        {
                            printf("You're Bowling");
                            printf("\n\n\n\tLOADING\n");
                            for(i=0;i<=20;i++)
                            {
                                fordelay(100000000);
                                printf("%c",220);
                            }
                            system("cls");
                            bowl();
                            break;
                        }
                        default:
                            printf("\nInvalid Input\n");
                            goto amp;
                    }

                }
            }
            else
            {
                if(e==2)
                {
                    if(m%2==0)
                    {
                        printf("\nComputer Goes On Strike\n");
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=30;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        system("cls");
                        bowl();
                    }
                    else
                    {
                        printf("\nComputer is Bowling\n");
                        printf("\n\n\n\tLOADING\n");
                        for(i=0;i<=30;i++)
                        {
                            fordelay(100000000);
                            printf("%c",220);
                        }
                        system("cls");
                        bat();
                    }

                }
                else
                {
                    int a;
                    printf("\nYOU WIN THE TOSS\n");
                    acp:
                    printf("1||Batting\n2||Bowling");
                    scanf("%d",&a);
                    switch(a)
                    {
                        case 1:
                        {
                            printf("You're On Strike");
                            printf("\n\n\n\tLOADING\n");
                            for(i=0;i<=20;i++)
                            {
                                fordelay(100000000);
                                printf("%c",220);
                            }
                            system("cls");
                            bat();
                            break;
                        }
                        case 2:

                        {
                            printf("You're Bowling");
                            printf("\n\n\n\tLOADING\n");
                            for(i=0;i<=20;i++)
                            {
                                fordelay(100000000);
                                printf("%c",220);
                            }
                            system("cls");
                            bowl();
                            break;
                        }
                        default:
                            printf("\nInvalid Input\n");
                            goto acp;
                    }

                }
            }
        }
        else
        {
            printf("\nInvalid Input\n");
            goto in;
        }

    }

//HANGMAN

int hangman(int z)
{
    switch(z)
    {
    case 0:
        {
            printf("\n _____");
            printf("\n|     |");
            printf("\n|     ");
            printf("\n|    ");
            printf("\n|    ");
            printf("\n|    ");
            printf("\nH\n");
            return 6;
            break;
        }
    case 1:
        {
            printf("\n _____");
            printf("\n|     |");
            printf("\n|     O");
            printf("\n|    ");
            printf("\n|    ");
            printf("\n|    ");
            printf("\nHA\n");
            return 5;
            break;
        }
    case 2:
        {
            printf("\n _____");
            printf("\n|     |");
            printf("\n|     O");
            printf("\n|     |");
            printf("\n|      ");
            printf("\n|    ");
            printf("\nHAN\n");
            return 4;
            break;
        }
    case 3:
        {
               printf("\n _____");
            printf("\n|     |");
            printf("\n|     O");
            printf("\n|    /| ");
            printf("\n|    ");
            printf("\n|    ");
            printf("\nHANG\n");
            return 3;
            break;
        }
    case 4:
        {
               printf("\n _____");
            printf("\n|     |");
            printf("\n|     O");
            printf("\n|    /|%c",92);
            printf("\n|    ");
            printf("\n|    ");
            printf("\nHANGM\n");
            return 2;
            break;
        }
    case 5:
        {
               printf("\n _____");
            printf("\n|     |");
            printf("\n|     O");
            printf("\n|    /|%c",92);
            printf("\n|    / ");
            printf("\n|    ");
            printf("\nHANGMA\n");
            return 1;
            break;
        }
    default:
        {
                printf(" _____");
                printf("\n|     |");
                printf("\n|     O");
                printf("\n|    /|%c",92);
                printf("\n|    / %c",92);
                printf("\n|    ");
            printf("\nHANGMAN\n");
            return 0;
        }
    }
}
int input(int r)
{
    printf("\nDO NOT PRESS ENTER AFTER A GUESS\n");
    char ch1,ch;
    int z=0;
    int e=7;
    abgg:
    printf("\nMake A Guess:");
    ch1=getch();
    ch=tolower(ch1);
    printf("%c",ch);

    char a[26];
    int k,j,i=0;


        a[i]=ch;
        int c=0;
        for(j=0;j<r;j++)
        {

            if(a[i]==name[j])
            {
                c++;
            }

        }
        system("cls");
        if(c==0)
        {
           e=hangman(z);
           z++;
        }
        else
        {
            for(j=0;j<r;j++)
            {
                if(a[i]==name[j])
                {
                    {
                       s[j]=name[j];

                    }

                }

            }
        }
        for(k=0;k<r;k++)
        {
            if(s[k]=='\0')
            {
                printf("_");
            }
            else
            {
                printf("%c",s[k]);
            }
        }
        i++;
        int g=0;
        for(i=0;i<r;i++)
        {
            if(s[i]==name[i])
            {
                g++;
            }
        }
        if(g<r)
        {
            if(e==0)
            {
            printf("\nThe word was %s\n",name);
            printf("No Points Awarded\n");
            return 0;
            }
            else
            {
            goto abgg;
            }
        }
        else
        {
            return e;
        }

}
void teamA()
{
    char name1[50];
    printf("Word:\n");
    int p=0;
    do{
        name1[p]=getch();
        name[p]=tolower(name1[p]);
        if(name[p]!='\r'){
            printf("*");
        }
        p++;
    }while(name[p-1]!='\r');
    name[p-1]='\0';

    int r=strlen(name);

    printf("\nIt is a %d letter word",r);
    int k;
    for(k=0;k<r;k++)
    {
        s[k]='\0';
    }
    int v=input(r);
    printf("\nScore this round is:%d",v);
    sumA=sumA+v;


}
void teamB()
{
    char name1[50];
    printf("word:\n");
    int p=0;
    do{
        name1[p]=getch();
        name[p]=tolower(name1[p]);
        if(name[p]!='\r'){
            printf("*");
        }
        p++;
    }while(name[p-1]!='\r');
    name[p-1]='\0';
    int r=strlen(name);
    printf("\nIt is a %d letter word",r);
    int k;
    for(k=0;k<r;k++)
    {
        s[k]='\0';
    }
    int v=input(r);
    sumB=sumB+v;
    printf("\nScore this round is:%d\n",v);

}
int h()
{
    
        printf("ooooo   ooooo                                                                          \n");                                                  
        printf("`888'   `888'                                                                          \n");
        printf(" 888     888   .oooo.   ooo. .oo.    .oooooooo ooo. .oo.  .oo.    .oooo.   ooo. .oo.   \n");
        printf(" 888ooooo888  `P  )88b  `888P Y88b  888' `88b  `888P Y88bP Y88b  `P  )88b  `888P Y88b  \n");
        printf(" 888     888   .oP 888   888   888  888   888   888   888   888   .oP 888   888   888  \n");
        printf(" 888     888  d8(  888   888   888  `88bod8P'   888   888   888  d8(  888   888   888  \n");
        printf("o888o   o888o `Y888  8o o888o o888o `8oooooo.  o888o o888o o888o `Y888  8o o888o o888o \n");
        printf("                                    d      YD                                          \n");
        printf("                                    Y88888P'                                           \n");
    printf("\n\t\t INSTRUCTIONS \n\t\t");
    printf("\nHANGMAN IS THE GAME WHERE YOU HAVE TO GUESS THE WORD.");
    printf("\nYOU GET 7 INCORRECT GUESSES");
    printf("\n7 POINTS WILL BE AWARDED IF U GUESS THE WORD WITHOUT ANY INCORRECT GUESSES");
    printf("\nPOINTS WILL DECREASE BY 1 PER INCORRECT GUESS\n\n");
    int n;
   printf("\nHow Many Rounds Per Team:");
   scanf("%d",&n);
   system("cls");
   int k=2*n;
   int i;
   for(i=0;i<k;i++)
   {
       if(i%2==0)
       {
           printf("\nteam A your turn\n");
           teamA();
       }
       else
       {
           printf("\nTeam B your turn\n");
           teamB();
       }

   }
   printf("\nTotal score of Team A:%d",sumA);
   printf("\nTotal score of Team B:%d",sumB);
   if(sumA>sumB)
   {
       printf("\nTeam A Wins!\n");
   }
   else
   {
       printf("Team B Wins!\n");
   }
}

//CONWAYS GAME OF LIFE

void boarddraw (int board[H][W])
{
    int cols, rows;
    for (cols =0; cols <W; cols++)
    {
        board[0][cols] = 220;
        board[H -1][cols]= 220;
    }
    for (rows =1; rows <H; rows++)
    {
        board[rows][0] = 219;
        board[rows][W -1] = 219;
    }
}

void dead(int board[H][W])
{
    int i,j;
    for(i =1; i <H-1; i++)
        for(j=1; j <W-1; j++)
            board[i][j] = ' ';
}

void randomcell(int board[H][W])
{
    int i, j, num;
    
    randomizer = 16 - temp;
    randomizer = randomizer/2;

    srand((unsigned)time(NULL));
    for(i =1; i <H -1; i++)
        for(j=1; j <W -1;j++)
        {
            num = rand()%randomizer;
            if (num == 1)
                board[i][j] = 254;
            else board[i][j] = ' ';
        }
}

void drawarray(int board[H][W],int H, int W)
{
int rows;
int cols;

    for (rows = 0; rows <H; rows++)
    {
        for(cols =0; cols <W; cols++)
        if(rows==0||rows==W - 1)
        {
            printf("%c%c%c",220,220,220);
        }
        else
        printf ("%3c", board[rows][cols]);
        printf ("\n");
    }
}

void neighbour (int board[H][W])
{
    int neighbours;
    int rows;
    int cols;
    int a, b;
    for (rows =1; rows <H; rows++)
    {
        for (cols = 1; cols <W; cols ++)
        {
            neighbours = 0;
            if (board[rows][cols] == 254)
            {
                for (a = -1; a <2; a++)
                {
                    for (b = -1; b <2; b++)
                        if (((rows +a) == rows) && ((cols +b) == cols))
                             neighbours = neighbours;
                        else if ((board[rows +a][cols +b] == 254) ||(board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbours++;
                }
                if ((neighbours == 2) || (neighbours == 3))
                    board[rows][cols] = 1;
                else if ((neighbours < 2) || (neighbours >= 4))
                    board[rows][cols] = 0;
            }
        }
    }
}
void newcell (int board[H][W])
{
    int neighbours;
    int rows;
    int cols;
    int a, b;
    for (rows =1; rows <H -1; rows++)
    {
        for (cols = 1; cols <W -1; cols ++)
        {
            neighbours = 0;
            if (board[rows][cols] == ' ')
            {
                for (a = -1; a <2; a++)
                {
                    for (b = -1; b <2; b++)
                        if (((rows +a) == rows) && ((cols +b) == cols))
                            neighbours = neighbours;
                        else if ((board[rows +a][cols +b] == 254) || (board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbours++;
                }
                if ((neighbours == 3))
                    board[rows][cols] = 2;
            }
        }
    }
}

void gen1 (int board[H][W])
{
    int rows;
    int cols;
    for (rows =1; rows <H -1; rows++)
    {
        for (cols = 1; cols <W -1; cols ++)
        {
            if (board[rows][cols] == 1)
                board[rows][cols] = 254;
            else if (board[rows][cols] == 2)
                board[rows][cols] = 254;
            else if(board[rows][cols] == 0)
                board[rows][cols] = ' ';
        }
    }
}

int livecheck (int board[H][W])
{
    int rows;
    int cols;
    int creatures =0;
    for (rows =1; rows <H -1; rows++)
    {
        for (cols = 1; cols <W -1; cols ++)
        {
            if (board[rows][cols] == 254)
                creatures++;
        }
    }
    if (creatures == 0)
        return T;
    else return F;
}


void start (int board[H][W], int generation)
{
    int i, c, check;

    switch (x)
    {
        case 1:
        printf("ENTER ANY NUMBER TO INCREASE 1 GENERATION\nENTER 0 TO EXIT\n");
        for (i = 0; (i <= generation) && (c != 32); i++)
    {
        fordelay(500000000);
        system("cls");
        neighbour(board);
        newcell(board);
        gen1(board);
        printf ("Generation: %i\n", i);
        drawarray(board);
        scanf("%d",&c);
        if(c == 0)
        break;
    }
        check = livecheck(board);
        break;

        case 2:
        for (i = 1; (i <= generation) && (c != 32); i++)
    {
        fordelay(500000000);
        system("cls");
        neighbour(board);
        newcell(board);
        gen1(board);
        printf ("Generation: %i\n", i);
        drawarray(board);

        if(kbhit())
        {
        c = getch();
        if(c == 32)
        break;
        }
    }
    default:
    printf("Invalid Input\n");
    }


        if ((check = livecheck(board)) == T)
        {
            printf ("\nThe Are No More Creatures Alive");
        }
    
}

void run(int board[H][W])
{
    int i, generation, c;
    randomcell(board);
    drawarray(board,H,W);
    printf ("\nPlease select a number of generation: ");
    scanf ("%i", &generation);
    start(board, generation);
}

int gol()
{

    system("cls");


    int board[H][W], mode;

    boarddraw(board);
    dead(board);

    printf ("     .oooooo.                                                                o8o                 .oooooo.                                                          .o88o.      ooooo         o8o   .o88o.\n");
    printf ("    d8P'  `Y8b                                                               `YP                d8P'  `Y8b                                                         888 `       `888'         ` '   888 ` \n");
    printf ("   888           .ooooo.  ooo. .oo.   oooo oooo    ooo  .oooo.   oooo    ooo  '   .oooo.o      888            .oooo.   ooo. .oo.  .oo.    .ooooo.        .ooooo.  o888oo        888         oooo  o888oo   .ooooo.\n");
    printf ("   888          d88' `88b `888P Y88b   `88. `88.  .8'  `P  )88b   `88.  .8'      d88(  8      888            `P  )88b  `888P Y88bP Y88b  d88' `88b      d88' `88b  888          888         `888   888    d88' `88b\n");
    printf ("   888          888   888  888   888    `88..]88..8'     .oP888    `88..8'       ` Y88b.       888     ooooo  .oP 888   888   888   888  888ooo888      888   888  888          888          888   888    888ooo888\n");
    printf ("   `88b    ooo  888   888  888   888     `888'`888'    d8(  888     `888'        o.  )88b      `88.    .88'  d8(  888   888   888   888  888    .o      888   888  888          888       o  888   888    888    .o\n");
    printf ("    `Y8bood8P'  `Y8bod8P' o888o o888o     `8'  `8'     `Y8888^8o     .8'         88888P'        `Y8bood8P'   `Y8888^8o o888o o888o o888o `Y8bod8P'      `Y8bod8P' o888o        o888ooooood8 o888o o888o   `Y8bod8P'\n");
    printf ("                                                                __,..P'                                                                                                                                         \n");
    printf ("                                                              `Y8P' \n");
    printf ("\n");

    printf("Enter Board Size\nWidth:");
    scanf("%d",&W);
    printf("Height:");
    scanf("%d",&H);
    printf("Manual or Auto (1 or 2)\n");
    scanf("%d",&x);

    printf("Cells should spawn in the order of\n");
    printf("Enter 1 to 10:\n");
    scanf("%d",&temp);

    run(board);



return 0;
}
int main()
{
    
    fp=fopen("loginID.txt","a");
    fp1=fopen("phonenumber.txt","a");
    fp2=fopen("password.txt","a");
    fp3=fopen("name.txt","a");
    g1=fopen("rps.txt","a");
    g2=fopen("ttt.txt","a");
    g3=fopen("hc.txt","a");
    g4=fopen("h.txt","a");
    g5=fopen("cgl.txt","a");
    system("cls");
    system("color A");
    printf("  ooooooooo.   oooo                .    .o88o.                                        \n");
    printf("  `888   `Y88. `888              .o8    888 `                                         \n");
    printf("   888   .d88'  888   .oooo.   .o888oo o888oo   .ooooo.  oooo d8b  ooo. .oo.  .oo.    \n");
    printf("   888ooo88P'   888  `P  )88b    888    888    d88' `88b `888  8P `888P  Y88bP Y88    \n");
    printf("   888          888   .oP 888    888    888    888   888  888      888   888   888    \n");
    printf("   888          888  d8(  888    888 .  888    888   888  888      888   888   888    \n");
    printf("  o888o        o888o `Y888^8o    888   o888o   `Y8bod8P' d888b    o888o o888o o888o   \n");
    printf("\n\n\n\n");
    printf("'||%c   /||`                          '||%c   /||`                               \n",92,92);
    printf(" ||%c%c.//||           ''               ||%c%c.//||                                \n",92,92,92,92);
    printf(" || %c / ||   '''|.   ||  `||''|,      || %c / ||  .|''|, `||''|,  '||  ||`      \n",92,92);
    printf(" ||     ||  .|''||   ||   ||  ||      ||     ||  ||..||  ||  ||   ||  ||       \n");
    printf(".||     ||. `|..||. .||. .||  ||.    .||     ||. `|...  .||  ||.  `|..'|.      \n");
    int n,i;

    abcd:
            printf("\n\n\t\t1.TO SIGN UP\n\t\t2.TO LOGIN\n\t\t");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        system("cls");
        printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
        signup();
        break;
    case 2:system("cls");
        printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
        login();
        break;
    default:
        printf("Invalid Input");
        goto abcd;


    }
    
    ab:
    printf("\n1||   EDIT  PROFILE   ||");
    printf("\n2||   VIEW  PROFILE   ||");
    printf("\n3|| LIST ALL PROFILES ||");
    printf("\n4||     CURRENCY      ||");
    printf("\n5||    GAME LIBRARY   ||");
    printf("\n6||       EXIT        ||\n");
    int s;
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        {
            system("cls");
            printf("\n\n\n\tLOADING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            edit();
            goto ab;
            break;
        }
    case 2:
        {
            system("cls");
            printf("\n\n\n\tLOADING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            viewprofile();
            goto ab;
            break;
        }
    case 3:
        {
            system("cls");
            printf("\n\n\n\tLOADING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            viewlist();
            goto ab;
            break;
        }
    case 4:
        {
            system("cls");
            printf("\n\n\n\tLOADING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            money();
            goto ab;
            break;
        }
    case 5:
        {
            system("cls");
            printf("\n\n\n\tLOADING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            buygame();
            goto ab;
            break;
        }
    case 6:
        {
           printf("\nREMAINING BALANCE:%d",a[k].wallet);
            printf("\nTHIS AMOUNT HAS BEEN SENT TO YOUR ACCOUNT\n");
            a[k].wallet=0;
            printf("\nREMAINING BALANCE:%d",a[k].wallet);
            printf("\n\tEXITING\n");
            for(i=0;i<=20;i++)
            {
                fordelay(100000000);
                printf("%c",220);
            }
            break;
        }
        default:
        {
            printf("Invalid Input\nTry Again");
            goto ab;
            break;
        }

    }
    fclose(fp);
    fclose(fp1);
}



