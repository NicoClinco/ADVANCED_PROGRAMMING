import quadBind as qb
import matplotlib.pyplot as plt

"""
 TO DO: Inherits from the base class and create a
        decorator for plotting convergence for each method.
"""

def plotConvergenceHistory(eval):
    
    def wrapPlot(self,*args,**kwargs):
        fig, ax = plt.subplots(figsize=(5,5));
        errors = eval(self,*args,*kwargs);
        ax.plot(args[3],errors,linewidth=3);
        ax.set_xlabel("Number of points");
        ax.set_ylabel("Absolute-error");
        ax.set_xticks(args[3]);
        plt.show();
        return errors;

    return wrapPlot;
        
class pyQuadrature:
    
    quad_available_types = ["Simpson","Trapezoidal","MidPoint","GaussLegeandre"];
    
    def __init__(self,QuadType : str):
        """
        Base constructor
        Initialize from the quadrature type as string.
        @param QuadType: Type of numerical quadrature formula used
        """
        self.ChooseIntegratorType(QuadType);
    
    def __call__(self,to_integrate : callable , x_start : float, x_end : float , N : int):
        """
        Call simply the operator for integrating a function
        """
        return self.integrator(to_integrate,x_start,x_end,N);

    def integrate(self,to_integrate : callable , x_start : float, x_end : float , N : int):
        return self.__call__(to_integrate,x_start,x_end,N);

    @plotConvergenceHistory
    def evaluate(self,to_integrate : callable , x_start : float, x_end : float , N : list, analytic_res : float):
        """
        Evaluating the goodness of the quadrature
        formula
        """
        error = [];
        for n in N:
            error.append(abs(self.integrate(to_integrate,x_start,x_end,n)-analytic_res));
            
        return error;
            
    def ChooseIntegratorType(self,QuadType : str):

        try:
            if(QuadType not in pyQuadrature.quad_available_types ):
                raise KeyError("Invalid numerical quadrature-type")
            else:
                match QuadType:
                    case "Simpson":
                        self.integrator = qb.pyNumSimp();
                    case "Trapezoidal":
                        self.integrator = qb.pyNumTrapz();
                    case "MidPoint":
                        self.integrator = qb.pyNumMid();
                    case "GaussLegeandre":
                        self.integrator = qb.pyNumGaussLeg();
        except(KeyError):
            print("Error- Invalid numerical quadrature-type\n");


class EvalQuadFormulas:
    """
    Evaluate the goodness
    of different quadrature formulas
    """
    def __init__(self,to_integrate : callable, QuadTypes : list,x_start : float,
                 x_end : float, N : list,analytic_result : float):

        # Check if the quadrature formulas are exact:
        try:
            if( not (all(QuadTypes) in pyQuadrature.quad_available_types) ):
                
                raise KeyError("Invalid numerical quadrature type found while evaluating various quadrature formulas.")
            else:
                self.formulas = [];
                for quad in QuadTypes:
                    self.formulas.append(pyQuadrature(quad));
                self.to_integrate = to_integrate;
                self.x_start = x_start;
                self.x_end = x_end;
                self.N = N;
                self.analytic_result = analytic_result;
                
        except(KeyError):
            print("Invalid numerical quadrature type found while evaluating various quadrature formulas.")
            
    def plotResults(self):
        for formula in self.formulas:
            formula.evaluate(self.to_integrate,self.x_start,self.x_end,self.N,self.analytic_result);

            
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
x_end = 3.0;
N = 2;

funList = [SimpsonInterface,TrapzInterface,MidPointInterface,GLInterface];
funNameList = ["simps","trapz","mid","GL"];

print(Results(funList,funNameList),"\n");

#Going on:

integrator = pyQuadrature("Simpson");

res = integrator(to_integrate,x_start,x_end,N);

integrator.ChooseIntegratorType("Trapezoidal");

res2 = integrator(to_integrate,x_start,x_end,N);

#errors = integrator.evaluate(to_integrate,x_start,x_end,[1,5,10,20],9.0)

print(res,res2);

history = EvalQuadFormulas(to_integrate,["Simpson","Trapezoidal","MidPoint"],x_start,x_end,[1,5,10,20],9.0);

x = [1,2,3];
y= [1,2,3,4,5,6];

print( (all(["Simpson","Trapezoidal","MidPoint","GaussLegeandre"]) in pyQuadrature.quad_available_types))

