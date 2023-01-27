#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<int> borisCards;
    queue<int> nursikCards;

    for(int i = 0; i < 10; i++){
        int card; cin >> card;
        if(i < 5){
            borisCards.push(card);
        }else{
            nursikCards.push(card);
        }
    }
    int cnt = 0;
    while(!borisCards.empty() && !nursikCards.empty()){
        cnt++;
        if(cnt == 1000000){
            cout << "blin nichya"<< endl;
            break;
        }

        if(borisCards.front() == 0 && nursikCards.front() == 9){
            borisCards.push(borisCards.front());
            borisCards.push(nursikCards.front());
            borisCards.pop();
            nursikCards.pop();
        }
        else if(nursikCards.front() == 0 && borisCards.front() == 9){
            nursikCards.push(borisCards.front());
            nursikCards.push(nursikCards.front());
            borisCards.pop();
            nursikCards.pop();
        }
        else if(borisCards.front() > nursikCards.front()){
            borisCards.push(borisCards.front());
            borisCards.push(nursikCards.front());
            borisCards.pop();
            nursikCards.pop();
           
        }
        else if(nursikCards.front() > borisCards.front()){
            nursikCards.push(borisCards.front());
            nursikCards.push(nursikCards.front());
            borisCards.pop();
            nursikCards.pop();
        }
    }
    

    if(nursikCards.empty()){
        cout << "Boris " << cnt; 
    }else{
        cout << "Nursik " << cnt;
    }


    return 0;
}