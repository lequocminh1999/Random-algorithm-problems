#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> f;
int res=0;

/*Given a set of distinct positive integers, find the largest subset such that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20]. Given [1, 3, 6, 24], return [1, 3, 6, 24].*/

/*Solution:
    I solved it using dynamic programming.
    First, I noticed that suppose you got a subset x1...xm that satisfy the for every pair one of the two % the other = 0.
    And without lost of generality assumed that x1..xm is sorted in an ascending order. Then x[i] % x[i-1] ==0 for all i>=2.
    We find that subset the following way. First we sort the array.
    Then we define f[i] as the number of j between 1 and i such that f[i]%f[j]==0. The result size of the subset would be the
    max f. From the position of max f, we run an iterator find the position with f. Output it and record that position and continue
    moving to the left, if we find a position where it is equal to f[prev]-1 and v[prev]%v[pos]==0 then pos is the next position.
    We set prev = pos, print pos out and continue to the left. We repeat this until we reach f[prev]=1
*/

int main(){
    ios_base::sync_with_stdio(false);
    freopen("1.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        v.push_back(x);
        f.push_back(1);
    }
    sort(v.begin(),v.end());
//    for(int i=0;i<n;++i) cout<<v[i]<<" ";
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(v[i]%v[j]==0){
                f[i]=max(f[i],f[j]+1);
                res=max(res,f[i]);
            }
        }
    }
    cout<<res<<endl;
    int pos=n-1;
    bool ff=false;
    int prev;
    while(pos>=0){
        if(f[pos]==res){
            if(!ff){
                cout<<v[pos]<<endl;
                --res;
                prev=pos;
                ff=true;
            }
            else if(v[prev]%v[pos]==0){
                cout<<v[pos]<<endl;
                --res;
                prev=pos;
            }
        }
        --pos;
    }
}
