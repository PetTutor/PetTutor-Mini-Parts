# Pet Tutor BLE protocol (DIY)

Short notes for connecting a BLE client (phone, Arduino, ESP32, Raspberry Pi, and similar) to a Pet Tutor feeder and sending a feed command. The feeder acts as a BLE peripheral. Feeders sold in 2018 or later are Gen 3. Older units are Gen 2 (LightBlue Bean by Punch Through). The Pet Tutor Mini uses the same BLE interface as Gen 3.

## Gen 3 and Mini

- **Advertised name:** `PTFeeder`, or `PTFeeder:<name>` if a device name is set. The prefix is case-sensitive (`PTFeeder` and `PTFeeder:Name` match; `ptfeeder` does not).
- **Service UUID:** `b0e6a4bf-cccc-ffff-330c-0000000000f0`
- **Characteristic UUID:** `b0e6a4bf-cccc-ffff-330c-0000000000f1`
- **Write type:** write with response
- **Feed command:** write a single byte `0x00` (binary zero, not the ASCII character `0`). This is what the Pet Tutor BLU app sends to Gen 3 feeders and the Mini. In a BLE scanner app, enter `00` as a byte array.

**Steps**

1. Scan and keep devices whose name starts with `PTFeeder`, or that advertise the service UUID above.
2. Connect, then discover that service and characteristic.
3. Write `0x00` with response.

**Mini only** (same characteristic, ASCII text; not supported on original Gen 3 feeders):

- `s` = feed (handy for manual testing from a BLE scanner app)
- `B` = buzzer on
- `b` = buzzer off

## Gen 2 (LightBlue Bean, before 2018)

- **Advertised name:** `PetTutor Feeder` (with a space; exact, case-sensitive).
- **Service UUID:** `a495ff10-c5b1-4b44-b512-1370f02d74de` (Bean serial)
- **Characteristic UUID:** `a495ff11-c5b1-4b44-b512-1370f02d74de`
- **Write type:** write without response
- **Feed command:** the ASCII string `CMD-FEED` (case-sensitive).

The simplest path is the Punch Through Bean SDK: `sendSerialString:@"CMD-FEED"` from iOS or OS X. You can also set Bean scratch bank 5 to `1`. The feeder acknowledges with `ACK!`, or scratch bank 5 set to `2`.

A raw GATT write must use Bean serial framing, not the bare ASCII string. The 14-byte `CMD-FEED` frame is:

`0A 00 00 00 43 4D 44 2D 46 45 45 44 A6 90`

**Steps**

1. Scan and keep a device named `PetTutor Feeder`, or one that advertises the serial service UUID above.
2. Connect, then discover that service and characteristic (or use the Bean SDK).
3. Send `CMD-FEED` as described above.

## Notes

- If a connect or write fails, close any phone app or remote already talking to that feeder and try again.
- Leave about a one-second gap between feed commands.
- Questions: Support@PetTutor.Biz — https://PetTutor.Biz

## Disclaimer

This information is provided as-is for hobby and educational use, with no warranty or support commitment. Use it at your own risk. Smart Animal Training Systems, LLC is not responsible for damage to devices, missed or extra feedings, or injury from custom software. Always supervise your pet when testing, and do not rely on DIY code for a pet's essential feeding. The protocol may change in future firmware.
