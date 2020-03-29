#include<stdio.h>
struct scheduling
{
    int pname, arvlTime, waiturnT, turnT, priority,burT, burTcopy;
}Q1[15],Q2[15];
void main()
{
	struct schedule;
    int i,time=0,FixedT,RobinT,bu_t=0,largest,totalP,count=0,k,pf2=0,totalP2,n,pos,j,flag=0,y;
   float WTime=0,TATime= 0,avgWtime,avgTAtime;
    scanf("%d", &totalP);
    n=totalP;
    for(i=0;i<totalP;i++)
    {
        scanf("%d",&Q1[i].pname);
        scanf("%d",&Q1[i].arvlTime);
        scanf("%d",&Q1[i].burT);
        Q1[i].burTcopy=Q1[i].burT;
        scanf("%d",&Q1[i].priority);
    }
    scanf("%d",&FixedT);
    scanf("%d",&RobinT);
    for(i=0;i<totalP;i++)
    {
        pos=i;
        for(j=i+1;j<totalP;j++)
        {
            if(Q1[j].arvlTime<Q1[pos].arvlTime)
                pos=j;
        }
        temp=Q1[i];
        Q1[i]=Q1[pos];
        Q1[pos]=temp;
    }
    
	totalP2=pf2;
	for(count=0;totalP2!=0;) 
	{ 
		if(Q2[count].burT<=RobinT&&Q2[count].burT>0) 
    	{ 
    		time=time+Q2[count].burT; 
    		Q2[count].burT=0; 
    		flag=1; 
    	} 
    	else if(Q2[count].burT>0) 
    	{ 
    		Q2[count].burT=Q2[count].burT-RobinT; 
    		time=time+RobinT; 
    	} 
    	if(Q2[count].burT==0&&flag==1) 
    	{ 
    		totalP2=totalP2-1; 
    		Q2[count].turnT=time-Q2[count].arvlTime;
			Q2[count].waiturnT=Q2[count].turnT-Q2[count].burTcopy; 
    		TATime=TATime+time-Q2[count].arvlTime; 
    		WTime=WTime+time-Q2[count].arvlTime-Q2[count].burTcopy;
    		for(k=count; k<totalP2;k++)
    			Q2[k]=Q2[k+1];count=count-1;
    		flag=0;
    	} 
    	if(count==totalP2-1) 
      		count=0; 
    	else 
    		count=count+1; 
    }
}
