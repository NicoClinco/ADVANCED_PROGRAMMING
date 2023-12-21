import newton_py

def f(x):
    return x*x-50*x;

def df(x):
    return 2*x-50;


solver = newton_py.NewtonSolver(f,df,30,1e-10,100);
solution = solver.solve();
print("SOLUTION IS :",solution);
