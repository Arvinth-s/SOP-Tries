//OM NAMO NARAYANA
#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll >
#define vvll vecotr<vll >
#define vl vector<long> 
#define vvl vector<vl >
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define loop(x, n) for(long long x = 0; x < n; x++)
#define pii pair<int, int> 
#define pll pair<long, long>
#define ff first
#define ss second
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define str to_string
#define Nsize 18

using namespace std;

void update(vector<string> &arr, string s)
{
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < Nsize; j++)
        {
            arr[i][j] = int(arr[i][j] - '0' + s[j] - '0')%10 + '0';
        }
    }
    return;
}

string check(vector<string> arr, string s)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == s)
        {
            return("YES\n");
        }
    }
    return("NO\n");
}

string Max(vector<string> arr)
{
    string Mx=arr[0];
    for(int i = 0; i < arr.size(); i++)
    {
        if(Mx < arr[i])Mx=arr[i];
    }
    return(Mx+"\n");
}

int main()
{
    fastio;
    for(int fno = 0; fno < 20; fno++)
    {
        string ifname = ".././Tries/TelephoneDirectoryF/input/input"+str(fno)+".txt";
        string ofname = ".././Tries/TelephoneDirectoryF/output_check/output"+str(fno)+".txt";
        ifstream ifile(ifname);
        ofstream ofile(ofname);
        if(!ifile)
        {
            cout<<"file doesn't exist";
            exit(0);
        }
        int t;
        ifile>>t;
        vector<string> arr;
        while(t--)
        {
            int q;
            ifile>>q;
            if(t%2000 == 0)
            {
                printf("%.2f\n", (fno+1 - t/100000.0)*5);
            }
            string s;
            assert(q < 5 && q > 0);
            if(q < 4)
            {
                ifile>>s;
            }
            string ans = "";
            switch(q)
            {
                case 1:arr.pb(s);break;
                case 2:update(arr, s);break;
                case 3:ans = check(arr, s);break;
                case 4:ans = Max(arr);break;
            }
            if(q > 2)
            {
                ofile<<ans;
            }
        }
    }
    return 0;
}