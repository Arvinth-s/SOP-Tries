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
#define Nsize 10

using namespace std;

char ac[Nsize];
char Mx[Nsize];

struct node{
    char val[Nsize];
    node* children[10];
};

struct node* createNode()
{
    node* Node = new node();
    for(int i=0; i<10; i++)
        Node->children[i]=NULL;
    for(int i = 0; i < Nsize; i++)Node->val[i]='0';
    return Node;
}

node* root = createNode();

void Sum(string s)
{
    assert(s.size()==Nsize);
    for(int i = 0; i < Nsize; i++)
    {
        int id = (s[i] - '0') + (ac[i] - '0');
        if(id >= 10)id-=10;
        assert(id > 0 && id < 10);
        ac[i] =  id + '0';
    }   
    return;
}

void insert()
{
    node* Node = root;
    for(int i = 0; i < Nsize; i++)
    {
        int id = ac[i]-'0';
        if(Node->children[id]==NULL)Node->children[id]=createNode();
        Node=Node->children[id];
    }
    strcpy(Node->val, ac);
    return;
}

void Maximum()
{
    node* Node = root;
    char Max[Nsize];
    for(int i = 0; i < Nsize; i++)
    {
        int idx = ac[i]-'0', j;
        for(j = idx+1; idx-j+10 >= 0; j++)
        {
            int value = idx-j+10;
            if(Node->children[j%10]!=NULL)
            {
                Node=Node->children[j%10];
                Max[i]=value;
                break;
            }
        }
    }
    if(strcmp(Max, Mx))strcmp(Mx, Max);
    return;
}

int main()
{
    fastio;
    for(int i = 0; i < Nsize; i++)ac[i]='0', Mx[i] = '0';
    int N;
    cin>>N;
    string arr[N], emp;
    getline(cin, emp);
    for(int n = 0; n < N; n++)
    {
        getline(cin, arr[n]);
        string zero(Nsize-arr[n].size(),'0');
        arr[n] = zero + arr[n];
        Sum(arr[n]);
        insert();
        Maximum();
    }
    cout<<Mx;
    return 0;
}