#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<string,int> indexOf;
unordered_map<int,string> keyOf;

class entry {
  private:
    string key;
    int value;
  public:
    entry(string k, int v) {
      key = k;
      value = v;
    }
    void updateValue(int v) {
      value = v;
    }
    string getKey() {
      return key;
    }
    int getValue() {
      return value;
    }
};

bool sortEntries(entry &a, entry &b) {
  return a.getKey() < b.getKey();
}

vector<int> mapEntries(vector<entry> &entries) {
  vector<int> entryArray;
  sort(entries.begin(), entries.end(), sortEntries);
  int index = 0;
  for(entry e: entries) {
    string K = e.getKey();
    int V = e.getValue();
    indexOf[K] = index;
    keyOf[index] = K;
    entryArray.push_back(e.getValue());
    index++;
  }
  return entryArray;
}

int getIndex(vector<entry> &entries, string qk) {
  int lo = 0, mid, hi = entries.size();
  while(lo<hi) {
    mid = (lo+hi)>>1;
    if(entries[mid].getKey()> qk) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

template <typename T> 
struct segmentTree {
  int n;
  T def;
  function<T(T, T)> op;
  vector<T> segTree;

  segmentTree(vector<T> &arr, T def, function<T(T, T)> op) : def{def}, op{op} {
    n = arr.size();
    segTree.resize(2*n, def);
    for(int i = n; i<2*n; i++) {
      segTree[i] = arr[i-n];
    }
  }
  void build() {
    for(int i = n-1; i>0; i--)
      segTree[i] = op(segTree[i<<1], segTree[i<<1|1]);
  }
  void pointUpdate(int p, T newVal) {
    for(segTree[p += n] = newVal; p>1; p >>= 1) 
      segTree[p>>1] = op(segTree[p], segTree[p^1]);
  }
    T rangeQuery(int l, int r) {
    T resultL = def, resultR = def;
    for(l += n, r += n; l<r; l >>= 1, r >>= 1) {
      if (l&1) 
        resultL = op(resultL, segTree[l++]);
      if (r&1) 
        resultR = op(segTree[--r], resultR);
    }
    T result = op(resultL, resultR);
    return result;
  }
  void rangeOperate(int l, int r, T val) {
    for(l += n, r += n; l<r; l >>= 1, r >>= 1) {
      if (l&1)
        segTree[l++] = op(segTree[l], val);
      if (r&1)
        segTree[r] = op(segTree[--r], val);
    }
  }
  T pointQueryAfterRangeOperate(int p) {
    T result = def;
    for(p += n; p>0; p >>= 1) 
      result = op(result, segTree[p]);
    return result;
  }
  T getElement(int p) {
    return segTree[p+n];
  }
  void printSegTree() {
    for(T x: segTree) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
};

int32_t main() {
  int N,Q;
  cin>>N>>Q;
  vector<entry> entries;
  for(int n = 0; n<N; n++) {
    string K;
    int V;
    cin>>K>>V;
    entries.push_back(entry(K,V));
  }
  vector<int> entryArray = mapEntries(entries);
  segmentTree<int> T(entryArray, 0, [](int a, int b){return a+b;});
  T.build();
  while(Q--) {
    int q;
    cin>>q;
    if(q == 1) {
      string qk;
      int qv;
      cin>>qk>>qv;
      T.pointUpdate(indexOf[qk], qv);
    } else if(q == 2) {
      string qk;
      cin>>qk;
      cout<<T.rangeQuery(0, getIndex(entries, qk))<<endl;
    } else {
      cout<<"Invalid Operation!";
    }
  }
  return 0;
}