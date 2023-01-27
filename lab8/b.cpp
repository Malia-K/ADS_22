#include <bits/stdc++.h>
using namespace std;

map <size_t, size_t> mp; // мап для мониторинга количества повторений индексов в стрингах
size_t cnt = 0; 

void hashing(string s, string t){
    size_t n = s.size();// размер строки
    size_t m = t.size();//размер подсроки

    long long h[n]; // массив хэшов префиксов
    long long p[n];// массив прайм намберов которые каждый раз увеличиваются на 31
    p[0] = 1; // первый элемент 1, ибо 31^0 = 1

    long long q = 1e9 +7; // большое прайм число


    // выявление для начала все степени прайм 31
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 31) % q;
    }

    // вычисление хэша для каждого префикса
    for(size_t i = 0; i < n;i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q; // хэш самого элемента
        // cout << s[i] << " " << h[i] << " "  << p[i] << " ";
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q; // когда i-тый не ноль, то хэш префикса это сумма хэша предыдущего префикса + хэш его самого
        }
        // cout << h[i]<<endl;
    }

    long long hOfPattern = 0; // хэш искомого паттерна
    for(size_t i = 0; i < m; i++){
        hOfPattern = (hOfPattern + ((t[i] - int('a') + 1)* p[i]) % q) % q;
    }
    // cout << hOfPattern << endl;

    // проверка всех подстрок с длиной как у паттерна на совместимость хэшей
    for(size_t i = 0; i + m - 1 < n; i++){
        long long d = h[i + m - 1]; 

        if(i > 0){
            d = (d - h[i - 1] + q) % q;
        }

        if(d == (hOfPattern * p[i]) % q){
            mp[i]++;
            if(mp[i] == 2){
                cnt++;
            }
        }
    }
}



int main(){
    vector<string> s;
    for(int i = 0; i < 2; i++ ){
        string x; cin >> x;
        s.push_back(x);
    }
    string target;
    cin >> target;

    for(int i = 0; i < 2; i++){
        hashing(s[i], target);
    }

    cout << cnt;
    return 0;
}
