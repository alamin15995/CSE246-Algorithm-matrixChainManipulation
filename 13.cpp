#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int n;;//declare number of matrix
int m [101][101];//use for storing multiplication value
int s [101][101];//use for parenthesis
int p[101];//dimension array: A1,A2.......An


//calculate the total multiplication of given matrix index number
int mcm(int i, int j)
{
    if (i==j)//Base Case
    {
        return 0;
    }
    if(m[i][j]==0) //value not set yet
    {
        int Min=INF;//value set
        int index=1;
        for (int k=1; k<=j-i; k++)
        {
            int x=mcm(i,i+k-1)+mcm(i+k,j)+p[i-1]*p[i+k-1]*p[j];
            //Calculate the left sub-chain multiplication: MCM(i,i+k-1)
             //Calculate the left sub-chain multiplication: MCM(i+k,j)
            if (x<Min)
            {
                Min=x;
                index=k;
            }
        }
        m[i][j]=Min;// minimum value
        s[i][j]=index;//minimum index
    }
    return m[i][j];//value always return from storage matrix

}

void parenthesis(int i, int j)
{

    if (i==j)//Base case
    {
        cout<<"A"<<i;
        return ;
    }
    int k =s[i][j];

    cout<<"(";
    parenthesis(i, i+k-1);//print: left sub-chain
    parenthesis(i+k, j);//print: right sub-chain
    cout <<")";
}

int main()
{

    cin >>n;//input number of matrix from user
    for (int i=1; i<=n; i++)
    {
        int row, col;// declare  row and col
        cin >>row>>col;// input row and col from user
        p[i-1]=row;//store number of row into dimension array, start from  index: Po
        p[i]=col;//store number of row into dimension array, start from  index: P1
    }

    cout<<"Print Dimension array"<<endl;
    for (int i=0; i<=n; i++)
        cout<<p[i]<<" ";//print dimension array
        cout<<endl<<endl;


  cout<<"Storing Matrix"<<endl;
    int result= mcm(1,n);
    for (int i=1; i<=n; i++)//print matrix
    {
        for (int j=1; j<=n; j++)
        {
            cout<<m[i][j]<<" ";
        }
            cout<<endl;
    }     cout<<endl<<endl;


    cout<<"Total Multiplication Need:"<<result<<endl<<endl;
    cout<<endl<<endl;
    cout<<"Parenthesied:";
    parenthesis(1,n);
}

