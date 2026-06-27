#pragma once

#include <functional>
#include <juce_gui_basics/juce_gui_basics.h>

namespace monakai::ui {

/**
 * A thin wrapper around juce::Slider for a consistent linear control.
 */
class Slider : public juce::Component,
               private juce::Slider::Listener
{
public:
    Slider();
    ~Slider() override;

    void setRange(double minimum, double maximum, double interval = 0.01);
    double getValue() const;
    void setValue(double value,
                  juce::NotificationType notification = juce::dontSendNotification);

    std::function<void(double)> onValueChanged;

    juce::Colour trackColour { juce::Colours::grey };
    juce::Colour thumbColour { juce::Colours::white };

private:
    void paint(juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

    juce::Slider slider_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider)
};

} // namespace monakai::ui
