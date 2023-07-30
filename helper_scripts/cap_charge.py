""" Script to calculate Supercapacitor voltage and 
current curve for a given capacity and resistance """
import matplotlib.pyplot as plt
import math
import numpy as np

timeArray = []
voltageArray = []
currentArray = []
""" CAP """
protectRes1 = 90
capFarad = 1.5
capESR = 15
charging_voltage = 3 #initial voltage of cap
minimum_voltage = 0.8 # minimum voltage power regulator can work with
capStartChargeVoltage = 0 #cant be higher than 3


def makeChargePlots(timeArray, voltageArray, currentArray):
   for voltageVal in np.arange(capStartChargeVoltage, 3, 0.01):
      time = np.log(3.3/(3.3-voltageVal))*capFarad*(capESR+protectRes1)
      timeArray.append(time) 
   
   for seconds in timeArray: 
      voltage = 3.3*(1-math.exp(-seconds/((capESR+protectRes1)*capFarad)))
      voltageArray.append(voltage)

   for seconds in timeArray:
      current = (3.3/(protectRes1+ capESR))*math.exp(-seconds/((capESR+protectRes1)*capFarad)) *1000
      currentArray.append(current)


def calculateCapEnergy(): #calculate total cap energy@charging_voltage
   energy = capFarad*(math.pow(charging_voltage,2) - math.pow(0,2))/2
   return energy

def capConstantPowerDischargeFromGPS():
   min_VBCKP = 1.5 #minimum gps backup voltage
   bckp_current = 10 / 1000000
   timeTodischarge = (charging_voltage - min_VBCKP) * capFarad/bckp_current
   return  timeTodischarge * 3600

def calulateVoltageRemainingFromLORAburst():
   #using SF11 and 22 byte size payload transmit time. 200mA transmit RA-01s
   PowerUsed = (3.3*0.2) 
   energyUsed = PowerUsed * 1
   energy_remaining = calculateCapEnergy() - energyUsed
   voltage_remaining = (energy_remaining*2)/capFarad
   return math.sqrt(voltage_remaining)


#print (capConstantPowerDischargeFromGPS())
#print(calculateCapEnergy())
print(calulateVoltageRemainingFromLORAburst())
makeChargePlots(timeArray, voltageArray, currentArray)

timeArrayMinutes = []
for secs in timeArray:
   timeArrayMinutes.append(secs/60)



plt.subplot(1,2,1)
plt.title("Cap Voltage curve with res R=%i" %protectRes1)
plt.plot(timeArrayMinutes, voltageArray, color='red')
plt.xlabel("Time of charging in minutes")
plt.ylabel("Cap Voltage in Volts")
plt.axhline(y = 2.7, color = 'g', linestyle = '-')

plt.subplot(1,2,2)
plt.title("cap current with res: R=%i" %protectRes1)
plt.plot(timeArrayMinutes, currentArray)
plt.xlabel("Time of charging in minutes")
plt.ylabel("Cap current in mA")


#plt.show()   
