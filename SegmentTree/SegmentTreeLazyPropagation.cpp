/**
 *	Segment Tree - Range Update
 *	Lazy Propagation – An optimization to make range updates faster When there are many updates in a range, 
 *	we can postpone some updates (avoid recursive calls in update) and do those updates only when required.
 *
 *	SC - O(4*N) + O(4*N)
**/

#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
	
	vector<int> seg, lazy;
	
public:
		
	SegmentTree(int n) {
		seg.resize(4*n + 1);
		lazy.resize(4*n + 1, 0);
	}
	
	// TC - O(4*N)
	void build(int ind, int low, int high, int arr[]) {
	
		if(low == high) {
			seg[ind] = arr[low];
			return;
		}
		
		int mid = (low + high) / 2;
		
		build(2*ind + 1, low, mid, arr);
		build(2*ind + 2, mid + 1, high, arr);
		
		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
	}
	
	// TC - O(logN)
	int querySumLazy(int ind, int low, int high, int l, int r) {
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];

			if(low != high) {
				lazy[ind*2 + 1] = lazy[ind];
				lazy[ind*2 + 2] = lazy[ind];
			}

			lazy[ind] = 0;
		}

		if(r < low || high < l || low > high) return 0;

		if(low >= l && high <= r) return seg[ind];
	
		int mid = (low + high) >> 1;
		
		int left = querySumLazy(2*ind + 1, low, mid, l, r);
		int right = querySumLazy(2*ind + 2, mid + 1, high, l, r);
		
		return left + right;
	}
	
	// TC - O(logN)
	void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
	
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];

			if(low != high) {
				lazy[ind*2 + 1] = lazy[ind];
				lazy[ind*2 + 2] = lazy[ind];
			}

			lazy[ind] = 0;
		}

		if(r < low || high < l || low > high) return;

		if(low >= l && high <= r) {
			seg[ind] += (high - low + 1) * val;

			if(low != high) {
				lazy[ind*2 + 1] += val;
				lazy[ind*2 + 2] += val;
			}

			return;
		}
	
		int mid = (low + high) >> 1;
		
		rangeUpdate(2*ind + 1, low, mid, l, r, val);
		rangeUpdate(2*ind + 2, mid + 1, high, l, r, val);
		
		seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
	}
};

// Find sum in range and range update
void solve() {
	int n;
	cin >> n;
	
	int arr[n];
	for(int i = 0; i < n; i++) 
		cin >> arr[i];

	SegmentTree sg(n);
	sg.build(0, 0, n-1, arr);

	int q;
	cin >> q;
	
	while(q--) {
		int type;
		cin >> type;
		
		if(type == 1) {
			int l, r;
			cin >> l >> r;
			cout << sg.querySumLazy(0, 0, n-1, l, r) << endl;
		} else {
			int l, r, val;
			cin >> l >> r >> val;
			sg.rangeUpdate(0, 0, n-1, l, r, val);
			
			for(int i = l; i <= r; i++) arr[i] += val;
		}
	}
}

int main() {

	solve();

	return 0;
}

/** 
    n = 7

	ind - 0 1 2 3 4 5 6
	arr - 4 6 8 2 9 0 5

	post update -
		  4 6 8 5 12 3 8

	query = 4

	q = 1, l = 1, r = 5 / output = 25
	q = 2, l = 3, r = 6, val = 3 
	q = 1, l = 1, r = 5 / output = 34
	q = 1, l = 4, r = 6 / output = 23
**/