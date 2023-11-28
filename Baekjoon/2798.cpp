#include <iostream>
using namespace std;
int main(void){
    int N, M;
    int sum, max=0;
    int num[100]={0,};
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    for(int i=0;i<N-2;i++){
            for(int j=i+1;j<N-1;j++){
                for(int k=j+1;k<N;k++){
                    sum=num[i]+num[j]+num[k];
                    /*새로운 세 카드의 조합이 기존 sum보다 크고, 
                    M보다는 작으면 값 없데이트*/
                    if(sum>max && sum <=M){
                        max=sum;
                    }
                }
            }
        }
    return 0;
}