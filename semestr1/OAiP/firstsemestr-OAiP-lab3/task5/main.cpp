#include <iostream>
#include <cmath>
long long factorial(int N)
{
	long long F = 1; 
	
	for(int i=1; i<=N; ++i)
	{
		F *= i; 
	}
	return F; 
}
int main()
{   
    setlocale(LC_ALL, "Russian");
    int n, N;
    long double x, S;
    std::cout<<"Введите количество членов ряда: ";
    std::cin>>n;
    std::cout<<"Введите количество чисел, от которых сравниваются значения функций: ";
    std::cin>>N;
    for(int i = 0; i<N; i++)
    {
        std::cout<<"Введите x"<<i<<" :";
        std::cin>>x;
        S=0;
        for(int j=0; j<n; j++)
        {
            S+=powl(-1, j)*powl(x, 2*j+1)/factorial(2*j+1);
        }
        std::cout<<"По ряду Тейлора: "<<S<<"\t Стандартная функция: "<<sinl(x)<<std::endl;
        
    }

}