# Media Controller

A rotary encoder-based media controller for Arduino micro pro, allowing control of media playback and volume via HID commands.

## English

### Description
Mediacontroller looks like simple encoder for music controll.

### Features
- **Volume Control**: Rotate the encoder clockwise to increase volume, counterclockwise to decrease.
- **Track Navigation**: Rotate while holding the button to skip to next/previous track.
- **Playback Control**: Single press to play/pause.
- **Mute**: Double press to mute/unmute volume.

### Hardware Requirements
- Arduino-compatible board (e.g., Arduino Leonardo, Pro Micro)
- Rotary Encoder (connected to pins 2 and 3)
- Push Button (connected to pin 7)
- USB connection for HID communication

### Pin Configuration
- Pin 2: Encoder DT (Data)
- Pin 3: Encoder CLK (Clock)
- Pin 7: Button
- Pins 2, 3, 7: INPUT_PULLUP

### Installation
1. Install [PlatformIO](https://platformio.org/).
2. Clone or download this project.
3. Open the project in PlatformIO.
4. Build and upload to your board.

### Dependencies
- [HID-Project](https://github.com/NicoHood/HID) library for HID functionality.

### Usage
1. Connect the hardware as per pin configuration.
2. Upload the code to the board.
3. The device will appear as a HID media controller on your computer.
4. Use the encoder and button as described in Features.

### Troubleshooting
- Ensure the board supports HID (e.g., ATmega32U4-based).
- Check serial output for debugging information.
- Adjust debounce and timing constants if button presses are unreliable.

### License
This project is open-source. Feel free to modify and distribute.

---

## Русский

### Описание
Медиаконтроллер ввиде простого энкодера для управления музыкой. 

### Функционал
- **Управление громкостью**: Поворот энкодера по часовой стрелке увеличивает громкость, против часовой — уменьшает.
- **Навигация по трекам**: Поворот с зажатой кнопкой для перехода к следующему/предыдущему треку.
- **Управление воспроизведением**: Одиночное нажатие — воспроизведение/пауза.
- **Отключение звука**: Двойное нажатие — мьют/анмьют.

### Аппаратные требования
- Плата на базе Arduino (например, Arduino Leonardo, Pro Micro)
- Поворотный энкодер (подключён к пинам 2 и 3)
- Кнопка (подключена к пину 7)
- USB-соединение для HID-коммуникации

### Конфигурация пинов
- Пин 2: Энкодер DT (Данные)
- Пин 3: Энкодер CLK (Тактовый сигнал)
- Пин 7: Кнопка
- Пины 2, 3, 7: INPUT_PULLUP

### Установка
1. Установите [PlatformIO](https://platformio.org/).
2. Склонируйте или скачайте этот проект.
3. Откройте проект в PlatformIO.
4. Соберите и загрузите на плату.

### Зависимости
- Библиотека [HID-Project](https://github.com/NicoHood/HID) для функциональности HID.

### Использование
1. Подключите аппаратную часть согласно конфигурации пинов.
2. Загрузите код на плату.
3. Устройство появится как HID медиа-контроллер на вашем компьютере.
4. Используйте энкодер и кнопку, как описано в Функционале.

### Устранение неисправностей
- Убедитесь, что плата поддерживает HID (например, на базе ATmega32U4).
- Проверьте вывод Serial для отладочной информации.
- Настройте константы debounce и тайминга, если нажатия кнопки ненадёжны.

### Лицензия
Этот проект является открытым исходным кодом. Можете модифицировать и распространять.