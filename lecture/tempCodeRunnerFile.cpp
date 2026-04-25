
}
void sumSubSet(int arr[], int k){
    int n = sizeof(arr) / sizeof(arr[0]);
    int curr_set[100];
    helper3(n,k,arr,curr_set,0);
}
int main() {
    
    int arr[6] = {1,3,2,5,1,3};
    int k = 5;
    sumSubSet(arr, k);
    return 0;
}