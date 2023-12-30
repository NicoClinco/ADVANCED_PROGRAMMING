from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    # Helper class to determine the pybind11 include path.
    def __str__(self):
        import pybind11
        return pybind11.get_include()

extra_compile_args_df =['--std=c++17'];
extra_compile_args_q  =['--std=c++17','-lgsl','-lgslcblas'];

EIGEN_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/eigen/include/eigen3'
GSL_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/gsl'+'/include'
BOOST_PATH= '/home/nico/Desktop/PHD-COURSES/libraries/Boost'+'/include'

dataframe_path = '/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/data_frame_module'
df_bind_path='/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDirDF'
quad_path = '/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/quad_module'
q_bind_path='/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/src/pyDirQuad'

headers_dir='/home/nico/Desktop/PHD-COURSES/ADVANCED_PROGRAMMING/homework_02.01/Headers'

extra_link_args_qb = [];
extra_link_args_qb.append('-Wl,-rpath,' + '/home/nico/Desktop/PHD-COURSES/libraries/gsl'+'/lib')
extra_link_args_qb.append('-L'+'/home/nico/Desktop/PHD-COURSES/libraries/gsl'+'/lib')
extra_link_args_qb.append('-lgsl');
extra_link_args_qb.append('-lgslcblas');

ext_modules = [
    Extension(
        'dataFrameBind', # Name of the module.
        [dataframe_path+'/DATA_FRAME.cpp',df_bind_path+'/dataFrameBind.cpp'], # C++ source files.
        include_dirs=[
            get_pybind_include(), # Path to pybind11 includes.
            headers_dir, # Additional include paths.
            BOOST_PATH,
        ],
        language='c++',
        extra_compile_args=extra_compile_args_df
    ),
    Extension(
        'quadBind',
        [quad_path+'/Quadrature.cpp',q_bind_path+'/quadBind.cpp'],
        library_dirs=['/home/nico/Desktop/PHD-COURSES/libraries/gsl/lib'],
        include_dirs=[
            get_pybind_include(),
            headers_dir,
            GSL_PATH,
            ],
        language='c++',
        extra_link_args=extra_link_args_qb
        )
]

setup(
name='pyBinding',
version='0.0',
author='Nicola Clinco',
author_email='nicoclinco@gmail.com',
description='Creating the libraries for statistic and quadrature module',
long_description='',
ext_modules=ext_modules,
install_requires=['pybind11>=2.5.0'], # pybind11 requirement.
cmdclass={'build_ext': build_ext},
zip_safe=False,
)
