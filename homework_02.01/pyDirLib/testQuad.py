import quadBind as qb

"""
 TO DO: Inherits from the base class and create a
        decorator for plotting convergence for each method.
 # to review: classmethods and so on.
"""

def Results(functionList : list,functionNameList : list):
    """
    Return various results for
    various quadrature integration type
    """
    results = [];
    for fun in functionList:
        results.append(fun(to_integrate,x_start,x_end,N));
    return results;
    


SimpsonInterface = qb.pyNumSimp();

TrapzInterface = qb.pyNumTrapz();

MidPointInterface = qb.pyNumMid();

GLInterface = qb.pyNumGaussLeg();

to_integrate = lambda x: x*x;
x_start = 0.0;
x_end = 2.0;
N = 100;

funList = [SimpsonInterface,TrapzInterface,MidPointInterface,GLInterface];
funNameList = ["simps","trapz","mid","GL"];

print(Results(funList,funNameList));
