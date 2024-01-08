#include <iostream>
using namespace std;
int arr[1000001];
int arr2[1000001];

//삽입정렬 시간복잡도 => O(n*n) 시간초과
/*
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/

/*
void selection_sort(int* arr, int n) {
    int i, j, min, minIndex;
    for (i = 0; i < n - 1; i++) {
        min = 10000001;
        for (j = i + 1; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                minIndex = j;
                //cout << "min: " << min << ", minIndex: " << minIndex << endl;
            }
        }
        //cout << "swap(" << arr[minIndex] << ", " << arr[i] << ")" << endl;
        if(min<arr[i]) swap(arr[minIndex], arr[i]);
    }
}
*/

//merge sort 시간복잡도 => O(nlogn)
void merge(int left, int right) {

    int mid=(left+right)/2, i = left, j = mid+1,k=left,tmp;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            arr2[k++] = arr[i++];
        }
        else {
            arr2[k++] = arr[j++];
        }
    }
    tmp = (i>mid)?j:i;
    while (k <= right) {
        arr2[k++] = arr[tmp++];
    }
    for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition(int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid + 1, right);
        merge(left, right);
    }
}

int main(void) {
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }

    //selection_sort(arr, n);
    partition(0, n - 1);

    for (int i = 0; i < n; i++) cout<<arr[i]<<endl;

    return 0;
}