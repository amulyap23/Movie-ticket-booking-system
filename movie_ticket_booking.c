#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct book
{    char name[15];
	  int seat[10];
  	int id;
}b;
void booking();
void cancel();
void cancel_bkp();
void admin();
void movie();
void delete();
void contact();
void price();
void details();
int q,no;
int Id=1000;
void main()
{ 
  int d,b,flag=1;
  char movie1[20];
  while(flag) 
  {
  printf("----------------------------------------------------------------\n");
  printf("                         TICKETNEW                              \n");
  printf("----------------------------------------------------------------\n");
  printf("                     1.BOOK A TICKET                            \n");
  printf("                     2.CANCEL A TICKET                          \n");
  printf("                     3.TICKET DETAILS                           \n");
  printf("                     4.ADMIN                                    \n");
  printf("                     5.CONTACT US                               \n");
  printf("                     6.EXIT                                     \n");
  printf("----------------------------------------------------------------\n");
  printf("ENTER YOUR CHOICE\n");
  int a;
  scanf("%d",&a);
  switch(a)
  {
    case 1: booking();
            main();
            break;
    case 2: cancel();
            main();
            break;
    case 3: details();
            main();
            break;
    case 4: admin();
            main();
            break;
    case 5: contact();
            main();
            break;
    case 6: flag=0;
            break;
    default: printf("Invalid choice\n");
             main();
  }
  }
}
void admin(){
    char t;
    int q,flag=1,d,b;
    printf("enter ur id: ");
    scanf("%d",&d);
    printf("enter password: ");
    scanf("%d",&b);
  if(d==202203&&b==16231){
    while(flag)
    {
  printf("----------------------------------------------------------------\n");
  printf("                            ADMIN                               \n");
  printf("----------------------------------------------------------------\n");
  printf("                     1. CHANGE OF PRICE                         \n");
  printf("                     2. ADD A MOVIE                             \n");
  printf("                     3. DELETE A MOVIE                          \n");
  printf("                     4. EXIT                                    \n");
  printf("----------------------------------------------------------------\n");
  printf("ENTER YOUR CHOICE\n");
  scanf("%d",&q);
  switch(q)
  {
    case 1: price();
            break;
    case 2: movie();
            break;
    case 3: delete();
            break;
    case 4: flag=0;
            //main();
            break;
   default: printf("Invalid choice\n");
             break;
             admin();
  } 
  }
}
else{
  printf("Invalid ID or Password\n"); 
  admin();
  }
}
void contact()
{
  printf("contact no 1: 8468294001\n");
  printf("contact no 2: 8468294002\n");
  printf("EMAIL ID: ticketnew2@gmail.com\n");
}
void movie()
{
    int flag=1,price1;  
    char movie1[20]; char u[1];
    FILE *fpi;
    FILE *fpo;
    fpi=fopen("movie.txt","a");
    fpo=fopen("price.txt","a");
    while(flag)
    {
        printf("enter movie1 name: ");
        scanf("%s",movie1);
        printf("enter movie price: ");
        scanf("%d",&price1);
        fprintf(fpi,"%s\n",movie1);
        fprintf(fpo,"%d\n",price1);
        printf("\nDo u want enter another movie?(y/n): ");
        scanf("%s",u);
        if (*u!='y'){
            printf("\nEntry completed\n");
            flag=0;
        }
    }
    rewind(fpi);
    rewind(fpo);
    fclose(fpi);
    fclose(fpo);
}
void delete()
{
      FILE *fp;
        int count=0;
        char filename[]="movie.txt",line[200];char string[20];
        printf("enter the movie name u would like to delete: ");
        scanf("%s",string);
        //printf("%s",string);
        fp=fopen(filename,"r");
        if(!fp)
        {
                perror("could not find the file");
                exit(0);
        }
        while ( fgets ( line, 200, fp ) != NULL )// read a line
        {
                if(strstr(line,string))
                 {count++;
                 break;}
                else 
                 {count++;}
        }
        fclose ( fp );
        FILE *fptr1, *fptr2,*fptr3,*fptr4;
      int ctr=0;char str[200],c,p;
      char ch;char a[20];int y=0;
     fptr1 = fopen("movie.txt","r");
     fptr2 = fopen("movie1.txt","w"); 
     fptr3 = fopen("price.txt","r");
     fptr4 = fopen("price1.txt","w");    
        while (!feof(fptr1)) 
        {
            fgets(str, 200, fptr1);  
            if (!feof(fptr1)) 
            {
                ctr++;
                if (ctr != count) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        while (!feof(fptr3)) 
        {
            fgets(a, 200, fptr3);  
            if (!feof(fptr3)) 
            {
                y++;
                if (y != count) 
                {
                    fprintf(fptr4, "%s", a);
                }
            }
        }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    remove("h.txt");
    remove("p.txt");
    fptr1 = fopen("movie.txt","w");
    fptr2 = fopen("movie1.txt","r"); //   rewind files - goto first line
    fptr3 = fopen("price.txt","w");
    fptr4 = fopen("price1.txt","r");   
           c = fgetc(fptr2);
           while (c != EOF)
          {
           fputc(c, fptr1);
           c = fgetc(fptr2);
          }
           p = fgetc(fptr4);
           while (p != EOF)
          {
           fputc(p, fptr3);
           p = fgetc(fptr4);
          }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    printf("movie %s is deleted!\n",string);
}
void price()
{
  FILE *fp,*fpo,*fpi;
  int ctr=0,count=0,price2;
  char str[200],line[200],string[20],sprice2[10],c;
  char *str1[10];
  fpos_t pos1, pos2;
  printf("enter the movie name: ");
  scanf("%s",string);
  printf("enter the price");
  scanf("%d",&price2);
  fp=fopen("movie.txt","r");
  fpo=fopen("price.txt","r");
  fpi=fopen("price2.txt","w");
    if(!fp)
    {
      perror("could not find the file");
      exit(0);
    }// get line number of movie
     while ( fgets ( line, 200, fp ) != NULL )// read a line
        {
                if(strstr(line,string))
                 {count++;
                 break;}
                else 
                 {count++;}
        }
    
    while (!feof(fpo)) 
        {
            fgets(str, 200, fpo);  
            if (!feof(fpo)) 
            {
                ctr++;
                if (ctr != count) 
                {
                    fprintf(fpi, "%s", str);
                }
                else
                {
                  fprintf(fpi,"%d\n", price2);
                }
            }
        }
  fclose(fp);
  fclose(fpo);
  fclose(fpi);
  remove("price.txt");
  fp = fopen("price.txt","w");
  fpo = fopen("price1.txt","r");
   c = fgetc(fpo);
           while (c != EOF)
          {
           fputc(c, fp);
           c = fgetc(fpo);
          }
  fclose(fp);
  fclose(fpo);
  printf("Price is changed!\n");
}

void booking()
{
  Id++;
  struct book b;
  time_t t;  
  time(&t);
  FILE *fp1;FILE *fp2,*fp3;
  int ch,d;char show[15];
  b.id=Id; int i=1,r;char p[20];
  char display[50];
  char c[30];
  char *time;
  fp1=fopen("movie.txt","r");
  fp2=fopen("price.txt","r");
  fp3=fopen("ticket.csv","a");
  if(fp1==NULL && fp2==NULL)
  {
    printf("FILE NOT FOUND\n");
    exit(0);
  }
  printf("Enter Date(dd/mm/yy):");
  scanf("%s",&c);
  printf("WHICH MOVIE  DO YOU WANT TO WATCH?\n");
  while((fgets(display,50,fp1)&&fgets(p,50,fp2))!=0)
  {
    printf("%d %s price:%s",i,display,p);
    i++;
  }
  printf("\n");
  scanf("%d",&ch);
  rewind(fp1);
  rewind(fp2);
  i=1;
  while(fgets(display,50,fp1)!=NULL)
  {
   fgets(p,50,fp2);
   if(i==ch){
    printf("You have selected:");
    printf(" %s                  price:%s",display,p);
    display[strlen(display)-1]='\0';
    fprintf(fp3,"%s,",display);
    break;
   }
    i++;
  }
  int x=atoi(p);
  int flag=1;
  while(flag)
  {
  printf("SELECT TIME:\n");
  printf("1) 10:00AM\n");
  printf("2) 4:00PM\n");
  printf("3) 8:00PM\n");
  scanf("%d",&r);
  switch(r)
  {
    case 1:time="10:00AM";
            fprintf(fp3,"10:00AM,");
           flag=0;
           break;
    case 2:time="4:00PM";
           fprintf(fp3,"4:00PM,");
          flag=0;
           break;
    case 3:time="8:00PM";
            fprintf(fp3,"8:00PM,");
           flag=0;
           break;
    default:printf("Invalid choose again\n");
  }
  }
  printf("                                                          SCREEN                                 ");
  printf("\n");
  printf("\n");
  for(int i=1;i<=100;i++)
  {
    if(i%1==0)
    {
      printf(" ");
    }
    printf("%d\t",i);
  }
  printf("\n");
  printf("HOW MANY SEATS DO YOU WANT:");
  scanf("%d",&no);
  fprintf(fp3,"%d,",no);
  for(int j=0;j<no;j++)
  {
    printf("WHICH SEAT NUMBER YOU WANT?");
    scanf("%d",&b.seat[j]);
     fprintf(fp3,"%d,",b.seat[j]);
  }
  printf("PLEASE ENTER YOUR NAME:");
  scanf("%s",b.name);
 fprintf(fp3,"%s,",b.name);
  printf("----------------------------------------------------------------\n");
  printf("                THEATER TICKET                                  \n");
  printf("----------------------------------------------------------------\n");
  char *ct=ctime(&t);
  ct[strcspn(ct, "\n")] = '\0';
  printf("%s                                                              \n",ct);
  fprintf(fp3,"%s,%d,",ct,b.id);
  printf("BOOKING ID:%d                                                   \n",b.id);
  printf("                                    CUSTOMER:%s                 \n",b.name);
  printf("                                    SHOW NAME:%s                \n",display);
  printf("DATE:%s                                                         \n",c);
  c[strlen(c)-1]='\0';
  fprintf(fp3,"%s,",c);
  printf("TIME:%s                                                   \n",time);
  printf("                                    HALL:01                     \n");
  for(int j=0;j<no;j++)
  {
  printf("                                    SEAT NO:%d                 \t \n",b.seat[j]);
  }
  printf("                                    PRICE:%d                   \n",x*no);
  fprintf(fp3,"%d,\n",x*no);
  printf("----------------------------------------------------------------\n");
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  //main();
}
void details()
{
FILE *fp=fopen("ticket.csv","r");
char *p[100];int s[1000],no,pr;
char line[1000],*mn,*time,*n,*ct,*i,*name,*date,*price,r[200];int e;
printf("enter your booking id:");
scanf("%d",&e);
sprintf(r,"%d",e);
while(fgets(line,1000,fp)!=NULL)
{
  mn=strtok(line,",");
  time=strtok(NULL,",");
  n=strtok(NULL,",");
  no=atoi(n);
  for(int i=0;i<no;i++)
  {
    p[i]=strtok(NULL,",");
    s[i]=atoi(p[i]);
  }
  name=strtok(NULL,",");
  ct=strtok(NULL,",");
  i=strtok(NULL,",");
  date=strtok(NULL,",");
  price =strtok(NULL,",");
  pr=atoi(price);
   
if(strcmp(i,r)==0)
{
  printf("----------------------------------------------------------------\n");
  printf("                THEATER TICKET                                  \n");
  printf("----------------------------------------------------------------\n");
  printf("%s                                                              \n",ct);
  printf("BOOKING ID:%s                                                   \n",i);
  printf("                                    CUSTOMER:%s                 \n",name);
  printf("                                    SHOW NAME:%s                \n",mn);
  printf("DATE:%s                                                         \n",date);
  printf("TIME:%s                                                   \n",time);
  printf("                                    HALL:01                     \n");
  for(int j=0;j<no;j++)
  {
  printf("                                    SEAT NO:%d                 \t \n",s[j]);
  }
  printf("                                    PRICE:%d                   \n",pr);
  printf("----------------------------------------------------------------\n");
printf("\n");
}
}
fclose(fp);
//main();
}
void cancel()
{
FILE *fp1=fopen("ticket.csv","r");
FILE *fp2=fopen("ticket1.csv","w");
char line[1000],str[200];
int booking_id;
printf("enter your booking id:");
scanf("%d",&booking_id);
sprintf(str,"%d",booking_id);

while ( fgets ( line, 200, fp1 ) != NULL && !feof(fp1))// read a line
  {
   // printf("##%s\n",line);
    if(!strstr(line,str))
    {
      fprintf(fp2,"%s",line);
    }
    
  }
fclose(fp2);
fclose(fp1);

FILE *fp3=fopen("ticket.csv","w");
FILE *fp4=fopen("ticket1.csv","r");
while ( fgets ( line, 200, fp4 ) != NULL && !feof(fp4))// read a line
  {
    fprintf(fp3,"%s",line); 
  }
fclose(fp3);
fclose(fp4);
printf("Your ticket is cancelled!\n");
}






