#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//T1134
int main()
{
    char a[256];
    int len;
    int i;

    cin >> a;
    len=strlen(a);

    if(a[0]>='0'&&a[0]<='9')
    {
        cout<<"no"<<endl;
        return 0;
    }
    for(i=0; i<len; i++) 
    {
        if(!( (a[i]>='0'&&a[i]<='9') || (a[i]>='A'&&a[i]<='Z') || (a[i]>='a'&&a[i]<='z') || a[i]=='_') )
        {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
