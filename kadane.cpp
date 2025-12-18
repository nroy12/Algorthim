#include <bits/stdc++.h>
using namespace std;

class kadane
{

private:
    int arr[10];

public:
    // constructor:

    kadane(int myarr[10])
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = myarr[i];
        }
    }

    // methods of class:
    int brute_force();
    int optimize();
    // This is class functions
    void getter()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i];
        }
    }
};

int kadane ::brute_force()
{
    // Finding the maximum subarray

    int maxsum = INT_MIN;

    for (int i = 0; i < 10; i++)
    {
        int sum = arr[i];
        for (int j = i + 1; j < 10; j++)
        {
            sum = sum + arr[j];
            if (sum > maxsum)
            {
                maxsum = sum;
            }
        }
    }
    return maxsum;
}


int kadane:: optimize(){

    int sum=0;
    int maxi = INT_MIN;
    for(int i=0;i<10;i++){
      sum=sum+arr[i];
      maxi = max(sum,maxi);
      if(sum<0){
        sum = 0;
      }
    }
 
    return maxi;


}
int main()
{
    int myarr[10];
    int mysecondarr[10];
    for(int i = 0;i<10;i++){
        cout<<i+1<<" th element : ";
        cin>> myarr[i];
        mysecondarr[i] = myarr[i];
    }
    
    kadane k1test(myarr);
    int maxvalue = k1test.brute_force();
    cout<<"Maximum subarray value is : " << maxvalue<<"\n";
    
    kadane k2test(mysecondarr);
    maxvalue = k2test.optimize();
    cout<<"Maximum subarray value is : " << maxvalue<<"\n";


    return 0;
}