# DTA - The Death Trap Amplifier
This repository contains schematics and information on the Death Trap Amplifier, derived from the Fender 5F6/5F6-A Bassman.

## The DTA design improves on the 5F6-A Bassman with the following features:

1. An improved power supply design, including proper (Earth) grounding of the chassis.
2. Independent power tube bias, with increased range to support a variety of tube types.
3. Ultralinear mode operation.
4. Selectable output impedance for modern cabinets (4/8/16 ohm)
5. Variable negative feedback (Off, 105K-5K Ohm)  
   NFB is taken off the selected output tap. Supports Marshall or Fender feedback levels in all OT tap positions.
6. Independently voiced Bass and Guitar input channels.
    Dark (bass) & Bright (guitar) switches.
7. Selectable cathode bypass in second gain stage (Treble/Global boost).

---

## Death Trap Design Warning

Tube amplifiers have lethal voltages and current running through them.  
Without a basic working knowledge of electrical design principles and appropriate safety precautions you can very
well kill yourself building or servicing this or any tube amplifier design.

In addition to the usual risks associated with tube amplifiers it is important to note that **the DTA design does not
attempt to protect you from yourself in any way**, and includes features which are *ACTIVELY DANGEROUS*.  
In particular:  
* There are no "bleed resistors" in the power supply as designed.  
  The power supply capacitors may maintain (or accumulate) a dangerous charge, even if the amplifier is unplugged.
* The tone stack bypass / FX Module interface carries high voltages.  
  The FX Module interface is designed to facilitate alternate (pluggable) tone stacks.  
  It carries the same voltage as the tone stack circuit and presents it to the user in a 1/4 inch jack. 
