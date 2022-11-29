# :hearts: 3K04-Pacemaker

## :family: Group 16 Members
Jack Fujita, Tim Hoy Tang, Shu Dai, Antheus Aldridge, and Sabrina Vieira Sousa

## Simulink
### State Flow
- serial communication from DCM for parameter and mode inputs
- 4 programmable modes: AOO, VOO, VVI, AAI which can be changed dynamically through the mode select page in the DCM
### Requirements Table 
- all requirements and stateflow defined for different modes

### Known Limitations
- no rate adapting or dual pacing modes
- testing with requirements table not implemented

## DCM
### User Interface
- welcome, login and register screens with a maximum of 10 locally stored users
- connects to and disconnects from pacers, and remembers hardware ids
- allows user to select mode then apply to dynamically change mode of pacer
- allows user to select next after a mode is selected and see the programmable parameters and apply changes
- 3 electrograms can be viewed for the ventricle, atrium or both from the mode select page

### Known Limitations
- when applying mode and changes, the serial communication sometimes requires the user to click "Apply" or "Apply Changes" many times until the mode/parameter changes

## Errors
- Serial communication worked with changing the mode and some parameters initially, but after adding in more parameters the serial communication had many errors and previous versions of the code don't work with the current simulink

### Libraries to Install:
- tkinter
- sv_ttk
- serial
- pySerial
