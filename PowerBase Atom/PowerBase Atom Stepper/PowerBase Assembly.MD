## Assemblies required for a complete Pet Tutor Mini are:  
1. Assembly Power Base Assembly (see parts list below)
2. Subassembly [Canister][ca] This container holds the food and screws onto the Dispense Mechanism to make the Food Assembly.
3. Subassembly [Dispense Mechanism][dm] This is the dispenser mechanism which separates out the kibble and drops it out of the feeder

---  

<img width="3300" height="6000" alt="Base V5 Atom Exploded Assembly" src="https://github.com/user-attachments/assets/849ded26-341c-4a8e-8f46-a112fc8b6e89" />
<img width="3300" height="2550" alt="Base V5 Atom Exploded Assembly (2)" src="https://github.com/user-attachments/assets/9245002f-47c7-4de4-86bf-3b2df96fdea7" />  

---  

## Bill of Materials Pet Tutor Mini PowerBase Assembly (*est costs in 2025)

| Item # | Part Name/link              | Quantity | buy/3D print  | Description / Specs                          | Source / Supplier              | Unit Cost* | Total Cost* |
|:--------:|:------------------------|:----------:|:-------:|:----------------------------------------------|:--------------------------------|-----------:|------------:|
| 1      | [ATOM Lite ESP32 IoT Development Kit][Atom]        | 1  | buy  | ATOM ESP32                                                                                                        | M5Stack                     | $7.50     | $7.50      |
| 2      | [ULN2003 Stepper Motor + ULN2003 Driver Board][db] | 1  | buy  | ELEGOO 28BYJ-48 ULN2003 5V Stepper Motor + ULN2003 Driver Board(5sets $15)                                        | ELEGOO(Amazon)              | $3.00     | $3.00      |
| 3      | [Buzzer][buz]                                      | 1  | buy  | Buzzer with wires DC3-12v Active NOTE: must add 2 pin Dupont see [Build Instructions](#Build-Instructions)                                                                                  | bnafes(Amazon)              | $0.58     | $0.58      |
| 4      | [Motor mount screws][mms]                          | 2  | buy  | Phillips Rounded Head Thread-Forming Screws(box 50 $16.46)                                                        | McMaster-Carr               | $0.33     | $0.66      |
| 5      | [Shoulder screws][scr]                             | 2  | buy  | Mod-eez 2155 Shoulder Screw 5 mm x 5/8″ (pkg 25 $8.99)                                                            | Knapp                       | $0.36     | $0.72      |
| 6      | [4 pin cable&connectors female 10 cm][4p]          | 1  | buy  | Dupont 2.54mm Wire Female to Female Connector & 22AWG Pre-Crimped Cable (motor driver), Single Row 10cm (5pkg $8) | Amazon                      | $1.60     | $1.60      |
| 7      | [2 pin cable&connectors 30 cm][2p]                 | 1  | buy  | Dupont 2.54mm Wire Female to Female Connector & 22AWG Pre-Crimped Cable, (motor driver&buzzer) (5 pkg $7.64)      | Amazon                      | $1.53     | $1.53      |
| 8      | [BaseV5 Stepper - 1.stl][s1]                       | 1  | 3D   | Main base for electronics  PLA any color                                                                          | PLA color choice            | n/a       | n/a        |
| 9      | [BaseV5 Stepper - 2 Clear.stl][cs]                 | 1  | 3D   | Channel for LED light on ATOM clear filament required                                                             | ex. [Coex Natural PLA][cn]  | n/a       | n/a        |
| 10      | [BaseV5 Stepper - 3.stl][s3]                      | 1  | 3D   | Holder for ATOM PLA                                                                                               | PLA color choice            | n/a       | n/a        |
| 11     | [Base top Stepper.stl][ts]                         | 1  | 3D   | Clear top holds motor and transmits led light PLA                                                                 | ex. [Coex Natural PLA][cn]  | n/a       | n/a        |
| 12      | [28BY-J Motor Pin.stl][mp]                        | 1  | 3D   | Motor pin fits over motor shaft and drive dispenser                                                               | PLA color choice            | n/a       | n/a        |
| 13      | [Centering ring Stepper.stl][crs]                 | 1  | 3D   | Centering ring aligns dispenser                                                                                   | PLA color choice            | n/a       | n/a        |
---

## Build Instructions:  
- All 3D stl files are printed in PLA at .2 Layer Height and 15% infill.
- Cables connect ATOM to stepper motor driver board(2 pin & 4 pin).
- *Add buzzer connector*: 2 wires from buzzer require adding Dupont 2-pin connector. [Kit with tool and connector][tool]
- The motor pin is glued(ex. silicon glue) on the motor shaft. Note: height is critical along the shaft so mount motor and use the dispense canister assembly to push the pin down on shaft with glue
- Advanced firmware option: This has capabilites to allow the Pet Tutor Mini to connect to both WiFi and Bluetooth. It also can run other addons via the Groove connector.
- In addition to the feeder electronics module the dispenser is required and attached to the module. The food assembly is built from: [Canister][ca] and [Dispense Mechanism][dm] The Dispense Mechanism subassembly fits inside the Canister subassembly and this food assembly twists onto the PowerBase assembly.
- Basic firmware option:  This allows the feeder to be controlled from bluetooth.

---

*Last updated: November 14, 2025*   

<!-- The links below will not show up in the render but are used as shortcuts in the code -->
[Atom]: https://shop.m5stack.com/products/atom-lite-esp32-development-kit?srsltid=AfmBOorpaCo6LaSdYEo0xqwaS0408o4Nq70mW2EWUiq_U3TJ0CaQtvyv
[buz]: https://www.amazon.com/QMseller-Connector-Active-Plastic-Electronic/dp/B07VX87W5Q/ref=sr_1_2_sspa?crid=3PGXR9NJSZ1ML&dib=eyJ2IjoiMSJ9.mngVaeKPfaSjJypt80Rt_Cs2bHcnr88bma-fT_LDqLuZbQqBchicAbzb8fgQ0MIr6aQ1DqjD2rtZ9uH9NXTk5FZjlpjGM5pPuBT0tuTu8ca5d3yGqNhCLzCNc_PiyDFlZZON_daGggbWeN2LBHsiZBaH4pCZC35k4x3gP4mTOUE6cdO6K_9d3QEwIQQaURuixIQqPflwf333RoFkBTb92wWWdbipBEAD1nWqr_rWzBiyrOB4QttO7qMH0nmIBG7fwFZyuQ7UpawxXzOCNDzNZaK3Jf5MVfvq9KkOg6Oygv8.rZq3GyGFamQZGUpWsNWpN5t4dB9dQnoA65l1gw1p7DM&dib_tag=se&keywords=buzzer&qid=1750974701&sprefix=buzzer%2Caps%2C153&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1
[scr]: https://knappconnectors.com/mod-eez-system/shoulder-screws/mod-eez-2155-shoulder-screw-5mm-x-5-8-inch/
[4p]: https://www.amazon.com/gp/aw/d/B0CCV3NJ8Q/?_encoding=UTF8&pd_rd_plhdr=t&aaxitk=506ee69713e5ad772f31c7477b954023&hsa_cr_id=0&qid=1760321211&sr=1-1-f02f01d6-adaf-4bef-9a7c-29308eff9043&ref_=sbx__sbtcd2_asin_0_title&pd_rd_w=umEob&content-id=amzn1.sym.e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a%3Aamzn1.sym.e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a&pf_rd_p=e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a&pf_rd_r=ETXXGVBPQAQSCBZZXWBG&pd_rd_wg=1hlMW&pd_rd_r=72a2d184-2b7e-40e4-94a4-52785567555c&th=1
[2p]: https://www.amazon.com/gp/aw/d/B0CCV3PXFP/?_encoding=UTF8&pd_rd_plhdr=t&aaxitk=506ee69713e5ad772f31c7477b954023&hsa_cr_id=0&qid=1760321211&sr=1-1-f02f01d6-adaf-4bef-9a7c-29308eff9043&ref_=sbx__sbtcd2_asin_0_title&pd_rd_w=umEob&content-id=amzn1.sym.e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a%3Aamzn1.sym.e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a&pf_rd_p=e2c9099f-6964-4dbf-9ce9-8bc2c1a8ec1a&pf_rd_r=ETXXGVBPQAQSCBZZXWBG&pd_rd_wg=1hlMW&pd_rd_r=72a2d184-2b7e-40e4-94a4-52785567555c&th=1
[s1]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/BaseV5%20Stepper%20-%201.stl
[db]: https://www.amazon.com/ELEGOO-28BYJ-48-ULN2003-Stepper-Arduino/dp/B01CP18J4A
[mms]: https://www.mcmaster.com/catalog/131/3432/99461A505
[cs]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/BaseV5%20Stepper%20-%202%20Clear.stl
[s3]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/BaseV5%20Stepper%20-%203.stl
[ts]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/Base%20top%20Stepper.stl
[mp]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/28BY-J%20Motor%20Pin.stl
[crs]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20Atom/PowerBase%20Atom%20Stepper/Centering%20ring%20Stepper.stl
[dm]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Dispense%20Mechanism
[cn]: https://coex3d.com/products/natural-pla-175mm-1kg
[tool]: https://www.amazon.com/Taiss-Ratcheting-Connector-Crimping-Terminal/dp/B0B11RLGDZ?th=1
[ca]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Canister
