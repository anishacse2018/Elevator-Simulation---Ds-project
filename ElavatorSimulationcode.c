#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int front=-1,rear=-1,a[30],b,c=1,o=0,g,h,desired_floor,n,temp;
char s[4];
int m=0;
struct que{
    char data;
    struct que *next;
};
struct que *front1=NULL;
struct que *rear1=NULL;
void arrowup();
void arrowdown();
int full(int);
void pattern(int);
void delete(int,int);
void insert(int,int);
void search(int,int);
void display(int);
int movement(int,int);
void emergency();
void main()
{
    int i,j,k=0,t,currentfloor=0,e,d,y,x,z,q,u,l;
    printf("The number of floors in the apartment are-> 16\n");
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
         printf("%d ",k);
         k++;
        }
        printf("\n");
    }
printf("<|> for opening\t  >|< for closing\t  EMERGENCY\n");
printf("The maximum load the lift can weigh is =1000 kgs\n");
printf("Current floor number is-> 0\n");
    for(i=0;i<16;i++)
    {
        insert(16,i);
    }
    while(c==1)
    {
    scanf("%d",&c);
    if(c!=1)
        {
            break;
        }
    printf("Floor at which people want to access the lift->");
    scanf("%d",&h);
         if(h==16)
         {
             printf("Pls enter valid floor number");
             scanf("%d",&h);
         }
          e=currentfloor;
          x=e;
          currentfloor=h;
          q=currentfloor;
       while(q>e)
      {
        printf(" %d\n",x++);
        arrowup();
        q--;
      }
      while(q<e)
     {  
         printf(" %d\n",x--);
         arrowdown();
         q++;
      }
      search(n,h);
      display(n);
      printf("\n");
      pattern(h);
      delete(n,h);
     printf("Doors Opening\n ");
     printf("People enter the elevator\n");
      printf("Which floor do u want to got to->?");
      scanf("%d",&t);
      currentfloor=movement(h,t);
    }
printf("The elevator is at %d floor.Now, it is at rest\n",currentfloor);}
int full(int n)
{
    if(front==0 && rear==n-1)
    {
        printf("Queue is full");
        return 0;
    }
    if(front==rear+1)
    {
        printf("Queue is full");
        return 0;
    }
    return 1;
}
void insert(int n,int d)
{   int r;
    r=full(n);
    if(r==0)
    {
        return;
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        rear=(rear+1)%n;
        a[rear]=d;
    }
}
void display(int n)
{
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",a[i]);
    }
    else
    {
        for (int i = front; i < n; i++)
            printf("%d ", a[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", a[i]);
    }
}

void search(int n,int b)
{
    int p;
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            {if(a[i]==b)
            a[i]=-5;}
    }
    else
    {
        for (int i = front; i < n; i++)
         {if(a[i]==b)
            a[i]=-5;}
 
        for (int i = 0; i <= rear; i++)
             {if(a[i]==b)
            a[i]=-5;}
    }
}
void delete(int n,int b)
{
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            {if(a[i]==-5)
            a[i]=b;}
    }
    else
    {
        for (int i = front; i < n; i++)
         {if(a[i]==-5)
            a[i]=b;}
 
        for (int i = 0; i <= rear; i++)
             {if(a[i]==-5)
            a[i]=b;}
    }
}
void pattern(int l)
{
    int i,j,k=0;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(k==l)
            {
                printf("**");
            }
         printf("%d ",k);
         k++;
        }
        printf("\n");
    }
}
void arrowup()
{
 int i=5;
    printf(" ^\n");
    for(i=0;i<3;i++)
    {printf(" |\n");}
    printf("\n");
}
void arrowdown()
{
    int i=5;
    for(i=0;i<3;i++)
    {printf(" |\n");}
     printf(" v");
     printf("\n");
}
int movement(int currentfloor,int desired_floor)
{
    int e,q,x,start_t,end_t,d,y,g;
    e=currentfloor;
          x=e;
          currentfloor=desired_floor;
          q=currentfloor;
          printf("Doors open and people enter the elevator->\n");
           printf("Sum of weights of people in the elevator");
     scanf("%d",&g);
     if(g>1000)
     {
         printf("Overload!!!\n");
     }
         start_t = clock();
      for(y=0;y<10000000;y++){}
      end_t=clock();
     printf("%d\n",end_t);
          if(end_t<10000)
         {
         scanf("%s",s);
         d=0;
      if(s[d]=='>')
      {printf("Doors closing\n");} 
     }
      if(end_t>10000)
    {
        printf("Doors are about to close->Did everyone get in?\n");
        scanf("%s",s);
        d=0;
      if(s[d]=='>')
      {printf("Doors closing\n");}
      else{
          printf("Doors are still open\n");
          printf("Doors Closing\n");
      }}
       while(q>e)
      {
        
        printf(" %d\n",x++);
        arrowup();
        emergency();
        q--;
      }
      while(q<e)
     {  
         printf(" %d\n",x--);
         arrowdown();
         emergency();
         q++;
      }
      search(16,desired_floor);
        display(16); 
      pattern(desired_floor);
      delete(16,desired_floor);
      
      printf("\n Current floor is %d\n",desired_floor);
      delete(16,desired_floor);
      return desired_floor;
}
void emergency()
{
    int l,p;
    printf("\nIs there any case of emergency-? if yes,choose Emergency by pressing on 1\n");
    scanf("%d",&l);
    if(l==1)
    {
        printf("As it is an emergency,pls enter the floor where u want to get off the elevator->\n");
        scanf("%d",&p);
        pattern(p);
        printf("Doors opening\n");
        printf("Elevator is at %d\n",p);
        printf("Pls Get down... \n");
        exit(0);
    }
}








