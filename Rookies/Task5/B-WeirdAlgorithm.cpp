#include <iostream>
#include <vector>

using namespace std;
void sequence(long long n)
{
    if(n==1)
        return ;

    if(n%2==0)
    {
        n=n/2;
    }else{
        n=n*3+1;
    }
    cout<<n<<" ";
    sequence(n);
}
int main() {
    long long n;
    cin>>n;
    cout<<n<<" ";
    sequence(n);

    return 0;
}
