#include <bits/stdc++.h>
using namespace std;
int Count;

void merge(int arr[], int l, int r, int mid) {
    int l_sz = mid - l + 1;
    int r_sz = r - (mid + 1) + 1;
    int L[l_sz], R[r_sz];
    for(int i = 0; i < l_sz; i++)L[i] = arr[i+l];
    for(int i = 0; i < r_sz; i++)R[i] = arr[i+mid+1];
    int l_i = 0, r_i = 0;
    
    for(int i = l; i <= r && l_i < l_sz && r_i < r_sz; i++) {
        if(L[l_i] <= R[r_i])l_i++;
        else if(L[l_i] > R[r_i]){
            Count+=(l_sz-1)-l_i+1;
            r_i++;
        }
    }
    l_i = 0, r_i = 0;
    for(int i = l; i <= r; i++) {
        if(r_i == r_sz) {
            arr[i] = L[l_i];
            l_i++;
        }else if(l_i == l_sz) {
            arr[i] = R[r_i];
            r_i++;
        }else if(L[l_i] <= R[r_i]) {
            arr[i] = L[l_i];
            l_i++;
        }else {
            arr[i] = R[r_i];
            r_i++;
        }
    }
}
void mergeSort(int arr[], int l, int r) {
    if(l == r)return;
    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r, mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)cin >> arr[i];
        mergeSort(arr, 0, n-1);
        cout << Count << "\n";
        for(int i = 0; i < n; i++)cout << arr[i] << " ";
    }
    return 0;
}
