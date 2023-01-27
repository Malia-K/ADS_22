#include <bits/stdc++.h>
using namespace std;

struct student{
    vector<pair< pair<string, string>, double>> v;

    void append(string sname, string name, double gpa){
        v.push_back(make_pair(make_pair(sname, name), gpa));
    }

    void print(){
        cout << v[0].first.first << " " <<  v[0].first.second <<  " "  << fixed << setprecision(3) << v[0].second <<  endl;
    }

    string getSurname(){
        return v[0].first.first;
    }
    string getName(){
        return v[0].first.second;
    }

    double getGPA(){
        return v[0].second;
    }
};

bool checkStudent(student a,  student &b){
    if(a.getGPA() < b.getGPA()){
        return true;
    }else if(a.getGPA() > b.getGPA()){
        return false;
    }else{
        if(a.getSurname() < b.getSurname()){
            return true;
        }else if(a.getSurname() > b.getSurname()){
            return false;
        }else{
            if(a.getName() < b.getName()){
                return true;
            }else if(a.getName() > b.getName()){
                return false;
            }
        }
    }
}

int partition(student *a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(checkStudent(a[j], a[pivot])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}

void qsort(student *a, int low, int high){
    if(low < high){
        int pivot  = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

double cSum;
double gcSum;

void credSum(int cred){
    cSum += cred;
    // cout << "cred "<<cSum << endl;
}

void gpaCredSum(string letter, int cred){
    double g;
    if(letter == "A+")       g = 4.00;
    else if(letter == "A")   g = 3.75;
    else if (letter == "B+") g = 3.50;
    else if (letter == "B")  g = 3.00;
    else if (letter == "C+") g = 2.50;
    else if (letter == "C")  g = 2.00;
    else if (letter == "D+") g = 1.50;
    else if (letter == "D")  g = 1.00;
    else if (letter == "F")  g = 0;

    gcSum += (g * cred);
    // cout << g << " " << cred << " " <<gcSum << endl;
}



int main(){
    int n, m; cin >> n;
    student students[n];

    for(int i = 0; i < n;i++){
        string sname, name;
        double gpa;
        cin >> sname >> name >> m;

        for(int j = 0; j < m; j++){
            string letter; cin >> letter;
            int cred; cin >> cred;
            gpaCredSum(letter, cred);
            credSum(cred);
        }
        // cout << gcSum << " " << cSum << endl;
        gpa = gcSum / cSum;
        // cout << gpa << endl;
        students[i].append(sname, name, gpa);
        gcSum = 0;
        cSum = 0;
        
    }
    
    qsort(students, 0, n - 1);
    for(int i = 0; i < n;i++){
        students[i].print();
    }
    return 0;
}