#include<iostream>
using namespace std;

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maximum(int *arr , int size){
    int max = INT_MIN;
    for(int i=0; i<size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}
void countsort(int *arr , int n){
    // finding max
    int max = maximum(arr , n);
    // initializing count array which size is max+1
    int *arr1 = (int *)malloc((max+1)*sizeof(int)) ;

    // putting zero at every value of count array
    for(int i=0; i<max+1; i++){
        arr1[i] = 0;
        // cout<<arr1[i]<<" ";
    }
    // cout<<endl;
    // increasing the value of count array
    for(int i=0; i<n; i++){
        int val = arr[i];
        arr1[val] += 1; 
    }

    // getting the sorted array
    int i=0 , j=0;
    while(i <= max){
        if(arr1[i] > 0){
            arr[j] = i;
            arr1[i] = arr1[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int arr[] = {57, 8, 112, 7, 2};
    int size = 5;
    display(arr, size);

    // mergesort(arr , 0 , size-1);
    countsort(arr , size);

    display(arr , size);
    return 0;
}