//
// Created by rudri on 9/12/2019.
//
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <map>

#include "Polynomial.h"

Polynomial::Polynomial(const vector<pair<double, int>> &u) {
    this->m=u.size();
    this->v=u;
}


Polynomial::Polynomial(const Polynomial &p) {
    this->m=p.m;
    this->v=p.v;
}

int Polynomial::degree() {
    int mx=0;
    for(int i=0; i<m; i++){
        mx=max(v[i].second,mx);
    }
    return mx;
}

string get_expression(Polynomial p) {
    vector <char> s;


    for(int i=0;i<p.m;i++){
        if(p.v[i].second==0) s.push_back(p.v[i].first+'0'-48);
        else if(p.v[i].first>0) {
            s.push_back('+');
            s.push_back(p.v[i].first+'0'-48);
            s.push_back('^');
            s.push_back(p.v[i].second+'0'-48);
        }
        else {
            s.push_back('-');
            s.push_back(p.v[i].first+'0'-48);
            s.push_back('^');
            s.push_back(p.v[i].second+'0'-48);
        }
    }

    string pol;
    for (int i=0; i<s.size();i++){
        pol.push_back(s[i]);
    }
    return pol;
}


Polynomial Polynomial::operator+(const Polynomial &p)  {
    for (int i=0; i<p.m; i++) {
        int l=0;
        for (int j = 0; i < m; j++) {
            if (p.v[i].second == v[j].second) {
                v[j].first += p.v[i].first;
                l=1;
            }
        }
        if(!l) v.push_back(p.v[i]);
    }
    return *this;
}


Polynomial Polynomial::operator+(const int x) {
    for(int i=0; i<=m; i++){
       if(v[i].second==0) v[i].first +=x;
    }

    return *this;
}


Polynomial Polynomial::operator*(const Polynomial &p) {
    vector<pair<double,int>> mt;
    for(int i=0;i<m;i++) {
        for (int j=0;j<p.m;j++)
            mt.push_back(make_pair(v[i].first*p.v[j].first,v[i].second+p.v[j].second ));
    }
    map<int, float>::iterator itr;
    map<int , float> map;
    for (int i=0;i<mt.size();i++)
        map[mt[i].second]+=mt[i].first;

    v.clear();

    for (  itr= map.begin(); itr != map.end(); ++itr) {
        v.push_back(make_pair(itr->second,itr->first));
    }
    return *this;
}

Polynomial Polynomial::operator*(const int x) {
    for(int i=0; i<=m; i++) v[i].first*=x;
    return *this;
}

Polynomial Polynomial::operator^(const int x) {
    Polynomial o(v);
    Polynomial u(v);
    for(int i=0; i<x; i++)
        u*o;
return u;
}



