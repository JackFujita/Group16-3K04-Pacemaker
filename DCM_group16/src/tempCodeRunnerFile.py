with serial.Serial(frdm_port, 115200) as pacemaker:
        #     pacemaker.write(Signal_echo)
        #     data = pacemaker.read(9)
        #     red_rev = data[0]
        #     green_rev = data[1]
        #     blue_rev = data[2]
        #     off_rev =  struct.unpack("f", data[3:7])[0]
        #     switch_rev =  struct.unpack("H", data[7:9])[0]
        #     print("echo complete")

        # print("From the board:")
        # print("red_en = ", red_rev)
        # print("green_en = ", green_rev)
        # print("blue_en = ", blue_rev)
        # print("off_time = ",  off_rev)
        # print("switch_time = ", switch_rev)