import dataFrameBind as dfb
import numpy as np
import pandas as pd

# A class that inherits from the base class:
# It is specialized:
class pyDataFrame(dfb.pyDF):
    """
    A specialized class that inherits from pyDF:
    The datastructure is converted from a python list
    to a dataframe
    """
    def __init__(self,config_file : str):
        dfb.pyDF.__init__(config_file);

    def read(self,filename :str, has_header : True):
        dfb.pyDF.read(filename,has_header);
        #Convert to a pandas dataframe for speed:
        self.data = pd.DataFrame(self.data());
        



# Creating the object:
df = dfb.pyDF("configCSV.txt");

#Read the .CSV:
df.read("London_weather.csv",True);


#Get the data:
data = pd.DataFrame(df.data());



