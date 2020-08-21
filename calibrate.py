import gpiozero, os, time, signal

os.chdir(os.path.dirname(os.path.abspath(__file__)))
from devices import pump, button

def calibrate():
    start = time.time()
    pump.on()
    yield
    pump.off()
    print(time.time() - start)

button.when_pressed = calibrate
