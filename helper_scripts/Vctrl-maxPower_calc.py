#calculate resistor needed to control Vout by Vctrl
Vout = float(input("Give me Vout: "))
print("using Vout of ", Vout, "Volts")
R1 = input("Give R1 value in ohms (will be translated to MΩ)")
R1 = float(R1)*1000000
print("using", float(R1)/1000000, " MΩ R1 resistor\n")
R2 = 0

### FORMULA ####
#R1/R2 = (Vout/1,25) -1
def calcR2AndMaxPower(Vout, R1): #reference spv1040 datasheet page 16 "Output voltage partitioning".
    second_product = (float(Vout)/1.25) -1
    global R2
    R2 = R1/second_product
    print("R2 must be: ", R2/1000000, " MΩ")


    series_resistance = float(R1) + float(R2)
    Pvctrl_sns = pow(Vout,2) / series_resistance
    microwatt = Pvctrl_sns*1000000
    print("Max power dissipation R1+R2: ", microwatt, "microwatt")
    
def currentIntoVctrl():
    current = Vout/R1
    AmpstoMicroAmps = current*1000000
    print("Current into R1: ", AmpstoMicroAmps, " MicroAmpere")


calcR2AndMaxPower(Vout, R1)
currentIntoVctrl()
