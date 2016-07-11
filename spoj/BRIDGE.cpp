#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct bridge
{
    bridge(){}
    bridge(const bridge &b)
    {
        x1 = b.x1;
        x2 = b.x2;
    }
    int x1, x2;
    bool operator<(const bridge & p) const
    {
        return (x1 < p.x1 || (x1 == p.x1 && x2 < p.x2));
    }
};

int N;
vector<int> seq;

int find_max()
{
    vector<int> res(N+1);
    for(int i=1; i<=N; ++i)
		res[i] = -1;
    for(int i=1; i<N; ++i)
    {
        int j = 0;
        while(res[j] != -1 && seq[res[j]] <= seq[i])
			++j;
        res[j] = i;
    }
    for(int i=0; i<=N; ++i)
        if(res[i] == -1) return i;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        vector<bridge> A(N), B;
        for(int i=0; i<N; ++i)
        {
            cin >> A[i].x1;
            A[i].x1 += 1001;
        }
        for(int i=0; i<N; ++i)
        {
            cin >> A[i].x2;
            A[i].x2 += 1001;
        }
        sort(A.begin(), A.end());
        B.push_back(bridge(A[0]));
        for(int i=1; i<N; ++i)
                B.push_back(A[i]);
        N = B.size();

        seq.resize(N);
        for(int i=0; i<N; ++i)
            seq[i] = B[i].x2;
        cout << find_max() << endl;
    }
}
