
template<class type>
EULER_FIRST_ORDER<type>::EULER_FIRST_ORDER()
{
  // Initialize the butcher coefficients,
  // For explicit Euler everything is simple.
  m_aij = {{0.0}};

  // Initialize the vector b_{ij}
  m_bj = {1.0};

  // Initialize the vector c_i:
  m_ci = {0.0};
  
}

//Specialization for double:
template<>
double EULER_FIRST_ORDER<double>::solve
(
 const double& tInit,
 const double& tFinal,
 std::function< double (double,double)> RHS,
 const double& x0,
 const unsigned int N
)
{
  unsigned int Nstep = N;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;
  double x_current = x0;
  // First stage:
  /*
    K_{i,j} : i stage index, j index for vectors or scalars(1)
    
  */
  size_t stages = 1;
  size_t variables = 1;
  
  Eigen::MatrixXd K(stages,variables);

  while(counter<Nstep)
    {
      // Compute stage-values:
      for(unsigned int i=0;i<m_aij.rows();i++)
	{
	  double prev_sum = 0.0;
	  K(i,0) = RHS(time+m_ci(i)*dt,x_current+prev_sum);
	}
      // Compute end of the stage values:
      for(unsigned int j=0;j<m_bj.size();j++)
	x_current=x_current+m_bj(i)*dt*K(j,1);
    }
  return x_current;
}

//Specialization for vectorXd
template<>
Eigen::VectorXd EULER_FIRST_ORDER<Eigen::VectorXd>::solve
(
 const double& tInit,
 const double& tFinal,
 std::function< Eigen::VectorXd (double,Eigen::VectorXd)> RHS,
 const Eigen::VectorXd& x0,
 const unsigned int N
)
{
  unsigned int Nstep = N;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;
  Eigen::VectorXd x_current = x0;
  // First stage:
  /*
    K_{i,j} : i stage index, j index for vectors or scalars(1)
    
  */
  size_t stages = 1;
  size_t variables = x0.size();
  
  Eigen::MatrixXd K(stages,variables);

  while(counter<Nstep)
    {
      // Compute stage-values:
      for(unsigned int i =0;i<m_aij.rows();++i)
	{
	  // Initialize to zero:
	  Eigen::VectorXd prev_sum = 0.0;
	  for(unsigned int j=0;j<variables;++j)
	    {
	      K(i,j) = RHS(time+m_ci(i)*dt,x_current(j)+prev_sum(j));
	    }
	 
	}
      // Compute end of the stage values:
      for(unsigned int j=0;j<m_bj.size();j++)
	x_current=x_current+m_bj(j)*dt*K(j,1);
    }
  return x_current;
}

template<class type>
CLASSIC_RK4<type>::CLASSIC_RK4()
{
  // Initialize the butcher coefficients:
  
  // For RUNGE-KUTTA-4TH-ORDER
  m_aij = {{0.0,0.0,0.0,0.0},
           {0.5,0.0,0.0,0.0},
           {0.0,0.5,0.0,0.0},
           {0.0,0.0,1.0,0.0}};

  // Initialize the vector b_{ij}
  m_bj = {0.16666,0.33333,0.33333,0.16666};

  // Initialize the vector c_i:
  m_ci = {0.0,0.5,0.5,1.0};
  
}


//Specialization for double:
template<>
double CLASSIC_RK4<double>::solve
(
 const double& tInit,
 const double& tFinal,
 std::function< double (double,double)> RHS,
 const double& x0,
 const unsigned int N
)
{
  unsigned int Nstep = N;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;
  double x_current = x0;
  // First stage:
  /*
    K_{i,j} : i stage index, j index for vectors or scalars(1)
    
  */
  size_t stages = 4;    // Number of stages:
  size_t variables = 1; // Scalar
  
  Eigen::MatrixXd K(stages,variables);
  double previous_sum = 0.0;
  
  while(counter<Nstep)
    {
      // Compute stage-values:
      for(unsigned int i =0;i<m_aij.rows();++i)
	{
	  previous_sum = 0.0; // \sum a_{ij}{k_j}
	  for(unsigned int k = 0;k<i;++k)
	    {
	      previous_sum+= dt*m_aij(i,k)*K(k,0);
	    }
	  
	  K(i,0) = RHS(time+m_ci(i)*dt,x_current+prev_sum);
	}
      // Compute end of the stage values:
      for(unsigned int j=0;j<m_bj.size();j++)
	x_current=x_current+m_bj(j)*dt*K(j,1);
    }
  
  return x_current;
}


//Specialization for Eigen::VectorXd
/*
template<>
Eigen::VectorXd double CLASSIC_RK4<double>::solve
(
 const double& tInit,
 const double& tFinal,
 std::function< double (double,double)> RHS,
 const double& x0,
 const unsigned int N
)
{
  unsigned int Nstep = N;
  unsigned int counter = 0;
  const double& dt = (tFinal-tInit)/Nstep;
  double x_current = x0;
 
  size_t stages = 4;
  size_t variables = 1; //doule
  
  Eigen::MatrixXd K(stages,variables);

  
  while(counter<Nstep)
    {
      // Compute stage-values:
      double previous_sum = 0.0;
      for(unsigned int i =0;i<m_aij.rows();i++)
	{
	  for(unsigned int k = 0;k<i;++k)
	    {
	      previous_sum+= dt*m_aij(i,k)*K(k,0);
	    }
	  
	  K(i,0) = RHS(time+m_ci(i)*dt,x_current+prev_sum);
	}
      // Compute end of the stage values:
      for(unsigned int j=0;j<m_bj.size();j++)
	x_current=x_current+m_bj(j)*dt*K(j,1);
    }
  return x_current;
}
*/


//Explicit specialization for class-templates:

template<> class TimeIntegrator<EULER_FIRST_ORDER<double>,double>;

template<> class TimeIntegrator<EULER_FIRST_ORDER<Eigen::VectorXd>,Eigen::VectorXd>;

template<> class TimeIntegrator<CLASSIC_RK4<double>,double>;


template<> class EULER_FIRST_ORDER<double>;

template<> class EULER_FIRST_ORDER<Eigen::VectorXd>;

template<> class CLASSIC_RK4<double>;

// template<> class CLASSIC_RK4<Eigen::VectorXd>;

