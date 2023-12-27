from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import sys
import setuptools

class get_pybind_include(object):
    # Helper class to determine the pybind11 include path.
    def __str__(self):
        import pybind11
        return pybind11.get_include()

extra_compile_args =['--std=c++17'];

EIGEN_PATH = '/home/nico/Desktop/PHD-COURSES/libraries/eigen/include/eigen3'

ext_modules = [
    Extension(
        'pythonEig', # Name of the module.
        ['src/pythonEig.cpp','src/eigen_op.cpp'], # C++ source files.
        include_dirs=[
            get_pybind_include(), # Path to pybind11 includes.
            'include', # Additional include paths.
            EIGEN_PATH
        ],
        language='c++',
        extra_compile_args=extra_compile_args
    ),
]
setup(
name='pythonEig',
version='0.0',
author='Your Name',
author_email='nicoclinco@gmail.com',
description='A Python module',
long_description='',
ext_modules=ext_modules,
install_requires=['pybind11>=2.5.0'], # pybind11 requirement.
cmdclass={'build_ext': build_ext},
zip_safe=False,
)
