from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    # Helper class to determine the pybind11 include path.
    def __str__(self):
        import pybind11
        return pybind11.get_include()


extra_compile_args_df =['--std=c++17','-Wall','-Werror'];

extra_compile_args_q  =['--std=c++17','-Wall','-Werror'];

EIGEN_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/eigen';
GSL_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/gsl';
BOOST_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/Boost';

EIGEN_PATH_INCLUDE = EIGEN_PATH +'/include/eigen3'
GSL_PATH_INCLUDE = GSL_PATH +'/include'
BOOST_PATH_INCLUDE = BOOST_PATH+'/include'

import os;
cwd = os.getcwd(); #Current work directory

#Path for C++ libraries:
dataframe_path = cwd+'/src/data_frame_module';
quad_path = cwd+'/src/quad_module';

df_bind_path = cwd+'/src/pyDirDF';
q_bind_path=cwd+'/src/pyDirQuad';

#directory of headers:
headers_dir=cwd+'/Headers'

extra_link_args_qb = [];
extra_link_args_qb.append('-Wl,-rpath,' + GSL_PATH+'/lib');
extra_link_args_qb.append('-L'+GSL_PATH+'/lib');
extra_link_args_qb.append('-lgsl');
extra_link_args_qb.append('-lgslcblas');


Extension_statistics =  Extension( \
                        'dataFrameBind', \
                        [dataframe_path+'/DATA_FRAME.cpp',df_bind_path+'/dataFrameBind.cpp'],  \
                        include_dirs=[                                                         \
                        get_pybind_include(), \
                        headers_dir,          \
                        BOOST_PATH_INCLUDE,   \
                        ],                    \
                        language='c++',       \
                        extra_compile_args=extra_compile_args_df);

Extension_quadrature =     Extension(  \
                           'quadBind', \
                           [quad_path+'/Quadrature.cpp',q_bind_path+'/quadBind.cpp'], \
                           library_dirs=[GSL_PATH+'/lib'],  \
                           include_dirs=[ \
                           get_pybind_include(), \
                           headers_dir, \
                           GSL_PATH_INCLUDE, \
                           ], \
                           language='c++', \
                           extra_compile_args=extra_compile_args_q, \
                           extra_link_args=extra_link_args_qb);

#Specify here if you want only the statistics or the quadrature module:

build_statistics=True;
build_quadrature=True;

ext_modules= [];

if(build_statistics):
    ext_modules.append(Extension_statistics);
if(build_quadrature):
    ext_modules.append(Extension_quadrature);

if(build_statistics and build_quadrature):
    name_ = 'pyGeneral';
elif(build_statistics):
    name_= 'pyDataFrame';
elif(build_quadrature):
    name_= 'pyQuadrature';
else:
    name_= 'default';

setup(
name=name_,
version='1.0',
author='Nicola Clinco',
author_email='nicoclinco@gmail.com',
description='Library for statistics and quadrature module',
long_description='',
ext_modules=ext_modules,
install_requires=['pybind11>=2.5.0'], # pybind11 requirement.
cmdclass={'build_ext': build_ext},
zip_safe=False,
);

