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

using namespace std;

int main()
{
    fastio;
    for(int fno = 0; fno < 20; fno++)
    {
        string ifname1 = "../../.././Tries/MaxSubSumF/output/output"  + str(fno) + ".txt";
        string ifname2 = "../../.././Tries/MaxSubSumF/output_check/output"  + str(fno) + ".txt";
        ifstream ifile1(ifname1);
        ifstream ifile2(ifname2);
        string s1, s2;
        ifile1>>s1;
        ifile2>>s2;
        if(s1 == s2)
        {
            cout<<fno+1<<"th files match\n";
        }
        else
        {
            cout<<fno+1<<"th files doesn't match\n";
        }
        
    }
    return 0;
}