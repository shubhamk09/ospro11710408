#include<iostream> 
using namespace std;
const int np = 5;
const int nr = 4;
static bool finish[np];
int i;
int j;
int count=0;
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

void calneed(int all[np][nr],int mm[np][nr]){
	for(i = 0; i<np; i++){
		for(j = 0; j<nr; j++){
			need[i][j]=mm[i][j]-all[i][j];
		}
	}
//		for(j=0;j<nr;j++){
//	        printf("\n %d",avail[i]);
//			}
}
bool check(int a,int temp[nr]){
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
	void add(int t){
	
	for(j=0;j<nr;j++){
		work[j]=allo[t][j]+work[j];	
		
	}
	for(j=0;j<nr;j++){
	        printf("\n %d",work[j]);
			}
	}
	

int main(){
	 								// Step 1
	for(i=0;i<nr;i++){
		work[i] = avail[i];
	}
	for(j=0;j<nr;j++){
	        printf("\n %d",work[j]);
	        
			}
	for(i=0;i<np;i++){
		finish[i] = false;
	}              //     step 1 finished
	calneed(allo,mx);
	for(i=0;i<np;i++){
		printf("\n");
		for(j=0;j<nr;j++){
			printf("%d",need[i][j]);
		}
	}
	for(i = 0; i<np; i++){
		if(finish[i]==false){
			bool ch = check(i,work);
			if(ch==true){
				finish[i]=true;
				add(i);
			
		}
	}	

}	
}
