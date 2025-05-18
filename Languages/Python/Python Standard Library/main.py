import datetime
from dateutil import tz

def comparing_time_zones():
    #datetime with time zone information
    d1 = datetime.datetime(1989, 4, 24, 10, 11, tzinfo=tz.gettz("Europe/Madrid"))
    d2 = datetime.datetime(1989, 4, 24, hour=8, tzinfo=tz.gettz("America/Los_Angeles"))
    #compare times
    print(d1.hour > d2.hour)
    print(d1 > d2)
    #converts from one timezone to another
    d2_madrid = d2.astimezone(tz.gettz("Europe/Madrid"))
    print(d2_madrid.hour)
    
def main():
    comparing_time_zones()
    #page 259
    
if __name__=="__main__":
    main()