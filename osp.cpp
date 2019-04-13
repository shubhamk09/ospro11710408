#include<iostream> 
using namespace std;
const int np = 5;
const int nr = 4;
bool finish[np];
int i;
int j;
int count=0;
int avail[nr] = {1,5,2,0};
int work[nr];
int  allo[np][nr] = {{0,0,1,2},
 					{1,0,0,0},
					{1,3,5,4},
					{0,6,3,2},
					{0,0,1,4}};
int  mx[np][nr] = {{0,0,1,2},
				   {1,7,5,0},
				   {2,3,5,6},
				   {0,6,5,2},
				   {0,6,5,6}};

int need[np][nr];

void calneed(int all[np][nr],int mm[np][nr]){
	for(i = 0; i<np; i++){
		for(j = 0; j<nr; j++){
			need[i][j]=mm[i][j]-all[i][j];
		}
	}
}
bool check(int a,int temp[nr]){
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
		printf("\n %d",avail[t]);
	}
//	for(j=0;j<nr;j++){
//	        printf("\n %d",work[i]);
//			}
}
int main(){
	  // Step 1
	for(i=0;i<nr;i++){
		work[i] = avail[i];
	}
	for(j=0;j<nr;j++){
	        printf("\n %d",work[i]);
	        
			}
	for(i=0;i<np;i++){
		finish[i] = false;
	}              //     step 1 finished
//	for(i=0;i<np;i++){
//		printf("%d",finish[i]);
//		printf("%s", finish[i]?"true":"false");
//	}
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
