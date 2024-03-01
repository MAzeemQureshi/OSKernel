#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>

using namespace std;
int n;

struct process_struct{
						int pid;
						int at;
						int bt;
						string status;
  						string priority; 
						int ct,wt,tat,rt,start_time;
						}ps[20];

void getdata(int n){
				for(int i=0;i<n;i++)
				{
				ps[i].priority="high";
		    	ps[i].pid=i;
		    	cout<<"Process ID:"<<ps[i].pid<<endl;
		    	ps[i].status="ready";
				cout<<"Process Status: "<<ps[i].status<<endl;
				cout<<"\nEnter Process" <<i<< "Arrival Time: ";
				cin >> ps[i].at;
				cout<<"\nEnter Process" <<i<< "Burst Time: ";
				cin >> ps[i].bt;
				ps[i].pid=i;
				
				}
}

void fcfs(int n){
	for(int i=0;i<n;i++)
				{
				if(ps[i].start_time = (i==0)){
					ps[i].at;
				}
				  else{
				  	max(ps[i].at, ps[i-1].ct);
				  }  
				ps[i].ct =  ps[i].start_time + ps[i].bt;
				ps[i].tat = ps[i].ct-ps[i].at;       
				ps[i].wt = ps[i].tat-ps[i].bt;
				ps[i].rt=ps[i].wt;
				}
}

void sjf(int n){
	bool is_completed[100]={false},is_first_process=true;
						int current_time = 0;
						int completed = 0;;
						
						
						while(completed!=n)
						{
						int min_index = -1;
						int minimum = INT_MAX;
						for(int i = 0; i < n; i++) {
						if(ps[i].at <= current_time && is_completed[i] == false) {
						    if(ps[i].bt < minimum) {
						        minimum = ps[i].bt;
						        min_index = i;
						    }
						    if(ps[i].bt== minimum) {
						        if(ps[i].at < ps[min_index].at) {
						            minimum= ps[i].bt;
						            min_index = i;
						        }
						    }
						}
						}
						
						if(min_index==-1)
						{
						current_time++;
						}
						else
						{
						ps[min_index].start_time = current_time;
						ps[min_index].ct = ps[min_index].start_time + ps[min_index].bt;
						ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
						ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
						ps[min_index].rt = ps[min_index].wt;
						
						completed++;
						is_completed[min_index]=true;
						current_time = ps[min_index].ct;
						is_first_process = false;
						}
						}
						
}

void showprocess(int n){
	cout<<"\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n";
						for(int i=0;i<n;i++)
						cout<<i<<"\t\t"<<ps[i].at<<"\t"<<ps[i].bt<<"\t\t"<<ps[i].ct<<"\t"<<ps[i].tat<<"\t"<<ps[i].wt<<"\t"<<ps[i].rt<<endl;
						cout<<endl;
}

void destroyprocess(int n){
	int list=0;
	for(int i=0;i<n;i++){
		if(ps[i].pid >= 0){
			list++;
		}
	}
	if(list > 0){
		showprocess(n);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		int id;
		int found=0;
		cout<<"\nEnter Process id to Delete: ";
	    cin>>id;
	    for(int i=0; i<n; i++)
	    {
	        if(ps[i].pid==id)
	        {
	        	found++;
	            for(int j=i; j<(n-1); j++)
	                ps[j] = ps[j+1];
	            found++;
	            i--;
	            n--;
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Deleted Successfully!";
	    cout<<endl;
	}
}

void suspendprocess(int n){
	int list=0;
	for(int i=0;i<n;i++){
		if(ps[i].pid >= 0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(n);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		int id;
		int found=0;
		cout<<"\nEnter Process no to Suspend: ";
	    cin>>id;
	    
	    for(int i=0; i<n; i++)
	    {
	        if(ps[i].pid==id)
	        {
	        	found++;
	            ps[i].status = "suspend";
	            ps[i].priority = "medium";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Suspended Successfully!";
	    cout<<endl;
	}
}
void resumeprocess(int n){
	int id;
	int found=0;
	int list=0;
	for(int i=0;i<n;i++)
	{
		if(ps[i].status=="suspend"){
			list++;
		}
	}
	if(list > 0){
		cout<<"Process Number\tArrival Time\tBurst Time\n";
		for(int i=0;i<n;i++)
		{
			if(ps[i].status=="suspend"){
				cout<<ps[i].pid<<"\t\t"<<ps[i].at<<"\t\t"<<ps[i].bt<<endl;		
			}
		}
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		
		cout<<"\nEnter Process no to Resume: ";
	    cin>>id;
	    for(int i=0; i<n; i++)
	    {
	        if(ps[i].pid==id)
	        {
	        	found++;
	            ps[i].status = "ready";
	            ps[i].priority = "high";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
}

void blockprocess(int n){
	int list=0;
	for(int i=0;i<n;i++){
		if(ps[i].pid>=0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(n);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		int id;
		int found=0;
		cout<<"\nEnter Process id to Block: ";
	    cin>>id;
	    for(int i=0; i<id; i++)
	    {
	        if(ps[i].pid==id)
	        {
	        	found++;
	            ps[i].status = "block";
	            ps[i].priority = "low";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Blocked Successfully!";
	    cout<<endl;
	}
}

void wakeupprocess(int n){
	int id;
	int found=0;
	int list=0;
	for(int i=0;i<n;i++)
	{
		if(ps[i].status=="block"){
			list++;
		}
	}
	if(list > 0){
		cout<<"Process Number\tArrival Time\tBurst Time\n";
		for(int i=0;i<n;i++)
		{
			if(ps[i].status=="block"){
				cout<<ps[i].pid<<"\t\t"<<ps[i].at<<"\t\t"<<ps[i].bt<<endl;		
			}
		}
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

		cout<<"\nEnter Process Name to Resume: ";
	    cin>>id;
	    for(int i=0; i<n; i++)
	    {
	        if(ps[i].status=="block"){
	        	if(ps[i].pid==id)
		        {
		        	found++;
		            ps[i].status = "ready";
		            ps[i].priority = "high";
		        }
			}
			else{
				goto found0;
			}
	    }
	    if(found==0)
	    found0:
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
}

void changepriority(int n){
		int list=0;
	for(int i=0;i<n;i++){
		if(ps[i].pid>=0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(n);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		int id;
		int found=0;
		cout<<"\nEnter Process Name to Change Priority: ";
	    cin>>id;
	    for(int i=0; i<n; i++)
	    {
	        if(ps[i].pid==id)
	        {
	        	found++;
	        	string temp;
	        	cout<<"Enter Process Priority: ";
	            cin>>temp;
	            if(temp=="high"){
	            	ps[i].status="ready";
	            	ps[i].priority="high";
				}
				else if(temp=="medium"){
					ps[i].status="suspend";
	            	ps[i].priority="medium";
				}
				else if(temp=="low"){
					ps[i].status="block";
	            	ps[i].priority="low";
				}
				else{
					cout<<"Invalid"<<endl;
				}
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else{
	    	cout<<"\nPriority Changed Successfully!"<<endl;
		}
	        
	}

}

void pcb(int n){
	for(int i=0; i<n; i++)
		    {
		    	
		        cout<<"ID: "<<ps[i].pid<<endl;
		        cout<<"Status: "<<ps[i].status<<endl;
		        cout<<"Priority: "<<ps[i].priority<<endl;
				cout<<"-----------------------------------"<<endl;
			}
}

				bool comparatorAT(struct process_struct a,struct process_struct b)
				{
				int x =a.at;
				int y =b.at;
				return x < y;
				
				} 
				
				bool comparatorPID(struct process_struct a,struct process_struct b)
				{
				int x =a.pid;
				int y =b.pid;
				return x < y;
				}


int main(){
	int num;
	cout<<"----------------------OS Kernel Simulation----------------------"<<endl;
	cout<<endl<<endl;
	cout<<endl;
	cout<<endl<<endl;
	cout<<"-----------------------Muhammad Azeem Qureshi---------------------"<<endl;
	getch();
	mainmenu:
	system("CLS");
	cout<<"--------------------------------------------"<<endl;
	cout<<"Press"<<endl;
	cout<<"1. Process Management"<<endl;
	cout<<"2. Memory Management"<<endl;
	cout<<"3. I/O Management"<<endl;
	cout<<"4. Other Operations"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>num;
	switch(num){
		case 1:
			menu:
			system("CLS");
			cout<<"--------------------------------------------"<<endl;
			cout<<"Welcome to Process Management:"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<endl;
			cout<<"Press"<<endl;
			cout<<"1.  Create a Process"<<endl;
			cout<<"2.  Destroy a Process"<<endl;
			cout<<"3.  Suspend a Process"<<endl;
			cout<<"4.  Resume a Process"<<endl;
			cout<<"5.  Block a Process"<<endl;
			cout<<"6.  Wakeup a Process"<<endl;
			cout<<"7.  Dispatch a Process"<<endl;
			cout<<"8.  Change Process Priority"<<endl;
			cout<<"9.  Process Communication with Other Processes"<<endl;
			cout<<"10. PCB"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"11. FCFS Process Scheduling"<<endl;
			cout<<"12. SJF Process Scheduling"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"0: Back"<<endl;
			cin>>num;
			if(num == 0){
					goto mainmenu;
				
				}			
			else if(num==1)
			{
				system("CLS");
				cout<<"Enter total number of processes: ";
				cin>>n;
				getdata(n);
				back:
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==2){
				system("CLS");
				destroyprocess(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==3){
				system("CLS");
				suspendprocess(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==4){
				system("CLS");
				resumeprocess(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==5){
				system("CLS");
				blockprocess(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==6){
				system("CLS");
				wakeupprocess(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==8){
				system("CLS");
				changepriority(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num==10){
				system("CLS");
				pcb(n);
				cout<<"0 back"<<endl;
				cin >> num;
				if(num==0)
				{
					goto menu;
				}else{
					cout<<"Error"<<endl;
					goto back;
				}
			}
			else if(num == 12){	
				system("CLS");
					cout<<"--------------------------------------------"<<endl;
					cout<<"SJF Process:"<<endl;
					cout<<"--------------------------------------------"<<endl;
					sjf(n);
					showprocess(n);
					cout<<"-----------------------------------------------------------"<<endl;		
				cout<<"1: Menu"<<endl;
				cout<<"2: Exit"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				cin>>num;
				if(num==1){
					system("CLS");
				goto menu;
				}
			}
			else if(num==11){
				system("CLS");
				cout<<"--------------------------------------------"<<endl;
				cout<<"FCFS Process:"<<endl;
				cout<<"--------------------------------------------"<<endl;
				sort(ps,ps+n, comparatorAT);	
				fcfs(n);
				showprocess(n);
				cout<<"-----------------------------------------------------------"<<endl;		
				cout<<"1: Menu"<<endl;
				cout<<"2: Exit"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				cin>>num;
				if(num==1){
				system("CLS");
				goto menu;
				}			
}			
}
	return 0;
}
