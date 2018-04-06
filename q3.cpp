#include <bits/stdc++.h>
using namespace std;
struct P
{
	int proid,burt,arrt;
};
void wtprocess(P process[],int nofp,int wt[])
{	
	int temp[nofp],value=0,ep=0;
	int t=0,least_bt_p=0,e=0,ft,minet=5000;
	bool flag=false;	
	for(int i=0;i<nofp;i++)
{
	temp[i]=process[i].burt;
}
	while(e!=nofp)
	{
		if(ep==0)
		{
				system("cls");
				cout<<"Order of Execution of processes:";
				ep=ep+1;
		}
		for(int i=0;i<nofp;i++)
		{			
			if((process[i].arrt<=t)&&(temp[i]<minet&&temp[i]>0))
			{
				minet=temp[i];
				least_bt_p=i;
				flag=true;				
			}			
		}		
		if(flag==false)
		{
			t++;
			continue;
		}
		value=temp[least_bt_p];
		t=t+value;
		temp[least_bt_p]=0;
		minet=5000;		
		if(temp[least_bt_p]==0)
		{
			cout<<"\n"<<process[least_bt_p].proid;
			e++;
			ft=t+2;
			t=t+2;                
			wt[least_bt_p]=ft-process[least_bt_p].burt-process[least_bt_p].arrt;			
		}		
	}
} 
void tatprocess(P process[],int nofp,int wt[],int tat[])
{
	for(int i=0;i<nofp;i++)
	{
		tat[i]=process[i].burt+wt[i];		 
	}
}
void avgatime(P process[],int nofp)
{
	int wt[nofp],tat[nofp];
	int twt=0,ttat=0;	
	wtprocess(process,nofp,wt);
	tatprocess(process,nofp,wt,tat);
	
	cout << "\n\n\n | Process No. |"<< " | Burst time | "<< " | Waiting time | "<< " | Turn around time | \n";
	
	for(int i=0;i<nofp;i++)
	{
		twt=twt+wt[i];
		ttat=ttat+tat[i];
		cout << "\t" << process[i].proid << " \t\t"<< process[i].burt << " \t\t " << wt[i]<< " \t\t " << tat[i] << "\n";
	}
		cout << "\nAverage waiting time = "<< (float)twt / (float)nofp;
    	cout << "\nAverage turn around time = "<< (float)ttat / (float)nofp;
}
int main()
{
	int nofprocess;
	cout<<"\n Enter number of processes to be executed :\n";
	cin>>nofprocess;
	P process[nofprocess];
	for(int i=0;i<nofprocess;i++)
	{
		system("cls");
		process[i].proid=i+1;
		cout<<"\nEnter the arrival time for process no. "<<i+1<<" :\t";
		cin>>process[i].arrt;
		cout<<"\nEnter the burst time for process no. "<<i+1<<" :\t";
		cin>>process[i].burt;	
	}
	avgatime(process,nofprocess);
	return 0;	
}
