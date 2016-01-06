#ifndef DWL__SOLVER__CMAESSOFAMILY__H
#define DWL__SOLVER__CMAESSOFAMILY__H

#include <dwl/solver/OptimizationSolver.h>
#include <dwl/utils/YamlWrapper.h>
#pragma GCC system_header // This pragma turns off the warning messages in this file
#pragma message "Turning off the warning messages of libcmaes"
#include_next <cmaes.h>


namespace dwl
{

namespace solver
{

enum CMAESFamily {CMAES, IPOP, BIPOP, ACMAES, AIPOP, ABIPOP, SEPCMAES,
	SEPIPOP, SEPBIPOP, SEPACMAES, SEPAIPOP, SEPABIPOP, VDCMA, VDIPOPCMA,
	VDBIPOPCMA};

class cmaesSOFamily : public OptimizationSolver
{
	public:
		cmaesSOFamily();
		~cmaesSOFamily();

		void setFromConfigFile(std::string filename);

		void setFamily(enum CMAESFamily alg);
		void setAllowedNumberofIterations(unsigned int max_iter);
		void setAllowedNumberOfFunctionEvalutions(unsigned int max_fevals);
		void setElitism(unsigned int elitism);

		bool init();
		bool compute(double allocated_time_secs);


	private:
		double fitnessFunction(const double* x,
							   const int& n);

		libcmaes::FitFunc fitness_;
		libcmaes::CMAParameters<libcmaes::GenoPheno<libcmaes::pwqBoundStrategy>>* cmaes_params_;
		Eigen::VectorXd warm_point_;
};

} //@namespace solver
} //@namespace dwl


#endif
