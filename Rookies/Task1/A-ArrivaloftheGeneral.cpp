#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    auto max= max_element(arr.begin(),arr.end());
    int maxindex = distance(arr.begin(),max);

    auto min= min_element(arr.rbegin(),arr.rend());
    int minindex = distance(arr.begin(),min.base())-1;

    int secmin = n-1-minindex;
    int allsec;
    if(maxindex>minindex) {
        allsec=maxindex+secmin-1;
    }else{
        allsec=maxindex+secmin;
    }
    cout<<allsec<<endl;
    return 0;
}