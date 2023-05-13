#include <iostream>
#include <cassert>
int CountInterestingInInterval(int interval_end) //O(1)
{
    return (interval_end+1)/10;
}
void Testing();
int main()
{
    Testing();
    int q, n;
    std::cin >> q;
    for (int i = 0; i<q; i++)
    {
        std::cin >> n;
        std::cout << CountInterestingInInterval(n) << std::endl;
    }
}
void Testing()
{
    assert(CountInterestingInInterval(9)==1);
    assert(CountInterestingInInterval(2)==0);
    assert(CountInterestingInInterval(32)==3);
    assert(CountInterestingInInterval(1)==0);
}