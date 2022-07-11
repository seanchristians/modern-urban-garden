import time, signal, processlog
from devices import pump, button

processlog.log("Started calibration")


def calibrator():
    while True:
        start = time.time()

        pump.on()
        yield
        pump.off()

        diff = time.time() - start

        processlog.log("Calibrated time", diff)
        print(diff)
        yield diff


calibrate = calibrator()
button.when_pressed = lambda: next(calibrate)

signal.pause()
