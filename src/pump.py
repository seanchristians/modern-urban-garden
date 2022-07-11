import time, syslog
from devices import pump

amount = 121.970  # Pumping time from calibration program

syslog.log("Pump activated for", str(amount) + "s")

start = time.time()

pump.on()
time.sleep(amount)
pump.off()

syslog.log("Pump deactivated. Run time:", str(round(time.time() - start, 2)) + "s")
