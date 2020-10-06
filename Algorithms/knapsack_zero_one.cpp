#include<iostream>

using namespace std;

int max(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int main(){
	
	int noOfGoods;
	cout << "Number of goods: ";
	cin >> noOfGoods;
	
	int maxWeight;
	cout << "Max weight: ";
	cin >> maxWeight;
	
	int dataArr[noOfGoods][2];
	
	cout << "Weight  Profit:\n";
	
	for(int i=0; i<noOfGoods; i++){
		
		cin >> dataArr[i][0] >> dataArr[i][1];
	}
	
	for(int i=0; i<noOfGoods; i++){
		
		for(int j=i; j<noOfGoods; j++){
			
			if(dataArr[i][0] >= dataArr[j+1][0]){
				
				int temp1 = dataArr[i][0];
				int temp2 = dataArr[i][1];
				
				dataArr[i][0] = dataArr[j+1][0];
				dataArr[i][1] = dataArr[j+1][1];
				
				dataArr[j+1][0] = temp1;
				dataArr[j+1][1] = temp2;
				
			}
		}
	}
	
	int knackMatrix[noOfGoods+2][maxWeight+4];
	
	for(int i=0; i<(noOfGoods+2); i++){
		
		for(int j=0; j<(maxWeight+4); j++){
			
			knackMatrix[i][j] = 0;
		}
	}
	
	for(int i=3; i<(maxWeight+4); i++){
		
		knackMatrix[0][i] = i-3;
		knackMatrix[1][i] = 0;
	}
	
	for(int i=1; i<(noOfGoods+2); i++){
		
		knackMatrix[i][2] = i-1;
		knackMatrix[i][3] = 0;
		
		
		knackMatrix[i][0] = dataArr[i-1][1];
		knackMatrix[i][1] = dataArr[i-1][0];
		
	}
	
	
	for(int i=2; i<(noOfGoods+2); i++){
		
		for(int w=4; w<(maxWeight+4); w++){
			
			int val1 = (knackMatrix[0][w]-knackMatrix[i][1]);
			int val =(int) max(knackMatrix[i-1][w], (knackMatrix[i-1][val1+3] + knackMatrix[i][0]));
			
			if(knackMatrix[0][w] < knackMatrix[i][1]){
		        
				knackMatrix[i][w] = knackMatrix[i-1][w];
			}else{
				
				knackMatrix[i][w] = val;
			}
		}
	}
	
	for(int i=0; i<(noOfGoods+2); i++){
		
		for(int j=0; j<(maxWeight+4); j++){
			
			cout << knackMatrix[i][j] << "\t";
		}
		cout << "\n" ;
	}
	
	int profit = knackMatrix[noOfGoods+1][maxWeight+3];
	
	for(int i=(noOfGoods+2); i>=2; i--){
		
		int prevAvail = 0;
		
		
		
		for(int j=3; j<(maxWeight+4); j++){
			
			if(profit == knackMatrix[i-1][j]){
				prevAvail = 1;
				break;
			}
		}
		
		if(prevAvail == 0){
			profit -= knackMatrix[i][0];
			cout << knackMatrix[i][1] << "\t";
		}
	}
    return 0;
}
