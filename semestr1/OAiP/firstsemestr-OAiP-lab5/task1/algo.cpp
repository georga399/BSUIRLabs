void Solve(long double X[], long double A[], long double B[], int size)
{
    for(int i = 0; i<size; i++)
    {
        X[i] = (A[i]==0)? 0: (-1)*B[i]/A[i];
    }
}