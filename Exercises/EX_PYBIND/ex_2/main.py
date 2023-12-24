import newton_py

def f(x):
    return x*x-50*x;

def df(x):
    return 2*x-50;

# Define standard complex number:
xInit = 0.5+2.0j;

solver = newton_py.NewtonSolverComplex(f,df,xInit,1e-10,100);
solution = solver.solve();
print("SOLUTION IS :",solution);


xInitD = 0.5;

solverII = newton_py.NewtonSolverDouble(f,df,xInitD,1e-10,100);
solutionII = solverII.solveII();
print("Second-solution is",solutionII);
