//
//  main.cpp
//  ComparatorFunction
//
//  Created by bsarvan on 10/12/18.
//  Copyright © 2018 bsarvan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Name {
    string first_name, last_name;
public:
    Name(string f, string l):first_name(f), last_name(l) {}
    bool operator==(const Name & that) const {
        return first_name ==  that.first_name;
    }
    
    bool operator<(const Name &that) const {
        if (first_name == that.first_name) {
            return (last_name < that.last_name);
        }
        return (first_name < that.first_name);
    }

    void print() {
        cout<<first_name<<" "<<last_name<<endl;
    }
};




struct data {
    int age;
    string name;

    data(string S, int v){
        age = v;
        name = S;
    }
};


// struct comp {
//     bool operator()(data d1, data d2) {
//         return (d1.age > d2.age);
//     }
// };


bool comp(data d1, data d2) {
    return (d1.age > d2.age);
}

int main(int argc, const char * argv[]) {
    
    cout<<"Program to test comparator function in sorting"<<endl;
    
    //vector<string> S = {"Zeoon", "Bharat", "Tavish", "Rupal"};
    vector<Name> V;
    
    V.emplace_back("Ian","Botham");
    V.emplace_back("David","Gover");
    V.emplace_back("Ian","Chappel");
    V.emplace_back("David","Rwan");
    V.emplace_back("Ian","Bell");
    
    
   // for (auto c:S){
   //     cout<<c<<" ";
   // }
    cout<<endl;
    
    sort(V.begin(),V.end());
    
    for(auto b:V){
        b.print();
    }
    cout<<endl;
    


    vector<data> people;


    people.emplace_back(data{"Bharat", 39});
    people.emplace_back(data{"Tavish", 9});
    people.emplace_back(data{"Rupal", 35});


    for (auto p:people) {
        cout<<p.name<<" "<<p.age<<endl;
    }


    sort(people.begin(), people.end(), comp);

    cout<<"Names sorted as per the age"<<endl;

    for (auto p:people) {
        cout<<p.name<<" "<<p.age<<endl;
    }


    return 0;
}
