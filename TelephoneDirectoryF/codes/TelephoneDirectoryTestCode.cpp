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
#define Nsize 18
#define str to_string

using namespace std;



struct node{
    node* children[10];
};

struct node* createNode()
{
    node* Node = new node();
    for(int i = 0; i < 10; i++)
        Node->children[i] = NULL;
    return Node;
}


void insert(string num, struct node* root, int flag[])
{
    node* Node = root;
    assert(num.size()==Nsize);
    for(int i = 0; i < num.size(); i++)
    {
        int id = (num[i] - '0'+10 - flag[i])%10;
        if(Node->children[id] == NULL)Node->children[id] = createNode();
        Node=Node->children[id];
    }
}

void maximum(struct node* root, int flag[], char Mx[Nsize])
{
    node* Node = root;
    char Max[Nsize];
    for(int i = 0; i < Nsize; i++)
    {
        int j;
        for(j = 9-flag[i]; (j+flag[i])%10 != 0; j--)
        {
            if(j==-1)j=9;
            if(Node->children[j]!=NULL)
            {
                Node=Node->children[j];
                Max[i] = (j+flag[i])%10 + '0';
                break;
            }
        }
        if((j+flag[i])%10==0)
        {   
            Max[i] = '0';
            if(j<0)j+=10;
            Node=Node->children[j%10];
        }
    }    
    strcpy(Mx, Max);
}

void update(string num, int flag[])
{
    for(int i = 0; i < num.size(); i++)
    {
        int x = num[i] - '0';
        flag[i] = (flag[i] + x)%10;
    }
}

bool check(string num, struct node* root, int flag[])
{
    node* Node = root;
    assert(num.size()==Nsize);
    for(int i = 0; i < Nsize; i++)
    {
        int id = num[i]-'0' + 10 - flag[i];
        if(id > 9)id -= 10;
        if(Node->children[id] == NULL)
        {
            // cout<<id<<" "<<i<<" "<<num<<endl;
            return false;
        }
        Node=Node->children[id];
    }
    return true;
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
    node *root = createNode();
    char Mx[Nsize];
    int flag[Nsize] = {0};
    for(int i = 0; i < Nsize;i++)Mx[i]='0';
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        string num;
        if(q<4)
        {
            cin>>num;
        }
        string ans="";
        switch(q)
        {
            case 1:insert(num, root, flag);assert(check(num, root, flag)==true);break;
            case 2:update(num, flag);break;
            case 3:(check(num, root, flag))?ans="YES\n":ans="NO\n";break;
            case 4:maximum(root, flag, Mx);ans = cstr(Mx) + "\n";break;
            default: cout<<"invalid output";exit(0);
        }
        cout<<ans;
    }
    return 0;
}