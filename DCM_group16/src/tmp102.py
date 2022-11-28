
# TMP102 address on the I2C bus
i2c_address = 0x48

# Register addresses
reg_temp = 0x00
reg_config = 0x01

# Calculate the 2's complement of a number
def twos_comp(val, bits):
    if (val & (1 << (bits - 1))) != 0:
        val = val - (1 << bits)
    return val

# Read temperature registers and calculate Celsius
def read_temp():
    val = 10
    return val
   
# Initialize communications with the TMP102
def init():
    val = 10