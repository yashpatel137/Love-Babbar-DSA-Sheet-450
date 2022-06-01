//Method 1
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            pq.push(mat[i][j]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

//Method 2
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low=mat[0][0];
    int high=mat[n-1][n-1];
    while(low<high)
    {
        int mid=(low+high)/2;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=(upper_bound(mat[i],mat[i]+n,mid)-mat[i]);
        }
        if(count<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    return low;
}