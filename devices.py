import gpiozero

pump = gpiozero.DigitalOutputDevice(22)
button = gpiozero.Button(23)
