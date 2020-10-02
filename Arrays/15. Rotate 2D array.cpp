#include <bits/stdc++.h>
using namespace std;

//Rotate anti clockwise by 90 degree
void rotate(int a[][100],int n)
{
    for(int row=0;row<n;row++){
        int s_c=0; //start column
        int e_c=n-1; //end column
        if(s_c<e_c){
            swap(a[row][s_c],a[row][e_c]);
            s_c++;
            e_c--;
        }
    }

    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(i<j){
            swap(a[i][j],a[j][i]);
        }
    }
}
}

int main()
{
    int row=0,col=0;
    int a[100][100];
    int m,n;
    cout<<"Enter row and column"<<endl;
    cin>>m>>n;

    int val=1;
    for(int row=0;row<m;row++){
        for(col=0;col<n;col++){
                a[row][col]=val;
                val++;
                cout<<a[row][col]<<" ";

        }
        cout<<endl;
    }

    cout<<"After rotating"<<endl;
    rotate(a,n);

     for(int row=0;row<m;row++){
        for(col=0;col<n;col++){
               cout<<a[row][col]<<" ";

        }
        cout<<endl;
           }







    return 0;
}

/*
Output
Enter row and column
4
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
After rotating
4 8 12 16
2 6 10 14
3 7 11 15
1 5 9 13
*/


