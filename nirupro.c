#include<stdio.h>
#include<conio.h>
struct process
{
int pid;
int bt;
int rt;
int p;
int wt;
};
struct process p[10];
struct process temp;
void swap(struct process *m,struct process *n)
{
	temp=*n;
	*n=*m;
	*m=temp;
}
main()
{
	int esttime=0;
	int i,j,n,t=0;
	printf("Enter the number of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("Enter burst time of p%d:",i+1);
		scanf("%d",&p[i].bt);
		p[i].rt=p[i].bt;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(p[j+1].bt<p[j].bt)
			{
				swap(&p[j],&p[j+1]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		p[i+1].wt=p[i].wt+p[i].rt;
	}
	for(i=0;i<n;i++)
	{
		printf("P%d:%d\n",p[i].pid,p[i].bt);
		printf("WT%d:%d\n",p[i].pid,p[i].wt);
	}
	for(i=0;i<n;i++)
	{
		esttime=esttime+p[i].bt;
	}
	for(i=0;i<n;i++)
	{
	  p[i].p=1+(p[i].wt/esttime);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(p[j+1].p>p[j].p)
			{
				swap(&p[j],&p[j+1]);
			}
		}
		printf("\nGanttchart:");
		for(i=0;i<n;i++)
		{
			printf("|%d\t",t);
			printf("P%d:%d\t",p[i].pid,p[i].bt);
			t=t+p[i].rt;
			printf("%d|",t);
			p[i].rt=0;
			
		}
	}
}
