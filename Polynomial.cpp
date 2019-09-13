//
// Created by rudri on 9/12/2019.
//
#include <algorithm>
#include <stdexcept>
#include <iostream>
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
    vector<>

    return *this;
}

Polynomial Polynomial::operator*(const int x) {
    for(int i=0; i<=m; i++) v[i].first*=x;
    return *this;
}



