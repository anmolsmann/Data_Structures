void maxActivities(int s[], int f[], int n){
    int i,j;
    i=0;
    cout<<i;
    for (j = 1; j < n; j++)
    {
        if (s[j]>=f[i])
        {
            cout<<j<<" ";
            i=j;
        }
        
    }
    
}