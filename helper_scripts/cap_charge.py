""" Script to calculate Supercapacitor voltage and 
current curve for a given capacity and resistance """
import matplotlib.pyplot as plt
import math
import numpy as np

timeArray = []
voltageArray = []
currentArray = []

protectRes = 94
capFarad = 2
rc = protectRes * capFarad

for voltageVal in np.arange(0.8, 3.3, 0.01):
   time = np.log(3.3/(3.3-voltageVal))*rc
   timeArray.append(time) 



for seconds in timeArray: 
   voltage = 3.3*(1-math.exp(-seconds/rc))
   voltageArray.append(voltage)

for seconds in timeArray:
   current = (3.3/protectRes)*math.exp(-seconds/rc) * 1000
   currentArray.append(current)


plt.subplot(1,2,1)
plt.title("Cap Voltage curve")
plt.plot(timeArray, voltageArray, color='red')
plt.xlabel("Time of charging")
plt.ylabel("Cap Voltage in Volts")

plt.subplot(1,2,2)
plt.title("cap current")
plt.plot(timeArray, currentArray)
plt.xlabel("Time of charging")
plt.ylabel("Cap current in mA")

plt.show()   