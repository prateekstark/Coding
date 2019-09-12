#include<iostream>
using namespace std;
int finalPostion(int i, int n){
    int x = i/n;
    int y = i%n;
    int tempX = y;
    int tempY = (n - 1 - x);
    return (n*tempX + tempY);
}


void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int i, j;
    cin>>n;
    int arr[n*n];
    for(i=0;i<n*n;i++){
        cin>>arr[i];
    }
    int temp1, temp2, temp3, temp4;
    int valTemp1, valTemp2, valTemp3, valTemp4;
    int savage1, savage2;
    for(i=0;i<n*n;i++){
        if(arr[i] > 0){
            temp1 = finalPostion(i, n);
            valTemp1 = arr[temp1];
            arr[temp1] = arr[i] - 150;
            if(arr[i] > 0){
                temp2 = finalPostion(temp1, n);
                valTemp2 = arr[temp2];
                arr[temp2] = valTemp1 - 150;

                temp3 = finalPostion(temp2, n);
                valTemp3 = arr[temp3];
                arr[temp3] = valTemp2 - 150;

                arr[i] = valTemp3 - 150;
            }
        }
    }
    for(i=0;i<n*n;i++){
        arr[i] = arr[i] + 150;
    }
    printArray(arr, n*n);
    return 0;
}
