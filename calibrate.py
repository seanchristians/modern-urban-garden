import gpiozero, os, time, signal

os.chdir(os.path.dirname(os.path.abspath(__file__)))
from devices import pump, button

def calibrator():
    start = time.time()
    pump.on()
    yield
    pump.off()
    return time.time() - start

calibrate = calibrator()
button.when_pressed = lambda: next(calibrate)

signal.pause()
