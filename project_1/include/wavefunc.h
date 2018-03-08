#pragma once
#include <armadillo>

using namespace std;
using namespace arma;

class WaveFunc{
    public:
        int N_d, N_p; 
        vector<double> params;

        WaveFunc(){}
        virtual void set_params(vector<double> params, int N_d, int N_p) =0;
        virtual ~WaveFunc() {}
    
        virtual double evaluate(mat R) = 0; 
        virtual double E_l(mat R) = 0;
        virtual double nabla(mat R) = 0;
        virtual double laplace(mat R) = 0;
        virtual double proportion(mat R, mat R_p) = 0; 
       };
