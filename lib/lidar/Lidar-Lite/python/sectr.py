import time                                                                                                                                                                                                         
import smbus                                                                                              
                                                                                                          
bus=smbus.SMBus(1)                                                                                        
addr=0x62                                                                                                 
                                                                                                          
while True:                                                                                               
    bus.write_byte_data(0x62,0x00, 0x04)                                                                  
    val_high=bus.read_byte_data(0x62,0x0f)                                                                
    val_low=bus.read_byte_data(0x62,0x10)                                                                 
    dist_cm=val_high*256+val_low                                                                          
    print `dist_cm` + " cm   "                                                                            
    time.sleep(1)  
