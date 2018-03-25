#include "../include/gaussian_noninter_numeric.h"
#include "../include/gaussian_noninter_analytic.h"
#include "../include/vmc.h"

using namespace std;
using namespace arma;

int main(int argc, char *argv[]){
    // Derived object of WaveFunc class
    GaussianNonInterAnalytic g;

    Importance D;
    double alpha, alpha_sq, beta, step, h;
    int N_p, N_d, N_mc;
    alpha = 0.5; alpha_sq = alpha*alpha; beta = 1; step = 0.1; h = 1e-5;
    N_p = 50; N_d = 1; N_mc = 1e5;

    vector<double> params = {alpha, alpha_sq, h};
    g.set_params(params, N_d, N_p);
    //must be called or else you literally have no random numbers
    //args are alpha, beta, N_particles, N_dims, N_mccycles
    D.set_params(alpha, beta, N_p, N_d, N_mc);
    D.step = step;
    //reference must be passed or else you get static linking
    //
    vector<double> result;
	string filename = "../data/IN_a_" + to_string(alpha) + 
		"_b_" + to_string(beta) +
		"_step_" + to_string(step)+
		".csv";
    result = D.solve(&g, filename);

    return 0;
}
