import gpiozero, os, time

os.chdir(os.path.dirname(os.path.abspath(__file__)))
from devices import pump

start = time.time()

print(time.strftime("%Y-%m-%d %H:%M:%S"), 0.0)  # Redirect to pump.log

pump.on()
time.sleep(121.970)
pump.off()
