# Software packages for Pet Tutor  
- **Feeder:** The firmware in the feeder allows it to wirelessly connect to BLE(Bluetooth Low Energy) devices like a phone or one of the Pet Tutor remotes. The feeder can also simultaneously connect to WiFi to provide control over the internet from a browser. The internet option uses a MQTT IOT broker to manage status and control to the feeder.
- **Remote:** This firmware allows the remote to find and connect to the feeder using BLE. The button on the remote sends the feed command to the feeder over BLE.
- **Phones:** The apps for Android and iOS provide the phone with the ability to connect to the feeder via BLE and send commands.  In addition the user can use a browser on the phone to send feed commands over the internet from the phone. Using the phone browser does NOT require an app and just uses the browser.


---
# Android app  
This app is not in the Android app store but can be downloaded from the link below.  

Google Drive link to download-> [PetTutor Basic.apk][apk] 
  
---
# Firmware for the Pet Tutor Mini feeder    

This link is for an Arduino program to perform basic operation of the feeder.   
download-> [PTMini_Basic.apk][frm]   
---

[apk]: https://drive.google.com/file/d/19x49JGUla84gN7AuETKdELnhjsQVB5Vx/view?usp=sharing
[frm]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PetTutor%20Basic%20Software/PTMini_Basic.ino
