===============================================================================
    Read me file for the RL78 EEL T02 (Tiny) Endurance Calculation Sheet
===============================================================================

This Endurance Calculation Sheet (ECS) estimates the Flash usage of the RENESAS 
EEPROM Emulation (EEL) for a given data set configuration of the RL78 EEL T02. 
For details regarding the EEPROM emulation concept, 
please refer to the EEL documentation (R01US0070EDxxxx).

The EEL T02 ECS takes as inputs the following parameters: 
  1. number of Flash blocks allocated for EEPROM emulation
  2. Flash HW endurance (maximum Flash erase cycles)  
  3. EEPROM data sets. Each data is defined by:
      - data size and 
      - data required write cycles 
The EEL T02 ECS will compute the following outputs:
  1. Flash usage absolute 
      - number of erase cycles required by the given configuration
  2. Flash usage relative 
      - percent of Flash usage relative to the total Flash endurance

The results may be used as an estimation of the Flash usage. 
The results are not indicating a worst case scenario. 
The EEL T02 ECS is meant to be only a support tool for Flash usage estimation. 
No guarantee is given.
This tool is library specific and it applies only for EEL T02 library. 
Please use for each EEL library the proper Endurance Calculation Sheet.


========
Contents
========

  1. History of Corrections and Updates
  2. General Information
  3. File Naming
  4. Operating Precautions
  5. Support


======================================
1. History of Corrections and Updates
======================================

Endurance Calculation Sheet Changes
-----------------------------------
    E1.00f
    ------
    - First official release
    
    E1.00e
    ------
    - Removing "type_"-prefix from variable names in example
      Adding data checks in order to avoid negative numbers
    
    E1.00d
    ------
    - Adapt the example to the sample descriptor delivered with the libraries
    
    E1.00c
    ------
    - Changed endurance and added data validation
    
    E1.00b
    ------
    - Protection added
    
    E1.00a
    ------
    - Initial version


======================
2. General Information
======================

This Endurance Calculation sheet is delivered for applications 
running on RL78 devices with Data Flash based on MF3 Flash technology, 
using the RENESAS RL78 EEL T02 (Tiny EEL) library.


========================================
3. File Naming
========================================

The Endurance Calculation file has the name 
RENESAS_EEL_RL78_TxxE_EnduranceCalc_E{x}.{yy}{z}.xls
e.g. RENESAS_EEL_RL78_TxxE_EnduranceCalc_E1.00a.xls

{x} This version digit will be incremented in case of major changes 
    in calculation method e.g. EEL implementation changes
{y} This version digit will be incremented in case of bug fixes 
    and internal improvements in calculation method
{z} This version letter will be incremented in case of minor changes 
    that not change the calculation results


========================
4. Operating Precautions
========================

The calculated results may differ significantly from later implementations 
results as they are based on various assumptions, 
e.g related to data set write sequence.
Renesas does not provide any warranty or liability regarding 
the calculation results.


==========
5. Support
==========

In case of any question please do not hesitate to contact:

        Flash Support

        Renesas Electronics Europe GmbH
        Arcadiastr. 10
        D-40472 Duesseldorf, Germany

        email: application_support.flash-eu@lm.renesas.com


===============================================================================
  End of read me file for the RL78 EEL T02 (Tiny) Endurance Calculation Sheet
===============================================================================
