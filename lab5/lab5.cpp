#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

void show(set<int> s) {
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
}

void showMap(map<string, int> m) {
    cout << endl << "m: " << endl;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
} 

map<string, int>::iterator
searchByValue(map<string, int>& m, int val) {
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
        if (it->second == val)
            break;
    return it;
}

void zadanieLab() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(3);

    show(s);

    s.erase(s.begin(), s.find(2));
    show(s);
    s.erase(2);
    show(s);
    cout << s.count(2) << endl;

    set<int> s1 = { 1,2,3,7 };
    set<int> s2 = { -2,4,1,7,6 };
    cout << "s1: ";
    show(s1);
    cout << "s2: ";
    show(s2);
    set<int> sUnion, sIntersec, sDiffer;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sUnion, sUnion.begin()));

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sIntersec, sIntersec.begin()));

    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sDiffer, sDiffer.begin()));

    cout << "sUnion: ";
    show(sUnion);
    cout << "sIntersec: ";
    show(sIntersec);
    cout << "sDiffer: ";
    show(sDiffer);

    set<int> s3 = { 3,8 };
    pair<set<int>::iterator, bool> res;
    res = s3.insert(6);
    cout << "Dodany element: " << *(res.first) << endl;
    cout << "Czy element dodany? " << res.second << endl;
    show(s3);

    map<string, int> m;
    m.insert(pair<string, int>("Kowalski", 4500));
    m.insert(make_pair("Nowak", 2000));
    m["Adamek"] = 3000;

    showMap(m);
    int salary = m.find("Kowalski")->second;
    cout << "Zarobki Kowalskiego: " << salary << endl;
    m.erase("Adamek");
    showMap(m);
    cout << "Czy jest Kowalski?  " << m.count("Kowalski") << endl;


    map<string, int>::iterator it = searchByValue(m, 2000);
    if (it != m.end())
        cout << "Element znaleziony: " << it->first << " " << it->second << endl;
    else
        cout << "Brak elementu" << endl;
}

pair<int, int> findDuplikat(const vector<int>& vec) {
    set<int> uni;
    int sum = 0;
    int duplikat = -1;

    for (int num : vec) {
        if (uni.count(num) == 0) {
            uni.insert(num);
            sum += num;
        }
        else {
            duplikat = num;
        }
    }
    return make_pair(duplikat, sum);
}

void twoStrings(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    map<int, char> item1;
    map<int, char> item2;
    for (int i = 0; i < str1.size(); ++i) {
        item1[i] = str1[i];
    }
    for (int i = 0; i < str2.size(); ++i) {
        item2[i] = str2[i];
        if (item1[i] != item2[i]) {
            cout << item2[i];
            break;
        }
    }
}

int main()
{
    //zadanieLab();
    //zadanie 1
    /*vector<int> numbers = { 1,2,2,3 };
    pair<int, int> result = findDuplikat(numbers);

    cout << "Duplikat: " << result.first << endl;
    cout << "Suma unikatowych elementow: " << result.second << endl;*/

    //zadanie 3
    string text1{ "Ala ma kota" };
    string text2{ "lAa am takoa" };
    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;
    cout << "Dodany znak: ";
    twoStrings(text1, text2);

    return 0;
}