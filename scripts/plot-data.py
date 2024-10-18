import os
from os import listdir
from os.path import isfile, join
import pandas as pd 
import matplotlib.pyplot as plt 

path_to_csv = '../artifacts/csv'
files = [f for f in listdir(path_to_csv) if isfile(join(path_to_csv, f))]

print(files)

def plot(file):
    df = pd.read_csv(path_to_csv+"/"+file)
    prev = pd.read_csv(path_to_csv+"/previous_commit/"+file)
    fig, ax = plt.subplots()

    # Plot g1 and g2 against the index of the DataFrame
    ax.plot(df.iloc[:, 2], df.iloc[:, 1], label='Original GSR')
    ax.plot(df.iloc[:, 2], df.iloc[:, 0], label='Calculated GSR')
    ax.plot(prev.iloc[:, 2], prev.iloc[:, 0], label='Previous Commit GSR')

    # Add legend and axis labels
    ax.legend()
    ax.set_title('GSR Comparison Graph')
    ax.set_xlabel('Timestamp')
    ax.set_ylabel('Ground Steering Value')

    fig.savefig('../artifacts/'+file.split('.csv')[0]+ '.png', dpi=300)

for file in files:
    plot(file)
