/*
 * Copyright (c) 2019 Tobias Briones. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * This file is part of Example Project: Secant Method.
 *
 * This source code is licensed under the MIT License found in the
 * LICENSE file in the root directory of this source tree or at
 * https://opensource.org/licenses/MIT.
 */

#include "Polynomial.h"

Polynomial::Polynomial(int degree) :
    degree(degree)
{
    if (degree < 0)
    {
        string msg = "A polynomial has non-negative degree, invalid degree " + to_string(degree);
        throw runtime_error(msg);
    }
    for (int i = 0; i < degree; i++)
    {
        monomials.push_back(Monomial(i, 0));
    }
    monomials.push_back(Monomial(degree, 1));
}

int Polynomial::getDegree() const
{
    return degree;
}

void Polynomial::setCoefficient(int monomialDegree, double value)
{
    if (monomialDegree < 0 || monomialDegree > degree)
    {
        string msg = "Invalid monomial degree "
                     + to_string(monomialDegree)
                     + " for polynomial of degree "
                     + to_string(degree);
        throw runtime_error(msg);
    }

    // The last monomial can't be zero as this polynomial has grade n
    // It may be zero only if it is a constant polynomial
    if (!isConstant() && monomialDegree == degree && value == 0)
    {
        string g = to_string(degree);
        string msg = "This polynomial has degree " + g + ", the monomial of degree " + g + " can't be zero.";

        throw runtime_error(msg);
    }
    monomials.at(monomialDegree).setCoefficient(value);
}

void Polynomial::set(vector<double> coefficients)
{
    // The implementation for the coefficients can be significantly enhanced but I'll leave this
    // implementation of this polynomial class as this is an example project
    if (coefficients.size() != degree + 1)
    {
        throw runtime_error("The coefficients must be all exactly set! For each degree 0, 1, 2, ..., n");
    }
    for (size_t i = 0; i < coefficients.size(); i++)
    {
        setCoefficient(i, coefficients[i]);
    }
}

double Polynomial::getCoefficient(int monomialDegree) const
{
    return monomials.at(monomialDegree).getCoefficient();
}

double Polynomial::eval(double x)
{
    vector<Monomial>::iterator it;
    double y = 0;

    for (it = monomials.begin(); it != monomials.end(); it++)
    {
        Monomial monomial = (*it);
        y += monomial.eval(x);
    }
    return y;
}

string Polynomial::toString()
{
    vector<Monomial>::iterator it;
    string str = "";
    bool positive = false;

    for (it = monomials.begin(); it != monomials.end(); it++)
    {
        str += (*it).toString(positive);

        if (str != "")
        {
            positive = true;
        }
    }
    if (str == "")
    {
        str = "0";
    }
    return str;
}

bool Polynomial::isConstant() const
{
    return degree == 0;
}
