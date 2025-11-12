# Software packages for Pet Tutor  
- **Feeder:** The firmware in the feeder allows it to wirelessly connect to BLE(Bluetooth Low Energy) devices like a phone or one of the Pet Tutor remotes. The feeder can also simultaneously connect to WiFi to provide control over the internet from a browser. The internet option uses a MQTT IOT broker to manage status and control to the feeder.
- **Remote:** This firmware allows the remote to find and connect to the feeder using BLE. The button on the remote sends the feed command to the feeder over BLE.
- **Phones:** The apps for Android and iOS provide the phone with the ability to connect to the feeder via BLE and send commands.  In addition the user can use a browser on the phone to send feed commands over the internet from the phone. Using the phone browser does NOT require an app and just uses the browser.
- **Summary:** The feeder can be controlled via BLE or WiFI or both at the same time. The remotes or phones can be used for BLE connection which is easy to setup but has shorter range. For longer range the WiFi option is a good choice. When using WiFi the feeder is setup with credentials for the local WiFi router(SSID/Password) and user cloud account(ID/Password). Customers who buy the Pet Tutor Mini will get a free cloud account but DIY builders will need to provide their own cloud MQTT broker. Basic functions firmware for the feeder and remote can be downloaded and compiled on the Arduino IDE.

---  
# Firmware for devices and apps for the phone  

| Device | Software download link            | binary/source | Description | Software Contributor  | Comment |
|:--------:|:------------------------|:--------:|:----------:|:-------:|:------------|
| Android       | [Android APK][apk]   | binary| Not in app store. download and manually install  | Pet Tutor (Orion Patrie)           |           |   
| iOS           | [Apple iOS][ios]     | binary| In Apple Store for fee                           | Kona Currents,LLC (Scott Moody) |   Several advanced features to monitor MQTT traffic, Semantic Marker developer        |  
| Feeder        | [Arduino ino][ino]   | source | Arduino source code (c++)                        | Pet Tutor (Orion Patrie)           |    Basic firmware       |  
| Feeder        | [Advanced firmware][kc]   | source | Arduino source code (c++)                        | [Kona Currents,LLC (Scott Moody)][kc]           |    Advanced firmware       |  
| Basic Remote  | TBD  | TBD | source | Pet Tutor (Orion Patrie)  |     |  

---

*Updated 11 NOV 2025*

---
[apk]: https://drive.google.com/file/d/19x49JGUla84gN7AuETKdELnhjsQVB5Vx/view?usp=sharing
[frm]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PetTutor%20Basic%20Software/PTMini_Basic.ino
[ios]: https://apps.apple.com/us/app/semanticmarker/id6443887496  
[ino]: https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PetTutor%20Software/PTMini_Basic.ino
[kc]: https://github.com/konacurrents/konacurrents
