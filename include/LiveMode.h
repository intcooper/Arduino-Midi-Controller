#pragma once

#include <Adafruit_SSD1306.h>
#include "IMode.h"
#include "Settings.h"
#include "MidiBus.h"

class LiveMode : public IMode
{
public:
    LiveMode(Adafruit_SSD1306& display, Settings& settings);
    void Update() override;
    void SetSwitch1(bool value) override;
    void SetSwitch2(bool value) override;
    void Increment() override;
    void Decrement() override;
    void Select() override;

private:
    static constexpr uint8_t MaxPrograms{128};

    uint8_t m_bankSize{4};
    uint8_t m_maxBanks{31};
    uint8_t m_lastBank{0};
    uint8_t m_lastProgram{0};
    
    bool m_switch1{false};
    bool m_switch2{false};
    Adafruit_SSD1306& m_display;
    bool m_isChanged{true};

    Settings& m_settings;

    static constexpr uint8_t MidiTxPin{8};
    static constexpr uint8_t MidiRxPin{9};
    MidiBus m_midiBus{MidiTxPin, MidiRxPin};

    void DrawScreen();
};
