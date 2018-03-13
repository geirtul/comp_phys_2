#include "../include/gaussian_inter_numeric.h"
#include "../include/wavefunc.h"

#include <armadillo>

using namespace std;
using namespace arma;

GaussianInterNumeric::GaussianInterNumeric() : WaveFunc(){}

double GaussianInterNumeric::E_l(mat R){
    double _over_psi = evaluate(R);
    double _laplace_psi = laplace(R);

    return _over_psi*_laplace_psi;

}

double GaussianInterNumeric::evaluate(mat R){
    double alpha = params[0];
    double beta = params[1];

    mat R_c(size(R));
    R_c = R;
    if(N_d > 2){
        R_c.col(2) *= beta;
    }
    double ret_val = (double) as_scalar(exp(-alpha *(accu(sum(R_c)))));
    return ret_val;
}
double GaussianInterNumeric::laplace(mat R){
    double h = params[2];
    double der = (evaluate(R-h) - 2* evaluate(R) + evaluate(R + h))/(h*h) ;
    return der;
}

double GaussianInterNumeric::nabla(mat R){
    return 0;
}


double GaussianInterNumeric::ratio(mat R, mat R_p){
    double eval_R = evaluate(R);
    double eval_R_p = evaluate(R_p);

    double prop = eval_R / eval_R_p;
    return prop;
}

void GaussianInterNumeric::set_params(vector<double> params_i, int N_d_i, int N_p_i){
    N_d = N_d_i;
    N_p = N_p_i;
    params = params_i;
}