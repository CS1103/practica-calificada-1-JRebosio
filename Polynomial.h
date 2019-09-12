//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
using namespace std;


class Polynomial {

public:
    Polynomial( const vector<pair<double,int>> &u);
    Polynomial(const Polynomial & p);
    int degree();
    friend string * get_expression(Polynomial p);
    Polynomial operator+ (const Polynomial & p) ;
    Polynomial operator+ (const int x);

    Polynomial operator * (const int x) ;



private:
    int m;
    vector<pair<double,int>> v;




};



#endif //POLINOMIO_POLINOMIO_H
