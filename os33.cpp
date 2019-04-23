#include<iostream>
#include<stdio.h> 
#include<windows.h> 
using namespace std;
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat,ch;
    system("cls");
		
    cout<<"\t\t\t\t\t SELECT YOUR CHOICE :"<<endl;
    cout<<"\t\t\t\t\t  1. PROCESSES WITH DIFFERENT PRIORITY "<<endl;
    cout<<"\t\t\t\t\t  2. PROCESSES WITH SAME PRIORITY "<<endl;
    cout<<"\t\t\t\t\t\t\t ENTER YOUR CHOICE HERE : ";
    cin>>ch;
    switch(ch)
    {
    	case 1:
    		{
    			cout<<"\t\t\t\t\tEnter Total Number of Process: ";
    			
    			
    			cin>>n;
    			cout<<"\n\t\t\t\t\t Enter Burst Time and Priority\n"<<endl;
                for(i=0;i<n;i++)
                {
        			cout<<"\n\t\t\t\t\tProcess ["<<i+1<<"]\n";
        			cout<<"\t\t\t\t\tBurst Time:";
        			cin>>bt[i];
        			cout<<"\t\t\t\t\tPriority:";
        			cin>>pr[i];
        			p[i]=i+1;       
    			}
    			for(i=0;i<n;i++)
    			{
        			pos=i;
        			for(j=i+1;j<n;j++)
        			{
            			if(pr[j]<pr[pos])
                		pos=j;
        			}
 
        		   	temp=pr[i];
        			pr[i]=pr[pos];
        			pr[pos]=temp;
 
        			temp=bt[i];
        			bt[i]=bt[pos];
        			bt[pos]=temp;
 
        			temp=p[i];
        			p[i]=p[pos];
        			p[pos]=temp;
    			}
 
    				wt[0]=0;     
 
    				for(i=1;i<n;i++)
    			{
        			wt[i]=0;
        			for(j=0;j<i;j++)
            		wt[i]+=bt[j];
 
        			total+=wt[i];
    			}
 
    			avg_wt=total/n;      
    			total=0;
 
    			cout<<"\n\t\t\t\t\tProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    			for(i=0;i<n;i++)
    			{
        			tat[i]=bt[i]+wt[i];  
        			total+=tat[i];
        			cout<<"\n\t\t\t\t\tP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    			}
 
    			avg_tat=total/n;   
    			cout<<"\n\n\t\t\t\t\t\t\tAverage Waiting Time="<<avg_wt;
    			cout<<"\n\t\t\t\t\t\t\tAverage Turnaround Time="<<avg_tat;
			}break;
			case 2:
				{
					int i, limit, total = 0, x, counter = 0, time_quantum; 
      				int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10],priority[10], temp[10]; 
      				float average_wait_time, average_turnaround_time;
      				cout<<("\n\t\t\t\t\tEnter Total Number of Processes:\t"); 
      				cin>>limit; 
      				x = limit; 
      				for(i = 0; i < limit; i++) 
      				{
            			cout<<("\n\t\t\t\t\tEnter Details of Process\n");
            			cout<<"\t\t\t\t\t"<<(i+1)<<"  "<<"Arrival Time:  ";
            			cin>>arrival_time[i];
            			cout<<"\t\t\t\t\t"<<(i+1)<<"  "<<"Burst Time:\t";
            			cin>>burst_time[i]; 
            			temp[i] = burst_time[i];
      				} 
      				cout<<("\n\t\t\t\t\tEnter Time Quantum:\t"); 
      				cin>>time_quantum; 
      				cout<<("\n\t\t\t\t\tProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      				for(total = 0, i = 0; x != 0;) 
      				{ 
            			if(temp[i] <= time_quantum && temp[i] > 0) 
            			{ 
                  			total = total + temp[i]; 
                  			temp[i] = 0; 
                  			counter = 1; 
            			} 
            				else if(temp[i] > 0) 
            				{ 
                  				temp[i] = temp[i] - time_quantum; 
                  				total = total + time_quantum; 
            				} 
            				if(temp[i] == 0 && counter == 1) 
            				{ 
                  				x--; 
                  				cout<<"\n\t\t\t\t\tProcess"<<(i+1)<<"\t\t"<<burst_time[i]<<"\t\t\t"<<total - arrival_time[i]<<"\t\t\t"<<total - arrival_time[i] - burst_time[i]; 
                  				wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  				turnaround_time = turnaround_time + total - arrival_time[i]; 
                  				counter = 0; 
            				} 
            				if(i == limit - 1) 
            				{
                  				i = 0; 
            				}
            				else if(arrival_time[i + 1] <= total) 
            				{
                  				i++;
            				}
            				else 
            				{
                  				i = 0;
            				}
     					 } 
      				average_wait_time = wait_time * 1.0 / limit;
      				average_turnaround_time = turnaround_time * 1.0 / limit;
        			cout<<endl;
        			cout<<endl;
        			Sleep(1000);
        			system("color 4");
					Sleep(1000);
      				printf("\n\n\t\t\t\t\t\t\tAverage Waiting Time:\t%f", average_wait_time); 
      				printf("\n\t\t\t\t\t\t\tAvg Turnaround Time:\t%f\n", average_turnaround_time); 
					
			}break;
			default:
				cout<<" WRONG ENTRY "<<endl;
    
		}
    return 0;
}
