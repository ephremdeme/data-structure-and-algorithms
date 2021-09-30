#include <bits/stdc++.h>
using namespace std;

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

    //Wave form
    cout<<"WAVE FORM"<<endl;
    for(col=0;col<n;col++){
        if(col%2==0)
        {
            for(row=0;row<m;row++)
            {
                cout<<a[row][col]<<" ";
            }

        }
        else{
            for(row=m-1;row>=0;row--)
            {

                cout<<a[row][col]<<" ";
            }
        }
    }



    return 0;
}

/*
Output
Enter row and column
3
4
1 2 3 4
5 6 7 8
9 10 11 12
WAVE FORM
1 5 9 10 6 2 3 7 11 12 8 4
*/

