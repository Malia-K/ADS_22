#include <iostream>
using namespace std;


int main(){
    int x; cin >> x;
    int target[x];

    for(int i = 0; i < x; i++){
        cin >> target[i];
    }


    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }else{
            for(int j = m - 1; j >= 0; j--){
                cin >> arr[i][j];
            }
        }
    }




    
    for(int k = 0; k < x; k++){
        int l = 0; 
        int r = (n * m) - 1;

        bool isFind = false;
        while(l <= r){
            int mid = l + (r - l)/2;
           
            int i = mid / m;
            int j = mid % m;

            
            if(arr[i][j] == target[k]){
                isFind = true;
                if(i % 2 == 0)
                    cout << i << " " << j << endl;
                else
                    cout << i << " " << m - 1 - j << endl;
                break;
                
            }else if(arr[i][j] > target[k]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }

        }
        if(isFind == false)
            cout << -1 << endl;
        

    }



    return 0;
}