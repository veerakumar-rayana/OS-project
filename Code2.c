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
    time=Q1[0].arvlTime;
    for(i=0;totalP!=0;i++)
    {
    	while(count!=FixedT)
    	{
    		count=count+1;
    		if(Q1[i].arvlTime<=time)
    		{
    			for(j=i+1;j<totalP;j++)
    			{
    				if(Q1[j].arvlTime==time && Q1[j].priority<Q1[i].priority)//pr<
    				{
    					Q2[pf2]=Q1[i];
						pf2=pf2+1;
    					for(k=i; k<totalP-1;k++)
    						Q1[k]=Q1[k+1];
    					totalP=totalP-1;
						count=0;
    					i=j-1;
    					j=j-1;
					}
				}
			}
			time=time+1;
			Q1[i].burT=Q1[i].burT-1;
			if(Q1[i].burT==0)
			{
				Q1[i].turnT=time-Q1[i].arvlTime;
				Q1[i].waiturnT=Q1[i].turnT-Q1[i].burTcopy;
				WTime=WTime+time-Q1[i].waiturnT; 
    			TATime=TATime+time-Q1[i].turnT;
    			for(k=i;k<totalP-1;k++)
    				Q1[k]=Q1[k+1];i=i-1;
    			totalP=totalP-1;
				count=FixedT;break;
			}
		}
		count=0;
		if(Q1[i].burT!=0)
		{
			Q2[pf2]=Q1[i];
			pf2=pf2+1;
			for(k=i;k<totalP-1;k++)
    			Q1[k]=Q1[k+1];
    		totalP=totalP-1;
		}
			if(i==totalP-1)
				i=-1;
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
