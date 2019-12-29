/*
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once
#include "../Src/Math/Numerical/SecantMethodApp.h"

const double ERROR = pow(10, -4);
const int THRESHOLD = 1000;

struct Result
{

    double root;
    double froot;
    int iterations;
    bool wasFound;

    void set(double, double, int, bool = true);

};

bool comparePrecision(double, double);
void testPolynomial(Polynomial&, double, double, Result);
void testForConstantPolynomials();
void testForDegreeOnePolynomial();
void testForConstantMonomialZero();
void testForMixedPolynomial();
void testForPolynomialsWithDecimals();
void testForBigPolynomials();
void testForHugePolynomials();
void testForNonRootPolynomials();
void testForFarInitialValues();
void runAllTests();
