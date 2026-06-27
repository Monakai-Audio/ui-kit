#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <vector>

namespace monakai::ui {

/**
 * Draws a mono audio waveform from a sample buffer.
 *
 * The samples are stored internally; the component repaints when new samples
 * are supplied.
 */
class WaveformDisplay : public juce::Component
{
public:
    WaveformDisplay();

    void setSamples(const float* samples, size_t numSamples);
    void setWaveformColour(juce::Colour colour);

    void paint(juce::Graphics& g) override;

private:
    std::vector<float> samples_;
    juce::Colour waveformColour_ { juce::Colours::white };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformDisplay)
};

} // namespace monakai::ui
