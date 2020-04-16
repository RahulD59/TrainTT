#include<stdio.h>
#include<stdlib.h>

char stations[][18]={"KASARA","TITWALA","KALYAN","DOMBIVALI","THANE","AIROLI","JUINAGAR","NERUL","VASHI","GHATKOPAR","DADAR"
						,"CSMT","CHURCHGATE","BANDRA","ANDHERI","BORIVALI","BHAYANDAR","VIRAR"};

struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
struct node *head[18];
int visited[18];
int parent[18];
int distance[18];
int w=0;

void enqueue(int src) //function to insert data into the queue
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=src;
	temp->next=NULL;
	if(front==NULL)
	{
		front=rear=temp;
		w++;
	}
	else
	{
		rear->next=temp;
		rear=temp;
		w++;
	}
}
int dequeue()//function to remove data from queue
{
	  struct node* temp = front;
		if(front == NULL)
		printf("EMPTY QUEUE\n");
 	 	else{
				int temp_dequeue = temp->data;
   				front = front->next;
				w--;
				free(temp);
				return temp_dequeue;
	}
}

struct node *create(struct node *head[],int s,int d)  // function to create adjacency list
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	if(head[s]==NULL)
	{
		head[s]=temp;
		temp->next=NULL;

	}
	else
	{
		temp->next=head[s];
		head[s]=temp;
	}
	return head[s];
}
void BFS(int src,struct node *head[])  // function to find route
{
	int i=0;
	for(i=0;i<18;i++)
	{
		visited[i]=0;
		parent[i]=-1;
		distance[i]=-1;
	}
	enqueue(src);  //calling function
	visited[src]=1;
	distance[src]=0;
	while(w!=0)
	{
		int x=dequeue();
		struct node *temp=head[x];
		while(temp!=NULL)
		{
			if(visited[temp->data]==0)  //checking whether route is visited or not
			{
				enqueue(temp->data);
				visited[temp->data]=1;
				parent[temp->data]=x;
				distance[temp->data]=distance[x]+1;
			}
			temp=temp->next;
		}
	}


}
void route(int src,int dest,struct node *head[])  // function to print route
{
	BFS(src,head);
	printf("\nROUTE:\n------------------------------------------------------------------------------------------------\n");
	while(parent[dest]!=-1)
	{
		printf("%s <-",stations[dest]);
		dest=parent[dest];
	}
	printf("%s",stations[src]);
	printf("\n------------------------------------------------------------------------------------------------\n");
}
void timetable(int src,int dest)  // function to print trains timetable
{
	if(src==0&&dest>0)
	{
		printf("\nTRAINS FROM KASARA:\n");
		printf("4:25  AM CSMT S\n6:00  AM CSMT F\n7:24  AM CSMT SF");
		printf("\n9:00  AM CSMT S\n12:00 PM CSMT F\n2:12  PM CSMT SF");

	}
	if(src==1&&dest<1)
	{
		printf("\nTRAINS FROM TITWALA:");
		printf("\n7:00  AM KASARA S\n9:45 PM KASARA F\n10:12  AM KASARA SF");
		printf("\n1:00  PM KASARA S\n2:00 PM KASARA F\n6:56  PM KASARA SF");
	}
	if(src==1&&dest>1)
	{
		printf("\nTRAINS FROM TITWALA:");
		printf("\n5:25   AM CSMT S\n6:00  AM CSMT F\n6:24   AM CSMT SF");
		printf("\n11:00  AM CSMT S\n12:00  PM CSMT F\n5:55  PM CSMT SF");
	}
	if(src==2&&dest<2)
	{
		printf("\nTRAINS FROM KALYAN:");
		printf("\n7:00  AM KASARA S\n9:45 PM KASARA F\n10:12  AM KASARA SF");
		printf("\n1:00  PM KASARA S\n2:00 PM KASARA F\n6:56  PM KASARA SF");
	}
	if(src==2&&dest>2)
	{
		printf("\nTRAINS FROM KALYAN:");
		printf("\n5:25   AM CSMT S\n6:00  AM CSMT F\n6:24   AM CSMT SF");
		printf("\n11:00  AM CSMT S\n12:00  PM CSMT F\n5:55  PM CSMT SF");
	}
	if(src==3&&dest<3)
	{
		printf("\nTRAINS FROM DOMBIVALI:");
		printf("\n7:00  AM KASARA S\n9:45 PM KASARA F\n10:12  AM KASARA SF");
		printf("\n1:00  PM KASARA S\n2:00 PM KASARA F\n6:56  PM KASARA SF");
	}
	if(src==3&&dest>3)
	{
		printf("\nTRAINS FROM DOMBIVALI:");
		printf("\n5:25   AM CSMT S\n6:00  AM CSMT F\n6:24   AM BORIVALI SF");
		printf("\n11:00  AM CSMT S\n12:00  PM BORIVALI F\n5:55  PM CSMT SF");
		printf("\n6:00  PM CSMT S\n7:00  PM CSMT F\n8:55  PM BORIVALI SF");
	}
	if(src==4&&dest<4)
	{
		printf("\nTRAINS FROM THANE:");
		printf("\n7:00  AM KASARA S\n9:45 PM KASARA F\n10:12  AM KASARA SF");
		printf("\n1:00  PM KASARA S\n2:00 PM KASARA F\n6:56  PM KASARA SF");
	}
	if(src==4&&dest>4)
	{
		printf("\nTRAINS FROM THANE:");
		printf("\n5:25   AM CSMT S\n6:00  AM CSMT F\n6:24   AM VASHI SF");
		printf("\n11:00  AM CSMT S\n12:00  PM VASHI F\n5:55  PM CSMT SF");
		printf("\n6:00  PM CSMT S\n7:00  PM CSMT F\n8:55  PM VASHI SF");
	}
	if(src==5&&dest<5)
	{
		printf("\nTRAINS FROM AIROLI:");
		printf("\n7:00  AM THANE S\n9:45 PM THANE F\n10:12  AM THANE SF");
		printf("\n1:00  PM THANE S\n2:00 PM THANE F\n6:56  PM THANE SF");
	}
	if(src==5&&dest>5)
	{
		printf("\nTRAINS FROM AIROLI:");
		printf("\n5:25   AM VASHI S\n6:00  AM VASHI F\n6:24   AM VASHI SF");
		printf("\n11:00  AM VASHI S\n12:00  PM VASHI F\n5:55  PM VASHI SF");
	}
	if(src==6&&dest<6)
	{
		printf("\nTRAINS FROM JUINAGAR:");
		printf("\n7:00  AM THANE S\n9:45 PM THANE F\n10:12  AM THANE SF");
		printf("\n1:00  PM THANE S\n2:00 PM THANE F\n6:56  PM THANE SF");
	}
	if(src==6&&dest>6)
	{
		printf("\nTRAINS FROM JUINAGAR:");
		printf("\n5:25   AM VASHI S\n6:00  AM VASHI F\n6:24   AM VASHI SF");
		printf("\n11:00  AM VASHI S\n12:00  PM VASHI F\n5:55  PM VASHI SF");
	}

	if(src==7&&dest<7)
	{
		printf("\nTRAINS FROM NERUL:");
		printf("\n7:00  AM THANE S\n9:45 PM THANE F\n10:12  AM THANE SF");
		printf("\n1:00  PM THANE S\n2:00 PM THANE F\n6:56  PM THANE SF");
	}
	if(src==7&&dest>7)
	{
		printf("\nTRAINS FROM NERUL:");
		printf("\n5:25   AM VASHI S\n6:00  AM VASHI F\n6:24   AM VASHI SF");
		printf("\n11:00  AM VASHI S\n12:00  PM VASHI F\n5:55  PM VASHI SF");
	}
	if(src==8&&dest<8)
	{
		printf("\nTRAINS FROM VASHI:");
		printf("\n7:00  AM THANE S\n9:45 PM THANE F\n10:12  AM THANE SF");
		printf("\n1:00  PM THANE S\n2:00 PM THANE F\n6:56  PM THANE SF");
	}
    if(src==9&&dest<9)
    {
        printf("\nTRAINS FROM GHATKOPAR: ");
        printf("\n6:40 AM KASARA S\n7:10 AM KASARA F\n8:30 AM KASARA SF");
        printf("\n10:40 AM KASARA S\n2:10 PM KASARA F\n4:30 PM KASARA S");
    }
    if(src==9&&dest>9)
    {
        printf("\nTRAINS FROM GHATKOPAR: ");
        printf("\n5:45 AM CSMT S\n7:35 AM CSMT F\n10:30 AM CSMT SF");
        printf("\n4:40 PM CSMT F\n8:10 PM CSMT F\n11:30 PM CSMT S");
    }
    if(src==10 && dest<10)
    {
        printf("\nTRAINS FROM DADAR: ");
        printf("\n6:30 AM KASARA S\n10:10 AM KASARA F\n1:30 PM KASARA SF");
        printf("\n3:40 PM KASARA S\n5:10 PM KASARA F\n7:30 PM KASARA S");
    }
    if(src==10&&dest==11)
    {
        printf("\nTRAINS FROM DADAR: ");
        printf("\n6:45 AM CSMT S\n10:35 AM CSMT F\n12:30 PM CSMT SF");
        printf("\n4:40 PM CSMT F\n8:10 PM CSMT F\n11:30 PM CSMT S");
    }
    if(src==10&&dest==12)
    {
        printf("\nTRAINS FROM DADAR: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
    if(src==10&&dest>12)
    {
        printf("\nTRAINS FROM DADAR: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==11)
    {
        printf("\nTRAINS FROM CSMT:");
		printf("\n7:00  AM KASARA S\n9:45 PM KASARA F\n10:12  AM KASARA SF");
		printf("\n1:00  PM KASARA S\n2:00 PM KASARA F\n6:56  PM KASARA SF");
    }
    if(src==12)
    {
        printf("\nTRAINS FROM CHURCHGATE: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==13 &&dest==12)
    {
        printf("\nTRAINS FROM BANDRA: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
    if(src==13&&dest>13)
    {
        printf("\nTRAINS FROM BANDRA: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }

    if(src==14 &&dest<13)
    {
        printf("\nTRAINS FROM ANDHERI: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
    if(src==14&&dest>14)
    {
        printf("\nTRAINS FROM ANDHERI: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==15&&dest==3)
    {
        printf("\nTRAINS FROM BORIVALI: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==15&&dest==12)
    {
        printf("\nTRAINS FROM BORIVALI: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
    if(src==15&&dest>15)
    {
        printf("\nTRAINS FROM BORIVALI: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==16 &&dest<16)
    {
        printf("\nTRAINS FROM BHAYANDER: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
    if(src==16&&dest>16)
    {
        printf("\nTRAINS FROM BHAYANDER: ");
        printf("\n6:30 AM VIRAR S\n10:35 AM VIRAR F\n12:30 PM VIRAR SF");
        printf("\n4:40 PM VIRAR F\n8:10 PM VIRAR F\n11:30 PM VIRAR S");
    }
    if(src==17)
    {
        printf("\nTRAINS FROM VIRAR: ");
        printf("\n6:00 AM CHURCHGATE S\n10:35 AM CHURCHGATE F\n12:30 PM CHURCHGATE SF");
        printf("\n4:40 PM CHURCHGATE F\n8:10 PM CHURCHGATE F\n11:30 PM CHURCHGATE S");
    }
}
void display(struct node *head[],int v)  // function to display adjacency list
{
	struct node *temp;
	int i;
	for(i=0;i<18;i++)
	{
		temp=head[i];
		printf("%d",(i));
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()  // main function
{
	int i;
	for(i=0;i<18;i++)
	{
		visited[i]=0;
		parent[i]=-1;
		head[i]=NULL;
	}


	int array[18][18]={	{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
				{0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
				{0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0},
				{0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
				{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
				};

    printf("Adjacency Matrix IS:\n");

    int j;
    for(i=0;i<18;i++)
	{
		for(j=0;j<18;j++)
		{
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}

   for(i=0;i<18;i++)
	{
		for(j=0;j<18;j++)
		{
			if(array[i][j]==1)
			{
				head[i]=create(head,i,j);
			}

		}
	}

	printf("\n\nAdjacency List Is:\n");  
	display(head,18);

    printf("Stations:\n0>KASARA\t1>TITWALA\t2>KALYAN\t3>DOMBIVALI\t4>THANE\t5>AIROLI\n6>JUINAGAR\t7>NERUL\t8>VASHI\t9>GHATKOPAR\t10>DADAR\t11>CSMT\t12>CHURCHGATE\n13>BANDRA\t14>ANDHERI\t15>BORIVALI\t16>BHAYANDAR\t17>VIRAR\n\n");

	int src,dest,temp=0;
	do
    {
        printf("Enter Source Station:"); // taking source from the user
        scanf("%d",&src);
        switch(src) 
        {
            case 0:
            printf("Where Do You Want To Go:11.CSMT\n");
            scanf("%d",&dest);
            break;

            case 1:
            printf("Where Do You Want To Go:\n0.Kasara\t11.CSMT\n");
            scanf("%d",&dest);
            break;

            case 2:
            printf("Where Do You Want To Go:\n0.Kasara\t11.CSMT\n");
            scanf("%d",&dest);
            break;
            case 3:
            printf("Where Do You Want To Go:\n0.Kasara\t11.CSMT\t15.BORIVALI\n");
            scanf("%d",&dest);
            break;

            case 4:
            printf("Where Do You Want To Go:\n0.Kasara\t8.VASHI\t11.CSMT\n");
            scanf("%d",&dest);
            break;

            case 5:
            printf("Where Do You Want To Go:\n4.THANE\t8.VASHI\n");
            scanf("%d",&dest);
            break;

            case 6:
            printf("Where Do You Want To Go:\n4.THANE\t8.VASHI\n");
            scanf("%d",&dest);
            break;

            case 7:
            printf("Where Do You Want To Go:\n4.THANE\t8.VASHI\n");
            scanf("%d",&dest);
            break;

            case 8:
            printf("Where Do You Want To Go:\n4.THANE\n");
            scanf("%d",&dest);
            break;

            case 9:
            printf("Where Do You Want To Go:\n0.Kasara\t11.CSMT\n");
            scanf("%d",&dest);
            break;

            case 10:
            printf("Where Do You Want To Go:\n0.Kasara\t11.CSMT\t12.CHURCHGATE\t17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 11:
            printf("Where Do You Want To Go:\n0.Kasara\n");
            scanf("%d",&dest);
            break;

            case 12:
            printf("Where Do You Want To Go:\n17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 13:
            printf("Where Do You Want To Go:\012.CHURCHGATE\t17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 14:
            printf("Where Do You Want To Go:\n12.CHURCHGATE\t17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 15:
            printf("Where Do You Want To Go:\n3.DOMBIVALI\t12.CHURCHGATE\t17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 16:
            printf("Where Do You Want To Go:\n12.CHURCHGATE\t17.VIRAR\n");
            scanf("%d",&dest);
            break;

            case 17:
            printf("Where Do You Want To Go:\n12.CHURCHGATE\n");
            scanf("%d",&dest);
            break;
        }

        route(src,dest,head);
        timetable(src,dest);
        printf("\nEnter 1 to continue and 0 to exit\n");
        scanf("%d",&temp);
    }while(temp!=0);

	return 0;
}
