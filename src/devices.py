import gpiozero

pump = gpiozero.DigitalOutputDevice(22)
button = gpiozero.Button(23)
skip = gpiozero.LED(24)
