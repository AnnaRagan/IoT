Fixing 0 return issue:

Edit /boot/config.txt

Scroll to the bottom of the file.

Add the line:
dtoverlay=i2c_bcm2708

Save the file and reboot.
