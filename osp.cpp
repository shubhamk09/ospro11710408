#include<iostream> 
using namespace std;
const int np = 5;
const int nr = 4;
static bool finish[np];
int i;
int j;
int ss[5];
int count=0;
int count2=0;
static int avail[nr] = {1,5,2,0};
static int work[nr];
static int  allo[np][nr] = {{0,0,1,2},
 					{1,0,0,0},
					{1,3,5,4},
					{0,6,3,2},
					{0,0,1,4}};
static int  mx[np][nr] = {{0,0,1,2},
				   {1,7,5,0},
				   {2,3,5,6},
				   {0,6,5,2},
				   {0,6,5,6}};

static int need[np][nr];

void calneed(int all[np][nr],int mm[np][nr]){   //function to calculate need
	for(i = 0; i<np; i++){
		for(j = 0; j<nr; j++){
			need[i][j]=mm[i][j]-all[i][j];
		}
	}
}
bool check(int a,int temp[nr]){ //function to check weather need<work
	int count;
	for(int k=0;k<nr;k++){
		
		if(need[a][k]<=temp[k]){
			count=count+1;
		}
		
	}
	if(count==nr){
			return true;
		}
		else{
			return false;
		}
}
	void add(int t){       //function to add alocation to work
	
	for(j=0;j<nr;j++){
		work[j]=allo[t][j]+work[j];	
		
	}			
	}
		
	

int main(){
	 //int count3=0;
	 int temp;						// Step 1
	for(i=0;i<nr;i++){
		work[i] = avail[i];
	}
	for(i=0;i<np;i++){
		finish[i] = false;
	}                             //     step 1 finished
	calneed(allo,mx);
	
	while(count2<np)             //loop will run until all the process are completed
	{
		temp=count2;	
		for(i = 0; i<np; i++)
		{
			if(finish[i]==false)		// checking the value of false for each process
			{
				bool ch = check(i,work);
				if(ch==true)				// cheking need<work
				{
					finish[i]=true;
					add(i);
					ss[count2++]=i;        // putting the process in sef sequence
										
				}
				if(count2==temp){
					goto isnot;            //if the value of temp is same as count2 then the loop will end
					
				}
				cout<<"";	
			}
		}
		
	}
	goto istrue;
	isnot:
		cout<<"System is not in Safe state \n";
		goto end;
	istrue:
		cout<<"Safe Sequence is \n";
		for (i = 0; i < np ; i++) 
			cout << ss[i] << " ";
		cout<<"\n System is in safe State \n";
	end:
	cout<<"Thank you";	

}	

