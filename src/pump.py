import time, processlog
from devices import pump

amount = 121.970  # Pumping time from calibration program

processlog.log("Pump activated for", str(amount) + "s")

start = time.time()

pump.on()
time.sleep(amount)
pump.off()

processlog.log("Pump deactivated. Run time:", str(round(time.time() - start, 2)) + "s")
