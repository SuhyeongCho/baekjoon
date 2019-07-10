#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct person{
    int age;
    char name[101];
};
vector<person> v;

bool compare(person a, person b) {
    if (a.age < b.age) return 1;
    else return 0;
}

int main() {
    cin >> N;
    for (int i = 0 ; i < N ; i++) {
        person p;
        scanf("%d %s", &p.age, p.name);
        v.push_back(p);
    }
    stable_sort(v.begin(),v.end(),compare);
    
    for(int i = 0 ; i < N ; i++) {
        printf("%d %s\n", v[i].age, v[i].name);
    }
    return 0;
}


