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
#define Nsize 30
#define str to_string

using namespace std;


int main()
{
    fastio;
    for(ll fno = 0; fno < 20; fno++)
    {
        cout<<fno<<endl;
        char Mx[Nsize];
        string fname = "../../.././Tries/MaxSubSumF/";
        string ifname = fname+"input/input"+str(fno)+".txt";
        string ofname = fname+"output_check/output"+str(fno)+".txt";
        ifstream ifile(ifname);
        ofstream ofile(ofname);
        if(!ifile)
        {
            cout<<"file doesn't exist";
            exit(0);
        }
        int N;
        ifile>>N;
        for(int i = 0; i < Nsize; i++)Mx[i] = '0';
        char arr[N][Nsize];
        string num;
        for(int n = 0; n < N; n++)
        {
            ifile>>num;
            for(int i = 0; i < Nsize; i++)arr[n][i] = num[i];
        }
        for(int i = 0; i < N; i++)
        {
            if(i%100 == 0)
                cout<<double(i)*100/(N*20)<<endl;
            char Sum[Nsize];
            for(int k = 0; k < Nsize; k++)Sum[k]='0';
            for(int j = i; j < N; j++)
            {   
                for(int k = j; k <= j; k++)
                {
                    for(int l = 0; l < Nsize; l++)
                    {
                        Sum[l] = int(Sum[l] - '0' + arr[k][l] - '0')%10 + '0';
                    }
                }
                int t=0;
                while(t < Nsize && Sum[t] == Mx[t])t++;
                if(t < Nsize && Sum[t] > Mx[t])
                {
                    for(int s = 0; s < Nsize; s++)Mx[s]=Sum[s];
                }
            }
        }
        for(int s = 0; s < Nsize; s++)ofile<<Mx[s];
    }
    return 0;
}