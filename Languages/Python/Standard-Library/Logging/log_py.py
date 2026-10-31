import logging

#BASIC INFO
logger = logging.getLogger("logger_name")

#logger levels
logger.debug("Logging at debug")
logger.info("Logging at info")
logger.warning("Logging at warning")
logger.error("Logging at error")
logger.fatal("Logging at fatal")

#included info when logging
system = "moon"
for number in range(3):
    logger.warning("%d errors reported in %s", number,system)
    
#handling exception
try:
    int("none")
except Exception:
    logging.error("Something bad happened", exc_info=True)
    
    