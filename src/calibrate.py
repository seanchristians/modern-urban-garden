import time, signal, syslog
from devices import pump, button

syslog.log("Started calibration")


def calibrator():
    while True:
        start = time.time()

        pump.on()
        yield
        pump.off()

        diff = time.time() - start

        syslog.log("Calibrated time", diff)
        print(diff)
        yield diff


calibrate = calibrator()
button.when_pressed = lambda: next(calibrate)

signal.pause()
