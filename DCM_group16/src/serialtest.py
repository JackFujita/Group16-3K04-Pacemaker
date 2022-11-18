import serial
ser = serial.Serial('COM4')  # open serial port
print(ser.name)         # check which port was really used
print(ser)
# print(ser.serial_for_url('hwgrep://<regexp>[&skip_busy][&n=N]'))
# ser.write('hello')     # write a string
ser.close()
# ser2 = serial.Serial('COM6')
# print(ser2.name)
# print(ser2)
# ser2.close()             # close port
# ser3 = serial.Serial('COM4')
# print(ser3.name)
# print(ser3)
# ser3.close()



# ser = serial.serial_for_url(*args, **kwargs)
# ser.close()