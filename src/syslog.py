import time, os


def _get_logfile():
    if not "logs" in os.listdir():
        os.mkdir("logs")
        
    return "./logs/events.log"
    # if "LOGFILE" in os.environ:
    #     logfile = os.environ["LOGFILE"]
    # else:
    #     logfile = "events.log"

    # return logfile


def log(*message, sep=" ", logfile=_get_logfile(), localtime=time.gmtime()):
    timestamp = time.strftime("%Y-%m-%dT%H:%M:%SZ", localtime)

    with open(logfile, "a") as log:
        log.write("\n" + timestamp + " INFO: " + sep.join(message))
