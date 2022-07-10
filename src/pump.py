import time
from devices import pump

amount = 121.970 # Pumping time from calibration program

start = time.time()

print("Pump activated at", time.strftime("%Y-%m-%d %H:%M:%S"), "for", str(amount) + "s")  # Redirect to pump.log

pump.on()
time.sleep(amount)
pump.off()

print("Pump deactivated at", time.strftime("%Y-%m-%d %H:%M:%S") + ".", "Active for", str(round(time.time() - start, 2)) + "s")