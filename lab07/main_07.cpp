#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <random>
using namespace std;
int main() {
    vector<string> fruits {
        "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };
    auto it=find_if(fruits.begin(),fruits.end(),[](const string &e){
        return e.contains("berry");
    });
    if(it != fruits.end()){
        cout<<*it<<endl;
    }else{
        cout<<"No fruit with berry\n";
    }

     vector<int> numbers {
        2, 3, 5, 7, 9, 10, 11, 17, 20, 21, 23, 29, 51, 97
    };
    bool result= all_of(numbers.begin(),numbers.end(),[](int &e){
        return e%2==0;
    });
    cout << (result ? "True" : "False") << endl;

    vector<int> numbers1 {
        2, 3, 5, 7, 9, 10, 11, 17, 20, 21, 23, 29, 51, 97
    };
    for_each(numbers1.begin(), numbers1.end(), [] (int& param1){
         param1 *= 2;
    });
    for(auto e : numbers1){
        cout<<e<<" ";
    }
    cout<<endl;

    vector<string> months {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int count=0;
    for_each(months.begin(),months.end(),[&count](const string& month){
        if(month.size()==5){
            ++count;
        }
    });
    cout<<count<<endl;

    vector<double> numbers2 = {3.5, 1.2, 7.8, 4.4, 2.1};

    sort(numbers2.begin(), numbers2.end(), [](double a, double b) {
        return a > b; 
    });
    
    /*sort(numbers.begin(), numbers.end(), greater<double>());*/

    for(auto e: numbers2){
        cout<<e<<" ";
    }
    cout<<endl;

    vector<pair<string,int>> months1 {
    { "January",10},{"February",2},{"March",4},{"April", 12},{"May", 18},{"June",25},
    {"July",30},{ "August",32},{ "September", 20},{"October",12},{"November", 3},{"December",1}
    };

    sort(months1.begin(),months1.end(),[](const pair<string,int>& a, const pair<string,int>& b){
        return a.second<b.second;
    });

    for(const auto &e: months1){
        cout<<e.first<<" "<<e.second<<endl;
    }
    cout<<endl;

    vector<double> numbers3 = {3.5, 1.2, 7.8, 4.4, 2.1};

    sort(numbers3.begin(), numbers3.end(), [](double a, double b) {
        return abs(a)<abs(b); 
    });
    
    for(auto e: numbers3){
        cout<<e<<" ";
    }
    cout<<endl;

    vector<string> months2 {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for_each(months2.begin(),months2.end(), [](string &p) {
        transform(p.begin(), p.end(), p.begin(), [](char& c) {
        return c=tolower(c);
        });
    });
    for_each(months2.begin(), months2.end(), [](const string &p) {
        cout << "\t" << p<< endl;
    });

     string alphabet = "abcdefghijklmnopqrstuvwxyz";
    shuffle(alphabet.begin(), alphabet.end(), mt19937(random_device{}()));
    cout << "Furcsa ábécé: " << alphabet << endl;

    return 0;
}