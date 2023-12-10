
#__init__.py works as entry point

__all__=['data_config','data','process_data','analyze_data','additional_operation','DataProcessor','operations','data_analysis'];

from . import operations

from . import data_analysis

from .operations import data_config, data, process_data, analyze_data, additional_operation

from .data_analysis import DataProcessor

