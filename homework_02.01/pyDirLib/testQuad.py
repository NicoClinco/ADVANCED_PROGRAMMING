import quadBind as qb
import matplotlib.pyplot as plt


def plotConvergenceHistory(eval):
    
    def wrapPlot(self,*args,**kwargs):
        ax_ = args[5];
        errors = eval(self,*args,*kwargs);
        ax_.semilogy(args[3],errors,linewidth=3,label=self.__str__());
        ax_.set_xlabel("Number of points");
        ax_.set_ylabel("Absolute error");
        ax_.set_xticks(args[3]);
        ax_.set_title("Absolute error for different numerical quadrature formulas");
        ax_.legend(loc='best');
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
    def evaluate(self,to_integrate : callable , x_start : float, x_end : float , N : list, analytic_res : float, ax : plt.matplotlib.axes.Axes.plot):
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
                        self.type = "Simpson";
                    case "Trapezoidal":
                        self.integrator = qb.pyNumTrapz();
                        self.type = "Trapezoidal";
                    case "MidPoint":
                        self.integrator = qb.pyNumMid();
                        self.type = "MidPoint";
                    case "GaussLegeandre":
                        self.integrator = qb.pyNumGaussLeg();
                        self.type = "Gauss-Legeandre";
        except(KeyError):
            print("Error- Invalid numerical quadrature-type-selected \n");

    def __str__(self):
        return self.type;


class EvalQuadFormulas:
    """
    Evaluate the goodness
    of different quadrature formulas
    """
    def __init__(self,to_integrate : callable, QuadTypes : list,x_start : float,
                 x_end : float, N : list, analytic_result : float):
    

        
            for quadType in QuadTypes:
                if(quadType not in pyQuadrature.quad_available_types):
                    raise KeyError(f'Invalid numerical quadrature type "{quadType}" found while evaluating various quadrature formulas.');
            
            self.formulas = [];
            for quad in QuadTypes:
                self.formulas.append(pyQuadrature(quad));
                self.to_integrate = to_integrate;
                self.x_start = x_start;
                self.x_end = x_end;
                self.N = N;
                self.analytic_result = analytic_result;

            
    def plotResults(self):
        fig,axs = plt.subplots(1,1,figsize=(15,5));
        for indx,formula in enumerate(self.formulas):
            formula.evaluate(self.to_integrate,self.x_start,self.x_end,self.N,self.analytic_result,axs);
        plt.show();
            
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

to_integrate = lambda x: x*x*x*x;
x_start = 0.0;
x_end = 1.0;
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

history = EvalQuadFormulas(to_integrate,["Simpson","Trapezoidal","MidPoint","GaussLegeandre"],x_start,x_end,[2,4,6,8,10],0.2);

history.plotResults();


