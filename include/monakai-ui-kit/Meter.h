#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace monakai::ui {

/**
 * A simple vertical level meter.
 *
 * The meter draws from the bottom up. Call setLevel() with a normalized 0..1
 * value whenever a new level is available.
 */
class Meter : public juce::Component
{
public:
    Meter();

    void setLevel(float level);
    void setForegroundColour(juce::Colour colour);

    void paint(juce::Graphics& g) override;

private:
    float level_ = 0.0f;
    juce::Colour foregroundColour_ { juce::Colours::green };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Meter)
};

} // namespace monakai::ui
