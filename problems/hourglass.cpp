#include<bits/stdc++.h> 
using namespace std; 
const int R = 5; 
const int C = 5; 

int findMaxSum(int mat[R][C]) 
{ 
	if (R<3 || C<3) 
		return -1; 

	int max_sum = INT_MIN; 
	for (int i=0; i<R-2; i++) 
	{ 
		for (int j=0; j<C-2; j++) 
		{ 
			int sum = (mat[i][j]+mat[i][j+1]+mat[i][j+2])+ 
					(mat[i+1][j+1])+ 
				(mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2]); 

			
			max_sum = max(max_sum, sum); 
		} 
	} 
	return max_sum; 
} 


int main() 
{ 
	int mat[][C] = {{1, 2, 3, 0, 0}, 
					{0, 0, 0, 0, 0}, 
					{2, 1, 4, 0, 0}, 
					{0, 0, 0, 0, 0}, 
					{1, 1, 0, 1, 0}}; 
	int res = findMaxSum(mat); 
	if (res == -1) 
		cout << "Not possible" << endl; 
	else
		cout << "Maximum sum of hour glass = "
			<< res << endl; 
	return 0; 
} 
