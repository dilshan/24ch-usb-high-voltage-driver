## 24-Channel USB driver - Serial communication interface

Serial  configuration  =  Baud:`9600` - 8N1

All commands execute after host terminal send the *carriage return*.

----

*ON=**RELAY_POSITIONS**

On relays at given positions. 
ex: `ON=5` : On relays at 1 and 4 positions.

Result: OK/FAIL

----
  
*OFF=**RELAY_POSITIONS**

Off relays at given positions. 
ex: `OFF=3` : Off relays at 1 and 2 positions.

Result: OK/FAIL

----  

*GET*

Return positions of the active relays.

Result: **RELAY_POSITIONS**. 
ex: `128`

----

*TOG=**RELAY_POSITIONS*** 

Toggle the output of the given position.
ex: `TOG=3` : Toggle relays at 1 and 2 positions.

Result: OK/FAIL

----

*CLR*

Clear and turn off all relay positions.

Result: OK/FAIL

----

*STR*

Store current relay position as default configuration.

Result: OK/FAIL

----

*VER*

Return firmware version and signature.

Result: `ELECT10`

----

*Input  buffer  size  (max): OFF=xxxxxxxx : **14**
*Output  buffer  size  (max): **10**
