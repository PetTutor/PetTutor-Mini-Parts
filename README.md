# Pet Tutor Mini: Open-Source Wireless Dog Feeder for Training

[![License: CC BY-SA 4.0](https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-sa/4.0/)
[![3D Printable](https://img.shields.io/badge/3D%20Printable-Yes-blue.svg)](https://www.thingiverse.com/)
[![Electronics](https://img.shields.io/badge/Electronics-Arduino%20Compatible-green.svg)](https://www.arduino.cc/)

## Project Overview

**Pet Tutor Mini** is an open-source, wireless dog feeder designed specifically for **positive reinforcement training**. It dispenses small treats remotely via a mobile app or web interface, helping trainers reward behaviors instantly without interrupting sessions. Built with affordable 3D-printed parts and off-the-shelf electronics, it's customizable, hackable, and perfect for dog owners, trainers, or hobbyists. The original Pet Tutor was created by Smart Animal Training Systems, LLC in 2012 and has gone  through several generations with the new one being the Pet Tutor Mini which is the subject of this open-source project. The Pet Tutor Mini is sold as a completed unit; ;however for hobbiests and developers the parts are provided here at no charge. The Pet Tutor is available for wheelchairs with interfaces for accessibility.

### Key Features
- **Wireless Control**: Bluetooth(50 feet) or Wi-Fi connectivity(internet via MQTT broker) for remote treat dispensing.
- **Modular Design**: Easy-to-print parts.
- **USB-C power plug for Wall or external battery**: A standard USB-C cable and wall plug or external USB style battery provide power.
- **Smart Features**: Auto dispense from browser or app.
- **Open-Source Everything**: Full schematics, code(c++), and files shared under CC BY-SA 4.0 (attribution required; share-alike for derivatives).

> **Note**: While the designs are free to build and modify, commercial versions sold by Smart Animal Training Systems,LLC under the "Pet Tutor" brand include premium support, custom firmware, and quality-tested components—check [Pet Tutor store](https://pettutor.biz) for those.

<!-- remove
# 🐾 PetTutor Mini Parts

Welcome to the **PetTutor Mini Parts** repository! This repo contains 3D printable files, diagrams, and documentation for parts of the **PetTutor Mini** that are available for public use, repair, or customization.

## 📦 What's Included
-->

## This Pet Tutor Mini repository currently includes:

- ✅ STL files for printable components (non-proprietary)
- ✅ Exploded diagrams showing part relationships
- ✅ Licensing information for personal and educational use

> ⚠️ Note: This repository does **not** include any proprietary or internal mechanisms protected under patent or intellectual property rights. Please see the [LICENSE](https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/LICENSE) section for more info.
<!-- comment out
## 🧩 Available Parts

| Module Name             | File Type | Print Notes           | Status   |
|----------------------|-----------|------------------------|----------|
| [Canister](https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/Canister/Readme.md)             | `.stl`    | PLA 0.2mm layer        | Public   |
| [Tumbler](https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/Tumbler/Readme.md)             | `.stl`    | Most PLA 0.2mm layer   | Public   |
| [PowerBase ESP32](https://github.com/PetTutor/PetTutor-Mini-Parts/blob/main/PowerBase%20ESP32/README.md)      | `.stl`    | PLA 0.2mm layer        | Public   |
| [PowerBase Atom](https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/PowerBase%20Atom/README.md)       | `.stl`    | PLA 0.2mm layer        | Public   |
| [Clickers](https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Clickers)       | `.stl`    | PLA 0.2mm layer        | Public   |

-->
> Need a specific part? Open an issue or submit a request!
> 
# Modules Available   

| Module Name             | Description | Contains sw/3D/electronics |
|----------------------|-----------|:-------------:|
| [Canister][ca]             | Container for food. 1 cup is standard but larger versions are included    | 3D |
| [Dispense Mechanism][dm]   | This part moves the kibble out of the feeder. It fits into the canister module. The brushes can be printed(TPU) or purchased    | 3D |
| [PetTutor Software][sw]    | The software is for the PowerBase, Remotes and mobile apps   | sw |
| [PowerBase Atom][pba]      | The PowerBase contains the stepper motor, Atom and 3D parts       | 3D/Elec   |
| [PowerBase ESP32][pbe]     | Inactive version. No longer in use but provided for information       | 3D/Elec   |
| [Remotes][rm]              | There are two versions of the remote: advanced and basic. The advanced has a larger button for accessibility  | 3D/Elec   |

## 🤝 Contributions

We welcome:

- Suggestions for improvements
- Bug reports for fit or functionality
- Requests for additional public-facing parts

Please submit a pull request or open an issue if you’d like to contribute!
## Other resources and contributors to the open Pet Tutor community  
- **[Kona Currents](https://github.com/konacurrents/konacurrents)** :Inventor of the Semantic Marker(r) and developer of advanced firmware for the Pet Tutor

## 📄 License

All parts in this repository are provided under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)** license.

You are free to:

- Share and adapt the files
- Remix or build upon them

Under the following terms:

- 🏷️ **Attribution** – Give appropriate credit
- 💸 **NonCommercial** – Not for commercial use
- 🔄 **ShareAlike** – Distribute derivatives under the same license

Full license text available [here](https://creativecommons.org/publicdomain/zero/1.0/deed.en).

## 🖨️ 3D Printing Help

If you want to print your own parts and are new to 3D printing follow these simple steps:

STL Files: Download all printable parts from the /stl folder.

Find a friend or local library with 3D printer and ask them to aid in printing.

Recommended Settings:

Layer Height: 0.2 mm

Infill: 15%

Supports: Non unless specified

Other Print Settings: Default

Material: PLA unless otherwise specified

Assembly Tips:

Test-fit parts before gluing or screwing.

Clean up small holes with a drill bit if too tight.

Refer to the exploded diagrams for part orientation.

Need help? Open an issue or start a discussion on this repo.

## 📬 Contact & Support

For technical support or feedback, please contact:

📧 **PetTutor@SmartAnimalTraining.com** 

🌐 [www.pettutor.biz](https://smartanimaltraining.com/)  <-Assembled and tested units available here.



---

Thank you for supporting innovation, repairability, and pet care!

🐶🐱 – *The PetTutor Team*

[ca]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Canister  
[dm]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Dispense%20Mechanism
[sw]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/PetTutor%20Software  
[pba]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/PowerBase%20Atom
[pbe]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/PowerBase%20ESP32
[rm]: https://github.com/PetTutor/PetTutor-Mini-Parts/tree/main/Remotes
