#ifndef EIGENOP_H
#define EIGENOP_H


#include <Eigen/Dense>


Eigen::MatrixXd mult_op(const Eigen::MatrixXd& a,const Eigen::MatrixXd& b);

Eigen::MatrixXd inv_op(const Eigen::MatrixXd& a);

#endif
