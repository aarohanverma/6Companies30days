// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int>v;
        stack<pair<int,int>> st;
      
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && price[i]>=st.top().first)
            {
                st.pop();
            }
            if(st.empty())
            {
                v.push_back(-1);
            }
            else if(!st.empty() && price[i]<st.top().first)
            {
                v.push_back(st.top().second);
            }
            st.push({price[i],i});
        }
        for(int i=0;i<n;i++)
        {
            v[i]=i-v[i];
        }
        return v;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
