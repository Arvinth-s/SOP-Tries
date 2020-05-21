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

void Sum(string s, char ac[Nsize])
{
    assert(s.size()==Nsize);
    for(int i = 0; i < Nsize; i++)
    {
        int id = (s[i] - '0') + (ac[i] - '0');
        if(id >= 10)id-=10;
        assert(id >= 0 && id < 10);
        ac[i] =  id + '0';
    }   
    return;
}

void insert(struct node* root, char ac[Nsize])
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

void Maximum(struct node* root, char Mx[Nsize], char ac[Nsize])
{
    node* Node = root;
    char Max[Nsize];
    for(int i = 0; i < Nsize; i++)
    {
        int idx = ac[i]-'0', j;
        for(j = idx+1; idx-j+10 >= 0; j++)
        {
            int value = idx-j+10;
            assert(value >= 0 && value < 10);
            if(Node->children[j%10]!=NULL)
            {
                Node=Node->children[j%10];
                Max[i]=value+'0';
                break;
            }
        }
    }
    // for(int i = 0; i < Nsize; i++)
    // {
    //     Max[i] = Max[i] -  ac[i] + '0';
    // }
    if(strcmp(Max, Mx)>0)
    {
        // strcpy(Mx, Max);
        for(int i = 0; i < Nsize; i++)Mx[i]=Max[i];
    }
    return;
}

string cstr(char arr[])
{
    string ans = "";
    for(int i = 0; i < Nsize; i++)
        ans += arr[i];
    return ans;
}

int main()
{
    fastio;
    for(ll fno = 0; fno < 20; fno++)
    {
        cout<<fno<<endl;
        node *root = createNode();
        char Mx[Nsize], ac[Nsize];
        int flag[Nsize] = {0};
        string fname = ".././Tries/MaxSubSumF/";
        string ifname = fname+"input/input"+str(fno)+".txt";
        string ofname = fname+"output/output"+str(fno)+".txt";
        ifstream ifile(ifname);
        ofstream ofile(ofname);
        if(!ifile)
        {
            cout<<"file doesn't exist";
            exit(0);
        }
        int N;
        ifile>>N;
        for(int i = 0; i < Nsize; i++)ac[i]='0', Mx[i] = '0';
        // cin>>N;
        string arr[N], emp;
        // getline(cin, emp);
        // string init(Nsize, '0');
        insert(root, ac);
        for(int n = 0; n < N; n++)
        {
            // getline(cin, arr[n]);
            ifile>>arr[n];
            assert(Nsize>=arr[n].size());
            string zero(Nsize-arr[n].size(),'0');
            arr[n] = zero + arr[n];
            Sum(arr[n], ac);
            insert(root, ac);
            Maximum(root, Mx, ac);
        }
        ofile<<cstr(Mx);
    }
    return 0;
}